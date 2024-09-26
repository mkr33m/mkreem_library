#ifndef ZobristHash_HPP
#define ZobristHash_HPP

#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <random>

#include "macros.hpp"

template <typename T>
struct ZobristHash {
private:
    std::map<T, int> hash;

public:
    /**
     * @brief 各要素に対して、ハッシュ値を割り当てる
     * @remark 複数の vector を同時に渡すことができる
     */
    template <typename... Args>
    ZobristHash(const Args&... vecs){
        std::vector<T> merged;

        (merged.insert(merged.end(), vecs.begin(), vecs.end()), ...);

        std::sort(merged.begin(), merged.end());
        merged.erase(std::unique(merged.begin(), merged.end()), merged.end());

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> ran(0, std::numeric_limits<int>::max());

        for(const auto& e : merged){
            hash[e] = ran(mt);
        }
    }

    /**
     * @brief 引数に割り当てられたハッシュ値を返す
     */
    int val(const T& e){
        assert(hash.find(e) != hash.end());
        return hash[e];
    }

    /**
     * @brief 各要素のハッシュ値の XOR を取る ver
     * @remark set として（multiset ではない！）の一致判定を O(1) で行うことができる
     * @return 引数で渡された vector<T> vec の、各要素のハッシュ値の累積XORを取ったもの
     */
    std::vector<ll> xor_hash(const std::vector<T>& vec){
        int N = vec.size();
        std::vector<ll> hashed_vec(N + 1);
        std::unordered_set<T> memo;

        for(int i = 0; i < N; i++){
            if(memo.find(vec[i]) == memo.end()){
                memo.insert(vec[i]);
                hashed_vec[i + 1] = hashed_vec[i] ^ val(vec[i]);
            } else{
                hashed_vec[i + 1] = hashed_vec[i];
            }
        }

        return hashed_vec;
    }

    /**
     * @brief 各要素のハッシュ値の累積和をとる ver
     * @remark multiset としての一致判定を O(1) で行うことができる
     * @return 引数で渡された vector<T> vec の、各要素のハッシュ値の累積和を取ったもの
     */
    std::vector<ll> pref_hash(const std::vector<T>& vec){
        int N = vec.size();
        std::vector<ll> hashed_vec(N + 1);

        for(int i = 0; i < N; i++){
            hashed_vec[i + 1] = hashed_vec[i] + val(vec[i]);
        }

        return hashed_vec;
    }
};

#endif // ZobristHash_HPP