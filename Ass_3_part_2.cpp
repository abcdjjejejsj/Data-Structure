#include<iostream>
using namespace std;

class matrix {
public:
    int m[100][100];
    int cost[100][100]; 

    matrix() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                m[i][j] = 0;
                cost[i][j] = 0;  
            }
        }
    }

    void edge(int x, int y, int c) {
        m[x][y] = 1;
        m[y][x] = 1;
        cost[x][y] = c;
        cost[y][x] = c;
    }

    int getCost(int x, int y) {
        return cost[x][y];
    }
};

class list {
public:
    string data;
    list* next;

    list(string x) {
        data = x;
        next = NULL;
    }

    list() {}

    void insert(list*& head, list* temp) {
        if (head == NULL) {
            head = temp;
        } else {
            list* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    void display(list* current) {
        if (current == NULL) {
            return;
        }
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    matrix am;
    int ch, City, edges, no, c1, c2, cost;
    string arr[20], v1, v2, d;
    list* hed[20], * temp;
    list l;
    
    do {
        cout << "\n1. Adjacency Matrix\t2. Output (AM)\t3. Adjacency List\t4. Output (AL)\t5. Flight Cost Estimation\t6. Exit\nEnter choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1: // Input Adjacency Matrix
                cout << "Enter number of Cities: ";
                cin >> City;
                for (int i = 0; i < City; i++) {
                    cout << "City-" << i + 1 << ": ";
                    cin >> arr[i];
                }
                cout << "Enter number of edges: ";
                cin >> edges;
                for (int i = 0; i < edges; i++) {
                    cout << "Edge-" << i + 1 << endl;
                    cout << "\tCity-1: ";
                    cin >> v1;
                    cout << "\tCity-2: ";
                    cin >> v2;
                    cout << "\tEnter Cost (Fuel or Time): ";
                    cin >> cost;
                    
                    for (int k = 0; k < City; k++) {
                        if (v1 == arr[k]) c1 = k;
                        if (v2 == arr[k]) c2 = k;
                    }
                    
                    am.edge(c1, c2, cost);
                }
                break;
                
            case 2: // Output Adjacency Matrix
                cout << "\nAdjacency Matrix (1 = Flight exists, 0 = No flight)\n";
                for (int i = 0; i < City; i++) {
                    cout << "\t" << arr[i];
                }
                cout << "\n";
                for (int i = 0; i < City; i++) {
                    cout << arr[i] << "\t";
                    for (int j = 0; j < City; j++) {
                        cout << am.m[i][j] << "\t";
                    }
                    cout << "\n";
                }
                break;

            case 3: // Input Adjacency List
                cout << "Enter number of Cities: ";
                cin >> City;
                cout << "Enter Cities:\n";
                for (int i = 0; i < City; i++) {
                    cout << "City-" << i + 1 << ": ";
                    cin >> arr[i];
                }
                for (int i = 0; i < City; i++) {
                    hed[i] = NULL;
                    cout << "Enter number of adjacent Cities for " << arr[i] << ": ";
                    cin >> no;
                    for (int j = 0; j < no; j++) {
                        cout << "City-" << j + 1 << ": ";
                        cin >> d;
                        temp = new list(d);
                        if (hed[i] == NULL) {
                            hed[i] = temp;
                        } else {
                            l.insert(hed[i], temp);
                        }
                    }
                }
                break;

            case 4: // Display Adjacency List
                cout << "\nAdjacency List Representation:\n";
                for (int i = 0; i < City; i++) {
                    cout << arr[i] << " --> ";
                    l.display(hed[i]);
                    cout << endl;
                }
                break;

            case 5: { // Flight Cost Estimation
                string start, end;
                int price;
                cout << "Enter Start City: ";
                cin >> start;
                cout << "Enter Destination City: ";
                cin >> end;
                cout << "Enter Cost per Unit Distance: ";
                cin >> price;

                int startIdx = -1, endIdx = -1;
                for (int i = 0; i < City; i++) {
                    if (arr[i] == start) startIdx = i;
                    if (arr[i] == end) endIdx = i;
                }

                if (startIdx == -1 || endIdx == -1) {
                    cout << "Invalid Cities Entered!\n";
                } else if (am.m[startIdx][endIdx] == 0) {
                    cout << "No direct flight available between " << start << " and " << end << ".\n";
                } else {
                    int totalCost = am.getCost(startIdx, endIdx) * price;
                    cout << "Estimated Flight Cost from " << start << " to " << end << " is: " << totalCost << "\n";
                }
                break;
            }

        }
    } while (ch != 6);

    return 0;
}
