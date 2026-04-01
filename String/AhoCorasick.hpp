#ifndef AhoCorasick_HPP
#define AhoCorasick_HPP

#include <array>
#include <queue>
#include <string>
#include <vector>

/**
 * 各頂点について、
 * その頂点に対応する文字列を S としたとき
 * S の全 suffix（ただし S を除く）を見て、
 * P に属しているもののうち最長
 * へのリンクを持つ必要がある
 */
template <int siz, int base, bool store_matches = false> // 文字列の種類数
struct AhoCorasick {
    struct Node {
        /**
         * @param accept なんらかの文字列の終端となっているか
         * @param cnt このノードで終わる（追加された）文字列集合の要素数
         * @param idxes このノードで終わる（追加された）文字列集合の要素の添え字
         */
        std::array<int, siz> nxt;
        std::array<bool, siz> is_child;
        int par;
        bool accept;
        int failure_link;
        int cnt;
        std::vector<int> idxes;
        Node() : par(-1), accept(false), failure_link(0), cnt(0), idxes() {
            for (int i = 0; i < siz; i++) {
                nxt[i] = -1;
                is_child[i] = false;
            }
        }
    };
    std::vector<Node> nodes;
    std::vector<int> ID;
    AhoCorasick(int N) : ID(N, -1) {
        nodes.emplace_back(Node());
    }
    /**
     * @brief idx 番目の文字列 S を追加する
     */
    void add(const std::string& S, int idx) {
        int pos = 0;
        for (char ch : S) {
            if (nodes[pos].nxt[ch - base] == -1) {
                nodes[pos].nxt[ch - base] = (int)nodes.size();
                nodes[pos].is_child[ch - base] = true;
                nodes.emplace_back(Node());
                nodes.back().par = pos;
            }
            pos = nodes[pos].nxt[ch - base];
        }
        nodes[pos].accept = true;
        nodes[pos].cnt++;
        if (store_matches) {
            nodes[pos].idxes.push_back(idx);
        }
        ID[idx] = pos;
    };
    /**
     * @brief idx 番目の文字列に対応する頂点番号を返す
     */
    int getID(int idx) {
        return ID[idx];
    }
    void build() {
        std::queue<int> q;
        for (int i = 0; i < siz; i++) {
            int c = nodes[0].nxt[i];
            if (c != -1) { // 根の子は全て failure_link=0
                q.emplace(c);
            } else {
                nodes[0].nxt[i] = 0;
            }
        }
        // 各状態の failure_link を、BFS 順で埋めていく
        while (!q.empty()) {
            /**
             * 親の failure_link を見る（ノードを X、それに対応する文字列を S とする）
             * -> もしそこから文字 i が生えているなら、文字列 S+i に対応するノードが c の failure_link になる
             * -> そうでないなら、X の failure_link を見る
             */
            int v = q.front(); q.pop();
            int f = nodes[v].failure_link;
            nodes[v].cnt += nodes[f].cnt;
            if (store_matches) {
                for (int i : nodes[f].idxes) {
                    nodes[v].idxes.push_back(i);
                }
            }
            for (int i = 0; i < siz; i++) {
                int c = nodes[v].nxt[i];
                bool child = nodes[v].is_child[i];
                if (c != -1 && child) { // 遷移先がある（子が存在する）
                    // 親 v の failure_link から i に対応する文字進んだ状態が、子 c の failure_link
                    nodes[c].failure_link = nodes[f].nxt[i];
                    q.emplace(c);
                } else { // 遷移先がない（子が存在しない）
                    // 親 v から、i に対応する文字の遷移で遷移先がないなら、
                    // 次行くべきなのは、親 v の failure_link から i に対応する文字進んだ状態
                    nodes[v].nxt[i] = nodes[f].nxt[i];
                }
            }
        }
    }
};


#endif // AhoCorasick_HPP