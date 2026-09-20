#include <iostream>

using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
int main()
{

    int i, a[5];
    for (i = 0; i < 5; i++)
    {
        cout << "Enter the number: a[" << i << "]";
        cin >> a[i];
    }
    selectionSort(a, 5);
    for (i = 0; i < 5; i++)
    {
        cout << "After sorting array element  a[" << i << "] is =" << a[i] << endl;
    }

    return 0;
}