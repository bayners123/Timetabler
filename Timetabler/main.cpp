

#include <iostream>

#include "GLsource/Initialization.h"
#include "GLsource/ChromosomeOperations.h"
#include "GLsource/MultiValueChromosome.h"
#include "GLsource/Population.h"
#include "GLsource/StopCriterias.h"
#include "GLsource/SimpleAlgorithm.h"

using namespace std;

using namespace Algorithm;
using namespace Algorithm::StopCriterias;
using namespace Algorithm::SimpleAlgorithms;

#include "TTChromosone.h"

int main()
{
	GaInitialize();
    
    Configuration config = Configuration::getInstance();
    
    if (!config.parsed()) {
        printf("Config file is unparsed\nParsing now...\n");
        config.parseFile("/Users/Charles/config.txt");
    }

    printf("We have %i tutors, %i students and %i subjects.\n", config.numTutors(), config.numStudents(), config.numSubjects());
    
    Tutor * first = config.getTutor(1);
    cout << "The first tutor: " << first->getName();
    printf("'s ID is %i\n", first->getID());
    
//	GaChromosomeParams chromosomeParams( 0.1F, 10, true, 0.8F, 2 );
//    
//	GaMultiValueSet<char> valueSet( false );
//	valueSet.Add( "GAL: ", "     ", 5 );
//    
//	pFitness fitnessOperation;
//	GaChromosomeDomainBlock<char> configBlock( &valueSet,
//                                              GaCrossoverCatalogue::Instance().GetEntryData( "GaMultiValueCrossover" ),
//                                              GaMutationCatalogue::Instance().GetEntryData( "GaFlipMutation" ),
//                                              &fitnessOperation, GaFitnessComparatorCatalogue::Instance().GetEntryData( "GaMaxFitnessComparator" ),
//                                              &chromosomeParams );
//    
//	GaMultiValueChromosome<char> prototype( patternSize, &configBlock );
//    
//	GaPopulationConfiguration populationConfig;
//	GaPopulationParameters populationParams( 30, true, true, false, 0, 0 );
//    
//	populationConfig.SetParameters( populationParams );
//	populationConfig.SetSortComparator( &configBlock.GetFitnessComparator() );
//	populationConfig.Selection().GetParameters().SetSelectionSize( 6 );
//	
//	GaPopulation population( &prototype, &populationConfig );
//    
//	GaSimpleAlgorithmParams algorithmParams( 10, 2 );
//	GaSimpleAlgorithm algorithm( &population, algorithmParams );
//    
//	GaFitnessCriteriaParams criteriaParams( 100, GFC_EQUALS_TO, GSV_BEST_FITNESS );
//	algorithm.SetStopCriteria( GaStopCriteriaCatalogue::Instance().GetEntryData( "GaFitnessCriteria" ), 
//                              &criteriaParams );
//    
//	pObserver observer;
//	algorithm.SubscribeObserver( &observer );
//    
//	algorithm.StartSolving( false );
//    
//	algorithm.WaitForThreads();
//    
	GaFinalize();
    
    printf("Done\n");
    
	return 0;
}
