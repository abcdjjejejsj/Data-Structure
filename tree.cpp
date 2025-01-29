//binary tree
#include<iostream>
using namespace std;
class BT{
    public:
    int data;
    BT *left;
    BT *right;
    BT()
    {

    }
    BT(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
    void insert(BT *current,BT *temp)
    {
        int s;
        char ch1;
        if(current==NULL)
        {
            current=temp;
        }else{
            cout<<"enter left(l)/right(r):";
            cin>>ch1;
            if(ch1=='l' || ch1=='L')
            {
                if(current->left==NULL)
                {
                    current->left=temp;
                }else{
                    cout<<"left is NOT NULL\n";
                    insert(current->left,temp);

                }
            }else{
                if(current->right==NULL)
                {
                    current->right=temp;
                }else{
                    cout<<"right is NOT NULL\n";
                    insert(current->right,temp);

                }
            }
        }
    }
    void display(BT *index)
    {
        if(index==NULL)
        {
            return;
        }else{
            cout<<index->data<<"\t";
            display(index->left);
            display(index->right);
            
        }
     
    }
};
int main()
{
    int ch,s;
    BT *root,*newnode;
    BT b;
    do{
        cout<<"\n1)Create\t2)insert\t3.Display\t4.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://create
                   cout<<"Enter data:";
                   cin>>s;
                   root=new BT(s);
                   break;
            case 2://insert
                   cout<<"Enter data:";
                   cin>>s;
                   newnode=new BT(s);
                   b.insert(root,newnode);
                   break;
            case 3://display
                    b.display(root);
           
                   
        }
    }while(ch!=4);
}
