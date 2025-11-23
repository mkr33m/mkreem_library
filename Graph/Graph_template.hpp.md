---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "LCA\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09\u3092\u6C42\
      \u3081\u308B\u305F\u3081\u306E\u524D\u51E6\u7406"
    links:
    - https://qiita.com/muumu/items/bae1575c3161ced28587
  bundledCode: "#line 1 \"Graph/Graph_template.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <queue>\n#include <iostream>\n#include <limits>\n\ntemplate\
    \ <typename T = int>\nstruct Graph {\n    // \u8FBA\u306E\u69CB\u9020\u4F53\n\
    \    struct Edge {\n        int from, to;\n        T cost;\n        int id;\n\n\
    \        Edge() : from(-1), to(-1), cost(-1), id(-1) {}\n        Edge(int from,\
    \ int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\
    \n        bool operator<(const Edge &rhs) const { return cost < rhs.cost; }\n\
    \        friend std::ostream& operator<<(std::ostream& os, const Edge& e) {\n\
    \            return os << \"(\" << e.from << \" -> \" << e.to << \"  weight: \"\
    \ << e.cost << \", id: \" << e.id << \")\";\n        }\n    };\n\n    Graph()\
    \ = default;\n    Graph(int N) : N(N), M(0), G(N), color(N, -1) {}\n\nprivate:\n\
    \    int N, M;\n    std::vector<std::vector<Edge>> G;\n    bool is_weighted =\
    \ false;\n    std::vector<int> color; // for is_bipartite\n    bool precalc_done\
    \ = false; // for LCA\n    std::vector<std::vector<int>> parent; // for LCA ->\
    \ precalc_for_LCA \u95A2\u6570\u3067\u521D\u671F\u5316\n    std::vector<int> dist;\
    \ // for LCA -> precalc_for_LCA \u95A2\u6570\u3067\u521D\u671F\u5316\n\n    //\
    \ LCA ===========================================\n    /**\n     * @brief LCA\uFF08\
    \u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09\u3092\u6C42\u3081\u308B\u305F\u3081\
    \u306E\u524D\u51E6\u7406\n     * @param parent[i][v] := \u9802\u70B9 v \u306E\u3001\
    2^i\u5148\u306E\u7956\u5148\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\u3002\
    \n     */\n    void precalc_for_LCA(const int& root = 0) {\n        int K = 1;\n\
    \        while ((1 << K) < N) {\n            K++;\n        }\n        parent.assign(K,\
    \ std::vector<int>(N, -1));\n        dist.assign(N, -1);\n        dfs_for_LCA(root);\n\
    \        for (int i = 1; i < K; i++) {\n            for (int v = 0; v < N; v++)\
    \ {\n                auto& f = parent[i - 1];\n                parent[i][v] =\
    \ f[f[v]];\n            }\n        }\n    }\n\n    /**\n     * @brief \u6839\u304B\
    \u3089\u306E\u8DDD\u96E2\u3001\u89AA\u9802\u70B9\u3001\u3092\u6C42\u3081\u308B\
    \n     * @param dist \u6839\u304B\u3089\u306E\u8DDD\u96E2\n     */\n    void dfs_for_LCA(int\
    \ v, int par = -1, int d = 0) {\n        parent[0][v] = par;\n        dist[v]\
    \ = d;\n        for (const auto& e : G[v]) {\n            int nv = e.to;\n   \
    \         if (nv != par) {\n                dfs_for_LCA(nv, v, d + 1);\n     \
    \       }\n        }\n    }\n\npublic:\n    void add_edge(const int& u, const\
    \ int& v, T w = 1) {\n        G[u].push_back({u, v, w, M});\n        G[v].push_back({v,\
    \ u, w, M++});\n        if (w != 1) {\n            is_weighted = true;\n     \
    \   }\n    }\n    void add_directed_edge(const int& u, const int& v, T w = 1)\
    \ {\n        G[u].push_back({u, v, w, M++});\n        if (w != 1) {\n        \
    \    is_weighted = true;\n        }\n    }\n\n    void read(const int& M, bool\
    \ weighted = false, bool directed = false, int padding = 1) {\n        for (int\
    \ i = 0; i < M; i++) {\n            int u, v; std::cin >> u >> v;\n          \
    \  u -= padding;\n            v -= padding;\n            T w(1);\n           \
    \ if (weighted) {\n                is_weighted = true;\n                std::cin\
    \ >> w;\n            }\n            if (directed) {\n                add_directed_edge(u,\
    \ v, w);\n            } else {\n                add_edge(u, v, w);\n         \
    \   }\n        }\n    }\n\n    std::vector<Edge>& operator[](const int& v) {\n\
    \        return G[v];\n    }\n\n    std::vector<Edge> edges() {\n        std::vector<Edge>\
    \ es(M);\n        for (int v = 0; v < N; v++) {\n            for (const auto&\
    \ nv : G[v]) {\n                es[nv.id] = nv;\n            }\n        }\n  \
    \      return es;\n    }\n\n    // is_bipartite \u95A2\u6570 ===========================================\n\
    \    /**\n     * @brief \u30B0\u30E9\u30D5g\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n     */\n    bool is_bipartite(int\
    \ v, int v_color = 0) {\n        color[v] = v_color;\n        for (const auto&\
    \ e : G[v]) {\n            int nv = e.to;\n            if (color[nv] != -1) {\
    \ // \u96A3\u63A5\u9802\u70B9\u306E\u8272\u304C\u3059\u3067\u306B\u78BA\u5B9A\u3057\
    \u3066\u3044\u308B\n                if (color[nv] == v_color) {\n            \
    \        return false;\n                }\n                continue;\n       \
    \     }\n\n            if (!is_bipartite(nv, 1 - v_color)) {\n               \
    \ return false;\n            }\n        }\n\n        return true;\n    }\n\n \
    \   // \u6728\u306E\u76F4\u5F84 ===========================================\n\
    \    std::vector<int> get_tree_diameter(int x = 0) {\n\n        std::vector<T>\
    \ dist;\n        std::vector<Edge> prev_edges(N);\n        if (is_weighted) {\n\
    \            std::tie(dist, prev_edges) = Dijkstra(x);\n        } else {\n   \
    \         std::tie(dist, prev_edges) = BFS(x);\n        }\n        auto get_farthest_vertex\
    \ = [this](std::vector<T>& dist, int from) {\n            T max_dist = std::numeric_limits<T>::min();\n\
    \            int to = -1;\n            for (int v = 0; v < this->N; v++) {\n \
    \               if (max_dist < dist[v]) {\n                    max_dist = dist[v];\n\
    \                    to = v;\n                }\n            }\n            return\
    \ to;\n        };\n        int y = get_farthest_vertex(dist, x);\n        if (is_weighted)\
    \ {\n            std::tie(dist, prev_edges) = Dijkstra(y);\n        } else {\n\
    \            std::tie(dist, prev_edges) = BFS(y);\n        }\n        int z =\
    \ get_farthest_vertex(dist, y);\n\n        std::vector<int> path;\n        int\
    \ v = z;\n        while (1) {\n            path.push_back(v);\n            if\
    \ (v == y) {\n                break;\n            }\n            v = prev_edges[v].from;\n\
    \        }\n\n        std::reverse(path.begin(), path.end());\n\n        return\
    \ path;\n    }\n\n    // \u6700\u77ED\u8DDD\u96E2 ===========================================\n\
    \    std::pair<std::vector<T>, std::vector<Edge>> BFS(const int& start) {\n  \
    \      std::vector<T> dist(N, std::numeric_limits<T>::max());\n        std::queue<int>\
    \ q;\n        /**\n         * @param prev_edges[target] : start \u304B\u3089 target\
    \ \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u306B\u304A\u3051\u308B\u3001target\
    \ \u3092\u8A2A\u308C\u308B\u76F4\u524D\u306B\u901A\u3063\u305F\u8FBA\n       \
    \  */\n        std::vector<Edge> prev_edges(N);\n        dist[start] = 0;\n  \
    \      q.push(start);\n\n        while (!q.empty()) {\n            int v = q.front();\
    \ q.pop();\n            for (const auto& e : G[v]) {\n                int nv =\
    \ e.to;\n                if(dist[nv] != std::numeric_limits<T>::max()) {\n   \
    \                 continue;\n                }\n                dist[nv] = dist[v]\
    \ + 1;\n                prev_edges[nv] = e;\n                q.push(nv);\n   \
    \         }\n        }\n\n        return make_pair(dist, prev_edges);\n    }\n\
    \n    std::pair<std::vector<T>, std::vector<Edge>> BFS01(const int& start) {\n\
    \        std::vector<T> dist(N, std::numeric_limits<T>::max());\n        std::deque<int>\
    \ q;\n        /**\n         * @param prev_edges[target] : start \u304B\u3089 target\
    \ \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u306B\u304A\u3051\u308B\u3001target\u3092\
    \u8A2A\u308C\u308B\u76F4\u524D\u306B\u901A\u3063\u305F\u8FBA\n         */\n  \
    \      std::vector<Edge> prev_edges(N);\n        dist[start] = 0;\n        q.push_front(start);\n\
    \n        while (!q.empty()) {\n            int v = q.front(); q.pop_front();\n\
    \            for (const auto& e : G[v]) {\n                int nv = e.to;\n  \
    \              if (dist[nv] <= dist[v] + e.cost) {\n                    continue;\n\
    \                }\n                dist[nv] = dist[v] + e.cost;\n           \
    \     prev_edges[nv] = e;\n                if (e.cost == 0) {\n              \
    \      q.push_front(nv);\n                } else {\n                    q.push_back(nv);\n\
    \                }\n            }\n        }\n\n        return make_pair(dist,\
    \ prev_edges);\n    }\n\n    std::pair<std::vector<T>, std::vector<Edge>> Dijkstra(int\
    \ start) {\n        std::vector<T> dist(N, std::numeric_limits<T>::max());\n \
    \       std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> q;\n        /**\n         * @param prev_edges[target]\
    \ : start \u304B\u3089 target \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u306B\
    \u304A\u3051\u308B\u3001target\u3092\u8A2A\u308C\u308B\u76F4\u524D\u306B\u901A\
    \u3063\u305F\u8FBA\n         */\n        std::vector<Edge> prev_edges(N);\n  \
    \      dist[start] = 0;\n        q.push({dist[start], start});\n\n        while\
    \ (!q.empty()) {\n            auto [dist_v, v] = q.top(); q.pop();\n         \
    \   if (dist_v > dist[v]) {\n                continue;\n            }\n      \
    \      for (const auto& e : G[v]) {\n                int nv = e.to;\n        \
    \        if(dist[nv] <= dist[v] + e.cost) {\n                    continue;\n \
    \               }\n                dist[nv] = dist[v] + e.cost;\n            \
    \    prev_edges[nv] = e;\n                q.push({dist[nv], nv});\n          \
    \  }\n        }\n\n        return make_pair(dist, prev_edges);\n    }\n\n    /**\n\
    \     * @brief \u8CA0\u8FBA\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3067\u3001\u5358\
    \u4E00\u59CB\u70B9\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\n   \
    \  * @return \u8CA0\u9589\u8DEF\u3092\u542B\u3080\u5834\u5408\u304B\u3069\u3046\
    \u304B\u306E\u30D5\u30E9\u30B0\u3001dist \u914D\u5217\n     * @remark \u5168\u8FBA\
    \u306E\u30B3\u30B9\u30C8\u3092 -1 \u500D\u3059\u308B\u3068\u3001\u6700\u9577\u7D4C\
    \u8DEF\u3092\u6C42\u3081\u308B\n     */\n    std::pair<std::vector<T>, bool> bellman_ford(int\
    \ start) {\n        const T INF_ = std::numeric_limits<T>::max();\n        std::vector<T>\
    \ dist(N, INF_);\n        dist[start] = 0;\n        int cnt = 0;\n        std::vector<Graph::Edge>\
    \ es = edges();\n\n        /**\n         * \u5168\u3066\u306E\u8FBA\u3092\u8D70\
    \u67FB\u3057\u3066\u7DE9\u548C\u3092\u884C\u3046\n         * https://qiita.com/muumu/items/bae1575c3161ced28587\n\
    \         * \u5404 while \u30EB\u30FC\u30D7\u3067\u3001\n         * \u9577\u3055\
    \ 1 \u306E\u6700\u77ED\u8DEF\u304C\u6C7A\u5B9A -> \u9577\u3055 2 \u306E\u6700\u77ED\
    \u8DEF\u304C\u6C7A\u5B9A -> ...\n         * \u307F\u305F\u3044\u306A\u611F\u3058\
    \uFF1F\n         */\n        while (cnt < N) {\n            bool end = true;\n\
    \            for (const auto& e : es) {\n                if (dist[e.from] != INF_\
    \ and dist[e.from] + e.cost < dist[e.to]) {\n                    dist[e.to] =\
    \ dist[e.from] + e.cost;\n                    end = false;\n                }\n\
    \            }\n            if (end) {\n                break;\n            }\n\
    \            cnt++;\n        }\n\n        return make_pair(dist, (cnt == N));\n\
    \    }\n\n    std::vector<Edge> path(const int& start, const int& target, const\
    \ std::vector<Edge>& prev_edges) {\n        std::vector<Edge> path;\n        for\
    \ (int cur = target; cur != start; cur = prev_edges[cur].from) {\n           \
    \ if (prev_edges[cur].id == -1) {\n                return {};\n            }\n\
    \            path.push_back(prev_edges[cur]);\n        }\n        std::reverse(path.begin(),\
    \ path.end());\n\n        return path;\n    }\n\n    // LCA ===========================================\n\
    \    /**\n     * @brief u \u3068 v \u306E LCA \u3092\u8FD4\u3059\n     * @remark\
    \ \u8A08\u7B97\u91CF\uFF1AO(logN)\n     */\n    int LCA(int u, int v, const int&\
    \ root = 0) {\n        if (!precalc_done) {\n            precalc_for_LCA(root);\n\
    \            precalc_done = true;\n        }\n\n        if (dist[u] < dist[v])\
    \ {\n            std::swap(u, v);\n        }\n        int K = (int)parent.size();\n\
    \        // u \u306E\u65B9\u304C\u6DF1\u3044\u5834\u5408\u3001u \u3092\u4E0A\u306B\
    \u52D5\u304B\u3059\u3053\u3068\u3067\u3001u \u3068 v \u306E LCA \u307E\u3067\u306E\
    \u8DDD\u96E2\u3092\u540C\u3058\u306B\u3059\u308B\u3002\n        int difference\
    \ = dist[u] - dist[v];\n        for (int i = 0; i < K; i++) {\n            if\
    \ ((difference >> i) & 1) {\n                u = parent[i][u];\n            }\n\
    \        }\n\n        if (u == v) {\n            return u;\n        }\n      \
    \  for (int i = K - 1; i >= 0; i--) {\n            // u, v \u3092\u3001LCA \u306E\
    \u624B\u524D\u307E\u3067\u79FB\u52D5 -> u, v \u306E1\u3064\u5148\u304C LCA \u3068\
    \u306A\u308B\u3002\n            if (parent[i][u] != parent[i][v]) {\n        \
    \        u = parent[i][u];\n                v = parent[i][v];\n            }\n\
    \        }\n        return parent[0][u];\n    }\n\n    /**\n     * @brief \u6728\
    \u4E0A\u306E2\u9802\u70B9 u, v \u306E\u8DDD\u96E2\u3092\u3001LCA \u3092\u5229\u7528\
    \u3057\u3066\u6C42\u3081\u308B\u3002\n     */\n    int get_dist(int u, int v,\
    \ const int& root = 0) {\n        if (!precalc_done) {\n            precalc_for_LCA(root);\n\
    \            precalc_done = true;\n        }\n        return dist[u] + dist[v]\
    \ - 2 * dist[LCA(u, v)];\n    }\n\n    /**\n     * @brief \u6728\u4E0A\u306E2\u9802\
    \u70B9 u, v \u306E\u30D1\u30B9\u4E0A\u306B\u3001\u9802\u70B9 p \u304C\u3042\u308B\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool\
    \ is_on_path (int u, int v, int p, const int& root = 0) {\n        return get_dist(u,\
    \ p) + get_dist(p, v) == get_dist(u, v);\n    }\n};\n\n\n"
  code: "#ifndef Graph_template_HPP\n#define Graph_template_HPP\n\n#include <vector>\n\
    #include <algorithm>\n#include <queue>\n#include <iostream>\n#include <limits>\n\
    \ntemplate <typename T = int>\nstruct Graph {\n    // \u8FBA\u306E\u69CB\u9020\
    \u4F53\n    struct Edge {\n        int from, to;\n        T cost;\n        int\
    \ id;\n\n        Edge() : from(-1), to(-1), cost(-1), id(-1) {}\n        Edge(int\
    \ from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id)\
    \ {}\n\n        bool operator<(const Edge &rhs) const { return cost < rhs.cost;\
    \ }\n        friend std::ostream& operator<<(std::ostream& os, const Edge& e)\
    \ {\n            return os << \"(\" << e.from << \" -> \" << e.to << \"  weight:\
    \ \" << e.cost << \", id: \" << e.id << \")\";\n        }\n    };\n\n    Graph()\
    \ = default;\n    Graph(int N) : N(N), M(0), G(N), color(N, -1) {}\n\nprivate:\n\
    \    int N, M;\n    std::vector<std::vector<Edge>> G;\n    bool is_weighted =\
    \ false;\n    std::vector<int> color; // for is_bipartite\n    bool precalc_done\
    \ = false; // for LCA\n    std::vector<std::vector<int>> parent; // for LCA ->\
    \ precalc_for_LCA \u95A2\u6570\u3067\u521D\u671F\u5316\n    std::vector<int> dist;\
    \ // for LCA -> precalc_for_LCA \u95A2\u6570\u3067\u521D\u671F\u5316\n\n    //\
    \ LCA ===========================================\n    /**\n     * @brief LCA\uFF08\
    \u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09\u3092\u6C42\u3081\u308B\u305F\u3081\
    \u306E\u524D\u51E6\u7406\n     * @param parent[i][v] := \u9802\u70B9 v \u306E\u3001\
    2^i\u5148\u306E\u7956\u5148\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\u3002\
    \n     */\n    void precalc_for_LCA(const int& root = 0) {\n        int K = 1;\n\
    \        while ((1 << K) < N) {\n            K++;\n        }\n        parent.assign(K,\
    \ std::vector<int>(N, -1));\n        dist.assign(N, -1);\n        dfs_for_LCA(root);\n\
    \        for (int i = 1; i < K; i++) {\n            for (int v = 0; v < N; v++)\
    \ {\n                auto& f = parent[i - 1];\n                parent[i][v] =\
    \ f[f[v]];\n            }\n        }\n    }\n\n    /**\n     * @brief \u6839\u304B\
    \u3089\u306E\u8DDD\u96E2\u3001\u89AA\u9802\u70B9\u3001\u3092\u6C42\u3081\u308B\
    \n     * @param dist \u6839\u304B\u3089\u306E\u8DDD\u96E2\n     */\n    void dfs_for_LCA(int\
    \ v, int par = -1, int d = 0) {\n        parent[0][v] = par;\n        dist[v]\
    \ = d;\n        for (const auto& e : G[v]) {\n            int nv = e.to;\n   \
    \         if (nv != par) {\n                dfs_for_LCA(nv, v, d + 1);\n     \
    \       }\n        }\n    }\n\npublic:\n    void add_edge(const int& u, const\
    \ int& v, T w = 1) {\n        G[u].push_back({u, v, w, M});\n        G[v].push_back({v,\
    \ u, w, M++});\n        if (w != 1) {\n            is_weighted = true;\n     \
    \   }\n    }\n    void add_directed_edge(const int& u, const int& v, T w = 1)\
    \ {\n        G[u].push_back({u, v, w, M++});\n        if (w != 1) {\n        \
    \    is_weighted = true;\n        }\n    }\n\n    void read(const int& M, bool\
    \ weighted = false, bool directed = false, int padding = 1) {\n        for (int\
    \ i = 0; i < M; i++) {\n            int u, v; std::cin >> u >> v;\n          \
    \  u -= padding;\n            v -= padding;\n            T w(1);\n           \
    \ if (weighted) {\n                is_weighted = true;\n                std::cin\
    \ >> w;\n            }\n            if (directed) {\n                add_directed_edge(u,\
    \ v, w);\n            } else {\n                add_edge(u, v, w);\n         \
    \   }\n        }\n    }\n\n    std::vector<Edge>& operator[](const int& v) {\n\
    \        return G[v];\n    }\n\n    std::vector<Edge> edges() {\n        std::vector<Edge>\
    \ es(M);\n        for (int v = 0; v < N; v++) {\n            for (const auto&\
    \ nv : G[v]) {\n                es[nv.id] = nv;\n            }\n        }\n  \
    \      return es;\n    }\n\n    // is_bipartite \u95A2\u6570 ===========================================\n\
    \    /**\n     * @brief \u30B0\u30E9\u30D5g\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n     */\n    bool is_bipartite(int\
    \ v, int v_color = 0) {\n        color[v] = v_color;\n        for (const auto&\
    \ e : G[v]) {\n            int nv = e.to;\n            if (color[nv] != -1) {\
    \ // \u96A3\u63A5\u9802\u70B9\u306E\u8272\u304C\u3059\u3067\u306B\u78BA\u5B9A\u3057\
    \u3066\u3044\u308B\n                if (color[nv] == v_color) {\n            \
    \        return false;\n                }\n                continue;\n       \
    \     }\n\n            if (!is_bipartite(nv, 1 - v_color)) {\n               \
    \ return false;\n            }\n        }\n\n        return true;\n    }\n\n \
    \   // \u6728\u306E\u76F4\u5F84 ===========================================\n\
    \    std::vector<int> get_tree_diameter(int x = 0) {\n\n        std::vector<T>\
    \ dist;\n        std::vector<Edge> prev_edges(N);\n        if (is_weighted) {\n\
    \            std::tie(dist, prev_edges) = Dijkstra(x);\n        } else {\n   \
    \         std::tie(dist, prev_edges) = BFS(x);\n        }\n        auto get_farthest_vertex\
    \ = [this](std::vector<T>& dist, int from) {\n            T max_dist = std::numeric_limits<T>::min();\n\
    \            int to = -1;\n            for (int v = 0; v < this->N; v++) {\n \
    \               if (max_dist < dist[v]) {\n                    max_dist = dist[v];\n\
    \                    to = v;\n                }\n            }\n            return\
    \ to;\n        };\n        int y = get_farthest_vertex(dist, x);\n        if (is_weighted)\
    \ {\n            std::tie(dist, prev_edges) = Dijkstra(y);\n        } else {\n\
    \            std::tie(dist, prev_edges) = BFS(y);\n        }\n        int z =\
    \ get_farthest_vertex(dist, y);\n\n        std::vector<int> path;\n        int\
    \ v = z;\n        while (1) {\n            path.push_back(v);\n            if\
    \ (v == y) {\n                break;\n            }\n            v = prev_edges[v].from;\n\
    \        }\n\n        std::reverse(path.begin(), path.end());\n\n        return\
    \ path;\n    }\n\n    // \u6700\u77ED\u8DDD\u96E2 ===========================================\n\
    \    std::pair<std::vector<T>, std::vector<Edge>> BFS(const int& start) {\n  \
    \      std::vector<T> dist(N, std::numeric_limits<T>::max());\n        std::queue<int>\
    \ q;\n        /**\n         * @param prev_edges[target] : start \u304B\u3089 target\
    \ \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u306B\u304A\u3051\u308B\u3001target\
    \ \u3092\u8A2A\u308C\u308B\u76F4\u524D\u306B\u901A\u3063\u305F\u8FBA\n       \
    \  */\n        std::vector<Edge> prev_edges(N);\n        dist[start] = 0;\n  \
    \      q.push(start);\n\n        while (!q.empty()) {\n            int v = q.front();\
    \ q.pop();\n            for (const auto& e : G[v]) {\n                int nv =\
    \ e.to;\n                if(dist[nv] != std::numeric_limits<T>::max()) {\n   \
    \                 continue;\n                }\n                dist[nv] = dist[v]\
    \ + 1;\n                prev_edges[nv] = e;\n                q.push(nv);\n   \
    \         }\n        }\n\n        return make_pair(dist, prev_edges);\n    }\n\
    \n    std::pair<std::vector<T>, std::vector<Edge>> BFS01(const int& start) {\n\
    \        std::vector<T> dist(N, std::numeric_limits<T>::max());\n        std::deque<int>\
    \ q;\n        /**\n         * @param prev_edges[target] : start \u304B\u3089 target\
    \ \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u306B\u304A\u3051\u308B\u3001target\u3092\
    \u8A2A\u308C\u308B\u76F4\u524D\u306B\u901A\u3063\u305F\u8FBA\n         */\n  \
    \      std::vector<Edge> prev_edges(N);\n        dist[start] = 0;\n        q.push_front(start);\n\
    \n        while (!q.empty()) {\n            int v = q.front(); q.pop_front();\n\
    \            for (const auto& e : G[v]) {\n                int nv = e.to;\n  \
    \              if (dist[nv] <= dist[v] + e.cost) {\n                    continue;\n\
    \                }\n                dist[nv] = dist[v] + e.cost;\n           \
    \     prev_edges[nv] = e;\n                if (e.cost == 0) {\n              \
    \      q.push_front(nv);\n                } else {\n                    q.push_back(nv);\n\
    \                }\n            }\n        }\n\n        return make_pair(dist,\
    \ prev_edges);\n    }\n\n    std::pair<std::vector<T>, std::vector<Edge>> Dijkstra(int\
    \ start) {\n        std::vector<T> dist(N, std::numeric_limits<T>::max());\n \
    \       std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<std::pair<T, int>>> q;\n        /**\n         * @param prev_edges[target]\
    \ : start \u304B\u3089 target \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u306B\
    \u304A\u3051\u308B\u3001target\u3092\u8A2A\u308C\u308B\u76F4\u524D\u306B\u901A\
    \u3063\u305F\u8FBA\n         */\n        std::vector<Edge> prev_edges(N);\n  \
    \      dist[start] = 0;\n        q.push({dist[start], start});\n\n        while\
    \ (!q.empty()) {\n            auto [dist_v, v] = q.top(); q.pop();\n         \
    \   if (dist_v > dist[v]) {\n                continue;\n            }\n      \
    \      for (const auto& e : G[v]) {\n                int nv = e.to;\n        \
    \        if(dist[nv] <= dist[v] + e.cost) {\n                    continue;\n \
    \               }\n                dist[nv] = dist[v] + e.cost;\n            \
    \    prev_edges[nv] = e;\n                q.push({dist[nv], nv});\n          \
    \  }\n        }\n\n        return make_pair(dist, prev_edges);\n    }\n\n    /**\n\
    \     * @brief \u8CA0\u8FBA\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3067\u3001\u5358\
    \u4E00\u59CB\u70B9\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\n   \
    \  * @return \u8CA0\u9589\u8DEF\u3092\u542B\u3080\u5834\u5408\u304B\u3069\u3046\
    \u304B\u306E\u30D5\u30E9\u30B0\u3001dist \u914D\u5217\n     * @remark \u5168\u8FBA\
    \u306E\u30B3\u30B9\u30C8\u3092 -1 \u500D\u3059\u308B\u3068\u3001\u6700\u9577\u7D4C\
    \u8DEF\u3092\u6C42\u3081\u308B\n     */\n    std::pair<std::vector<T>, bool> bellman_ford(int\
    \ start) {\n        const T INF_ = std::numeric_limits<T>::max();\n        std::vector<T>\
    \ dist(N, INF_);\n        dist[start] = 0;\n        int cnt = 0;\n        std::vector<Graph::Edge>\
    \ es = edges();\n\n        /**\n         * \u5168\u3066\u306E\u8FBA\u3092\u8D70\
    \u67FB\u3057\u3066\u7DE9\u548C\u3092\u884C\u3046\n         * https://qiita.com/muumu/items/bae1575c3161ced28587\n\
    \         * \u5404 while \u30EB\u30FC\u30D7\u3067\u3001\n         * \u9577\u3055\
    \ 1 \u306E\u6700\u77ED\u8DEF\u304C\u6C7A\u5B9A -> \u9577\u3055 2 \u306E\u6700\u77ED\
    \u8DEF\u304C\u6C7A\u5B9A -> ...\n         * \u307F\u305F\u3044\u306A\u611F\u3058\
    \uFF1F\n         */\n        while (cnt < N) {\n            bool end = true;\n\
    \            for (const auto& e : es) {\n                if (dist[e.from] != INF_\
    \ and dist[e.from] + e.cost < dist[e.to]) {\n                    dist[e.to] =\
    \ dist[e.from] + e.cost;\n                    end = false;\n                }\n\
    \            }\n            if (end) {\n                break;\n            }\n\
    \            cnt++;\n        }\n\n        return make_pair(dist, (cnt == N));\n\
    \    }\n\n    std::vector<Edge> path(const int& start, const int& target, const\
    \ std::vector<Edge>& prev_edges) {\n        std::vector<Edge> path;\n        for\
    \ (int cur = target; cur != start; cur = prev_edges[cur].from) {\n           \
    \ if (prev_edges[cur].id == -1) {\n                return {};\n            }\n\
    \            path.push_back(prev_edges[cur]);\n        }\n        std::reverse(path.begin(),\
    \ path.end());\n\n        return path;\n    }\n\n    // LCA ===========================================\n\
    \    /**\n     * @brief u \u3068 v \u306E LCA \u3092\u8FD4\u3059\n     * @remark\
    \ \u8A08\u7B97\u91CF\uFF1AO(logN)\n     */\n    int LCA(int u, int v, const int&\
    \ root = 0) {\n        if (!precalc_done) {\n            precalc_for_LCA(root);\n\
    \            precalc_done = true;\n        }\n\n        if (dist[u] < dist[v])\
    \ {\n            std::swap(u, v);\n        }\n        int K = (int)parent.size();\n\
    \        // u \u306E\u65B9\u304C\u6DF1\u3044\u5834\u5408\u3001u \u3092\u4E0A\u306B\
    \u52D5\u304B\u3059\u3053\u3068\u3067\u3001u \u3068 v \u306E LCA \u307E\u3067\u306E\
    \u8DDD\u96E2\u3092\u540C\u3058\u306B\u3059\u308B\u3002\n        int difference\
    \ = dist[u] - dist[v];\n        for (int i = 0; i < K; i++) {\n            if\
    \ ((difference >> i) & 1) {\n                u = parent[i][u];\n            }\n\
    \        }\n\n        if (u == v) {\n            return u;\n        }\n      \
    \  for (int i = K - 1; i >= 0; i--) {\n            // u, v \u3092\u3001LCA \u306E\
    \u624B\u524D\u307E\u3067\u79FB\u52D5 -> u, v \u306E1\u3064\u5148\u304C LCA \u3068\
    \u306A\u308B\u3002\n            if (parent[i][u] != parent[i][v]) {\n        \
    \        u = parent[i][u];\n                v = parent[i][v];\n            }\n\
    \        }\n        return parent[0][u];\n    }\n\n    /**\n     * @brief \u6728\
    \u4E0A\u306E2\u9802\u70B9 u, v \u306E\u8DDD\u96E2\u3092\u3001LCA \u3092\u5229\u7528\
    \u3057\u3066\u6C42\u3081\u308B\u3002\n     */\n    int get_dist(int u, int v,\
    \ const int& root = 0) {\n        if (!precalc_done) {\n            precalc_for_LCA(root);\n\
    \            precalc_done = true;\n        }\n        return dist[u] + dist[v]\
    \ - 2 * dist[LCA(u, v)];\n    }\n\n    /**\n     * @brief \u6728\u4E0A\u306E2\u9802\
    \u70B9 u, v \u306E\u30D1\u30B9\u4E0A\u306B\u3001\u9802\u70B9 p \u304C\u3042\u308B\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool\
    \ is_on_path (int u, int v, int p, const int& root = 0) {\n        return get_dist(u,\
    \ p) + get_dist(p, v) == get_dist(u, v);\n    }\n};\n\n#endif // Graph_template_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Graph_template.hpp
  requiredBy: []
  timestamp: '2025-11-23 17:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Graph_template.hpp
layout: document
redirect_from:
- /library/Graph/Graph_template.hpp
- /library/Graph/Graph_template.hpp.html
title: "LCA\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09\u3092\u6C42\u3081\u308B\
  \u305F\u3081\u306E\u524D\u51E6\u7406"
---
