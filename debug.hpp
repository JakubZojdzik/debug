#include <iostream>

template <typename T, typename V>
void __print(const std::pair<T, V> &x);

template <typename... T>
void __print(const std::tuple<T...> &x);

template <typename T>
void __print(std::stack<T> x);

template <typename T>
void __print(std::queue<T> x);

template <typename T, typename... V>
void __print(std::priority_queue<T, V...> x);

template <typename T>
void __print(const T &x);

template <typename T, typename... V>
void _print(T t, V... v);

void __print(int x) { std::cerr << x; }
void __print(long x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(unsigned x) { std::cerr << x; }
void __print(unsigned long x) { std::cerr << x; }
void __print(unsigned long long x) { std::cerr << x; }
void __print(float x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(long double x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const std::pair<T, V> &x)
{
    std::cerr << '{';
    __print(x.first);
    std::cerr << ", ";
    __print(x.second);
    std::cerr << '}';
}

template <typename... T>
void __print(const std::tuple<T...> &x)
{
    bool first = true;
    std::cerr << '{';
    apply(
        [&first](const auto &...args)
        {
            ((std::cerr << (first ? "" : ", "), __print(args), first = false), ...);
        },
        x);
    std::cerr << '}';
}

template <typename T>
void __print(std::stack<T> x)
{
    std::vector<T> debugVector;
    while (!x.empty())
    {
        T t = x.top();
        debugVector.push_back(t);
        x.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}

template <typename T>
void __print(std::queue<T> x)
{
    std::vector<T> debugVector;
    while (!x.empty())
    {
        T t = x.front();
        debugVector.push_back(t);
        x.pop();
    }
    __print(debugVector);
}

template <typename T, typename... V>
void __print(std::priority_queue<T, V...> x)
{
    std::vector<T> debugVector;
    while (!x.empty())
    {
        T t = x.top();
        debugVector.push_back(t);
        x.pop();
    }
    __print(debugVector);
}

template <typename T>
void __print(const T &x)
{
    int f = 0;
    std::cerr << '{';
    for (auto &i : x)
        std::cerr << (f++ ? ", " : ""), __print(i);
    std::cerr << "}";
}

void _print() { std::cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        std::cerr << ", ";
    _print(v...);
}

#define debug(...) std::cerr << "[DEBUG L:" << __LINE__ << "] " << #__VA_ARGS__ << " = "; _print(__VA_ARGS__)
