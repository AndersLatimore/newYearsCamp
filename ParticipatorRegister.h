//
//  ParticipatorRegister.h
//  newYearsCamp
//
//  Created by Anders Akesson on 11/16/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __newYearsCamp__ParticipatorRegister__
#define __newYearsCamp__ParticipatorRegister__

#include <iostream>
#include "Participator.h"

class ParticipatorRegister
{
    
private:
    Participator** participatorPtrPtr;
        // Participator* newYearsRegisterPtr;
    int nrOfParticipents;
    int arraySize;
    
public:
        // constructors
    ParticipatorRegister();
    ParticipatorRegister(const ParticipatorRegister&);
        // misc functions
    int getNrOfParticipents() const;
    void addParticipator(string name, string address, bool paid);
    void resize();
    void displayAllByName() const;
    void displayAllPaid() const;
    void displayAllNotPaid() const;
    int findParticipator(string name);
    void searchAndDisplay(string searchName);
    bool removeParticipator(string name);
    bool changeParticipatorInfo(string name);
    void save(string filename);
    void load(string filename);
    bool sort();
        // overloaded operators
    bool operator==(const ParticipatorRegister &reg) const;
    void operator= (const ParticipatorRegister &reg);
        // destructor
    ~ParticipatorRegister();
    
};

#endif /* defined(__newYearsCamp__ParticipatorRegister__) */

