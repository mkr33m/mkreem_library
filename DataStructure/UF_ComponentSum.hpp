#ifndef UF_ComponentSum_HPP
#define UF_ComponentSum_HPP

#include <vector>
#include <cassert>

#include "UnionFind.hpp"

template <typename Op>
class UF_ComponentSum : public UnionFind { // 継承
    int N; // 頂点数
    Op op;

public:
                                                             // UF を初期化
    UF_ComponentSum(int N, const Op& op) : N(N), op(op), UnionFind(N) {}

    bool merge(int u, int v) { // 上書き
        int ru = root(u), rv = root(v);
        int r = UnionFind::merge(u, v);
        bool merged = (r != ru) || (r != rv);
        if (merged) {
            if (r == ru) {
                op(r, rv);
            } else { // r == pv
                op(r, ru);
            }
        }
        return merged;
    }
};

#endif // UF_ComponentSum_HPP