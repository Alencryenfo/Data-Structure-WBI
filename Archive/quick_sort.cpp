#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// 划分函数：选择第一个元素作为基准，将数组划分为两部分
// 返回基准元素的最终位置索引
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // 选择第一个元素作为基准值
    int i = low;
    int j = high;

    while (i < j) {
        // 从右向左找第一个小于基准值的元素
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        // 从左向右找第一个大于基准值的元素
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        // 如果 i < j，交换找到的两个元素
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // 将基准值放到最终的位置 (i 或 j 指向的位置)
    // 此时 i == j，arr[j] 是右侧子数组中第一个小于等于 pivot 的元素（或 i 是左侧第一个大于等于 pivot 的）
    // 基准值最初在 arr[low]
    swap(arr[low], arr[j]); // 将基准值放到正确的位置
    return j; // 返回基准值的索引
}

// 快速排序递归函数
// 需要传入数组引用以及排序范围的低位和高位索引
void qsort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi 是划分后基准值的索引
        int pi = partition(arr, low, high);

        // 分别对基准值左右两边的子数组进行递归排序
        qsort(arr, low, pi - 1);  // 排序左子数组
        qsort(arr, pi + 1, high); // 排序右子数组
    }
}

// 辅助函数：打印数组内容
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// 主函数：用于测试快速排序
int main() {
    vector<int> data = {12, 4, 5, 6, 7, 3, 1, 15, 8, 9, 2, 10, 11, 14, 13};
    cout << "原始数组: ";
    printArray(data);

    // 调用快速排序函数，传入整个数组的范围
    qsort(data, 0, data.size() - 1);

    cout << "排序后数组: ";
    printArray(data);

    return 0;
}