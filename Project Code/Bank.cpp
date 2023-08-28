#include<iostream>
#include<fstream>
#include<iomanip>
#include"Bank.h"
// -------------------------------------------( USER CLASS )-----------------------------------

void User::withdraw()
{
    int amount=0; 

    cout<<endl;
    cout<<"Enter amount: ";
    cin>>amount;

    if (amount > 300)
    {
        amount -= getamount();
        setamount(amount);
        cout<<"Cash Withdrawing... Thank you!"<<endl;
    }
    else
    {
        cout<<"Insufficent Balance to withdraw"<<endl;
    }

}
void User::deposit()
{
    int amount;

    cout<<"Enter Deposit Amount: ";
    cin>>amount;
    
    if (amount == 0 || amount != 0)
    {
        amount = amount + getamount();
    }
    setamount(amount);
}
void User::setamount(int balance)
{
    amount[0] = balance;
}
int User::getamount()
{
    return amount[0];
}
User::User(string name,string no,string cnic,string pass,int amount)
{
    this->name.push_back(name);
    phone_no.push_back(no);
    this->cnic.push_back(cnic);
    password.push_back(pass);
    this->amount.push_back(amount);
}
void User::display()
{
    char choice;

    cout<<"\t\t*******( Please confirm your entering data is correct )*******"<<endl;
    cout<<endl;
    cout<<"Name: "<<getname()<<endl;
    cout<<"Phone_Number: "<<getphone()<<endl;
    cout<<"Cnic: "<<getcnic()<<endl;
    cout<<"Press ( Y ) for *OK*"<<endl;
    cin>>choice;
    if (choice == 'Y')
    {
        cout<<"THANK YOU :)"<<endl;
    }
}
string User::getname()
{
    return name[0];
}
string User::getcnic()
{
    return cnic[0];
}
string User::getphone()
{
    return phone_no[0];
}
string User::getpass()
{
    return password[0];
}
// -------------------------------------------------( EMPLOYEE CLASS )---------------------------------------------------------


string Employee::getE_name()
{
    return name[0];
}
string Employee::getE_pass()
{
    return password[0];
}
void Employee::Display_userdata(vector<User> & user)
{
    vector<User>::iterator inter;
    inter = user.begin();

    for (inter ; inter != user.end(); inter++)
    {
        cout<<"Name: "<<inter->getname()<<endl;
        cout<<"Phone: "<<inter->getphone()<<endl;
        cout<<"Cnic: "<<inter->getcnic()<<endl;
        cout<<"Balance: "<<inter->getamount()<<endl;
        cout<<"Password: "<<inter->getpass()<<endl;
        cout<<endl;
    }
}
void Employee::employee_Function(fstream &file)
{
    int option;
    while (1)
    {
        cout<<endl;
        cout<<"Hello! Which action you want to perform?"<<endl;
        cout<<"1) Add a User"<<endl;
        cout<<"2) Delete a User"<<endl;
        cout<<"3) Display User Data"<<endl;
        cout<<"4) View Transcation Details"<<endl;
        cout<<"5) Exit"<<endl;
        cin>>option;
        
        if (option == 1)
        {
            newUser_Account();
        }
        else if (option == 2)
        {
            delete_user();
        }
        else if(option == 3)
        {
            Display_userdata(user);   
        }
        else if(option == 4)
        {
            // transcation details
        }
        else if (option == 5)
        {
            break;
        }
    }
    
}
bool Employee::Login_Employee() 
{
    ifstream File("Employee.txt");
    vector<Employee> employees;
    bool found = false;
    string line;

    string name, password;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;

    while (getline(File, line)) 
    {
        size_t name_start_pos = line.find("Name: ");
        if (name_start_pos != string::npos) 
        {
            name_start_pos += 6;
            size_t name_end_pos = line.find(",", name_start_pos);
            string emp_name = line.substr(name_start_pos, name_end_pos - name_start_pos);

            if (emp_name == name && line.find("Password: " + password) != string::npos) {
                found = true;
                break;
            }
        }
    }

    if (found == true) 
    {
        cout << "Login success!" << endl;
    } 
    else 
    {
        cout<<"Incorrect name or password."<<endl;
    }
    return found;
}
void Employee::delete_user()
{
    int index;
    fstream Source,Destination;

    cout<<"Enter the index you want to delete: ";
    cin>>index;

    if (index >= 0 && index < user.size()) 
    {
        user.erase(user.begin() + index);
        cout<<endl;
        cout << "User at index "<<index<<" deleted successfully!"<<endl;
    }
    else 
    {
        cout<<"Invalid index. Cannot delete user."<<endl;
    }
}
void Employee::newUser_Account()
{
    fstream File;
    string name,email,password,new_password,cnic,phone;
    char choose='y';
    int count = 0,balance;
    
    while (choose != 'n')
    {
        cin.ignore();
        cout<<endl;
        cout<<"Please fill some information"<<endl;
        cout<<"Name: ";
        getline(cin,name);
        cout<<"Email: ";
        getline(cin,email);
        cout<<"Password: ";
        getline(cin,password);
        cout<<"Re-type password: ";
        getline(cin,new_password);
        cout<<"Enter your first balance: ";
        cin>>balance;

        do
        {
            cout<<"CNIC No: ";
            cin>>cnic;
            if (cnic.length() != 13)
            {   
                cout<<endl;
                cout<<"Incorrect CNIC fill the space of 13 digits"<<endl;
            }
        } while (cnic.length() != 13);
        do
        {
            cout<<"Phone Number: ";
            cin>>phone;
            if (phone.length() != 11)
            {
                cout<<endl;
                cout<<"Phone No Incorrect Fill 11 digit Number"<<endl;
            }
        } while (phone.length() != 11);

        File.open("User.txt",ios::app);

        if (password == new_password)
        {
            if (!File)
            {
                cout<<"Failed to open the file"<<endl;
            }
            else
            {
                File<<"Name: "<<name<<endl;
                File<<"Password: "<<setw(password.length())<<setfill('*')<<""<<endl;
                File<<"Email: "<<email<<endl;
                File<<"Phone: "<<phone<<endl;
                File<<"Cnic: " <<cnic<<endl;
                File<<"--------------------------------------------"<<endl;
            }
            cout<<"Your Account have been created successfully"<<endl;
        }
        else
        {
            cout<<"Name or password is incorrect"<<endl;
        }
        count++;
        
        User userdata(name,phone,cnic,password,balance);
        user.push_back(userdata);
        File.close();
    
        if (count >= 1)
        {
            cout<<endl;
            cout<<"Do you want to add more User?";
            cin>>choose;
        }

    }    
}
// overload the << operator

