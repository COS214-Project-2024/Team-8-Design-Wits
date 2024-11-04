#include "IndustrialBuilding.h"
#include <string>

using namespace std;

#ifndef POWERPLANT_H
#define POWERPLANT_H

/**
 * @class PowerPlant
 * @brief Class representing a power plant, inheriting from IndustrialBuilding.
 */
class PowerPlant : public IndustrialBuilding {

protected:
    // Basic building details
    string buildingName; ///< Name of the building
    string buildingType; ///< Type of the building
    Citizen* listOfCitizens; ///< List of citizens associated with the building

    // Resource and cost requirements
    double maintenanceCost; ///< Cost required for maintenance
    int powerReq; ///< Power requirement for the building
    int waterReq; ///< Water requirement for the building
    int sewageCost; ///< Sewage cost for the building
    ResourceMediator* resources; ///< Mediator for resources

    // Business metrics
    float sales; ///< Total sales generated by the building
    float profit; ///< Total profit generated by the building
    int employment; ///< Number of jobs created by the building
    int waste; ///< Waste generated by the building

    // Current building state
    State* state; ///< Current state of the building

public:
    // Pure virtual functions for building operations
    /**
     * @brief Constructs a PowerPlant with specified parameters.
     * @param bName Name of the building
     * @param pReq Power requirement
     * @param wReq Water requirement
     * @param mCost Maintenance cost
     * @param sCost Sewage cost
     * @param waste Amount of waste generated
     * @param employment Number of jobs created
     */
    PowerPlant(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment);
    
    /**
     * @brief Gets the type of building.
     * @return Type of the building as a string.
     */
    virtual string getBuildingType();
    
    /**
     * @brief Gets the number of jobs created by the building.
     * @return Number of jobs created.
     */
    virtual int getJobsCreated();
    
    /**
     * @brief Gets the maintenance cost of the building.
     * @return Maintenance cost as a double.
     */
    virtual double getMaintenanceCost();
    
    /**
     * @brief Gets the name of the building.
     * @return Name of the building as a string.
     */
    virtual string getName();
    
    /**
     * @brief Gets the power requirement of the building.
     * @return Power requirement as an integer.
     */
    virtual int getPowerReq();
    
    /**
     * @brief Gets the sewage cost of the building.
     * @return Sewage cost as an integer.
     */
    virtual int getSewageCost();
    
    /**
     * @brief Gets the water requirement of the building.
     * @return Water requirement as an integer.
     */
    virtual int getWaterReq();
    
    /**
     * @brief Requests the current state of the building.
     */
    virtual void requestState();
    
    /**
     * @brief Gets the waste cost of the building.
     * @return Waste cost as an integer.
     */
    int getWasteCost();
    
   /**
     * @brief sets the state of the building
     */
    void setState(State* newState);

    // Additional functions
    /**
     * @brief Gets the total sales of the building.
     * @return Total sales as a float.
     */
    float getSales();
    
    /**
     * @brief Gets the total profit of the building.
     * @return Total profit as a float.
     */
    float getProfit();
    
    /**
     * @brief Pays a citizen associated with the building.
     * @return The amount paid to the citizen as an integer.
     */
    int payCitizen();
};

#endif

