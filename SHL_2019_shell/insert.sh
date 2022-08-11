function find_missing_arg()
{
    len=${#array[@]}
    it=0
    while (( it < ${#desc[@]}))
    do
        it2=0
        present=0
        while (( it2 < $len ))
        do
            if [ ${desc[it]} = "$(echo ${array[$it2]} | cut -f 1 -d =)" ]
            then
                present=1
            fi
            it2=$(($it2+1))
        done
        if [ $present = 0 ]
        then
            array+=("${desc[it]}=")
        fi
        it=$(($it+1))
    done
}

function insert()
{
    desc=($(query_describe))
    indent=0
    data[0]="{"
    IFS=',' read -r -a array <<< ${query[2]}
    IFS=$saveifs
    find_missing_arg
    it=1
    while (( it <= ${#array[@]} ))
    do
        if [ $((it)) = ${#array[@]} ]
        then
            data[$it]="\"${array[$(($it-1))]%=*}\":\"${array[$(($it-1))]##*=}\""
        else
            data[$it]="\"${array[$(($it-1))]%=*}\":\"${array[$(($it-1))]##*=}\","
        fi
        it=$(($it+1))
    done
    data[$it]="}"
    data_insert_line=0
    name="\"data_${query[1]}\""
    ct=0
    table_exist=0
    while (( ct < ${#db[@]} ))
    do
        test=$(echo ${db[$ct]} | grep "$name")
        if [ $? = 0 ]
        then
            table_exist=1
            break
        fi
        ct=$(($ct+1))
    done
    if [ $table_exist = 0 ]
    then
        print_error "Table doesn't exist"
        exit 1
    fi
    rm $filename
    touch $filename
    while [[ true ]]
    do
        if [ ${db[$ct]} = "}" ]
        then
            ct=$((ct+1))
            break
        fi
        if [ ${db[$ct]} = "]" ]
        then
            break
        fi
        ct=$(($ct+1))
    done
    j=0
    while (( j < $ct ))
    do
        if [ $(($j+1)) = $ct ] && [ ${db[$j]} = "}" ]
        then
            indent "${db[$j]},"
        else
            indent ${db[$j]}
        fi
        j=$(($j+1))
    done
    for str in ${data[*]}
    do
        indent $str
    done
    while (( $ct < ${#db[@]} ))
    do
        indent ${db[$ct]}
        ct=$(($ct+1))
    done
}