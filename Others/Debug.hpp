#ifndef Debug_HPP
#define Debug_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

std::ofstream debug_outfile;
std::ostream* debug_out = &std::cout;

void Initialize_DebugOutput(){
    debug_outfile.open("debug.txt");
    debug_out = &debug_outfile;
}

#ifdef LOCAL

namespace debug {

    template <typename T>
    void debug_print(const T& t){
        *debug_out << t;
    }

    template <typename T, typename... Args>
    void debug_print(const T& t, const Args&... args){
        *debug_out << t << ", ";
        debug_print(args...);
    }

    // pair
    template <typename T1, typename T2>
    void debug_print(const std::pair<T1, T2>& p){
        *debug_out << "{" << p.first << ", " << p.second << "}";
    }

    // tuple
    template <typename Tuple, std::size_t... Is>
    void print_tuple(const Tuple& t, std::index_sequence<Is...>){
        ((*debug_out << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
    }

    template <typename... Args>
    void debug_print(const std::tuple<Args...>& t){
        *debug_out << "{";
        print_tuple(t, std::index_sequence_for<Args...>{});
        *debug_out << "}";
    }

    // map
    template <typename Key, typename Value>
    void debug_print(const std::map<Key, Value>& m){
        *debug_out << "{\n";
        for(auto it = m.begin(); it != m.end(); it++){
            if(it != m.begin()) *debug_out << ",\n";
            debug_print(*it);
        }
        *debug_out << "\n}";
    }

    // set
    template <typename T>
    void debug_print(const std::set<T>& s){
        *debug_out << "{";
        for(auto it = s.begin(); it != s.end(); it++){
            if(it != s.begin()) *debug_out << ", ";
            *debug_out << *it;
        }
        *debug_out << "}";
    }

    // 1D vector
    template <typename T>
    void debug_print(const std::vector<T>& vec){
        *debug_out << "[";
        bool f = std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<T, char>::value;
        for(size_t i = 0; i < vec.size(); i++){
            if(!f){
                *debug_out << '\n';
            }
            debug_print(vec[i]);
            if(i != vec.size() - 1) *debug_out << ", ";
        }
        if(!f){
            *debug_out << '\n';
        }
        *debug_out << "]";
    }

    // 2D vector
    template <typename T>
    void debug_print(const std::vector<std::vector<T>>& vec){
        *debug_out << "[\n";
        for(const auto& row : vec){
            *debug_out << "  ";
            debug_print(row);
            *debug_out << "\n";
        }
        *debug_out << "]";
    }

} // namespace debug

#define debug(...) do{ \
    *debug_out << #__VA_ARGS__ << " = "; \
    debug::debug_print(__VA_ARGS__); \
    *debug_out << '\n'; \
} while(0)
#else
#define debug(...) do {} while(0)
#endif

#endif // Debug_HPP