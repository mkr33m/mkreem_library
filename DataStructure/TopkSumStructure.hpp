#ifndef TopkSumStructure_HPP
#define TopkSumStructure_HPP

#include <cassert>
#include <queue>
#include <vector>

template< typename T, typename Compare = std::less<T>, typename RCompare = std::greater<T>>
struct TopkSumStructure {
private:
    int k;
    T sum_;
    // lazy は、予約（遅延）削除用
    std::priority_queue<T, std::vector<T>, Compare> L, lazyL;
    std::priority_queue<T, std::vector<T>, RCompare> R, lazyR;

    void modify() {
        // 遅延削除用の pq を参照して、元の pq から要素を削除
        while (!L.empty() && !lazyL.empty() && L.top() == lazyL.top()) {
            L.pop();
            lazyL.pop();
        }
        while (!R.empty() && !lazyR.empty() && R.top() == lazyR.top()) {
            R.pop();
            lazyR.pop();
        }
        // R->L の要素移動（mofify）
        while ((int)L.size() - (int)lazyL.size() < k && !R.empty()) {
            T p = R.top(); R.pop(); // これを移すが、まず削除済みかどうかを確認
            if (!lazyR.empty() && lazyR.top() == p) {
                lazyR.pop();
            } else { // p は削除されていないので、L に移動
                sum_ += p;
                L.emplace(p);
            }
        }
        // L->R の要素移動（modify）
        while ((int)L.size() - (int)lazyL.size() > k) {
            T p = L.top(); L.pop(); // これを移す
            if (!lazyL.empty() && lazyL.top() == p) {
                lazyL.pop();
            } else { // p は削除されていないので、R に移動
                sum_ -= p;
                R.emplace(p);
            }
        }
    }

public:
    TopkSumStructure(int k) : k(k), sum_(T(0)) {}
    /**
     * @brief 要素 x を追加
     */
    void insert(T x) {
        L.emplace(x);
        sum_ += x;
        modify();
    }
    /**
     * @brief 要素 x を削除
     * @remark 多重集合内に x が存在しないと壊れる
     */
    void erase(T x) {
        assert(size() > 0);
        // L の top が x なら、（遅延させずに）素直に削除
        if (!L.empty() && L.top() == x) {
            sum_ -= x;
            L.pop();
        // そうでなくて、x が L に属している（L.top() > x）なら、遅延削除
        } else if (!L.empty() && RCompare()(L.top(), x)) {
            sum_ -= x;
            lazyL.emplace(x);
        // そうでないなら、x は R 側の要素であり、遅延削除
        } else {
            lazyR.emplace(x);
        }
        modify();
    }
    /**
     * @brief 上位 k 個の和を返す
     */
    T sum() const {
        return sum_;
    }
    /**
     * @brief k を指定しなおす
     */
    void set_k(int k_) {
        k = k_;
        modify();
    }
    /**
     * @brief 現在の k の値を返す
     */
    int get_k() const {
        return k;
    }
    /**
     * @brief 現在の要素数を返す
     */
    int size() const {
        return (int)L.size() - (int)lazyL.size() + (int)R.size() - (int)lazyR.size();
    }
};

template <typename T>
using MinTopkSum = TopkSumStructure<T, std::less<T>, std::greater<T>>;

template <typename T>
using MaxTopkSum = TopkSumStructure<T, std::greater<T>, std::less<T>>;

#endif // TopkSumStructure_HPP