#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

class Graph {
public:
    int v, e, wt = 0;
    int m[100][100];
    vector<int> start, final, edge;
    vector<string> cities; 

    Graph(int x, int y) {
        v = x;
        e = y;

      
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                m[i][j] = 0;
            }
        }

    
        for (int i = 0; i < v; i++) {
            start.push_back(1);
            final.push_back(-1);
        }
    }

   
    void addCity(string city) {
        cities.push_back(city);
    }

  
    void edges(string city1, string city2, int w) {
        int x = findIndex(city1);
        int y = findIndex(city2);
        m[x][y] = w;
        m[y][x] = w;
    }


    int findIndex(string city) {
        for (int i = 0; i < cities.size(); i++) {
            if (cities[i] == city) return i;
        }
        return -1; 
    }

   
    void display() {
        cout << "\nAdjacency Matrix (Distances Between Cities):\n";
        cout << "------------------------------------------------------------\n";
    
        
        cout << setw(12) << " ";
        for (int i = 0; i < cities.size(); i++) { 
            cout << setw(10) << cities[i];
        }
        cout << endl << "------------------------------------------------------------\n";
    
       
        for (int i = 0; i < v; i++) {
            cout << setw(10) << cities[i] << " |";
            for (int j = 0; j < v; j++) {
                if (m[i][j] == 0)
                    cout << setw(10) << "-"; 
                else
                    cout << setw(10) << m[i][j];
            }
            cout << endl;
        }
        cout << "------------------------------------------------------------\n";
    }
    
   
    void prims() {
        final[0] = 1;
        start[0] = -1;

        for (int i = 0; i < v - 1; i++) {
            int min = 9999;
            int parent = -1, child = -1;

            for (int j = 0; j < v; j++) {
                if (final[j] == 1) { 
                    for (int k = 0; k < v; k++) {
                        if (m[j][k] != 0 && final[k] != 1 && m[j][k] < min) {
                            min = m[j][k];
                            parent = j;
                            child = k;
                        }
                    }
                }
            }

            if (child != -1) { 
                final[child] = 1;
                start[child] = -1;
                edge.push_back(parent);
                edge.push_back(child);
                edge.push_back(min);
                wt += min;
            }
        }

      
        cout << "\nOptimized Travel Route for Interviews (Minimum Travel Distance):\n";
        cout << "Total Minimum Travel Distance: " << wt << " units\n";
        for (int i = 0; i < edge.size(); i += 3) {
            cout << "Travel from " << cities[edge[i]] << " to " << cities[edge[i+1]] << " (Distance: " << edge[i+2] << ")\n";
        }
    }
};

int main() {
    Graph g(5, 6);

   
    // g.addCity("Mumbai");
    // g.addCity("Pune");
    // g.addCity("Shirdi");
    // g.addCity("Nashik");
    // g.addCity("Rahata");


    // g.edges("Mumbai", "Pune", 2);
    // g.edges("Mumbai", "Shirdi", 4);
    // g.edges("Shirdi", "Nashik", 1);
    // g.edges("Pune", "Nashik", 2);
    // g.edges("Pune", "Rahata", 3);
    // g.edges("Nashik", "Rahata", 4);

    // g.display();
    // g.prims();
    int ch,no,d;
    string c,c1,c2;
    do{
        cout<<"1.Input\t2.Matrix\t3.MST\t4.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://input
                   cout<<"Enter no.of cities:";
                   cin>>no;
                   for(int i=0;i<no;i++)
                   {
                    cout<<"Enter city-"<<i+1<<":";
                    cin>>c;
                    g.addCity(c);
                   }
                   cout<<"Enter no.of edges :";
                   cin>>no;
                   for(int i=0;i<no;i++)
                   {
                    cout<<"City-1 :";
                    cin>>c1;
                    cout<<"City-2 :";
                    cin>>c2;
                    cout<<"Enter distance between them: ";
                    cin>>d;
                    g.edges(c1,c2,d);
                   }
                   break;
            case 2://matrix
                    g.display();
                    break;
            case 3://MST
                    g.prims();
                    break;
        }
    } while(ch!=4);

    return 0;
}
