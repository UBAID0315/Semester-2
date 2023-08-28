#include<iostream>
#include<fstream>
#include"Bank.h"

using namespace std;

// ---------------------------------------------------( MAIN FUCNTION )--------------------------------------
int main()
{
    Manager manager;
    int choose,option;
    fstream File;
    string name,password,line,email;
    bool found;

    while (1)
    {
        int i=0;
        cout<<"WELCOME TO MY BANKING MANAGEMENT SYSTEM"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1) Bank-Manager"<<endl;
        cout<<"2) Bank-Employee"<<endl;
        cout<<"3) Bank-User"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Choose the Option from the list which best describe you"<<endl;
        cin>>choose;

        if (choose == 1)
        {
            bool found = manager.Manager_login(File);
            if (found == true)
            {
                manager.Manager_Functions(manager.employee);
            }
            else if(found == false)
            {
                cout<<"Please Enter Correct Name or Password"<<endl;
                manager.Manager_login(File);
            }
        }
        else if (choose == 2)
        {
            found = manager.employee[i].Login_Employee();

            if (found != false)
            {
                manager.employee[i].employee_Function(File);
            }
        }
        else if(choose == 3)
        {
            cout<<"0---------------( WELCOME TO USER LOGIN SYSTEM )--------------0"<<endl;
            cout<<"Enter Username: ";
            cin>>name;
            cout<<"Enter Password: ";
            cin>>password;

            File.open("User.txt",ios::app);
            string nameFromFile = line.substr(line.find(": ") + 2);
            if (name == nameFromFile) 
            {
                getline(File, line);
                string passwordFromFile = line.substr(line.find(": ") + 2);
                if (password.length() == passwordFromFile.length()) 
                {
                    cout <<"Hello! "<<name<< "welcome back :)"<< endl;
                    found = true;
                }
                else
                {
                    cout<<"Incorrect password"<<endl;
                }
            }
            else
            {
                cout<<"Incorrect Name"<<endl;
            }
            cout<<endl;
            cout<<"Account Management System"<<endl;
            cout<<"1) Change Name"<<endl;
            cout<<"2) Change Password"<<endl;
            cout<<"3) Change Email"<<endl;
            cout<<"4) Deposit Cash"<<endl;
            cout<<"5) Withdraw Cash"<<endl;
            cout<<"6) Back"<<endl;
            cin>>option;
            if (option == 1)
            {
                cout<<"Enter Name: ";
                getline(cin,name);
                cout<<"Name updated succesfully"<<endl;
            }
            else if(option == 2)
            {
                cout<<"Enter New-Password: ";
                cin>>password;
                cout<<"Password updated succesfully"<<endl;
            }
            else if (option == 3)
            {
                cout<<"Enter New-Email: ";
                cin>>email;
                cout<<"Email updated succesfully"<<endl;
            }  
            else if(option == 4)
            {
                manager.employee[i].user[i].deposit();
            }
            else if (option == 5)
            {
                manager.employee[i].user[i].withdraw();
            }
            else if (option == 6)
            {
                cout<<"Signing out the Account..."<<endl;
                break;
            }
        }
        else if(choose == 4)
        {
            cout<<"Exiting the code..."<<endl;
            break;
        }
        i++;
    }   
}