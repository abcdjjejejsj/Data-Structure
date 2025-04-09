#include <iostream>
using namespace std;
class student
{
public:
    int roll;
    string name;
    int marks;
    int pos;
    student()
    {

    }

    student(int r, string n, int m)
    {
        roll = r;
        name = n;
        marks = m;
        pos=1;
    }
} ;
class Hash
{
    public:
    student s[10];
    int size = 10;
    int count = 0;
    Hash(){
        for(int i=0;i<10;i++)
        {
        s[i].pos = -1;
        }
    }
    
    int hashv(int key)
    {
        int res = key % size;
        return res;
    }
    void accept()
    {
        int rol, mark;
        string nav;
        cout << "Enter name : ";
        cin >> nav;
        cout << "Enter roll no : ";
        cin >> rol;
        cout << "Enter marks : ";
        cin >> mark;
        int ky = hashv(rol);
        if (s[ky].pos == -1)
        {
            s[ky] =student(rol, nav, mark);
        }
        else
        {
            int cnt=0;
            while (s[ky].pos != -1 && ky < size && cnt<size)
            {
                ky++;
                cnt++;
                if(ky>=size)
                {
                    ky=0;
                }
            }
            if(s[ky].pos == -1)
            {
               s[ky]=student(rol, nav, mark);
               s[ky].pos=1;
               count++;
            }else{
                cout<<"\nHash table is full.Can't insert more record\n";
            }
        }
        
       
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if(s[i].pos!=-1)
            {
                cout << i<< "]Name : " << s[i].name << endl;
                cout << "Roll no : " << s[i].roll << endl;
                cout << "Marks : " << s[i].marks << endl;
                cout << "\n\n";
            }
            
        }
    }
}; 
int main()
{
    Hash h;
    int ch;
    do
    {
        cout << "1.Insert\t2.display\t3.delete\t4.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: // insert
                h.accept();
                break;
        case 2://display
              h.display();
              break;
        case 3://delete
               break;
        case 4://exit
               break;
        }
    }while(ch!=4);
}
