#ifndef H_extended_gcd
#define H_extended_gcd

/**
 * @brief a * x + b * y == gcd(a, b)を満たす x, y を見つける
 * @return gcd(a, b)
 * x が a の逆元に相当
 */
long long extended_gcd(long long a, long long b, long long &x, long long &y){
    /*
    a * x0 + b * y0 == gcd(a, b)
    -> b * x1 + r * b1 == gcd(a, b)
    -> ...
    -> gcd(a, b) * xn + 0 * yn == gcd(a, b)
    */
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long nx, ny;
    long long gcd = extended_gcd(b, a % b, nx, ny);
    // 帰りがけに係数を更新
    x = ny;
    y = nx - (a / b) * ny;
    return gcd;
}

#endif
