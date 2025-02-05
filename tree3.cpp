//binary tree
#include<iostream>
using namespace std;
class BT{
    public:
    int data;
    BT *left;
    BT *right;
    int cn,cl,hgt;
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

    void count(BT *index)
    {
        if(index==NULL)
        {
           return;
        }else{
            cn++;
            count(index->left);
            count(index->right);
            
        }
    }
    void noleaf(BT *index)
    {
        if(index->left==NULL && index->right==NULL)
        {
            cl++;
            cout<<index->data;
            return;
        }else if(index->left!=NULL && index->right!=NULL){
            noleaf(index->left);
            noleaf(index->right);
        }else if(index->left!=NULL)
        {
            noleaf(index->left);
        }else if(index->right!=NULL)
        {
            noleaf(index->right);
        }
        
    }

    // void height(BT *index)
    // {
    //     if(index->left!=NULL)
    //     {
    //         hgt++;
    //         height(index->left);
    //         if(index->right!=NULL)
    //         {
    //             height(index->right);
    //         }
    //     }else if(index->right!=NULL)
    //     {
    //         hgt++;
    //         height(index->right);
    //     }else{
    //         return;
    //     }
    // }

   
};
int main()
{
    int ch,s,no,temp;
    BT *root,*newnode;
    BT b;
    do{
        cout<<"\n1.Create\t2.insert\t3.Preorder\t4.Inorder\t5.Postorder\t6.No.of nodes\t7.No.of leaf nodes\t8.height of the tree\t9.Ancestor\t10.Exit\nEnter choice:";
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
                 b.cn=0;
                
                   b.count(root);
                   cout<<"\nNo.of nodes : "<<b.cn<<endl;
                   break;
            case 7://no.of leaf node
                   b.cl=0;
                   b.noleaf(root);
                   cout<<"\nNo.of leaf nodes : "<<b.cl<<endl;
                break;
            case 8://height of the tree
                   b.hgt=0;
                   b.height(root);
                   cout<<"Height of the tree is : "<<b.hgt<<endl;
                   break;
            // case 9://ancestor of node
            //        cout<<"Enter node for finding ancestor : ";
            //        cin>>temp;
            //        b.search(temp,index)

                   
        }
    }while(ch!=10);
}