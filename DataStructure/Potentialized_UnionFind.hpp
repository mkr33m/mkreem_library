#ifndef Potentialized_UnionFind_HPP
#define Potentialized_UnionFind_HPP

/// aaaaa

/*
verify
https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
*/

#include <vector>
#include <cassert>
#include <numeric>

template <typename Abel>
struct Potentialized_UnionFind {
private:
    using S = typename Abel::S;
    std::vector<int> parent;
    std::vector<S> potential_from_parent; // 親から見たポテンシャル
    std::vector<int> size_;

public:
    Potentialized_UnionFind(int N) : parent(N), potential_from_parent(N, Abel::e()), size_(N, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v){
        static std::vector<int> tmp;
        while(parent[v] != v){ // 根まで辿っていく
            tmp.push_back(v);
            v = parent[v];
        }
        int par = v;
        while(!tmp.empty()){
            int pos = tmp.back(); tmp.pop_back();
            parent[pos] = v; // 経路圧縮
            potential_from_parent[pos] = Abel::op(potential_from_parent[pos], potential_from_parent[par]);
            par = pos;
        }
        return v;
    }

    bool same(int u, int v){
        return root(u) == root(v);
    }

    /**
     * @brief root_u から見た u のポテンシャルを返す
     */
    S weight(int u){
        root(u);
        return potential_from_parent[u];
    }

    /**
     * @param delta v から見た u のポテンシャル
     */
    bool merge(int u, int v, S delta){
        int root_u = root(u), root_v = root(v);
        // root_v から見た root_u のポテンシャルに変換
        /*
        v から見た u のポテンシャル -> w
        v から見た root_u のポテンシャル -> w -（root_u から見た u のポテンシャル）
        root_u から見た v のポテンシャル -> w +（root_v から見た v のポテンシャル）
        */
        delta = Abel::op(delta, weight(v));
        delta = Abel::op(delta, Abel::inv(weight(u)));

        if(root_u == root_v){
            return false;
        }

        if(size_[root_u] > size_[root_v]){
            std::swap(root_u, root_v); // マージテク
            delta = Abel::inv(delta);
            //delta = -delta;
        }
        size_[root_v] += size_[root_u];
        parent[root_u] = root_v;
        potential_from_parent[root_u] = delta;
        return true;
    }

    /**
     * @brief v から見た u のポテンシャルを返す
     */
    S weight(int u, int v){
        assert(same(u, v));
        return Abel::op(weight(u), Abel::inv(weight(v)));
    }

    int size(int v){
        return size_[v];
    }
};

#endif // Potentialized_UnionFind_HPP