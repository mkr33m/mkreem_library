---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Others/macros.hpp
    title: Others/macros.hpp
  - icon: ':warning:'
    path: ac-library/atcoder/internal_bit.hpp
    title: ac-library/atcoder/internal_bit.hpp
  - icon: ':warning:'
    path: ac-library/atcoder/lazysegtree.hpp
    title: ac-library/atcoder/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "b, a+b, ..., (r-l)a + b \u3092\u52A0\u7B97"
    links: []
  bundledCode: "#line 1 \"DataStructure/LazySegtree_arith_add.hpp\"\n\n\n\n#include\
    \ <vector>\n#line 1 \"Others/macros.hpp\"\n\n\n\n#line 5 \"Others/macros.hpp\"\
    \n#include <queue>\n#include <cmath>\n\nusing ll = long long;\nusing lll = __int128_t;\n\
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
    \ <typename T>\nusing maxpq = std::priority_queue<T>;\ntemplate <typename T>\n\
    using minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n// \u6700\
    \u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename T1,\
    \ typename T2>\nbool chmax(T1 &a, const T2& b){\n    if (a < b) { a = b; return\
    \ 1; }\n    return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a,\
    \ const T2& b){\n    if (a > b) { a = b; return 1; }\n    return 0;\n}\n\nconst\
    \ int di4[4] = {-1, 0, 1, 0};\nconst int dj4[4] = {0, 1, 0, -1};\nconst int di8[8]\
    \ = {-1, -1, 0, 1, 1, 1, 0, -1};\nconst int dj8[8] = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    \nbool out_of_grid(const int& i, const int& j, const int& h, const int& w){\n\
    \    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n    return false;\n\
    }\n\n\n#line 1 \"ac-library/atcoder/lazysegtree.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 1 \"ac-library/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n\
    namespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\n\
    using std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\nunsigned\
    \ int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x < (unsigned\
    \ int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nint countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 6 \"ac-library/atcoder/lazysegtree.hpp\"\
    \n#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP\n#endif\n\
    #include <cassert>\n#include <functional>\n#line 12 \"ac-library/atcoder/lazysegtree.hpp\"\
    \n\nnamespace atcoder {\n\n#if __cplusplus >= 201703L\n\ntemplate <class S,\n\
    \          auto op,\n          auto e,\n          class F,\n          auto mapping,\n\
    \          auto composition,\n          auto id>\nstruct lazy_segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                  \"op must work as S(S, S)\");\n\
    \    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,\n \
    \                 \"e must work as S()\");\n    static_assert(\n        std::is_convertible_v<decltype(mapping),\
    \ std::function<S(F, S)>>,\n        \"mapping must work as S(F, S)\");\n    static_assert(\n\
    \        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,\n\
    \        \"composition must work as F(F, F)\");\n    static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                  \"id must work as F()\");\n\n#else\n\
    \ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n        \
    \  class F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n\
    \          F (*id)()>\nstruct lazy_segtree {\n\n#endif\n\n  public:\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = (int)internal::bit_ceil((unsigned int)(_n));\n        log\
    \ = internal::countr_zero((unsigned int)size);\n        d = std::vector<S>(2 *\
    \ size, e());\n        lz = std::vector<F>(size, id());\n        for (int i =\
    \ 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(),\
    \ smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n}  // namespace atcoder\n\n\n#line 7 \"DataStructure/LazySegtree_arith_add.hpp\"\
    \n\nnamespace arith_add {\n\nstruct S {\n    ll sum;\n    int l, r;\n};\nS op(S\
    \ L, S R) {\n    return S{L.sum + R.sum, std::min(L.l, R.l), std::max(L.r, R.r)};\n\
    }\nS e() {\n    return S{0LL, INF, -INF};\n}\nstruct F {\n    ll a, b;\n};\nS\
    \ mapping(F f, S s) {\n    return S{\n        s.sum + (f.a * (s.l + s.r - 1) +\
    \ f.b * 2) * (s.r - s.l) / 2,\n        s.l, s.r\n        };\n}\nF composition(F\
    \ f, F g) {\n    return {f.a + g.a, f.b + g.b};\n};\nF id() {\n    return F{0,\
    \ 0};\n}\n\nusing lazy = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n\ntemplate <typename T>\nstruct LazySegtree_arith : lazy {\n    using\
    \ lazy::lazy; // \u57FA\u5E95\u30AF\u30E9\u30B9\u304C\u6301\u3064\u5168\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u3001\u6D3E\u751F\u30AF\u30E9\u30B9\u3067\
    \u3082\u4F7F\u3048\u308B\u3088\u3046\u306B\u3059\u308B\n    LazySegtree_arith(int\
    \ N) {\n        std::vector<S> vec(N);\n        for (int i = 0; i < N; i++) {\n\
    \            vec[i] = S{0, i, i + 1};\n        }\n        LazySegtree_arith tmp(vec);\
    \ // using lazy::lazy \u306B\u3088\u308B\u3001acl \u306E\u9045\u5EF6\u30BB\u30B0\
    \u6728\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u547C\u3073\u51FA\
    \u3057\u3066\u3044\u308B\n        /**\n         * \u6D3E\u751F\u30AF\u30E9\u30B9\
    \u306B\u304A\u3044\u3066\u3001int N \u3060\u3051\u6E21\u3057\u3066\u4E2D\u8EAB\
    \u306F\u30BC\u30ED\u521D\u671F\u5316\u3001vector<ll> \u3092\u6E21\u3057\u3066\
    \ vector<S> \u306B\u5909\u63DB\u3057\u3066\u304B\u3089\u521D\u671F\u5316\u3001\
    \u306A\u3069\u3001\u5225\u306E\u5F15\u6570\u30D1\u30BF\u30FC\u30F3\u3067\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u5B9A\u7FA9\u3057\u305F\u3044\u3002\
    \n         * \u3057\u304B\u3057\u3001\u6D3E\u751F\u30AF\u30E9\u30B9\u3067\u3082\
    \u308F\u3056\u308F\u3056\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3059\u308B\u306E\
    \u306F\u9762\u5012 \u2192 \u57FA\u5E95\u30AF\u30E9\u30B9\u306E\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3092\u547C\u3073\u51FA\u3057\u3066\u30BB\u30B0\u6728\
    \u3092\u69CB\u7BC9\u3057\u3066\uFF08\u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u306E\u751F\u6210\u3002\u91CD\u3044\u521D\u671F\u5316\u3092\u57FA\u5E95\
    \u30AF\u30E9\u30B9\u306B\u4E38\u6295\u3052\uFF09\u3001\u305D\u306E\u4E00\u6642\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092 *this \u306B\u30B3\u30D4\u30FC\u3002\
    \n         */\n        (*this) = tmp;\n    }\n    LazySegtree_arith(std::vector<T>\
    \ v) {\n        std::vector<S> vec((int)v.size());\n        for (int i = 0; i\
    \ < (int)v.size(); i++) {\n            vec[i] = S{v[i], i, i + 1};\n        }\n\
    \        LazySegtree_arith tmp(vec);\n        (*this) = tmp;\n    }\n\n    /**\n\
    \     * @brief b, a+b, ..., (r-l)a + b \u3092\u52A0\u7B97\n     */\n    void apply(int\
    \ l, int r, F f) {\n        lazy::apply(l, r, F{f.a, f.b - f.a * get(l).l});\n\
    \    }\n    /**\n     * @brief la + b, (l+1)a + b, ..., (r-1)a + b \u3092\u52A0\
    \u7B97\n     */\n    void apply_idx(int l, int r, F f) {\n        lazy::apply(l,\
    \ r, f);\n    }\n};\n\n} // namespace arith_add\n\n\n"
  code: "#ifndef LazySegtree_arith_add_HPP\n#define LazySegtree_arith_add_HPP\n\n\
    #include <vector>\n#include \"../Others/macros.hpp\"\n#include \"../ac-library/atcoder/lazysegtree.hpp\"\
    \n\nnamespace arith_add {\n\nstruct S {\n    ll sum;\n    int l, r;\n};\nS op(S\
    \ L, S R) {\n    return S{L.sum + R.sum, std::min(L.l, R.l), std::max(L.r, R.r)};\n\
    }\nS e() {\n    return S{0LL, INF, -INF};\n}\nstruct F {\n    ll a, b;\n};\nS\
    \ mapping(F f, S s) {\n    return S{\n        s.sum + (f.a * (s.l + s.r - 1) +\
    \ f.b * 2) * (s.r - s.l) / 2,\n        s.l, s.r\n        };\n}\nF composition(F\
    \ f, F g) {\n    return {f.a + g.a, f.b + g.b};\n};\nF id() {\n    return F{0,\
    \ 0};\n}\n\nusing lazy = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n\ntemplate <typename T>\nstruct LazySegtree_arith : lazy {\n    using\
    \ lazy::lazy; // \u57FA\u5E95\u30AF\u30E9\u30B9\u304C\u6301\u3064\u5168\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u3001\u6D3E\u751F\u30AF\u30E9\u30B9\u3067\
    \u3082\u4F7F\u3048\u308B\u3088\u3046\u306B\u3059\u308B\n    LazySegtree_arith(int\
    \ N) {\n        std::vector<S> vec(N);\n        for (int i = 0; i < N; i++) {\n\
    \            vec[i] = S{0, i, i + 1};\n        }\n        LazySegtree_arith tmp(vec);\
    \ // using lazy::lazy \u306B\u3088\u308B\u3001acl \u306E\u9045\u5EF6\u30BB\u30B0\
    \u6728\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u547C\u3073\u51FA\
    \u3057\u3066\u3044\u308B\n        /**\n         * \u6D3E\u751F\u30AF\u30E9\u30B9\
    \u306B\u304A\u3044\u3066\u3001int N \u3060\u3051\u6E21\u3057\u3066\u4E2D\u8EAB\
    \u306F\u30BC\u30ED\u521D\u671F\u5316\u3001vector<ll> \u3092\u6E21\u3057\u3066\
    \ vector<S> \u306B\u5909\u63DB\u3057\u3066\u304B\u3089\u521D\u671F\u5316\u3001\
    \u306A\u3069\u3001\u5225\u306E\u5F15\u6570\u30D1\u30BF\u30FC\u30F3\u3067\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u5B9A\u7FA9\u3057\u305F\u3044\u3002\
    \n         * \u3057\u304B\u3057\u3001\u6D3E\u751F\u30AF\u30E9\u30B9\u3067\u3082\
    \u308F\u3056\u308F\u3056\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\u3059\u308B\u306E\
    \u306F\u9762\u5012 \u2192 \u57FA\u5E95\u30AF\u30E9\u30B9\u306E\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3092\u547C\u3073\u51FA\u3057\u3066\u30BB\u30B0\u6728\
    \u3092\u69CB\u7BC9\u3057\u3066\uFF08\u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u306E\u751F\u6210\u3002\u91CD\u3044\u521D\u671F\u5316\u3092\u57FA\u5E95\
    \u30AF\u30E9\u30B9\u306B\u4E38\u6295\u3052\uFF09\u3001\u305D\u306E\u4E00\u6642\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092 *this \u306B\u30B3\u30D4\u30FC\u3002\
    \n         */\n        (*this) = tmp;\n    }\n    LazySegtree_arith(std::vector<T>\
    \ v) {\n        std::vector<S> vec((int)v.size());\n        for (int i = 0; i\
    \ < (int)v.size(); i++) {\n            vec[i] = S{v[i], i, i + 1};\n        }\n\
    \        LazySegtree_arith tmp(vec);\n        (*this) = tmp;\n    }\n\n    /**\n\
    \     * @brief b, a+b, ..., (r-l)a + b \u3092\u52A0\u7B97\n     */\n    void apply(int\
    \ l, int r, F f) {\n        lazy::apply(l, r, F{f.a, f.b - f.a * get(l).l});\n\
    \    }\n    /**\n     * @brief la + b, (l+1)a + b, ..., (r-1)a + b \u3092\u52A0\
    \u7B97\n     */\n    void apply_idx(int l, int r, F f) {\n        lazy::apply(l,\
    \ r, f);\n    }\n};\n\n} // namespace arith_add\n\n#endif // LazySegtree_arith_add_HPP"
  dependsOn:
  - Others/macros.hpp
  - ac-library/atcoder/lazysegtree.hpp
  - ac-library/atcoder/internal_bit.hpp
  isVerificationFile: false
  path: DataStructure/LazySegtree_arith_add.hpp
  requiredBy: []
  timestamp: '2025-05-28 18:48:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/LazySegtree_arith_add.hpp
layout: document
redirect_from:
- /library/DataStructure/LazySegtree_arith_add.hpp
- /library/DataStructure/LazySegtree_arith_add.hpp.html
title: "b, a+b, ..., (r-l)a + b \u3092\u52A0\u7B97"
---
