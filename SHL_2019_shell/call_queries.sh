function call_queries()
{
    if [ -z ${query[0]} ]
    then
        print_error "Bad query"
        exit 1
    fi
    if [ ${query[0]} = "create" ]
    then
        if [ ${query[1]} = "database" ]
        then
            create_database
        elif [ ${query[1]} = "table" ]
        then
            create_table
        else
            print_error "Bad query"
            exit 1
        fi
    elif [ ${query[0]} = "insert" ]
    then
        insert
    elif [ ${query[0]} = "describe" ]
    then
        query_describe
    elif [ ${query[0]} = "select" ]
    then
        query_select
    else
        print_error "Bad query"
        exit 1
    fi
}