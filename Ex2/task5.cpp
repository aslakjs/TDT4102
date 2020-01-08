#include <iostream>
#include "math.h"
//#include "../head/task5.h"
#include "task5.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;


void pythagoras(void) {
    int w = 1000;
    int h = 1000;
    int tx = 450;   // Top x-value
    int ty = 400;   // Top y-value
    int lx = 450;   // TBL x-value
    int ly = 650;   // TBL y-value
    int rx = 550;   // TBR x-value
    int ry = 650;   // TBR y-value
    Simple_window win{Point{100,100},w,h,"Task 5b) Pythagoras"};
    Polygon rightTriangle;
    Polygon squareOne;      // Bottom
    Polygon squareTwo;      // Left
    Polygon squareThr;      // Right
    
    // Triangle setup:
    rightTriangle.add(Point{tx,ty});  //top
    rightTriangle.add(Point{lx,ly});  //left
    rightTriangle.add(Point{rx,ry});  //right
    rightTriangle.set_fill_color(Color::black);
    win.attach(rightTriangle);

    // Bottom square setup:
    squareOne.add(Point{lx,ly+1});            // TL   
    squareOne.add(Point{lx,ly+(rx-lx)+1});    // BL
    squareOne.add(Point{rx,ry+(rx-lx)+1});    // BR
    squareOne.add(Point{rx,ry+1});            // TR 
    squareOne.set_fill_color(Color::red);
    win.attach(squareOne);
    
    // left square setup:
    squareTwo.add(Point{tx-(ly-ty)-1,ty});    // TL
    squareTwo.add(Point{lx-(ly-ty)-1,ly});    // BL
    squareTwo.add(Point{lx-1,ly});            // BR
    squareTwo.add(Point{tx-1,ty});            // TR
    squareTwo.set_fill_color(Color::green);
    win.attach(squareTwo);
    
    // Right square setup:
    int triHyp = getHyp((ly-ty),(rx-lx));       // Hypotenus for triangle
    int thrHyp = getHyp(triHyp, triHyp);        // Diagonal for square three
    int TRx = round(thrHyp/2);
    squareThr.add(Point{tx+1,ty});              // TL
    squareThr.add(Point{rx+1,ry});              // BL
    squareThr.add(Point{(rx+TRx),(ly-(TRx/2))});    // BR
    squareThr.add(Point{(tx+TRx),(ty-(TRx/2))});    // TR
    squareThr.set_fill_color(Color::blue);
    win.attach(squareThr);
    //
    //
    //
    win.wait_for_button();
}

int getHyp(double x, double y) {
    return round(sqrt(pow(x,2) + pow(y,2)));
}
int getKat(double hyp, double kat1) {
    return round(sqrt(pow(hyp,2) - (pow(kat1,2))));
}