#ifndef Grid_HPP
#define Grid_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T> // 各要素の型
class Grid {
private:
    std::vector<std::vector<T>> grid;

    static void pad_strings(std::vector<std::string>& grid_arg) {
        size_t maxlen = 0;
        for (const auto& row : grid_arg) {
            maxlen = std::max(maxlen, row.size());
        }
        for (auto& row : grid_arg) {
            row.resize(maxlen, ' ');
        }
    }

public:
    Grid() {}
    Grid(const std::vector<std::vector<T>>& grid_arg) : grid(grid_arg) {}
    Grid(std::vector<std::string> grid_arg) {
        pad_strings(grid_arg);
        int H = grid_arg.size();
        int W = grid_arg[0].size();
        grid.assign(H, std::vector<T>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                grid[i][j] = grid_arg[i][j];
            }
        }
    }

    T& get(size_t i, size_t j) const {
        return grid[i][j];
    }

    void set(size_t i, size_t j, T x) const {
        grid[i][j] = x;
    }

    size_t get_H() const {
        return grid.size();
    }

    size_t get_W() const {
        return grid[0].size();
    }

    const std::vector<std::vector<T>>& get_data() const {
        return grid;
    }

    // グリッドを出力（オプションで各要素間に空白を挿入）
    void print(bool space = false) const {
        int H = (int)get_H();
        if(H == 0) return;
        int W = (int)get_W();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                std::cout << grid[i][j];
                if (space && j < W - 1)
                    std::cout << ' ';
            }
            std::cout << '\n';
        }
    }

    // 反時計回りに90度回転
    void rotate90() {
        int H = (int)get_H();
        int W = (int)get_W();
        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                new_grid[i][j] = grid[j][W - 1 - i];
            }
        }
        grid.swap(new_grid);
    }

    // 180度回転
    void rotate180() {
        int H = (int)get_H();
        int W = (int)get_W();
        std::vector<std::vector<T>> new_grid(H, std::vector<T>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                new_grid[i][j] = grid[H - 1 - i][W - 1 - j];
            }
        }
        grid.swap(new_grid);
    }

    // 時計回りに90度回転
    void rotate270() {
        int H = (int)get_H();
        int W = (int)get_W();
        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                new_grid[i][j] = grid[H - 1 - j][i];
            }
        }
        grid.swap(new_grid);
    }

    // 転置
    void transpose() {
        int H = (int)get_H();
        int W = (int)get_W();
        std::vector<std::vector<T>> new_grid(W, std::vector<T>(H));
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                new_grid[i][j] = grid[j][i];
            }
        }
        grid.swap(new_grid);
    }
};

#endif // Grid_HPP