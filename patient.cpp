#include <iostream>
using namespace std;

class Patient {
public:
    int patientID;
    string name;
    string medicalHistory;
    int pos;

    Patient() {
        patientID = 0;
        name = "";
        medicalHistory = "";
        pos = -1;
    }

    Patient(int id, string n, string history) {
        patientID = id;
        name = n;
        medicalHistory = history;
        pos = 1;
    }
};

class MedicalRecordSystem {
public:
    Patient records[10];
    int size = 10;
    int count = 0;

    int hashv(int key) {
        return key % size;
    }

    void accept() {
        int id;
        string n, history;
        cout << "\nEnter patient name: ";
        cin >> n;
        cout << "Enter patient ID: ";
        cin >> id;
        cout << "Enter medical history: ";
        cin >> history;

        int index = hashv(id);

        int cnt = 0;
        while (records[index].pos == 1 && cnt < size) {
            cout << "Collision occurred at index: " << index << endl;
            index = (index + cnt * cnt) % size;  // Quadratic probing
            cnt++;
        }

        if (cnt == size) {
            cout << "\nMedical Record System is full. Can't insert more records.\n";
            return;
        }

        records[index] = Patient(id, n, history);
        cout << "Record inserted at index: " << index << endl;
        count++;
    }

    void display() {
        cout << "\n--- Medical Record System Contents ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << "] ";
            if (records[i].pos == 1) {
                cout << "Name: " << records[i].name << ", Patient ID: " << records[i].patientID << ", Medical History: " << records[i].medicalHistory << "\n";
            } else if (records[i].pos == -1) {
                cout << "Empty\n";
            } else if (records[i].pos == -2) {
                cout << "Deleted\n";
            }
        }
        cout << endl;
    }

    void del() {
        int id;
        cout << "\nEnter Patient ID to delete: ";
        cin >> id;

        int index = hashv(id);
        int cnt = 0;

        while (cnt < size) {
            if (records[index].pos == 1 && records[index].patientID == id) {
                records[index].pos = -2;
                cout << "Record with ID " << id << " deleted.\n";
                return;
            }
            index = (index + cnt * cnt) % size;  // Quadratic probing
            cnt++;
        }

        cout << "Record not found. Can't delete.\n";
    }
    
    void update() {
        int target;
        cout << "Enter Patient ID to update record: ";
        cin >> target;
        int index = hashv(target);
        int cnt = 0;
        while (cnt < size) {
            if (records[index].pos == 1 && records[index].patientID == target) {
                int id;
                string n, history;
                cout << "\nEnter updated patient name: ";
                cin >> n;
                cout << "Enter updated medical history: ";
                cin >> history;
                records[index].name = n;
                records[index].medicalHistory = history;
                cout << "Record with ID " << id << " updated successfully!\n";
                return;
            }
            index = (index + cnt * cnt) % size;  // Quadratic probing
            cnt++;
        }

        cout << "Record not found. Can't update.\n";
    }

    void search() {
        int target;
        cout << "Enter Patient ID to search record: ";
        cin >> target;
        int index = hashv(target);
        int cnt = 0;
        while (cnt < size) {
            if (records[index].pos == 1 && records[index].patientID == target) {
                cout << "Index: " << index << "\nID: " << records[index].patientID << "\nName: " << records[index].name << "\nMedical History: " << records[index].medicalHistory << endl;
                return;
            }
            index = (index + cnt * cnt) % size;  // Quadratic probing
            cnt++;
        }

        cout << "Record not found. Can't search.\n";
    }
};

int main() {
    MedicalRecordSystem system;
    int choice;

    do {
        cout << "\n1.Insert\n2.Display\n3.Delete\n4.Update\n5.Search\n6.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.accept();
                break;
            case 2:
                system.display();
                break;
            case 3:
                system.del();
                break;
            case 4:
                system.update();
                break;
            case 5:
                system.search();
                break;
            case 6:  // Exit
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
