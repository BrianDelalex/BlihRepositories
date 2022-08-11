function create_database()
{
    if [ -f $filename ]
    then
        print_error "database already exists"
        exit 1
    fi
    if [  -e $filename ]
    then
        print_error "$filename is not a file"
        exit 1
    fi
    touch $filename
    echo "{
}" >> $filename
}