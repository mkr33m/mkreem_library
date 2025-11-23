#ifndef LazySegtree_arith_HPP
#define LazySegtree_arith_HPP

#include <vector>
#include <algorithm>
#include "../Others/macros.hpp"
//#include "../ac-library/atcoder/lazysegtree.hpp"
#include <atcoder/lazysegtree>

namespace arith {

struct S {
    ll max, min, sum;
    int l, r;
};
S op(S L, S R) {
    return S{std::max(L.max, R.max), std::min(L.min, R.min), L.sum + R.sum, std::min(L.l, R.l), std::max(L.r, R.r)};
}
S e() {
    return S{-LLINF, LLINF, 0LL, INF, -INF};
}
struct F {
    ll a, b;
};
S mapping(F f, S s) {
    if (f.a == LLINF) {
        return s;
    }
    ll m = f.a * s.l + f.b;
    ll M = f.a * (s.r - 1) + f.b;
    if (f.a < 0) {
        std::swap(M, m);
    }
    return S{
        M, m,
        (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2,
        s.l, s.r
        };
}
F composition(F f, F g) {
    return (f.a == LLINF ? g : f);
};
F id() {
    return F{LLINF, LLINF};
}

using lazy = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

template <typename T>
struct LazySegtree_arith : lazy {
    using lazy::lazy; // 基底クラスが持つ全コンストラクタを、派生クラスでも使えるようにする
    LazySegtree_arith(int N) {
        std::vector<S> vec(N);
        for (int i = 0; i < N; i++) {
            vec[i] = S{0, 0, 0, i, i + 1};
        }
        LazySegtree_arith tmp(vec); // using lazy::lazy による、acl の遅延セグ木のコンストラクタを呼び出している
        /**
         * 派生クラスにおいて、int N だけ渡して中身はゼロ初期化、vector<ll> を渡して vector<S> に変換してから初期化、など、別の引数パターンでコンストラクタを定義したい。
         * しかし、派生クラスでもわざわざセグ木を構築するのは面倒 → 基底クラスのコンストラクタを呼び出してセグ木を構築して（一時オブジェクトの生成。重い初期化を基底クラスに丸投げ）、その一時オブジェクトを *this にコピー。
         */
        (*this) = tmp;
    }
    LazySegtree_arith(std::vector<T> v) {
        std::vector<S> vec((int)v.size());
        for (int i = 0; i < (int)v.size(); i++) {
            vec[i] = S{v[i], v[i], v[i], i, i + 1};
        }
        LazySegtree_arith tmp(vec);
        (*this) = tmp;
    }

    /**
     * @brief b, a+b, ..., (r-l)a + b で更新
     */
    void apply(int l, int r, F f) {
        lazy::apply(l, r, F{f.a, f.b - f.a * get(l).l});
    }
    /**
     * @brief la + b, (l+1)a + b, ..., (r-1)a + b で更新
     */
    void apply_idx(int l, int r, F f) {
        lazy::apply(l, r, F{f.a, f.b - f.a * get(l).l});
    }
};

} // namespace arith

#endif // LazySegtree_arith_HPP