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
int binarysearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);

        return binarysearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main()
{

    int i, a[5],x,loc;
    for (i = 0; i < 5; i++)
    {
        cout << "Enter the number: " << i;
        cin >> a[i];
    }
    insertionSort(a, 5);
    cout<<"enter the element to search"<<endl;
    cin>>x;
    loc=binarysearch(a,0,4,x);
    cout<<"Found at location"<<loc;

    return 0;
}