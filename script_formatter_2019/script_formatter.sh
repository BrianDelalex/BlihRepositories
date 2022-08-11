function help
{
    for args in $@; do
        if [ $args == "-help" ]; then
            return 0
        fi
    done
    return 1
}

function printHelp
{
    echo "Usage: script_formatter.sh in [-h] [-s] [-i nb_char] [-e] [-o out]
      in                      input file
    -h, --header              header generation
    -s, --spaces              force spaces instead of tabulations for indentation
    -i, --indentation=nb_char number of characters for indentation (8 by default)
    -e, --expand              force do and then keywords on new lines
    -o, --output=out          output file (stdout by default)"
}

function write_header
{
    line=${line#"${line%%[![:space:]]*}"}
    line=${line#"${line##*[![:space:]]}"}
    if [ $CursorHeader == 1 ] && [ $Header == 1 ] && [[  $line != *"#!/bin/sh"* ]] && [[ ${line:0:1} != *"#"* ]] && [ ${#line} != 0 ]; then
        echo "#####################" >> $FILE; echo "" >> $FILE
        CursorHeader=0
    elif [ $CursorHeader == 1 ] && [[  $line != *"#!/bin/sh"* ]] && [[ ${line:0:1} == *"#"* ]] && [ ${#line} != 0 ]; then
        echo $line >> $FILE
    elif [ $CursorHeader == 1 ] && [[  $line != *"#!/bin/sh"* ]] && [[ ${line:0:1} != *"#"* ]] && [ ${#line} != 0 ]; then
        echo "" >> $FILE
        CursorHeader=0
    fi
}

function read_header
{
    line=${line#"${line%%[![:space:]]*}"}
    line=${line#"${line##*[![:space:]]}"}
    if [ $CursorHeader == 1 ] && [ $Header == 1 ] && [[  $line != *"#!/bin/sh"* ]] && [[ ${line:0:1} != *"#"* ]] && [ ${#line} != 0 ]; then
        echo "#####################"; echo ""
        CursorHeader=0
    elif [ $CursorHeader == 1 ] && [[  $line != *"#!/bin/sh"* ]] && [[ ${line:0:1} == *"#"* ]] && [ ${#line} != 0 ]; then
        echo $line
    elif [ $CursorHeader == 1 ] && [[  $line != *"#!/bin/sh"* ]] && [[ ${line:0:1} != *"#"* ]] && [ ${#line} != 0 ]; then
        echo ""
        CursorHeader=0
    fi
}


function update_indentation
{
    if [ $1 == 0 ]; then SpaceIndentation=""
    else
        Value=$(($Indentation*$1))
        if [ $Space == 0 ]; then SpaceIndentation=`printf "%"$Value"s" $'\t'`; else SpaceIndentation=`printf "%"$Value"s" ' '`; fi
    fi
}

function write_if_extend
{
    update_indentation $CursorIf
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorIf} != $Level ] && [ ${CursorIf} -lt $Level ]; then echo "$SpaceIndentation${FORMAT[0]}" >> $FILE; echo "${SpaceIndentation}then" >> $FILE; CursorIf=$Level; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"then"* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            update_indentation $CursorIf
            echo "$SpaceIndentation${ins[@]:1}" >> $FILE;
        elif [[ ${ins} == *"fi"* ]]; then
            let "Level -= 1"
            let "CursorIf -= 1"
            update_indentation $CursorIf
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}" >> $FILE;
        elif [[ ${ins} != *"then"* ]] && [[ ${ins} != *"if"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}" >> $FILE;
        fi
    done
}

function read_if_extend
{
    update_indentation $CursorIf
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorIf} != $Level ] && [ ${CursorIf} -lt $Level ]; then echo "$SpaceIndentation${FORMAT[0]}"; echo "${SpaceIndentation}then"; CursorIf=$Level; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"then"* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            update_indentation $CursorIf
            echo "$SpaceIndentation${ins[@]:1}";
        elif [[ ${ins} == *"fi"* ]]; then
            let "Level -= 1"
            let "CursorIf -= 1"
            update_indentation $CursorIf
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}";
        elif [[ ${ins} != *"then"* ]] && [[ ${ins} != *"if"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}";
        fi
    done
}

function write_if_not_extend
{
    update_indentation $CursorIf
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorIf} != $Level ] && [ ${CursorIf} -lt $Level ]; then echo "$SpaceIndentation${FORMAT[0]}; then" >> $FILE; CursorIf=$Level; fi
    if [ ${CursorIf} == 0 ]; then echo ${FORMAT[0]}"; then" >> $FILE; CursorIf=1; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"then"* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            update_indentation $CursorIf
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            echo "$SpaceIndentation${ins[@]:1}" >> $FILE;
        elif [[ ${ins} == *"fi"* ]]; then 
            let "Level -= 1"
            let "CursorIf -= 1"
            update_indentation $CursorIf
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}" >> $FILE;
        elif [[ ${ins} != *"then"* ]] && [[ ${ins} != *"if"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins[@]}" >> $FILE;
        fi
    done
}

function read_if_not_extend
{
    update_indentation $CursorIf
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorIf} != $Level ] && [ ${CursorIf} -lt $Level ]; then echo "$SpaceIndentation${FORMAT[0]}; then"; CursorIf=$Level; fi
    if [ ${CursorIf} == 0 ]; then echo ${FORMAT[0]}"; then"; CursorIf=1; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"then"* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            update_indentation $CursorIf
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            echo "$SpaceIndentation${ins[@]:1}";
        elif [[ ${ins} == *"fi"* ]]; then 
            let "Level -= 1"
            let "CursorIf -= 1"
            update_indentation $CursorIf
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}";
        elif [[ ${ins} != *"then"* ]] && [[ ${ins} != *"if"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins[@]}";
        fi
    done
}

function write_if
{
    if [ $Extend == 0 ]; then 
        write_if_not_extend
    else
        write_if_extend
    fi
}

function read_if
{
    if [ $Extend == 0 ]; then 
        read_if_not_extend
    else
        read_if_extend
    fi
}


function write_for_and_while_extend
{
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorWhile} == 0 ]; then echo ${FORMAT[0]} >> $FILE; echo "do" >> $FILE; CursorWhile=$Level; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"do "* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins[@]:1}" >> $FILE;
        elif [[ ${ins} == *"done"* ]]; then 
            let "Level -= 1"
            let "CursorWhile -= 1"
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins}" >> $FILE;
        elif [[ ${ins} != *"do"* ]] && [[ ${ins} != *"for"* ]] && [[ ${ins} != *"while"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins}" >> $FILE;
        fi
    done
}

function read_for_and_while_extend
{
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorWhile} == 0 ]; then echo ${FORMAT[0]}; echo "do"; CursorWhile=1; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"do "* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins[@]:1}";
        elif [[ ${ins} == *"done"* ]]; then 
            let "Level -= 1"
            let "CursorWhile -= 1"
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins}"
        elif [[ ${ins} != *"do"* ]] && [[ ${ins} != *"for"* ]] && [[ ${ins} != *"while"* ]]; then
            update_indentation $CursorWhile
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}";
        fi
    done
}

