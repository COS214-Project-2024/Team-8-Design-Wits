#include "LandmarkBuilding.h"
#include <string>
using namespace std;
#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H

/**
 * @class CulturalCenter
 * @brief Represents a cultural center building, inheriting from LandmarkBuilding.
 */
class CulturalCenter : public LandmarkBuilding {

    string buildingName;          /**< Name of the cultural center. */
    string buildingType;          /**< Type of the cultural center. */
    Citizen* listOfCitizens;      /**< List of citizens associated with the cultural center. */

    double maintenanceCost;       /**< Maintenance cost for the cultural center. */
    int powerReq;                 /**< Power requirement of the cultural center. */
    int waterReq;                 /**< Water requirement of the cultural center. */
    int sewageCost;               /**< Sewage cost for the cultural center. */
    int waste;                    /**< Waste generated by the cultural center. */

    Utility* resources;  /**< Mediator for managing resources. */
    State* state;                 /**< Current state of the cultural center. */

public:
    /**
     * @brief Constructs a CulturalCenter object with the specified attributes.
     * @param bName Name of the building.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste generated by the building.
     */
    CulturalCenter(string bName, int pReq, int wReq, double mCost, int sCost, int waste);


    /**
     * @brief Gets the type of the cultural center.
     * @return The type of the building as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the cultural center.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the cultural center.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the cultural center.
     * @return The name of the building as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the cultural center.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the cultural center.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the cultural center.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Requests the current state of the cultural center.
     */
    virtual void requestState();

    /**
     * @brief Gets the waste cost for the cultural center.
     * @return The waste cost as an integer.
     */
    int getWasteCost();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);
};

#endif
