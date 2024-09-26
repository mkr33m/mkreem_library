#ifndef RangeSet_HPP
#define RangeSet_HPP

#include <vector>
#include <set>
#include <limits>
#include <iostream>

#include "../Others/macros.hpp"

/**
 * @brief 閉区間を set で管理する
 */
template <typename T>
class RangeSet{
private:
    std::set<std::pair<T, T>> s;
    /**
     * @param sum RangeSet 内の要素数
     */
    T sum;
    T TINF = std::numeric_limits<T>::max() / 2;

public:
    RangeSet() : sum(T(0)){
        s.emplace(TINF, TINF);
        s.emplace(-TINF, -TINF);
    }

    /**
     * @brief 区間 [l, r] が完全に含まれているかどうかを返す
     */
    bool covered(const T l, const T r){
        assert(l <= r);
        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));
        return ((itr->first <= l) && (r <= itr->second));
    }

    /**
     * @brief x が含まれているかどうかを返す
     */
    bool contained(const T x){
        auto itr = std::prev(s.lower_bound({x + 1, x + 1}));
        return ((itr->first <= x) && (x <= itr->second));
    }

    /**
     * @brief 区間 [l, r] を包含する区間があればその区間を返し、なければ [-INF, -INF] を返す
     */
    std::pair<T, T> covered_by(const T l, const T r){
        assert(l <= r);
        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));
        if(itr->first <= l && r <= itr->second) return *itr;
        return {-TINF, -TINF};
    }

    std::pair<T, T> covered_by(const T x){
        return covered_by(x, x);
    }

    /**
     * @brief 区間 [l, r] を挿入し、増分を返す
     */
    T insert(T l, T r){
        assert(l <= r);
        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));

        if(itr->first <= l && r <= itr->second) return T(0); // [l, r] がすでに完全に含まれている
        /**
         * @param sum_erased 消した区間の幅の合計
         */
        T sum_erased = T(0);
        if(itr->first <= l && l <= itr->second+1){ // l 側で、区間 itr をマージできる場合
            l = itr->first;
            sum_erased += itr->second - itr->first + 1;
            itr = s.erase(itr);
        }
        else{ // できなかったら、itr を次の区間に進める
            itr = std::next(itr);
        }
        while(r > itr->second){
            sum_erased += itr->second - itr->first + 1;
            itr = s.erase(itr);
        }
        if(itr->first <= r + 1 && r <= itr->second){ // r 側で、区間 itr をマージできる場合
            sum_erased += itr->second - itr->first + 1;
            r = itr->second;
            s.erase(itr);
        }
        s.emplace(l, r);
        sum += r - l + 1 - sum_erased;
        return r - l + 1 - sum_erased;
    }

    T insert(const T x){
        return insert(x, x);
    }

    /**
     * @brief 区間 [l, r] を削除し、減分を返す
     */
    T erase(const T l, const T r){
        assert(l <= r);
        auto itr = std::prev(s.lower_bound({l + 1, l + 1}));
        if(itr->first <= l && r <= itr->second){ // [l, r] が、1 つの区間に包含されている
        // はみ出した区間
            if(itr->first < l) s.emplace(itr->first, l - 1);
            if(r < itr->second) s.emplace(r+1, itr->second);
            s.erase(itr);
            sum -= r - l + 1;
            return r - l+1;
        }

        T res = T(0);
        if(itr->first <= l && l <= itr->second){ // l 側で、区間 itr を消せる場合
            res += itr->second - l + 1;
            // はみ出した区間
            if(itr->first < l) s.emplace(itr->first, l - 1);
            itr = s.erase(itr);
        }
        else{
            itr = std::next(itr);
        }
        while(itr->second <= r){
            res += itr->second - itr->first + 1;
            itr = s.erase(itr);
        }
        if(itr->first <= r && r <= itr->second){ // r 側で、区間 itr を消せる場合
            res += r - itr->first + 1;
            // はみ出した区間
            if(r < itr->second) s.emplace(r + 1, itr->second);
            s.erase(itr);
        }
        sum -= res;
        return res;
    }

    T erase(const T x){
        return erase(x, x);
    }

    /**
     * @brief 区間の数を返す
     */
    int size() const{
        return (int)s.size() - 2;
    }

    /**
     * x 以上で含まれてない最小の要素は
     * ・x が含まれていない：x
     * ・x が含まれている：x を含む区間の末端に 1 加えたもの
     */
    T mex(const T x = 0) const{
        auto itr = std::prev(s.lower_bound({x + 1, x + 1}));
        if(itr->first <= x && x <= itr->second) return itr->second + 1;
        else return x;
    }

    // @brief RangeSet 内の要素数を返す
    T sum_all() const{
        return sum;
    }

    // @brief 全区間を保持した set を返す
    std::set<std::pair<T, T>> get() const{
		std::set<std::pair<T, T>> res;
		for(auto& interval : s) {
			if(std::abs(interval.first) == TINF) continue;
			res.emplace(interval.first, interval.second);
		}
		return res;
	}

    void output() const{
        std::cout << "RangeSet:";
        for(auto& interval : s){
            if(interval.first == -INF || interval.second == INF) continue;
            std::cout << "[" << interval.first << "," << interval.second << "]";
        }
        std::cout << '\n';
    }
};

#endif // RangeSet_HPP