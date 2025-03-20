//minimum spanning tree
#include<iostream>
#include<vector>
using namespace std;
class graph{
    public:
    int v,e,wt=0;
    int m[100][100];
    vector <int>start,final,edge;
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
            start.push_back(1);
            final.push_back(-1);
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
    void prims()
{
    final[0] = 1;
    start[0] = -1;

    for(int i = 0; i < v - 1; i++)
    {
        int min = 9999; 
        int parent = -1, child = -1;

        for(int j = 0; j < v; j++)
        {
            if(final[j] == 1) 
            {
                for(int k = 0; k < v; k++)
                {
                    if(m[j][k] != 0 && final[k] != 1 && m[j][k] < min)
                    {
                        min = m[j][k];
                        parent = j;
                        child = k;
                    }
                }
            }
        }

        if (child != -1) 
        {
            final[child] = 1;
            start[child] = -1;
            edge.push_back(parent);
            edge.push_back(child);
            edge.push_back(min);
            wt += min;
        }
    }

    cout << "wt of MST = " << wt << endl;
    for(int i = 0; i < edge.size(); i += 3)
    {
        cout << edge[i] << " " << edge[i+1] << " --> " << edge[i+2] << endl;
    }
}

};
int main()
{
    graph g(5,6);
    g.edges(0,1,2);
    g.edges(0,2,4);
    g.edges(2,3,1);
    g.edges(1,3,2);
    g.edges(1,4,3);
    g.edges(3,4,4);
    g.display();
    g.prims();
}
