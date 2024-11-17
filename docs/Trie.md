---
title: Trie
documentation_of: //String/Trie.hpp
---

## 概要

各ノードを文字とした木構造によって、文字列の挿入、検索、走査などを、$O(文字列の長さ)$ で行う。

## Node 構造体

```cpp
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
```

- `next`：子の頂点番号を保持。`next[c]` の形式で、`c` に対応する文字を保持する子の頂点番号を返す。
- `accept`：末端がこの頂点となる（= この頂点が表す）文字列の str_id を保持（str_id は、i 番目 (0-indexed) に挿入された文字列なら、str_id == i となる）。
- `accepted`：末端がこの頂点となる文字列が存在するか（= `accept`.size() > 0 かどうか）
- `c`：この頂点が記録している文字の、`base` との距離。
- `share`：いくつの文字列がこの頂点を共有しているか。
- `depth`：この頂点の、根からの距離。

### コンストラクタ

頂点が表す文字 `c`、根からの距離 `depth` で初期化する。

## コンストラクタ

```cpp
    Trie() : root(0) {
        nodes.push_back(Node(root, 0)); // 根となる頂点を追加
    }
```

ノードを管理する vector である `nodes` を、根で初期化する。引数はない。`nodes` でのインデックスがそのまま `node_id` となることに注意。

## 機能

### insert

```cpp
void insert(const std::string& word, const std::function<void(int)>& f = [](int){})
```

trie 木に、文字列 `word` を挿入する。関数 `f` は、文字列 `word` の挿入の途中で、すでに作られている頂点を訪れるときに実行する関数。引数として、`node_id` を渡す。

### search

```cpp
bool search(const std::string& word, bool prefix = false)
```

`prefix` が true なら、文字列 `word` と完全に一致する文字列、false なら、prefix が `word` と一致する文字列が Trie 木に登録されているかを bool 値で返す。

### query

```cpp
void query(const std::string& word, const std::function<void(int)>& f, int word_idx = 0, int node_id = 0)
```

文字列 `word` の prefix と一致する文字列を検索する。ただし、一致するたびに関数 `f` が呼び出される。関数 `f` の引数としては、文字列の ID（`str_id`）が渡される（`str_id` は、i 番目に挿入された文字列なら、str_id == i となる）。

### scan

```cpp
void scan(const std::string& word, const std::function<void(int)>& f, int word_idx = 0, int node_id = 0, bool inserted = false)
```

文字列 `word` に対応するノードを、先頭から順に走査する。ただし、ノードごとに関数 `f` が呼び出される。関数 `f` の引数としては、訪れたノードの ID（`node_id`）を渡す。
注意点として、文字列 `word` が Trie 木に登録されている必要がある。

### count

```cpp
int count()
```

挿入した文字列の総数を返す。

### size

```cpp
int size()
```

Trie 木の頂点数を返す。

### node

```cpp
const Node& node(const int& node_id)
```

`node_id` に対応するノード（の参照）を返却する。別の変数にコピーすれば、（その変数にコピーされた方の `Node` 構造体を）書き換えることも可能。
