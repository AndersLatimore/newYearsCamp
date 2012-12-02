//
//  Participator.h
//  newYearsCamp
//
//  Created by Anders Akesson on 11/16/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __newYearsCamp__Participator__
#define __newYearsCamp__Participator__

#include <iostream>
#include <string>

using namespace std;

class Participator
{
    
private:
    string name;
    string address;
    bool paid;
    
public:
        // constructors
    Participator();
    Participator(string n, string a);
    Participator(string n, string a, bool p);
        // copy constructor
    Participator(const Participator& partref);
    
        // set functions
    void setName(string);
    void setAddress(string);
    void setPaid(bool);
        // get functions
    string getName() const;
    string getAddress() const;
    bool getPaid() const;
        // save or read to/from file, get string
    void save(ofstream& out);
    void read(ifstream& in);
    string toString();
        //overloaded operators
    bool operator==(const Participator &participator) const;
    bool operator< (const Participator &participator) const;
    
        // destructor
    ~Participator();
    
};

#endif /* defined(__newYearsCamp__Participator__) */
