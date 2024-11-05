#ifndef Input_HPP
#define Input_HPP

#include <iostream>
#include <vector>

namespace input {

    template <typename T>
    void read(T& t){
        std::cin >> t;
    }

    template <typename T, typename... Args>
    void read(T& t, Args&... args){
        std::cin >> t;
        read(args...);
    }

} // namespace input

#define READ(type, ...) \
    type __VA_ARGS__; \
    input::read(__VA_ARGS__)
#define INT(...) READ(int, __VA_ARGS__)
#define LL(...) READ(long long, __VA_ARGS__)
#define DOUBLE(...) READ(double, __VA_ARGS__)
#define LD(...) READ(long double, __VA_ARGS__)
#define STRING(...) READ(std::string, __VA_ARGS__)
#define CHAR(...) READ(char, __VA_ARGS__)
#define VI(vec, type, a) std::vector<type> vec(a); for(int i = 0; i < a; i++) std::cin >> vec[i]
#define VI2(vec1, vec2, type, a, b) std::vector<type> vec1(a), vec2(b); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int i = 0; i < b; i++) std::cin >> vec2[i]
#define VI3(vec1, vec2, vec3, type, a, b, c) std::vector<type> vec1(a), vec2(b), vec3(c); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin >> vec3[i]
#define VI4(vec1, vec2, vec3, vec4, type, a, b, c, d) std::vector<type> vec1(a), vec2(b), vec3(c), vec4(d); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin >> vec3[i]; for(int i = 0; i < d; i++) std::cin >> vec4[i]
#define VI5(vec1, vec2, vec3, vec4, vec5, type, a, b, c, d, e) std::vector<type> vec1(a), vec2(b), vec3(c), vec4(d), vec5(e); for(int i = 0; i < a; i++) std::cin >> vec1[i]; for(int i = 0; i < b; i++) std::cin >> vec2[i]; for(int i = 0; i < c; i++) std::cin >> vec3[i]; for(int i = 0; i < d; i++) std::cin >> vec4[i]; for(int i = 0; i < e; i++) std::cin >> vec5[i]
#define VI2_(vec1, vec2, type, a) std::vector<type> vec1(a), vec2(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i]
#define VI3_(vec1, vec2, vec3, type, a) std::vector<type> vec1(a), vec2(a), vec3(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i]
#define VI4_(vec1, vec2, vec3, vec4, type, a) std::vector<type> vec1(a), vec2(a), vec3(a), vec4(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i] >> vec4[i]
#define VI5_(vec1, vec2, vec3, vec4, vec5, type, a) std::vector<type> vec1(a), vec2(a), vec3(a), vec4(a), vec5(a); for(int i = 0; i < a; i++) std::cin >> vec1[i] >> vec2[i] >> vec3[i] >> vec4[i] >> vec5[i]
#define VVI(vec, type, a, b) std::vector<std::vector<type>> vec(a, std::vector<type>(b)); for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) std::cin >> vec[i][j]

#endif // Input_HPP