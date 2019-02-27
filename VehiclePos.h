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
#include "vehicle.h"
#include <list>
class VehiclePos {
public:
    int redline;
    list<vehicle*> allvehicles;
    int roadwidth,roadlength;
    void addVehicle(vehicle* v);
    bool availornot(int xleft,int xright,int yup,int ydown);
    char position(int x, int y);
    void moveall();
    VehiclePos(int redline, int roadwidth,int roadlength);
    VehiclePos();
    virtual ~VehiclePos();
private:

};

#endif /* VEHICLEPOS_H */

