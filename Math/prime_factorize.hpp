#ifndef prime_factorize_HPP
#define prime_factorize_HPP

#include <map>

/**
 * @brief N の素因数分解し、その結果を map に格納する
 */
template<typename T>
std::map<T, int> prime_factorize(T N){
    std::map<T, int> res;

    for(T i = 2; i * i <= N; i++){
        if(N % i != 0) continue;

        int exp = 0; // 指数
        // 割れる限り割り続ける
        while(N % i == 0){
            exp++;
            N /= i;
        }
        res[i] = exp;
    }

    // 素数のとき、2 ~ √N のいずれでも割り切ることができないので、N はそのままになる
    if(N != 1) res[N] = 1;
    return res;
}

#endif // H_prime_factorize