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

#include <string>

#include "VehiclePos.h"

VehiclePos::VehiclePos(int redline, int roadwidth,int roadlength) {
    VehiclePos::redline=redline;
    VehiclePos::roadwidth=roadwidth;
    VehiclePos::roadlength=roadlength;
}

void VehiclePos::addVehicle(vehicle* v){
    VehiclePos::allvehicles.push_front(v);
}
//TODO: avail ot not to be completed
bool VehiclePos::availornot(int xleft,int xright,int yup,int ydown){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        if( (( (*(*it)).posx - (*(*it)).length < xright ) && ( (*(*it)).posy - (*(*it)).width < yup )) && (( (*(*it)).posx  > xleft ) && ( (*(*it)).posy  > ydown )) ) {
            return false;
        }
    }
    return true;
}

char VehiclePos::position(int x,int y){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        if( (( (*(*it)).posx - (*(*it)).length < x ) && ( (*(*it)).posy - (*(*it)).width < y )) && (( (*(*it)).posx  > x ) && ( (*(*it)).posy  > y )) ) {
            return (*(*it)).name.at(0);
        }
    }
    return ' ';
}

void VehiclePos::moveall(){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        int nextx=(*(*it)).posx+(*(*it)).speed*(*(*it)).time;
        if(VehiclePos::availornot((*(*it)).posx+1,nextx,(*(*it)).posy,(*(*it)).posy-(*(*it)).width) ) {
            (*(*it)).movex();
        }
        int nexty=(*(*it)).posy+1;
        if(VehiclePos::availornot((*(*it)).posx-(*(*it)).length,(*(*it)).posx,nexty,nexty) ) {
            (*(*it)).movey(1);
        }
        nexty=(*(*it)).posy-1;
        if(VehiclePos::availornot((*(*it)).posx-(*(*it)).length,(*(*it)).posx,nexty,nexty) ) {
            (*(*it)).movey(-1);
        }
    }
}

VehiclePos::VehiclePos() {
}

VehiclePos::~VehiclePos() {
}

