#ifndef Doubling_HPP
#define Doubling_HPP

#include <vector>

template <typename S, S (*op)(S, S), S (*e)()>
struct Doubling {
    Doubling(const std::vector<int>& P, const std::vector<S>& V) {
        int N = P.size();
        next = std::vector<std::vector<int>> (61, std::vector<int>(N));
        // data[i][j] := j から 2^i 手進んだときの積
        dp = std::vector<std::vector<S>> (61, std::vector<S>(N));
        for (int i = 0; i < N; i++) {
            next[0][i] = P[i];
            dp[0][i] = V[i];
        }
        for (int i = 1; i <= 60; i++) {
            for (int j = 0; j < N; j++) {
                next[i][j] = next[i - 1][next[i - 1][j]];
                // j から 2^{i-1} 手（前半区間）
                // j から 2^{i-1} 行った先（next[i - 1][j]）から 2^{i-1} 手（後半区間）
                dp[i][j] = op(dp[i - 1][j], dp[i - 1][next[i - 1][j]]);
            }
        }
    }

    S get(int start, long long K) {
        S ret = e();
        int cur = start;
        for (int b = 0; b <= 60; b++) {
            if (K & (1LL << b)) {
                ret = op(ret, dp[b][cur]);
                cur = next[b][cur];
            }
        }
        return ret;
    }

public:
    std::vector<std::vector<int>> next;
    std::vector<std::vector<S>> dp;
};


#endif // Doubling_HPP