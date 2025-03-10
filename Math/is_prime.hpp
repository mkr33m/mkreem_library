#ifndef is_prime_HPP
#define is_prime_HPP

#include <vector>

class IsPrime {
private:
    int N;
    std::vector<bool> is_prime_;
    std::vector<int> primes_;

public:
    IsPrime(int N) : N(N), is_prime_(N + 1, true), primes_() {
        is_prime_[0] = is_prime_[1] = false;
        
        for (int i = 2; i * i <= N; i++) {
            if (!is_prime_[i]) {
                continue;
            }
            for (int j = i * i; j <= N; j += i) {
                is_prime_[j] = false;
            }
        }

        for (int i = 2; i <= N; i++) {
            if (is_prime_[i]) {
                primes_.push_back(i);
            }
        }
    }

    bool is_prime(int x) {
        return is_prime_[x];
    }
    const std::vector<int>& get_primes() const& {
        return primes_;
    }
};

#endif // is_prime_HPP