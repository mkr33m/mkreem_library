#ifndef Mo_HPP
#define Mo_HPP

#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>

/**
 * ソート -> ソート順に訪問して答えを求めていくの流れ。これらを全て solve に担わせる。
 * 答えの出力の仕方としては、output 関数に任せることにする。
 * 答えを求めていくときの add, del 関数に関しては、差分更新するものの型の種類や数を問題に応じて対応できるように、ラムダ関数を使う。
 * ラムダ関数の & によるキャプチャ参照を利用する。
 * main 関数内で生成された add, del オブジェクトは、キャプチャされた変数への参照を保持している。これを Mo 構造体のオブジェクト作成時に引数として渡して（add, del オブジェクトがコピーされて）も、（コピー先で）この参照が失われることはない。
 */
template <typename Add, typename Del> // ここのテンプレート仮引数は、実際の呼び出し式から推論される。柔軟性に富んで嬉しい！
struct Mo {

    Mo(int N, const Add& add, const Del& del) : N(N), add(add), del(del) {}

    void add_query(int l, int r, int id) {
        queries.push_back({l, r, id});
    };

    /**
     * どうして Out&& なのか？
     * 
     * T&（が束縛できる値）：左辺値のみ -> これに右辺値であるラムダ関数を束縛させることは不可能
     * const T&：左辺値 + const 右辺値
     * T&&：右辺値のみ
     * （右辺値 == 一時オブジェクト）
     * 
     * ラムダ関数は右辺値であるから、const T& or T&& が選択肢となる。
     * デフォルトのラムダ関数はキャプチャした変数について、operator() を const 扱いする。mutable を付けることで operator() は const ではなくなるが、そのため const T& には渡せない。
     * T&& は、右辺値ならムーブ（完全に所有権を移すと考えてよい。所有元は破棄しても OK）、左辺値なら参照として受け取ることができる。さらに、mutable ラムダも渡すことができる。
     */
    template <typename Out>
    void solve(Out&& output) {
        if (queries.empty()) {
            return;
        }
        const int Q = (int)queries.size();
        // sqrt(N) で分割するより sqrt(Q) で分割した方が高速らしい
        const int block = std::max(1, int(N / std::sqrt(Q)));

        std::sort(queries.begin(), queries.end(), [block](const query& x, const query& y) {
            if (x.l / block != y.l / block) {
                return x.l < y.l;
            }
            int x_block = x.l / block;
            // 偶数区間は昇順、奇数区間は降順
            return (x_block & 1) ? (x.r > y.r) :(x.r < y.r);
        });

        int cur_l = 0, cur_r = 0;
        for (const query& q : queries) {
            while (cur_l > q.l) {
                cur_l--; add(cur_l);
            }
            while (cur_l < q.l) {
                del(cur_l); cur_l++;
            }
            while (cur_r > q.r) {
                cur_r--; del(cur_r);
            }
            while (cur_r < q.r) {
                add(cur_r); cur_r++;
            }

            output(q.id);
        }
    }

private:
    int N;
    Add add;
    Del del;
    struct query {
        int l, r, id;
    };
    std::vector<query> queries;
};

#endif // Mo_HPP