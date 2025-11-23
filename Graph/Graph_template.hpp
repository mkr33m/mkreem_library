#ifndef Graph_template_HPP
#define Graph_template_HPP

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <limits>

template <typename T = int>
struct Graph {
    // 辺の構造体
    struct Edge {
        int from, to;
        T cost;
        int id;

        Edge() : from(-1), to(-1), cost(-1), id(-1) {}
        Edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}

        bool operator<(const Edge &rhs) const { return cost < rhs.cost; }
        friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
            return os << "(" << e.from << " -> " << e.to << "  weight: " << e.cost << ", id: " << e.id << ")";
        }
    };

    Graph() = default;
    Graph(int N) : N(N), M(0), G(N), color(N, -1) {}

private:
    int N, M;
    std::vector<std::vector<Edge>> G;
    bool is_weighted = false;
    std::vector<int> color; // for is_bipartite
    bool precalc_done = false; // for LCA
    std::vector<std::vector<int>> parent; // for LCA -> precalc_for_LCA 関数で初期化
    std::vector<int> dist; // for LCA -> precalc_for_LCA 関数で初期化

    // LCA ===========================================
    /**
     * @brief LCA（最近共通祖先）を求めるための前処理
     * @param parent[i][v] := 頂点 v の、2^i先の祖先。存在しなければ-1。
     */
    void precalc_for_LCA(const int& root = 0) {
        int K = 1;
        while ((1 << K) < N) {
            K++;
        }
        parent.assign(K, std::vector<int>(N, -1));
        dist.assign(N, -1);
        dfs_for_LCA(root);
        for (int i = 1; i < K; i++) {
            for (int v = 0; v < N; v++) {
                auto& f = parent[i - 1];
                parent[i][v] = f[f[v]];
            }
        }
    }

    /**
     * @brief 根からの距離、親頂点、を求める
     * @param dist 根からの距離
     */
    void dfs_for_LCA(int v, int par = -1, int d = 0) {
        parent[0][v] = par;
        dist[v] = d;
        for (const auto& e : G[v]) {
            int nv = e.to;
            if (nv != par) {
                dfs_for_LCA(nv, v, d + 1);
            }
        }
    }

