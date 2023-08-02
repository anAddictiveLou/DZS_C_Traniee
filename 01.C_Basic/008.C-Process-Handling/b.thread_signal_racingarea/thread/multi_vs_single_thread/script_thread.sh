#!bin/sh
BEGIN=1
END=100000000
NUM_RUNS=100
PROGRAM="./multi_thread $BEGIN $END"
FILE="result_multi_threads"
TIME="/usr/bin/time"

rm -rf $FILE

# Loop to run the program multiple times.
echo -e "X, Y\n" >> $FILE
for ((i = 1; i <= NUM_RUNS; i++)); do
    ($TIME -f "%e" $PROGRAM $i) >> $FILE 2>&1
done

