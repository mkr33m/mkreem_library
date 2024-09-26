#ifndef UnionFind_HPP
#define UnionFind_HPP

#include <vector>
#include <algorithm>

struct UnionFind {
private:
    // @param data 各ノードについて、所属する連結成分の根の頂点番号を保持（根自身は、「-（根が管轄する集合のノード数）」を保持）。
    int N;
    std::vector<int> data;

public:
    UnionFind() = default;
    UnionFind(int N) : N(N), data(N, -1) {}

    /**
     * @brief 頂点 x が所属する連結成分の根を返す。
     */
    int root(int x){
        /**
         * if(data[x] < 0) return x;
         * return data[x] = root(data[x]); // 経路圧縮
         */
        static std::vector<int> tmp;
        while(data[x] >= 0){ // 根まで辿っていく
            tmp.push_back(x);
            x = data[x];
        }
        while(!tmp.empty()){ // 経路圧縮
            data[tmp.back()] = x;
            tmp.pop_back();
        }
        return x;
    }

    /**
     * @brief 同じ集合に属しているかどうかを判定。
     */
    bool same(int x, int y){
        return root(x) == root(y);
    }

    /**
     * @brief 同じ集合にする。
     */
    bool merge(int x, int y){
        x = root(x), y = root(y); // <- 根

        if(x == y) return false; // 根が同じなら、既に同じ集合
        if(data[x] > data[y]) std::swap(x, y); // マージテク
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    // @brief xが属している集合のノード数を返す
    int size(int x){
        return -data[root(x)];
    }

    /**
     * @brief 集合構造の詳細を取得
     */
    std::vector<std::vector<int>> groups(){
        std::vector<std::vector<int>> res(N);
        for(int i = 0; i < N; i++){
            res[root(i)].push_back(i);
        }
        res.erase(std::remove_if(res.begin(), res.end(), [](const std::vector<int>& vec){ return vec.empty(); }), res.end());
        return res;
    }
};

/**
 * @param T モノイド（連結成分が持つ情報）の型
 */
template <typename T>
using merge_function = void(*)(T& parent_data, T child_data);

template <typename T, merge_function<T> f>
struct UF_ComponentSum : UnionFind {
private:
    std::vector<T> sum_;

public:
    UF_ComponentSum() : UF_ComponentSum(0) {}
    UF_ComponentSum(int N, const T& init_value = T{}) : UF_ComponentSum(std::vector<T>(N, init_value)) {}
    UF_ComponentSum(const std::vector<T>& init_values) : UnionFind(init_values.size()), sum_(init_values) {}

    bool merge(int x, int y){
        x = root(x), y = root(y); // <- 根
        bool res = UnionFind::merge(x, y);
        if(res){
            if(root(x) == y) std::swap(x, y); // マージ後の連結成分の根が x となるよう調整
            f(sum_[x], std::move(sum_[y]));
        }
        return res;
    }

    const T& sum(int x){
        return sum_[root(x)];
    }
};

#endif // UnionFind_HPP