//
//  Tutor.h
//  Timetabler
//
//  Created by Charles Baynham on 26/06/2013.
//  Copyright (c) 2013 Charles Baynham. All rights reserved.
//

#ifndef Timetabler_Tutor_h
#define Timetabler_Tutor_h

#include <string>
#include <list>

#include "Subject.h"

using namespace std;

class Tutor {
    int _ID;
    string _name;
    list<Subject*> _subjects;
    list<int> _notTimes; //List of times to avoid, from 0 to NUM_SLOTS-1
    list<int> _notSlots; //List of slots that the above times preclude
    
public:
    Tutor(int ID, const string& name, list<Subject*> subjects, list<int> notTimes);
    
    inline int getID(){ return _ID; }
    inline const string& getName() { return _name; }
};

#endif