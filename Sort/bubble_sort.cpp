/*
*   基于邓公DSA复写的冒泡排序
*/
template <typename T>
void bubble_sort(T *arr, int n)
{
    bool sorted = false;
    int temp = 0;

    while (!sorted) //若发现已排序, 直接返回
    {
        sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                sorted = false;
            }
        }

        n--;//末位元素一定就位
    }
}