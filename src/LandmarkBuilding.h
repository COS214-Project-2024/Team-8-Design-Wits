#include <exception>
using namespace std;

#ifndef __LandmarkBuilding_h__
#define __LandmarkBuilding_h__

#include "State.h"
#include "Buildings.h"

class State;
// class Buildings;
class LandmarkBuilding;

class LandmarkBuilding: public Buildings
{
	private: State _state;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;

	public: void requestState();

	public: double getMaintenanceCost();

	public: int getPowerReq();

	public: int getSewageCost();

	public: int getWaterCost();

	public: int getWasteCost();
};

#endif
