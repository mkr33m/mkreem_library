#ifndef UF_ComponentSum_HPP
#define UF_ComponentSum_HPP

#include <vector>

#include "UnionFind.hpp"

/**
 * @param T モノイド（連結成分が持つ情報）の型
 */
template <typename T>
using merge_function = void(*)(T& component_sum1, T component_sum2);

// 型引数、非型引数（コンパイル時に定まるものに限る）
template <typename T, merge_function<T> f>
class UF_ComponentSum : public UnionFind { // 継承
    std::vector<T> sum_;

public:
    UF_ComponentSum() = default;
    UF_ComponentSum(const std::vector<T>& init) : 
        UnionFind((int)init.size()), sum_(init) {}

    /**
     * @brief u が所属する連結成分の sum と v が所属する連結成分の sum を統合する
     */
    bool merge(const int& u, const int& v) {
        int prev_root_u = root(u), prev_root_v = root(v);
        bool merged = UnionFind::merge(u, v);
        if (merged) {
            int root_u = root(u);
            /*
            merge 後、
            ・prev_root_u == root_u -> 連結後の成分の根は prev_root_u
            ・prev_root_u != root_u -> 連結後の成分の根は prev_root_v
            */
            if (prev_root_u != root_u) {
                f(sum_[prev_root_v], std::move(sum_[prev_root_u]));
            } else {
                f(sum_[prev_root_u], std::move(sum_[prev_root_v]));
            }
        }

        return merged;
    }

    T sum(const int& v) {
        int root_v = root(v);
        return sum_[root_v];
    }

};

#endif // UF_ComponentSum_HPP