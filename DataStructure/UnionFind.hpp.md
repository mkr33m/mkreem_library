---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9802\u70B9 x \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\
      \u5206\u306E\u6839\u3092\u8FD4\u3059\u3002"
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n\nstruct UnionFind {\nprivate:\n    // @param data \u5404\
    \u30CE\u30FC\u30C9\u306B\u3064\u3044\u3066\u3001\u6240\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u6839\u306E\u9802\u70B9\u756A\u53F7\u3092\u4FDD\u6301\
    \uFF08\u6839\u81EA\u8EAB\u306F\u3001\u300C-\uFF08\u6839\u304C\u7BA1\u8F44\u3059\
    \u308B\u96C6\u5408\u306E\u30CE\u30FC\u30C9\u6570\uFF09\u300D\u3092\u4FDD\u6301\
    \uFF09\u3002\n    int N;\n    std::vector<int> data;\n\npublic:\n    UnionFind()\
    \ = default;\n    UnionFind(int N) : N(N), data(N, -1) {}\n\n    /**\n     * @brief\
    \ \u9802\u70B9 x \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u6839\
    \u3092\u8FD4\u3059\u3002\n     */\n    int root(int x){\n        /**\n       \
    \  * if(data[x] < 0) return x;\n         * return data[x] = root(data[x]); //\
    \ \u7D4C\u8DEF\u5727\u7E2E\n         */\n        static std::vector<int> tmp;\n\
    \        while(data[x] >= 0){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\
    \n            tmp.push_back(x);\n            x = data[x];\n        }\n       \
    \ while(!tmp.empty()){ // \u7D4C\u8DEF\u5727\u7E2E\n            data[tmp.back()]\
    \ = x;\n            tmp.pop_back();\n        }\n        return x;\n    }\n\n \
    \   /**\n     * @brief \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3002\n     */\n    bool same(int x,\
    \ int y){\n        return root(x) == root(y);\n    }\n\n    /**\n     * @brief\
    \ \u540C\u3058\u96C6\u5408\u306B\u3059\u308B\u3002\n     */\n    bool merge(int\
    \ x, int y){\n        x = root(x), y = root(y); // <- \u6839\n\n        if(x ==\
    \ y) return false; // \u6839\u304C\u540C\u3058\u306A\u3089\u3001\u65E2\u306B\u540C\
    \u3058\u96C6\u5408\n        if(data[x] > data[y]) std::swap(x, y); // \u30DE\u30FC\
    \u30B8\u30C6\u30AF\n        data[x] += data[y];\n        data[y] = x;\n      \
    \  return true;\n    }\n\n    // @brief x\u304C\u5C5E\u3057\u3066\u3044\u308B\u96C6\
    \u5408\u306E\u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\n    int size(int x){\n\
    \        return -data[root(x)];\n    }\n\n    /**\n     * @brief \u96C6\u5408\u69CB\
    \u9020\u306E\u8A73\u7D30\u3092\u53D6\u5F97\n     */\n    std::vector<std::vector<int>>\
    \ groups(){\n        std::vector<std::vector<int>> res(N);\n        for(int i\
    \ = 0; i < N; i++){\n            res[root(i)].push_back(i);\n        }\n     \
    \   res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>&\
    \ vec){ return vec.empty(); }), res.end());\n        return res;\n    }\n};\n\n\
    /**\n * @param T \u30E2\u30CE\u30A4\u30C9\uFF08\u9023\u7D50\u6210\u5206\u304C\u6301\
    \u3064\u60C5\u5831\uFF09\u306E\u578B\n */\ntemplate <typename T>\nusing merge_function\
    \ = void(*)(T& parent_data, T child_data);\n\ntemplate <typename T, merge_function<T>\
    \ f>\nstruct UF_ComponentSum : UnionFind {\nprivate:\n    std::vector<T> sum_;\n\
    \npublic:\n    UF_ComponentSum() : UF_ComponentSum(0) {}\n    UF_ComponentSum(int\
    \ N, const T& init_value = T{}) : UF_ComponentSum(std::vector<T>(N, init_value))\
    \ {}\n    UF_ComponentSum(const std::vector<T>& init_values) : UnionFind(init_values.size()),\
    \ sum_(init_values) {}\n\n    bool merge(int x, int y){\n        x = root(x),\
    \ y = root(y); // <- \u6839\n        bool res = UnionFind::merge(x, y);\n    \
    \    if(res){\n            if(root(x) == y) std::swap(x, y); // \u30DE\u30FC\u30B8\
    \u5F8C\u306E\u9023\u7D50\u6210\u5206\u306E\u6839\u304C x \u3068\u306A\u308B\u3088\
    \u3046\u8ABF\u6574\n            f(sum_[x], std::move(sum_[y]));\n        }\n \
    \       return res;\n    }\n\n    const T& sum(int x){\n        return sum_[root(x)];\n\
    \    }\n};\n\n\n"
  code: "#ifndef UnionFind_HPP\n#define UnionFind_HPP\n\n#include <vector>\n#include\
    \ <algorithm>\n\nstruct UnionFind {\nprivate:\n    // @param data \u5404\u30CE\
    \u30FC\u30C9\u306B\u3064\u3044\u3066\u3001\u6240\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E\u6839\u306E\u9802\u70B9\u756A\u53F7\u3092\u4FDD\u6301\uFF08\
    \u6839\u81EA\u8EAB\u306F\u3001\u300C-\uFF08\u6839\u304C\u7BA1\u8F44\u3059\u308B\
    \u96C6\u5408\u306E\u30CE\u30FC\u30C9\u6570\uFF09\u300D\u3092\u4FDD\u6301\uFF09\
    \u3002\n    int N;\n    std::vector<int> data;\n\npublic:\n    UnionFind() = default;\n\
    \    UnionFind(int N) : N(N), data(N, -1) {}\n\n    /**\n     * @brief \u9802\u70B9\
    \ x \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u6839\u3092\u8FD4\
    \u3059\u3002\n     */\n    int root(int x){\n        /**\n         * if(data[x]\
    \ < 0) return x;\n         * return data[x] = root(data[x]); // \u7D4C\u8DEF\u5727\
    \u7E2E\n         */\n        static std::vector<int> tmp;\n        while(data[x]\
    \ >= 0){ // \u6839\u307E\u3067\u8FBF\u3063\u3066\u3044\u304F\n            tmp.push_back(x);\n\
    \            x = data[x];\n        }\n        while(!tmp.empty()){ // \u7D4C\u8DEF\
    \u5727\u7E2E\n            data[tmp.back()] = x;\n            tmp.pop_back();\n\
    \        }\n        return x;\n    }\n\n    /**\n     * @brief \u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3002\n     */\n    bool same(int x, int y){\n        return root(x) ==\
    \ root(y);\n    }\n\n    /**\n     * @brief \u540C\u3058\u96C6\u5408\u306B\u3059\
    \u308B\u3002\n     */\n    bool merge(int x, int y){\n        x = root(x), y =\
    \ root(y); // <- \u6839\n\n        if(x == y) return false; // \u6839\u304C\u540C\
    \u3058\u306A\u3089\u3001\u65E2\u306B\u540C\u3058\u96C6\u5408\n        if(data[x]\
    \ > data[y]) std::swap(x, y); // \u30DE\u30FC\u30B8\u30C6\u30AF\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return true;\n    }\n\n    // @brief\
    \ x\u304C\u5C5E\u3057\u3066\u3044\u308B\u96C6\u5408\u306E\u30CE\u30FC\u30C9\u6570\
    \u3092\u8FD4\u3059\n    int size(int x){\n        return -data[root(x)];\n   \
    \ }\n\n    /**\n     * @brief \u96C6\u5408\u69CB\u9020\u306E\u8A73\u7D30\u3092\
    \u53D6\u5F97\n     */\n    std::vector<std::vector<int>> groups(){\n        std::vector<std::vector<int>>\
    \ res(N);\n        for(int i = 0; i < N; i++){\n            res[root(i)].push_back(i);\n\
    \        }\n        res.erase(std::remove_if(res.begin(), res.end(), [](const\
    \ std::vector<int>& vec){ return vec.empty(); }), res.end());\n        return\
    \ res;\n    }\n};\n\n/**\n * @param T \u30E2\u30CE\u30A4\u30C9\uFF08\u9023\u7D50\
    \u6210\u5206\u304C\u6301\u3064\u60C5\u5831\uFF09\u306E\u578B\n */\ntemplate <typename\
    \ T>\nusing merge_function = void(*)(T& parent_data, T child_data);\n\ntemplate\
    \ <typename T, merge_function<T> f>\nstruct UF_ComponentSum : UnionFind {\nprivate:\n\
    \    std::vector<T> sum_;\n\npublic:\n    UF_ComponentSum() : UF_ComponentSum(0)\
    \ {}\n    UF_ComponentSum(int N, const T& init_value = T{}) : UF_ComponentSum(std::vector<T>(N,\
    \ init_value)) {}\n    UF_ComponentSum(const std::vector<T>& init_values) : UnionFind(init_values.size()),\
    \ sum_(init_values) {}\n\n    bool merge(int x, int y){\n        x = root(x),\
    \ y = root(y); // <- \u6839\n        bool res = UnionFind::merge(x, y);\n    \
    \    if(res){\n            if(root(x) == y) std::swap(x, y); // \u30DE\u30FC\u30B8\
    \u5F8C\u306E\u9023\u7D50\u6210\u5206\u306E\u6839\u304C x \u3068\u306A\u308B\u3088\
    \u3046\u8ABF\u6574\n            f(sum_[x], std::move(sum_[y]));\n        }\n \
    \       return res;\n    }\n\n    const T& sum(int x){\n        return sum_[root(x)];\n\
    \    }\n};\n\n#endif // UnionFind_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2024-09-26 18:45:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.hpp
- /library/DataStructure/UnionFind.hpp.html
title: "\u9802\u70B9 x \u304C\u6240\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
  \u6839\u3092\u8FD4\u3059\u3002"
---
