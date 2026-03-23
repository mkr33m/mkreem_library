#ifndef Segtree_HPP
#define Segtree_HPP

#include <vector>
#include <cassert>

template <typename S, S (*op)(S, S), S (*e)()>
struct Segtree {
private:
    int p;
    int siz; // 配列の長さ
    int N; // 配列の長さ以上の 2 冪
    std::vector<S> seg;

public:
    Segtree(int siz) : siz(siz), p(0) {
        while (siz > (1 << p)) {
            p++;
        }
        N = (1 << p);
        seg.assign(2 * N, e());
    }
    Segtree(const std::vector<S>& vec) : siz((int)vec.size()), p(0) {
        while (siz > (1 << p)) {
            p++;
        }
        N = (1 << p);
        seg.assign(2 * N, e());
        for (int i = 0; i < siz; i++) {
            seg[i + N] = vec[i];
        }
        for (int i = N - 1; i >= 1; i--) {
            seg[i] = op(seg[(i << 1) | 0], seg[(i << 1) | 1]);
        }
    }

    S get(int i) {
        assert(0 <= i);
        assert(i < siz);
        i += N;
        return seg[i];
    }
    void set(int i, S s) {
        assert(0 <= i);
        assert(i < siz);
        i += N;
        seg[i] = s;
        while (i > 1) {
            i >>= 1;
            seg[i] = op(seg[(i << 1) | 0], seg[(i << 1) | 1]);
        }
    }
    void add(int i, S s) {
        assert(0 <= i);
        assert(i < siz);
        i += N;
        seg[i] = op(seg[i], s);
        while (i > 1) {
            i >>= 1;
            seg[i] = op(seg[i << 1], seg[(i << 1) | 1]);
        }
    }
    S prod(int l, int r) { // [l,r)
        assert(0 <= l);
        assert(l <= r);
        assert(r <= siz);
        S resL = e(), resR = e();
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            // 交換法則を仮定しなくてよい
            if (l & 1) {
                resL = op(resL, seg[l++]);
            }
            if (r & 1) {
                resR = op(seg[--r], resR);
            }
        }
        return op(resL, resR);
    }
    /**
     * @brief f(prod[L,r))=true となる最大の r を返す
     */
    int max_right(int L, auto f) {
        assert(0 <= L);
        assert(L <= siz);
        assert(f(e()));
        if (L == siz) {
            return siz;
        }
        int l = L + N, r = siz + N;
        std::vector<int> nodes, right_nodes; // [l,siz) のノード列
        while (l < r) {
            if (l & 1) {
                nodes.push_back(l++);
            }
            if (r & 1) {
                right_nodes.push_back(--r);
            }
            l >>= 1, r >>= 1;
        }
        for (int i = (int)right_nodes.size() - 1; i >= 0; i--) {
            nodes.push_back(right_nodes[i]);
        }
        S sm = e();
        for (int k = 0; k < (int)nodes.size(); k++) {
            int i = nodes[k];
            S nxt = op(sm, seg[i]);
            if (f(nxt)) {
                sm = nxt;
                continue;
            }
            // seg[i] から下っていく
            while (i < N) {
                int li = i << 1, ri = (i << 1) | 1;
                nxt = op(sm, seg[li]);
                if (f(nxt)) {
                    sm = nxt;
                    i = ri;
                } else {
                    i = li;
                }
            }
            return i - N;
        }
        return siz;
    }
    /**
     * @brief f(prod[l,R))=true となる最小の l を返す
     */
    int min_left(int R, auto f) {
        assert(0 <= R);
        assert(R <= siz);
        assert(f(e()));
        if (R == 0) {
            return 0;
        }
        int l = 0 + N, r = R + N;
        // [0,r) の場合、左側から回収されるノードはない
        std::vector<int> nodes; 
        while (l < r) {
            if (r & 1) {
                nodes.push_back(--r);
            }
            l >>= 1, r >>= 1;
        }
        S sm = e();
        for (int k = 0; k < (int)nodes.size(); k++) {
            int i = nodes[k];
            S nxt = op(seg[i], sm); // 非可換でも OK
            if (f(nxt)) {
                sm = nxt;
                continue;
            }
            while (i < N) {
                int li = (i << 1), ri = (i << 1) | 1;
                nxt = op(seg[ri], sm);
                if (f(nxt)) {
                    sm = nxt;
                    i = li;
                } else {
                    i = ri;
                }
            }
            return i - N + 1;
        }
        return 0;
    }
};

#endif // Segtree_HPP