#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, e; // Number of cities (vertices) and flight paths (edges)
    
    cout << "Enter number of cities (vertices): ";
    cin >> n;
    cout << "Enter number of flight paths (edges): ";
    cin >> e;

    // Adjacency matrix initialized to 0
    int adjMatrix[n][n]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Adjacency list representation using a 2D array
    int adjList[n][n]; // This will store destinations, -1 means empty
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjList[i][j] = -1; // Initialize with -1 (indicating no connection)
        }
    }

    cout << "Enter source city, destination city, and cost (time/fuel) for each flight:\n";
    for (int i = 0; i < e; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        // Filling the adjacency matrix with cost
        adjMatrix[src][dest] = cost;
        adjMatrix[dest][src] = cost; // Since it's an undirected graph

        // Filling adjacency list
        for (int j = 0; j < n; j++) {
            if (adjList[src][j] == -1) {
                adjList[src][j] = dest;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (adjList[dest][j] == -1) {
                adjList[dest][j] = src;
                break;
            }
        }
    }

    // Display the Adjacency Matrix
    cout << "\nAdjacency Matrix Representation:\n  ";
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << i << " ";
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display the Adjacency List
    cout << "\nAdjacency List Representation:\n";
    for (int i = 0; i < n; i++) {
        cout << "City " << i << " -> ";
        for (int j = 0; j < n; j++) {
            if (adjList[i][j] != -1) {
                cout << "City " << adjList[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
