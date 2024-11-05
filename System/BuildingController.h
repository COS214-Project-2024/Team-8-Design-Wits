#ifndef BUILDINGCONTROLLER_H
#define BUILDINGCONTROLLER_H

#include "Citizen.h"
#include "Buildings.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Utility.h"

#include <iostream>

/**
 * @class BuildingController
 * @brief A class to manage a collection of buildings and their resource requirements.
 * 
 * The BuildingController class manages a list of buildings and provides methods to add,
 * remove, and query information about buildings, including resource requirements and costs.
 * This class also provides some aggregated metrics like total power, sewage, water requirements,
 * and maintenance costs for the buildings.
 */
class BuildingController
{
private:
    Buildings ** ListOfBuildings; ///< A dynamic array of pointers to Building objects.
    int amountOfBuildings; ///< The current number of buildings in the list.

public:
    /**
     * @brief Default constructor for the BuildingController class.
     * 
     * Initializes internal variables and allocates memory for the list of buildings.
     */
    BuildingController();

    /**
     * @brief Destructor for the BuildingController class.
     * 
     * Cleans up dynamically allocated memory (e.g., deletes the list of buildings).
     */
    ~BuildingController();

    /**
     * @brief Adds a new building to the list.
     * 
     * This method adds a new Building object to the dynamic array and updates the internal count
     * of the number of buildings.
     * 
     * @param add A pointer to the Building object to be added.
     */
    void addBuilding(Buildings * add);

    /**
     * @brief Removes a building from the list.
     * 
     * This method removes a Building object from the dynamic array and updates the internal count
     * of the number of buildings.
     * 
     * @param rem A pointer to the Building object to be removed.
     */
    void removeBuilding(Buildings * rem);

    /**
     * @brief Gets the total number of buildings in the list.
     * 
     * This method returns the current count of buildings managed by the controller.
     * 
     * @return The number of buildings (int).
     */
    int getAmountOfBuildings();

    /**
     * @brief Gets the total power requirement of all buildings.
     * 
     * This method calculates the total power required by all buildings in the list by iterating
     * through the buildings and summing their individual power requirements.
     * 
     * @return The total power requirement (int).
     */
    int getTotalPowerReq();

    /**
     * @brief Gets the total sewage requirement of all buildings.
     * 
     * This method calculates the total sewage requirement of all buildings by iterating
     * through the list of buildings and summing their individual sewage requirements.
     * 
     * @return The total sewage requirement (int).
     */
    int getTotalSewageReq();

    /**
     * @brief Gets the total waste requirement of all buildings.
     * 
     * This method calculates the total waste generated by all buildings in the list.
     * 
     * @return The total waste requirement (int).
     */
    int getTotalWasteReq();

    /**
     * @brief Gets the total water requirement of all buildings.
     * 
     * This method calculates the total water required by all buildings in the list.
     * 
     * @return The total water requirement (int).
     */
    int getTotalWaterReq();

    /**
     * @brief Gets the total maintenance cost of all buildings.
     * 
     * This method calculates the total maintenance cost for all buildings in the list.
     * 
     * @return The total maintenance cost (int).
     */
    int getMaintenanceCost();

    /**
     * @brief Gets a list of citizens associated with the buildings.
     * 
     * This method may return the list of citizens related to the buildings, assuming buildings 
     * have a link to citizens (e.g., tenants or residents).
     * 
     * @return A pointer to an array of Citizen objects (Citizen**).
     */
    Citizen** getListOfCitizens();

    /**
     * @brief Gets the total commercial income from all commercial buildings.
     * 
     * This method sums the commercial income of all commercial buildings in the list.
     * 
     * @return The total commercial income (int).
     */
    int getCommercialIncome();
};


#endif