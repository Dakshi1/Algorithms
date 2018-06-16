#include <iostream>
#include <vector>


using namespace std;
vector<int> arr={2, 4, 1, 6, 8, 5, 3 ,7};
void Merge(int start, int mid, int endx)
{
    int st=start;
    int st1=mid+1;
    int helper[endx - start +1];
    int i=0;
    while(st <= mid && st1 <= endx)
    {
        if(arr[st] <= arr[st1])
        {
            helper[i]=arr[st];
            st++;
        }
        else
        {
            helper[i]=arr[st1];
            st1++;
        }
        i++;
    }
    while(st <= mid)
    {
        helper[i]=arr[st];
        st++;
        i++;
    }
    while(st1 <= endx)
    {
        helper[i]=arr[st1];
        st1++;
        i++;
    }
    for(i=0; i<= endx-start; i++)
    {
        arr[start + i]=helper[i];
    }
}
void MergeSort(int start, int endx)
{
    if(start == endx)
        return;
    int mid=start + (endx - start)/2;
    MergeSort(start, mid);
    MergeSort(mid+1, endx);
    Merge(start, mid, endx);
}
int main()
{

    vector<int>::iterator it;

    MergeSort(0, 7);

    for(it=arr.begin(); it!=arr.end();it++)
    {
        cout << *it << endl;
    }

    return 0;
}
