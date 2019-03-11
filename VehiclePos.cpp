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
//TODO: avail or not to be completed
void VehiclePos::setRedLight(int i){
    VehiclePos::redlight=i;
}
bool VehiclePos::availornot(int xleft,int xright,int yup,int ydown){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        if( ((( (*(*it)).posx  < xright ) && ( (*(*it)).posy + (*(*it)).width > yup )) && (( (*(*it)).posx+ (*(*it)).length  > xleft ) && ( (*(*it)).posy   < ydown ))) || ((yup  <0 )) || (ydown>VehiclePos::roadwidth) || (xright>VehiclePos::redline && VehiclePos::redlight==1)) {
            return false;
        }
    }
    return true;
}

char VehiclePos::position(int x,int y){
    if(x==VehiclePos::redline && VehiclePos::redlight==1){
        return '|';
    }
    char res=' ';
    int count=0;
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        if( (( (*(*it)).posx  <= x ) && ( (*(*it)).posy + (*(*it)).width > y )) && (( (*(*it)).posx+ (*(*it)).length  > x ) && ( (*(*it)).posy   <= y )) ) {
            res=(*(*it)).name.at(0);
            count++;
        }
    }
    if(count>1){
        return '$';
    }else{
        return res;
    }
    return ' ';
}

void VehiclePos::moveall(){
    for(auto it= VehiclePos::allvehicles.begin();it!=VehiclePos::allvehicles.end();it++){
        int nextx=(*(*it)).posx+ (*(*it)).length+(*(*it)).speed*(*(*it)).time;
        if(VehiclePos::availornot((*(*it)).posx+ (*(*it)).length+1,nextx,(*(*it)).posy,(*(*it)).posy+(*(*it)).width) ) {
            (*(*it)).movex();
        }
        else{
            srand(time(0));
            if(rand()%100<(*it)->lcFreq && (nextx<VehiclePos::redline)){
                int nextx=(*(*it)).posx+ (*(*it)).length+(*(*it)).speed*(*(*it)).time;
                int nexty=(*(*it)).posy+(*(*it)).width+1;
                if(VehiclePos::availornot((*(*it)).posx,(*(*it)).posx+(*(*it)).length,nexty,nexty)  ) {
                    (*(*it)).movey(1);
                }else{
                    nexty=(*(*it)).posy-1;
                    if(VehiclePos::availornot((*(*it)).posx,(*(*it)).posx+(*(*it)).length,nexty,nexty) ) {
                        (*(*it)).movey(-1);
                    }
                }
            }
        }
    }
}

VehiclePos::VehiclePos() {
}

VehiclePos::~VehiclePos() {
}

