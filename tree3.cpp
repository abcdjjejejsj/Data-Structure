//binary tree
#include<iostream>
using namespace std;
class BT{
    public:
    int data;
    BT *left;
    BT *right;
    int cn,cl;
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
    void preorder(BT *index)
    {
        if(index==NULL)
        {
            return;
        }else{
            cout<<index->data<<"\t";
            preorder(index->left);
            preorder(index->right);
        }
    }
    void inorder(BT *index)
    {
        if(index==NULL)
        {
            return;
        }else{
            inorder(index->left);
            cout<<index->data<<"\t";
            inorder(index->right);
        }
    }
    void postorder(BT *index)
    {
        if(index==NULL)
        {
            return;
        }else{
            postorder(index->left);
            postorder(index->right);
            cout<<index->data<<"\t";
        }
    }

    void count(BT *index,int cnt)
    {
        if(index==NULL)
        {
           return;
        }else{
            cnt++;
            count(index->left,cnt);
            count(index->right,cnt);
            
        }
        cn=cnt;
    }
    void noleaf(BT *index,int cntl)
    {
        if(index->left==NULL && index->right==NULL)
        {
            cntl++;
        }else{
            noleaf(index->left,cntl);
            noleaf(index->right,cntl);
        }
        cl=cntl;
    }
};
int main()
{
    int ch,s,no;
    BT *root,*newnode;
    BT b;
    do{
        cout<<"\n1.Create\t2.insert\t3.Preorder\t4.Inorder\t5.Postorder\t6.No.of nodes\t7.No.of leaf nodes\t8.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://create
                   cout<<"Enter data:";
                   cin>>s;
                   root=new BT(s);
                   b.cn=1;
                   b.cl=0;
                   break;
            case 2://insert
                   cout<<"Enter data:";
                   cin>>s;
                   newnode=new BT(s);
                   b.insert(root,newnode);
                   break;
            case 3://preorder display
                    b.preorder(root);
                    break;
            case 4://inorder
                    b.inorder(root);
                    break;
            case 5://postorder
                   b.postorder(root);
                   break;
            case 6://node count
                //    b.cn=0;
                
                   b.count(root,b.cn);
                   cout<<"\nNo.of nodes : "<<b.cn<<endl;
                   break;
            case 7://no.of leaf node
                //    b.cl=0;
                   b.noleaf(root,b.cl);
                   cout<<"\nNo.of leaf nodes : "<<b.cl<<endl;
           
                   
        }
    }while(ch!=8);
}