/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vehicle.h
 * Author: anmol
 *
 * Created on February 25, 2019, 10:29 PM
 */

#ifndef VEHICLE_H
#define VEHICLE_H
#include <cstdlib>
using namespace std;
class vehicle {
public:
    vehicle();
    vehicle(const vehicle& orig);
    virtual ~vehicle();
    move(float posyavail[]);
    string color;
private:
    float acc,maxvel,posx,posy;
    float length,width,speed,lcFreq,time;
    
};

#endif /* VEHICLE_H */

