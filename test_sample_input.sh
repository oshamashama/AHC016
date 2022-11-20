#!/bin/bash

ZIP_FILE="d5f3c281.zip"
if [ ! -d "tools" ]; then
    if  [ ! -f "$ZIP_FILE" ]; then
        wget https://img.atcoder.jp/ahc016/d5f3c281.zip
    fi
    unzip "$ZIP_FILE"
    rm "$ZIP_FILE"
elif  [ -f "$ZIP_FILE" ]; then
    rm "$ZIP_FILE"
fi


g++ --std=c++17 main.cpp

# rm ./tools/vis/*
rm ./tools/in/*.out

touch last_score
rm last_score
touch last_score

cd tools
sum=0
count=0

# for IN_FILE in in/*.txt ;
# do
#     ../a.out < $IN_FILE > ${IN_FILE%.txt}.out &
# done
# wait
touch all_out
rm all_out
for IN_FILE in in/*.txt ;
do
    # echo $IN_FILE
    f1=${IN_FILE#in/}
    OUT_FILE=./in/${f1%.txt}.out
    touch tmp_out
    cargo run --release --bin tester ../a.out < $IN_FILE > $OUT_FILE 2> tmp_out
    Score=`tail +6 tmp_out`
    cat tmp_out >> all_out
    rm tmp_out
    Score_num=${Score#Score\ =\ }
    echo $Score_num >> ../last_score
    count=$((count + 1))
    sum=$((Score_num + sum))
    # mv vis.html vis/vis${f1%.txt}.html
    echo "Score = "$Score_num", test_file : "$IN_FILE >&2
done

# printf "%'d\n" $((sum / count))
echo $((sum / count))  | sed -E ':l; s/^([0-9]+)([0-9]{3})/\1,\2/; t l;';
# printf "%'d\n" $((sum / count * 50))
echo $((sum / count * 50))  | sed -E ':l; s/^([0-9]+)([0-9]{3})/\1,\2/; t l;';
# printf "%'d\n" $sum
echo $sum  | sed -E ':l; s/^([0-9]+)([0-9]{3})/\1,\2/; t l;';


