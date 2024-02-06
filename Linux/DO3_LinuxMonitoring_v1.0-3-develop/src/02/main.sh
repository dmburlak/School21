#!/bin/bash

if ! command -v ifconfig &> /dev/null; then
    sudo apt-get update && sudo apt-get install -y net-tools
fi

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

echo "HOSTNAME = $HOSTNAME"
echo "TIMEZONE = $TIMEZONE"
echo "USER = $USER"
echo "OS = $OS"
echo "DATE = $DATE" 
echo "UPTIME = $UPTIME"
echo "UPTIME_SEC = $UPTIME_SEC"
echo "IP = $IP"
echo "MASK = $MASK"
echo "GATEWAY = $GATEWAY"
echo "RAM_TOTAL = $RAM_TOTAL"
echo "RAM_USED = $RAM_USED"
echo "RAM_FREE = $RAM_FREE"
echo "SPACE_ROOT = $SPACE_ROOT"
echo "SPACE_ROOT_USED = $SPACE_ROOT_USED"
echo "SPACE_ROOT_FREE = $SPACE_ROOT_FREE"


echo "Вы хотите записать данные в файл? (Y/N)"
read answer
if [ "$answer" = 'y' -o "$answer" = 'Y' ]
then
file_name=$(date +"%d_%m_%Y_%H_%M_%S")
echo "HOSTNAME = $HOSTNAME" >> $file_name.status
echo "TIMEZONE = $TIMEZONE" >> $file_name.status
echo "USER = $USER" >> $file_name.status
echo "OS = $OS" >> $file_name.status
echo "UPTIME = $UPTIME" >> $file_name.status
echo "UPTIME_SEC = $UPTIME_SEC" >> $file_name.status
echo "IP = $IP" >> $file_name.status
echo "MASK = $MASK" >> $file_name.status
echo "GATEWAY = $GATEWAY" >> $file_name.status
echo "RAM_TOTAL = $RAM_TOTAL" >> $file_name.status
echo "RAM_USED = $RAM_USED" >> $file_name.status
echo "RAM_FREE = $RAM_FREE" >> $file_name.status
echo "SPACE_ROOT = $SPACE_ROOT" >> $file_name.status
echo "SPACE_ROOT_USED = $SPACE_ROOT_USED" >> $file_name.status
echo "SPACE_ROOT_FREE = $SPACE_ROOT_FREE" >> $file_name.status
fi
