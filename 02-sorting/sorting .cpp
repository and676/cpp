
#include <bits/stdc++.h>
using namespace std;

// 交换数组中 i 和 j 位置的数
void swap(int arr[], size_t i, size_t j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 选择排序
void selection_sort(int arr[], size_t n) {
    if (arr == NULL || n < 2) {
        return;
    }

    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;

        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr, i, min_index);
    }
}

// 冒泡排序
void bubble_sort(int arr[], size_t n) {
    if (arr == NULL || n < 2) {
        return;
    }

    for (size_t end = n - 1; end > 0; end--) {
        for (size_t i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }
        }
    }
}

// 插入排序
void insertion_sort(int arr[], size_t n) {
    if (arr == NULL || n < 2) {
        return;
    }

    for (size_t i = 1; i < n; i++) {
        // 通过不断交换相邻元素，将当前元素移动到正确位置
        for (size_t j = i;
             j > 0 && arr[j - 1] > arr[j];
             j--) {
            swap(arr, j - 1, j);
        }
    }
}   