#include "PopulationControl.h"

// Define the maximum population limit
const int PopulationControl::MAX_POPULATION = 1000000;
// Migration rate multiplier (5% per 1000 jobs)
const float PopulationControl::MIGRATION_RATE_MULTIPLIER = 0.05f;


// Constructor initializes total population to zero
PopulationControl::PopulationControl() : totalPopulation(0) {}

// Destructor deallocates dynamically allocated buildings
PopulationControl::~PopulationControl() {
}

// Update the total population based on the new building being added
void PopulationControl::updatePopulation(ResidentialBuilding* building) {
    int buildingCapacity = 0;
    if(building->getBuildingType() == "Residential"){
        buildingCapacity = building->getCapacity();
    }

    // Check if adding this building will exceed the maximum population
    if (totalPopulation + buildingCapacity <= MAX_POPULATION) {
        totalPopulation += buildingCapacity; 
        buildings.push_back(building);
    } else {
        std::cout << "Cannot add building: population limit exceeded! Enforcing population policy." << std::endl;
        enforcePopulationControl();
    }
    // Simulate migration based on jobs created for commercial buildings
        if (CommercialBuilding* commercialBuilding = dynamic_cast<CommercialBuilding*>(building)) {
            simulateMigration(commercialBuilding->getJobsCreated());
        }
}


// Get the current total population
int PopulationControl::getTotalPopulation() {
    return totalPopulation;
}

// Simulate population growth based on births from medical centers
void PopulationControl::simulatePopulationGrowth() {
    int totalBirths = 0;

    for (const Buildings* building : buildings) {
        if (const MedicalCenter* constHospital = dynamic_cast<const MedicalCenter*>(building)) {
            MedicalCenter* hospital = const_cast<MedicalCenter*>(constHospital);
            totalBirths += hospital->getBirthRate();
        }
    }

    totalPopulation += totalBirths;

    if (totalPopulation > MAX_POPULATION) {
        enforcePopulationControl();
    }
}



// Simulate migration based on jobs created in commercial buildings
void PopulationControl::simulateMigration(int jobsCreated) {
    int migrationEffect = calculateMigration(jobsCreated);
    totalPopulation += migrationEffect;

    if (totalPopulation > MAX_POPULATION) {
        enforcePopulationControl();
    }
}

// Calculate migration effect based on jobs created
int PopulationControl::calculateMigration(int jobsCreated)  {
    return static_cast<int>(jobsCreated * MIGRATION_RATE_MULTIPLIER);
}

// Enforce population control policies when limits are exceeded
void PopulationControl::enforcePopulationControl() {
    int overflow = totalPopulation - MAX_POPULATION;

    // Reduce population through emigration incentive
    if (overflow > 0) {
        int emigration = static_cast<int>(overflow * 0.10f); // Emigrate 10% of overflow
        std::cout << "Population exceeds maximum limit. Emigrating " << emigration << " people." << std::endl;
        totalPopulation -= emigration;
    }

    // Ensure total population does not exceed the maximum limit
    if (totalPopulation > MAX_POPULATION) {
        totalPopulation = MAX_POPULATION;
    }
}

void PopulationControl::increasePopulation()
{
    totalPopulation++;
}
