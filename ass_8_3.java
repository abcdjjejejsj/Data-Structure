#include<iostream>
#include<vector>
using namespace std;
float w[100][100],c[100][100];
 int r[100][100];
class obst{
    public:
    int data;
    obst *left;
    obst *right;
    obst(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }

};



void weightCalc(float a[],float p[],float q[],int n)
{

    for(int i=0;i<=n;i++)
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
   
    int tr;
    float ss=0;
    int cnt=0;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=cnt;j<n;j++)
    //     {
    //         if(i<=j)
    //         {
    //             if(i==j)
    //             {
    //                 c[i][j]=0;
    //             }else{
    //                 float min=9999;
    //                 for(int k=i+1;k<=j;k++)
    //                 {
    //                     int temp=c[i][k-1]+c[k][j];
    //                     if(temp<min)
    //                     {
    //                         min=temp;
    //                     }
                        
    //                 }
    //                 c[i][j]=min+w[i][j];
    //                 ss=c[i][j];
                  
    //             }
    //         }
    //     }
    //         cnt++;
    // }

    int i=0,j=0;
    int a=i,b=j;
    float min;
    for(int h=0;h<(n+1);h++)
    {
        while(j<=n)
        {
            if(i==j)
            {
                c[i][j]=0;
                i++;
                j++;
            }else{
            min=9999;
                    for(int k=i+1;k<=j;k++)
                    {
                        float temp=c[i][k-1]+c[k][j];
                        if(temp<min)
                        {
                            min=temp;
                            tr=k;

                        }
                        
                    }
                    c[i][j]=min+w[i][j];
                    r[i][j]=tr;

                    i++;
                    j++;
                }
        }
        a++;
        b+=2;
        i=0;
        j=a;
    }

    cout<<"\n\nCost table :\n";
     for(i=0;i<=n;i++)
        {
            cout<<"     "<<i<<"  ";
        }
        cout<<"\n\n";
    for(i=0;i<=n;i++)
    {
        cout<<i<<"  ";
        for(j=0;j<=n;j++)
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
    cout<<"\n\nRoot table :\n";
     for(i=0;i<=n;i++)
        {
            cout<<"      "<<i;
        }
        cout<<"\n\n";
    for(i=0;i<=n;i++)
    {
        cout<<i<<"     ";
        for(j=0;j<=n;j++)
        {
            if(r[i][j]==0)
            {
                cout<<"0"<<"      ";
            }else{

            cout<<r[i][j]<<"      ";
            }
            
        }
        cout<<"\n\n";
    }

}

void create(int i,int j,obst *current)
{
    if(i==j)
    {
        return;
    }else{
        
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

    //obst *root=new root(r[0][s]);
   //create(0,s-1,root);

}
