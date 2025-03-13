//assignment-3 of flight path
#include<iostream>
#include<vector>
using namespace std;
class matrix{
    public:
    int m[100][100],v,e;
    vector<int>start,final;
    matrix()
    {

    }
    void setGraph(int x,int y)
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
            final.push_back(1);
        }
    }

    void edge(int x,int y,int cost)
    {
        m[x][y]=cost;
        m[y][x]=cost;
    }
    void prims()
{
    int parent[v];   // Stores the MST structure
    int key[v];      // Stores the minimum cost to reach each node
    bool inMST[v];   // True if a vertex is included in MST

    // Initialize arrays
    for (int i = 0; i < v; i++) {
        key[i] = 99999;   // Large value (infinity)
        inMST[i] = false; // No node included in MST initially
        parent[i] = -1;   // No parent assigned yet
    }

    key[0] = 0; // Start from the first vertex

    // MST Construction Loop
    for (int count = 0; count < v - 1; count++) {
        int min = 99999, minIndex = -1;

        // Find the minimum key vertex not yet in MST
        for (int i = 0; i < v; i++) {
            if (!inMST[i] && key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }

        int u = minIndex;
        inMST[u] = true; // Include in MST

        // Update key and parent for adjacent vertices
        for (int j = 0; j < v; j++) {
            if (m[u][j] && !inMST[j] && m[u][j] < key[j]) {
                key[j] = m[u][j];
                parent[j] = u;
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree (MST):\n";
    int totalCost = 0;
    for (int i = 1; i < v; i++) {
        cout << parent[i] << "  " << i << " -->" << m[i][parent[i]] << endl;
        totalCost += m[i][parent[i]];
    }
    cout << "Total Cost of MST: " << totalCost << endl;
}

};

int main()
{
    matrix am;
    int ch,vertex,edges,v1,v2,no,d;
    int arr[20];
    do{
        cout<<"\n1.Adjancancy matrix\t2.Output(AM)\t3.MST\nEnter choice :";
        cin>>ch;
        switch(ch)
        {
            case 1://input 
                    cout<<"Enter no.of vertices:";
                    cin>>vertex;
                    for(int i=0;i<vertex;i++)
                    {
                        cout<<"Vertex-"<<i+1<<":";
                        cin>>arr[i];
                    }
                    cout<<"Enter no.of edges:";
                    cin>>edges;
                    am.setGraph(vertex,edges);
                    for(int i=0;i<edges;i++)
                    {
                        cout<<"edge-"<<i+1<<endl;
                        cout<<"\tvertiex-1 :";
                        cin>>v1;
                        cout<<"\tvertiex-2 :";
                        cin>>v2;
                        cout<<"Enter cost:";
                        cin>>d;
                        am.edge(v1,v2,d);
                    }
                    break;
            case 2://output of AM
                   for(int i=0;i<vertex;i++)
                   {
                    cout<<"\t"<<arr[i];
                   }
                   cout<<"\n\n";
                   for(int i=0;i<vertex;i++)
                   {
                    cout<<arr[i]<<"\t";
                    for(int j=0;j<vertex;j++)
                    {
                        cout<<am.m[arr[i]][arr[j]]<<"\t";
                    }
                    cout<<"\n";
                   }
                   break;
            case 3://MST
                   am.prims();
                   break;
                   
                   
            

        }
    }while(ch!=4);
}
