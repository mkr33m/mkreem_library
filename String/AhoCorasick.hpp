#ifndef AhoCorasick_HPP
#define AhoCorasick_HPP

#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

template <int siz, int base, bool store_matches = false> // 文字列の種類数
struct AhoCorasick {
private:
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
    int M;
    std::vector<int> ID;
    bool built;
public:
    /**
     * @param M 文字列集合数
     */
    AhoCorasick(int M) : M(M), ID(M, -1), built(false) {
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
    }
    void read() {
        assert(!built);
        for (int i = 0; i < M; i++) {
            std::string S; std::cin >> S;
            add(S, i);
        }
        build();
    }
    void build() {
        assert(!built);
        built = true;
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
                if (c != -1 && child) { // 遷移先がある（ただし、子が存在するという意味で）
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
    /**
     * @brief idx 番目の文字列に対応する頂点番号を返す
     */
    int getID(int idx) const {
        return ID[idx];
    }
    /**
     * @brief Trie 木上の状態数を返す
     */
    int size() const {
        return (int)nodes.size();
    }
    /**
     * @brief ノード pos から i で遷移したときの遷移先を返す
     */
    int to(int pos, int i) const {
        return nodes[pos].nxt[i];
    }
    /**
     * @brief ノード pos を始点とした failure_link 鎖上の accept ノードに対応する文字列（の添え字）を返す
     */
    const std::vector<int>& get_idxes(int pos) const {
        return nodes[pos].idxes;
    }
    /**
     * @brief ノード pos を始点とした failure_link 鎖上の accept ノード数を返す
     */
    int get_cnt(int pos) const {
        return nodes[pos].cnt;
    }
    /**
     * @brief ノード pos が accept かどうかを返す
     */
    bool is_accept(int pos) const {
        return nodes[pos].accept;
    }
    /**
     * @brief ノード pos の failure_link を返す
     */
    int failure_link(int pos) const {
        return nodes[pos].failure_link;
    }
};


#endif // AhoCorasick_HPP