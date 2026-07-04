#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];
}

void mergeSort(vector<int>& arr,int l,int r)
{
    if(l>=r)
        return;

    int m=l+(r-l)/2;

    if(r-l>1000)
    {
        thread t1(mergeSort,ref(arr),l,m);
        thread t2(mergeSort,ref(arr),m+1,r);

        t1.join();
        t2.join();
    }
    else
    {
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
    }

    merge(arr,l,m,r);
}

int main()
{
    ifstream file("input.txt");

    vector<int> arr;
    int x;

    while(file>>x)
        arr.push_back(x);

    file.close();

    auto start=high_resolution_clock::now();

    mergeSort(arr,0,arr.size()-1);

    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout<<"Sorted Elements\n\n";

    for(int i:arr)
        cout<<i<<" ";

    cout<<"\n\nExecution Time : "<<duration.count()<<" microseconds"<<endl;

    return 0;
}