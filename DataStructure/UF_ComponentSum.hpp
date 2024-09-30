#ifndef UF_ComponentSum_HPP
#define UF_ComponentSum_HPP

#include <vector>

#include "UnionFind.hpp"

/**
 * @param T モノイド（連結成分が持つ情報）の型
 */
template <typename T>
using merge_function = void(*)(T& parent_data, T child_data);

template <typename T, merge_function<T> f>
struct UF_ComponentSum : UnionFind {
private:
    std::vector<T> sum_;

public:
    UF_ComponentSum() : UF_ComponentSum(0) {}
    UF_ComponentSum(int N, const T& init_value = T{}) : UF_ComponentSum(std::vector<T>(N, init_value)) {}
    UF_ComponentSum(const std::vector<T>& init_values) : UnionFind(init_values.size()), sum_(init_values) {}

    bool merge(int x, int y){
        x = root(x), y = root(y); // <- 根
        bool res = UnionFind::merge(x, y);
        if(res){
            if(root(x) == y) std::swap(x, y); // マージ後の連結成分の根が x となるよう調整
            f(sum_[x], std::move(sum_[y]));
        }
        return res;
    }

    const T& sum(int x){
        return sum_[root(x)];
    }
};

#endif // UF_ComponentSum_HPP