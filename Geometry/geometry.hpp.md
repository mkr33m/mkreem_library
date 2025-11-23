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
    document_title: "\u5185\u7A4D\u3092\u6C42\u3081\u308B"
    links: []
  bundledCode: "#line 1 \"Geometry/geometry.hpp\"\n\n\n\n#line 1 \"Others/macros.hpp\"\
    \n\n\n\n#include <vector>\n#include <queue>\n#include <cmath>\n\nusing ll = long\
    \ long;\nusing lll = __int128_t;\nusing ld = long double;\n#define newl '\\n'\n\
    #define REF const auto&\n#define INF 1000390039\n#define LLINF 1000000039000000039\n\
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
    // 1D\n#define VC(name, type, ...) \\\n    vector<type> name( \\\n        __VA_ARGS__\
    \ \\\n    )\n// 2D\n#define VVC(name, type, a, ...) \\\n    vector<vector<type>>\
    \ name( \\\n        (a), vector<type>( \\\n            __VA_ARGS__ \\\n      \
    \  ) \\\n    )\n// 3D\n#define VVVC(name, type, a, b, ...) \\\n    vector<vector<vector<type>>>\
    \ name( \\\n        (a), vector<vector<type>>( \\\n            (b), vector<type>(\
    \ \\\n                __VA_ARGS__ \\\n            ) \\\n        ) \\\n    )\n\
    // 4D\n#define VVVVC(name, type, a, b, c, ...) \\\n    vector<vector<vector<vector<type>>>>\
    \ name( \\\n        (a), vector<vector<vector<type>>>( \\\n            (b), vector<vector<type>>(\
    \ \\\n                (c), vector<type>( \\\n                    __VA_ARGS__ \\\
    \n                ) \\\n            ) \\\n        ) \\\n    )\n// 5D\n#define\
    \ VVVVVC(name, type, a, b, c, d, ...) \\\n    vector<vector<vector<vector<vector<type>>>>>\
    \ name( \\\n        (a), vector<vector<vector<vector<type>>>>( \\\n          \
    \  (b), vector<vector<vector<type>>>( \\\n                (c), vector<vector<type>>(\
    \ \\\n                    (d), vector<type>( \\\n                        __VA_ARGS__\
    \ \\\n                    ) \\\n                ) \\\n            ) \\\n     \
    \   ) \\\n    )\n// 6D\n#define VVVVVVC(name, type, a, b, c, d, e, ...) \\\n \
    \   vector<vector<vector<vector<vector<vector<type>>>>>> name( \\\n        (a),\
    \ vector<vector<vector<vector<vector<type>>>>>( \\\n            (b), vector<vector<vector<vector<type>>>>(\
    \ \\\n                (c), vector<vector<vector<type>>>( \\\n                \
    \    (d), vector<vector<type>>( \\\n                        (e), vector<type>(\
    \ \\\n                            __VA_ARGS__ \\\n                        ) \\\
    \n                    ) \\\n                ) \\\n            ) \\\n        )\
    \ \\\n    )\ntemplate <typename T>\nint lwb(const std::vector<T>& vec, const T&\
    \ x){\n    return lower_bound(all(vec), x) - vec.begin();\n}\ntemplate <typename\
    \ T>\nint upb(const std::vector<T>& vec, const T& x){\n    return upper_bound(all(vec),\
    \ x) - vec.begin();\n}\ntemplate <typename T>\nT max(const std::vector<T>& vec){\
    \ return *max_element(all(vec)); }\ntemplate <typename T>\nT min(const std::vector<T>&\
    \ vec){ return *min_element(all(vec)); }\ntemplate <typename T>\nT rad(const T&\
    \ x){ return x * PI/180; }\ntemplate <typename T>\nusing maxpq = std::priority_queue<T>;\n\
    template <typename T>\nusing minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    // \u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u66F4\u65B0\ntemplate <typename\
    \ T1, typename T2>\nbool chmax(T1 &a, const T2& b){\n    if (a < b) { a = b; return\
    \ 1; }\n    return 0;\n}\ntemplate <typename T1, typename T2>\nbool chmin(T1 &a,\
    \ const T2& b){\n    if (a > b) { a = b; return 1; }\n    return 0;\n}\n\nconst\
    \ int di4[4] = {0, -1, 0, 1};\nconst int dj4[4] = {1, 0, -1, 0};\nconst int di8[8]\
    \ = {0, -1, -1, -1, 0, 1, 1, 1};\nconst int dj8[8] = {1, 1, 0, -1, -1, -1, 0,\
    \ 1};\n\nbool out_of_grid(const int& i, const int& j, const int& h, const int&\
    \ w){\n    if(i < 0 || j < 0 || i >= h || j >= w) return true;\n    return false;\n\
    }\n\n\n#line 5 \"Geometry/geometry.hpp\"\n#include <complex>\n#include <cassert>\n\
    \nnamespace geom {\n\n/**\n * real \u304C x \u8EF8\n * imag \u304C y \u8EF8\n\
    \ */\nusing Point = std::complex<ld>;\nconst ld EPS = 1e-7;\n\ninline bool equal(const\
    \ ld& a, const ld& b) {\n    return fabs(a - b) < EPS;\n}\n\n/**\n * @brief \u5185\
    \u7A4D\u3092\u6C42\u3081\u308B\n */\nld dot(const Point& a, const Point& b) {\n\
    \    return a.real() * b.real() + a.imag() * b.imag();\n}\n\n/**\n * @brief \u5916\
    \u7A4D\u3092\u6C42\u3081\u308B\n */\nld cross(const Point& a, const Point& b)\
    \ {\n    return a.real() * b.imag() - a.imag() * b.real();\n}\n\n/**\n * @brief\
    \ \u70B9 p \u3092\u53CD\u6642\u8A08\u5468\u308A\u306B theta \u5EA6\u56DE\u8EE2\
    \n */\nPoint rotate(const Point& p, const ld& theta) {\n    return Point(p.real()\
    \ * cos(theta) - p.imag() * sin(theta), \n                    p.real() * sin(theta)\
    \ + cos(theta) * p.imag());\n}\n\n/**\n * @brief \u76F4\u7DDA\u3092\u8868\u3059\
    \u69CB\u9020\u4F53\n * @brief b - a \u306B\u3088\u308A\u3001\u76F4\u7DDA\u30FB\
    \u7DDA\u5206\u3092\u8868\u305B\u308B\n */\nstruct Line {\n    /**\n     * @param\
    \ a, b \u76F4\u7DDA\u304C\u901A\u904E\u3059\u308B 2 \u70B9\n     */\n    Point\
    \ a, b;\n    Line() = default;\n    Line(Point a, Point b) : a(a), b(b) {}\n\n\
    \    /**\n     * Ax + By = C\n     */\n    Line (ld A, ld B, ld C) {\n       \
    \ if (equal(A, 0)) { // \u6C34\u5E73 -> y = C/B\n            a = Point(0, C /\
    \ B), b = Point(1, C / B);\n        } else if (equal(B, 0)) { // \u5782\u76F4\
    \ -> x = C/A\n            a = Point(C / A, 0), b = Point(C / A, 1);\n        }\
    \ else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n        }\n \
    \   }\n};\n\n/**\n * @brief \u7DDA\u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\n\
    \ * @remark \u69CB\u9020\u4F53 Line \u3092\u7D99\u627F\n */\nstruct Segment :\
    \ Line {\n    Segment() = default;\n\n    Segment(Point a, Point b) : Line(a,\
    \ b) {}\n};\n\n/**\n * @brief \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n */\n\
    struct Circle {\n    /**\n     * @param p \u4E2D\u5FC3\u306E\u4F4D\u7F6E\u30D9\
    \u30AF\u30C8\u30EB\n     * @param r \u534A\u5F84\n     */\n    Point p;\n    ld\
    \ r;\n\n    Circle() = default;\n    Circle(Point p, ld r) : p(p), r(r) {\n  \
    \      assert(r >= -EPS);\n    }\n};\n\n/**\n * @brief \u2192pr \u306F \u2192\
    pq \u3092\u3069\u3061\u3089\u306E\u65B9\u5411\u306B\uFF08p \u57FA\u6E96\u3067\uFF09\
    \u56DE\u8EE2\u3055\u305B\u305F\u3089\u3001\u3088\u308A\u65E9\u304F \u2192pq \u306E\
    \u5411\u304D\u306B\u4E00\u81F4\u3055\u305B\u3089\u308C\u308B\u304B\u3092\u5224\
    \u5B9A\n * @remark Counter-ClockWise\n */\nint ccw(const Point& p, Point q, Point\
    \ r) {\n    q -= p, r -= p;\n    // \u53CD\u6642\u8A08\u56DE\u308A\n    if (cross(q,\
    \ r) > EPS) {\n        return 1;\n    }\n    // \u6642\u8A08\u56DE\u308A\n   \
    \ if (cross(q, r) < -EPS) {\n        return -1;\n    }\n    // r, p, q \u304C\u3053\
    \u306E\u9806\u3067\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(q, r) < 0) {\n       \
    \ return -2;\n    }\n    // p, q, r \u304C\u3053\u306E\u9806\u3067\u4E00\u76F4\
    \u7DDA\u4E0A\n    if (norm(q) < norm(r)) {\n        return 2;\n    }\n    // q\
    \ \u304C\u7DDA\u5206 pq \u4E0A\n    return 3;\n}\n\n/**\n * @brief \u5185\u7A4D\
    \u3092\u6C42\u3081\u308B\n * @return \u70B9 p \u304B\u3089\u76F4\u7DDA l \u306B\
    \u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\u8DB3\n */\nPoint projection(const\
    \ Line& l, const Point& p) {\n    ld t = dot(p - l.a, l.a - l.b) / std::norm(l.a\
    \ - l.b);\n    return l.a + t * (l.a - l.b);\n};\n\nPoint projection(const Segment\
    \ &l, const Point &p) {\n    ld t = dot(p - l.a, l.a - l.b) / std::norm(l.a -\
    \ l.b);\n    return l.a + t * (l.a - l.b);\n}\n\n/**\n* @brief \u53CD\u5C04\u3092\
    \u6C42\u3081\u308B\n* @return \u76F4\u7DDA l \u306B\u95A2\u3057\u3066\u3001\u70B9\
    \ p \u306E\u53CD\u5BFE\u5074\u306B\u3042\u308B\u70B9\n*/\nPoint refrection(const\
    \ Line& l, const Point& p) {\n    Point ah = projection(l, p);\n    return p +\
    \ 2.0l * (ah - p);\n}\n\n/**\n * @brief 2 \u76F4\u7DDA\u306E\u76F4\u884C\u5224\
    \u5B9A -> \u5185\u7A4D\u304C 0\n */\nbool is_orthogonal(const Line& s, const Line&\
    \ t) {\n    return equal(dot(s.b - s.a, t.b - t.a), 0);\n}\n\n/**\n * @brief 2\
    \ \u76F4\u7DDA\u306E\u4E26\u884C\u5224\u5B9A -> \u5916\u7A4D\u304C 0\n */\nbool\
    \ is_parallel(const Line& s, const Line& t) {\n    return equal(cross(s.b - s.a,\
    \ t.b - t.a), 0);\n}\n\n/**\n * @brief \u76F4\u7DDA\u306E\u4EA4\u70B9\u3092\u6C42\
    \u3081\u308B\n * @return \u76F4\u7DDA s, t \u306E\u4EA4\u70B9\n */\nPoint cross_point(const\
    \ Line& s, const Line& t) {\n    ld d1 = cross(t.b - t.a, s.b - s.a);\n    ld\
    \ d2 = cross(s.a - t.a, s.b - s.a);\n    if (equal(abs(d1), 0) and equal(abs(d2),\
    \ 0)) {\n        return t.a;\n    }\n    return t.a + (d2 / d1) * (t.b - t.a);\n\
    }\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\u70B9\u3092\u6C42\u3081\u308B\n */\n\
    Point cross_point(const Segment& s, const Segment& t) {\n    return cross_point(Line(s),\
    \ Line(t));\n}\n\n/**\n * @brief \u70B9 p, q, r \u304C\u5468\u4E0A\u306B\u5B58\
    \u5728\u3059\u308B\u5186\u306E\u5916\u5FC3\u3092\u6C42\u3081\u308B\n */\nPoint\
    \ gaisin(Point p, Point q, Point r) {\n    Line pq((p + q) * 0.5l, (p + q) * 0.5l\
    \ + rotate(p - q, PI / 2));\n    Line qr((q + r) * 0.5l, (q + r) * 0.5l + rotate(q\
    \ - r, PI / 2));\n    return cross_point(pq, qr);\n}\n\n} // namespace geom\n\n\
    \n\n\n\n"
  code: "#ifndef H_Point\n#define H_Point\n\n#include \"../Others/macros.hpp\"\n#include\
    \ <complex>\n#include <cassert>\n\nnamespace geom {\n\n/**\n * real \u304C x \u8EF8\
    \n * imag \u304C y \u8EF8\n */\nusing Point = std::complex<ld>;\nconst ld EPS\
    \ = 1e-7;\n\ninline bool equal(const ld& a, const ld& b) {\n    return fabs(a\
    \ - b) < EPS;\n}\n\n/**\n * @brief \u5185\u7A4D\u3092\u6C42\u3081\u308B\n */\n\
    ld dot(const Point& a, const Point& b) {\n    return a.real() * b.real() + a.imag()\
    \ * b.imag();\n}\n\n/**\n * @brief \u5916\u7A4D\u3092\u6C42\u3081\u308B\n */\n\
    ld cross(const Point& a, const Point& b) {\n    return a.real() * b.imag() - a.imag()\
    \ * b.real();\n}\n\n/**\n * @brief \u70B9 p \u3092\u53CD\u6642\u8A08\u5468\u308A\
    \u306B theta \u5EA6\u56DE\u8EE2\n */\nPoint rotate(const Point& p, const ld& theta)\
    \ {\n    return Point(p.real() * cos(theta) - p.imag() * sin(theta), \n      \
    \              p.real() * sin(theta) + cos(theta) * p.imag());\n}\n\n/**\n * @brief\
    \ \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n * @brief b - a \u306B\u3088\
    \u308A\u3001\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n */\nstruct\
    \ Line {\n    /**\n     * @param a, b \u76F4\u7DDA\u304C\u901A\u904E\u3059\u308B\
    \ 2 \u70B9\n     */\n    Point a, b;\n    Line() = default;\n    Line(Point a,\
    \ Point b) : a(a), b(b) {}\n\n    /**\n     * Ax + By = C\n     */\n    Line (ld\
    \ A, ld B, ld C) {\n        if (equal(A, 0)) { // \u6C34\u5E73 -> y = C/B\n  \
    \          a = Point(0, C / B), b = Point(1, C / B);\n        } else if (equal(B,\
    \ 0)) { // \u5782\u76F4 -> x = C/A\n            a = Point(C / A, 0), b = Point(C\
    \ / A, 1);\n        } else {\n            a = Point(0, C / B), b = Point(C / A,\
    \ 0);\n        }\n    }\n};\n\n/**\n * @brief \u7DDA\u5206\u3092\u8868\u3059\u69CB\
    \u9020\u4F53\n * @remark \u69CB\u9020\u4F53 Line \u3092\u7D99\u627F\n */\nstruct\
    \ Segment : Line {\n    Segment() = default;\n\n    Segment(Point a, Point b)\
    \ : Line(a, b) {}\n};\n\n/**\n * @brief \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\
    \n */\nstruct Circle {\n    /**\n     * @param p \u4E2D\u5FC3\u306E\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\n     * @param r \u534A\u5F84\n     */\n    Point p;\n\
    \    ld r;\n\n    Circle() = default;\n    Circle(Point p, ld r) : p(p), r(r)\
    \ {\n        assert(r >= -EPS);\n    }\n};\n\n/**\n * @brief \u2192pr \u306F \u2192\
    pq \u3092\u3069\u3061\u3089\u306E\u65B9\u5411\u306B\uFF08p \u57FA\u6E96\u3067\uFF09\
    \u56DE\u8EE2\u3055\u305B\u305F\u3089\u3001\u3088\u308A\u65E9\u304F \u2192pq \u306E\
    \u5411\u304D\u306B\u4E00\u81F4\u3055\u305B\u3089\u308C\u308B\u304B\u3092\u5224\
    \u5B9A\n * @remark Counter-ClockWise\n */\nint ccw(const Point& p, Point q, Point\
    \ r) {\n    q -= p, r -= p;\n    // \u53CD\u6642\u8A08\u56DE\u308A\n    if (cross(q,\
    \ r) > EPS) {\n        return 1;\n    }\n    // \u6642\u8A08\u56DE\u308A\n   \
    \ if (cross(q, r) < -EPS) {\n        return -1;\n    }\n    // r, p, q \u304C\u3053\
    \u306E\u9806\u3067\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(q, r) < 0) {\n       \
    \ return -2;\n    }\n    // p, q, r \u304C\u3053\u306E\u9806\u3067\u4E00\u76F4\
    \u7DDA\u4E0A\n    if (norm(q) < norm(r)) {\n        return 2;\n    }\n    // q\
    \ \u304C\u7DDA\u5206 pq \u4E0A\n    return 3;\n}\n\n/**\n * @brief \u5185\u7A4D\
    \u3092\u6C42\u3081\u308B\n * @return \u70B9 p \u304B\u3089\u76F4\u7DDA l \u306B\
    \u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\u8DB3\n */\nPoint projection(const\
    \ Line& l, const Point& p) {\n    ld t = dot(p - l.a, l.a - l.b) / std::norm(l.a\
    \ - l.b);\n    return l.a + t * (l.a - l.b);\n};\n\nPoint projection(const Segment\
    \ &l, const Point &p) {\n    ld t = dot(p - l.a, l.a - l.b) / std::norm(l.a -\
    \ l.b);\n    return l.a + t * (l.a - l.b);\n}\n\n/**\n* @brief \u53CD\u5C04\u3092\
    \u6C42\u3081\u308B\n* @return \u76F4\u7DDA l \u306B\u95A2\u3057\u3066\u3001\u70B9\
    \ p \u306E\u53CD\u5BFE\u5074\u306B\u3042\u308B\u70B9\n*/\nPoint refrection(const\
    \ Line& l, const Point& p) {\n    Point ah = projection(l, p);\n    return p +\
    \ 2.0l * (ah - p);\n}\n\n/**\n * @brief 2 \u76F4\u7DDA\u306E\u76F4\u884C\u5224\
    \u5B9A -> \u5185\u7A4D\u304C 0\n */\nbool is_orthogonal(const Line& s, const Line&\
    \ t) {\n    return equal(dot(s.b - s.a, t.b - t.a), 0);\n}\n\n/**\n * @brief 2\
    \ \u76F4\u7DDA\u306E\u4E26\u884C\u5224\u5B9A -> \u5916\u7A4D\u304C 0\n */\nbool\
    \ is_parallel(const Line& s, const Line& t) {\n    return equal(cross(s.b - s.a,\
    \ t.b - t.a), 0);\n}\n\n/**\n * @brief \u76F4\u7DDA\u306E\u4EA4\u70B9\u3092\u6C42\
    \u3081\u308B\n * @return \u76F4\u7DDA s, t \u306E\u4EA4\u70B9\n */\nPoint cross_point(const\
    \ Line& s, const Line& t) {\n    ld d1 = cross(t.b - t.a, s.b - s.a);\n    ld\
    \ d2 = cross(s.a - t.a, s.b - s.a);\n    if (equal(abs(d1), 0) and equal(abs(d2),\
    \ 0)) {\n        return t.a;\n    }\n    return t.a + (d2 / d1) * (t.b - t.a);\n\
    }\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\u70B9\u3092\u6C42\u3081\u308B\n */\n\
    Point cross_point(const Segment& s, const Segment& t) {\n    return cross_point(Line(s),\
    \ Line(t));\n}\n\n/**\n * @brief \u70B9 p, q, r \u304C\u5468\u4E0A\u306B\u5B58\
    \u5728\u3059\u308B\u5186\u306E\u5916\u5FC3\u3092\u6C42\u3081\u308B\n */\nPoint\
    \ gaisin(Point p, Point q, Point r) {\n    Line pq((p + q) * 0.5l, (p + q) * 0.5l\
    \ + rotate(p - q, PI / 2));\n    Line qr((q + r) * 0.5l, (q + r) * 0.5l + rotate(q\
    \ - r, PI / 2));\n    return cross_point(pq, qr);\n}\n\n} // namespace geom\n\n\
    \n\n\n#endif // H_Point"
  dependsOn:
  - Others/macros.hpp
  isVerificationFile: false
  path: Geometry/geometry.hpp
  requiredBy: []
  timestamp: '2025-11-23 17:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/geometry.hpp
layout: document
redirect_from:
- /library/Geometry/geometry.hpp
- /library/Geometry/geometry.hpp.html
title: "\u5185\u7A4D\u3092\u6C42\u3081\u308B"
---
