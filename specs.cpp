/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   specs.cpp
 * Author: anmol
 * 
 * Created on February 27, 2019, 11:50 PM
 */

#include "specs.h"
#include<string>
#include <cstdlib>
using namespace std;
void specs::set_specs(string name,int acc,int maxvel,int length,int width,int lcFreq,int time) {
    specs::name=name;
    specs::acc=acc;
    specs::maxvel=maxvel;
    specs::length=length;
    specs::width=width;
    specs::lcFreq=lcFreq;
    specs::time=time;
    specs::movingLeft=0;
}

specs::specs(const specs& orig) {
}
specs::specs() {
}

specs::~specs() {
}

