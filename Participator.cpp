//
//  Participator.cpp
//  newYearsCamp
//
//  Created by Anders Akesson on 11/16/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "Participator.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

    // constructors
Participator::Participator()
{
    this -> name = "None";
    this -> address = "Not registered";
    this -> paid = false;
}
Participator::Participator(string newName, string newAddress)
{
    this -> name = newName;
    this -> address = newAddress;
    this -> paid = false;
}
Participator::Participator(string newName, string newAddress, bool newPaid)
{
    this -> name = newName;
    this -> address = newAddress;
    this -> paid = newPaid;
}
    // copy constructor
Participator::Participator(const Participator& partref)
{
    this -> name = partref.name;
    this -> address = partref.address;
    this -> paid = partref.paid;
}

    // set functions
void Participator::setName(string newName)
{
   this -> name = newName;
}
void Participator::setAddress(string newAddress)
{
    this -> address = newAddress;
}
void Participator::setPaid(bool newPaid)
{
    this -> paid = newPaid;
}
    // get functions
string Participator::getName() const
{
    return this -> name;
}
string Participator::getAddress() const
{
    return this -> address;
}
bool Participator::getPaid() const
{
    return this -> paid;
}
    // save or read to/from file, get string

void Participator::save(ofstream& out)
{
    string filename;
    cout << "Enter filename: " << endl;
    out.open(filename);
    
    out << name << endl;
    out << address << endl;
    out << paid << endl;
    
    out.close();
}
void Participator::read(ifstream& in)
{
    string filename;
    cout << "Enter filename: " << endl;
    in.open(filename);
    
    string name;
    getline(in, name);
    string address;
    getline(in, address);
    
    Participator(name, address);
    
    in.close();
}
string Participator::toString()
{
    stringstream strStream;
    strStream << name << "\n" << address << "\n";
    if(paid == true)
    {
        strStream << "Fee paid" << endl;
    }
    else if(paid == false)
    {
        strStream << "Fee not paid" << endl;
    }
    return strStream.str();
}
    //overloaded operators

bool Participator::operator==(const Participator &participator) const
{
    return participator.name == this -> name && participator.address == this -> address && participator.paid == this -> paid;
}

bool Participator::operator< (const Participator &participator) const
{
    return participator.getName() < name; 
}

    // destructor
Participator::~Participator()
{
    
}

