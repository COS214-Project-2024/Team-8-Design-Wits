#include "ResidentialBuilding.h"
#include <string>
using namespace std;

#ifndef HOUSE_H
#define HOUSE_H

/**
 * @class House
 * @brief Represents a house, inheriting from ResidentialBuilding.
 */
class House : public ResidentialBuilding {

protected:
    string buildingName;          /**< Name of the house. */
    string buildingType;          /**< Type of the house. */
    int capacity;                 /**< Capacity of the house. */
    Citizen* listOfCitizens;      /**< List of citizens residing in the house. */

    double maintenanceCost;       /**< Maintenance cost for the house. */
    int powerReq;                 /**< Power requirement of the house. */
    int waterReq;                 /**< Water requirement of the house. */
    int sewageCost;               /**< Sewage cost for the house. */
    int waste;                    /**< Waste generated by the house. */

    ResourceMediator* resources;  /**< Mediator for managing resources. */
    State* state;                 /**< Current state of the house. */

public:
    /**
     * @brief Constructs a House object with the specified attributes.
     * @param bName Name of the house.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste generated by the house.
     * @param capacity Capacity of the house.
     */
    House(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int capacity);

    /**
     * @brief Cleans the sewage of the house.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the house.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the house.
     * @return The type of the building as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the house.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the house.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the house.
     * @return The name of the building as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the house.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the house.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the house.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Pays the maintenance cost for the house.
     * @return true if payment was successful, false otherwise.
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the house.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the house.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the house.
     */
    virtual void requestState();

    /**
     * @brief Sets the state of the house.
     */
    void setState();

    /**
     * @brief Gets the list of residents in the house.
     * @return Pointer to the list of residents (Citizen objects).
     */
    Citizen* getListOfResidents();

    /**
     * @brief Gets the capacity of the house.
     * @return The capacity as an integer.
     */
    int getCapacity();

    /**
     * @brief Gets the waste cost for the house.
     * @return The waste cost as an integer.
     */
    int getWasteCost();
};

#endif