#ifndef cum2D_HPP
#define cum2D_HPP

#include <vector>

/**
 * @remark 逆元が存在する二項演算である必要がある
 */
template <typename M>
struct cum2D {
private:
    using T = typename M::S;
    int H, W;
    std::vector<std::vector<T>> prefix_prod, suffix_prod;

public:
    cum2D() = default;
    cum2D(const std::vector<std::vector<T>>& grid) : H(grid.size()), W(grid[0].size()) {
        prefix_prod.resize(H + 1, std::vector<T>(W + 1, M::e()));
        suffix_prod.resize(H + 1, std::vector<T>(W + 1, M::e()));
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                prefix_prod[i + 1][j + 1] = M::op( M::op( M::op( grid[i][j], prefix_prod[i][j + 1] ), prefix_prod[i + 1][j] ), M::inv(prefix_prod[i][j]) );
            }
        }
        for(int i = H - 1; i >= 0; i--){
            for(int j = W - 1; j >= 0; j--){
                suffix_prod[i][j] = M::op( M::op( M::op( grid[i][j], suffix_prod[i + 1][j] ), suffix_prod[i][j + 1] ), M::inv(suffix_prod[i + 1][j + 1]) );
            }
        }
    }

    /**
     * @brief [i1, j1) * [i2, j2) の総積を取得する
     */
    T prod(const int& i1, const int& j1, const int& i2, const int& j2){
        if(i2 <= i1 || j2 <= j1){
            return 0;
        }
        return M::op( M::op( M::op( prefix_prod[i2][j2], M::inv(prefix_prod[i1][j2]) ), M::inv(prefix_prod[i2][j1]) ), prefix_prod[i1][j1] );
    }

    T pref(const int& i, const int& j){
        return prefix_prod[i][j];
    }

    T suff(const int& i, const int& j){
        return suffix_prod[i][j];
    }
};


#endif  // cum2D_HPP