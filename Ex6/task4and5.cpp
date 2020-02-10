/*----------------------------------------------------
TITLE:  Assignment 6: Task 4
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - 
---------------------------------------------------*/

#include "task4and5.h"
#include "def.h"
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;
bool gData = false; // global switch-variabel used for task 5

istream& operator>>(istream& is, Temps& t) {
    is >> t.max;
    is >> t.min;
    return is;
}

vector<Temps> addTemp(Temps t, vector<Temps> tempVector) {
    tempVector.push_back(t);
    return tempVector;
}

void getTemp(vector<Temps> tempVector) {
    for (int i = 0; i < tempVector.size(); i++) {
        cout << "Max: " << tempVector[i].max << " \tMin: " << tempVector[i].min << endl;
    }
}

void testOperator(void) {
    int tempSize = 0;
    vector<Temps>tempVector;
    ifstream temp_file(PATH_T);
    Temps t;
    while (!temp_file.eof()) {
        temp_file >> t;
        tempVector = addTemp(t, tempVector);
    }
    tempSize = static_cast<int>(tempVector.size());
#if DEB_TXT
    cout << "Size of vector: " << tempSize << endl;
#endif /* DEB_TXT */
    if (gData == false) {
        getTemp(tempVector);
    }
    else{   // Task 5 below:
        double maxValue = 0;
        for (int i = 0; i < tempVector.size(); i++) {
            if (tempVector[i].max > maxValue) {maxValue = tempVector[i].max;}
            if (abs(tempVector[i].min) > maxValue) {maxValue = abs(tempVector[i].min);}
        }
        cout << maxValue << " = MAX" << endl;
        cout << "\nRunning task 5:" << endl;
        using namespace Graph_lib;
        int yScale = 2;
        int xmax = tempVector.size();
        int ymax = maxValue*2*yScale+100; //maxValue*yScale;
        int xoffset = 5;
        int xPos = xoffset;
        int yPosMin = 0;
        int yPosMax = 0;
        int yoffset = ymax / 100;
        int xlength = xmax - ((xmax*10)/100);
        int ylength = ymax - ((ymax*10)/100);
        cout << "Yo" << endl;
        
        
#if DEB_TXT
        cout << "Initiate axis:" << endl;
#endif /* DEB_TXT */
    
        Window win {Point{100,100},xmax,ymax,"Temperatures"};
        Axis x {Axis::x, Point{xoffset,ymax/2}, xlength, 12, "Feb\t" "Mar\t" "Apr\t" "May\t" "Jun\t" "Jul\t" "Aug\t" "Sep\t" "Oct\t" "Nov\t" "Dec\t" "Jan"};
        x.label.move(-100,0);
        x.set_color(Color::black);
        win.attach(x);
        Axis y {Axis::y, Point{xoffset,ymax-yoffset}, ylength, ylength/20,"Degrees [C]"};
        y.set_color(Color::black);
        win.attach(y);

#if DEB_TXT
        cout << "Start plotting:" << endl;
#endif /* DEB_TXT */

        Open_polyline gMin;
        Open_polyline gMax;
        cout << "YoYo" << endl;

        for (int i = 0; i < tempSize; i++) {
            cout << i << endl;
            xPos = xoffset + i;
            yPosMin = -static_cast<int>(tempVector[i].min)*yScale + (ymax/2);
            yPosMax = -static_cast<int>(tempVector[i].max)*yScale + (ymax/2);

#if DEB_TXT
            cout << "yPosMin: " << yPosMin << " and yPosMax: " << yPosMax << endl;
#endif /* DEB_TXT */
        
            gMin.add(Point{xPos,yPosMin});
            gMax.add(Point{xPos,yPosMax});
        }

        gMin.set_color(Color::blue);
        gMax.set_color(Color::red);
        win.attach(gMin);
        win.attach(gMax);
        win.wait_for_expose();
    }
}

void graphData(void) {
    if (gData == false) {gData = true;}
    testOperator();
    gData = false;
}