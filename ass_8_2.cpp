#include<iostream>
#include<vector>
using namespace std;

float w[100][100], c[100][100];
int r[100][100];

class Node {
public:
    string key;
    Node* left;
    Node* right;

    Node(string k) {
        key = k;
        left = right = NULL;
    }
};

void weightCalc(float p[], float q[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i <= j)
            {
                if(j == i)
                {
                    w[i][j] = q[i];
                }
                else
                {
                    w[i][j] = w[i][j-1] + p[j-1] + q[j];
                }
            }
        }
    }

    // Print Weight Table
    cout << "Weight table : \n";
    for(int i = 0; i <= n; i++)
    {
        cout << "     " << i << "  ";
    }
    cout << "\n\n";
    for(int i = 0; i <= n; i++)
    {
        cout << i << "  ";
        for(int j = 0; j <= n; j++)
        {
            if(w[i][j] == 0)
            {
                cout << "000" << "     ";
            }
            else
            {
                cout << w[i][j] << "     ";
            }
        }
        cout << "\n\n";
    }
}

void cost(int n)
{
    int tr;
    float min;
    for(int len = 1; len <= n; len++)  // len is the length of the range
    {
        for(int i = 0; i <= n - len; i++)  // i is the starting index
        {
            int j = i + len - 1;  // j is the ending index
            if(i == j)
            {
                c[i][j] = w[i][i];  // Cost for a single key is its weight
            }
            else
            {
                min = 9999;
                for(int k = i + 1; k <= j; k++)
                {
                    float temp = c[i][k-1] + c[k][j];
                    if(temp < min)
                    {
                        min = temp;
                        tr = k;
                    }
                }
                c[i][j] = min + w[i][j];
                r[i][j] = tr;
            }
        }
    }

    // Print Cost Table
    cout << "\n\nCost table :\n";
    for(int i = 0; i <= n; i++)
    {
        cout << "     " << i << "  ";
    }
    cout << "\n\n";
    for(int i = 0; i <= n; i++)
    {
        cout << i << "  ";
        for(int j = 0; j <= n; j++)
        {
            if(c[i][j] == 0)
            {
                cout << "000" << "     ";
            }
            else
            {
                cout << c[i][j] << "     ";
            }
        }
        cout << "\n\n";
    }

    // Print Root Table
    cout << "\n\nRoot table :\n";
    for(int i = 0; i <= n; i++)
    {
        cout << "      " << i;
    }
    cout << "\n\n";
    for(int i = 0; i <= n; i++)
    {
        cout << i << "     ";
        for(int j = 0; j <= n; j++)
        {
            if(r[i][j] == 0)
            {
                cout << "0" << "      ";
            }
            else
            {
                cout << r[i][j] << "      ";
            }
        }
        cout << "\n\n";
    }
}

Node* buildOBST(int r[100][100], string keys[], int i, int j) {
    if (i > j) return NULL;

    int rootIndex = r[i][j];
    if (rootIndex == 0) return NULL;  // Avoid invalid root index
    
    Node* root = new Node(keys[rootIndex - 1]); // Adjust for 0-indexed array
    root->left = buildOBST(r, keys, i, rootIndex - 1);
    root->right = buildOBST(r, keys, rootIndex + 1, j);
    
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main()
{
    int s = 4;
    float pi[] = {0.1, 0.2, 0.1, 0.2};
    float qi[] = {0.1, 0.05, 0.15, 0.05, 0.05};
    string keys[] = {"K1", "K2", "K3", "K4"};

    weightCalc(pi, qi, s);
    cost(s);

    Node* root = buildOBST(r, keys, 1, s);
    if (root != NULL) {
        cout << "Root: " << root->key << "\n";
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << endl;
    } else {
        cout << "No valid root found.\n";
    }

    return 0;
}
