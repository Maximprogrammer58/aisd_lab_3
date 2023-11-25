#ifndef LAB_3_INCLUDE_ANALYTICS_H
#define LAB_3_INCLUDE_ANALYTICS_H

#include "../include/Sorting.h"
#include "../include/Random.h"

Stats average_stats(int min, int max, size_t length, Stats(*func)(std::vector<int>& a)) {
	Stats average_stats;
	size_t count = 100;
	for (size_t i = 0; i < count; ++i) {
		std::vector<int> vec = generateRandomVector(min, max, length);
		average_stats += func(vec);
	}
	average_stats.comparison_count /= count;
	average_stats.copy_count /= count;

	return average_stats;
}

#endif