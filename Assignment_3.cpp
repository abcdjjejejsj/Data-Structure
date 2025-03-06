//assignment-3 of flight path
#include<iostream>
using namespace std;
class matrix{
    public:
    int m[100][100];
    matrix()
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                m[i][j]=0;
            }
        }
    }

    void edge(int x,int y)
    {
        m[x][y]=1;
        m[y][x]=1;
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
    matrix am;
    int ch,vertex,edges,v1,v2,no,d;
    int arr[20];
    list *hed[20],*temp;
    list l;
    do{
        cout<<"\n1.Adjancancy matrix\t2.Output(AM)\t3.Adjacency list\t4.Output(AL)\t5.Exit\nEnter choice :";
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
                    for(int i=0;i<edges;i++)
                    {
                        cout<<"edge-"<<i+1<<endl;
                        cout<<"\tvertiex-1 :";
                        cin>>v1;
                        cout<<"\tvertiex-2 :";
                        cin>>v2;
                        am.edge(v1,v2);
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
            case 3://adjacency list
                   cout<<"Enter no.of vertices :";
                   cin>>vertex;
                   cout<<"Enter vertex :"<<endl;
                   for(int i=0;i<vertex;i++)
                   {
                    cout<<"vertex-"<<i+1<<": ";
                    cin>>arr[i];
                   }
                   for(int i=0;i<vertex;i++)
                   {
                    hed[i]=NULL;
                    cout<<"Enter no.of adjacent vertices for vertex-"<<arr[i]<<" :";
                    cin>>no;
                    for(int j=0;j<no;j++)
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
                   
                   }
                 break;

            case 4://display
                   for(int i=0;i<vertex;i++)
                   {
                    cout<<arr[i]<<"-->";
                    l.display(hed[i]);
                    cout<<endl;
                   }
                   break;

        }
    }while(ch!=5);
}
