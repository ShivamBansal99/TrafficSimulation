/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   specs.h
 * Author: anmol
 *
 * Created on February 27, 2019, 11:50 PM
 */

#ifndef SPECS_H
#define SPECS_H
#include <string>
#include <cstdlib>
using namespace std;
class specs {
public:
    string color;
    string name;
    int acc,maxvel,posx,posy,movingLeft;
    int length,width,speed,lcFreq,time;
    void set_specs(string name,int acc,int maxvel,int length,int width,int lcFreq,int time);
    specs();
    specs(const specs& orig);
    virtual ~specs();
private:

};

#endif /* SPECS_H */

