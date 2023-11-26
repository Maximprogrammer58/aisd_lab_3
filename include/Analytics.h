#ifndef LAB_3_INCLUDE_ANALYTICS_H
#define LAB_3_INCLUDE_ANALYTICS_H

#include <iostream>

#include "../include/Sorting.h"
#include "../include/Random.h"

Stats averageStats(int min, int max, size_t length, Stats(*sort_func)(std::vector<int>& a)) {
	Stats average_stats;
	size_t count = 100;
	for (size_t i = 0; i < count; ++i) {
		std::vector<int> vec = generateRandomVector(min, max, length);
		average_stats += sort_func(vec);
	}
	average_stats.comparison_count /= count;
	average_stats.copy_count /= count;

	return average_stats;
}

void getStatsByLength(int min, int max, const std::vector<size_t>& len_vec, Stats(*sort_func)(std::vector<int>& a)) {
	for (size_t i = 0; i < len_vec.size(); ++i) {
		Stats stats = averageStats(min, max, len_vec[i], sort_func);
		std::cout << "For length: " << len_vec[i] << std::endl;
		std::cout << stats.comparison_count << std::endl;
		std::cout << stats.copy_count << std::endl;
	}
	std::cout << std::endl;
}

void getStats(const std::vector<size_t>& len_vec, std::vector<int>(*generate_func)(size_t length), Stats(*sort_func)(std::vector<int>& a)) {
	for (size_t i = 0; i < len_vec.size(); ++i) {
		std::vector<int> a = generate_func(len_vec[i]);
		Stats stats = sort_func(a);
		std::cout << "For length: " << len_vec[i] << std::endl;
		std::cout << stats.comparison_count << std::endl;
		std::cout << stats.copy_count << std::endl;
	}
	std::cout << std::endl;
}

#endif