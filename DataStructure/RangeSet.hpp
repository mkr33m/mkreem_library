#ifndef RangeSet_HPP
#define RangeSet_HPP

/*
verify
・https://atcoder.jp/contests/abc330/tasks/abc330_e
*/

#include <vector>
#include <set>
#include <limits>
#include <iostream>

#include "../Others/macros.hpp"

/**
 * @brief 開区間を set で管理する
 */
template <typename T>
struct RangeSet {
private:
    std::set<std::pair<T, T>> intervals;
    T sum_width;
    T TINF = std::numeric_limits<T>::max() / 2;

public:
    RangeSet() : sum_width(T(0)){
        intervals.emplace(TINF, TINF); // 番兵
        intervals.emplace(-TINF, -TINF); // 番兵
    }

    /**
     * @brief [l, r) が完全に含まれているかどうかを返す
     * @param itv 左端が l 以下であるような区間のうち、最も右側にあるもの
     */
    bool covered(const T& l, const T& r){
        assert(l <= r);
        if(l == r){
            return true;
        }
        auto itv = std::prev(intervals.upper_bound(std::make_pair(l, TINF)));
        return (itv->first <= l) && (r <= itv->second);
    }

    /**
     * @brief x が含まれているかどうかを返す
     */
    bool contained(const T& x){
        return covered(x, x + 1);
    }

    /**
     * @brief [l, r) を包含する区間があればその区間を返し、なければ [-INF, -INF) を返す
     */
    std::pair<T, T> covered_by(const T& l, const T& r){
        assert(l <= r);
        if(l == r){
            return std::make_pair(-TINF, -TINF);
        }
        auto itv = std::prev(intervals.upper_bound(std::make_pair(l, TINF)));
        if(itv->first <= l && r <= itv->second){
            return *itv;
        }
        return std::make_pair(-TINF, -TINF);
    }

    std::pair<T, T> covered_by(const T& x){
        return covered_by(x, x + 1);
    }

    /**
     * @brief [l, r) を挿入し、区間幅の増分を返す
     * l と r それぞれで、l, r を含む区間とマージできるかどうかを見る
     */
    T insert(T l, T r){
        assert(l <= r);
        if(l == r){
            return T(0);
        }
        auto itv = std::prev(intervals.upper_bound(std::make_pair(l, TINF)));

        if(itv->first <= l && r <= itv->second) return T(0); // [l, r) がすでに包含されている場合は例外処理
        /**
         * @param sum_erased_width 消した区間の幅の合計
         */
        T sum_erased_width = T(0);
        if(itv->first <= l && l <= itv->second){ // l 側で、区間 itv をマージできる場合
            l = itv->first;
            sum_erased_width += itv->second - itv->first;
            itv = intervals.erase(itv);
        } else{ // できなかったら、itr を次の区間に進める
            itv = std::next(itv);
        }
        while(r > itv->second){ // 現時点で [l, r) に包含される区間は全て消す
            sum_erased_width += itv->second - itv->first;
            itv = intervals.erase(itv);
        }
        if(itv->first <= r && r <= itv->second){ // r 側で、区間 itv をマージできる場合
            sum_erased_width += itv->second - itv->first;
            r = itv->second;
            intervals.erase(itv);
        }
        intervals.emplace(l, r);
        sum_width += r - l - sum_erased_width;
        return r - l - sum_erased_width;
    }

    T insert(const T x){
        return insert(x, x + 1);
    }

    /**
     * @brief [l, r) を削除し、区間幅の減分を返す
     */
    T erase(const T& l, const T& r){
        assert(l <= r);
        if(l == r){
            return T(0);
        }
        auto itv = std::prev(intervals.upper_bound(std::make_pair(l, TINF)));
        if(itv->first <= l && r <= itv->second){ // [l, r] が itv に包含されている場合
            if(itv->first < l){ // l 側での itv のはみだし部分が存在する
                intervals.emplace(itv->first, l);
            }
            if(r < itv->second){ // r 側での itv のはみだし部分が存在する
                intervals.emplace(r, itv->second);
            }
            intervals.erase(itv);
            sum_width -= r - l;
            return r - l;
        }

        T sum_erased_width = T(0);
        if(itv->first <= l && l < itv->second){ // [l, r) が、l 側で itv と共通部分を持つ場合
            sum_erased_width += itv->second - l;
            if(itv->first < l){ // l 側での itv のはみだし部分が存在する
                intervals.emplace(itv->first, l);
            }
            itv = intervals.erase(itv);
        } else{
            itv = std::next(itv);
        }
        while(itv->second <= r){
            sum_erased_width += itv->second - itv->first;
            itv = intervals.erase(itv);
        }
        if(itv->first <= r && r < itv->second){ // [l, r) が、l 側で itv と共通部分を持つ場合
            sum_erased_width += r - itv->first;
            if(r < itv->second){ // r 側での itv のはみだし部分が存在する
                intervals.emplace(r, itv->second);
            }
            intervals.erase(itv);
        }
        sum_width -= sum_erased_width;
        return sum_erased_width;
    }

    T erase(const T& x){
        return erase(x, x + 1);
    }

    /**
     * @brief 区間の数を返す
     */
    int size() const {
        return (int)intervals.size() - 2;
    }

    /**
     * x 以上で含まれてない最小の要素は
     * ・x が含まれていない：x
     * 『・x が含まれている：x を含む区間の末端に 1 加えたもの』
     */
    T mex(const T& x = 0) const {
        auto itv = std::prev(intervals.upper_bound({x, TINF}));
        if(itv->first <= x && x < itv->second){
            return itv->second;
        }
        return x;
    }

    /**
     * @brief 区間幅の合計を返す
     */
    T sum_all() const {
        return sum_width;
    }

    /**
     * @brief 全区間を保持した set を返す
     */
    std::set<std::pair<T, T>> get_intervals() const {
		std::set<std::pair<T, T>> res;
		for(const auto& interval : intervals) {
			if(std::abs(interval.first) == TINF) continue;
			res.emplace(interval.first, interval.second);
		}
		return res;
	}

    void output() const {
        for(const auto& interval : intervals){
            if(interval.first == -INF || interval.second == INF) continue;
            std::cout << "[" << interval.first << ", " << interval.second << ")" << '\n';
        }
    }
};

#endif // RangeSet_HPP