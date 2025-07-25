#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>arr;
    int n=37;
    int d=5,no=0;

    int res=n*5;
    int cnt=5;
    while(cnt<=res)
    {
        arr.push_back(cnt);
        cnt+=5;
    }
    int low=0,high=arr.size()-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        cnt=5;
        no=0;
        while(arr[mid]>=cnt)
        {
            int res=arr[mid]/cnt;
            no+=res;
            cnt*=5;
        }
         if(no==n)
        {
            cout<<"solution : "<<arr[low]<<endl;
        }
        if(no<n)
        {
            low=mid+1;
        }else{
            high=mid-1;

        }
    }
    if(low==high)
    {
        cnt=5;
        no=0;
        while(arr[low]>=cnt)
        {
            int res=arr[low]/cnt;
            no+=res;
            cnt*=5;
        }
        if(no==n)
        {
            cout<<arr[low]<<endl;
        }else{
            cout<<"Invalid case !"<<endl;
        }

    }
}