function write_for_and_while_not_extend
{
    update_indentation $CursorWhile
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorWhile} == 0 ]; then echo ${FORMAT[0]}"; do" >> $FILE; CursorWhile=$Level; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"do "* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins[@]:1}" >> $FILE;
        elif [[ ${ins} == *"done"* ]]; then 
            let "Level -= 1"
            let "CursorWhile -= 1"
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins}" >> $FILE;
      elif [[ ${ins} != *"do"* ]] && [[ ${ins} != *"for"* ]] && [[ ${ins} != *"while"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}" >> $FILE;
        fi
    done
}

function read_for_and_while_not_extend
{
    update_indentation $CursorWhile
    IFS=';' read -ra TABLE <<< ${line}
    IFS=$'\r' read -ra FORMAT <<< ${TABLE}
    if [ ${CursorWhile} == 0 ]; then echo ${FORMAT[0]}"; do"; CursorWhile=$Level; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"do "* ]]; then 
            IFS=' ' read -ra ins <<< "$ins"
            if [[ ${#ins[@]} == 1 ]]; then return; fi
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins[@]:1}"
        elif [[ ${ins} == *"done"* ]]; then 
            let "Level -= 1"
            let "CursorWhile -= 1"
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            update_indentation $CursorWhile
            echo "$SpaceIndentation${ins}"
      elif [[ ${ins} != *"do"* ]] && [[ ${ins} != *"for"* ]] && [[ ${ins} != *"while"* ]]; then
            ins=${ins#"${ins%%[![:space:]]*}"}
            ins=${ins#"${ins##*[![:space:]]}"}
            echo "$SpaceIndentation${ins}"
        fi
    done
}

function write_for_and_while
{
    if [ $Extend == 0 ]; then 
        write_for_and_while_not_extend
    else
        write_for_and_while_extend
    fi
}

function read_for_and_while
{
    if [ $Extend == 0 ]; then 
        read_for_and_while_not_extend
    else
        read_for_and_while_extend
    fi
}


function write_function() 
{
    IFS=';' read -ra TABLE <<< ${line##*"{"}
    if [ ${CursorFunction} == 0 ]; then echo ${line%% "{"*} >> $FILE; echo "{" >> $FILE; CursorFunction=1; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"}"* ]]; then 
            echo "}" >> $FILE; echo "" >> $FILE
            CursorFunction=0
        elif [[ ${ins} != *"function"* ]] ; then
            IFS=' ' read -ra ins <<< "$ins"
            update_indentation $CursorFunction
            echo "$SpaceIndentation${ins[@]}" >> $FILE
        fi
    done
}

function read_function() 
{
    IFS=';' read -ra TABLE <<< ${line##*"{"}
    if [ ${CursorFunction} == 0 ]; then echo ${line%% "{"*}; echo "{"; CursorFunction=1; fi
    for ins in "${TABLE[@]}"; do
        if [[ ${ins} == *"}"* ]]; then 
            echo "}"; echo ""
            CursorFunction=0
        elif [[ ${ins} != *"function"* ]] ; then
            IFS=' ' read -ra ins <<< "$ins"
            update_indentation $CursorFunction
            echo "$SpaceIndentation${ins[@]}"
        fi
    done
}

function write_body 
{
    if [ $CursorHeader == 1 ]; then
        return;
    fi
    if [[ ${line:0:2} == *"if"* ]] || [[ ${line:0:3} == *"for"* ]] || [[ ${line:0:5} == *"while"* ]]; then
        let "Level += 1"
    fi
    if [[ ${line:0:2} == *"if"* ]] || [ $CursorIf -gt 0 ]; then
        write_if
    elif [[ ${line:0:3} == *"for"* ]] || [[ ${line:0:5} == *"while"* ]] || [ $CursorWhile == 1 ]; then
        write_for_and_while
    elif [[ ${line:0:8} == *"function"* ]] || [ $CursorFunction == 1 ]; then
        write_function
    else
        echo $line >> $FILE
    fi
}


function read_body 
{
    if [ $CursorHeader == 1 ]; then
        return;
    fi
    if [[ ${line:0:2} == *"if"* ]] || [[ ${line:0:3} == *"for"* ]] || [[ ${line:0:5} == *"while"* ]]; then
        let "Level += 1"
    fi
    if [[ ${line:0:2} == *"if"* ]] || [ $CursorIf -gt 0 ]; then
        read_if
    elif [[ ${line:0:3} == *"for"* ]] || [[ ${line:0:5} == *"while"* ]] || [ $CursorWhile == 1 ]; then
        read_for_and_while
    elif [[ ${line:0:8} == *"function"* ]] || [ $CursorFunction == 1 ]; then
        read_function
    else
        echo $line
    fi
}


function prepare_file 
{
    Level=0
    CursorIf=0
    CursorWhile=0
    CursorHeader=1
    CursorFunction=0
    if [ $Space == 0 ]; then SpaceIndentation=`printf "%"$Indentation"s" \t`; else SpaceIndentation=`printf "%"$Indentation"s" ' '`; fi
    FILE=$OutputFile".temp"
    if [[ -f "$FILE" ]] && [ $1 == 0 ]; then
        rm $FILE
    fi
    if [ $1 == 0 ]; then
        echo "#!/bin/sh" >> $FILE; echo "" >> $FILE
    else
        echo "#!/bin/sh"; echo ""
    fi
}


function cat_beautify
{
    prepare_file 1
    if [ $Header == 1 ]; then echo "#####################"; echo "#"; echo "# no filename"; echo "# "$(date '+%dth %B, %Y'); echo "# "; fi
    
    while read line; do
        read_header
        read_body
    done < $InputFile
}

function write_file
{
    prepare_file 0
    if [ $Header == 1 ]; then echo "#####################" >> $FILE; echo "#" >> $FILE; echo "# "$OutputFile >> $FILE; echo "# "$(date +%Y/%m/%d) >> $FILE; echo "# " >> $FILE; fi
    
    while read line; do
        write_header
        write_body
    done < $InputFile
    mv $FILE $OutputFile
}

function setConfig
{
    InputFile=$1
    OutputFile=-1
    Indentation=8
    Header=0
    Space=0
    Extend=0
    args=("$@")
    for i in $(seq ${#@}); do
        case ${args[$i - 1]} in
            "-h" | "--header") Header=1;;
            "-o" | "--output="*) if [[ ${args[$i - 1]} == *"--output="* ]]; then OutputFile=${args[$i - 1]##*=}; else OutputFile=${args[$i]}; fi;;
            "-s" | "--space") Space=1;;
            "-e" | "--extend") Extend=1;;
            "-i" | "--indentation="*) if [[ ${args[$i - 1]} == *"--indentation="* ]]; then Indentation=${args[$i - 1]##*=}; else Indentation=${args[$i]}; fi;;
            *"-"*) if [[ ${args[$i - 1]} == *"s"* ]]; then Space=1; fi; if [[ ${args[$i - 1]} == *"h"* ]]; then Header=1; fi; if [[ ${args[$i - 1]} == *"e"* ]]; then Extend=1; fi;;
        esac
    done
    if [ ${#OutputFile} == 0 ]; then 
        echo "Error output file don't have name"
        exit 84;
    elif [ ${OutputFile} != -1 ]; then
        write_file
    else
        cat_beautify
    fi
}

function params
{
    if help $@; then
        printHelp 
        return
    fi
    if test -f "$1"; then
        setConfig $@
    else
        echo "Error file not exist !"
        exit 84
    fi
}
params $@
exit 0