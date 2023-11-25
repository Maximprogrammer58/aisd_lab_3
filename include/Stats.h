#ifndef LAB_3_INCLUDE_STATS_H
#define LAB_3_INCLUDE_STATS_H

struct Stats {
	size_t comparison_count;
	size_t copy_count;

	Stats() : comparison_count(0), copy_count(0) {}

	Stats(const Stats& other) {
		comparison_count = other.comparison_count;
		copy_count = other.copy_count;
	}

	Stats& operator=(const Stats& other) {
		comparison_count = other.comparison_count;
		copy_count = other.copy_count;
		return *this;
	}

	Stats& operator+=(const Stats& other) {
		comparison_count += other.comparison_count;
		copy_count += other.copy_count;
		return *this;
	}
};

#endif