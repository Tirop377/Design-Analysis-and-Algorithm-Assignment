#include <iostream>
#include <vector>

std::vector<int> circular_shift_array(std::vector<int> arr, int k) {
    int n = arr.size();
    if (n == 0) {
        return arr;
    }
    
    k = k % n;
    std::vector<int> result(n);
    for (int i = 0; i < k; ++i) {
        result[i] = arr[n - k + i];
    }
    for (int i = 0; i < n - k; ++i) {
        result[k + i] = arr[i];
    }
    return result;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    std::vector<int> shifted = circular_shift_array(arr, k);
    for (int i = 0; i < shifted.size(); ++i) {
        std::cout << shifted[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
 
