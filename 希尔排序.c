// 希尔排序函数，使用 Hibbard 增量序列
void shellSortHibbard(int arr[], int n) {
    int k = log2(n + 1);
    while (k > 0) {
        int gap = (int)pow(2, k) - 1;
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        k--;
    }
}