function query_describe()
{
    dbname=$filename
    table=${query[1]}
    i=
    arg="\"desc_"$table"\":["
    while (( i < ${#db[@]} ))
    do
        if [ ${db[i]} = $arg ]
        then
            i=$((i+1))
            while [[ true ]]
            do
                currentline=${db[i]%,*}
                echo $currentline | cut -f 2 -d \"
                i=$((i+1))
                if [ ${db[i]} = "]," ]
                then
                    exit 0
                fi
            done
        fi
        i=$((i+1))
    done
}