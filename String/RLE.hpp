#ifndef RLE_HPP
#define RLE_HPP

#include <vector>
#include <string>
#include <tuple>

std::vector<std::pair<char, int>> encode(const std::string& S){
    int N = (int)S.size();
    std::vector<std::pair<char, int>> res;
    int l = 0, r;
    while(r < N){
        r = l + 1;
        while(r < N && S[l] == S[r]) r++;
        res.emplace_back(S[l], r - l);
        l = r;
    }
    return res;
}

std::string decode(const std::vector<std::pair<char, int>>& encoded){
    std::string res = "";
    for(const auto& [ch, num] : encoded){
        for(int i = 0; i < num; i++){
            res += ch;
        }
    }
    return res;
}

#endif // RLE_HPP