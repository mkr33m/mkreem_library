#ifndef suffix_array_HPP
#define suffix_array_HPP

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

namespace internal_suffix_array {

void radix_sort(std::vector<int>& sa, const std::vector<int>& key, int maxv) {
    int N = (int)sa.size();
    std::vector<int> sorted_sa(N), pref(maxv + 1, 0);
    for (int x : sa) {
        pref[key[x]]++;
    }
    for (int i = 1; i <= maxv; i++) {
        pref[i] += pref[i - 1];
    }
    for (int i = N - 1; i >= 0; i--) {
        int x = sa[i];
        sorted_sa[--pref[key[x]]] = x;
    }
    sa.swap(sorted_sa);
}

} // namespace internal_suffix_array

std::vector<int> suffix_array(const std::string& S) {
    if (S.empty()) {
        return {};
    }
    int N = (int)S.size();
    std::vector<int> sa(N), rank(N), tmp(N);
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        rank[i] = (unsigned char)S[i]; // 初期化
    }
    int b = 1; // 2^0
    int mx = 256; // rank の上限
    do {
        /**
         * @param key1 rank[i]
         * @param key2 rank[i + b]
         */
        std::vector<int> key1(N), key2(N);
        for (int i = 0; i < N; i++) {
            key1[i] = rank[i] + 1;
            key2[i] = (i + b < N ? rank[i + b] + 1 : 0);
        }

        internal_suffix_array::radix_sort(sa, key2, mx);
        internal_suffix_array::radix_sort(sa, key1, mx);
        
        tmp[sa[0]] = 0;
        for (int i = 1; i < N; i++) { // rank_{k+1} を求める
            int pre_idx = sa[i - 1];
            int pos_idx = sa[i];
            tmp[pos_idx] = tmp[pre_idx];
            int pre_rank_1 = rank[pre_idx];
            int pos_rank_1 = rank[pos_idx];
            int pre_rank_2 = (pre_idx + b < N ? rank[pre_idx + b] : -1);
            int pos_rank_2 = (pos_idx + b < N ? rank[pos_idx + b] : -1);
            if (pre_rank_1 != pos_rank_1 || pre_rank_2 != pos_rank_2) {
                tmp[pos_idx]++;
            }
        }
        rank = tmp;
        mx = rank[sa[N - 1]] + 1;
        b <<= 1;
    } while (mx != N);
    return sa;
}

#endif 