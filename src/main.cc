#include <iostream>
#include "../include/Sorting.h"

int main() {
    std::vector<int> arr = { 2, 8, -3, 9, 7 };
    int comparisons = naturialTwoWayMergeSorting(arr).comparison_count;
    std::cout << "Number of comparisons: " << comparisons << std::endl;
    for (const auto& el: arr)
        std::cout << el << " ";
    return 0;
}