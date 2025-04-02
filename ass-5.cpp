//minimum spanning tree
#include<iostream>
#include<vector>
using namespace std;
class graph{
    public:
    int v,e,wt=0,t,prev;
    int m[100][100];
    int current;
    vector <int>start,visited,dist;
    graph(int x,int y)
    {
        v=x;
        e=y;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                m[i][j]=0;
            }
        }
        for(int i=0;i<v;i++)
        {
            visited.push_back(0);
            dist.push_back(9999);
        }
    }
    void edges(int x,int y,int w)
    {
        m[x][y]=w;
        m[y][x]=w;
    }
    void display()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }

void DJ()
{   
   dist[0]=0;
   visited[0]=1;
   current=0;
   int count=0;
   while(count<v)
   {
    prev=current;
    visited[current]=1;
   for(int i=0;i<v;i++)
   {
    if(m[current][i]!=0)
    {
        int temp=dist[current]+m[current][i];
        if(temp<dist[i])
        {
            dist[i]=temp;
        }
    }
   }
   t=9999;
   for(int i=0;i<v;i++)
   {
    if(m[current][i]!=0 && visited[i]!=1 && m[current][i]<t)
    {
        t=m[current][i];
        current=i;
    }
   }
   if(current!=prev)
   {
    count++;
   }
 
   }
   cout<<"shortest path :";
   for(int i=0;i<dist.size();i++)
   {
    cout<<dist[i]<<" ";
   }
}

};
int main()
{
    graph g(6,8);
    g.edges(0,1,2);
    g.edges(0,2,5);
    g.edges(0,4,3);
    g.edges(1,4,5);
    g.edges(1,3,8);
    g.edges(2,5,6);
    g.edges(3,5,3);
    g.edges(4,5,6);
    g.display();
    g.DJ();
}
