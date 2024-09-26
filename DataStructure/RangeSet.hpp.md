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
    document_title: "\u9589\u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"DataStructure/RangeSet.hpp\"\n\n\n\n#include <vector>\n\
    #include <set>\n#include <limits>\n#include <iostream>\n\n#line 1 \"Others/macros.hpp\"\
    \n\n\n\n#line 5 \"Others/macros.hpp\"\n#include <queue>\n#include <cmath>\n\n\
    using ll = long long;\nusing lll = __int128_t;\nusing ld = long double;\n#define\
    \ newl '\\n'\n#define REF const auto&\n#define INF 1000390039\n#define LLINF 1000000039000000039\n\
    #define IMAX INT_MAX\n#define IMIN INT_MIN\n#define LLMAX LONG_LONG_MAX\n#define\
    \ LLMIN LONG_LONG_MIN\n#define BIT(i) (1LL << (i))\n#define tbit(n, k) ((n >>\
    \ k) & 1) // n\u306E\uFF08\u4E0A\u304B\u3089\uFF09k\u30D3\u30C3\u30C8\u76EE\n\
    #define bit(n, k) (n & (1LL << (k))) // n\u306E\uFF08\u4E0B\u304B\u3089\uFF09\
    k\u30D3\u30C3\u30C8\u76EE\n#define PI acos(-1)\n#define inr(l, x, r) (l <= x &&\
    \ x < r)\n#define einr(l, x, r) (l <= x && x <= r)\n#define rep(i, a, b) for(int\
    \ i = (a); i < (b); i++)\n#define erep(i, a, b) for(int i = (a); i <= (b); i++)\n\
    #define rrep(i, a, b) for(int i = (a); i >= (b); i--)\n#define repl(i, a, b) for(long\
    \ long i = (a); i < (b); i++)\n#define erepl(i, a, b) for(long long i = (a); i\
    \ <= (b); i++)\n#define rrepl(i, a, b) for(long long i = (a); i >= (b); i--)\n\
    #define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define FOR_subset(sub, bit) for (ll sub = (bit); sub >= 0; sub = (sub == 0 ?\
    \ -1 : (sub - 1) & (bit)))\n#define UNIQUE(v) (std::sort(all(v)), (v).erase(std::unique(all(v)),\
    \ (v).end()))\n#define pcnt(x) __builtin_popcount(x)\n#define llpcnt(x) __builtin_popcountll(x)\n\
    #define VC(name, type, ...) vector<type> name(__VA_ARGS__)\n#define VVC(name,\
    \ type, a, ...) vector<vector<type>> name(a, vector<type>(__VA_ARGS__))\n#define\
    \ VVVC(name, type, a, b, ...) vector<vector<vector<type>>> name(a, vector<vector<type>>(b,\
    \ vector<type>(__VA_ARGS__)))\n#define VVVVC(name, type, a, b, c, ...) vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    #define VVVVVC(name, type, a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>>\
    \ name(a, vector<vector<vector<vector<type>>>>(b, vector<vector<vector<type>>>(c,\
    \ vector<vector<type>>(d, vector<type>(__VA_ARGS__)))));\ntemplate <typename T>\n\
    int lwb(const std::vector<T>& vec, const T& x){\n    return lower_bound(all(vec),\
    \ x) - vec.begin();\n}\ntemplate <typename T>\nint upb(const std::vector<T>& vec,\
    \ const T& x){\n    return upper_bound(all(vec), x) - vec.begin();\n}\ntemplate\
    \ <typename T>\nT max(const std::vector<T>& vec){ return *max_element(all(vec));\
    \ }\ntemplate <typename T>\nT min(const std::vector<T>& vec){ return *min_element(all(vec));\
    \ }\ntemplate <typename T>\nT rad(const T& x){ return x * PI/180; }\ntemplate\
    \ <typename T>\nusing pq = std::priority_queue<T>;\ntemplate <typename T>\nusing\
    \ pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1, typename\
    \ T2>\nbool chmax(T1 &a, const T2& b){\n    if(a < b){ a = b; return 1; }\n  \
    \  else return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a, const\
    \ T2& b){\n    if(a > b){ a = b; return 1; }\n    else return 0;\n}\n\n\n#line\
    \ 10 \"DataStructure/RangeSet.hpp\"\n\n/**\n * @brief \u9589\u533A\u9593\u3092\
    \ set \u3067\u7BA1\u7406\u3059\u308B\n */\ntemplate <typename T>\nclass RangeSet{\n\
    private:\n    std::set<std::pair<T, T>> s;\n    /**\n     * @param sum RangeSet\u5185\
    \u306E\u8981\u7D20\u6570\n     */\n    T sum;\n    T TINF = std::numeric_limits<T>::max()\
    \ / 2;\n\npublic:\n    RangeSet() : sum(T(0)){\n        s.emplace(TINF, TINF);\n\
    \        s.emplace(-TINF, -TINF);\n    }\n\n    /**\n     * @brief \u533A\u9593\
    \ [l, r] \u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool covered(const T l, const T r){\n\
    \        assert(l <= r);\n        auto itr = std::prev(s.lower_bound({l + 1, l\
    \ + 1}));\n        return ((itr->first <= l) && (r <= itr->second));\n    }\n\n\
    \    /**\n     * @brief x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool contained(const T x){\n    \
    \    auto itr = std::prev(s.lower_bound({x + 1, x + 1}));\n        return ((itr->first\
    \ <= x) && (x <= itr->second));\n    }\n\n    /**\n     * @brief \u533A\u9593\
    \ [l, r] \u3092\u5305\u542B\u3059\u308B\u533A\u9593\u304C\u3042\u308C\u3070\u305D\
    \u306E\u533A\u9593\u3092\u8FD4\u3057\u3001\u306A\u3051\u308C\u3070 [-INF, -INF]\
    \ \u3092\u8FD4\u3059\n     */\n    std::pair<T, T> covered_by(const T l, const\
    \ T r){\n        assert(l <= r);\n        auto itr = std::prev(s.lower_bound({l\
    \ + 1, l + 1}));\n        if(itr->first <= l && r <= itr->second) return *itr;\n\
    \        return {-TINF, -TINF};\n    }\n\n    std::pair<T, T> covered_by(const\
    \ T x){\n        return covered_by(x, x);\n    }\n\n    /**\n     * @brief \u533A\
    \u9593 [l, r] \u3092\u633F\u5165\u3057\u3001\u5897\u5206\u3092\u8FD4\u3059\n \
    \    */\n    T insert(T l, T r){\n        assert(l <= r);\n        auto itr =\
    \ std::prev(s.lower_bound({l + 1, l + 1}));\n\n        if(itr->first <= l && r\
    \ <= itr->second) return T(0); // [l, r] \u304C\u3059\u3067\u306B\u5B8C\u5168\u306B\
    \u542B\u307E\u308C\u3066\u3044\u308B\n        /**\n         * @param sum_erased\
    \ \u6D88\u3057\u305F\u533A\u9593\u306E\u5E45\u306E\u5408\u8A08\n         */\n\
    \        T sum_erased = T(0);\n        if(itr->first <= l && l <= itr->second+1){\
    \ // l \u5074\u3067\u3001\u533A\u9593 itr \u3092\u30DE\u30FC\u30B8\u3067\u304D\
    \u308B\u5834\u5408\n            l = itr->first;\n            sum_erased += itr->second\
    \ - itr->first + 1;\n            itr = s.erase(itr);\n        }\n        else{\
    \ // \u3067\u304D\u306A\u304B\u3063\u305F\u3089\u3001itr \u3092\u6B21\u306E\u533A\
    \u9593\u306B\u9032\u3081\u308B\n            itr = std::next(itr);\n        }\n\
    \        while(r > itr->second){\n            sum_erased += itr->second - itr->first\
    \ + 1;\n            itr = s.erase(itr);\n        }\n        if(itr->first <= r\
    \ + 1 && r <= itr->second){ // r \u5074\u3067\u3001\u533A\u9593 itr \u3092\u30DE\
    \u30FC\u30B8\u3067\u304D\u308B\u5834\u5408\n            sum_erased += itr->second\
    \ - itr->first + 1;\n            r = itr->second;\n            s.erase(itr);\n\
    \        }\n        s.emplace(l, r);\n        sum += r - l + 1 - sum_erased;\n\
    \        return r - l + 1 - sum_erased;\n    }\n\n    T insert(const T x){\n \
    \       return insert(x, x);\n    }\n\n    /**\n     * @brief \u533A\u9593 [l,\
    \ r] \u3092\u524A\u9664\u3057\u3001\u6E1B\u5206\u3092\u8FD4\u3059\n     */\n \
    \   T erase(const T l, const T r){\n        assert(l <= r);\n        auto itr\
    \ = std::prev(s.lower_bound({l + 1, l + 1}));\n        if(itr->first <= l && r\
    \ <= itr->second){ // [l, r] \u304C\u30011 \u3064\u306E\u533A\u9593\u306B\u5305\
    \u542B\u3055\u308C\u3066\u3044\u308B\n        // \u306F\u307F\u51FA\u3057\u305F\
    \u533A\u9593\n            if(itr->first < l) s.emplace(itr->first, l - 1);\n \
    \           if(r < itr->second) s.emplace(r+1, itr->second);\n            s.erase(itr);\n\
    \            sum -= r - l + 1;\n            return r - l + 1;\n        }\n\n \
    \       T res = T(0);\n        if(itr->first <= l && l <= itr->second){ // l \u5074\
    \u3067\u3001\u533A\u9593 itr \u3092\u6D88\u305B\u308B\u5834\u5408\n          \
    \  res += itr->second - l + 1;\n            // \u306F\u307F\u51FA\u3057\u305F\u533A\
    \u9593\n            if(itr->first < l) s.emplace(itr->first, l - 1);\n       \
    \     itr = s.erase(itr);\n        }\n        else{\n            itr = std::next(itr);\n\
    \        }\n        while(itr->second <= r){\n            res += itr->second -\
    \ itr->first + 1;\n            itr = s.erase(itr);\n        }\n        if(itr->first\
    \ <= r && r <= itr->second){ // r \u5074\u3067\u3001\u533A\u9593 itr \u3092\u6D88\
    \u305B\u308B\u5834\u5408\n            res += r - itr->first + 1;\n           \
    \ // \u306F\u307F\u51FA\u3057\u305F\u533A\u9593\n            if(r < itr->second)\
    \ s.emplace(r + 1, itr->second);\n            s.erase(itr);\n        }\n     \
    \   sum -= res;\n        return res;\n    }\n\n    T erase(const T x){\n     \
    \   return erase(x, x);\n    }\n\n    /**\n     * @brief \u533A\u9593\u306E\u6570\
    \u3092\u8FD4\u3059\n     */\n    int size() const{\n        return (int)s.size()-2;\n\
    \    }\n\n    /**\n     * x\u4EE5\u4E0A\u3067\u542B\u307E\u308C\u3066\u306A\u3044\
    \u6700\u5C0F\u306E\u8981\u7D20\u306F\n     * \u30FBx\u304C\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\uFF1Ax\n     * \u30FBx\u304C\u542B\u307E\u308C\u3066\u3044\u308B\
    \uFF1Ax \u3092\u542B\u3080\u533A\u9593\u306E\u672B\u7AEF\u306B 1 \u52A0\u3048\u305F\
    \u3082\u306E\n     */\n    T mex(const T x = 0) const{\n        auto itr = std::prev(s.lower_bound({x\
    \ + 1, x + 1}));\n        if(itr->first <= x && x <= itr->second) return itr->second\
    \ + 1;\n        else return x;\n    }\n\n    // @brief RangeSet \u5185\u306E\u8981\
    \u7D20\u6570\u3092\u8FD4\u3059\n    T sum_all() const{\n        return sum;\n\
    \    }\n\n    // @brief \u5168\u533A\u9593\u3092\u4FDD\u6301\u3057\u305F set \u3092\
    \u8FD4\u3059\n    std::set<std::pair<T, T>> get() const{\n\t\tstd::set<std::pair<T,\
    \ T>> res;\n\t\tfor(auto& interval : s) {\n\t\t\tif(std::abs(interval.first) ==\
    \ TINF) continue;\n\t\t\tres.emplace(interval.first, interval.second);\n\t\t}\n\
    \t\treturn res;\n\t}\n\n    void output() const{\n        std::cout << \"RangeSet:\"\
    ;\n        for(auto& interval : s){\n            if(interval.first == -INF ||\
    \ interval.second == INF) continue;\n            std::cout << \"[\" << interval.first\
    \ << \",\" << interval.second << \"]\";\n        }\n        std::cout << '\\n';\n\
    \    }\n};\n\n\n"
  code: "#ifndef RangeSet_HPP\n#define RangeSet_HPP\n\n#include <vector>\n#include\
    \ <set>\n#include <limits>\n#include <iostream>\n\n#include \"../Others/macros.hpp\"\
    \n\n/**\n * @brief \u9589\u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B\
    \n */\ntemplate <typename T>\nclass RangeSet{\nprivate:\n    std::set<std::pair<T,\
    \ T>> s;\n    /**\n     * @param sum RangeSet\u5185\u306E\u8981\u7D20\u6570\n\
    \     */\n    T sum;\n    T TINF = std::numeric_limits<T>::max() / 2;\n\npublic:\n\
    \    RangeSet() : sum(T(0)){\n        s.emplace(TINF, TINF);\n        s.emplace(-TINF,\
    \ -TINF);\n    }\n\n    /**\n     * @brief \u533A\u9593 [l, r] \u304C\u5B8C\u5168\
    \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\
    \u3059\n     */\n    bool covered(const T l, const T r){\n        assert(l <=\
    \ r);\n        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));\n        return\
    \ ((itr->first <= l) && (r <= itr->second));\n    }\n\n    /**\n     * @brief\
    \ x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\
    \u3059\n     */\n    bool contained(const T x){\n        auto itr = std::prev(s.lower_bound({x\
    \ + 1, x + 1}));\n        return ((itr->first <= x) && (x <= itr->second));\n\
    \    }\n\n    /**\n     * @brief \u533A\u9593 [l, r] \u3092\u5305\u542B\u3059\u308B\
    \u533A\u9593\u304C\u3042\u308C\u3070\u305D\u306E\u533A\u9593\u3092\u8FD4\u3057\
    \u3001\u306A\u3051\u308C\u3070 [-INF, -INF] \u3092\u8FD4\u3059\n     */\n    std::pair<T,\
    \ T> covered_by(const T l, const T r){\n        assert(l <= r);\n        auto\
    \ itr = std::prev(s.lower_bound({l + 1, l + 1}));\n        if(itr->first <= l\
    \ && r <= itr->second) return *itr;\n        return {-TINF, -TINF};\n    }\n\n\
    \    std::pair<T, T> covered_by(const T x){\n        return covered_by(x, x);\n\
    \    }\n\n    /**\n     * @brief \u533A\u9593 [l, r] \u3092\u633F\u5165\u3057\u3001\
    \u5897\u5206\u3092\u8FD4\u3059\n     */\n    T insert(T l, T r){\n        assert(l\
    \ <= r);\n        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));\n\n   \
    \     if(itr->first <= l && r <= itr->second) return T(0); // [l, r] \u304C\u3059\
    \u3067\u306B\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\n        /**\n\
    \         * @param sum_erased \u6D88\u3057\u305F\u533A\u9593\u306E\u5E45\u306E\
    \u5408\u8A08\n         */\n        T sum_erased = T(0);\n        if(itr->first\
    \ <= l && l <= itr->second+1){ // l \u5074\u3067\u3001\u533A\u9593 itr \u3092\u30DE\
    \u30FC\u30B8\u3067\u304D\u308B\u5834\u5408\n            l = itr->first;\n    \
    \        sum_erased += itr->second - itr->first + 1;\n            itr = s.erase(itr);\n\
    \        }\n        else{ // \u3067\u304D\u306A\u304B\u3063\u305F\u3089\u3001\
    itr \u3092\u6B21\u306E\u533A\u9593\u306B\u9032\u3081\u308B\n            itr =\
    \ std::next(itr);\n        }\n        while(r > itr->second){\n            sum_erased\
    \ += itr->second - itr->first + 1;\n            itr = s.erase(itr);\n        }\n\
    \        if(itr->first <= r + 1 && r <= itr->second){ // r \u5074\u3067\u3001\u533A\
    \u9593 itr \u3092\u30DE\u30FC\u30B8\u3067\u304D\u308B\u5834\u5408\n          \
    \  sum_erased += itr->second - itr->first + 1;\n            r = itr->second;\n\
    \            s.erase(itr);\n        }\n        s.emplace(l, r);\n        sum +=\
    \ r - l + 1 - sum_erased;\n        return r - l + 1 - sum_erased;\n    }\n\n \
    \   T insert(const T x){\n        return insert(x, x);\n    }\n\n    /**\n   \
    \  * @brief \u533A\u9593 [l, r] \u3092\u524A\u9664\u3057\u3001\u6E1B\u5206\u3092\
    \u8FD4\u3059\n     */\n    T erase(const T l, const T r){\n        assert(l <=\
    \ r);\n        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));\n        if(itr->first\
    \ <= l && r <= itr->second){ // [l, r] \u304C\u30011 \u3064\u306E\u533A\u9593\u306B\
    \u5305\u542B\u3055\u308C\u3066\u3044\u308B\n        // \u306F\u307F\u51FA\u3057\
    \u305F\u533A\u9593\n            if(itr->first < l) s.emplace(itr->first, l - 1);\n\
    \            if(r < itr->second) s.emplace(r+1, itr->second);\n            s.erase(itr);\n\
    \            sum -= r - l + 1;\n            return r - l + 1;\n        }\n\n \
    \       T res = T(0);\n        if(itr->first <= l && l <= itr->second){ // l \u5074\
    \u3067\u3001\u533A\u9593 itr \u3092\u6D88\u305B\u308B\u5834\u5408\n          \
    \  res += itr->second - l + 1;\n            // \u306F\u307F\u51FA\u3057\u305F\u533A\
    \u9593\n            if(itr->first < l) s.emplace(itr->first, l - 1);\n       \
    \     itr = s.erase(itr);\n        }\n        else{\n            itr = std::next(itr);\n\
    \        }\n        while(itr->second <= r){\n            res += itr->second -\
    \ itr->first + 1;\n            itr = s.erase(itr);\n        }\n        if(itr->first\
    \ <= r && r <= itr->second){ // r \u5074\u3067\u3001\u533A\u9593 itr \u3092\u6D88\
    \u305B\u308B\u5834\u5408\n            res += r - itr->first + 1;\n           \
    \ // \u306F\u307F\u51FA\u3057\u305F\u533A\u9593\n            if(r < itr->second)\
    \ s.emplace(r + 1, itr->second);\n            s.erase(itr);\n        }\n     \
    \   sum -= res;\n        return res;\n    }\n\n    T erase(const T x){\n     \
    \   return erase(x, x);\n    }\n\n    /**\n     * @brief \u533A\u9593\u306E\u6570\
    \u3092\u8FD4\u3059\n     */\n    int size() const{\n        return (int)s.size()-2;\n\
    \    }\n\n    /**\n     * x\u4EE5\u4E0A\u3067\u542B\u307E\u308C\u3066\u306A\u3044\
    \u6700\u5C0F\u306E\u8981\u7D20\u306F\n     * \u30FBx\u304C\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\uFF1Ax\n     * \u30FBx\u304C\u542B\u307E\u308C\u3066\u3044\u308B\
    \uFF1Ax \u3092\u542B\u3080\u533A\u9593\u306E\u672B\u7AEF\u306B 1 \u52A0\u3048\u305F\
    \u3082\u306E\n     */\n    T mex(const T x = 0) const{\n        auto itr = std::prev(s.lower_bound({x\
    \ + 1, x + 1}));\n        if(itr->first <= x && x <= itr->second) return itr->second\
    \ + 1;\n        else return x;\n    }\n\n    // @brief RangeSet \u5185\u306E\u8981\
    \u7D20\u6570\u3092\u8FD4\u3059\n    T sum_all() const{\n        return sum;\n\
    \    }\n\n    // @brief \u5168\u533A\u9593\u3092\u4FDD\u6301\u3057\u305F set \u3092\
    \u8FD4\u3059\n    std::set<std::pair<T, T>> get() const{\n\t\tstd::set<std::pair<T,\
    \ T>> res;\n\t\tfor(auto& interval : s) {\n\t\t\tif(std::abs(interval.first) ==\
    \ TINF) continue;\n\t\t\tres.emplace(interval.first, interval.second);\n\t\t}\n\
    \t\treturn res;\n\t}\n\n    void output() const{\n        std::cout << \"RangeSet:\"\
    ;\n        for(auto& interval : s){\n            if(interval.first == -INF ||\
    \ interval.second == INF) continue;\n            std::cout << \"[\" << interval.first\
    \ << \",\" << interval.second << \"]\";\n        }\n        std::cout << '\\n';\n\
    \    }\n};\n\n#endif // RangeSet_HPP"
  dependsOn:
  - Others/macros.hpp
  isVerificationFile: false
  path: DataStructure/RangeSet.hpp
  requiredBy: []
  timestamp: '2024-09-26 23:38:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RangeSet.hpp
layout: document
redirect_from:
- /library/DataStructure/RangeSet.hpp
- /library/DataStructure/RangeSet.hpp.html
title: "\u9589\u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B"
---
