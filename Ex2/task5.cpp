#include <iostream>
//#include "../head/task5.h"
#include "task5.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;


void pythagoras(void) {
    int w = 1000;
    int h = 1000;
    int tx = 400;
    int ty = 400;
    int lx = 400;
    int ly = 600;
    int rx = 600;
    int ry = 600;
    Polygon rightTriangle;
    Polygon squareOne;      // Bottom
    Polygon squareTwo;      // Left
    Polygon squareThr;      // Right
    
    // Triangle setup:
    rightTriangle.add(Point{tx,ty});  //top
    rightTriangle.add(Point{lx,ly});  //left
    rightTriangle.add(Point{rx,ry});  //right
    rightTriangle.set_fill_color(Color::black);

    // Bottom square setup:
    squareOne.add(Point{lx,ly});
    squareOne.add(Point{rx,ry});
    squareOne.add(Point{lx,ly+(rx-lx)});
    squareOne.add(Point{rx,ry+(rx-lx)});
    rightTriangle.set_fill_color(Color::red);
    /*
    // left square setup:
    squareOne.add(Point{x,y});
    squareOne.add(Point{x,y});
    squareOne.add(Point{x,y});
    squareOne.add(Point{x,y});
    rightTriangle.set_fill_color(Color::green);

    // Right square setup:
    squareOne.add(Point{x,y});
    squareOne.add(Point{x,y});
    squareOne.add(Point{x,y});
    squareOne.add(Point{x,y});
    rightTriangle.set_fill_color(Color::green);
    */
    Simple_window win{Point{100,100},w,h,"Task 5b) Pythagoras"};
    win.attach(rightTriangle);
    //win.attach(squareOne);
    win.wait_for_button();
}