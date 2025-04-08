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
   int count=0;

   while(count < v)
   {
       int t=9999;
       for(int i=0;i<v;i++)
       {
           if(visited[i]==0 && dist[i]<t)
           {
               t=dist[i];
               current=i;
           }
       }

       visited[current]=1;
       count++;

       for(int i=0;i<v;i++)
       {
           if(m[current][i]!=0 && visited[i]==0)
           {
               if(dist[current]+m[current][i] < dist[i])
               {
                   dist[i]=dist[current]+m[current][i];
               }
           }
       }
   }

   cout<<"Shortest Path from Node 0 to all Nodes : ";
   for(int i=0;i<v;i++)
   {
       cout<<dist[i]<<" ";
   }
   cout<<endl;
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
