g++ main.cpp
cd tools
echo "---V---1---V---"
cargo run --release --bin tester ../a.out 1 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---3---V---"
cargo run --release --bin tester ../a.out 3 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---5---V---"
cargo run --release --bin tester ../a.out 5 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---7---V---"
cargo run --release --bin tester ../a.out 7 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---9---V---"
cargo run --release --bin tester ../a.out 9 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---11---V---"
cargo run --release --bin tester ../a.out 11 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---13---V---"
cargo run --release --bin tester ../a.out 13 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---15---V---"
cargo run --release --bin tester ../a.out 15 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---25---V---"
cargo run --release --bin tester ../a.out 25 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---29---V---"
cargo run --release --bin tester ../a.out 29 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
echo "---V---35---V---"
cargo run --release --bin tester ../a.out 35 < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out
# cargo run --release --bin tester python3 sample.py < ./in_M050_e40/0000.txt > ./in_M050_e40/0000.out