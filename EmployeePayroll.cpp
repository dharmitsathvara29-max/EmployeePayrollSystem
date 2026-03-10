#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    int empID;
    string name;
    double basicSalary;
    double hra, da, pf, bonus;
    double netSalary;
public:
   void inputDetails()
    {
        cout << "Enter Employee ID:\n ";
        cin >> empID;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        calculateSalary();
    }

    void calculateSalary()
    {
        hra = 0.20 * basicSalary;
        da = 0.10 * basicSalary;
        bonus = 0.05 * basicSalary;
        pf = 0.12 * basicSalary;
        netSalary = basicSalary + hra + da + bonus - pf;
    }
     int getID()
    {
        return empID;
    }
     void generatePayslip()
    {
        cout << "\n========== Employee Payslip ==========\n";
        cout << "Employee ID : " << empID << endl;
        cout << "Name        : " << name << endl;
        cout << "--------------------------------------\n";
        cout << "Basic Salary : " << basicSalary << endl;
        cout << "HRA (20%)    : " << hra << endl;
        cout << "DA (10%)     : " << da << endl;
        cout << "Bonus (5%)   : " << bonus << endl;
        cout << "PF (12%)     : -" << pf << endl;
        cout << "--------------------------------------\n";
        cout << "Net Salary   : " << netSalary << endl;
        cout << "======================================\n";
        cout << "Payslip Generated Successfully!\n";
    }
};
int main()
{
    Employee emp[50];
    int count = 0;
    int choice;
    int searchID;
    bool found;
    do
    {
        cout << "\n===== Employee Payroll System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Generate Payslip\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
       switch(choice)
        {
            case 1:
                if(count < 50)
                {
                    emp[count].inputDetails();
                    count++;
                    cout << "\nEmployee Added Successfully\n";
                }
                else
                {
                    cout << "\nEmployee limit reached\n";
                }
                break;
            case 2:
                cout << "\nEnter Employee ID to generate payslip: ";
                cin >> searchID;
               found = false;
                for(int i = 0; i < count; i++)
                {
                    if(emp[i].getID() == searchID)
                    {
                        emp[i].generatePayslip();
                        found = true;
                        break;
                    }
                }
                 if(!found)
                {
                    cout << "Employee ID not found!\n";
                }
                break;

            case 3:
                cout << "\nExiting Program...\n";
                break;
             default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while(choice != 3);

    return 0;
}