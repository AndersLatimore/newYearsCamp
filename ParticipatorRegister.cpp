//
//  ParticipatorRegister.cpp
//  newYearsCamp
//
//  Created by Anders Akesson on 11/16/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "ParticipatorRegister.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

    // constructor
ParticipatorRegister::ParticipatorRegister()
{
    nrOfParticipents = 0;
    arraySize = 1;
    participatorPtrPtr = new Participator*[arraySize];
    
    for(int i = 0; i < arraySize; i++)
    {
        participatorPtrPtr[i] = new Participator();
    }
     
}
    // copy constructor
ParticipatorRegister::ParticipatorRegister(const ParticipatorRegister &regRef)
{
    nrOfParticipents = regRef.nrOfParticipents;
    Participator** participatorPtrPtr;
    participatorPtrPtr = new Participator*[nrOfParticipents];
    for(int i = 0; i < nrOfParticipents; i++)
    {
        *participatorPtrPtr[i] = *regRef.participatorPtrPtr[i];
    }
}

    // misc functions
int ParticipatorRegister::getNrOfParticipents() const
{
    return this -> nrOfParticipents;
}
void ParticipatorRegister::addParticipator(string nName, string aAddress, bool pPaid)
{
    
    if(nrOfParticipents >= arraySize)
    {
        resize();
    }

    participatorPtrPtr[nrOfParticipents] = new Participator(nName, aAddress, pPaid);
     
    nrOfParticipents++;
}
void ParticipatorRegister::resize()
{
    Participator** temp;
    arraySize = arraySize * 2;
    temp = new Participator*[arraySize];
    
    for(int i = 0; i < nrOfParticipents; i++)
    {
        temp[i] = participatorPtrPtr[i];
    }
    delete [] participatorPtrPtr;
    
    participatorPtrPtr = temp;
    
}
void ParticipatorRegister::displayAllByName() const
{
    for(int i = 0; i < nrOfParticipents; i++)
    {
        cout << participatorPtrPtr[i]->getName() << endl;
    }
}
void ParticipatorRegister::displayAllPaid() const
{
    cout << "All participants that have paid: " << endl;
    for(int i = 0; i < nrOfParticipents; i++)
    {
        if(participatorPtrPtr[i]->getPaid())
        {
            cout << participatorPtrPtr[i]->toString();
        }
    }
}
void ParticipatorRegister::displayAllNotPaid() const
{
    cout << "All participants that have not paid: " << endl;
    for(int i = 0; i < nrOfParticipents; i++)
    {
        if(participatorPtrPtr[i]->getPaid() == false)
        {
            cout << participatorPtrPtr[i]->toString();
        }
    }
}
int ParticipatorRegister::findParticipator(string nName)
{
    int find = -1;
    for(int i = 0; i < nrOfParticipents; i++)
    {
        if(nName == participatorPtrPtr[i]->getName())
        {
            find = i;
        }
    }
    return find;
}

void ParticipatorRegister::searchAndDisplay(string searchName) 
{
    int pos = 0;
    pos = findParticipator(searchName);
    
        if(pos != -1)
        {
            cout << participatorPtrPtr[pos]->toString();
        }
        else
        {
            cout << "Person not found. " << endl;
        }
}


