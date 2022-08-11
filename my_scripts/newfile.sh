#!/bin/sh

function print_help()
{
    echo "Usage: ./create_class.sh -f filename [OPTION]...
OPTION:
    -h				display usage
    -d				add ifndef"
}

function parse_input()
{
    i=0
    ifndef=0
    while (( $i < ${#args[@]} ))
    do
        case ${args[i]} in
        -h )    print_help
                exit 0
                ;;
        -d )   ifndef=1
                ;;
        -f  |    --file )   i=$(($i+1))
                file_name=${args[i]}
                ;;
    esac
        i=$(($i+1))
    done
    if [ "$class_name" = "" ]
    then
        print_error "Can't create files without Class name"
        exit 1
    fi
}

args=("$@")