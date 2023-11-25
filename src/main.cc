#include <iostream>

#include "../include/Sorting.h"
#include "../include/Analytics.h"
#include "../include/User.h"

int main() {
    Stats stats = average_stats(-100, 100, 100, insertionSorting);
    std::cout << stats.comparison_count << std::endl;
    std::cout << stats.copy_count << std::endl;

    stats = average_stats(-100, 100, 100, quickSort);
    std::cout << stats.comparison_count << std::endl;
    std::cout << stats.copy_count << std::endl;

    stats = average_stats(-100, 100, 100, naturialTwoWayMergeSorting);
    std::cout << stats.comparison_count << std::endl;
    std::cout << stats.copy_count << std::endl;
  
    return 0;
}