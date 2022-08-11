#!/bin/sh

function print_help() 
{
    echo "Usage: ./create_class.sh [OPTION]...
OPTION:
  -h				display usage
  -c	--class		Class name
  -n	--namespace	Creating a namespace
  -d	--desc		File description
  -s	--source	Folder to save .cpp
  -i	--include	Folder to save .hpp"
}

function parse_input()
{
    i=0

    class_name=""
    desc=""
    namespace=""
    folder=1
    display=0
    while (( $i < ${#args[@]} ))
    do
        case ${args[i]} in
        -h )    print_help
                exit 0
                ;;
        -c  |    --class )   i=$(($i+1))
                            class_name=${args[i]}
                            ;;
        -d  | --desc )   i=$(($i+1))
                        desc=${args[i]}
                        ;;
        -n  | --namespace )  i=$(($i+1))
                            namespace=${args[i]}
                            ;;
        -ds |  --display )  display=1
                            ;;
        -nf | --no-folder ) folder=0
                            ;;
        -s | --source     ) i=$(($i+1))
                            cpp_folder="${args[i]}/$class_name.cpp"
                            ;;
        -i | --include    ) i=$(($i+1))
                            hpp_folder="${args[i]}/$class_name.hpp"
                            ;;
        * )     echo "${args[i]} unknown flag"
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

function create_cppfile()
{
    echo  "/*
** EPITECH PROJECT, 2019
** $class_name.cpp
** File description:
** $desc
*/" > $cpp_folder
    echo -e "\n#include \"$class_name.hpp\"\n" >> $cpp_folder
    echo -e "$class_name::$class_name()\n{\n}\n" >> $cpp_folder
    echo -e "$class_name::~$class_name() {}" >> $cpp_folder
    
}

function create_hppfile()
{
     echo -e "/*
** EPITECH PROJECT, 2019
** $class_name.hpp
** File description:
** $desc
*/\n" > $hpp_folder
    echo -e "#ifndef ${class_name^^}_HPP_" >> $hpp_folder
    echo -e "#define ${class_name^^}_HPP_\n" >> $hpp_folder
    if [ "$namespace" != "" ]
    then
        echo -e "namespace $namespace\n{\n    class $class_name\n    {\n    public:\n        $class_name();\n        ~$class_name();" >> $hpp_folder
        echo -e "    private:\n    };\n}\n" >> "inc/$class_name.hpp" >> $hpp_folder
    else
        echo -e "class $class_name\n{\npublic:\n    $class_name();\n    ~$class_name();" >> $hpp_folder
        echo -e "private:\n};\n" >> $hpp_folder
    fi
    echo -e "#endif" >> $hpp_folder
}

source /home/bdelalex/my_scripts/utils.sh
args=("$@")
cpp_folder="$class_name.cpp"
hpp_folder="$class_name.hpp"
parse_input
echo "Creating $cpp_folder"
create_cppfile
echo -e "Creating $hpp_folder\n"
create_hppfile
if [ "$display" = "1" ]
then
    echo "----- CPP FILE -----"
    cat $cpp_folder
    echo -e "\n"
    echo "----- HPP FILE -----"
    cat $hpp_folder
fi