bool ParticipatorRegister::removeParticipator(string name)
{
    bool success = false;
    int pos;
    pos = findParticipator(name);
    
    if(pos != -1)
    {
        cout << "Removing " << participatorPtrPtr[pos]->getName() << "..." << endl;
        participatorPtrPtr[pos] = participatorPtrPtr[--nrOfParticipents];
        cout << "Done. " << endl;
        success = true;
    }
    else
        cout << "No participator with that name found. " << endl;
    
    return success;
}
bool ParticipatorRegister::changeParticipatorInfo(string name)
{
    bool success = false;
    int pos;
    pos = findParticipator(name);
    
    if(pos != -1)
    {
        string nName;
        cout << "Enter the new name of the participator: " << endl;
        getline(cin, nName);
        (*participatorPtrPtr[pos]).setName(nName);
        
        string aAddress;
        cout << "Enter the new address of the participator: " << endl;
        getline(cin, aAddress);
        (*participatorPtrPtr[pos]).setAddress(aAddress);
        
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
        (*participatorPtrPtr[pos]).setPaid(pPaid);
        
        success = true;
    }
    else
        cout << "No participator with that name found. " << endl;
    
    return success;
}
void ParticipatorRegister::save(string filename)
{
    ofstream out;
    out.open(filename);
    
    if(out.is_open())
    { 
        cout << "Saving to file " << filename << "..." << endl;
    
        for(int i = 0; i < nrOfParticipents; i++)
        {
            out << participatorPtrPtr[i]->toString();
        }
        out.close();
        
        cout << "Done. " << endl;

    }
    else
        cout << "Could not open " << filename << ", returning to main menu. " << endl;
    
}
void ParticipatorRegister::load(string filename)
{
    ifstream in;
    in.open(filename);
    
    if(in.is_open())
    {
        cout << "Loading from file " << filename  << "..." << endl;
    
        for(int i = 0; i < nrOfParticipents; i++)
        {
            string name;
            getline(in, name);
        
            string address;
            getline(in, address);
        
            bool paid;
            in >> paid;
        
            participatorPtrPtr[nrOfParticipents] = new Participator(name, address, paid);
        }
            in.close();
    
        cout << "Done. " << endl;
    }
    else
        cout << "Could not open " << filename << ", returning to main menu. " << endl;
}

bool ParticipatorRegister::sort()
{
    bool status = false;
    Participator temp;
    
    cout << "The names unsorted: " << endl;
    for (int i = 0; i < nrOfParticipents; i++)
    {
        cout << participatorPtrPtr[i]->getName() << endl;
    }
    
    cout << "Sorting..." << endl;
    
    char *a;
    char *b;
        for (int mi,i = 0; i < nrOfParticipents - 1; i++)
        {
            temp = *participatorPtrPtr[i];
            a= new char[participatorPtrPtr[i]->getName().size()];
            memcpy(a,participatorPtrPtr[i]->getName().c_str(),participatorPtrPtr[i]->getName().size());
            mi = i;
            for (int j=i+1; j < nrOfParticipents; j++)
            {
                b= new char[participatorPtrPtr[j]->getName().size()];
                memcpy(b,participatorPtrPtr[j]->getName().c_str(),participatorPtrPtr[j]->getName().size());
            
                if(strcmp(a ,b) > 0)
                {
                    temp = (*participatorPtrPtr[j]);
                    status = true;
                    mi = j;
                }
            }
            *participatorPtrPtr[mi] = *participatorPtrPtr[i];
            *participatorPtrPtr[i] = temp;
 
        }
    
    delete a;
    a = NULL;
    delete b;
    b = NULL;
    
    cout << "The names sorted: " << endl;
    for (int i = 0; i < nrOfParticipents; i++)
    {
        cout << participatorPtrPtr[i]->getName() << endl;
    }
    
    return status;
}

    // overloaded operators
bool ParticipatorRegister::operator==(const ParticipatorRegister &reg) const
{
    return (reg.participatorPtrPtr == this -> participatorPtrPtr && reg.participatorPtrPtr == this -> participatorPtrPtr && reg.participatorPtrPtr == this -> participatorPtrPtr);
}
 
void ParticipatorRegister::operator= (const ParticipatorRegister &reg) 
{
    if(nrOfParticipents > 0) delete [] participatorPtrPtr;
    arraySize = reg.arraySize;
    participatorPtrPtr = new Participator*[arraySize];
    for(int i = 0; i < nrOfParticipents; i++)
        participatorPtrPtr[i] = reg.participatorPtrPtr[i];
}

    // destructor
ParticipatorRegister::~ParticipatorRegister()
{
    for(int i = 0; i < nrOfParticipents; i++)
    {
        delete participatorPtrPtr[i];
        participatorPtrPtr[i] = NULL;
    }
    delete participatorPtrPtr;
    participatorPtrPtr = NULL;
}