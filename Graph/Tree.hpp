#ifndef Tree_HPP
#define Tree_HPP

#include <algorithm>
#include <limits>
#include <vector>
#include "./Graph.hpp"

template <typename T = int>
struct Tree : Graph<T> {
private:
    using Graph<T>::Dijkstra;
    using Graph<T>::BFS;
    using Edge = typename Graph<T>::Edge;
    int root;
    int N;
    std::vector<int> parent, depth, siz;
    std::vector<T> weighted_depth;
    bool done_build;

public:
    Tree(int N, int root = 0) : Graph<T>(N), root(root), N(N), parent(N, -1), depth(N, -1), siz(N, 0), weighted_depth(N, T(0)), done_build(false) {}
    void read(bool weighted = false, bool directed = false, int padding = 1) {
        Graph<T>::read(N - 1, weighted, directed, padding);
        if (!done_build) {
            build();
            done_build = true;
        }
    }
    int get_root() const { return root; }
    int get_parent(int v) const { return parent[v]; }
    int get_depth(int v) const { return depth[v]; }
    int get_size(int v) const { return siz[v]; }
    T get_weighted_depth(int v) const { return weighted_depth[v]; }
    int size() const { return N; }

    void build() {
        if (done_build) {
            return;
        }
        done_build = true;
        auto dfs = [&](auto dfs, int v, int p, int d, T wd) -> void {
            parent[v] = p;
            depth[v] = d;
            weighted_depth[v] = wd;
            int cnt = 0;
            for (const auto& e : (*this)[v]) {
                if (e.to == p) {
                    continue;
                }
                dfs(dfs, e.to, v, d + 1, wd + e.cost);
                cnt += siz[e.to];
            }
            cnt++;
            siz[v] = cnt;
        };
        dfs(dfs, root, -1, 0, T(0));
    }

    // 木の直径 ===========================================
    std::vector<int> get_tree_diameter(int x = 0) {
        std::vector<T> dist;
        std::vector<Edge> prev_edges(N);
        if (this->is_weighted) {
            std::tie(dist, prev_edges) = Dijkstra(x);
        } else {
            std::tie(dist, prev_edges) = BFS(x);
        }
        auto get_farthest_vertex = [this](std::vector<T>& dist) {
            T max_dist = std::numeric_limits<T>::lowest();
            int to = -1;
            for (int v = 0; v < this->N; v++) {
                if (max_dist < dist[v]) {
                    max_dist = dist[v];
                    to = v;
                }
            }
            return to;
        };
        int y = get_farthest_vertex(dist);
        if (this->is_weighted) {
            std::tie(dist, prev_edges) = Dijkstra(y);
        } else {
            std::tie(dist, prev_edges) = BFS(y);
        }
        int z = get_farthest_vertex(dist);
        std::vector<int> path;
        int v = z;
        while (1) {
            path.push_back(v);
            if (v == y) {
                break;
            }
            v = prev_edges[v].from;
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
};



#endif // Tree_HPP