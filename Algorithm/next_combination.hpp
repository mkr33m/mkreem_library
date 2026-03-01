#ifndef next_combination_HPP
#define next_combination_HPP

#include <vector>

/**
 * @brief 昇順の idx 配列（長さ K）を、次の組み合わせへ進める
 * @remark 0 <= idx[0] < idx[1] < ... < idx[K-1] < N を保つ
 * @remark idx={0,1,...,K-1} で初期化して渡す
 */
bool next_combination(std::vector<int>& idx, int N) {
    int K = (int)idx.size();
    // 後ろから
    for (int i = K - 1; i >= 0; i--) {
        // idx[i] の max は N-K+i
        if (idx[i] < N - K + i) {
            idx[i]++;
            for (int j = i + 1; j < K; j++) { // (i,K) は辞書順最小に
                idx[j] = idx[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

#endif // next_combination_HPP