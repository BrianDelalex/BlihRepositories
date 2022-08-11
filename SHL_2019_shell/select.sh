function query_select() {
    source ./read_database.sh
    read_database
    tablename="\"data_"${query[1]}"\":["
    colname=${query[2]}
    array=($(echo $colname | tr "," "\n"))
    i=0
    j=0
    e=0
    move=0
    while ((move < ${#db[@]})); do
        if [ ${db[move]} = $tablename ]; then
            j=0
            while ((j < ${#array[@]})); do
                i=$move+1
                while ((i < ${#db[@]})); do
                    test=$(echo ${db[$i]%:*} | grep "${array[j]}")
                    if [[ $? = 0 ]]; then
                        data[$e]=$(echo ${db[$i]#*:} | cut -f 2 -d '"')
                        e=$((e + 1))
                    fi
                    i=$((i + 1))
                done
                j=$((j + 1))
            done
            i=0
        fi
        move=$((move + 1))
    done

    i=0
    a=0
    num=${#data[@]}
    if [[ num%2 -ne 0 ]]; then
        num=$((num / 2 + 1))
    else
        num=$((num / 2))
    fi
    if [[ ${#array[@]} > 1 ]]; then
        while ((a < ${#array[@]})); do
            echo -e "${array[a]}\t |\c"
            echo -e " ${array[a + 1]}"
            a=$((a + 2))
        done
        a=0
        while ((a < 25)); do
            echo -e "-\c"
            a=$((a + 1))
        done
        if [ $i = 0 ]; then
            echo -e ''
        fi
        over=0
        while ((i < ${#data[@]} / 2)); do
            if [[ ${#data[i]} -ge 8 ]]; then
                over=1
                break
            fi
            i=$((i + 1))
        done
        i=0
        while ((i < ${#data[@]} / 2)); do
            if [[ over -eq 1 ]]; then
                if [[ ${#data[i]} -lt 8 ]]; then
                    if [[ ${data[i]} = "" && ${data[i + num]} = "" ]]; then
                        i=$((i + 1))
                    else
                        echo -e "${data[i]}\t\t | ${data[i + num]}"
                    fi
                else
                    echo -e "${data[i]}\t | ${data[i + num]}"
                fi
                i=$((i + 1))
            else
                echo -e "${data[i]}\t | ${data[i + num]}"
                i=$((i + 1))
            fi
        done
    else
        echo "${array[0]}"
        a=0
        while ((a < 12)); do
            echo -e "-\c"
            a=$((a + 1))
        done
        if [ $i = 0 ]; then
            echo -e ''
        fi
        while ((i < ${#data[@]})); do
            echo -e "${data[i]}"
            i=$((i + 1))
        done
    fi
}
