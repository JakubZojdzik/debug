/*
    -- Your name --
    --DATE--
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    tuple<int, string, double> x;
    get<0>(x) = 4;
    get<1>(x) = "abrakadabra";
    get<2>(x) = 3.14;
    debug(x);

    vpll y;
    y.pb({20000000000, 1});
    y.pb({3, 7});
    y.pb({400000000, 200000000000000000});
    debug(y);
    debug(y[0].se);

    priority_queue<int> pq;
    pq.push(5);
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);
    debug(pq);

    debug(x, y, pq);
}

/*
Given output:
[DEBUG L:42] x = {4, "abrakadabra", 3.14}
[DEBUG L:48] y = {{20000000000, 1}, {3, 7}, {400000000, 200000000000000000}}
[DEBUG L:49] y[0].se = 1
[DEBUG L:57] pq = {8, 5, 5, 2, 1}
[DEBUG L:59] x, y, pq = {4, "abrakadabra", 3.14}, {{20000000000, 1}, {3, 7}, {400000000, 200000000000000000}}, {8, 5, 5, 2, 1}
*/