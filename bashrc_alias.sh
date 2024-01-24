c() {
    if [[ "$1" != "" ]]
    then
        g++ -DLOCAL -O3 -static "$1" -std=c++20 -o main
    else
        g++ -DLOCAL -O3 -static main.cpp -std=c++20 -o main
    fi
}