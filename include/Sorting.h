#ifndef LAB_3_INCLUDE_SORTING_H
#define LAB_3_INCLUDE_SORTING_H

#include <vector>
#include "../include/Stats.h"


// InsertionSorting
template<typename T>
Stats insertionSorting(std::vector<T>& a) {
    Stats stats;
    size_t size = a.size();
    if (size < 2) return stats;
    for (size_t i = 1; i < size; ++i) {
        for (size_t j = i; j > 0; j--) {
            stats.comparison_count++;
            if (a[j - 1] < a[j])
                break;
            stats.copy_count += 2;
            std::swap(a[j - 1], a[j]);
        }
    }
    return stats;
}


// QuickSorting
template<typename T>
int partition(std::vector<T>& a, int start, int end, Stats& stats) {
    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        stats.comparison_count++;
        if (a[i] <= pivot)
        {
            stats.copy_count += 2;
            std::swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    stats.copy_count += 2;
    std::swap(a[pIndex], a[end]);

    return pIndex;
}

template<typename T>
void quickSortWithEndPivot(std::vector<T>& arr, int low, int high, Stats& stats) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, stats);
        quickSortWithEndPivot(arr, low, pivotIndex - 1, stats);
        quickSortWithEndPivot(arr, pivotIndex + 1, high, stats);
    }
}

template<typename T>
Stats quickSorting(std::vector<T>& arr) {
    Stats stats;
    quickSortWithEndPivot(arr, 0, arr.size() - 1, stats);
    return stats;
}


// Naturial two-way merge sort
template<typename T>
void merge(std::vector<T>& arr, size_t left, size_t mid, size_t right, Stats& stats) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<T> leftArr(n1), rightArr(n2);

    stats.comparison_count++;
    for (size_t i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
        stats.copy_count++;
        stats.comparison_count++;
    }

    stats.comparison_count++;
    for (size_t j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
        stats.copy_count++;
    }

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        stats.comparison_count += 2;
        if (leftArr[i] <= rightArr[j]) {
            stats.comparison_count++;
            arr[k] = leftArr[i];
            stats.copy_count++;
            i++;
        }
        else {
            stats.comparison_count++;
            arr[k] = rightArr[j];
            stats.copy_count++;
            j++;
        }
        k++;
    }

    if (i >= n1)
        stats.comparison_count++;
    else
        stats.comparison_count += 2;

    stats.comparison_count++;
    while (i < n1) {
        stats.comparison_count++;
        arr[k] = leftArr[i];
        stats.copy_count++;
        i++;
        k++;
    }

    stats.comparison_count++;
    while (j < n2) {
        stats.comparison_count++;
        arr[k] = rightArr[j];
        stats.copy_count++;
        j++;
        k++;
    }
}

template<typename T>
Stats naturialTwoWayMergeSorting(std::vector<T>& arr) {
    Stats stats;
    size_t n = arr.size();

    while (true) {
        size_t left = 0;
        stats.comparison_count++;
        while (left < n) {
            stats.comparison_count++;
            size_t mid = left;
            
            while (mid + 1 < n && arr[mid] <= arr[mid + 1]) {
                stats.comparison_count += 2;
                mid++;
            }

            if (mid + 1 >= n)
                stats.comparison_count++;
            else
                stats.comparison_count += 2;

            stats.comparison_count++;
            if (mid == n - 1) 
                return stats;

            size_t right = mid + 1;


            while (right + 1 < n && arr[right] <= arr[right + 1]) {
                stats.comparison_count += 2;
                right++;
            }

            if (right + 1 >= n)
                stats.comparison_count++;
            else
                stats.comparison_count += 2;
            
            merge(arr, left, mid, right, stats);

            left = right + 1;
        }
    }

    return stats;
}

#endif