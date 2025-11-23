#ifndef H_Point
#define H_Point

#include "../Others/macros.hpp"
#include <complex>
#include <cassert>

namespace geom {

/**
 * real が x 軸
 * imag が y 軸
 */
using Point = std::complex<ld>;
const ld EPS = 1e-7;

inline bool equal(const ld& a, const ld& b) {
    return fabs(a - b) < EPS;
}

/**
 * @brief 内積を求める
 */
ld dot(const Point& a, const Point& b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

/**
 * @brief 外積を求める
 */
ld cross(const Point& a, const Point& b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

/**
 * @brief 点 p を反時計周りに theta 度回転
 */
Point rotate(const Point& p, const ld& theta) {
    return Point(p.real() * cos(theta) - p.imag() * sin(theta), 
                    p.real() * sin(theta) + cos(theta) * p.imag());
}

/**
 * @brief 直線を表す構造体
 * @brief b - a により、直線・線分を表せる
 */
struct Line {
    /**
     * @param a, b 直線が通過する 2 点
     */
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}

    /**
     * Ax + By = C
     */
    Line (ld A, ld B, ld C) {
        if (equal(A, 0)) { // 水平 -> y = C/B
            a = Point(0, C / B), b = Point(1, C / B);
        } else if (equal(B, 0)) { // 垂直 -> x = C/A
            a = Point(C / A, 0), b = Point(C / A, 1);
        } else {
            a = Point(0, C / B), b = Point(C / A, 0);
        }
    }
};

/**
 * @brief 線分を表す構造体
 * @remark 構造体 Line を継承
 */
struct Segment : Line {
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

/**
 * @brief 円を表す構造体
 */
struct Circle {
    /**
     * @param p 中心の位置ベクトル
     * @param r 半径
     */
    Point p;
    ld r;

    Circle() = default;
    Circle(Point p, ld r) : p(p), r(r) {
        assert(r >= -EPS);
    }
};

/**
 * @brief →pr は →pq をどちらの方向に（p 基準で）回転させたら、より早く →pq の向きに一致させられるかを判定
 * @remark Counter-ClockWise
 */
int ccw(const Point& p, Point q, Point r) {
    q -= p, r -= p;
    // 反時計回り
    if (cross(q, r) > EPS) {
        return 1;
    }
    // 時計回り
    if (cross(q, r) < -EPS) {
        return -1;
    }
    // r, p, q がこの順で一直線上
    if (dot(q, r) < 0) {
        return -2;
    }
    // p, q, r がこの順で一直線上
    if (norm(q) < norm(r)) {
        return 2;
    }
    // q が線分 pq 上
    return 3;
}

/**
 * @brief 内積を求める
 * @return 点 p から直線 l に下ろした垂線の足
 */
Point projection(const Line& l, const Point& p) {
    ld t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
    return l.a + t * (l.a - l.b);
};

Point projection(const Segment &l, const Point &p) {
    ld t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
    return l.a + t * (l.a - l.b);
}

/**
* @brief 反射を求める
* @return 直線 l に関して、点 p の反対側にある点
*/
Point refrection(const Line& l, const Point& p) {
    Point ah = projection(l, p);
    return p + 2.0l * (ah - p);
}

/**
 * @brief 2 直線の直行判定 -> 内積が 0
 */
bool is_orthogonal(const Line& s, const Line& t) {
    return equal(dot(s.b - s.a, t.b - t.a), 0);
}

/**
 * @brief 2 直線の並行判定 -> 外積が 0
 */
bool is_parallel(const Line& s, const Line& t) {
    return equal(cross(s.b - s.a, t.b - t.a), 0);
}

/**
 * @brief 直線の交点を求める
 * @return 直線 s, t の交点
 */
Point cross_point(const Line& s, const Line& t) {
    ld d1 = cross(t.b - t.a, s.b - s.a);
    ld d2 = cross(s.a - t.a, s.b - s.a);
    if (equal(abs(d1), 0) and equal(abs(d2), 0)) {
        return t.a;
    }
    return t.a + (d2 / d1) * (t.b - t.a);
}

/**
 * @brief 線分の交点を求める
 */
Point cross_point(const Segment& s, const Segment& t) {
    return cross_point(Line(s), Line(t));
}

/**
 * @brief 点 p, q, r が周上に存在する円の外心を求める
 */
Point gaisin(Point p, Point q, Point r) {
    Line pq((p + q) * 0.5l, (p + q) * 0.5l + rotate(p - q, PI / 2));
    Line qr((q + r) * 0.5l, (q + r) * 0.5l + rotate(q - r, PI / 2));
    return cross_point(pq, qr);
}

} // namespace geom




#endif // H_Point