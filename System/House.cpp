#include <iostream>
#include <exception>
using namespace std;

#include "House.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResidentialBuilding.h"
#include "Utility.h"
#include "Citizen.h"

House::House(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity)
{
	this->buildingName = bName;
	this->buildingType = "Residential";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->capacity = capacity;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->state->changeState();//in case it needs to change

	this->listOfCitizens = new Citizen("Newcitizen", 100, 21 , 5.0);
}

void House::requestState() {
	this->state->handle();
}

int House::getCapacity() {
	return this->capacity;
}

Citizen* House::getListOfResidents() {
return this->listOfCitizens;
}

double House::getMaintenanceCost() {
	return this->maintenanceCost;
}

int House::getPowerReq() {
	return this->powerReq;
}

int House::getWaterReq() {
	return this->waterReq;
}

int House::getSewageCost() {
	return this->sewageCost;
}

int House::getWasteCost() {
	return this->waste;
}

void House::setState(State* newState)
{
	this->state = newState;
}

string House::getName()
{
	return this->buildingName;
}

string House::getBuildingType()
{
	return this->buildingType;
}

void House::addBuilding(){
	if(resources){
		resources->addBuilding(this);
	}

}

bool House::getWater(){
	if(resources){
		return resources->getWater(this);
	}
return false;
}

bool House::cleanWaste(){
	if(resources){
		return resources->cleanWaste(this);
	}
return false;
}

bool House::cleanSewage(){
	if(resources){
		return resources->cleanSewage(this);
	}
return false;
}

bool House::getPower(){
	if(resources){
		return resources->getPower(this);
	}
return false;
}






