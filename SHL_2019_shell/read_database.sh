function read_database()
{
    if [ "${query[0]}" = "create" ] && [ "${query[1]}" = "database" ]
    then
        return
    fi
    saveifs=$IFS   
    IFS=$'\n'
    db=($(cat $filename))
    i=0
    while (( i < ${#db[@]} ))
    do
        db[$i]=$(echo ${db[$i]} | tr -d ' ')
        i=$((i+1))
    done
    IFS=$saveifs
}