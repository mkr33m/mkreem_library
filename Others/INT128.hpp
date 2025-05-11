#ifndef INT128_HPP
#define INT128_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * @remark __int128_t 型整数について
 * 標準入力からの受け取り・標準出力への出力は、他の整数型と同様に行う
 * プログラムに __int128_t 型整数を埋め込むときは、文字列とする必要がある。演算をするなら、parse関数で __int128_t 型に変換したものを __int128_t 型変数に格納する。
 */
/**
 * @brief 入力演算子を、__int128_t 型用にオーバーロード
 */
std::istream& operator>>(std::istream& is, __int128_t& value) {
    std::string s;
    is >> s;
    value = 0;
    int start = 0;
    bool is_negative = false;

    if (s[0] == '-') {
        is_negative = true;
        start = 1;
    }

    for (size_t i = start; i < s.size(); ++i) {
        value = 10 * value + (s[i] - '0');
    }

    if (is_negative) {
        value = -value;
    }

    return is;
}
/**
 * @brief 出力演算子を、__int128_t型用にオーバーロード
 */
std::ostream& operator<<(std::ostream& os, __int128_t value) {
    if (value == 0) return os << 0;

    static char buffer[128];
    if (value < 0) {
        os << '-';
        value = -value;
    }

    int itr = 0;
    while (value > 0) {
        buffer[itr++] = value % 10 + '0';
        value /= 10;
    }
    std::reverse(buffer, buffer + itr);
    buffer[itr] = 0;

    return os << buffer;
}
/**
 * @brief string型の10進非負整数を、__128_t型に変換する
 */
__int128_t parse(const std::string& s) {
    __int128_t res = 0;
    for (size_t i = 0; i < s.length(); i++) {
        res = 10 * res + (s[i] - '0');
    }
    return res;
}

#endif // INT128_HPP