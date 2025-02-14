#ifndef next_pairing_HPP
#define next_pairing_HPP

/*
verify
・https://atcoder.jp/contests/abc236/tasks/abc236_d
*/

#include <vector>

#include "../Others/macros.hpp"
#include "../Math/math.hpp"

template <typename T>
bool next_pairing(const std::vector<T>& vec) {
    int N = vec.size();
    /**
     * @param used vec を右から左へ走査したとき、どの数字を見たか
     */
    ll used = 0;
    for (int i = N - 1; i >= 0; i--) {
        used |= (1 << vec[i]);
        if (i % 2 == 1 && vec[i] < math::log2_floor(used)) {
            vec[i] = __builtin_ctzll(used >> (vec[i] + 1)) + vec[i] + 1; // まだ見ていない数字のうち、 vec[i] より大きいものの中で最小のもの
            used ^= (1 << vec[i]);
            for (int j = i + 1; j < N; j++) { // i より後ろを辞書順最小に
                vec[j] = __builtin_ctzll(used);
                used ^= (1 << vec[j]);
            }
            return true;
        }
    }
    return false;
}

#endif // next_pairing_HPP