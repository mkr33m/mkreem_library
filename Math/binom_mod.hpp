#ifndef binom_mod_HPP
#define binom_mod_HPP

#include <vector>

template <typename T>
struct binom_mod {
private:
    int MAX_N;
    int mod;
    std::vector<T> factorial, factorial_inv;

public:
    binom_mod() = default;
    binom_mod(int MAX_N = 10000000) : MAX_N(MAX_N), mod(mod), factorial(MAX_N + 1, 0), factorial_inv(MAX_N + 1, 0) {
        factorial[0] = 1;
        for(int i = 1; i <= MAX_N; i++){
            factorial[i] = factorial[i - 1] * i;
        }
        factorial_inv[MAX_N] = factorial[MAX_N].inv();
        for(int i = MAX_N - 1; i >= 0; i--){
            factorial_inv[i] = factorial_inv[i + 1] * (i + 1);
        }
    }

    T val(int N, int K){
        if(N < K || N < 0 || K < 0){
            return T(0);
        }
        return factorial[N] * factorial_inv[K] * factorial_inv[N - K];
    }
};

#endif // binom_mod_HPP