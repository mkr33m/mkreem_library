#ifndef LCA_HPP
#define LCA_HPP

#include <algorithm>
#include <cassert>
#include <vector>
#include "./Tree.hpp"

template <typename T>
struct LCA {
private:
    const Tree<T>& tree;
    int N, LOG;
    std::vector<std::vector<int>> par;

public:
    LCA(const Tree<T>& tree) : tree(tree), N(tree.size()) {
        LOG = 1;
        while ((1 << LOG) <= N) {
            LOG++;
        }
        par.assign(LOG, std::vector<int>(N, -1));
        for (int v = 0; v < N; v++) {
            par[0][v] = tree.get_parent(v);
        }
        for (int i = 1; i < LOG; i++) {
            for (int v = 0; v < N; v++) {
                if (par[i - 1][v] == -1) {
                    par[i][v] = -1;
                } else {
                    par[i][v] = par[i - 1][par[i - 1][v]];
                }
            }
        }
    }

    int lca(int u, int v) {
        if (tree.get_depth(u) < tree.get_depth(v)) {
            std::swap(u, v);
        }
        int diff = tree.get_depth(u) - tree.get_depth(v);
        for (int i = 0; i < LOG; i++) { // u を持ち上げる
            if ((diff >> i) & 1) {
                u = par[i][u];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
    /**
     * @brief u, v 間の距離を返す
     */
    int get_dist(int u, int v) {
        return tree.get_depth(u) + tree.get_depth(v) - 2 * tree.get_depth(lca(u, v));
    }
    /**
     * @brief u, v 間の重み付き距離を返す
     */
    T get_weighted_dist(int u, int v) {
        return tree.get_weighted_depth(u) + tree.get_weighted_depth(v) - 2 * tree.get_weighted_depth(lca(u, v));
    }
    /**
     * @brief u, v 間に p があるかを判定する
     */
    bool is_on_path(int u, int v, int p) {
        return get_dist(u, p) + get_dist(p, v) == get_dist(u, v);
    }
    /**
     * @brief v の k 個上の祖先を返す
     */
    int kth_ancestor(int v, int k) {
        for (int i = 0; i < LOG; i++) {
            if (v == -1) {
                break;
            }
            if ((k >> i) & 1) {
                v = par[i][v];
            }
        }
        return v;
    }
    /**
     * @brief u が v の祖先かを判定する
     */
    bool is_ancestor(int u, int v) {
        return lca(u, v) == u;
    }
    /**
     * @brief u から v への単純パス上で、u から k 個進んだ頂点を返す
     * @remark k>dist(u,v) なら -1 を返す
     */
    int jump(int u, int v, int k) {
        assert(k >= 0);
        int w = lca(u, v);
        int du = tree.get_depth(u) - tree.get_depth(w);
        int dv = tree.get_depth(v) - tree.get_depth(w);
        int dist = du + dv;
        assert(k <= dist);
        if (k <= du) {
            return kth_ancestor(u, k);
        }
        return kth_ancestor(v, dist - k);
    }
};

#endif // LCA_HPP