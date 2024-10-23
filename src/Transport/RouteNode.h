#ifndef ROUTENODE_H
#define ROUTENODE_H

#include "Stops.h"
class RouteNode {
protected:
	Stops* data = nullptr;
	RouteNode* successor = nullptr;

public:
	virtual void add(Stops* data) = 0;

	virtual float getDistance() = 0;

	virtual ~RouteNode();

	virtual Stops* getData() = 0;

	virtual RouteNode* travel() = 0;
};

#endif