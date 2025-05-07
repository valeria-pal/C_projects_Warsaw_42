#!/bin/bash


COUNT=${1:-100}

ARG=($(seq -1000 1000 | shuf -n $COUNT))


valgrind --leak-check=full --track-origins=yes ./checker "${ARG[@]}" < /tmp/cmds.txt

./push_swap "${ARG[@]}" | tee /tmp/cmds.txt | ./checker "${ARG[@]}"
echo "Used:" $(wc -l < /tmp/cmds.txt)