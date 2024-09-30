#ifndef Potentialized_UnionFind_HPP
#define Potentialized_UnionFind_HPP

/*
verify
https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
*/

#include <vector>
#include <cassert>

template <typename Abel>
struct Potentialized_UnionFind {
private:
    using S = typename Abel::S;
    std::vector<int> parent;
    std::vector<Abel> potential_from_parent; // 親から見たポテンシャル
    std::vector<int> size;

public:
    Potentialized_UnionFind(int N) : parent(N), potential_from_parent(N, Abel::e()), size(N, 1) {
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
    }

    int root(int v){
        if(parent[v] == v){
            return v;
        }
        static std::vector<int> tmp;
        while(parent[v] != v){ // 根まで辿っていく
            tmp.push_back(v);
            potential_from_parent[v] = Abel::op(potential_from_parent[v], potential_from_parent[parent[v]]);
            v = parent[v];
        }
        while(!tmp.empty()){ // 経路圧縮
            parent[tmp.back()] = v;
            tmp.pop_back();
        }
        return v;
    }

    /**
     * @param delta v から見た u のポテンシャル
     */
    bool merge(int u, int v, const S& delta){
        int root_u = root(u), root_v = root(v);

        if(root_u == root_v){
            return false;
        }

        if(size[root_u] < size[root_v]){
            std::swap(root_u, root_v); // マージテク
        }
        parent[root_v] = root_u;
        /**
         * @param new_weight 
         */
        /*
        重み u - 重み v == delta
        重み u - 重み ru == pfp u
        重み v - 重み rv == pfp v
        すなわち、
        new_weight = 重み u - 重み v + delta
        */
        S new_weight = Abel::op(potential_from_parent[u], Abel::inverse(potential_from_parent[v]));
        new_weight = Abel::op(new_weight, delta);
        size[root_u] += size[root_v];
        return true;
    }

    bool same(int u, int v){
        return root(u) == root(v);
    }

    /**
     * @brief root_u から見た u のポテンシャルを返す
     */
    S weight_to_root(int u){
        root(u);
        return potential_from_parent[u];
    }

    /**
     * @brief v から見た u のポテンシャルを返す
     */
    S weight_between(int u, int v){
        assert(same(u, v));
        return Abel::op(potential_from_parent(u), Abel::inv(potential_from_parent[v]));
    }
};

#endif // Potentialized_UnionFind_HPP