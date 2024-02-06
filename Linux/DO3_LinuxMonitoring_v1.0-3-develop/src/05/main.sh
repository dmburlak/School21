#!/bin/bash

start=$( date +%s )

path=$1

# Топ 10 файлов с самым большим весом в порядке убывания (путь, размер и тип)
top_files () {
    i=1
    find $1 -type f -exec du -h {} \; 2>/dev/null | sort -hr | head -10 | while IFS= read -r file_line; do
        file=$( echo $file_line | cut -d ' ' -f2 )
        size=$( echo $file_line | cut -d ' ' -f1 )
        type=$( file -b $file | cut -f1 -d ',' )
        echo "$i - $file, $size, $type"
        i=$(( $i + 1 ))
    done
}

# Топ 10 исполняемых файлов с самым большим весом в порядке убывания (путь, размер и хеш)
ex_files () {
    i=1
    find $1 -type f -executable -exec du -h {} \; 2>/dev/null | sort -hr | head -10 | while IFS= read -r file_line; do
        file=$( echo $file_line | cut -d ' ' -f2 )
        size=$( echo $file_line | cut -d ' ' -f1 )
        hash=$( md5sum $file | cut -f1 -d ' ' )
        echo "$i - $file, $size, $hash"
        i=$(( $i + 1 ))
    done
}

all_data () {
    # Общее число папок, включая вложенные
    total_folders=$( du "$1" 2>/dev/null | wc -l )

    # Топ 5 папок с самым большим весом в порядке убывания (путь и размер)
    top_folders=$( du -h "$1"* 2>/dev/null | sort -hr | head -n 5 | awk '{print NR " - " $2 ", " $1}' )

    # Общее число файлов
    total_files=$( find "$1" -type f 2>/dev/null | wc -l )

    # Число конфигурационных файлов (с расширением .conf), текстовых файлов, исполняемых файлов, логов (файлов с расширением .log), архивов, символических ссылок
    conf_files=$(find "$1" -type f -name "*.conf" 2>/dev/null | wc -l)
    txt_files=$(find "$1" -type f -name "*.txt" 2>/dev/null | wc -l)
    exe_files=$(find "$1" -type f -executable 2>/dev/null | wc -l)
    log_files=$(find "$1" -type f -name "*.log" 2>/dev/null | wc -l)
    archive_files=$(find "$1" -type f \( 2>/dev/null -name "*.zip" -o -name "*.7z" -o -name "*.tar" -o -name "*.rar" -o -name "*.gz" \) | wc -l)
    symlinks=$(find "$1" -type l 2>/dev/null | wc -l)

    echo "Total number of folders (including all nested ones) = $total_folders"
    echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
    echo "$top_folders"
    echo "Total number of files = $total_files"
    echo "Number of:"
    echo "Configuration files (with the .conf extension) = $conf_files"
    echo "Text files = $txt_files"
    echo "Executable files = $exe_files"
    echo "Log files (with the extension .log) = $log_files"
    echo "Archive files = $archive_files"
    echo "Symbolic links = $symlinks"
    echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
    top_files $1
    echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"
    ex_files $1
    # Время выполнения скрипта
    echo "Script execution time (in seconds) =" $(( $( date +%s ) - $start ))

}



# Проверяем, предоставил ли пользователь аргумент пути
if [ $# -eq 0 ]; then
    echo "Ошибка: путь не задан."
    exit 1
else 
    # Проверяем, закрыл ли пользователь путь "/"
    if [ "${path: -1}" != "/" ]; then
        echo "Путь до папки должен заканчиваться на '/'."
        exit 1
    else 
        # Проверяем, является ли предоставленный аргумент каталогом
        if [ ! -d "$path" ]; then
            echo "Ошибка: Папка не существует."
            exit 1
        else
            all_data $path
        fi
    fi
fi
