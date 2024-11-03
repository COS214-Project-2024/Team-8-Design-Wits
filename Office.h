#include "CommercialBuilding.h"
#include <string>
using namespace std;

#ifndef OFFICE_H
#define OFFICE_H

/**
 * @class Office
 * @brief Represents an office building, inheriting from the CommercialBuilding class.
 */
class Office : public CommercialBuilding {

protected:
    // Basic building details
    string buildingName; /**< Name of the building. */
    string buildingType; /**< Type of the building. */
    Citizen* listOfCitizens; /**< List of citizens associated with the building. */

    // Resource and cost requirements
    double maintenanceCost; /**< Maintenance cost of the building. */
    int powerReq; /**< Power requirement of the building. */
    int waterReq; /**< Water requirement of the building. */
    int sewageCost; /**< Sewage cost for the building. */
    int waste; /**< Waste generated by the building. */
    ResourceMediator* resources; /**< Mediator for managing resources. */

    // Business metrics
    float sales; /**< Sales generated by the building. */
    float profit; /**< Profit from the building's operations. */
    int employment; /**< Number of jobs created by the building. */
    int income; /**< Income generated by the building. */
     double balance;               /**< Balance of the mall. */
    
    // Current building state
    State* state; /**< Current state of the building. */

public:
    // Pure virtual functions for building operations
    /**
     * @brief Constructor for the Office class.
     * @param bName Name of the building.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste produced.
     * @param sales Sales generated.
     * @param profit Profit made.
     * @param emp Number of jobs created.
     * @param income Income generated.
     */
    Office(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp, int income);
    
    /**
     * @brief Cleans the sewage of the building.
     * @return True if the sewage was cleaned successfully, otherwise false.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the building.
     * @return True if the waste was cleaned successfully, otherwise false.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the building.
     * @return String representing the building type.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the building.
     * @return Number of jobs created.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the building.
     * @return Maintenance cost.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the building.
     * @return Name of the building.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the building.
     * @return Power requirement.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the building.
     * @return Sewage cost.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the building.
     * @return Water requirement.
     */
    virtual int getWaterReq();

    /**
     * @brief Performs the operation associated with the building.
     */
    virtual void operation();

    /**
     * @brief Pays the maintenance cost of the building.
     * @return True if payment was successful, otherwise false.
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the building.
     * @return True if power was received successfully, otherwise false.
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the building.
     * @return True if water was received successfully, otherwise false.
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the building.
     */
    virtual void requestState();

    /**
     * @brief Gets the waste cost for the building.
     * @return Waste cost.
     */
    int getWasteCost();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);
    /**
     * @brief Gets the income generated by the building.
     * @return Income.
     */
    int getIncome();

    // Additional functions
    /**
     * @brief Gets the sales generated by the building.
     * @return Sales amount.
     */
    float getSales();

    /**
     * @brief Gets the profit generated by the building.
     * @return Profit amount.
     */
    float getProfit();

    /**
     * @brief Pays a citizen associated with the building.
     * @return Amount paid to the citizen.
     */
    int payCitizen();

     /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual int getCommercialIncome();

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual double getBalance();

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual void setBalance(double b);
};

#endif

