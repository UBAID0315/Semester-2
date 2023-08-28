#include<iostream>
#include<vector>
using namespace std;

class User
{
    protected:
        vector<string> name;
        vector<string> phone_no;
        vector<string> cnic;
        vector<string> password;
        vector<string> email;
        vector<int> amount;
    public:
        User(string,string,string,string,int);
        void withdraw();
        void deposit();
        void display();
        void setamount(int);
        string getname();
        string getphone();
        string getcnic();
        string getpass();
        int getamount();
};
class Employee
{
    public:
        vector<User> user;
        vector<string> name;
        vector<int> id;
        vector<string> password;

        Employee(string name,int id,string pass)
        {
            this->name.push_back(name);
            this->id.push_back(id);
            this->password.push_back(pass);
        }

        void newUser_Account();
        string getE_name();
        string getE_pass();
        void employee_Function(fstream&);
        bool Login_Employee();
        void delete_user();
        void Display_userdata(vector<User> &);
        friend ostream& operator<<(ostream& os, User& u);
};
class Manager
{
    protected:
        string manager_name;
        string manager_password;
    public:
        vector<Employee> employee;
        Manager();
        string getManager_password();
        string getManager_name();
        bool Manager_login(fstream &);
        void Manager_Functions(vector<Employee> &);
        void Add_Employee(fstream &);
        void display_employeedata(vector<Employee> &);
        void remove_employee_data();
};