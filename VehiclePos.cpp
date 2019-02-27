/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VehiclePos.cpp
 * Author: anmol
 * 
 * Created on February 26, 2019, 4:07 PM
 */

#include "VehiclePos.h"

VehiclePos::VehiclePos() {
}

VehiclePos::addVehicle(vehicle v){
    VehiclePos::allvehicles.push_front(v);
}
//TODO: avail ot not to be completed
bool VehiclePos::availornot(int xleft,int xright,int yup,int ydown){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        if( ( (*it).posx - (*it).length < xright ) && ( (*it).posy - (*it).width < yup && (*it).posy >= ydown) || x>=VehiclePos::redline) {
            return false;
        }
    }
    return true;
}

VehiclePos::moveall(){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        bool avail= true;
        int nextx=(*it).posx+(*it).speed*(*it).time;
        
        for()
        if( ) {
            (*it).movex();
        }
    }
}

VehiclePos::VehiclePos(const VehiclePos& orig) {
}

VehiclePos::~VehiclePos() {
}

