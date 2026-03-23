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
    Graph(int N) : N(N), M(0), G(N) {}

private:
    int N, M;
    std::vector<std::vector<Edge>> G;

public:
    bool is_weighted = false;
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
    int size() const { return N; }
    const std::vector<Edge>& operator[](int v) const { return G[v]; }
    std::vector<Edge>& operator[](int v) { return G[v]; }
    std::vector<Edge> edges() {
        std::vector<Edge> es(M);
        for (int v = 0; v < N; v++) {
            for (const auto& nv : G[v]) {
                es[nv.id] = nv;
            }
        }
        return es;
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
};

#endif // Graph_template_HPP