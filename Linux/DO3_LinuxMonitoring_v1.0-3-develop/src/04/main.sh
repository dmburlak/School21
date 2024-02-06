#!/bin/bash

source ./colors.cfg


bg_color_name() {
    case $1 in
        107) echo "white";;
        101) echo "red";;
        42) echo "green";;
        106) echo "blue";;
        105) echo "purple";;
        40) echo "black";;
    esac;
}

bg_color_number() {
    case $1 in
        107) echo "1";;
        101) echo "2";;
        42) echo "3";;
        106) echo "4";;
        105) echo "5";;
        40) echo "6";;        
        404) echo "default";;    
    esac;
}

ft_color_name() {
    case $1 in
        97) echo "white";;
        91) echo "red";;
        32) echo "green";;
        34) echo "blue";;
        95) echo "purple";;
        30) echo "black";;
    esac;
}

ft_color_number() {
    case $1 in
        97) echo "1";;
        91) echo "2";;
        32) echo "3";;
        34) echo "4";;
        95) echo "5";;
        30) echo "6";;        
        404) echo "default";;    
    esac;
}


about_sys () {
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

code_continue () {

    background_of_value_names=(107 101 42 106 105 40)
    font_of_value_names=(97 91 32 34 95 30)
    background_of_values=(107 101 42 106 105 40)
    font_of_values=(97 91 32 34 95 30)

    defaults=0

    for ((i=1; i<=$#; i++)); do
        current_value="${!i}"  # Получаем значение текущего параметра
        
        if ! [[ "$current_value" =~ ^[0-9]+$ ]] || [ "$current_value" -ge 7 ] || [ $# -ne 4 ]; then
            defaults=1
            break
        fi
    done

    if [ $defaults -eq 1 ] || [ "$1" = "$2" ] || [ "$3" = "$4" ]; then
        bk_value_names=${background_of_value_names[0]}
        ft_value_names=${font_of_value_names[1]}
        bk_values=${background_of_values[2]}
        ft_values=${font_of_values[3]}
        defaults=1
    else 
        bk_value_names=${background_of_value_names[$1 - 1]}
        ft_value_names=${font_of_value_names[$2 - 1]}
        bk_values=${background_of_values[$3 - 1]}
        ft_values=${font_of_values[$4 - 1]}  
    fi  
}

output_code () {
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

output_stat () {
    if [ $defaults -eq 1 ]; then
        # дефолт = 1, выводим значения по умолчанию
        def_num=404
        echo ""
        echo "Column 1 background =" "$( bg_color_number ${def_num} )" "($( bg_color_name ${bk_value_names} ))"
        echo "Column 1 font color =" "$( ft_color_number ${def_num} )" "($( ft_color_name ${ft_value_names} ))"
        echo "Column 2 background =" "$( bg_color_number ${def_num} )" "($( bg_color_name ${bk_values} ))"
        echo "Column 2 font color =" "$( ft_color_number ${def_num} )" "($( ft_color_name ${ft_values} ))"
    else
        # дефолт = 0, выводим заданные значения 
        echo ""   
        echo "Column 1 background =" "$( bg_color_number ${bk_value_names} )" "($( bg_color_name ${bk_value_names} ))"
        echo "Column 1 font color =" "$( ft_color_number ${ft_value_names} )" "($( ft_color_name ${ft_value_names} ))"
        echo "Column 2 background =" "$( bg_color_number ${bk_values} )" "($( bg_color_name ${bk_values} ))"
        echo "Column 2 font color =" "$( ft_color_number ${ft_values} )" "($( ft_color_name ${ft_values} ))"
    fi
}

code_continue ${column1_background} ${column1_font_color} ${column2_background} ${column2_font_color}
about_sys
output_code  ${column1_background} ${column1_font_color} ${column2_background} ${column2_font_color}
output_stat 
