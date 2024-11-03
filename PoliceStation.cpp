#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include "PoliceStation.h"
#include "State.h"
#include "UnderConstruction.h"
#include "ResourceMediator.h"
#include "Citizen.h"

PoliceStation::PoliceStation(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int employment, float sCov)
{
	this->buildingName = bName;
	this->buildingType = "Public Service";
	this->powerReq = pReq;
	this->waterReq = wReq;
	this->maintenanceCost = mCost;
	this->sewageCost = sCost;
	this->waste = waste;
	this->employment = employment;
	this->securityCoverage = sCov;

	this->state =  new UnderConstruction(); //when we instantiate a building it will be under construction
	this->state->handle(); //handle the state;
	this->setState(); //change the state to operation if the resources are available

	this->listOfCitizens = new Citizen("NewCitizen",100,21,5.0);
}

void PoliceStation::requestState() {
	this->state->handle();
}

double PoliceStation::getMaintenanceCost() {
	return this->maintenanceCost;
}

int PoliceStation::getPowerReq() {
	return this->powerReq;
}

int PoliceStation::getSewageCost() {
	return this->sewageCost;
}

int PoliceStation::getWaterReq() {
	return this->waterReq;
}

int PoliceStation::getWasteCost() {
	return this->waste;
}

void PoliceStation::setState(State* newState)
{
	this->state = newState;
}


int PoliceStation::getJobsCreated()
{
	return employment; //NOT SURE - ask Tebogo what this should return
}

string PoliceStation::getName()
{
	return this->buildingName;
}

string PoliceStation::getBuildingType()
{
	return this->buildingType;
}

float PoliceStation::getSecurityCoverage()
{
	return this->securityCoverage;
}

bool PoliceStation::payMaintenance()
{
	if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully paid maintenance."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to pay maintenance"<<endl;
		this->state->changeState();
		return false;
	}
}

bool PoliceStation::receivePower()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->useRevenue(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully paid maintenance."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to pay maintenance"<<endl;
		this->state->changeState();
		return false;
	}
}

bool PoliceStation::receiveWater()
{
		if(this->waterReq > 200)
	{
		this->resources->useWater(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully recieved water."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to recieve water."<<endl;
		this->state->changeState();
		return false;
	}
}

bool PoliceStation::cleanSewage()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->cleanSewage(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully cleaned sewage."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to clean sewage."<<endl;
		this->state->changeState();
		return false;
	}
}
    
bool PoliceStation::cleanWaste()
{
		if(this->maintenanceCost > 200)
	{
		this->resources->cleanWaste(100, this);
		this->maintenanceCost = this->maintenanceCost - 100;
		cout<<"successfully cleaned waste."<<endl;
		return true;
	}
	else
	{
		cout<<"insufficient funds to clean waste"<<endl;
		this->state->changeState();
		return false;
	}
}


