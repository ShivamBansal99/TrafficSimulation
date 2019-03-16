/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anmol
 *
 * Created on February 25, 2019, 10:28 PM
 */

#include <cstdlib>
#include <iostream>
#include "vehicle.h"
#include <string>
#include<time.h>
#include "VehiclePos.h"
#include <unistd.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vehicle* car= new vehicle("white","car",1,3,0,0, 5,3,0,100,1);
    vehicle* truck= new vehicle("white","truck",1,1,2,1, 5,4,0,100,1);
    vehicle* truk= new vehicle("white","lruck",1,2,5,3, 5,4,0,100,1);
    VehiclePos* vp = new VehiclePos(20,10,40);
    (*vp).addVehicle(car);
    (*vp).addVehicle(truck);
    (*vp).addVehicle(truk);
    int k=0;
    (*vp).setRedLight(1);
    do
    {
        if(k==25 ) (*vp).setRedLight(0);
        for(int i=0;i<(*vp).roadwidth;i++){
            for(int j=0;j<(*vp).roadlength;j++){
                cout<<(*vp).position(j,i)<<',';
            }
            cout<<'\n';
        }
        cout<<'\n';
        k++;
        (*vp).moveall();
        usleep(300000);
    }
    while(k<50);
    return 0;
}

