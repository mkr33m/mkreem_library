#ifndef Trie_HPP
#define Trie_HPP

#include <vector>
#include <string>
#include <functional>
#include <cassert>

/**
 * @brief 文字列の挿入・検索など、O(文字列の長さ)で行う。
 */
template <int num_of_char, int base, bool use_accept = false>
struct Trie {
public:
    struct Node {
        /**
         * @param next 子の頂点番号を記録。next[c] の形式で、c に対応する文字を記録する子の頂点番号を返す。
         * @param accept 末端がこの頂点となる（= この頂点が表す）文字列の str_id を記録（str_id は、i 番目（0-indexed）に挿入された文字列なら、str_id == i となる）。
         * @param accepted 末端がこの頂点となる文字列が存在するか（= accept.size() > 0 かどうか）
         * @param c この頂点が記録している文字の、base との距離。
         * @param share いくつの文字列がこの頂点を共有しているか。
         * @param depth 根からの距離。
         */
        std::vector<int> next;
        std::vector<int> accept;
        bool accepted;
        int c, share, depth;

        Node(int c, int depth) : next(num_of_char, -1),
                                accept(0),
                                accepted(false),
                                c(c),
                                share(0),
                                depth(depth) { };
    };

    Trie() : root(0) {
        nodes.push_back(Node(root, 0)); // 根となる頂点を追加
    }

    void insert(const std::string& word, const std::function<void(int)>& f = [](int){}){
        insert_(word, f, nodes[0].share);
    }

    /**
     * @brief 文字列 word が trie 木に記録されているかどうかを、bool値で返す
     * @brief prefix が word と一致するものを探す場合は、prefix を true にする。
     */
    bool search(const std::string& word, bool prefix = false){
        int node_id = 0; // 根から辿る
        for(const char& ch : word){
            const int c = (int)(ch - base);
            int& next_id = nodes[node_id].next[c];
            if(next_id == -1){
                return false;
            }
            node_id = next_id;
        }
        // prefix == false の場合は、最後の頂点が受理状態かどうかを判定する。
        return (prefix ? true : nodes[node_id].accepted); 
    }

    /**
     * @brief 文字列 word の prefix に一致する文字列を検索する。ただし、一致した文字列ごとに関数 f が呼び出される。
     * @param std::function<void(int)>& f  呼び出す関数 f。引数として、文字列の id（str_id）が渡される。
     */
    void query(const std::string& word, const std::function<void(int)>& f, int word_idx = 0, int node_id = 0){
        for(const auto& str_id : nodes[node_id].accept){
            f(str_id);
        }
        if(word_idx == (int)word.size()){
            return;
        } else{
            const int c = word[word_idx] - base;
            int next_id = nodes[node_id].next[c];
            if(next_id == -1){
                return;
            }
            query(word, f, word_idx + 1, next_id);
        }
    }

    /**
     * @brief 文字列 word に対応するノードを、先頭から順に走査する。ただし、ノードごとに関数 f が呼び出される。
     * @param std::function<void(int)>& f  呼び出す関数 f。引数として、訪れたノードの ID（node_id）が渡される。
     * @remark word は、Trie 木に insert されていなければならない。
     */
    void scan(const std::string& word, const std::function<void(int)>& f, int word_idx = 0, int node_id = 0, bool inserted = false){
        if(!inserted){ // 最初だけの処理
            assert(search(word, false));
        }
        if(word_idx == (int)word.size()){
            return;
        } else{
            const int c = word[word_idx] - base;
            int next_id = nodes[node_id].next[c];
            if(next_id == -1){
                return;
            }
            f(next_id);
            scan(word, f, word_idx + 1, next_id, true);
        }
    }

    /**
     * @brief 挿入した単語の数を返却する。
     */
    int count() const {
        return (nodes[0].share);
    }

    /**
     * @brief Trie 木のノード数を返却する。
     */
    int size() const {
        return ((int)nodes.size());
    }

    /**
     * @brief node_id に対応するノード（の参照）を返却する。
     */
    const Node& node(const int& node_id) const {
        assert(node_id < (int)nodes.size());
        return nodes[node_id];
    }

private:
    std::vector<Node> nodes; // Trie木
    int root;

    /**
     * @brief trie木に文字列を挿入する
     * @remark 計算量：O(挿入する文字列の長さ)
     * @param std::function<void(int)>& f  挿入するとき、すでに追加されているノードを訪れたときに実行する関数。引数として、訪れたノードの ID（node_id）が渡される（ただし、根は除く）。
     */
    void insert_(const std::string& word, const std::function<void(int)>& f, int word_id){
        int node_id = 0;
        for(int i = 0; i < (int)word.size(); i++){
            const char ch = word[i];
            const int c = int(ch - base);
            int& next_id = nodes[node_id].next[c];
            if(next_id == -1){ // 次の頂点が存在しない（新たに頂点を追加する必要がある）。
                next_id = (int)nodes.size();
                nodes.push_back(Node(c, i + 1));
            } else{
                f(next_id);
            }
            nodes[node_id].share++;
            node_id = next_id;
        }
        // この時点で、node_id は単語の終点を記録する頂点を指す。
        nodes[node_id].share++;
        nodes[node_id].accepted = true;
        if(use_accept){
            nodes[node_id].accept.push_back(word_id);
        }
    }
};

#endif // Trie_HPP