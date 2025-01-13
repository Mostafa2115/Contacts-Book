#include <iostream>
#include<string>
#include"Address.h"
#include"Person.h"
#include"Array.h"
#include<fstream>
#include<iomanip>
#include"contactsBook.h"
int main()
{
    Array<Person<std::string>>* personArr = new Array<Person<std::string>>;
    contactsBook<Person<std::string>>* contacts = new contactsBook<Person<std::string>>(personArr);
    while (true) {
        std::cout << "\t\t\t\t";
        for (size_t i = 0; i < 55; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "\t\t\t\tContacts Book Menu:" << std::endl;
        std::cout << "\t\t\t\t------------------------" << std::endl;
        std::cout << "\t\t\t\t1. Add New contact" << std::endl
            << "\t\t\t\t2. Search by last Name (Enter last name correctly)" << std::endl
            << "\t\t\t\t3. Search by Classification (friend,work,family,other)" << std::endl
            << "\t\t\t\t4. Print All contacts" << std::endl
            << "\t\t\t\t5. Print favorite contacts" << std::endl
            << "\t\t\t\t6. Save to File" << std::endl
            << "\t\t\t\t7. Load from File" << std::endl
            << "\t\t\t\t8. Delete contact" << std::endl
            << "\t\t\t\t9. Update contact Information" << std::endl
            << "\t\t\t\t10. Reverse contacts Book" << std::endl
            << "\t\t\t\t11. Exit" << std::endl;
        std::cout << "\t\t\t\t";
        for (size_t i = 0; i < 55; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        int choise;
        std::cout << "Enter your choise: ";
        std::cin >> choise;
        std::cout << std::endl;
        if (choise == 1) {
                system("cls");
            std::cout << "\t\t\t\t--- Add a new contact ---" << std::endl;
            std::string fname, lname, classi, sName, state, town, stNum;
            size_t eNum = 0, phoneNum = 0, fav;
            std::cout << "First Name: ";
            std::cin >> fname;
            std::cout << "Last Name: ";
            std::cin >> lname;
            std::cout << "Class(friend,work,family,other): ";
            std::cin >> classi;
            std::cout << "Set as Fav: ";
            std::cin >> fav;
            std::cout << "How many numbers: ";
            std::cin >> phoneNum;
            std::string* arr = new std::string[phoneNum];
            for (size_t i = 0; i < phoneNum; i++) {
                std::cout << "phone #" << i + 1 << ": ";
                std::cin >> arr[i];
            }
            std::cout << "How many mails: ";
            std::cin >> eNum;
            std::string* arr1 = new std::string[eNum];
            for (size_t i = 0; i < eNum; i++) {
                std::cout << "Email #" << i + 1 << ": ";
                std::cin >> arr1[i];
            }
            std::cout << "Street Number: ";
            std::cin >> stNum;
            std::cout << "Street Name: ";
            std::cin >> sName;
            std::cout << "City: ";
            std::cin >> town;
            std::cout << "State: ";
            std::cin >> state;
            Address<std::string> adder(stNum, sName, town, state);
            Person<std::string>per(fname, lname, fav, phoneNum, eNum, classi, adder, arr, arr1);
            contacts->AddContact(per);
            std::cout << "The new contact added successfully" << std::endl;
            delete[] arr;
            delete[] arr1;
        }
        else if (choise == 2) {
            system("cls");
            std::string lastN;
            std::cout << "Enter last Name in correct form: ";
            std::cin >> lastN;
            contacts->search_Last(lastN);
        }
        else if (choise == 3) {
            std::string classsi;
            std::cout << "Enter Classification: ";
            std::cin >> classsi;
            contacts->search_Classi(classsi);
        }
        else if (choise == 4) {
            contacts->printAllContacts();
        }
        else if (choise == 5) {
            contacts->printAllFav();
        }
        else if (choise == 6) {
            std::ofstream datafile("Array.txt");
            if (datafile.is_open())
            {
                datafile << std::setw(10) << std::left << "Id" << std::setw(15) << std::left << "FName"
                    << std::setw(15) << std::left << "LName" << std::setw(15) << std::left << "Classi"
                    << std::setw(10) << std::left << "Fav" << std::setw(40) << std::left << "Address"
                    << std::setw(40) << std::left << "Phonenum" << std::endl;
                for (size_t i = 0; i < 146; i++) {
                    datafile << "-";
                }
                datafile << std::endl;
                contacts->printInFile(datafile);
                datafile.close();
                std::cout << "Saved\n";
            }
        }
        else if (choise == 7) {
            try {
                contacts->printFromFile("Array.txt");
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
        else if (choise == 8) {
            size_t index;
            std::cout << "Enter the index: ";
            std::cin >> index;
            contacts->DeleteContact(index);
        }
        else if (choise == 9) {
            size_t index;
            std::cout << "Enter The index: ";
            std::cin >> index;
            std::string fname, lname, classi, sName, state, town, stNum;
            size_t eNum, phoneNum, fav;
            std::cout << "First Name: ";
            std::cin >> fname;
            std::cout << "Last Name: ";
            std::cin >> lname;
            std::cout << "Class(friend,work,family,other): ";
            std::cin >> classi;
            std::cout << "Set as Fav: ";
            std::cin >> fav;
            std::cout << "How many numbers: ";
            std::cin >> phoneNum;
            std::string* arr = new std::string[phoneNum];
            for (size_t i = 0; i < phoneNum; i++) {
                std::cout << "phone #" << i + 1 << ": ";
                std::cin >> arr[i];
            }
            std::cout << "How many mails: ";
            std::cin >> eNum;
            std::string* arr1 = new std::string[eNum];
            for (size_t i = 0; i < eNum; i++) {
                std::cout << "Email #" << i + 1 << ": ";
                std::cin >> arr1[i];
            }
            std::cout << "Street Number: ";
            std::cin >> stNum;
            std::cout << "Street Name: ";
            std::cin >> sName;
            std::cout << "City: ";
            std::cin >> town;
            std::cout << "State: ";
            std::cin >> state;
            Address<std::string> adder(stNum, sName, town, state);
            Person<std::string>per(fname, lname, fav, phoneNum, eNum, classi, adder, arr, arr1);
            contacts->updateContact(per, index);
            contacts->printAllContacts();
        }
        else if (choise == 10) {
            contacts->ReverseContacts();
            contacts->printAllContacts();
        }
        else if (choise == 11) {
            std::cout << "Thanks for your visit";
            return 0;
        }
        else {
            std::cout << "Invaild Number Please enter Num from 1 to 11" << std::endl;
        }

    }
    delete personArr;
    delete contacts;
    return 0;
}
