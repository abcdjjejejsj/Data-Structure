#include <iostream>
using namespace std;

class Track {
public:
    int trackID;
    string title;
    int duration; // in seconds
    int pos; // -1 = Empty, -2 = Deleted, 1 = Occupied

    Track() {
        trackID = 0;
        title = "";
        duration = 0;
        pos = -1;
    }

    Track(int id, string t, int d) {
        trackID = id;
        title = t;
        duration = d;
        pos = 1;
    }
};

class MusicLibrary {
public:
    Track tracks[10];
    int size = 10;
    int count = 0;

    int hashv(int key) {
        return key % size;
    }

    void accept() {
        int id, dur;
        string t;
        cout << "\nEnter track title: ";
        cin >> t;
        cout << "Enter track ID: ";
        cin >> id;
        cout << "Enter duration (in seconds): ";
        cin >> dur;

        int index = hashv(id);

        // Linear probing
        int cnt = 0;
        while ((tracks[index].pos == 1) && cnt < size) {
            index = (index + 1) % size;
            cnt++;
        }

        if (cnt == size) {
            cout << "\nMusic Library is full. Can't insert more tracks.\n";
            return;
        }

        tracks[index] = Track(id, t, dur);
        count++;
    }

    void display() {
        cout << "\n--- Music Library Contents ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << "] ";
            if (tracks[i].pos == 1) {
                cout << "Title: " << tracks[i].title << ", Track ID: " << tracks[i].trackID << ", Duration: " << tracks[i].duration << "s\n";
            } else if (tracks[i].pos == -1) {
                cout << "Empty\n";
            } else if (tracks[i].pos == -2) {
                cout << "Deleted\n";
            }
        }
        cout << endl;
    }

    void del() {
        int id;
        cout << "\nEnter Track ID to delete: ";
        cin >> id;

        int index = hashv(id);
        int cnt = 0;

        while (cnt < size) {
            if (tracks[index].pos == 1 && tracks[index].trackID == id) {
                tracks[index].pos = -2;
                cout << "Track with ID " << id << " deleted.\n";
                return;
            }
            index = (index + 1) % size;
            cnt++;
        }

        cout << "Track not found. Can't delete.\n";
    }
};

int main() {
    MusicLibrary lib;
    int choice;

    do {
        cout << "\n1. Add Track\n2. Show Library\n3. Delete Track\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.accept();
                break;
            case 2:
                lib.display();
                break;
            case 3:
                lib.del();
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
