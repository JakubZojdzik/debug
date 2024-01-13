# Add this function at the end of your .bashrc or .zshrc file to create `c` alias compiling your program with standard competition flags

c() {
    if [[ "$1" != "" ]]
    then
        g++ -O3 -static "$1" -std=c++20 -o main
    else
        g++ -O3 -static main.cpp -std=c++20 -o main
    fi
}
