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
#include <vehicle.h>
using namespace std;

vehicle::vehicle() {
}

vehicle::vehicle(const vehicle& orig) {
}

vehicle::~vehicle() {
}

vehicle::move(float availPosy[]) {
    if((rand%100)/100 < vehicle::lcFreq){
        random_shuffle(availPosy, availPosy+sizeof(availPosy)/sizeof(*availPosy));
        vehicle:: = availPosy[0];
    }
    vehicle::posx+=vehicle::speed*vehicle::time;
    if(vehicle::speed<vehicle::maxvel){
        vehicle::speed+=vehicle::acc*vehicle::time;
    }
}

