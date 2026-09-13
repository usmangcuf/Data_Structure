#include <iostream>

using namespace std;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(a, 5);
    for (i = 0; i < 5; i++)
    {
        cout << "a[" << i << "]" << a[i] << endl;
    }

    return 0;
}