#ifndef Binom_HPP
#define Binom_HPP

#include <vector>

#include "../Others/macros.hpp"

struct Binom {
private:
    int N;
    std::vector<std::vector<ll>> C;

public:
    Binom() = default;
    Binom(const int& N) : N(N), C(N + 1, std::vector<ll>(N + 1, 0)) {
        for (int i = 0; i <= N; i++) {
            C[i][0] = 1;
        }
        // nCk = (n-1)C(k-1) + (n-1)Ck
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    ll val(int i, int j) {
        if (i < j || i < 0 || j < 0) {
            return 0LL;
        }
        return C[i][j];
    }
};

#endif // Binom_HPP