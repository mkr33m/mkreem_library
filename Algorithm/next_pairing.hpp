#ifndef next_pairing_HPP
#define next_pairing_HPP

#include <vector>

#include "../Others/macros.hpp"
#include "../Math/math.hpp"

template <typename T>
/**
 * @brief (2,...,2)-shuffle である 0, 1, ..., 2 * N - 1 の置換 A を、辞書順で列挙する
 */
bool next_pairing(const std::vector<T>& vec){
    int N = vec.size();
    /**
     * @param used vec に含まれるどの数が使用済みであるか
     */
    ll used = 0;
    for(int i = N - 1; i >= 0; i--){
        used |= (1 << vec[i]);
        if(i % 2 == 1 && vec[i] < math::log2_floor(used)){ // インクリメントできる
            vec[i] = __builtin_ctzll(used >> (vec[i] + 1)) + vec[i] + 1;
            used ^= (1 << vec[i]);
            for(int j = i + 1; j < N; j++){
                vec[j] = __builtin_ctzll(used);
                used ^= (1 << vec[j]);
            }
            return true;
        }
    }
    return false;
}

#endif // next_pairing_HPP