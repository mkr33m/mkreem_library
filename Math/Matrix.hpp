#ifndef Matrix_HPP
#define Matrix_HPP

#include <cassert>
#include <vector>

// 行列の構造体
template <typename Ops>
struct Matrix {
private:
    using T = typename Ops::T;
    int N, M;
    std::vector<std::vector<T>> val;

public:
    Matrix() : N(0), M(0) {}
    Matrix(int N, int M) : N(N), M(M), val(N, std::vector<T>(M, Ops::zero())) {}
    static Matrix identity(int N) {
        Matrix<Ops> I(N, N);
        for (int i = 0; i < N; i++) {
            I.val[i][i] = Ops::one();
        }
        return I;
    }
    int rows() const { return N; }
    int cols() const { return M; }
    void set(int i, int j, T v) {
        assert(0 <= i && i < N);
        assert(0 <= j && j < M);
        val[i][j] = v;
    }
    T get(int i, int j) const {
        assert(0 <= i && i < N);
        assert(0 <= j && j < M);
        return val[i][j];
    }
    Matrix operator*(const Matrix& other) const {
        assert(M == other.N);
        Matrix res(N, other.M);
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < M; k++) {
                T aik = val[i][k];
                for (int j = 0; j < other.M; j++) {
                    res.val[i][j] = Ops::add(res.val[i][j], Ops::mul(aik, other.val[k][j]));
                }
            }
        }
        return res;
    }
    Matrix& operator*=(const Matrix& other) {
        *this = (*this) * other;
        return *this;
    }
    Matrix operator^(long long n) const {
        assert(N == M);
        assert(n >= 0);
        Matrix base = *this;
        Matrix res = Matrix::identity(N);
        while (n > 0) {
            if (n & 1) {
                res *= base;
            }
            base = base * base;
            n >>= 1;
        }
        return res;
    }
    Matrix& operator^=(long long n) {
        *this = (*this) ^ n;
        return *this;
    }
};

// 行列×ベクトル
template <typename Ops>
std::vector<typename Ops::T> mat_mul_vec(const Matrix<Ops>& A, const std::vector<typename Ops::T>& x) {
    using T = typename Ops::T;
    assert(A.cols() == (int)x.size());
    std::vector<T> y(A.rows(), Ops::zero());
    for (int i = 0; i < A.rows(); i++) {
        T res = Ops::zero();
        for (int k = 0; k < A.cols(); k++) {
            res = Ops::add(res, Ops::mul(A.get(i, k), x[k]));
        }
        y[i] = res;
    }
    return y;
}

#endif // Matrix_HPP