#ifndef UnionFind_HPP
#define UnionFind_HPP

/*
verify
・https://judge.yosupo.jp/problem/unionfind
*/

#include <vector>
#include <algorithm>
#include <numeric>

struct UnionFind {
private:
    int N;
    std::vector<int> parent;
    std::vector<int> size_;

public:
    UnionFind() = default;
    UnionFind(int N) : N(N), parent(N), size_(N, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v){
        static std::vector<int> tmp;
        while(parent[v] != v){ // 根まで辿っていく
            tmp.push_back(v);
            v = parent[v];
        }
        while(!tmp.empty()){ // 経路圧縮
            parent[tmp.back()] = v;
            tmp.pop_back();
        }
        return v;
    }

    bool same(int u, int v){
        return root(u) == root(v);
    }

    bool merge(int u, int v){
        int root_u = root(u), root_v = root(v);

        if(root_u == root_v){
            return false; // 根が同じなら、既に同じ集合
        }

        if(size_[root_u] < size_[root_v]){
            std::swap(root_u, root_v); // マージテク
        }
        size_[root_u] += size_[root_v];
        parent[root_v] = root_u;
        return true;
    }

    int size(int v){
        return size_[root(v)];
    }

    std::vector<std::vector<int>> groups(){
        std::vector<std::vector<int>> res(N);
        for(int i = 0; i < N; i++){
            res[root(i)].push_back(i);
        }
        res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>& vec){ return vec.empty(); }), res.end());
        return res;
    }
};

#endif // UnionFind_HPP