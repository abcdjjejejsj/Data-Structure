//binary tree operations
#include<iostream>
#include<stack>
using namespace std;
class BT{
    public:
    int data;
    BT *left;
    BT *right;
    int total_c,leaf,a,res,flag=0;
    BT(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
    BT()
    {

    }
    
    //insertion 
    void insert(BT *current,BT *key)
    {
        char op;
        if(current==NULL)
        {
            current=key;
            return;
        }
        cout<<"left or right (l/r):";
        cin>>op;
        if(op=='l')
        {
            if(current->left==NULL)
            {
                current->left=key;
            }else{
                cout<<"\nleft is not null"<<endl;
                insert(current->left,key);
            }
        }
        if(op=='r')
        {
            if(current->right==NULL)
            {
                current->right=key;
            }else{
                cout<<"\nright is not null"<<endl;
                insert(current->right,key);
            }
        }
    }
    //recursive approach
    // void preorder(BT *current)
    // {
    //     if(current==NULL)
    //     {
    //         return;
    //     }
    //     cout<<current->data<<"\t";
    //     preorder(current->left);
    //     preorder(current->right);
    // }

    //iterative approach
    void preorder(BT *current)
    {
        stack<BT*>s;
        s.push(current);
        while(!s.empty())
        {
            cout<<s.top()->data<<"\t";
            current=s.top();
             s.pop();
            if(current->right!=NULL)
            {

                s.push(current->right);
            }
            if(current->left!=NULL)
            {

                s.push(current->left);
            }
        }
        
    }
    //recursive approach
    // void inorder(BT *current)
    // {
    //     if(current==NULL)
    //     {
    //         return;
    //     }
    //     preorder(current->left);
    //     cout<<current->data<<"\t";
    //     preorder(current->right);
    // }

    //iterative approach
    void inorder(BT *current)
    {
        stack<BT*>s;
        s.push(current);
        while(current!=NULL || !(s.empty()))
        {
            current=current->left;
            s.push(current);
            while(!s.empty())
            {
            cout<<s.top()->data<<"\t";
            current=s.top();
            s.pop();
            }
            current=current->right;
        }
        
    }
    void postorder(BT *current)
    {
        if(current==NULL)
        {
            return;
        }
        preorder(current->left);
        preorder(current->right);
        cout<<current->data<<"\t";
    }
    void total(BT *current)
    {
        if(current==NULL)
        {
            return;
        }
        total_c++;
        total(current->left);
        total(current->right);
    }
    void total_leaf(BT *current)
    {
        if(current==NULL)
        {
            return;
        }
        if(current->left==NULL && current->right==NULL)
        {
            cout<<"\ncurrent->data = "<<current->data<<"\tleaf :"<<leaf<<endl;
            leaf++;
            cout<<"\nleaf++ :"<<leaf<<endl;
        }
       
            total_leaf(current->left);
     
            total_leaf(current->right);
    }
    void small(BT *current,int b)
    {
        if(current==NULL)
        {
            return;
        }
         a=current->data;
         if(a<b)
         {
            res=a;
         }else{
            res=b;
         }
         if(current->left!=NULL)
         {
            small(current->left,b);
         }else if(current->right!=NULL)
         {
            small(current->right,b);
         }
    }
    void large(BT *current,int b)
    {
        if(current==NULL)
        {
            return;
        }
         a=current->data;
         if(a>b)
         {
            res=a;
         }else{
            res=b;
         }
         if(current->left!=NULL)
         {
            large(current->left,b);
         }else if(current->right!=NULL)
         {
            large(current->right,b);
         }
    }
    void family(BT *current, int ky, BT *parent = NULL) {
        if (current == NULL) {
            return;
        }
    
        // Found the node
        if (current->data == ky) {
            cout << "Node: " << ky << endl;
    
            // Print Parent (Father)
            if (parent != NULL) {
                cout << "Father: " << parent->data << endl;
            } else {
                cout << "Father: NOT found" << endl;
            }
    
            // Print Sibling (Brother)
            if (parent != NULL) {
                if (parent->left == current && parent->right) {
                    cout << "Brother: " << parent->right->data << endl;
                } else if (parent->right == current && parent->left) {
                    cout << "Brother: " << parent->left->data << endl;
                } else {
                    cout << "Brother: None" << endl;
                }
            } else {
                cout << "Brother: None" << endl;
            }
    
            // Print Left Child
            if (current->left!=NULL) {
                cout << "LC: " << current->left->data << endl;
            } else {
                cout << "LC: None" << endl;
            }
    
            // Print Right Child
            if (current->right!=NULL) {
                cout << "RC: " << current->right->data << endl;
            } else {
                cout << "RC: None" << endl;
            }
    
            return;
        }
    
        // Recursively search in left and right subtrees
        family(current->left, ky, current);
        family(current->right, ky, current);
    }
    
};
int main()
{
    int ch,x,key;
    BT b;
    BT *root,*temp;
    do{
        cout<<"\n1.Create\t2.Insert\t3.preorder\t4.Inorder\t5.Postorder\t6.Total nodes\t7.No.of leaf nodes\t8.Small element\t9.Large element\t10.Family\t11.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://creation
                  b.total_c=0;
                  cout<<"Enter data:";
                  cin>>x;
                  root = new BT(x);
                  break;
            case 2://inserting new node to tree
                    cout<<"Enter data:";
                    cin>>x;
                    temp =new BT(x);
                    b.insert(root,temp);
                    break;
            case 3://preorder
                    cout<<"\nTree elemnts are :";
                    b.preorder(root);
                    break;
            case 4://Inorder
                    cout<<"\nTree elemnts are :";
                    b.inorder(root);
                    break;
            case 5://postorder
                    cout<<"\nTree elemnts are :";
                    b.postorder(root);
                    break;
            case 6://total no.of nodes
                    b.total_c=0;
                    b.total(root);
                    cout<<"\ntotal no.of nodes : "<<b.total_c<<endl;
                    break;
            case 7://total no.of leaf nodes
                    b.leaf=0;
                    b.total_leaf(root);
                    cout<<"\ntotal no.of leaf nodes : "<<b.leaf<<endl;
                    break;
                    
            case 8:// smallest element
                  b.small(root,root->data);
                  cout<<"\nsmallest element :"<<b.res<<endl;
                  break;
            case 9:// largest element
                  b.large(root,root->data);
                  cout<<"\nLargest element :"<<b.res<<endl;
                  break;
            case 10://find family of node
                    b.flag=0;
                    cout<<"Enter the key :";
                    cin>>key;
                    b.family(root,key);
                    break;

        }
    }while(ch!=11);
}
