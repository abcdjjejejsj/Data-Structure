#include <iostream>
using namespace std;

class student {
public:
    int roll;
    string name;
    int marks;
    int pos; // -1 = Empty, -2 = Deleted, 1 = Occupied

    student() {
        roll = 0;
        name = "";
        marks = 0;
        pos = -1;
    }

    student(int r, string n, int m) {
        roll = r;
        name = n;
        marks = m;
        pos = 1;
    }
};

class Hash {
public:
    student s[10];
    int size = 10;
    int count = 0;

    int hashv(int key) {
        return key % size;
    }

    void accept() {
        int roll, mark;
        string name;
        cout << "\nEnter name : ";
        cin >> name;
        cout << "Enter roll no : ";
        cin >> roll;
        cout << "Enter marks : ";
        cin >> mark;

        int index = hashv(roll);

        // Linear probing
        int cnt = 0;
        while ((s[index].pos == 1) && cnt < size) {
            index = (index + 1) % size;
            cnt++;
        }

        if (cnt == size) {
            cout << "\nHash table is full. Can't insert more records.\n";
            return;
        }

        s[index] = student(roll, name, mark); // Constructor sets pos = 1
        count++;
    }

    void display() {
        cout << "\n--- Hash Table Contents ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << "] ";
            if (s[i].pos == 1) {
                cout << "Name: " << s[i].name << ", Roll no: " << s[i].roll << ", Marks: " << s[i].marks << endl;
            } else if (s[i].pos == -1) {
                cout << "Empty" << endl;
            } else if (s[i].pos == -2) {
                cout << "Deleted" << endl;
            }
        }
        cout << endl;
    }

    void del() {
        int roll;
        cout << "\nEnter Roll no to delete record: ";
        cin >> roll;

        int index = hashv(roll);
        int cnt = 0;

        while (cnt < size) {
            if (s[index].pos == 1 && s[index].roll == roll) {
                s[index].pos = -2;
                cout << "Record with roll no " << roll << " deleted.\n";
                return;
            }
            index = (index + 1) % size;
            cnt++;
        }

        cout << "Record not found. Can't delete.\n";
    }
};

int main() {
    Hash h;
    int choice;

    do {
        cout << "\n1. Insert\n2. Display\n3. Delete\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.accept();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.del();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
