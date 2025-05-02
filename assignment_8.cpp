#include<iostream>
#include<vector>
using namespace std;
float w[100][100],c[100][100];
int r[100][100];
float arr[]={10,20,30,40};
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
                }
            }
        }
    }
    cout<<"Weight table : \n";
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(w[i][j]==0)
            {
                cout<<"w["<<i<<"]["<<j<<"]="<<"0"<<"     ";
            }else{
            cout<<"w["<<i<<"]["<<j<<"]="<<w[i][j]<<"     ";
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
        
        for(j=0;j<=n;j++)
        {
            if(c[i][j]==0)
            {
                cout<<"c["<<i<<"]["<<j<<"]="<<"0"<<"     ";
            }else{

                cout<<"c["<<i<<"]["<<j<<"]="<<c[i][j]<<"     ";
            }
            
        }
        cout<<"\n\n";
    }
    cout<<"\n\nRoot table :\n";
     
    for(i=0;i<=n;i++)
    {
       
        for(j=0;j<=n;j++)
        {
            if(r[i][j]==0)
            {
                cout<<"r["<<i<<"]["<<j<<"]="<<"0"<<"      ";
            }else{

                cout<<"r["<<i<<"]["<<j<<"]="<<r[i][j]<<"     ";
            }
            
        }
        cout<<"\n\n";
    }

}
class bst{
    public:
    int data;
    bst *left;
    bst * right;
    bst()
    {

    }

    bst(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }

    void obst(int i,int j,bst *current,char c)
    {
        if(i==j)
        {
            return;
        }else if(i==j-1)
        {
            // bst *node=new bst(r[i][j]);
            bst *node=new bst(arr[r[i][j]-1]);
            if(c=='l')
            {
                current->left=node;
            }else if(c=='n')
            {

            }else{
                current->right=node;
            }
          
        }else{
            // bst *node=new bst(r[i][j]);
           bst *node=new bst(arr[r[i][j]-1]);
            if(c=='l')
            {
                current->left=node;
                current=current->left;
            }else if(c=='n')
            {

            }else{
                current->right=node;
                current=current->right;
            }
            obst(i,r[i][j]-1,current,'l');
            obst(r[i][j],j,current,'r');

        }
    }

    void preorder(bst *current)
    {
        if(current==NULL)
        {
            return;
        }
        cout<<current->data<<" ";
        preorder(current->left);
        preorder(current->right);
    }

    void inorder(bst *current)
    {
        if(current==NULL)
        {
            return;
        }
        inorder(current->left);
        cout<<current->data<<" ";
        inorder(current->right);
    }
};
int main()
{
    bst b;
    // float arr[100],pi[100],qi[100];
    // float key;
    int s;
    s=4;
    
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
    bst *root=new bst(arr[r[0][s]-1]);
    b.obst(0,s,root,'n');
    cout<<"\nOBST : \n";
    cout<<"Preorder ---> ";
    b.preorder(root);
    cout<<"\nInorder ---> ";
    b.inorder(root);


}
