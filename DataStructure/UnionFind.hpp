#ifndef UnionFind_HPP
#define UnionFind_HPP

/*
verify
・https://judge.yosupo.jp/problem/unionfind
*/

#include <vector>
#include <algorithm>
#include <numeric>

class UnionFind {
private:
    int N_;
    std::vector<int> parent_;
    std::vector<int> size_;

public:
    UnionFind() = default;
    UnionFind(int N) : N_(N), parent_(N), size_(N, 1) {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    int root(int v) {
        static std::vector<int> tmp;
        while (parent_[v] != v) { // 根まで辿っていく
            tmp.push_back(v);
            v = parent_[v];
        }
        while (!tmp.empty()) { // 経路圧縮
            parent_[tmp.back()] = v;
            tmp.pop_back();
        }
        return v;
    }

    bool same(int u, int v) {
        return root(u) == root(v);
    }

    int merge(int u, int v) {
        int root_u = root(u), root_v = root(v);

        if (root_u == root_v) {
            return root_u; // 根が同じなら、既に同じ集合
        }

        if (size_[root_u] < size_[root_v]) {
            std::swap(root_u, root_v);
        }
        size_[root_u] += size_[root_v];
        parent_[root_v] = root_u;
        return root_u;
    }

    int size(int v) {
        return size_[root(v)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(N_);
        for (int i = 0; i < N_; i++) {
            res[root(i)].push_back(i);
        }
        res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>& vec){ return vec.empty(); }), res.end());
        return res;
    }
};

#endif // UnionFind_HPP