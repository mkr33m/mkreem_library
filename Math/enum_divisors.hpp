#ifndef enum_divisors_HPP
#define enum_divisors_HPP

#include <vector>

template<typename T>
std::vector<T> enum_divisors(T N){
    std::vector<T> res;

    for(T i = 1; i * i <= N; i++){
        if(N % i == 0){
            res.push_back(i);
            if(N / i != i) res.push_back(N / i);
        }
    }

    return res; // 未ソート
}

#endif // enum_divisors_HPP