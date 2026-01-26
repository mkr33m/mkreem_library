#ifndef prime_factorize_vector_HPP
#define prime_factorize_vector_HPP

#include <vector>
#include <tuple>

/**
 * @brief N の素因数分解し、その結果を map に格納する
 */
template<typename T>
std::vector<std::pair<T, int>> prime_factorize_vector(T N) {
    std::vector<std::pair<T, int>> res;

    for (T i = 2; i * i <= N; i++) {
        if(N % i != 0) {
            continue;
        }

        int exp = 0;
        while (N % i == 0) {
            exp++;
            N /= i;
        }
        res.emplace_back(i, exp);
    }

    // 素数のとき、2 ~ √N のいずれでも割り切ることができないので、N はそのまま
    if (N != 1) {
        res.emplace_back(N, 1);
    }

    return res;
}

#endif // prime_factorize_vector_HPP