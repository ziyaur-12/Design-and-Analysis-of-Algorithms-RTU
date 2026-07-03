#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Partition Function
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    ifstream file("input.txt");

    vector<int> arr;
    int x;

    while(file >> x)
    {
        arr.push_back(x);
    }

    file.close();

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted Elements:\n";

    for(int num : arr)
        cout << num << " ";

    cout << "\n\nTime Taken: "
         << duration.count()
         << " microseconds\n";

    return 0;
}