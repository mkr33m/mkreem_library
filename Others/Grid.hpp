#ifndef Grid_HPP
#define Grid_HPP

#include <vector>
#include <string>
#include <iostream>

const int di4[4] = {-1, 0, 1, 0};
const int dj4[4] = {0, 1, 0, -1};
const int di8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
/**
 * @brief 縦・横・斜めのインデックスを生成
 */
std::vector<std::vector<int>> lines(const int& N){
    std::vector<std::vector<int>> lines;

    for(int i = 0; i < N; i++){
        std::vector<int> line;
        for(int j = 0; j < N; j++){
            line.push_back(i * N + j);
        }
        lines.push_back(line);
    }

    for(int j = 0; j < N; j++){
        std::vector<int> line;
        for(int i = 0; i < N; i++){
            line.push_back(i * N + j);
        }
        lines.push_back(line);
    }

    std::vector<int> diag1;
    for(int i = 0; i < N; i++){
        diag1.push_back(i * N + i);
    }
    lines.push_back(diag1);

    std::vector<int> diag2;
    for(int i = 0; i < N; i++){
        diag2.push_back(i * N + (N - i - 1));
    }
    lines.push_back(diag2);

    return lines;
}

bool OutOfGrid(const int& i, const int& j, const int& h, const int& w){
    if(i < 0 || j < 0 || i >= h || j >= w) return true;
    return false;
}

/**
 * @brief 全ての行の文字列の長さを統一するために、空白文字で埋める
 */
void pad_strings(std::vector<std::string>& grid){
    size_t maxlen = 0;
    for(const auto& row : grid){
        maxlen = std::max(maxlen, row.size());
    }
    for(auto& row : grid){
        row.resize(maxlen, ' ');
    }
}

template <typename T>
std::vector<std::vector<T>> convert_to_matrix(std::vector<std::string>& grid){
    int H = (int)grid.size();
    int W = (int)grid[0].size();

    pad_strings(grid);
    std::vector<std::vector<T>> after_grid(H, std::vector<T>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            after_grid[i][j] = grid[i][j];
        }
    }
    return after_grid;
}

// 反時計回りに 90 度回転
template<typename T>
void rotate90(std::vector<std::vector<T>>& grid){
    int H = (int)grid.size();
    int W = (int)grid[0].size();

    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            after_grid[i][j] = grid[j][(W - 1) - i];
        }
    }
    std::swap(grid, after_grid);
}

// 180 度回転
template<typename T>
void rotate180(std::vector<std::vector<T>>& grid){
    int H = (int)grid.size();
    int W = (int)grid[0].size();

    std::vector<std::vector<T>> after_grid(H, std::vector<T>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            after_grid[i][j] = grid[(H - 1) - i][(W - 1) - j];
        }
    }
    std::swap(grid, after_grid);
}

// 時計回りに 90 度回転（270 度回転）
template<typename T>
void rotate270(std::vector<std::vector<T>>& grid){
    int H = (int)grid.size();
    int W = (int)grid[0].size();

    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            after_grid[i][j] = grid[(H - 1) - j][i];
        }
    }
    std::swap(grid, after_grid);
}

// 転置
template<typename T>
void transpose(std::vector<std::vector<T>>& grid){
    int H = (int)grid.size();
    int W = (int)grid[0].size();

    std::vector<std::vector<T>> after_grid(W, std::vector<T>(H));
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            after_grid[i][j] = grid[j][i];
        }
    }
    std::swap(grid, after_grid);
}

template<typename T>
void print(const std::vector<std::vector<T>>& grid, bool space = true){
    int H = (int)grid.size();
    int W = (int)grid[0].size();

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            std::cout << grid[i][j];
            if(space && j < W - 1) std::cout << " ";
        }
        std::cout << '\n';
    }
}

#endif // Grid_HPP