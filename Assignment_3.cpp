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
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
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
    void insert(list *&head,list *temp)
    {
        
        if(head==NULL)
        {
            head=temp;
        }else{
            list *current=head;
            while(current->next!=NULL)
            {
                current = current->next;
            }
            current->next=temp;
        }
    }
    void display(list *current)
    {
        if(current==NULL)
        {
            return;
        }
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
int main()
{
    Graph g;
    Graph *c;
    list *hed[20],*temp;
    list l;
    int a[20];
    int ch,vertex,edges,v1,v2,i,j,cnt=0,no,d,n;
    for(int i = 0; i < 20; i++) {
        hed[i] = NULL;
    }
    
    do{
        cout<<"\n1.Adjancancy matrix\t2.Output(AM)\t3.Adjacency list\t4.Output(AL)\t5.Exit\nEnter choice :";
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
                    cin>>v1>>v2;
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
                   cout<<"Enter vertex :"<<endl;
                   for(i=0;i<vertex;i++)
                   {
                    cout<<"vertex-"<<i+1<<": ";
                    cin>>a[i];
                   }
                   for(i=0;i<vertex;i++)
                   {
                    hed[i]=NULL;
                    cout<<"Enter no.of adjacent vertices for vertex-"<<a[i]<<" :";
                    cin>>no;
                    for(j=0;j<no;j++)
                    {
                        cout<<"vertex-"<<j+1<<" :";
                        cin>>d;
                        temp=new list(d);
                        if(hed[i]==NULL)
                        {
                            hed[i]=temp;
                        }else{
                        l.insert(hed[i],temp);
                        }
                    }
                    cnt++;
                   }

                 break;
                   
            case 4://display
                   for(i=0;i<cnt;i++)
                   {
                    cout<<a[i]<<"-->";
                    l.display(hed[i]);
                    cout<<endl;
                   }
                   break;

        }
    }while(ch!=5);

}
