#include <iostream>
#include "../head/task5.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;


void pythagoras(void) {
    int w = 100;
    int h = 100;
    Simple_window win{Point{100,100},w,h,"Pythagoras"};

    win.wait_for_button();
}