#include <iostream>

using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main()
{

    int i, a[5];
    for (i = 0; i < 5; i++)
    {
        cout << "Enter the number: a[" << i<<"]";
        cin >> a[i];
    }
    quicksort(a, 0, 4);
    for (i = 0; i < 5; i++)
    {
        cout << "a[" << i << "]=" << a[i] << endl;
    }

    return 0;
}