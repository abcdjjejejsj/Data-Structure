//binary tree
#include<iostream>
using namespace std;
class BT{
    public:
    int age,gg;
    string name,prof;
    BT *left;
    BT *right;
    int cn,cl,hgt;
    BT()
    {

    }
    BT(string nme,int ag,string pro)
    {
        name=nme;
        age=ag;
        prof=pro;
        left=NULL;
        right=NULL;
    }
    void insert(BT *current,BT *temp)
    {
        
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
            cout<<"Name : "<<index->name<<"\nProfession : "<<index->prof<<"\nAge : "<<index->age<<"\n\n";
            preorder(index->left);
            preorder(index->right);
        }
    }
    void search(BT *index,string temName)
    {
        if(index->name==temName)
        {
            gg=1;
            cout<<"Member found successfully !"<<endl;
            cout<<"Member details : "<<endl;
            cout<<"Name : "<<index->name<<"\nProfession : "<<index->prof<<"\nAge : "<<index->age<<"\n\n";
        }else if(index==NULL)
        {
           return;
        }else{
           
            preorder(index->left);
            preorder(index->right);
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
        if (index == NULL) return;
        if(index->left==NULL && index->right==NULL)
        {
            cl++;
            cout<<"Name : "<<index->name<<"\nProfession : "<<index->prof<<"\nAge : "<<index->age<<"\n\n";
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
int height(BT* index) {
        if (index == NULL) return -1;
        int leftHeight = height(index->left);
        int rightHeight = height(index->right);
        return max(leftHeight, rightHeight) + 1;
    }
   
    bool findAncestors(BT* root, string target) {
        if (root == NULL) return false;
        
        if (root->name == target) return true;

        // If target is found in left or right subtree, print current node as ancestor
        if (findAncestors(root->left, target) || findAncestors(root->right, target)) {
            cout<<"Name : "<<root->name<<"\nProfession : "<<root->prof<<"\nAge : "<<root->age<<"\n\n";
            return true;
        }

        return false;
    }
};
int main()
{
    int ch,no,a;
    string temp,nn,pp;
    BT *root,*newnode;
    BT b;
    do{
        cout<<"\n1.Create\t2.insert\t3.Preorder\t4.No.of nodes\t5.No.of leaf nodes\t6.height of the tree\t7.Ancestor\t8.Search\t9.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://create
                   cout<<"Enter Name:";
                   cin>>nn;
                   cout<<"Enter Profession:";
                   cin>>pp;
                   cout<<"Enter age:";
                   cin>>a;
                   root=new BT(nn,a,pp);
                   b.cn=1;
                   b.cl=0;
                   break;
            case 2://insert
                    cout<<"Enter Name:";
                    cin>>nn;
                    cout<<"Enter Profession:";
                    cin>>pp;
                    cout<<"Enter age:";
                    cin>>a;
                    newnode=new BT(nn,a,pp);
                    b.insert(root,newnode);
                    break;
            case 3://preorder display
                    b.preorder(root);
                    break;
            case 4://node count
                 b.cn=0;
                
                   b.count(root);
                   cout<<"\nNo.of nodes : "<<b.cn<<endl;
                   break;
            case 5://no.of leaf node
                   b.cl=0;
                   b.noleaf(root);
                   cout<<"\nNo.of leaf nodes : "<<b.cl<<endl;
                break;
            case 6://height of the tree
                   cout << "Height of the tree is: " << b.height(root) << endl;
                   break;
            case 7: // Find Ancestors
                cout << "Enter node to find ancestors: ";
                cin >> temp;
                cout << "Ancestors of " << temp << ": ";
                if (!b.findAncestors(root, temp)) {
                    cout << "No ancestors found (node not in tree or root node selected)." << endl;
                } else {
                    cout << endl;
                }
                break;
            case 8://serching 
                  b.gg=0;
                  cout<<"Enter name of thge member for search : ";
                  cin>>temp;
                  b.search(root,temp);
                  if(b.gg==0)
                  {
                    cout<<"Member NOT found !"<<endl;
                  }
                  break;

                   
        }
    }while(ch!=9);
}