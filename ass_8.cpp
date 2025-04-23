#include<iostream>
#include<vector>
using namespace std;

void weightCalc(int a[],int p[],int q[],int n)
{
    int w[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++)
        {
            if((j-i)<n)
            {
                if(j==i)
                {
                    w[i][j]=q[i];
                }else{
                    w[i][j]=w[i][j-1]+p[j]+q[j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
        for(int j=0;j<n;j++)
        {
            cout<<" "<<j;
            cout<<" "<<w[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int arr[100],pi[100],qi[100];
    int s,key;
    cout<<"Enter no.of keys : ";
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cout<<"Enter key-"<<(i+1)<<" : ";
        cin>>key;
        arr[i]=key;
    }
    cout<<"Enter probability of success : "<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<"for key "<<arr[i]<<" : ";
        cin>>key;
        pi[i]=key;
    }
    cout<<"Enter probability of unsuccesseful search :"<<endl;
    for(int i=0;i<=s;i++)
    {
        cout<<(i+1)<<" : ";
        cin>>key;
        qi[i]=key;
    }
    weightCalc(arr,pi,qi,s);

}
