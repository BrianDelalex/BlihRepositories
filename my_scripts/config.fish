set -gx PATH /home/bdelalex/my_scripts/ $PATH
set -gx PATH /home/bdelalex/.cargo/bin $PATH
set -gx lib ~/delivery/my_lib/
## Alias git
alias gpm "sh gpm.sh"
alias gp "sh gp.sh"
alias gc "sh gc.sh"
alias gcm "git checkout master"
alias gmm "sh gmm.sh"
alias gm "sh gm.sh"
function clone
    set rep "git@git.epitech.eu:/brian.delalex@epitech.eu/"$argv[1]
    git clone $rep
end
function cloneo
    set rep "git@git.epitech.eu:/"$argv[1]"/"$argv[2]
    git clone $rep
end
function clonegh
    set rep "https://github.com/"$argv[1]
    git clone $rep
end
#alias maison "ssh btcombo@btcombossh.ddns.net"
alias tek "cd /home/bdelalex/delivery"
alias CONNECTION "nmcli radio wifi off; nmcli radio wifi on"
#alias rmrf "rm -rf $1"
alias pers "cd ~/personnal/"
function go
    set  to "/home/bdelalex/delivery/"$argv[1]"/"$argv[1]"_"$argv[2]"_2019"
    echo $to
    cd $to
end
#alias CPP
alias class "sh create_class.sh"
#
alias ls "ls --color"
alias header "cat /home/bdelalex/Documents/my_scripts/header"
alias doc "cd /home/bdelalex/Documents"
#alias pair "bluetoothctl connect 19:12:02:07:63:05"
#alias disconnect "bluetoothctl disconnect"
alias download "cd /home/bdelalex/Downloads"
alias cl "clear"
alias si3 "startx /usr/bin/i3"
alias pmr "prepare_my_repo.sh"
alias shutdown "shutdown -h 0"
alias gs "git status"
alias lock "i3lock -i ~/Pictures/wallpaper.png"
#alias psu "cd home/bdelalex/delivery/PSU/"
#alias cpe "cd home/bdelalex/delivery/CPE/"
#alias oop "cd home/bdelalex/delivery/OOP/"
#alias math "cd home/bdelalex/delivery/MATH/"
#alias mul "cd home/bdelalex/delivery/MUL/"
alias makr "make re"
alias makf "make fclean"
alias scripts "cd /home/bdelalex/my_scripts"
alias lscripts "ls /home/bdelalex/my_scripts"
alias grt "give_rigth_to.sh"
alias img "qimgv"
alias aliases "kak ~/.config/fish/config.fish"
alias vg "valgrind"
alias search2 "sudo find / -name $1"
alias search "sudo find /home -name $1"
