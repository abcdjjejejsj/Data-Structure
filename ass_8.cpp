#include<iostream>
#include<vector>
using namespace std;

void weightCalc(float a[],float p[],float q[],int n)
{
    float w[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i<=j)
            {
                if(j==i)
                {
                    w[i][j]=q[i];
                }else{
                    w[i][j]=w[i][j-1]+p[j-1]+q[j];
                    cout<<"w["<<i<<"]["<<j<<"] = "<<w[i][j]<<"\tw[<<"<<i<<"]["<<(j-1)<<"= "<<w[i][j-1]<<"\tp["<<j<<"] = "<<p[j]<<"\tq["<<j<<"]="<<q[j]<<endl;
                }
            }
        }
    }
        for(int k=0;k<=n;k++)
        {
            cout<<"  "<<k;
        }
        cout<<"\n\n";
    for(int i=0;i<=n;i++)
    {
        cout<<i<<"  ";
        for(int j=0;j<=n;j++)
        {
            
            cout<<w[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    float arr[100],pi[100],qi[100];
    float key;
    int s;
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
