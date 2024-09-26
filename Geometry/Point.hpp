#ifndef H_Point
#define H_Point

#include "../Others/macros.hpp"

struct Point {
private:
    /**
     * @remark 大まかには、グループの昇順でソート。
     * @remark 原点の扱いに注意。どこに持ってくるかによってグルーピングを設定する。
     */
    int grouping(const Point& p) const {
        /**
         * 偏角の範囲：[0, 2π)
         * 分割：[0, π/2], (π/2, π], (π, 2π)
         * @remark 原点は、先頭に持ってくるようにしている（つまり、偏角を0とみなしている）。
         */
        if(p.x == 0 && p.y == 0){
            return 0;
        } else if(p.y < 0){ // (π, 2π)
            return 3;
        } else if(p.x < 0){ // (π/2, π]
            return 2;
        } else{ // [0, π/2]
            return 1;
        }

        /*
        * 偏角の範囲：(-π/2, π/2]
        * 分割 (-π/2, 0], (0, π/2]
        * @remark 原点の偏角は、0とみなしている。
        */
        /* if(p.x == 0 && p.y == 0){ // 原点
            return 0;
        } else if(p.y < 0 || (p.y == 0 && p.x > 0)){ // (-π/2, 0]
            return -1;
        } else{ // (0, π/2]
            return 1;
        } */
    }

public:
    long long x, y;
    Point() : x(0LL), y(0LL)  {}
    Point(long long x, long long y) : x(x), y(y) {}

    bool operator!=(const Point& q) const {
        return x != q.x || y != q.y;
    }
    bool operator==(const Point& q) const {
        return !(*this == q);
    }
    /**
     * 点の比較は、偏角の大きさによる
     */
    bool operator<(const Point& q) const {
        int group_p = grouping(*this);
        int group_q = grouping(q);

        if(group_p != group_q){
            return group_p < group_q;
        }

        return y * q.x < x * q.y; // p.y / p.x < q.y / q.x
    }
    bool operator<=(const Point& q) const {
        return *this < q || *this == q;
    }
    bool operator>(const Point& q) const {
        return !(*this <= q);
    }
    bool operator>=(const Point& q) const {
        return !(*this < q);
    }

    /**
     * 演算の定義
     */
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    Point operator*(ll k) const {
        return Point(k * x, k * y);
    }
    long long length2() const {
        return x * x + y * y;
    }
    long long dist2(const Point& p) const {
        return (x - p.x) * (x - p.x) + (y - p.y) + (y - p.y);
    }
    long long dot(const Point& p) const { // 内積（dot product）
        return x * p.x + y * p.y;
    }
    long long cross(const Point& p) const { // 外積（cross product）
        return x * p.y - y * p.x;
    }
};

#endif // H_Point