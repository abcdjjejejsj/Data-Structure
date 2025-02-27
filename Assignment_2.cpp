#include <iostream>
using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
    Employee* left;
    Employee* right;

    Employee(int i, string n, double s) : id(i), name(n), salary(s), left(nullptr), right(nullptr) {}
};

class EmployeeBST {
private:
    Employee* root;

    Employee* insert(Employee* node, int id, string name, double salary) {
        if (!node) return new Employee(id, name, salary);
        
        if (salary < node->salary)
            node->left = insert(node->left, id, name, salary);
        else
            node->right = insert(node->right, id, name, salary);
        
        return node;
    }

    Employee* search(Employee* node, double salary) {
        if (!node || node->salary == salary) return node;
        return (salary < node->salary) ? search(node->left, salary) : search(node->right, salary);
    }

    void inorder(Employee* node) {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name << ", Salary: " << node->salary << endl;
        inorder(node->right);
    }

    Employee* findMin(Employee* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Employee* findMax(Employee* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    Employee* deleteNode(Employee* node, double salary) {
        if (!node) return node;
        if (salary < node->salary) node->left = deleteNode(node->left, salary);
        else if (salary > node->salary) node->right = deleteNode(node->right, salary);
        else {
            if (!node->left) {
                Employee* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Employee* temp = node->left;
                delete node;
                return temp;
            }
            Employee* temp = findMin(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->salary = temp->salary;
            node->right = deleteNode(node->right, temp->salary);
        }
        return node;
    }

    void computeSalaryStats(Employee* node, double &sum, int &count) {
        if (!node) return;
        computeSalaryStats(node->left, sum, count);
        sum += node->salary;
        count++;
        computeSalaryStats(node->right, sum, count);
    }

    int countEmployees(Employee* node) {
        if (!node) return 0;
        return 1 + countEmployees(node->left) + countEmployees(node->right);
    }

public:
    EmployeeBST() : root(nullptr) {}

    void create(int id, string name, double salary) {
        root = insert(root, id, name, salary);
    }

    void search(double salary) {
        Employee* res = search(root, salary);
        if (res) cout << "Employee Found: ID: " << res->id << ", Name: " << res->name << ", Salary: " << res->salary << endl;
        else cout << "Employee not found.\n";
    }

    void update(double salary, string newName, int newId) {
        Employee* res = search(root, salary);
        if (res) {
            res->name = newName;
            res->id = newId;
            cout << "Employee details updated successfully.\n";
        } else {
            cout << "Employee not found.\n";
        }
    }

    void display() {
        inorder(root);
    }

    void findMinSalary() {
        Employee* minEmp = findMin(root);
        if (minEmp) cout << "Minimum Salary Employee: ID: " << minEmp->id << ", Name: " << minEmp->name << ", Salary: " << minEmp->salary << endl;
    }

    void findMaxSalary() {
        Employee* maxEmp = findMax(root);
        if (maxEmp) cout << "Maximum Salary Employee: ID: " << maxEmp->id << ", Name: " << maxEmp->name << ", Salary: " << maxEmp->salary << endl;
    }

    void computeAverageSalary() {
        double sum = 0;
        int count = 0;
        computeSalaryStats(root, sum, count);
        if (count == 0) cout << "No employees in system.\n";
        else cout << "Average Salary: " << (sum / count) << endl;
    }

    void totalEmployees() {
        cout << "Total Employees: " << countEmployees(root) << endl;
    }

    void deleteEmployee(double salary) {
        root = deleteNode(root, salary);
    }
};

int main() {
    EmployeeBST bst;
    int choice, id;
    string name;
    double salary;
    
    do {
        cout << "\nEmployee Management System:\n";
        cout << "1. Create\n2. Search\n3. Update\n4. Display\n5. Minimum Salary\n6. Maximum Salary\n7. Average Salary\n8. Total Employees\n9. Delete\n10. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Salary: ";
                cin >> id >> name >> salary;
                bst.create(id, name, salary);
                break;
            case 2:
                cout << "Enter Salary to Search: ";
                cin >> salary;
                bst.search(salary);
                break;
            case 3:
                cout << "Enter Salary to Update: ";
                cin >> salary;
                cout << "Enter New ID and New Name: ";
                cin >> id >> name;
                bst.update(salary, name, id);
                break;
            case 4:
                bst.display();
                break;
            case 5:
                bst.findMinSalary();
                break;
            case 6:
                bst.findMaxSalary();
                break;
            case 7:
                bst.computeAverageSalary();
                break;
            case 8:
                bst.totalEmployees();
                break;
            case 9:
                cout << "Enter Salary to Delete: ";
                cin >> salary;
                bst.deleteEmployee(salary);
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);
    
    return 0;
}
