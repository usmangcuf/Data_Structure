#include <iostream>

using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main()
{

    int i, a[5];
    for (i = 0; i < 5; i++)
    {
        cout << "Enter the number: " << i;
        cin >> a[i];
    }
    BubbleSort(a, 5);
    for (i = 0; i < 5; i++)
    {
        cout << "a[" << i << "]" << a[i] << endl;
    }

    return 0;
}