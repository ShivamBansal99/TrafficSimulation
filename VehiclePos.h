/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VehiclePos.h
 * Author: anmol
 *
 * Created on February 26, 2019, 4:07 PM
 */

#ifndef VEHICLEPOS_H
#define VEHICLEPOS_H
#include <vehicle.h>
#include <list>
class VehiclePos {
public:
    int redline;
    list<vehicle> allvehicles;
    addVehicle(vehicle v);
    bool availornot(int x, int y);
    moveall();
    VehiclePos();
    VehiclePos(const VehiclePos& orig);
    virtual ~VehiclePos();
private:

};

#endif /* VEHICLEPOS_H */

