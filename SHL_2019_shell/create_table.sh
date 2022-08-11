function indent()
{
    if [ "$(echo $1 | head -c 5)" = "\"desc" ] || [ "$(echo $1 | head -c 5)" = "\"data" ] && [ "$(echo $1 | tail -c 2)" = "[" ]
    then
        echo "  $(echo $1 | cut -f 1 -d [) [" >> $filename
        indent=$(($indent+2))
    else
        i=0
        space=""
        if [ $1 = "}," ] || [ $1 = "]," ] || [ $1 = "}" ] || [ $1 = "]" ]
        then
            indent=$(($indent-2))
        fi
        while (( $i < $indent ))
        do
            space=" $space"
            i=$(($i+1))
        done
        if [ $1 = "{" ]
        then
            indent=$(($indent+2))
        fi
        if [ $(expr index $1 :) = 0 ]
        then
            echo "$space$1" >> $filename
        else
            echo -e "$space$(echo $1 | head -c $(expr index $1 :)) ${1#*:}" >> $filename
        fi
    fi
}

function create_table()
{
    rm $filename
    touch $filename
    desc[0]="\"desc_${query[2]}\":["
    data[0]="\"data_${query[2]}\":["
    data[1]="]"
    field=$(echo ${query[3]} | cut -f 1 -d ',')
    i=1
    indent=0
    while [ "$field" != "" ]
    do  
        if [ "$(echo ${query[3]} | cut -f $((i+1)) -d ',')" == "" ]
        then
            desc[$i]="    \"$field\""
        else
            desc[$i]="    \"$field\","
        fi
        i=$((i+1))
        field=$(echo ${query[3]} | cut -f $i -d ',')
    done
    desc[$i]="],"
    desc_insert_line=0
    if [ ${#db[@]} = 2 ]
    then
        desc_insert_line=1
    else
        while [ "$(echo ${db[$desc_insert_line]} | head -c 5)" != "\"data" ]
        do
            desc_insert_line=$(($desc_insert_line+1))
        done
    fi
    while (( j < $desc_insert_line ))
    do
        indent ${db[$j]}
        j=$((j+1))
    done
    for str in ${desc[*]}
    do
        indent $str
    done
    while (( j < ${#db[@]} ))
    do
        if [ $j != $((${#db[@]}-1)) ]
        then
            if [ ${db[$j]} = "]" ]
            then
                indent "${db[$j]},"
            else
                indent ${db[$j]}
            fi
        fi
        j=$((j+1))
    done
    for str in  ${data[*]}
    do
        indent $str
    done
    indent "}"
}