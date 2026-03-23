#ifndef EulerTour_Monoid_HPP
#define EulerTour_Monoid_HPP

#include <vector>
#include "./Tree.hpp"
#include "../DataStructure/Segtree.hpp"

/**
 * @brief モノイドに対応したオイラーツアー
 */
template <typename S, S (*op)(S, S), S (*e)()>
struct EulerTour_Monoid {
private:
    int N; // 頂点数
    std::vector<int> in, out, ord;
    std::vector<int> edge_to_vertex;
    Segtree<S, op, e> seg_vertex, seg_edge;
    const Tree<S>& T;

public:
    EulerTour_Monoid(const Tree<S>& T) : N(T.size()), in(N, -1), out(N, -1), edge_to_vertex(N - 1, -1), seg_vertex(N), seg_edge(N), T(T) {
        ord.reserve(N);
        auto dfs = [&](auto dfs, int v, int p = -1, S prev_edge_cost = e()) -> void {
            in[v] = (int)ord.size(); // in
            ord.push_back(v);
            if (p != -1) {
                seg_edge.set(in[v], prev_edge_cost);
            }
            for (const auto& ed : T[v]) {
                if (ed.to == p) {
                    continue;
                }
                edge_to_vertex[ed.id] = ed.to;
                dfs(dfs, ed.to, v, ed.cost);
            }
            out[v] = (int)ord.size(); // out
        }; dfs(dfs, T.get_root());
    }

    /**
     * @brief 頂点 v の値を設定
     */
    void set_vertex(int v, S val) {
        seg_vertex.set(in[v], val);
    }
    void add_vertex(int v, S val) {
        seg_vertex.add(in[v], val);
    }
    S get_vertex(int v) {
        return seg_vertex.get(in[v]);
    }
    /**
     * @brief 辺 i の値を設定
     */
    void set_edge(int i, S val) {
        int v = edge_to_vertex[i];
        seg_edge.set(in[v], val);
    }
    void add_edge(int i, S val) {
        int v = edge_to_vertex[i];
        seg_edge.add(in[v], val);
    }
    S get_edge(int i) {
        int v = edge_to_vertex[i];
        return seg_edge.get(in[v]);
    }
    /**
     * @brief 部分木 v 内の頂点の総積を取得
     */
    S prod_vertex(int v) {
        return seg_vertex.prod(in[v], out[v]);
    }
    /**
     * @brief 部分木 v 内の辺の総積を取得
     */
    S prod_edge(int v) {
        return seg_edge.prod(in[v] + 1, out[v]);
    }
};

#endif // EulerTour_Monoid