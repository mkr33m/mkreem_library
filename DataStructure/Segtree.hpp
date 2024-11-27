#ifndef Segtree_HPP
#define Segtree_HPP

#include <vector>
#include <cassert>
#include <functional>
#include <iostream>

template <typename Monoid>
class Segtree {

using T = typename Monoid::S;
std::vector<T> seg_; // 1-indexed で管理
int N_;
int seg_N_;

using F = std::function<bool(const T&)>; // 二分探索の判定関数

int min_pow(int N) const {
    int res = 1;
    while (res < N) {
        res <<= 1;
    }
    return res;
}

void update_node(int i) {
    int left_child_idx = i << 1;
    int right_child_idx = (i << 1) + 1;
    seg_[i] = Monoid::op(seg_[left_child_idx], seg_[right_child_idx]);
}

public:
    Segtree(const std::vector<T>& data) : N_(data.size()) {
        seg_N_ = min_pow(N_);
        seg_.assign(2 * seg_N_, Monoid::e());

        for (int i = 0; i < N_; i++) {
            seg_[seg_N_ + i] = data[i];
        }
        for (int i = seg_N_ - 1; i >= 1; i--) {
            update_node(i);
        }
    }
    Segtree(int N, T initial_value) : Segtree(std::vector<T>(N, initial_value)) {}
    Segtree(int N) : Segtree(std::vector<T>(N, T())) {}
    Segtree() : seg_(), N_(0), seg_N_(0) {}

    void set(int i, T x) {
        assert(0 <= i && i < N_);

        i += seg_N_;
        seg_[i] = x;

        while (i > 1) { // 親を辿って更新していく
            i >>= 1;
            update_node(i);
        }
    }

    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= N_);

        T left_val = Monoid::e(), right_val = Monoid::e();
        l += seg_N_, r += seg_N_;
        while (l < r) {
            if (l & 1) {
                // 奇数 -> 足してからずらす
                left_val = Monoid::op(left_val, seg_[l++]);
            }
            if (r & 1) { 
                // 偶数 -> ずらしてから足す（開区間だから）
                right_val = Monoid::op(seg_[--r], right_val);
            }
            
            l >>= 1, r >>= 1;
        }
        return Monoid::op(left_val, right_val);
    }

    T all_prod() const {
        return seg_[1];
    }

    T get(int i) const {
        assert(0 <= i && i < N_);

        return seg_[seg_N_ + i];
    }

    template <typename F>
    int max_right(int l, const F& f) const {
        assert(0 <= l && l < N_);
        assert(f(Monoid::e()));

        if (!f(seg_[l + seg_N_])) { // r が存在しない
            return l; // (== r)
        }

        l += seg_N_;
        T prod = Monoid::e();
        int r = l;
        int next_r = r + 1;

        while (1) {
            if (!(next_r & 1)) { // 偶数なら、親ノードへ
                next_r >>= 1;
            }
            T next_prod = Monoid::op(prod, seg_[next_r]);
            if (!f(next_prod)) {
                while (next_r < seg_N_ && !f(next_prod)) {
                    next_r <<= 1; // 条件を満たしてくれるまで、左の子を辿っていく
                    next_prod = Monoid::op(prod, seg_[next_r]);
                }
                if (!f(next_prod)) {
                    break;
                }
            }
            r = next_r; // r を更新
            prod = next_prod; // prod を更新
            next_r = r + 1; // 次のノード

            if ((next_r & (next_r - 1)) == 0) { // 2 冪になったら終了
                break;
            }
        }

        // r が葉にたどり着くまで潜っていく
        while (r < seg_N_) {
            r <<= 1;
            r++;
        }

        r -= seg_N_;

        return r + 1; // 開区間に戻す
    }

    template <typename F> 
    int min_left(int r, const F& f) {
        assert(0 <= r && r <= N_);
        assert(f(Monoid::e()));

        if (!f(seg_[r - 1 + seg_N_])) { // l が存在しない
            return r; // (== l)
        }

        r += seg_N_;
        T prod = Monoid::e();
        int l = r;
        int next_l = l - 1;

        while (1) {
            if (next_l & 1) { // 奇数なら、親ノードへ
                next_l >>= 1;
            }
            T next_prod = Monoid::op(prod, seg_[next_l]);
            if (!f(next_prod)) {
                while (next_l < seg_N_ && !f(next_prod)) {
                    next_l <<= 1; // 条件を満たしてくれるまで、右の子を辿っていく
                    next_l++;
                    next_prod = Monoid::op(prod, seg_[next_l]);
                }
                if (!f(next_prod)) {
                    break;
                }
            }
            l = next_l; // l を更新
            prod = next_prod; // prod を更新
            next_l = l - 1; // 次のノード

            if (((next_l + 1) & next_l) == 0) { // 2^n - 1 の形になったら終了
                break;
            }
        }

        // r が葉にたどり着くまで潜っていく
        while (l < seg_N_) {
            l <<= 1;
        }

        l -= seg_N_;

        return l; // 開区間に戻す
    }

};

#endif // Segtree_HPP