#ifndef ZETA_MOBIUS_HPP
#define ZETA_MOBIUS_HPP

#include <vector>
#include <bit>

template <typename T>
/**
 * @brief 下位集合方向の高速ゼータ変換
 * 下 i 桁が S の下位集合で、下 i 桁以外が S に一致
 * F_{i+1}[S] = F_{i}[S] + F_{i}[S - (1 << i)]
 * @remark F_{i+1}[S - (1 << i)] == F_{i}[S - (1 << i)] だから、in-place に更新可能
 */
void subset_zeta_transform(std::vector<T>& F) {
    int N = 0, sz = (int)F.size();
    assert(sz && (sz & (sz - 1)) == 0);
    while ((1 << N) < sz) {
        N++;
    }
    for (int i = 0; i < N; i++) {
        for (int S = 0; S < (1 << N); S++) {
            if (S & (1 << i)) {
                F[S] = F[S] + F[S - (1 << i)];
            }
        }
    }
}

template <typename T>
/**
 * @brief 下位集合方向の高速メビウス変換
 * 下 i 桁が S の下位集合で、下 i 桁以外が S に一致
 * F_{i+1}[S] = F_{i}[S] - F_{i}[S - (1 << i)]
 */
void subset_mobius_transform(std::vector<T>& F) {
    int N = 0, sz = (int)F.size();
    assert(sz && (sz & (sz - 1)) == 0);
    while ((1 << N) < sz) {
        N++;
    }
    for (int i = 0; i < N; i++) {
        for (int S = 0; S < (1 << N); S++) {
            if (S & (1 << i)) {
                F[S] = F[S] - F[S - (1 << i)];
            }
        }
    }
}

template <typename T>
/**
 * @brief 上位集合方向の高速ゼータ変換
 * 下 i 桁が S の上位集合で、下 i 桁以外が S に一致
 * F_{i+1}[S] = F_{i}[S] + F_{i}[S + (1 << i)]
 * @remark F_{i+1}[S + (1 << i)] == F_{i}[S + (1 << i)] だから、in-place に更新可能
 */
void superset_zeta_transform(std::vector<T>& F) {
    int N = 0, sz = (int)F.size();
    assert(sz && (sz & (sz - 1)) == 0);
    while ((1 << N) < sz) {
        N++;
    }
    for (int i = 0; i < N; i++) {
        for (int S = 0; S < (1 << N); S++) {
            if (!(S & (1 << i))) {
                F[S] = F[S] + F[S + (1 << i)];
            }
        }
    }
}

template <typename T>
/**
 * @brief 上位集合方向の高速メビウス変換
 * 下 i 桁が S の上位集合で、下 i 桁以外が S に一致
 * F_{i+1}[S] = F_{i}[S] - F_{i}[S + (1 << i)]
 */
void superset_mobius_transform(std::vector<T>& F) {
    int N = 0, sz = (int)F.size();
    assert(sz && (sz & (sz - 1)) == 0);
    while ((1 << N) < sz) {
        N++;
    }
    for (int i = 0; i < N; i++) {
        for (int S = 0; S < (1 << N); S++) {
            if (!(S & (1 << i))) {
                F[S] = F[S] - F[S + (1 << i)];
            }
        }
    }
} 


#endif // ZETA_MOBIUS_HPP