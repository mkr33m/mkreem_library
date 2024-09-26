#ifndef sieve_HPP
#define sieve_HPP

#include <vector>

/**
 * @brief N 以下の非負整数について、素数の種類数を数える（1 種類なら素数）
 * @remark (Nloglog(N))
 */
std::vector<int> sieve(int N){
    std::vector<int> res(N + 1);
    for(int i = 2; i <= N; i++){
        if(res[i] != 0) continue; // 合成数
        for(int j = 1; i * j <= N; j++){
            res[i * j]++;
        }
    }
    return res;
}

#endif // sieve_HPP