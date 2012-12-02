//
//  main.cpp
//  newYearsCamp
//
//  This program is a register for people going to a new years camp.
//  The ParticipatorRegister class uses a double pointer to access the Participator objects.
//  The Participator objects are in turn accessible through an array of pointers, created by
//  the constructor in ParticipatorRegister.
//
//  Created by Anders Akesson on 11/16/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include <iostream>
#include <string>
#include "ParticipatorRegister.h"

using namespace std;

int getChoice();
void displayMenu();

int main()
{
    ParticipatorRegister newRegister;

    int choice;
    do {
        displayMenu();
        choice = getChoice();
        switch (choice)
        {
            case 1:
            {
                string nName;
                cout << "Enter the name of the participator: " << endl;
                getline(cin, nName);
                string aAddress;
                cout << "Enter the address of the participator: " << endl;
                getline(cin, aAddress);
                int pPaid;
                cout << "Has the participator paid the fee? 1 for yes, 0 for no: " << endl;
                cin >> pPaid;
                cin.ignore();
                while(pPaid < 0 || pPaid > 1 || !(cin.good()))
                {
                    cin.clear();               // clear error condition
                    cin.ignore(100,'\n');     // remove characters))
                
                    cout << "Not a valid input, enter 1 or 0: " << endl;
                    cin >> pPaid;
                    cin.ignore();
                }
                newRegister.addParticipator(nName, aAddress, pPaid);
                break;
            }
            case 2:
                newRegister.displayAllByName();
                break;
            case 3:
                newRegister.displayAllPaid();
                break;
            case 4:
                newRegister.displayAllNotPaid();
                break;
            case 5:
            {
                string sName;
                cout << "Enter the name of the person you want to display: " << endl;
                getline(cin, sName);
                newRegister.searchAndDisplay(sName);
                break;
            }
            case 6:
            {
                string rName;
                cout << "Enter the name of the participator you want to remove: " << endl;
                getline(cin, rName);
                newRegister.removeParticipator(rName);
                break;
            }
            case 7:
            {
                string cName;
                cout << "Enter the name of the participator you want to change: " << endl;
                getline(cin, cName);
                newRegister.changeParticipatorInfo(cName);
                break;
            }
            case 8:
            {
                string sFilename;
                cout << "Enter the filename: " << endl;
                getline(cin, sFilename);
                newRegister.save(sFilename);
                break;
            }
            case 9:
            {
                string lFilename;
                cout << "Enter the filename: " << endl;
                getline(cin, lFilename);
                newRegister.load(lFilename);
                break;
            }
            case 10:
                newRegister.sort();
                break;
            case 11:
                break;
        }
    } while (choice != 11);
    
    return 0;
}

int getChoice()
{
    int choice;
    cout << "Enter your number of choice: " << endl;
    cin >> choice;
    cin.ignore();
    
    while(choice < 1 || choice > 11 || !(cin.good()))
    {
        cin.clear();               // clear error condition
        cin.ignore(100,'\n');     // remove characters)

        cout << "Not a valid input, choice can only by 1 - 11. " << endl;
        cout << "Please re-enter: ";
        cin >> choice;
        cin.ignore();
    }
    
    return choice;
}
void displayMenu() 
{
    cout << "*******Participator Register*******" << endl;
    cout << "***********************************" << endl;
    cout << "1. Add participator. " << endl;
    cout << "2. Display all by name. " << endl;
    cout << "3. Display all that have paid. " << endl;
    cout << "4. Display all that have not paid. " << endl;
    cout << "5. Search and display one participator. " << endl;
    cout << "6. Remove a participator. " << endl;
    cout << "7. Change a participator. " << endl;
    cout << "8. Save register to file. " << endl;
    cout << "9. Load participants from file. " << endl;
    cout << "10. Sort participants by name. " << endl;
    cout << "11. Quit the program. " << endl;
    cout << "***********************************" << endl;
}

