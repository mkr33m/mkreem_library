#ifndef Doubling_HPP
#define Doubling_HPP

#include <vector>

template<class S = void, auto op = nullptr, auto e = nullptr>
struct Doubling;

template <auto op, auto e>
struct Doubling<void, op, e> {
    int N;
    std::vector<std::vector<int>> next;

    Doubling(const std::vector<int>& P) : N((int)P.size()) {
        next.assign(60, std::vector<int>(N));
        for (int i = 0; i < N; i++) {
            next[0][i] = P[i];
        }
        for (int b = 1; b < 60; b++) {
            for (int i = 0; i < N; i++) {
                next[b][i] = next[b - 1][ next[b - 1][i] ];
            }
        }
    }

    int to(int start, long long K) {
        int pos = start;
        for (int b = 0; b < 60; b++) {
            if (K & (1LL << b)) {
                pos = next[b][pos];
            }
        }
        return pos;
    }
};

template <typename S, auto op, auto e>
struct Doubling {
    int N;
    std::vector<std::vector<int>> next;
    std::vector<std::vector<S>> db;

    Doubling(const std::vector<int>& P, const std::vector<S>& V) : N((int)P.size()) {
        next.assign(60, std::vector<int>(N));
        db.assign(60, std::vector<S>(N)); // db[i][j] := j から 2^i 手進んだときの積
        for (int i = 0; i < N; i++) {
            next[0][i] = P[i];
            db[0][i] = V[i];
        }
        for (int i = 1; i < 60; i++) {
            for (int j = 0; j < N; j++) {
                next[i][j] = next[i - 1][next[i - 1][j]];
                // j から 2^{i-1} 手（前半区間）
                // j から 2^{i-1} 行った先（next[i - 1][j]）から 2^{i-1} 手（後半区間）
                db[i][j] = op(db[i - 1][j], db[i - 1][next[i - 1][j]]);
            }
        }
    }

    /**
     * @brief start から（start を含めて）K 頂点踏んだとき、踏んだ頂点の値の合計値を返す
     */
    S prod(int start, long long K) {
        S ret = e();
        int pos = start;
        for (int b = 0; b < 60; b++) {
            if (K & (1LL << b)) {
                ret = op(ret, db[b][pos]);
                pos = next[b][pos];
            }
        }
        return ret;
    }

    /**
     * @brief start から K 手進んだ先の頂点番号を返す
     */
    int to(int start, long long K) {
        int pos = start;
        for (int b = 0; b < 60; b++) {
            if (K & (1LL << b)) {
                pos = next[b][pos];
            }
        }
        return pos;
    }
};


#endif // Doubling_HPP