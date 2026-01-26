#ifndef prime_factorize_map_HPP
#define prime_factorize_map_HPP

#include <map>

template <typename T>
std::map<T, int> prime_factorize_map(T N) {
    std::map<T, int> res;

    for (T i = 2; i * i <= N; i++) {
        if(N % i != 0) {
            continue;
        }

        int exp = 0;
        while (N % i == 0) {
            exp++;
            N /= i;
        }
        res[i] = exp;
    }

    // 素数のとき、2 ~ √N のいずれでも割り切ることができないので、N はそのまま
    if (N != 1) {
        res[N] = 1;
    }

    return res;
}

#endif // end prime_factorize_map_HPP