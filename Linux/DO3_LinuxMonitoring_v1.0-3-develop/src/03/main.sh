#!/bin/bash


code_continue () {

        # Проверка, что все цвета шрифта отличаются от фона имен значений

                # Выполнение расчетов

                part1=$( timedatectl show --value --property=Timezone )
                part2=$( date +%:::z )

                HOSTNAME=$(hostname)
                TIMEZONE=$(echo $part1 UTC $part2)
                USER=$(whoami)
                OS=$(hostnamectl | grep 'Operating System' | sed 's/Operating System: //')
                DATE=$(date +"%d %B %Y %H:%M:%S")
                UPTIME=$(uptime | awk '{print $3}')
                UPTIME_SEC=$(cat /proc/uptime | awk '{print $1}')
                IP=$(ifconfig | awk 'NR == 2{print$2}')
                MASK=$(ifconfig | awk 'NR == 2{print$4}')
                GATEWAY=$(ifconfig | awk 'NR == 2{print$6}')
                RAM_TOTAL=$(free -k | awk '/Mem/ {printf "%.3f GB\n", $2/1024/1024}')
                RAM_USED=$(free -k | awk '/Mem/ {printf "%.3f GB\n", $3/1024/1024}')
                RAM_FREE=$(free -k | awk '/Mem/ {printf "%.3f GB\n", $4/1024/1024}')
                SPACE_ROOT=$(df -BM / | awk 'NR==2 {printf "%.2f MB\n", $2}')
                SPACE_ROOT_USED=$(df -BM / | awk 'NR==2 {printf "%.2f MB\n", $3}')
                SPACE_ROOT_FREE=$(df -BM / | awk 'NR==2 {printf "%.2f MB\n", $4}')
}


output_code () {

# Настройка цветов

        background_of_value_names=(107 101 42 106 105 40)
        font_of_value_names=(97 91 32 34 95 30)
        background_of_values=(107 101 42 106 105 40)
        font_of_values=(97 91 32 34 95 30)

        bk_value_names=${background_of_value_names[$1 - 1]}
        ft_value_names=${font_of_value_names[$2 - 1]}
        bk_values=${background_of_values[$3 - 1]}
        ft_values=${font_of_values[$4 - 1]}
        
# Вывод значений на экран с цветами

        echo -e "\e[${ft_value_names};${bk_value_names}mHOSTNAME = \e[0m\e[${ft_values};${bk_values}m$HOSTNAME\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mTIMEZONE = \e[0m\e[${ft_values};${bk_values}m$TIMEZONE\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mUSER = \e[0m\e[${ft_values};${bk_values}m$USER\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mOS = \e[0m\e[${ft_values};${bk_values}m$OS\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mDATE = \e[0m\e[${ft_values};${bk_values}m$DATE\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mUPTIME = \e[0m\e[${ft_values};${bk_values}m$UPTIME\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mUPTIME_SEC = \e[0m\e[${ft_values};${bk_values}m$UPTIME_SEC\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mIP = \e[0m\e[${ft_values};${bk_values}m$IP\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mMASK = \e[0m\e[${ft_values};${bk_values}m$MASK\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mGATEWAY = \e[0m\e[${ft_values};${bk_values}m$GATEWAY\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mRAM_TOTAL = \e[0m\e[${ft_values};${bk_values}m$RAM_TOTAL\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mRAM_USED = \e[0m\e[${ft_values};${bk_values}m$RAM_USED\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mRAM_FREE = \e[0m\e[${ft_values};${bk_values}m$RAM_FREE\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mSPACE_ROOT = \e[0m\e[${ft_values};${bk_values}m$SPACE_ROOT\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mSPACE_ROOT_USED = \e[0m\e[${ft_values};${bk_values}m$SPACE_ROOT_USED\\e[0m"
        echo -e "\e[${ft_value_names};${bk_value_names}mSPACE_ROOT_FREE = \e[0m\e[${ft_values};${bk_values}m$SPACE_ROOT_FREE\\e[0m"

}


# Проверка, что все 4 параметра заданы пользователем

if [ "$#" -ne 4 ]; then
        echo "Error. Invalid arguments. Please, сhoose 4 colors, where:"
        echo "    Parameter 1  - background of the value names"
        echo "    Parameter 2  - font colour of the value names"
        echo "    Parameter 3  - background of the values"
        echo "    Parameter 4  - font colour of the values"
        echo " Available colors:"
        echo "    1 - white"
        echo "    2 - red"
        echo "    3 - green"
        echo "    4 - blue"
        echo "    5 - purple"
        echo "    6 - black"
        exit 1
else
         # Проверка, что параметры являются числами и находятся в пределах диапазона [1..6]

        if [ "$1" = "$2" ] || [ "$3" = "$4" ]; then
                echo "The font color and the background of the same column should not match. Try again."
        else 

                for i in "$@"; do

                        if [[ "${i}" =~ ^[1-9]+$ ]]; then                

                                code_continue "$1" "$2" "$3" "$4"
                                
                        else
                                echo "Error: Parameter color must be a number between 1 and 6."
                                echo "Available colors:"
                                echo "   1 - white"
                                echo "   2 - red"
                                echo "   3 - green"
                                echo "   4 - blue"
                                echo "   5 - purple"
                                echo "   6 - black"
                                exit 1
                        fi
                done

        output_code  "$1" "$2" "$3" "$4"        

        fi 
        
        
fi
