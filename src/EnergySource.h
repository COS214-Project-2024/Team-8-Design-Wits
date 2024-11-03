#ifndef ENERGYSOURCE_H
#define ENERGYSOURCE_H

#include <iostream>
/**
 * @file EnergySource.h
 * 
 * @brief The header file for the EnergySource class
 */
class EnergySource {
protected:
	float energyOutput;

public:
	float getEnergyOutput();

	virtual std::string getFuelType() = 0;
};

#endif
