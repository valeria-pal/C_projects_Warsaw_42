#!/bin/bash

# Кол-во чисел: по умолчанию 100, можно передать аргумент (например, ./test_push_swap.sh 500)
COUNT=${1:-100}

# Генерация массива случайных уникальных чисел от 1 до 1000
ARG=($(shuf -i 1-1000 -n $COUNT))

# Проверка валидности с выводом утечек памяти
valgrind --leak-check=full --track-origins=yes ./checker "${ARG[@]}" < /tmp/cmds.txt

# Сохраняем команды в файл
./push_swap "${ARG[@]}" | tee /tmp/cmds.txt | ./checker "${ARG[@]}"
echo "Used:" $(wc -l < /tmp/cmds.txt)
