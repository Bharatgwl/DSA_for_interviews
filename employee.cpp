#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int employeeID;
    long long  salary;

public:
    void inputDetails()
    {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cout << "Enter employee salary: ";
        cin >> salary; 
    }

  
    void displayDetails() 
    {
        cout << "\nEmployee Details:"<<endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }

    long long  AnnualSalary() 
    {
        return salary * 12;
    }
};

int main()
{
    Employee *emp=new Employee;
    emp->inputDetails();
    emp->displayDetails();

    cout << "Annual Salary: " << emp->AnnualSalary() << endl;

    return 0;
}