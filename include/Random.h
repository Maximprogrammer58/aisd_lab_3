#ifndef LAB_3_INCLUDE_RANDOM_H
#define LAB_3_INCLUDE_RANDOM_H

#include <random>
#include <vector>

int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

std::vector<int> generateRandomVector(int min, int max, size_t length) {
    std::vector<int> vec;
    for (size_t i = 0; i < length; ++i)
        vec.push_back(generateRandomNumber(min, max));
    return vec;
}

std::vector<int> generateSortedVector(size_t length) {
    std::vector<int> vec;
    for (size_t i = 1; i <= length; ++i)
        vec.push_back(i);
    return vec;
}

std::vector<int> generateReverseSortedVector(size_t length) {
    std::vector<int> vec;
    for (size_t i = length; i > 0; --i)
        vec.push_back(i);
    return vec;
}

#endif