ostream& operator<<(ostream& os,User& u)
{
    os << "Name: " << u.getamount() << endl;
    os << "Phone No: " << u.getphone() << endl;
    os << "CNIC: " << u.getcnic() << endl;
    os << "Password: " << u.getpass() << endl;
    os << "Balance: " << u.getamount() << endl;
    return os;
}

// -------------------------------------------------------( MANAGER CLASS )----------------------------------------------


void Manager::display_employeedata(vector<Employee>& employee)
{
    vector<Employee>::iterator inter;
    inter = employee.begin();

    for (inter ; inter != employee.end(); inter++)
    {
        cout<<"Name: "<<inter->getE_name()<<endl;
        cout<<"Password: "<<inter->getE_pass()<<endl;
        cout<<endl;
    }
}
void Manager::remove_employee_data()
{
    int index;
    fstream File;
    cout << "Enter the index you want to delete: ";
    cin >> index;
    
    employee.erase(employee.begin() + index);

    cout<<"removed succesfully"<<endl;
}
void Manager::Add_Employee(fstream &File)
{
    int counter=1,id;
    char choose='y';
    string name, password;
    bool found;
        
        do
        {
            cin.ignore();
            cout<<"Enter name:";
            getline(cin,name);
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter Password: ";
            cin>>password;

            Employee new_employee(name, id, password);
            employee.push_back(new_employee);

            cout<<"Data entered successfully"<<endl;
            cout<<endl;
            cout<<"Do you want to enter more employee(y/n)? ";
            cin>>choose;

            File.open("Employee.txt",ios::app);
            if (!File)
            {
                cout<<"File not open"<<endl;
            }
            else
            {
            File<<counter<<") "<<"Employee Data "<<": "<<endl;
            File<<"Name: "<<name<<", ";
            File<<"Id: "<<id<<", ";
            File<<"Password: "<<setw(password.length())<<setfill('*')<<password<<endl;
            File<<endl;
            counter++;
            }
            File.close();

            } while(choose == 'y' || choose == 'Y');
}
void Manager::Manager_Functions(vector<Employee> & employee)
{
    fstream File;
    string line;
    int condition;
    char choose = 'y';

    while (condition != 5)
    {
        cout<<endl;
        cout<<"Choose the operation below"<<endl;
        cout<<"1) Add an Employee Data"<<endl;
        cout<<"2) Delete an Employee Data"<<endl;
        cout<<"3) Transcation Details"<<endl;
        cout<<"4) Display Employee Data"<<endl;
        cout<<"5) Exit"<<endl;
        cin>>condition;

        if (condition == 1)
        {
            Add_Employee(File);
        }
        else if (condition == 2)
        {
            remove_employee_data();
        }
        else if(condition == 3)
        {
            File.open("Transcation.txt",ios::in);
            if (!File)
            {
                cout<<"File not open!"<<endl;
            }
            else
            {
                while (getline(File,line))
                {
                    File<<line;
                }
            }
        }
        else if(condition == 4)
        {
            display_employeedata(employee);
        }
        else if(condition == 5)
        {
            break;
            cout<<"Exiting the program..."<<endl;
        }
    }
}
Manager::Manager()
{
    manager_name = "ubaid-ur-Rehman";
    manager_password = "1234";
}
string Manager::getManager_name()
{
    return manager_name;
}
string Manager::getManager_password()
{
    return manager_password;
}
// ------------------------------------------------------------------------------------------------------------------

bool Manager::Manager_login(fstream &File)
{
    string name,password,line;
    bool found = false;
    
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Password: ";
    cin>>password;


    File.open("Manager.txt", ios::in); 

    if (!File) 
    {
        cout << "Could not open file." << endl;
    }

    while (getline(File, line)) 
    {
        string nameFromFile = line.substr(line.find(": ") + 2);
        if (name == nameFromFile) 
        {
            getline(File, line);
            string passwordFromFile = line.substr(line.find(": ") + 2);
            if (password == passwordFromFile) 
            {
                cout << "Login successfully" << endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "User not found." << endl;
    }

    File.close();
    return found;
}