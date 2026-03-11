#ifndef Mo_HPP
#define Mo_HPP

#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>

template <typename Add, typename Del> // ここのテンプレート仮引数は、実際の呼び出し式から推論
struct Mo {
    Mo(int N, const Add& add, const Del& del) : N(N), add(add), del(del) {}

    void add_query(int l, int r) {
        int id = (int)queries.size();
        queries.push_back({l, r, id});
    };

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
            return (x_block & 1) ? (x.r > y.r) : (x.r < y.r);
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