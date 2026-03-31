#ifndef lcp_array_HPP
#define lcp_array_HPP

#include <cassert>
#include <string>
#include <vector>

#include "./suffix_array.hpp"

std::vector<int> lcp_array(const std::string& S) {
    if (S.empty()) {
        return {};
    }
    int N = (int)S.size();
    std::vector<int> sa = suffix_array(S), rank(N), lcp(N - 1);
    for (int i = 0; i < N; i++) {
        rank[sa[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < N; i++) { // S[i,N)
        int p = rank[i];
        if (p == N - 1) { // 辞書順で次のやつがないなら、
            h = 0;
            continue;
        }
        int j = sa[p + 1]; // 辞書順で次のやつ
        while (i + h < N && j + h < N && S[i + h] == S[j + h]) {
            h++;
        }
        lcp[p] = h;
        if (h > 0) {
            h--;
        }
    }
    return lcp;
}

#endif // lcp_array_HPP