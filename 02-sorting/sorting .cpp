
#include <bits/stdc++.h>
using namespace std;

// 交换数组中 i 和 j 位置的数
void swap_int(vector<int>& arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 选择排序
void selection_sort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        swap_int(arr, i, min_index);
    }
}

// 冒泡排序
void bubble_sort(vector<int>& arr)
{
    int n = arr.size();

    for (int end = n - 1; end > 0; end--)
    {
        bool swapped = false;

        for (int i = 0; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap_int(arr, i, i + 1);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

// 插入排序
void insertion_sort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        for (int j = i;
             j > 0 && arr[j - 1] > arr[j];
             j--)
        {
            swap_int(arr, j - 1, j);
        }
    }
}

int main()
{
    vector<int> a = {5, 3, 8, 1, 9};

    // 选择一种排序算法进行测试
    selection_sort(a);
    // bubble_sort(a);
    // insertion_sort(a);

    for (int x : a)
        cout << x << " ";

    return 0;
}