public:
    void add_edge(const int& u, const int& v, T w = 1) {
        G[u].push_back({u, v, w, M});
        G[v].push_back({v, u, w, M++});
        if (w != 1) {
            is_weighted = true;
        }
    }
    void add_directed_edge(const int& u, const int& v, T w = 1) {
        G[u].push_back({u, v, w, M++});
        if (w != 1) {
            is_weighted = true;
        }
    }

    void read(const int& M, bool weighted = false, bool directed = false, int padding = 1) {
        for (int i = 0; i < M; i++) {
            int u, v; std::cin >> u >> v;
            u -= padding;
            v -= padding;
            T w(1);
            if (weighted) {
                is_weighted = true;
                std::cin >> w;
            }
            if (directed) {
                add_directed_edge(u, v, w);
            } else {
                add_edge(u, v, w);
            }
        }
    }

    std::vector<Edge>& operator[](const int& v) {
        return G[v];
    }

    std::vector<Edge> edges() {
        std::vector<Edge> es(M);
        for (int v = 0; v < N; v++) {
            for (const auto& nv : G[v]) {
                es[nv.id] = nv;
            }
        }
        return es;
    }

    // is_bipartite 関数 ===========================================
    /**
     * @brief グラフgが二部グラフかどうかを判定する
     */
    bool is_bipartite(int v, int v_color = 0) {
        color[v] = v_color;
        for (const auto& e : G[v]) {
            int nv = e.to;
            if (color[nv] != -1) { // 隣接頂点の色がすでに確定している
                if (color[nv] == v_color) {
                    return false;
                }
                continue;
            }

            if (!is_bipartite(nv, 1 - v_color)) {
                return false;
            }
        }

        return true;
    }

    // 木の直径 ===========================================
    std::vector<int> get_tree_diameter(int x = 0) {

        std::vector<T> dist;
        std::vector<Edge> prev_edges(N);
        if (is_weighted) {
            std::tie(dist, prev_edges) = Dijkstra(x);
        } else {
            std::tie(dist, prev_edges) = BFS(x);
        }
        auto get_farthest_vertex = [this](std::vector<T>& dist, int from) {
            T max_dist = std::numeric_limits<T>::min();
            int to = -1;
            for (int v = 0; v < this->N; v++) {
                if (max_dist < dist[v]) {
                    max_dist = dist[v];
                    to = v;
                }
            }
            return to;
        };
        int y = get_farthest_vertex(dist, x);
        if (is_weighted) {
            std::tie(dist, prev_edges) = Dijkstra(y);
        } else {
            std::tie(dist, prev_edges) = BFS(y);
        }
        int z = get_farthest_vertex(dist, y);

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

    // 最短距離 ===========================================
    std::pair<std::vector<T>, std::vector<Edge>> BFS(const int& start) {
        std::vector<T> dist(N, std::numeric_limits<T>::max());
        std::queue<int> q;
        /**
         * @param prev_edges[target] : start から target までの最短経路における、target を訪れる直前に通った辺
         */
        std::vector<Edge> prev_edges(N);
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (const auto& e : G[v]) {
                int nv = e.to;
                if(dist[nv] != std::numeric_limits<T>::max()) {
                    continue;
                }
                dist[nv] = dist[v] + 1;
                prev_edges[nv] = e;
                q.push(nv);
            }
        }

        return make_pair(dist, prev_edges);
    }

    std::pair<std::vector<T>, std::vector<Edge>> BFS01(const int& start) {
        std::vector<T> dist(N, std::numeric_limits<T>::max());
        std::deque<int> q;
        /**
         * @param prev_edges[target] : start から target までの最短経路における、targetを訪れる直前に通った辺
         */
        std::vector<Edge> prev_edges(N);
        dist[start] = 0;
        q.push_front(start);

        while (!q.empty()) {
            int v = q.front(); q.pop_front();
            for (const auto& e : G[v]) {
                int nv = e.to;
                if (dist[nv] <= dist[v] + e.cost) {
                    continue;
                }
                dist[nv] = dist[v] + e.cost;
                prev_edges[nv] = e;
                if (e.cost == 0) {
                    q.push_front(nv);
                } else {
                    q.push_back(nv);
                }
            }
        }

        return make_pair(dist, prev_edges);
    }

    std::pair<std::vector<T>, std::vector<Edge>> Dijkstra(int start) {
        std::vector<T> dist(N, std::numeric_limits<T>::max());
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> q;
        /**
         * @param prev_edges[target] : start から target までの最短経路における、targetを訪れる直前に通った辺
         */
        std::vector<Edge> prev_edges(N);
        dist[start] = 0;
        q.push({dist[start], start});

        while (!q.empty()) {
            auto [dist_v, v] = q.top(); q.pop();
            if (dist_v > dist[v]) {
                continue;
            }
            for (const auto& e : G[v]) {
                int nv = e.to;
                if(dist[nv] <= dist[v] + e.cost) {
                    continue;
                }
                dist[nv] = dist[v] + e.cost;
                prev_edges[nv] = e;
                q.push({dist[nv], nv});
            }
        }

        return make_pair(dist, prev_edges);
    }

    /**
     * @brief 負辺を含むグラフで、単一始点の最短経路を求める
     * @return 負閉路を含む場合かどうかのフラグ、dist 配列
     * @remark 全辺のコストを -1 倍すると、最長経路を求める
     */
    std::pair<std::vector<T>, bool> bellman_ford(int start) {
        const T INF_ = std::numeric_limits<T>::max();
        std::vector<T> dist(N, INF_);
        dist[start] = 0;
        int cnt = 0;
        std::vector<Graph::Edge> es = edges();

        /**
         * 全ての辺を走査して緩和を行う
         * https://qiita.com/muumu/items/bae1575c3161ced28587
         * 各 while ループで、
         * 長さ 1 の最短路が決定 -> 長さ 2 の最短路が決定 -> ...
         * みたいな感じ？
         */
        while (cnt < N) {
            bool end = true;
            for (const auto& e : es) {
                if (dist[e.from] != INF_ and dist[e.from] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.cost;
                    end = false;
                }
            }
            if (end) {
                break;
            }
            cnt++;
        }

        return make_pair(dist, (cnt == N));
    }

    std::vector<Edge> path(const int& start, const int& target, const std::vector<Edge>& prev_edges) {
        std::vector<Edge> path;
        for (int cur = target; cur != start; cur = prev_edges[cur].from) {
            if (prev_edges[cur].id == -1) {
                return {};
            }
            path.push_back(prev_edges[cur]);
        }
        std::reverse(path.begin(), path.end());

        return path;
    }

    // LCA ===========================================
    /**
     * @brief u と v の LCA を返す
     * @remark 計算量：O(logN)
     */
    int LCA(int u, int v, const int& root = 0) {
        if (!precalc_done) {
            precalc_for_LCA(root);
            precalc_done = true;
        }

        if (dist[u] < dist[v]) {
            std::swap(u, v);
        }
        int K = (int)parent.size();
        // u の方が深い場合、u を上に動かすことで、u と v の LCA までの距離を同じにする。
        int difference = dist[u] - dist[v];
        for (int i = 0; i < K; i++) {
            if ((difference >> i) & 1) {
                u = parent[i][u];
            }
        }

        if (u == v) {
            return u;
        }
        for (int i = K - 1; i >= 0; i--) {
            // u, v を、LCA の手前まで移動 -> u, v の1つ先が LCA となる。
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }

    /**
     * @brief 木上の2頂点 u, v の距離を、LCA を利用して求める。
     */
    int get_dist(int u, int v, const int& root = 0) {
        if (!precalc_done) {
            precalc_for_LCA(root);
            precalc_done = true;
        }
        return dist[u] + dist[v] - 2 * dist[LCA(u, v)];
    }

    /**
     * @brief 木上の2頂点 u, v のパス上に、頂点 p があるかどうかを判定する。
     */
    bool is_on_path (int u, int v, int p, const int& root = 0) {
        return get_dist(u, p) + get_dist(p, v) == get_dist(u, v);
    }
};

#endif // Graph_template_HPP