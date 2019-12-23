#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void bucket_sort(int arr[], int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max) max = arr[i];
    }
    vector<stack<int>> bucket(max + 1);
    for(int i = 0; i < n; i++)
    {
        bucket[arr[i]].push(arr[i]);
    }
    for(int i = 0, j = 0; i < bucket.size(); i++)
    {
        while(!bucket[i].empty())
        {
            arr[j] = bucket[i].top();
            bucket[i].pop();
            j++;
        }
    }
}

int main()
{
    int arr[] = { 5, 8, 5, 2, 3 };
    cout << "Array before sorting..." << endl;
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
	cout << "Applying bucket sort algorithm..." << endl;
    bucket_sort(arr, 5);
    cout << "Array after sorting..." << endl;
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}