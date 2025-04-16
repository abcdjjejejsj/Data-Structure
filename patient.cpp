#include <iostream>
using namespace std;

class MedicalRecord {
public:
    int patientID;
    string name;
    string diagnosis;
    int pos; // -1 = Empty, -2 = Deleted, 1 = Occupied

    MedicalRecord() {
        patientID = 0;
        name = "";
        diagnosis = "";
        pos = -1;
    }

    MedicalRecord(int id, string n, string d) {
        patientID = id;
        name = n;
        diagnosis = d;
        pos = 1;
    }
};

class MedicalRecordSystem {
public:
    MedicalRecord records[10];
    int size = 10;
    int count = 0;

    int hashv(int key) {
        return key % size;
    }

    void accept() {
        int id;
        string n, d;
        cout << "\nEnter patient name: ";
        cin >> n;
        cout << "Enter patient ID: ";
        cin >> id;
        cout << "Enter diagnosis: ";
        cin >> d;

        int index = hashv(id);

        // Linear probing
        int cnt = 0;
        while ((records[index].pos == 1) && cnt < size) {
            index = (index + 1) % size;
            cnt++;
        }

        if (cnt == size) {
            cout << "\nMedical record system is full. Cannot insert more records.\n";
            return;
        }

        records[index] = MedicalRecord(id, n, d);
        count++;
    }

    void display() {
        cout << "\n--- Medical Record Table ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << "] ";
            if (records[i].pos == 1) {
                cout << "Name: " << records[i].name << ", Patient ID: " << records[i].patientID << ", Diagnosis: " << records[i].diagnosis << "\n";
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
        cout << "\nEnter Patient ID to delete record: ";
        cin >> id;

        int index = hashv(id);
        int cnt = 0;

        while (cnt < size) {
            if (records[index].pos == 1 && records[index].patientID == id) {
                records[index].pos = -2;
                cout << "Record with Patient ID " << id << " deleted.\n";
                return;
            }
            index = (index + 1) % size;
            cnt++;
        }

        cout << "Record not found. Cannot delete.\n";
    }
};

int main() {
    MedicalRecordSystem system;
    int choice;

    do {
        cout << "\n1. Add Medical Record\n2. Display Records\n3. Delete Record\n4. Exit\nEnter choice: ";
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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
