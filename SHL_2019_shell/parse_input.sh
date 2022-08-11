function print_help() 
{
    echo "Usage: ./bdsh [OPTION]... [COMMAND] [REQUEST]
OPTION:
  -h				display usage
  -f FILE			json database file
  -j                json formated output for select command"
}

function parse_input()
{
json=0
filename=""
query=""
ct=0
i=0
while (( i  < ${#args[@]} ))
do
    args[$i]=$(echo ${args[$i]} | tr -d ' ')
    case ${args[i]} in
        -h )    print_help
                exit 0
                ;;
        -f )    i=$(($i+1))
                filename=${args[i]}
                ;;
        -j )    json=1
                ;;
        * )     query[$ct]="${args[i]}"
                ct=$((ct+1))
                ;;
    esac
    i=$(($i+1))
done
}