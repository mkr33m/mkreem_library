#ifndef Matrix_HPP
#define Matrix_HPP

#include <cassert>
#include <vector>

// 行列の構造体
template <typename Ops>
struct Matrix {
    using T = typename Ops::T;
    int N, M;
    std::vector<std::vector<T>> mat;

    Matrix() : N(0), M(0) {}
    Matrix(int N, int M) : N(N), M(M), mat(N, std::vector<T>(M, Ops::zero())) {}
    static Matrix identity(int N) {
        Matrix I(N, N);
        for (int i = 0; i < N; i++) {
            I.mat[i][i] = Ops::one();
        }
        return I;
    }
};

// 行列×行列
template <typename Ops>
Matrix<Ops> mat_mul(const Matrix<Ops>& A, const Matrix<Ops>& B) {
    using T = typename Ops::T;
    assert(A.M == B.N);
    Matrix<Ops> C(A.N, B.M);

    for (int i = 0; i < A.N; i++) {
        for (int k = 0; k < A.M; k++) {
            T aik = A.mat[i][k];
            for (int j = 0; j < B.M; j++) {
                C.mat[i][j] = Ops::add(C.mat[i][j], Ops::mul(aik, B.mat[k][j]));
            }
        }
    }
    return C;
}

// 行列×ベクトル
template <typename Ops>
std::vector<typename Ops::T> mat_mul_vec(const Matrix<Ops>& A, const std::vector<typename Ops::T>& x) {
    using T = typename Ops::T;
    assert(A.M == (int)x.size());
    std::vector<T> y(A.N, Ops::zero());
    for (int i = 0; i < A.N; i++) {
        T res = Ops::zero();
        for (int k = 0; k < (int)x.size(); k++) {
            res = Ops::add(res, Ops::mul(A.mat[i][k], x[k]));
        }
        y[i] = res;
    }
    return y;
}

// 行列累乗
template <typename Ops>
Matrix<Ops> mat_pow (Matrix<Ops> A, long long n) {
    assert(A.N == A.M);
    Matrix<Ops> res = Matrix<Ops>::identity(A.N);
    while (n > 0) {
        if (n & 1) {
            res = mat_mul(res, A);
        }
        A = mat_mul(A, A);
        n >>= 1;
    }
    return res;
}

#endif // Matrix_HPP