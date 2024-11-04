#include <iostream>
#include <exception>
using namespace std;

#include "Office.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

Office::Office(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp, int income)
{
	this->buildingName = bName;
	this->buildingType = "Landmark";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->sales = sales;
	this->profit = profit;
	this->employment = emp;
	this->income = income;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
	this->listOfCitizens->adjustCitizenSatisfaction(5.0);
}

void Office::requestState() {
	this->state->handle();
}

double Office::getMaintenanceCost() {
	return this->maintenanceCost;
}

int Office::getPowerReq() {
	return this->powerReq;
}

int Office::getSewageCost() {
	return this->sewageCost;
}

int Office::getWasteCost() {
	return this->waste;
}

void Office::setState(State* newState)
{
	this->state = newState;
}

string Office::getName()
{
	return this->buildingName;
}

string Office::getBuildingType()
{
	return this->buildingType;
}

float Office::getSales()
{
	return this->sales;
}

float Office::getProfit()
{
	return this->profit;
}

int Office::getJobsCreated()
{
	return this->employment;
}

int Office::getIncome()
{
	return this->income;
}


int Office::payCitizen()
{
	cout<<"Paying citizen"<<endl;
	return 5000;
}

int Office::getCommercialIncome()
{
	return this->profit ;
}

void Office::setBalance(double d)
{
	this->balance  = d;
}

double Office::getBalance()
{
	return this->balance;
}
// In Office.cpp

int Office::getWaterReq() {
    return this->waterReq; // Return the water requirement
}
