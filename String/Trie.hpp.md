---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6587\u5B57\u5217\u306E\u633F\u5165\u30FB\u691C\u7D22\u306A\u3069\
      \u3001O(\u6587\u5B57\u5217\u306E\u9577\u3055)\u3067\u884C\u3046\u3002"
    links: []
  bundledCode: "#line 1 \"String/Trie.hpp\"\n\n\n\n#include <vector>\n#include <string>\n\
    #include <functional>\n#include <cassert>\n\n/**\n * @brief \u6587\u5B57\u5217\
    \u306E\u633F\u5165\u30FB\u691C\u7D22\u306A\u3069\u3001O(\u6587\u5B57\u5217\u306E\
    \u9577\u3055)\u3067\u884C\u3046\u3002\n */\ntemplate <int num_of_char, int base,\
    \ bool use_accept = false>\nstruct Trie {\npublic:\n    struct Node {\n      \
    \  /**\n         * @param next \u5B50\u306E\u9802\u70B9\u756A\u53F7\u3092\u8A18\
    \u9332\u3002next[c] \u306E\u5F62\u5F0F\u3067\u3001c \u306B\u5BFE\u5FDC\u3059\u308B\
    \u6587\u5B57\u3092\u8A18\u9332\u3059\u308B\u5B50\u306E\u9802\u70B9\u756A\u53F7\
    \u3092\u8FD4\u3059\u3002\n         * @param accept \u672B\u7AEF\u304C\u3053\u306E\
    \u9802\u70B9\u3068\u306A\u308B\uFF08= \u3053\u306E\u9802\u70B9\u304C\u8868\u3059\
    \uFF09\u6587\u5B57\u5217\u306E str_id \u3092\u8A18\u9332\uFF08str_id \u306F\u3001\
    i \u756A\u76EE\uFF080-indexed\uFF09\u306B\u633F\u5165\u3055\u308C\u305F\u6587\u5B57\
    \u5217\u306A\u3089\u3001str_id == i \u3068\u306A\u308B\uFF09\u3002\n         *\
    \ @param accepted \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\u3068\u306A\u308B\
    \u6587\u5B57\u5217\u304C\u5B58\u5728\u3059\u308B\u304B\uFF08= accept.size() >\
    \ 0 \u304B\u3069\u3046\u304B\uFF09\n         * @param c \u3053\u306E\u9802\u70B9\
    \u304C\u8A18\u9332\u3057\u3066\u3044\u308B\u6587\u5B57\u306E\u3001base \u3068\u306E\
    \u8DDD\u96E2\u3002\n         * @param share \u3044\u304F\u3064\u306E\u6587\u5B57\
    \u5217\u304C\u3053\u306E\u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\
    \u304B\u3002\n         * @param depth \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3002\
    \n         */\n        std::vector<int> next;\n        std::vector<int> accept;\n\
    \        bool accepted;\n        int c, share, depth;\n\n        Node(int c, int\
    \ depth) : next(num_of_char, -1),\n                                accept(0),\n\
    \                                accepted(false),\n                          \
    \      c(c),\n                                share(0),\n                    \
    \            depth(depth) { };\n    };\n\n    Trie() : root(0) {\n        nodes.push_back(Node(root,\
    \ 0)); // \u6839\u3068\u306A\u308B\u9802\u70B9\u3092\u8FFD\u52A0\n    }\n\n  \
    \  void insert(const std::string& word, const std::function<void(int)>& f = [](int){}){\n\
    \        insert_(word, f, nodes[0].share);\n    }\n\n    /**\n     * @brief \u6587\
    \u5B57\u5217 word \u304C trie \u6728\u306B\u8A18\u9332\u3055\u308C\u3066\u3044\
    \u308B\u304B\u3069\u3046\u304B\u3092\u3001bool\u5024\u3067\u8FD4\u3059\n     *\
    \ @brief prefix \u304C word \u3068\u4E00\u81F4\u3059\u308B\u3082\u306E\u3092\u63A2\
    \u3059\u5834\u5408\u306F\u3001prefix \u3092 true \u306B\u3059\u308B\u3002\n  \
    \   */\n    bool search(const std::string& word, bool prefix = false){\n     \
    \   int node_id = 0; // \u6839\u304B\u3089\u8FBF\u308B\n        for(const char&\
    \ ch : word){\n            const int c = (int)(ch - base);\n            int& next_id\
    \ = nodes[node_id].next[c];\n            if(next_id == -1){\n                return\
    \ false;\n            }\n            node_id = next_id;\n        }\n        //\
    \ prefix == false \u306E\u5834\u5408\u306F\u3001\u6700\u5F8C\u306E\u9802\u70B9\
    \u304C\u53D7\u7406\u72B6\u614B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n        return (prefix ? true : nodes[node_id].accepted); \n   \
    \ }\n\n    /**\n     * @brief \u6587\u5B57\u5217 word \u306E prefix \u306B\u4E00\
    \u81F4\u3059\u308B\u6587\u5B57\u5217\u3092\u691C\u7D22\u3059\u308B\u3002\u305F\
    \u3060\u3057\u3001\u4E00\u81F4\u3057\u305F\u6587\u5B57\u5217\u3054\u3068\u306B\
    \u95A2\u6570 f \u304C\u547C\u3073\u51FA\u3055\u308C\u308B\u3002\n     * @param\
    \ std::function<void(int)>& f  \u547C\u3073\u51FA\u3059\u95A2\u6570 f\u3002\u5F15\
    \u6570\u3068\u3057\u3066\u3001\u6587\u5B57\u5217\u306E id\uFF08str_id\uFF09\u304C\
    \u6E21\u3055\u308C\u308B\u3002\n     */\n    void query(const std::string& word,\
    \ const std::function<void(int)>& f, int word_idx = 0, int node_id = 0){\n   \
    \     for(const auto& str_id : nodes[node_id].accept){\n            f(str_id);\n\
    \        }\n        if(word_idx == (int)word.size()){\n            return;\n \
    \       } else{\n            const int c = word[word_idx] - base;\n          \
    \  int next_id = nodes[node_id].next[c];\n            if(next_id == -1){\n   \
    \             return;\n            }\n            query(word, f, word_idx + 1,\
    \ next_id);\n        }\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 word\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u3001\u5148\u982D\u304B\
    \u3089\u9806\u306B\u8D70\u67FB\u3059\u308B\u3002\u305F\u3060\u3057\u3001\u30CE\
    \u30FC\u30C9\u3054\u3068\u306B\u95A2\u6570 f \u304C\u547C\u3073\u51FA\u3055\u308C\
    \u308B\u3002\n     * @param std::function<void(int)>& f  \u547C\u3073\u51FA\u3059\
    \u95A2\u6570 f\u3002\u5F15\u6570\u3068\u3057\u3066\u3001\u8A2A\u308C\u305F\u30CE\
    \u30FC\u30C9\u306E ID\uFF08node_id\uFF09\u304C\u6E21\u3055\u308C\u308B\u3002\n\
    \     * @remark word \u306F\u3001Trie \u6728\u306B insert \u3055\u308C\u3066\u3044\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u3002\n     */\n    void scan(const\
    \ std::string& word, const std::function<void(int)>& f, int word_idx = 0, int\
    \ node_id = 0, bool inserted = false){\n        if(!inserted){ // \u6700\u521D\
    \u3060\u3051\u306E\u51E6\u7406\n            assert(search(word, false));\n   \
    \     }\n        if(word_idx == (int)word.size()){\n            return;\n    \
    \    } else{\n            const int c = word[word_idx] - base;\n            int\
    \ next_id = nodes[node_id].next[c];\n            if(next_id == -1){\n        \
    \        return;\n            }\n            f(next_id);\n            scan(word,\
    \ f, word_idx + 1, next_id, true);\n        }\n    }\n\n    /**\n     * @brief\
    \ \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\u6570\u3092\u8FD4\u5374\u3059\u308B\
    \u3002\n     */\n    int count() const {\n        return (nodes[0].share);\n \
    \   }\n\n    /**\n     * @brief Trie \u6728\u306E\u30CE\u30FC\u30C9\u6570\u3092\
    \u8FD4\u5374\u3059\u308B\u3002\n     */\n    int size() const {\n        return\
    \ ((int)nodes.size());\n    }\n\n    /**\n     * @brief node_id \u306B\u5BFE\u5FDC\
    \u3059\u308B\u30CE\u30FC\u30C9\uFF08\u306E\u53C2\u7167\uFF09\u3092\u8FD4\u5374\
    \u3059\u308B\u3002\n     */\n    const Node& node(const int& node_id) const {\n\
    \        assert(node_id < (int)nodes.size());\n        return nodes[node_id];\n\
    \    }\n\nprivate:\n    std::vector<Node> nodes; // Trie\u6728\n    int root;\n\
    \n    /**\n     * @brief trie\u6728\u306B\u6587\u5B57\u5217\u3092\u633F\u5165\u3059\
    \u308B\n     * @remark \u8A08\u7B97\u91CF\uFF1AO(\u633F\u5165\u3059\u308B\u6587\
    \u5B57\u5217\u306E\u9577\u3055)\n     * @param std::function<void(int)>& f  \u633F\
    \u5165\u3059\u308B\u3068\u304D\u3001\u3059\u3067\u306B\u8FFD\u52A0\u3055\u308C\
    \u3066\u3044\u308B\u30CE\u30FC\u30C9\u3092\u8A2A\u308C\u305F\u3068\u304D\u306B\
    \u5B9F\u884C\u3059\u308B\u95A2\u6570\u3002\u5F15\u6570\u3068\u3057\u3066\u3001\
    \u8A2A\u308C\u305F\u30CE\u30FC\u30C9\u306E ID\uFF08node_id\uFF09\u304C\u6E21\u3055\
    \u308C\u308B\uFF08\u305F\u3060\u3057\u3001\u6839\u306F\u9664\u304F\uFF09\u3002\
    \n     */\n    void insert_(const std::string& word, const std::function<void(int)>&\
    \ f, int word_id){\n        int node_id = 0;\n        for(int i = 0; i < (int)word.size();\
    \ i++){\n            const char ch = word[i];\n            const int c = int(ch\
    \ - base);\n            int& next_id = nodes[node_id].next[c];\n            if(next_id\
    \ == -1){ // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\u3057\u306A\u3044\uFF08\
    \u65B0\u305F\u306B\u9802\u70B9\u3092\u8FFD\u52A0\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\uFF09\u3002\n                next_id = (int)nodes.size();\n     \
    \           nodes.push_back(Node(c, i + 1));\n            } else{\n          \
    \      f(next_id);\n            }\n            nodes[node_id].share++;\n     \
    \       node_id = next_id;\n        }\n        // \u3053\u306E\u6642\u70B9\u3067\
    \u3001node_id \u306F\u5358\u8A9E\u306E\u7D42\u70B9\u3092\u8A18\u9332\u3059\u308B\
    \u9802\u70B9\u3092\u6307\u3059\u3002\n        nodes[node_id].share++;\n      \
    \  nodes[node_id].accepted = true;\n        if(use_accept){\n            nodes[node_id].accept.push_back(word_id);\n\
    \        }\n    }\n};\n\n\n"
  code: "#ifndef Trie_HPP\n#define Trie_HPP\n\n#include <vector>\n#include <string>\n\
    #include <functional>\n#include <cassert>\n\n/**\n * @brief \u6587\u5B57\u5217\
    \u306E\u633F\u5165\u30FB\u691C\u7D22\u306A\u3069\u3001O(\u6587\u5B57\u5217\u306E\
    \u9577\u3055)\u3067\u884C\u3046\u3002\n */\ntemplate <int num_of_char, int base,\
    \ bool use_accept = false>\nstruct Trie {\npublic:\n    struct Node {\n      \
    \  /**\n         * @param next \u5B50\u306E\u9802\u70B9\u756A\u53F7\u3092\u8A18\
    \u9332\u3002next[c] \u306E\u5F62\u5F0F\u3067\u3001c \u306B\u5BFE\u5FDC\u3059\u308B\
    \u6587\u5B57\u3092\u8A18\u9332\u3059\u308B\u5B50\u306E\u9802\u70B9\u756A\u53F7\
    \u3092\u8FD4\u3059\u3002\n         * @param accept \u672B\u7AEF\u304C\u3053\u306E\
    \u9802\u70B9\u3068\u306A\u308B\uFF08= \u3053\u306E\u9802\u70B9\u304C\u8868\u3059\
    \uFF09\u6587\u5B57\u5217\u306E str_id \u3092\u8A18\u9332\uFF08str_id \u306F\u3001\
    i \u756A\u76EE\uFF080-indexed\uFF09\u306B\u633F\u5165\u3055\u308C\u305F\u6587\u5B57\
    \u5217\u306A\u3089\u3001str_id == i \u3068\u306A\u308B\uFF09\u3002\n         *\
    \ @param accepted \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\u3068\u306A\u308B\
    \u6587\u5B57\u5217\u304C\u5B58\u5728\u3059\u308B\u304B\uFF08= accept.size() >\
    \ 0 \u304B\u3069\u3046\u304B\uFF09\n         * @param c \u3053\u306E\u9802\u70B9\
    \u304C\u8A18\u9332\u3057\u3066\u3044\u308B\u6587\u5B57\u306E\u3001base \u3068\u306E\
    \u8DDD\u96E2\u3002\n         * @param share \u3044\u304F\u3064\u306E\u6587\u5B57\
    \u5217\u304C\u3053\u306E\u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\
    \u304B\u3002\n         * @param depth \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3002\
    \n         */\n        std::vector<int> next;\n        std::vector<int> accept;\n\
    \        bool accepted;\n        int c, share, depth;\n\n        Node(int c, int\
    \ depth) : next(num_of_char, -1),\n                                accept(0),\n\
    \                                accepted(false),\n                          \
    \      c(c),\n                                share(0),\n                    \
    \            depth(depth) { };\n    };\n\n    Trie() : root(0) {\n        nodes.push_back(Node(root,\
    \ 0)); // \u6839\u3068\u306A\u308B\u9802\u70B9\u3092\u8FFD\u52A0\n    }\n\n  \
    \  void insert(const std::string& word, const std::function<void(int)>& f = [](int){}){\n\
    \        insert_(word, f, nodes[0].share);\n    }\n\n    /**\n     * @brief \u6587\
    \u5B57\u5217 word \u304C trie \u6728\u306B\u8A18\u9332\u3055\u308C\u3066\u3044\
    \u308B\u304B\u3069\u3046\u304B\u3092\u3001bool\u5024\u3067\u8FD4\u3059\n     *\
    \ @brief prefix \u304C word \u3068\u4E00\u81F4\u3059\u308B\u3082\u306E\u3092\u63A2\
    \u3059\u5834\u5408\u306F\u3001prefix \u3092 true \u306B\u3059\u308B\u3002\n  \
    \   */\n    bool search(const std::string& word, bool prefix = false){\n     \
    \   int node_id = 0; // \u6839\u304B\u3089\u8FBF\u308B\n        for(const char&\
    \ ch : word){\n            const int c = (int)(ch - base);\n            int& next_id\
    \ = nodes[node_id].next[c];\n            if(next_id == -1){\n                return\
    \ false;\n            }\n            node_id = next_id;\n        }\n        //\
    \ prefix == false \u306E\u5834\u5408\u306F\u3001\u6700\u5F8C\u306E\u9802\u70B9\
    \u304C\u53D7\u7406\u72B6\u614B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n        return (prefix ? true : nodes[node_id].accepted); \n   \
    \ }\n\n    /**\n     * @brief \u6587\u5B57\u5217 word \u306E prefix \u306B\u4E00\
    \u81F4\u3059\u308B\u6587\u5B57\u5217\u3092\u691C\u7D22\u3059\u308B\u3002\u305F\
    \u3060\u3057\u3001\u4E00\u81F4\u3057\u305F\u6587\u5B57\u5217\u3054\u3068\u306B\
    \u95A2\u6570 f \u304C\u547C\u3073\u51FA\u3055\u308C\u308B\u3002\n     * @param\
    \ std::function<void(int)>& f  \u547C\u3073\u51FA\u3059\u95A2\u6570 f\u3002\u5F15\
    \u6570\u3068\u3057\u3066\u3001\u6587\u5B57\u5217\u306E id\uFF08str_id\uFF09\u304C\
    \u6E21\u3055\u308C\u308B\u3002\n     */\n    void query(const std::string& word,\
    \ const std::function<void(int)>& f, int word_idx = 0, int node_id = 0){\n   \
    \     for(const auto& str_id : nodes[node_id].accept){\n            f(str_id);\n\
    \        }\n        if(word_idx == (int)word.size()){\n            return;\n \
    \       } else{\n            const int c = word[word_idx] - base;\n          \
    \  int next_id = nodes[node_id].next[c];\n            if(next_id == -1){\n   \
    \             return;\n            }\n            query(word, f, word_idx + 1,\
    \ next_id);\n        }\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 word\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u3001\u5148\u982D\u304B\
    \u3089\u9806\u306B\u8D70\u67FB\u3059\u308B\u3002\u305F\u3060\u3057\u3001\u30CE\
    \u30FC\u30C9\u3054\u3068\u306B\u95A2\u6570 f \u304C\u547C\u3073\u51FA\u3055\u308C\
    \u308B\u3002\n     * @param std::function<void(int)>& f  \u547C\u3073\u51FA\u3059\
    \u95A2\u6570 f\u3002\u5F15\u6570\u3068\u3057\u3066\u3001\u8A2A\u308C\u305F\u30CE\
    \u30FC\u30C9\u306E ID\uFF08node_id\uFF09\u304C\u6E21\u3055\u308C\u308B\u3002\n\
    \     * @remark word \u306F\u3001Trie \u6728\u306B insert \u3055\u308C\u3066\u3044\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u3002\n     */\n    void scan(const\
    \ std::string& word, const std::function<void(int)>& f, int word_idx = 0, int\
    \ node_id = 0, bool inserted = false){\n        if(!inserted){ // \u6700\u521D\
    \u3060\u3051\u306E\u51E6\u7406\n            assert(search(word, false));\n   \
    \     }\n        if(word_idx == (int)word.size()){\n            return;\n    \
    \    } else{\n            const int c = word[word_idx] - base;\n            int\
    \ next_id = nodes[node_id].next[c];\n            if(next_id == -1){\n        \
    \        return;\n            }\n            f(next_id);\n            scan(word,\
    \ f, word_idx + 1, next_id, true);\n        }\n    }\n\n    /**\n     * @brief\
    \ \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\u6570\u3092\u8FD4\u5374\u3059\u308B\
    \u3002\n     */\n    int count() const {\n        return (nodes[0].share);\n \
    \   }\n\n    /**\n     * @brief Trie \u6728\u306E\u30CE\u30FC\u30C9\u6570\u3092\
    \u8FD4\u5374\u3059\u308B\u3002\n     */\n    int size() const {\n        return\
    \ ((int)nodes.size());\n    }\n\n    /**\n     * @brief node_id \u306B\u5BFE\u5FDC\
    \u3059\u308B\u30CE\u30FC\u30C9\uFF08\u306E\u53C2\u7167\uFF09\u3092\u8FD4\u5374\
    \u3059\u308B\u3002\n     */\n    const Node& node(const int& node_id) const {\n\
    \        assert(node_id < (int)nodes.size());\n        return nodes[node_id];\n\
    \    }\n\nprivate:\n    std::vector<Node> nodes; // Trie\u6728\n    int root;\n\
    \n    /**\n     * @brief trie\u6728\u306B\u6587\u5B57\u5217\u3092\u633F\u5165\u3059\
    \u308B\n     * @remark \u8A08\u7B97\u91CF\uFF1AO(\u633F\u5165\u3059\u308B\u6587\
    \u5B57\u5217\u306E\u9577\u3055)\n     * @param std::function<void(int)>& f  \u633F\
    \u5165\u3059\u308B\u3068\u304D\u3001\u3059\u3067\u306B\u8FFD\u52A0\u3055\u308C\
    \u3066\u3044\u308B\u30CE\u30FC\u30C9\u3092\u8A2A\u308C\u305F\u3068\u304D\u306B\
    \u5B9F\u884C\u3059\u308B\u95A2\u6570\u3002\u5F15\u6570\u3068\u3057\u3066\u3001\
    \u8A2A\u308C\u305F\u30CE\u30FC\u30C9\u306E ID\uFF08node_id\uFF09\u304C\u6E21\u3055\
    \u308C\u308B\uFF08\u305F\u3060\u3057\u3001\u6839\u306F\u9664\u304F\uFF09\u3002\
    \n     */\n    void insert_(const std::string& word, const std::function<void(int)>&\
    \ f, int word_id){\n        int node_id = 0;\n        for(int i = 0; i < (int)word.size();\
    \ i++){\n            const char ch = word[i];\n            const int c = int(ch\
    \ - base);\n            int& next_id = nodes[node_id].next[c];\n            if(next_id\
    \ == -1){ // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\u3057\u306A\u3044\uFF08\
    \u65B0\u305F\u306B\u9802\u70B9\u3092\u8FFD\u52A0\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\uFF09\u3002\n                next_id = (int)nodes.size();\n     \
    \           nodes.push_back(Node(c, i + 1));\n            } else{\n          \
    \      f(next_id);\n            }\n            nodes[node_id].share++;\n     \
    \       node_id = next_id;\n        }\n        // \u3053\u306E\u6642\u70B9\u3067\
    \u3001node_id \u306F\u5358\u8A9E\u306E\u7D42\u70B9\u3092\u8A18\u9332\u3059\u308B\
    \u9802\u70B9\u3092\u6307\u3059\u3002\n        nodes[node_id].share++;\n      \
    \  nodes[node_id].accepted = true;\n        if(use_accept){\n            nodes[node_id].accept.push_back(word_id);\n\
    \        }\n    }\n};\n\n#endif // Trie_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/Trie.hpp
  requiredBy: []
  timestamp: '2024-11-18 02:37:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie.hpp
layout: document
title: Trie
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
