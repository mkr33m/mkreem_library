#ifndef macros_HPP
#define macros_HPP

#include <vector>
#include <queue>
#include <cmath>

using ll = long long;
using lll = __int128_t;
using ld = long double;
#define newl '\n'
#define REF const auto&
#define INF 1000390039
#define LLINF 1000000039000000039
#define IMAX INT_MAX
#define IMIN INT_MIN
#define LLMAX LONG_LONG_MAX
#define LLMIN LONG_LONG_MIN
#define BIT(i) (1LL << (i))
#define tbit(n, k) ((n >> k) & 1) // nの（上から）kビット目
#define bit(n, k) (n & (1LL << (k))) // nの（下から）kビット目
#define PI acos(-1)
#define inr(l, x, r) (l <= x && x < r)
#define einr(l, x, r) (l <= x && x <= r)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define erep(i, a, b) for(int i = (a); i <= (b); i++)
#define rrep(i, a, b) for(int i = (a); i >= (b); i--)
#define repl(i, a, b) for(long long i = (a); i < (b); i++)
#define erepl(i, a, b) for(long long i = (a); i <= (b); i++)
#define rrepl(i, a, b) for(long long i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FOR_subset(sub, bit) for (ll sub = (bit); sub >= 0; sub = (sub == 0 ? -1 : (sub - 1) & (bit)))
#define UNIQUE(v) (std::sort(all(v)), (v).erase(std::unique(all(v)), (v).end()))
#define pcnt(x) __builtin_popcount(x)
#define llpcnt(x) __builtin_popcountll(x)
#define VC(name, type, ...) vector<type> name(__VA_ARGS__)
#define VVC(name, type, a, ...) vector<vector<type>> name(a, vector<type>(__VA_ARGS__))
#define VVVC(name, type, a, b, ...) vector<vector<vector<type>>> name(a, vector<vector<type>>(b, vector<type>(__VA_ARGS__)))
#define VVVVC(name, type, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define VVVVVC(name, type, a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>> name(a, vector<vector<vector<vector<type>>>>(b, vector<vector<vector<type>>>(c, vector<vector<type>>(d, vector<type>(__VA_ARGS__)))));
template <typename T>
int lwb(const std::vector<T>& vec, const T& x){
    return lower_bound(all(vec), x) - vec.begin();
}
template <typename T>
int upb(const std::vector<T>& vec, const T& x){
    return upper_bound(all(vec), x) - vec.begin();
}
template <typename T>
T max(const std::vector<T>& vec){ return *max_element(all(vec)); }
template <typename T>
T min(const std::vector<T>& vec){ return *min_element(all(vec)); }
template <typename T>
T rad(const T& x){ return x * PI/180; }
template <typename T>
using maxpq = std::priority_queue<T>;
template <typename T>
using minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
// 最大値・最小値の更新
template <typename T1, typename T2>
bool chmax(T1 &a, const T2& b){
    if(a < b){ a = b; return 1; }
    else return 0;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2& b){
    if(a > b){ a = b; return 1; }
    else return 0;
}

const int di4[4] = {-1, 0, 1, 0};
const int dj4[4] = {0, 1, 0, -1};
const int di8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool out_of_grid(const int& i, const int& j, const int& h, const int& w){
    if(i < 0 || j < 0 || i >= h || j >= w) return true;
    return false;
}

#endif // macros_HPP