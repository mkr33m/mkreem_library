#ifndef RerootingDP_HPP
#define RerootingDP_HPP

#include <cassert>
#include <vector>

template <class Tree, class T, class Merge, class AddEdge, class AddRoot>
struct RerootingDP {
    Tree& G;
    Merge merge;
    AddEdge add_edge;
    AddRoot add_vertex;
    T id;

    int N;
    std::vector<T> bottom_up_dp;
    std::vector<T> ans;
    RerootingDP(Tree& G, Merge merge, AddEdge add_edge, AddRoot add_vertex, T id)
        : G(G), merge(merge), add_edge(add_edge), add_vertex(add_vertex), id(id), N(G.size()), bottom_up_dp(N, id), ans(N, id) {
            calc_bottom_up(0, -1);
            calc_top_down(0, -1, id);
        }

    T get(int v) {
        assert(0 <= v && v < N);
        return ans[v];
    }

private:
    // ふつうの木 dp
    void calc_bottom_up(int v, int p) {
        T acc = id;
        for (const auto& e : G[v]) {
            int nv = e.to;
            if (nv == p) {
                continue;
            }
            calc_bottom_up(nv, v);
            acc = merge(acc, add_edge(bottom_up_dp[nv], e));
        }
        bottom_up_dp[v] = add_vertex(acc, v);
    }

    void calc_top_down(int v, int p, const T& from_par) {
        int deg = (int)G[v].size();

        // vals[i] := G[v][i] 方向から v に入ってくる寄与
        std::vector<T> vals(deg, id);
        for (int i = 0; i < deg; i++) {
            const auto& e = G[v][i];
            int nv = e.to;
            if (nv == p) {
                vals[i] = from_par;
            } else {
                vals[i] = add_edge(bottom_up_dp[nv], e);
            }
        }

        std::vector<T> pref(deg + 1, id), suff(deg + 1, id);
        for (int i = 0; i < deg; i++) {
            pref[i + 1] = merge(pref[i], vals[i]);
        }
        for (int i = deg - 1; i >= 0; i--) {
            suff[i] = merge(vals[i], suff[i + 1]);
        }

        ans[v] = add_vertex(pref[deg], v);

        for (int i = 0; i < deg; i++) {
            const auto& e = G[v][i];
            int nv = e.to;
            if (nv == p) {
                continue;
            }
            /**
             * to にとっての from_par を構成
             */
            T without_i = merge(pref[i], suff[i + 1]);
            T pass_to_child = add_edge(add_vertex(without_i, v), e);
            calc_top_down(nv, v, pass_to_child);
        }
    }

};


#endif // RerootingDP_HPP