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
#include<string>
using namespace std;
class vehicle {
public:
    vehicle(string color,string name,int acc,int maxvel,int posx,int posy, int length,int width,int speed,int lcFreq,int time);
    vehicle();
    virtual ~vehicle();
    void movex();
    void movey(int y);
    string color;
    string name;
    int acc,maxvel,posx,posy,movingLeft;
    int length,width,speed,lcFreq,time;
private:
    
    
};

#endif /* VEHICLE_H */

