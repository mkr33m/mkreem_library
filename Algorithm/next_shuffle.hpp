#ifndef next_shuffle_HPP
#define next_shuffle_HPP

#include <vector>
#include <limits>
#include <algorithm>

template <typename T>
/**
 * @brief (K,N - K)-shuffle である0, 1, ..., N - 1 の置換 A を、辞書順で列挙する
 */
bool next_shuffle(std::vector<T>& vec, const int& K){
    int N = vec.size();
    if(N <= K){
        return false;
    }

    // 前 K 項 := L
    // 後ろN - K項 := R
    auto left = vec.begin();
    auto right = vec.begin() + K;
    T R_max = *std::max_element(right, vec.end());
    T tmp = (std::numeric_limits<T>::min)();
    /**
     * @param i L の要素の中で、R の要素の最大値よりも小さいもののうち、最大のもののイテレータ (*i := L_(i))
     */
    auto tmpi = left, i = right;
    while(tmpi != right){
        if(tmp <= *tmpi && *tmpi < R_max){
            tmp = *tmpi;
            i = tmpi;
        }
        tmpi++;
    }
    if(i == right){
        std::sort(vec.begin(), vec.end());
        return false;
    }

    /**
     * @param j R の要素の中で、L_(i) よりも大きいもののうち、最小のもののイテレータ (*j := R_(j))
     */
    tmp = (std::numeric_limits<T>::max)();
    auto tmpj = right, j = vec.end();
    while(tmpj != vec.end()){
        if(tmp >= *tmpj && *tmpj > *i){
            tmp = *tmpj;
            j = tmpj;
        }
        tmpj++;
    }

    std::iter_swap(i, j); // L_(i)とR_(j)をswap
    i++, j++;
    // やりたいこと：L_(i + 1)～L_(K - 1)(:= X) と R_(j + 1)～R_(N - K - 1)(:= Y) を接続し、R_(j + 1) が先頭に来るように回転する
    int X_len = K - std::distance(left, i);
    int Y_len = N - K - std::distance(right, j);
    int swap_len = std::min(X_len, Y_len);
    // X の末尾 swap_len 項と Y の末尾 swap_len 項を swap する
    std::swap_ranges(right - swap_len, right, j);
    if(swap_len == X_len){
        std::rotate(j, j + swap_len, vec.end());
    }
    else{
        std::rotate(i, right - swap_len, right);
    }

    return true;
}

#endif // next_shuffle_HPP