#ifndef cum1D_HPP
#define cum1D_HPP

#include <vector>

template <typename M>
struct cum1D {
private:
    using T = typename M::S;
    int N;
    std::vector<T> prefix_prod, suffix_prod;

public:
    cum1D() = default;
    cum1D(const std::vector<T>& vec) : N(vec.size()){
        prefix_prod.resize(N + 1, M::e());
        suffix_prod.resize(N + 1, M::e());

        for(int i = 0; i < N; i++){
            prefix_prod[i + 1] = M::op(prefix_prod[i], vec[i]);
        }
        for(int i = N - 1; i >= 0; i--){
            suffix_prod[i] = M::op(vec[i], suffix_prod[i + 1]);
        }
    }

    /**
     * @brief [0, i) の総積を返却
     */
    T pref(const int& i) const {
        return prefix_prod[i];
    }

    /**
     * @brief [i, N) の総積を返却
     */
    T suff(const int& i) const {
        return suffix_prod[i];
    }

    /**
     * @brief [l, r) を除いた総積を返却
     */
    T prod_exclude(const int& l, const int& r) const {
        return M::op(prefix_prod[l], suffix_prod[r]);
    }

    /**
     * @brief i 番目の要素を除いた総積を返却
     */
    T prod_exclude(const int& i) const {
        return M::op(prefix_prod[i], suffix_prod[i + 1]);
    }

    /**
     * @brief [l, r) の総積を返却
     * @remark 逆元が存在する二項演算である必要がある
     */
    T prod(const int& l, const int& r) const {
        return M::op(prefix_prod[r], M::inv(prefix_prod[l]));
    }
};

#endif // cum1D_HPP