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
    movex();
    movey(int posyavail[]);
    string color;
    int acc,maxvel,posx,posy;
    int length,width,speed,lcFreq,time;
private:
    
    
};

#endif /* VEHICLE_H */

