#ifndef LAB_3_INCLUDE_SORTING_H
#define LAB_3_INCLUDE_SORTING_H

#include <vector>
#include "../include/Stats.h"


// Сортировка вставками
template<typename T>
Stats insertionSorting(std::vector<T>& a) {
    Stats stats;
    size_t size = a.size();
    if (size < 2) return stats;
    for (size_t i = 1; i < size; ++i) {
        for (size_t j = i; j > 0; j--) {
            stats.comparison_count++;
            if (a[j - 1] <= a[j]) 
                break;
            stats.copy_count++;
            T temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
        }
    }
    return stats;
}

// Быстрая сортировка
template<typename T>
int partition(std::vector<T>& a, int start, int end, Stats& stats) {
    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        stats.comparison_count++;
        if (a[i] <= pivot)
        {
            stats.copy_count++;
            std::swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    stats.comparison_count++;
    std::swap(a[pIndex], a[end]);

    return pIndex;
}

template<typename T>
void countComparisons(std::vector<T>& arr, int low, int high, Stats& stats) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, stats);
        countComparisons(arr, low, pivotIndex - 1, stats);
        countComparisons(arr, pivotIndex + 1, high, stats);
    }
}

template<typename T>
Stats quickSort(std::vector<T>& arr) {
    Stats stats;
    countComparisons(arr, 0, arr.size() - 1, stats);
    return stats;
}


// Сортировка естественным двухпутевым слиянием
template <typename T>
void merge(std::vector<T>& a, size_t left, size_t mid, size_t right, Stats& stats) {
    size_t i = left;
    size_t j = mid + 1;
    std::vector<T> temp;
    while (i <= mid && j <= right) {
        stats.comparison_count++;
        if (a[i] < a[j]) {
            temp.push_back(a[i++]);
            stats.copy_count++;
        }
        else {
            temp.push_back(a[j++]);
            stats.copy_count++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i++]);
        stats.copy_count++;
    }

    while (j <= right) {
        temp.push_back(a[j++]);
        stats.copy_count++;
    }

    for (size_t i = left; i <= right; ++i) {
        a[i] = temp[i - left];
        stats.copy_count++;
    }
}

template<typename T>
void countAndSorting(std::vector<T>& a, size_t left, size_t right, Stats& stats) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        countAndSorting(a, left, mid, stats);
        countAndSorting(a, mid + 1, right, stats);

        merge(a, left, mid, right, stats);
    }
}

template<typename T>
Stats naturialTwoWayMergeSorting(std::vector<T>& a) {
    Stats stats;
    countAndSorting(a, 0, a.size() - 1, stats);
    return stats;
}


#endif