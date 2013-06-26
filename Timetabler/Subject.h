//
//  Subject.h
//  Timetabler
//
//  Created by Charles Baynham on 26/06/2013.
//  Copyright (c) 2013 Charles Baynham. All rights reserved.
//

#ifndef Timetabler_Subject_h
#define Timetabler_Subject_h

#include <string>

using namespace std;

class Subject {
    int _ID;
    string _name;
    
public:
    Subject(int ID, const string& name); // Initialise ID and name
    
    inline int getID(){ return _ID; }
    inline const string& getName() { return _name; }
    
};

#endif