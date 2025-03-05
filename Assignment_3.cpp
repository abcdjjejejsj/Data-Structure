//assignment-3 : Graph
#include<iostream>
using namespace std;
class Graph{
   public:
    int v,e;
    int m[100][100];
    Graph()
    {

    }
    Graph(int x,int y)
    {
        v=x;
        e=y;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                m[i][j]=0;
            }
        }
    }
    void edge(int u,int v)
    {
        m[u][v]=1;
        m[v][u]=1;
    }
};
class list{
    public:
    int data;
    list *next;

    list(int x)
    {
        data=x;
        next=NULL;
    }
    list(){

    }
    void insert(list *hed,list *temp)
    {
        
        if(hed==NULL)
        {
            hed=temp;
        }else{
            while(hed->next==NULL)
            {
                hed = hed->next;
            }
            hed=temp;
        }
    }
};
int main()
{
    Graph g;
    Graph *c;
    list *hed[20],*temp;
    list l;
    int ch,vertex,edges,v1,v2,i,j,cnt=0,no,d,n;
    do{
        cout<<"\n1.Input\t2.Output\t3.Exit\nEnter choice :";
        cin>>ch;
        switch(ch)
        {
            case 1://input :-adjacency matrix
                   cout<<"Enter no.of vertices :";
                   cin>>vertex;
                   cout<<"Enter no.of edges :";
                   cin>>edges;
                   c = new Graph(vertex,edges);
                   cout<<"Enter vertex that have edges between them :"<<endl;
                   for(i=0;i<edges;i++)
                   {
                    cin>>v1;
                    cin>>v2;
                    g.edge(v1,v2);
                   }
                   break;
                
            case 2://output :adjacency matrix
                  cout<<"\t";
                  for(i=1;i<=vertex;i++)
                  {
                    cout<<i<<"\t";
                  }
                  cout<<endl;
                  for(i=1;i<=vertex;i++)
                  {
                    cout<<i<<"\t";
                    for(j=1;j<=vertex;j++)
                    {
                        cout<<g.m[i][j]<<"\t";
                    }
                    cout<<endl;
                  }
                  break;
            case 3://adjacency list
                   cout<<"Enter no.of vertices :";
                   cin>>vertex;
                   for(i=0;i<vertex;i++)
                   {
                    hed[cnt]=NULL;
                    cout<<"Enter no.of adjacent vertices :";
                    cin>>no;
                    for(j=0;j<no;j++)
                    {
                        cout<<"vertex-"<<j+1<<" :";
                        cin>>d;
                        temp=new list(d);
                        l.insert(hed[cnt],temp);
                    }
                    cnt++;
                   }

                 break;
                   
            case 4://display
                   n=0;
                   for(i=0;i<cnt;i++)
                   {
                    temp=hed[i];

                    while(hed!=NULL)
                    {

                        cout<<temp->data<<"\t";
                    }
                   }
                   break;

        }
    }while(ch!=5);

}
