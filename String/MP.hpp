#ifndef KMP_HPP
#define KMP_HPP

#include <string>
#include <vector>

/**
 * @brief S[0, i) の接頭辞、接尾辞が最大何文字一致しているかを記録した配列を返す。つまり、S[0, k) == S[i-k, i) なる最大の k。
 */
std::vector<int> MP(std::string S) {
    int N = (int)S.size();
    std::vector<int> res(N + 1); // [0, i)

    res[0] = -1;
    int j = -1;
    for (int i = 0; i < N; i++) {
        while (j >= 0 && S[i] != S[j]) {
            j = res[j];
        }
        j++;
        res[i + 1] = j;
    }

    return res;
}


#endif // KMP_HPP