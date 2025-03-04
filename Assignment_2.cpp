//employee database using binary search tree
#include<iostream>
using namespace std;
class Employee{
    public:
    int salary;
    string name;
    int id;
    Employee *left;
    Employee *right;
    Employee()
    {

    }
    Employee(string nme,int sal,int ID)
    {
        name=nme;
        salary=sal;
        id=ID;
        left=NULL;
        right=NULL;
    }

    void insert(Employee *current,Employee *node)
    {
        Employee *prev;
        if(current==NULL)
        {
            current=node;
        }else{
            while(current!=NULL)
            {
                prev=current;
                if(current->salary<node->salary)
                {
                    current=current->right;
                }else{
                    current=current->left;
                }
            }
            if(prev->salary<node->salary)
            {
                prev->right=node;
            }else{
                prev->left=node;
            }
        }
    }

    void display(Employee *current)
    {
        if(current==NULL)
        {
            return;
        }
        display(current->left);
        cout<<"ID : "<<current->id<<" Name :"<<current->name<<" Salary :"<<current->salary<<endl;
        display(current->right);
    }

    void search(Employee *current,int ss)
    {
        int count=0;
        if(current==NULL)
        {
            cout<<"List is empty"<<endl;
        }else{
            while(current!=NULL)
            {
                if( current->salary==ss)
                {
                    cout<<"ID : "<<current->id<<" Name :"<<current->name<<" Salary :"<<current->salary<<endl;
                    count++;
                }
                if(current->salary<ss)
                {
                    current=current->right;
                }else{
                    current=current->left;
                }
            }
            if(count==0)
            {
                cout<<"Employee NOT Exist !"<<endl;
            }
        }
    }

    void update(Employee *current,int ss)
    {
        int flag=0,mch,n=0,mch2;
        if(current==NULL)
        {
            cout<<"List is empty"<<endl;
        }else{
            while(flag!=1 && current!=NULL)
            {
                if( current->salary==ss)
                {
                    cout<<" Employee details :\nID : "<<current->id<<" Name :"<<current->name<<" Salary :"<<current->salary<<endl;
                    cout<<"do you want to update this details(press 1 for yes) :";
                    cin>>mch2;
                    if(mch2==1)
                    {
                    cout<<"What do you want update 1)Name\t2)ID\t3)Both :";
                    cin>>mch;
                    switch(mch)
                    {
                        case 1://name
                               cout<<"Enter new name :";
                               cin>>current->name;
                               break;
                        case 2://ID
                               cout<<"Enter new ID :";
                               cin>>current->id;
                               break;
                        case 3://both
                                cout<<"Enter new name :";
                                cin>>current->name;
                                cout<<"Enter new ID :";
                                cin>>current->id;
                                break;
                        default:cout<<"Wrong choice"<<endl;
                    }
                    flag=1;
                   }
                  
                }
                if(mch!=1)
                {

                }
                if(current->salary<ss)
                {
                    current=current->right;
                }else{
                    current=current->left;
                }
            }
        }
    }

    void min(Employee *current)
    {
        if(current==NULL)
        {
            cout<<"List is empty !"<<endl;
            return;
        }
        while(current->left!=NULL)
        {
            current=current->left;
        }
        cout<<"Minimum salary :"<<current->salary<<endl;

    }
    void max(Employee *current)
    {
        if(current==NULL)
        {
            cout<<"List is empty !"<<endl;
            return;
        }
        while(current->right!=NULL)
        {
            current=current->right;
        }
        cout<<"Maximum salary :"<<current->salary<<endl;
    }
    float avg(Employee *current,float &sm,float &cnt)
    {
        if(current==NULL)
        {
            return 0;
        }
        avg(current->left,sm,cnt);
        sm+=current->salary;
        cnt++;
        avg(current->right,sm,cnt);
        return sm/cnt;
    }
    int total(Employee *current,int &cnt)
    {
        if(current==NULL)
        {
            return 0;
        }
        total(current->left,cnt);
        cnt++;
        total(current->right,cnt);
        return cnt;
    }
   void del(Employee *&current, int ss) 
{
  
    Employee *prev = NULL;

    if (current == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Employee *target = current;
    while (target != NULL && target->salary != ss)
    {
        
       
        prev = target;
        if (target->salary < ss)
        {
            target = target->right;
        }
        else
        {
            target = target->left;
        }
    }

    if (target == NULL)
    {
        cout << "Node NOT found !" << endl;
        return;
    }

   
 ;

    if (target->left == NULL && target->right != NULL)
    {
        if (prev != NULL) 
        {
            if (prev->left == target)
            {
                prev->left = target->right;
            }
            else
            {
                prev->right = target->right;
            }
        }
        else
        {
            current = target->right;
        }
    }
    else if (target->left != NULL && target->right == NULL)
    {
       
        if (prev != NULL) 
        {
            if (prev->left == target)
            {
              
                prev->left = target->left;
            }
            else
            {
                prev->right = target->left;
            }
        }
        else
        {
            current = target->left;
        }
    }
    else if (target->left == NULL && target->right == NULL)
    {
        if (prev != NULL)
        {
            if (prev->left == target)
            {
                prev->left = NULL;
            }
            else
            {
                prev->right = NULL;
            }
        }
        else
        {
            current = NULL;
        }
    }
    else if (target->left != NULL && target->right != NULL)
    {
        prev = target;
        Employee *temp = target->right; 

        while (temp->left != NULL)
        {
            prev = temp;
            temp = temp->left;
        }

        target->salary = temp->salary;

        if (prev->left == temp)
        {
            prev->left = temp->right;
        }
        else
        {
            prev->right = temp->right;
        }

        delete temp; 
        return;
    }

    delete target; 
}


};
int main()
{
    Employee e;
    int ch,s,Id,t,cc;
    float sum,cnt;
    string nam;
    Employee *root,*temp;
    do{
        cout<<"\n1.Create\t2.Insert\t3.Search\t4.Update\t5.Display\t6.Minimum salary\t7.Maximum salary\t8.Average salary\t9.Total employee\t10.Delete\t11.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://create
                  cout<<"Enter name:";
                  cin>>nam;
                  cout<<"Enter ID :";
                  cin>>Id;
                  cout<<"Enter Salary :";
                  cin>>s;
                  root = new Employee(nam,s,Id);
                  break;
            case 2://insert
                  cout<<"Enter name:";
                  cin>>nam;
                  cout<<"Enter ID :";
                  cin>>Id;
                  cout<<"Enter Salary :";
                  cin>>s;
                  temp = new Employee(nam,s,Id);
                  e.insert(root,temp);
                  break;
            case 3://search
                  cout<<"Enter Salary :";
                  cin>>s;
                  e.search(root,s);
                  break;
            case 4://update
                   cout<<"Enter Salary :";
                   cin>>s;
                   e.update(root,s);
                   break;
            case 5://display
                   e.display(root);
                   break;
            case 6://min sal
                    e.min(root);
                    break;
            case 7://max sal
                    e.max(root);
                    break;
            case 8://avg sal
                    sum=0;
                    cnt=0;
                    sum=e.avg(root,sum,cnt);
                    cout<<"Average salary :"<<sum;
                    break;
            case 9://total emp
                    cc=0;
                    t=e.total(root,cc);
                    cout<<"Total employee :"<<t<<endl;
                    break;
            case 10://delete
                    cout<<"Enter salary for search :";
                    cin>>s;
                    e.del(root,s);
                    break;
            case 11://exit..
                   break;
            default:cout<<"Wrong choice"<<endl;

        }
    }while(ch!=11);

}
