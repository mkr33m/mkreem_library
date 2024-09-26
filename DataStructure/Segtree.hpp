#ifndef Segtree_HPP
#define Segtree_HPP

#include <vector>

template <typename M>
struct Segtree {
private:
    /**
     * @param seg セグ木
     * @param siz 管理する vector のサイズ以上の最小の 2 冪（葉の数）
     * @param N vector のサイズ
     */
    using T = typename M::S;
    std::vector<T> seg;
    int N;
    int siz = 1;

    struct Reference {
        Segtree& seg_ref;
        int index;

        Reference(Segtree& seg_ref, int index) : seg_ref(seg_ref), index(index) {}

        Reference& operator=(const T& x){
            seg_ref.set(index, x);
            return *this;
        }

        operator T() const {
            return seg_ref.seg[index + seg_ref.siz];
        }
    };

    void set(int i, const T x){
        i += siz;
        seg[i] = x;
        while(i >>= 1){
            seg[i] = M::op(seg[(i << 1) + 0], seg[(i << 1) + 1]);
        }
    }

public:
    // vector サイズを渡して、単位元で初期化
    Segtree(const int N) : N(N) {
        while(siz < N) siz <<= 1;
        seg.resize(2 * siz, M::e());
    }
    // vector サイズと初期値を渡して、初期値で初期化
    Segtree(const int N, const T init) : N(N) {
        while(siz < N) siz <<= 1;
        seg.resize(2 * siz, init);
    }
    // vector を渡して初期化
    Segtree(const std::vector<T>& vec) : N(vec.size()) {
        while(siz < N) siz <<= 1;
        seg.resize(2 * siz, M::e());
        for(int i = 0; i < N; i++){
            seg[i + siz] = vec[i];
        }
        for(int i = siz - 1; i >= 0; i--){
            seg[i] = M::op(seg[(i << 1) + 0], seg[(i << 1) + 1]);
        }
    }

    /**
     * @brief seg[i] = x  配列の i 番目に対応するノードを x でセットし、上にあるノードを更新
     */
    Reference operator[](const int& i){
        return Reference(*this, i);
    }

    /**
     * @brief 配列の i 番目に対応するノードの値を返却
     */
    const T operator[](const int& i) const {
        return seg[i + siz];
    }

    /**
     * @brief 区間 [l, r) での値を取得
     */
    T prod(int l, int r){
        T ansl = M::e(), ansr = M::e();
        l += siz, r += siz;
        while(l < r){
            if(l & 1) ansl = M::op(ansl, seg[l++]);
            if(r & 1) ansr = M::op(seg[--r], ansr);
            l >>= 1, r >>= 1;
        }
        return M::op(ansl, ansr);
    }

    T prod(const int& i){
        return prod(i, i + 1);
    }

    T all_prod(){
        return prod(0, N);
    }
};
#endif // Segtree_HPP