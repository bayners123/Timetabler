//
//  Student.h
//  Timetabler
//
//  Created by Charles Baynham on 26/06/2013.
//  Copyright (c) 2013 Charles Baynham. All rights reserved.
//

#ifndef Timetabler_Student_h
#define Timetabler_Student_h

#include <string>
#include <list>

using namespace std;

#include "Subject.h"
#include "Tutor.h"

class Student {
    
private:
    int _ID;
    string _name;
    Subject* _subject; // Interview subject
    int _noInterviews;  // Number of interviews (2 or 4)
    list<Tutor*> _prevTutors; // Previous tutors to be avoided
//    list<Tutor*> _tutors;
    static int _nextID; // Next ID to be autoassigned
    int _baseID;
//    Unique ID of this student. N.b. the baseID has no relationship with the ID:
//    a student may have the same baseID as another's ID, but with no relationship between them
//    I use a base ID since the timetabler works by duplicating students _noInterviews times.
//    The baseID forms a link between these duplicates. 
    
    list<int> _notTimes; //List of times to avoid, from 0 to SLOTS_IN_DAY-1
    
public:

    // constructor. If baseID is set to 0 then it is autogenerated
    Student(int baseID, const string& name, Subject* subj, int noInterviews, list<Tutor*> prevTutors, list<int> notTimes); // Initiate wth auto id
    Student(Student* copy); // Copy constructor
    
    inline int getID(){ return _ID; }
    inline const string& getName() { return _name; }
    inline list<int> getNotTimes() { return _notTimes; }

    inline void addNotTime(int time) { _notTimes.push_back(time); }
    inline void removeNotTime(int time) { _notTimes.remove(time); }
    inline void clearNotTimes() { _notTimes.clear(); }
    
    inline void addPrevTutor(Tutor* t) { _prevTutors.push_back(t); }
    inline void removePrevTutor(Tutor* t) { _prevTutors.remove(t); }
    inline void clearPrevTutors() { _prevTutors.clear(); }

    
//    inline void setID(int ID){ _ID = ID; }
    inline void setName(string name) { _name = name; }
    inline void setNumInterviews(int num) { _noInterviews = num; }
    inline void setSubject(Subject* subject) { _subject = subject; }
    
    inline Subject* getSubject() { return _subject; }
    inline list<Tutor*> getPrevTutors() { return _prevTutors; }
    inline int getNoInterviews() { return _noInterviews; }
    inline int getBaseID() { return _baseID; }
};

#endif
