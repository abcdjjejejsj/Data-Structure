#include<iostream>
#include<vector>
using namespace std;
float w[100][100],c[100][100];
void weightCalc(float a[],float p[],float q[],int n)
{

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
                    //cout<<"w["<<i<<"]["<<j<<"] = "<<w[i][j]<<"\tw[<<"<<i<<"]["<<(j-1)<<"= "<<w[i][j-1]<<"\tp["<<j<<"] = "<<p[j]<<"\tq["<<j<<"]="<<q[j]<<endl; 
                }
            }
        }
    }
    cout<<"Weight table : \n";
        for(int i=0;i<=n;i++)
        {
            cout<<"     "<<i<<"  ";
        }
        cout<<"\n\n";
    for(int i=0;i<=n;i++)
    {
        cout<<i<<"  ";
        for(int j=0;j<=n;j++)
        {
            if(w[i][j]==0)
            {
                cout<<"000"<<"     ";
            }else{

            cout<<w[i][j]<<"     ";
            }
            
        }
        cout<<"\n\n";
    }
}

void cost(int n)
{
    float ss=0;
    int cnt=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=cnt;j<n;j++)
        {
            if(i<=j)
            {
                if(i==j)
                {
                    c[i][j]=0;
                }else{
                    float min=9999;
                    for(int k=i+1;k<=j;k++)
                    {
                        int temp=c[i][k-1]+c[k][j];
                        if(temp<min)
                        {
                            min=temp;
                        }
                        
                    }
                    c[i][j]=min+w[i][j];
                    ss=c[i][j];
                  
                }
            }
        }
            cnt++;
    }

    cout<<"\n\nCost table :\n";
     for(int i=0;i<=n;i++)
        {
            cout<<"     "<<i<<"  ";
        }
        cout<<"\n\n";
    for(int i=0;i<=n;i++)
    {
        cout<<i<<"  ";
        for(int j=0;j<=n;j++)
        {
            if(c[i][j]==0)
            {
                cout<<"000"<<"     ";
            }else{

            cout<<c[i][j]<<"     ";
            }
            
        }
        cout<<"\n\n";
    }

}

int main()
{
    // float arr[100],pi[100],qi[100];
    // float key;
    int s;
    s=4;
    float arr[]={10,20,30,40};
    float pi[]={0.1,0.2,0.1,0.2};
    float qi[]={0.1,0.05,0.15,0.05,0.05};
    /*cout<<"Enter no.of keys : ";
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
    */
    weightCalc(arr,pi,qi,s);
    cost(s);

}
