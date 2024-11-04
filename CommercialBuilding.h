#include <string>
#include "Buildings.h"
using namespace std;

#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

class Citizen;
class Utility;
class State;

/**
 * @class CommercialBuilding
 * @brief Represents a commercial building with specific business-related attributes.
 */
class CommercialBuilding : public Buildings {

protected:
    float sales;                  /**< Sales generated by the commercial building. */
    float profit;                 /**< Profit generated by the commercial building. */
    int employment;               /**< Employment count in the commercial building. */
    double balance;               /**< Balance of the commercial building. */
    int income;
    int waste;                   /**< Income generated by the mall. */

    State* state;                 /**< Current state of the building. */


public:
    
    /**
     * @brief Gets the type of the building.
     * @return The type of the building as a string.
     */
    virtual string getBuildingType() = 0;

    /**
     * @brief Gets the number of jobs created by the building.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated(){return employment;}

    /**
     * @brief Gets the maintenance cost of the building.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost() = 0;

    /**
     * @brief Gets the name of the building.
     * @return The name of the building as a string.
     */
    virtual string getName() = 0;

    /**
     * @brief Gets the power requirement of the building.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq() = 0;

    /**
     * @brief Gets the sewage cost of the building.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost() = 0;

    /**
     * @brief Gets the water requirement of the building.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq() = 0;

    /**
     * @brief Requests the current state of the building.
     */
    virtual void requestState() = 0;

    /**
     * @brief Gets the sales generated by the commercial building.
     * @return Sales amount as a float.
     */
    virtual float getSales(){return sales;}

    /**
     * @brief Gets the profit generated by the commercial building.
     * @return Profit amount as a float.
     */
    virtual float getProfit(){return profit;}

    /**
     * @brief Pays a citizen employed in the building.
     * @return The payment amount as an integer.
     */
    virtual int payCitizen(){return 100;}

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual int getCommercialIncome(){return income;}

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual double getBalance(){return balance;}

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual void setBalance(double b){balance = b;}

    /**
     * @brief sets the state of the building
     */
    virtual void setState(State* newState) = 0;

    /**
     * @brief Receives power for the building.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool getPower() = 0;

    /**
     * @brief Receives water for the building.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool getWater() = 0;

    /**
     * @brief Cleans the waste of the building.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste() = 0;

    /**
     * @brief Cleans the sewage of the building.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage() = 0;

    /**
	 * @brief Add a building to the Utility resource
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding() = 0;

    virtual ~CommercialBuilding(){}
};

#endif
