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
#include <tuple>
#include<time.h>
#include "VehiclePos.h"
#include <unistd.h>
#include "scan.h"

#define loop(a,b) for(int a=0;a<b;a++)
using namespace std;

/*

 * 
 */
VehiclePos* vp = new VehiclePos(8,10,10);
long long unit =0 ;
vector< vector<int> > spec ;			 
vector<string> types; 	
vector< vector<string> > seconds ;
/*
tuple<float,float,float> colorconv(string a){
	if(!a.compare("red")) return make_tuple((float)247.0/255.0,(float)81.0/255.0,(float) 81.0/255.0) ;	
	if(!a.compare("blue")) return make_tuple((float)81/255.0,(float)205/255.0,(float)247/255.0) ;
	if(!a.compare("green")) return make_tuple((float)136/255.0,(float)247/255.0,(float)81/255.0) ;
	if(!a.compare("purple")) return make_tuple((float)240/255.0,(float)111/255.0,(float)247/255.0) ;
	if(!a.compare("yellow")) return make_tuple((float)247/255.0,(float)236/255.0,(float)111/255.0) ;
	if(!a.compare("brown")) return make_tuple((float)150/255.0,(float)99/255.0,(float)66/255.0) ;
	if(!a.compare("black")) return make_tuple((float)48/255.0,(float)43/255.0,(float)40/255.0) ;
	}
void move(){
	unit++ ;
	(*vp).moveall() ;
	//cout<<unit<<endl ;
}

void environment(){
		int length=spec[0][1] ;
		int width = spec[0][2]*spec[0][3] ;
		int lanes=spec[0][2] ;
		glBegin(GL_QUADS);
		glColor3f(0,0,0) ;
    		glVertex2f(0,width);
    		glVertex2f(length,width);
    		glVertex2f(length,width+5);
    		glVertex2f(0,width+5);
		glEnd() ;
		glBegin(GL_QUADS);
		glColor3f(0,0,0) ;
    		glVertex2f(0,0);
    		glVertex2f(length,0);
    		glVertex2f(length,-5);
    		glVertex2f(0,-5);
		glEnd() ;		
}
void diveh(int x, int y, int l, int b, tuple<float,float,float> color){
		//cout<< get<0> (color)<< get<1> (color)<<get<2> (color)<<endl ;
		//
	glBegin(GL_QUADS);
		glColor3f(get<0> (color),get<1> (color),get<2> (color)) ;
    		glVertex2f(x,y);
    		glVertex2f(x+l,y);
    		glVertex2f(x+l,y+b);
    		glVertex2f(x,y+b);
	glEnd() ;
}
void display() {
	list <vehicle*> allv = (*vp).allvehicles ;
	list <vehicle*> :: iterator it; int n= allv.size() ;
	int times=0;
	glClear(GL_COLOR_BUFFER_BIT);
	environment() ;
	for(it=allv.begin();it!=allv.end();it++) {
		
		diveh((*it)->posx,(*it)->posy,(*it)->length,(*it)->width,colorconv((*it)->color)) ;
	}
	//glTranslatef(xg,yg,0.0f) ;

	glFlush() ;
	glutPostRedisplay() ;
	glutSwapBuffers();
	move() ;
	usleep(10000);
	//cout<<xg<<" "<<yg<<" "<<l<<" "<<b<<endl ;
	//times++ ;cout<<times<<endl ;
}

void start(int argc, char** argv){
	int max_road_len=spec[0][0] ;
	int max_road_width = spec[0][2]*spec[0][3] ;
	int lanes=spec[0][2] ;
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	 glutInitWindowSize(1000,800);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");

	glutDisplayFunc(display);
	//glutIdleFunc(callglut);
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	gluOrtho2D(0,max_road_len,-(800-max_road_width)/2,(max_road_width+800)/2) ; //workout later ;
	//gluOrtho2D(0,800,0,800) ;
	//glutSpecialFunc(Event) ;
	glutMainLoop() ;
	
}*/
vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
int main(int argc, char** argv) {
    
    specs *specific=new specs[100];
    int specs_count=0;
    vehicle *vehcl = new vehicle[100];
    int vehcl_count=0;
	scan(spec,types,seconds) ;
        (*vp).roadlength=spec[0][2]*2;
        (*vp).roadwidth=spec[0][3]/2;
            loop(i,spec.size()) {
                
                if(i>=3){
                    if(spec[i].size()==4){
                        //cout<<types[i]<<spec[i][0]<<spec[i][1]<<spec[i][2]<<spec[i][3];
                        specific[specs_count].set_specs(types[i],spec[i][0],spec[i][1],spec[i][2],spec[i][3],100,1);
                        cout<<specific[specs_count].width<<'\n';
                        specs_count++;
                    }
                    else if(spec[i].size()==2){
                        specific[specs_count].set_specs(types[i],spec[i][0],spec[i][1],10,10,100,1);
                        cout<<specific[specs_count].width<<'\n';
                        specs_count++;
                        specs_count++;
                        // cout<<specific[i].name;
                    }
                    else{
                        cout<<"check conf file";
                        return 1;
                    }
                }
                
	}
    int k=0;
    (*vp).setRedLight(1);
    int readline=1;
    int stop_time=0;
	 do
    {
        if(stop_time==0){
                //cout<<seconds[readline][0];
            if(seconds[readline][0]=="Pass"){
                stop_time=stoi(seconds[readline][1]);
            }if(seconds[readline][0]=="Signal"){
                if(seconds[readline][1]=="GREEN")   (*vp).setRedLight (0);
                else (*vp).setRedLight (1);
            }else{
                loop(i,specs_count){
                    cout<<specific[i].name<<'\n';
                    if(specific[i].name==seconds[readline][0]){
                        vehcl[vehcl_count].new_vehicle(&specific[i],seconds[readline][1],0,stoi(seconds[readline][2]),0);
                        (*vp).addVehicle(&vehcl[vehcl_count]);
                        vehcl_count++;
                        cout<<vehcl[vehcl_count-1].length;
                    }
                }
            }
        }
        else{
            stop_time--;
        }
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
        readline++;
    }
    while(readline<seconds.size() || stop_time!=0);
	
    return 0;
}

