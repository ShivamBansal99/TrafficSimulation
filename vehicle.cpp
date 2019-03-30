/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vehicle.cpp
 * Author: anmol
 * 
 * Created on February 25, 2019, 10:29 PM
 */

#include <cstdlib>
#include "vehicle.h"
using namespace std;

vehicle::vehicle(string color,string name,int acc,int maxvel,int posx,int posy, int length,int width,int speed,int lcFreq,int time) {
    vehicle::color=color;
    vehicle::name=name;
    vehicle::acc=acc;
    vehicle::maxvel=maxvel;
    vehicle::posx=posx;
    vehicle::posy=posy;
    vehicle::length=length;
    vehicle::width=width;
    vehicle::speed=speed;
    vehicle::lcFreq=lcFreq;
    vehicle::time=time;
    vehicle::movingLeft=0;
}

void vehicle::new_vehicle(specs* s,string color,int posx,int posy,int speed) {
    vehicle::color=color;
    vehicle::name=s->name;
    vehicle::acc=s->acc;
    vehicle::maxvel=s->maxvel;
    vehicle::posx=posx;
    vehicle::posy=posy;
    vehicle::length=s->length;
    vehicle::width=s->width;
    vehicle::speed=speed;
    vehicle::lcFreq=s->lcFreq;
    vehicle::time=s->time;
    vehicle::movingLeft=0;
}

vehicle::vehicle() {
}

vehicle::~vehicle() {
}

void vehicle::accelerate() {
    if(vehicle::speed<vehicle::maxvel){
        vehicle::speed+=vehicle::acc*vehicle::time;
    }
    if(vehicle::speed>vehicle::maxvel){
        vehicle::speed=vehicle::maxvel;
    }
}
void vehicle::movex(int avail) {
    int old = vehicle::posx;
    vehicle::posx=avail-vehicle::length;
    vehicle::speed=1+((vehicle::posx-old)/(vehicle::time));
}

void vehicle::movey(int y) {
    vehicle::posy += y;
}


