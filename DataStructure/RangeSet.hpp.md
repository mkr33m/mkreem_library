---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u958B\u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B"
    links:
    - https://atcoder.jp/contests/abc330/tasks/abc330_e
  bundledCode: "#line 1 \"DataStructure/RangeSet.hpp\"\n\n\n\n/*\nverify\n\u30FBhttps://atcoder.jp/contests/abc330/tasks/abc330_e\n\
    */\n\n#include <vector>\n#include <set>\n#include <limits>\n#include <iostream>\n\
    \n#line 1 \"Others/macros.hpp\"\n\n\n\n#line 5 \"Others/macros.hpp\"\n#include\
    \ <queue>\n#include <cmath>\n\nusing ll = long long;\nusing lll = __int128_t;\n\
    using ld = long double;\n#define newl '\\n'\n#define REF const auto&\n#define\
    \ INF 1000390039\n#define LLINF 1000000039000000039\n#define IMAX INT_MAX\n#define\
    \ IMIN INT_MIN\n#define LLMAX LONG_LONG_MAX\n#define LLMIN LONG_LONG_MIN\n#define\
    \ BIT(i) (1LL << (i))\n#define tbit(n, k) ((n >> k) & 1) // n\u306E\uFF08\u4E0A\
    \u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define bit(n, k) (n & (1LL << (k)))\
    \ // n\u306E\uFF08\u4E0B\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n#define PI\
    \ acos(-1)\n#define inr(l, x, r) (l <= x && x < r)\n#define einr(l, x, r) (l <=\
    \ x && x <= r)\n#define rep(i, a, b) for(int i = (a); i < (b); i++)\n#define erep(i,\
    \ a, b) for(int i = (a); i <= (b); i++)\n#define rrep(i, a, b) for(int i = (a);\
    \ i >= (b); i--)\n#define repl(i, a, b) for(long long i = (a); i < (b); i++)\n\
    #define erepl(i, a, b) for(long long i = (a); i <= (b); i++)\n#define rrepl(i,\
    \ a, b) for(long long i = (a); i >= (b); i--)\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define FOR_subset(sub, bit) for (ll\
    \ sub = (bit); sub >= 0; sub = (sub == 0 ? -1 : (sub - 1) & (bit)))\n#define UNIQUE(v)\
    \ (std::sort(all(v)), (v).erase(std::unique(all(v)), (v).end()))\n#define pcnt(x)\
    \ __builtin_popcount(x)\n#define llpcnt(x) __builtin_popcountll(x)\n#define VC(name,\
    \ type, ...) vector<type> name(__VA_ARGS__)\n#define VVC(name, type, a, ...) vector<vector<type>>\
    \ name(a, vector<type>(__VA_ARGS__))\n#define VVVC(name, type, a, b, ...) vector<vector<vector<type>>>\
    \ name(a, vector<vector<type>>(b, vector<type>(__VA_ARGS__)))\n#define VVVVC(name,\
    \ type, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n#define VVVVVC(name, type,\
    \ a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>> name(a, vector<vector<vector<vector<type>>>>(b,\
    \ vector<vector<vector<type>>>(c, vector<vector<type>>(d, vector<type>(__VA_ARGS__)))));\n\
    template <typename T>\nint lwb(const std::vector<T>& vec, const T& x){\n    return\
    \ lower_bound(all(vec), x) - vec.begin();\n}\ntemplate <typename T>\nint upb(const\
    \ std::vector<T>& vec, const T& x){\n    return upper_bound(all(vec), x) - vec.begin();\n\
    }\ntemplate <typename T>\nT max(const std::vector<T>& vec){ return *max_element(all(vec));\
    \ }\ntemplate <typename T>\nT min(const std::vector<T>& vec){ return *min_element(all(vec));\
    \ }\ntemplate <typename T>\nT rad(const T& x){ return x * PI/180; }\ntemplate\
    \ <typename T>\nusing pq = std::priority_queue<T>;\ntemplate <typename T>\nusing\
    \ pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1, typename\
    \ T2>\nbool chmax(T1 &a, const T2& b){\n    if(a < b){ a = b; return 1; }\n  \
    \  else return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a, const\
    \ T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\n\n#line\
    \ 15 \"DataStructure/RangeSet.hpp\"\n\n/**\n * @brief \u958B\u533A\u9593\u3092\
    \ set \u3067\u7BA1\u7406\u3059\u308B\n */\ntemplate <typename T>\nstruct RangeSet\
    \ {\nprivate:\n    std::set<std::pair<T, T>> intervals;\n    T sum_width;\n  \
    \  T TINF = std::numeric_limits<T>::max() / 2;\n\npublic:\n    RangeSet() : sum_width(T(0)){\n\
    \        intervals.emplace(TINF, TINF); // \u756A\u5175\n        intervals.emplace(-TINF,\
    \ -TINF); // \u756A\u5175\n    }\n\n    /**\n     * @brief [l, r) \u304C\u5B8C\
    \u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\
    \u8FD4\u3059\n     * @param itv \u5DE6\u7AEF\u304C l \u4EE5\u4E0B\u3067\u3042\u308B\
    \u3088\u3046\u306A\u533A\u9593\u306E\u3046\u3061\u3001\u6700\u3082\u53F3\u5074\
    \u306B\u3042\u308B\u3082\u306E\n     */\n    bool covered(const T& l, const T&\
    \ r){\n        assert(l <= r);\n        if(l == r){\n            return true;\n\
    \        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n        return (itv->first <= l) && (r <= itv->second);\n    }\n\n\
    \    /**\n     * @brief x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool contained(const T& x){\n   \
    \     return covered(x, x + 1);\n    }\n\n    /**\n     * @brief [l, r) \u3092\
    \u5305\u542B\u3059\u308B\u533A\u9593\u304C\u3042\u308C\u3070\u305D\u306E\u533A\
    \u9593\u3092\u8FD4\u3057\u3001\u306A\u3051\u308C\u3070 [-INF, -INF) \u3092\u8FD4\
    \u3059\n     */\n    std::pair<T, T> covered_by(const T& l, const T& r){\n   \
    \     assert(l <= r);\n        if(l == r){\n            return std::make_pair(-TINF,\
    \ -TINF);\n        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n        if(itv->first <= l && r <= itv->second){\n            return\
    \ *itv;\n        }\n        return std::make_pair(-TINF, -TINF);\n    }\n\n  \
    \  std::pair<T, T> covered_by(const T& x){\n        return covered_by(x, x + 1);\n\
    \    }\n\n    /**\n     * @brief [l, r) \u3092\u633F\u5165\u3057\u3001\u533A\u9593\
    \u5E45\u306E\u5897\u5206\u3092\u8FD4\u3059\n     * l \u3068 r \u305D\u308C\u305E\
    \u308C\u3067\u3001l, r \u3092\u542B\u3080\u533A\u9593\u3068\u30DE\u30FC\u30B8\u3067\
    \u304D\u308B\u304B\u3069\u3046\u304B\u3092\u898B\u308B\n     */\n    T insert(T\
    \ l, T r){\n        assert(l <= r);\n        if(l == r){\n            return T(0);\n\
    \        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n\n        if(itv->first <= l && r <= itv->second) return T(0); //\
    \ [l, r) \u304C\u3059\u3067\u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\u5834\
    \u5408\u306F\u4F8B\u5916\u51E6\u7406\n        /**\n         * @param sum_erased_width\
    \ \u6D88\u3057\u305F\u533A\u9593\u306E\u5E45\u306E\u5408\u8A08\n         */\n\
    \        T sum_erased_width = T(0);\n        if(itv->first <= l && l <= itv->second){\
    \ // l \u5074\u3067\u3001\u533A\u9593 itv \u3092\u30DE\u30FC\u30B8\u3067\u304D\
    \u308B\u5834\u5408\n            l = itv->first;\n            sum_erased_width\
    \ += itv->second - itv->first;\n            itv = intervals.erase(itv);\n    \
    \    } else{ // \u3067\u304D\u306A\u304B\u3063\u305F\u3089\u3001itr \u3092\u6B21\
    \u306E\u533A\u9593\u306B\u9032\u3081\u308B\n            itv = std::next(itv);\n\
    \        }\n        while(r > itv->second){ // \u73FE\u6642\u70B9\u3067 [l, r)\
    \ \u306B\u5305\u542B\u3055\u308C\u308B\u533A\u9593\u306F\u5168\u3066\u6D88\u3059\
    \n            sum_erased_width += itv->second - itv->first;\n            itv =\
    \ intervals.erase(itv);\n        }\n        if(itv->first <= r && r <= itv->second){\
    \ // r \u5074\u3067\u3001\u533A\u9593 itv \u3092\u30DE\u30FC\u30B8\u3067\u304D\
    \u308B\u5834\u5408\n            sum_erased_width += itv->second - itv->first;\n\
    \            r = itv->second;\n            intervals.erase(itv);\n        }\n\
    \        intervals.emplace(l, r);\n        sum_width += r - l - sum_erased_width;\n\
    \        return r - l - sum_erased_width;\n    }\n\n    T insert(const T x){\n\
    \        return insert(x, x + 1);\n    }\n\n    /**\n     * @brief [l, r) \u3092\
    \u524A\u9664\u3057\u3001\u533A\u9593\u5E45\u306E\u6E1B\u5206\u3092\u8FD4\u3059\
    \n     */\n    T erase(const T& l, const T& r){\n        assert(l <= r);\n   \
    \     if(l == r){\n            return T(0);\n        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n        if(itv->first <= l && r <= itv->second){ // [l, r] \u304C\
    \ itv \u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\u5834\u5408\n         \
    \   if(itv->first < l){ // l \u5074\u3067\u306E itv \u306E\u306F\u307F\u3060\u3057\
    \u90E8\u5206\u304C\u5B58\u5728\u3059\u308B\n                intervals.emplace(itv->first,\
    \ l);\n            }\n            if(r < itv->second){ // r \u5074\u3067\u306E\
    \ itv \u306E\u306F\u307F\u3060\u3057\u90E8\u5206\u304C\u5B58\u5728\u3059\u308B\
    \n                intervals.emplace(r, itv->second);\n            }\n        \
    \    intervals.erase(itv);\n            sum_width -= r - l;\n            return\
    \ r - l;\n        }\n\n        T sum_erased_width = T(0);\n        if(itv->first\
    \ <= l && l < itv->second){ // [l, r) \u304C\u3001l \u5074\u3067 itv \u3068\u5171\
    \u901A\u90E8\u5206\u3092\u6301\u3064\u5834\u5408\n            sum_erased_width\
    \ += itv->second - l;\n            if(itv->first < l){ // l \u5074\u3067\u306E\
    \ itv \u306E\u306F\u307F\u3060\u3057\u90E8\u5206\u304C\u5B58\u5728\u3059\u308B\
    \n                intervals.emplace(itv->first, l);\n            }\n         \
    \   itv = intervals.erase(itv);\n        } else{\n            itv = std::next(itv);\n\
    \        }\n        while(itv->second <= r){\n            sum_erased_width +=\
    \ itv->second - itv->first;\n            itv = intervals.erase(itv);\n       \
    \ }\n        if(itv->first <= r && r < itv->second){ // [l, r) \u304C\u3001l \u5074\
    \u3067 itv \u3068\u5171\u901A\u90E8\u5206\u3092\u6301\u3064\u5834\u5408\n    \
    \        sum_erased_width += r - itv->first;\n            if(r < itv->second){\
    \ // r \u5074\u3067\u306E itv \u306E\u306F\u307F\u3060\u3057\u90E8\u5206\u304C\
    \u5B58\u5728\u3059\u308B\n                intervals.emplace(r, itv->second);\n\
    \            }\n            intervals.erase(itv);\n        }\n        sum_width\
    \ -= sum_erased_width;\n        return sum_erased_width;\n    }\n\n    T erase(const\
    \ T& x){\n        return erase(x, x + 1);\n    }\n\n    /**\n     * @brief \u533A\
    \u9593\u306E\u6570\u3092\u8FD4\u3059\n     */\n    int size() const {\n      \
    \  return (int)intervals.size() - 2;\n    }\n\n    /**\n     * x \u4EE5\u4E0A\u3067\
    \u542B\u307E\u308C\u3066\u306A\u3044\u6700\u5C0F\u306E\u8981\u7D20\u306F\n   \
    \  * \u30FBx \u304C\u542B\u307E\u308C\u3066\u3044\u306A\u3044\uFF1Ax\n     * \u300E\
    \u30FBx \u304C\u542B\u307E\u308C\u3066\u3044\u308B\uFF1Ax \u3092\u542B\u3080\u533A\
    \u9593\u306E\u672B\u7AEF\u306B 1 \u52A0\u3048\u305F\u3082\u306E\u300F\n     */\n\
    \    T mex(const T& x = 0) const {\n        auto itv = std::prev(intervals.upper_bound({x,\
    \ TINF}));\n        if(itv->first <= x && x < itv->second){\n            return\
    \ itv->second;\n        }\n        return x;\n    }\n\n    /**\n     * @brief\
    \ \u533A\u9593\u5E45\u306E\u5408\u8A08\u3092\u8FD4\u3059\n     */\n    T sum_all()\
    \ const {\n        return sum_width;\n    }\n\n    /**\n     * @brief \u5168\u533A\
    \u9593\u3092\u4FDD\u6301\u3057\u305F set \u3092\u8FD4\u3059\n     */\n    std::set<std::pair<T,\
    \ T>> get_intervals() const {\n\t\tstd::set<std::pair<T, T>> res;\n\t\tfor(const\
    \ auto& interval : intervals) {\n\t\t\tif(std::abs(interval.first) == TINF) continue;\n\
    \t\t\tres.emplace(interval.first, interval.second);\n\t\t}\n\t\treturn res;\n\t\
    }\n\n    void output() const {\n        for(const auto& interval : intervals){\n\
    \            if(interval.first == -INF || interval.second == INF) continue;\n\
    \            std::cout << \"[\" << interval.first << \", \" << interval.second\
    \ << \")\" << '\\n';\n        }\n    }\n};\n\n\n"
  code: "#ifndef RangeSet_HPP\n#define RangeSet_HPP\n\n/*\nverify\n\u30FBhttps://atcoder.jp/contests/abc330/tasks/abc330_e\n\
    */\n\n#include <vector>\n#include <set>\n#include <limits>\n#include <iostream>\n\
    \n#include \"../Others/macros.hpp\"\n\n/**\n * @brief \u958B\u533A\u9593\u3092\
    \ set \u3067\u7BA1\u7406\u3059\u308B\n */\ntemplate <typename T>\nstruct RangeSet\
    \ {\nprivate:\n    std::set<std::pair<T, T>> intervals;\n    T sum_width;\n  \
    \  T TINF = std::numeric_limits<T>::max() / 2;\n\npublic:\n    RangeSet() : sum_width(T(0)){\n\
    \        intervals.emplace(TINF, TINF); // \u756A\u5175\n        intervals.emplace(-TINF,\
    \ -TINF); // \u756A\u5175\n    }\n\n    /**\n     * @brief [l, r) \u304C\u5B8C\
    \u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\
    \u8FD4\u3059\n     * @param itv \u5DE6\u7AEF\u304C l \u4EE5\u4E0B\u3067\u3042\u308B\
    \u3088\u3046\u306A\u533A\u9593\u306E\u3046\u3061\u3001\u6700\u3082\u53F3\u5074\
    \u306B\u3042\u308B\u3082\u306E\n     */\n    bool covered(const T& l, const T&\
    \ r){\n        assert(l <= r);\n        if(l == r){\n            return true;\n\
    \        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n        return (itv->first <= l) && (r <= itv->second);\n    }\n\n\
    \    /**\n     * @brief x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool contained(const T& x){\n   \
    \     return covered(x, x + 1);\n    }\n\n    /**\n     * @brief [l, r) \u3092\
    \u5305\u542B\u3059\u308B\u533A\u9593\u304C\u3042\u308C\u3070\u305D\u306E\u533A\
    \u9593\u3092\u8FD4\u3057\u3001\u306A\u3051\u308C\u3070 [-INF, -INF) \u3092\u8FD4\
    \u3059\n     */\n    std::pair<T, T> covered_by(const T& l, const T& r){\n   \
    \     assert(l <= r);\n        if(l == r){\n            return std::make_pair(-TINF,\
    \ -TINF);\n        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n        if(itv->first <= l && r <= itv->second){\n            return\
    \ *itv;\n        }\n        return std::make_pair(-TINF, -TINF);\n    }\n\n  \
    \  std::pair<T, T> covered_by(const T& x){\n        return covered_by(x, x + 1);\n\
    \    }\n\n    /**\n     * @brief [l, r) \u3092\u633F\u5165\u3057\u3001\u533A\u9593\
    \u5E45\u306E\u5897\u5206\u3092\u8FD4\u3059\n     * l \u3068 r \u305D\u308C\u305E\
    \u308C\u3067\u3001l, r \u3092\u542B\u3080\u533A\u9593\u3068\u30DE\u30FC\u30B8\u3067\
    \u304D\u308B\u304B\u3069\u3046\u304B\u3092\u898B\u308B\n     */\n    T insert(T\
    \ l, T r){\n        assert(l <= r);\n        if(l == r){\n            return T(0);\n\
    \        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n\n        if(itv->first <= l && r <= itv->second) return T(0); //\
    \ [l, r) \u304C\u3059\u3067\u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\u5834\
    \u5408\u306F\u4F8B\u5916\u51E6\u7406\n        /**\n         * @param sum_erased_width\
    \ \u6D88\u3057\u305F\u533A\u9593\u306E\u5E45\u306E\u5408\u8A08\n         */\n\
    \        T sum_erased_width = T(0);\n        if(itv->first <= l && l <= itv->second){\
    \ // l \u5074\u3067\u3001\u533A\u9593 itv \u3092\u30DE\u30FC\u30B8\u3067\u304D\
    \u308B\u5834\u5408\n            l = itv->first;\n            sum_erased_width\
    \ += itv->second - itv->first;\n            itv = intervals.erase(itv);\n    \
    \    } else{ // \u3067\u304D\u306A\u304B\u3063\u305F\u3089\u3001itr \u3092\u6B21\
    \u306E\u533A\u9593\u306B\u9032\u3081\u308B\n            itv = std::next(itv);\n\
    \        }\n        while(r > itv->second){ // \u73FE\u6642\u70B9\u3067 [l, r)\
    \ \u306B\u5305\u542B\u3055\u308C\u308B\u533A\u9593\u306F\u5168\u3066\u6D88\u3059\
    \n            sum_erased_width += itv->second - itv->first;\n            itv =\
    \ intervals.erase(itv);\n        }\n        if(itv->first <= r && r <= itv->second){\
    \ // r \u5074\u3067\u3001\u533A\u9593 itv \u3092\u30DE\u30FC\u30B8\u3067\u304D\
    \u308B\u5834\u5408\n            sum_erased_width += itv->second - itv->first;\n\
    \            r = itv->second;\n            intervals.erase(itv);\n        }\n\
    \        intervals.emplace(l, r);\n        sum_width += r - l - sum_erased_width;\n\
    \        return r - l - sum_erased_width;\n    }\n\n    T insert(const T x){\n\
    \        return insert(x, x + 1);\n    }\n\n    /**\n     * @brief [l, r) \u3092\
    \u524A\u9664\u3057\u3001\u533A\u9593\u5E45\u306E\u6E1B\u5206\u3092\u8FD4\u3059\
    \n     */\n    T erase(const T& l, const T& r){\n        assert(l <= r);\n   \
    \     if(l == r){\n            return T(0);\n        }\n        auto itv = std::prev(intervals.upper_bound(std::make_pair(l,\
    \ TINF)));\n        if(itv->first <= l && r <= itv->second){ // [l, r] \u304C\
    \ itv \u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\u5834\u5408\n         \
    \   if(itv->first < l){ // l \u5074\u3067\u306E itv \u306E\u306F\u307F\u3060\u3057\
    \u90E8\u5206\u304C\u5B58\u5728\u3059\u308B\n                intervals.emplace(itv->first,\
    \ l);\n            }\n            if(r < itv->second){ // r \u5074\u3067\u306E\
    \ itv \u306E\u306F\u307F\u3060\u3057\u90E8\u5206\u304C\u5B58\u5728\u3059\u308B\
    \n                intervals.emplace(r, itv->second);\n            }\n        \
    \    intervals.erase(itv);\n            sum_width -= r - l;\n            return\
    \ r - l;\n        }\n\n        T sum_erased_width = T(0);\n        if(itv->first\
    \ <= l && l < itv->second){ // [l, r) \u304C\u3001l \u5074\u3067 itv \u3068\u5171\
    \u901A\u90E8\u5206\u3092\u6301\u3064\u5834\u5408\n            sum_erased_width\
    \ += itv->second - l;\n            if(itv->first < l){ // l \u5074\u3067\u306E\
    \ itv \u306E\u306F\u307F\u3060\u3057\u90E8\u5206\u304C\u5B58\u5728\u3059\u308B\
    \n                intervals.emplace(itv->first, l);\n            }\n         \
    \   itv = intervals.erase(itv);\n        } else{\n            itv = std::next(itv);\n\
    \        }\n        while(itv->second <= r){\n            sum_erased_width +=\
    \ itv->second - itv->first;\n            itv = intervals.erase(itv);\n       \
    \ }\n        if(itv->first <= r && r < itv->second){ // [l, r) \u304C\u3001l \u5074\
    \u3067 itv \u3068\u5171\u901A\u90E8\u5206\u3092\u6301\u3064\u5834\u5408\n    \
    \        sum_erased_width += r - itv->first;\n            if(r < itv->second){\
    \ // r \u5074\u3067\u306E itv \u306E\u306F\u307F\u3060\u3057\u90E8\u5206\u304C\
    \u5B58\u5728\u3059\u308B\n                intervals.emplace(r, itv->second);\n\
    \            }\n            intervals.erase(itv);\n        }\n        sum_width\
    \ -= sum_erased_width;\n        return sum_erased_width;\n    }\n\n    T erase(const\
    \ T& x){\n        return erase(x, x + 1);\n    }\n\n    /**\n     * @brief \u533A\
    \u9593\u306E\u6570\u3092\u8FD4\u3059\n     */\n    int size() const {\n      \
    \  return (int)intervals.size() - 2;\n    }\n\n    /**\n     * x \u4EE5\u4E0A\u3067\
    \u542B\u307E\u308C\u3066\u306A\u3044\u6700\u5C0F\u306E\u8981\u7D20\u306F\n   \
    \  * \u30FBx \u304C\u542B\u307E\u308C\u3066\u3044\u306A\u3044\uFF1Ax\n     * \u300E\
    \u30FBx \u304C\u542B\u307E\u308C\u3066\u3044\u308B\uFF1Ax \u3092\u542B\u3080\u533A\
    \u9593\u306E\u672B\u7AEF\u306B 1 \u52A0\u3048\u305F\u3082\u306E\u300F\n     */\n\
    \    T mex(const T& x = 0) const {\n        auto itv = std::prev(intervals.upper_bound({x,\
    \ TINF}));\n        if(itv->first <= x && x < itv->second){\n            return\
    \ itv->second;\n        }\n        return x;\n    }\n\n    /**\n     * @brief\
    \ \u533A\u9593\u5E45\u306E\u5408\u8A08\u3092\u8FD4\u3059\n     */\n    T sum_all()\
    \ const {\n        return sum_width;\n    }\n\n    /**\n     * @brief \u5168\u533A\
    \u9593\u3092\u4FDD\u6301\u3057\u305F set \u3092\u8FD4\u3059\n     */\n    std::set<std::pair<T,\
    \ T>> get_intervals() const {\n\t\tstd::set<std::pair<T, T>> res;\n\t\tfor(const\
    \ auto& interval : intervals) {\n\t\t\tif(std::abs(interval.first) == TINF) continue;\n\
    \t\t\tres.emplace(interval.first, interval.second);\n\t\t}\n\t\treturn res;\n\t\
    }\n\n    void output() const {\n        for(const auto& interval : intervals){\n\
    \            if(interval.first == -INF || interval.second == INF) continue;\n\
    \            std::cout << \"[\" << interval.first << \", \" << interval.second\
    \ << \")\" << '\\n';\n        }\n    }\n};\n\n#endif // RangeSet_HPP"
  dependsOn:
  - Others/macros.hpp
  isVerificationFile: false
  path: DataStructure/RangeSet.hpp
  requiredBy: []
  timestamp: '2024-09-29 06:50:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RangeSet.hpp
layout: document
redirect_from:
- /library/DataStructure/RangeSet.hpp
- /library/DataStructure/RangeSet.hpp.html
title: "\u958B\u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B"
---
