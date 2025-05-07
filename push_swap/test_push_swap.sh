#!/bin/bash


COUNT=${1:-100}

ARG=($(shuf -i 1-1000 -n $COUNT))


valgrind --leak-check=full --track-origins=yes ./checker "${ARG[@]}" < /tmp/cmds.txt

./push_swap "${ARG[@]}" | tee /tmp/cmds.txt | ./checker "${ARG[@]}"
echo "Used:" $(wc -l < /tmp/cmds.txt)