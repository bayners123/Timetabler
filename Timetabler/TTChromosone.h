//
//  TTChromosone.h
//  Timetabler
//
//  Created by Charles Baynham on 26/06/2013.
//  Copyright (c) 2013 Charles Baynham. All rights reserved.
//

#ifndef Timetabler_TTChromosone_h
#define Timetabler_TTChromosone_h

#include "Student.h"
#include "Configuration.h"
#include <ext/hash_map>
using namespace __gnu_cxx;

#include "GLSource/Initialization.h"

#include "GLSource/MultiValueChromosome.h"
#include "GLSource/ChromosomeOperations.h"

#include "GLSource/Population.h"
#include "GLSource/SelectionOperations.h"
#include "GLSource/ReplacementOperations.h"

#include "GLSource/StopCriterias.h"
#include "GLSource/IncrementalAlgorithm.h"

class TTChromosomeParams : public GaChromosomeParams {
    
    // The probability of swapping two students in a mutation instead of randomly moving as normal
    double _probSwap;
    
public:
    
    // Initialise TTChromosomeParams with probSwap and the parent's variables
    TTChromosomeParams(float mutationProbability, int mutationSize, double mutationProbSwap, bool improvingOnlyMutations, float crossoverProbability, int numberOfCrossoverPoints) :
    _probSwap(mutationProbSwap),
    GaChromosomeParams(mutationProbability,
                       mutationSize,
                       improvingOnlyMutations,
                       crossoverProbability,
                       numberOfCrossoverPoints) {}
    
    inline double getProbSwap() const { return _probSwap; }
    
    
};

class Chromosone : public GaMultiValueChromosome<list<Student*> > {
    
    friend class TTMutation;
    friend class TTCrossover;
    friend class TTFitness;
    
    hash_map<Student*, int> _lookup;
    hash_map<Student*, int> _backupLookup;
    
    // map holding whether the essential criteria have been met for a student (updated when fitness is calculated)
    map<Student*, bool> _essentialMet;
    
public:
    
    Chromosone(GaChromosomeDomainBlock<list<Student*> >* configBlock);
    
	Chromosone(const Chromosone& c, bool setupOnly);
    
	virtual ~Chromosone() { }
    
    virtual GaChromosomePtr MakeCopy(bool setupOnly) const;
    
	virtual GaChromosomePtr MakeNewFromPrototype() const;
    
	virtual void PreapareForMutation(); // Spelling mistake in the framework! Might fix later
    
	virtual void AcceptMutation();
    
	virtual void RejectMutation(); 
    
	// Returns reference to table of classes
	inline const hash_map<Student*, int>& GetStudentLookup() const { return _lookup; }
    
	// Return reference to array of time-space slots
	inline const vector<list<Student*> >& GetSlots() const { return _values; }
    
};


class TTFitness : public GaFitnessOperation
{
public:
    
	virtual float GACALL operator ()(GaChromosome* chromosome) const;
    
	virtual GaParameters* GACALL MakeParameters() const { return NULL; }
    
	virtual bool GACALL CheckParameters(const GaParameters& parameters) const { return true; }
};


class TTMutation : public GaMutationOperation
{
public:
    
	virtual void GACALL operator ()(GaChromosome* parent) const;
    
	virtual GaParameters* GACALL MakeParameters() const { return NULL; }
    
	virtual bool GACALL CheckParameters(const GaParameters& parameters) const { return true; }

};


class TTCrossover : public GaCrossoverOperation
{
    
public:
    
	virtual GaChromosomePtr GACALL operator ()(const GaChromosome* parent1,
                                               const GaChromosome* parent2) const;
    
	virtual GaParameters* GACALL MakeParameters() const { return NULL; }
    
	virtual bool GACALL CheckParameters(const GaParameters& parameters) const { return true; }
    
    
};

#endif
