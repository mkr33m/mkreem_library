#ifndef LIS_HPP
#define LIS_HPP

#include <vector>
#include <numeric>

template<typename T, bool strict = true>
int LIS(const std::vector<T>& A) {
    int N = (int)A.size();
    std::vector<T> lis(N + 1, std::numeric_limits<T>::max());
    lis[0] = std::numeric_limits<T>::lowest();
    
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int idx = 0;
        if (strict) {
            idx = std::lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        } else { 
            idx = std::upper_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        }
        lis[idx] = A[i];
        chmax(mx, idx);
    }
    return mx;
};

#endif // LIS_HPP