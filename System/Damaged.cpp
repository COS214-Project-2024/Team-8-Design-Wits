#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include "Damaged.h"
#include "State.h"
#include "Buildings.h"
#include "Operational.h"
#include "Utility.h"
class Buildings;
class Operational;

Damaged::Damaged()
{
	this->stateName = "Damaged";
}

void Damaged::handle() {
	cout<<"This building is damaged, replenish resources to repair!"<<endl;
}

void Damaged::changeState() {
	if(this->building->resources != nullptr )
	{
        if(building->getPower() && building->getPower())
        {
            State* newState = new Operational();
            building->setState(newState);
            cout<<"The building is now Operational again, resources have been replenished!";
            //if the resources are available, the building will be repaired
            //the state will become operations
        }
	}
	else
	{
		//the building will remain damaged
		cout<<"No resources available. please replenish resources to make this building operational"<<endl;
	}
}

string Damaged::getStateName()
{
	return this->stateName;
}
