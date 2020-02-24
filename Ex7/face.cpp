#include "face.h"

using namespace Graph_lib;

// Face: --------------------------------------------------------
Face::Face(Point c, int r) : outline{c, r} {
    outline.set_fill_color(Color::yellow);
}
void Face::attach_to(Graph_lib::Window& win) {
    win.attach(outline);
}

// Empty face: --------------------------------------------------
EmptyFace::EmptyFace(Point c, int r) : Face{c, r}, rEye{{c.x + (r/3),c.y  - (r/5)}, r/10, r/7}, lEye{{c.x  - (r/3),c.y  - (r/5)}, r/10, r/7} {
    rEye.set_fill_color(Color::black);
    rEye.set_color(Color::black);
    lEye.set_fill_color(Color::black);
    lEye.set_color(Color::black);
}
void EmptyFace::attach_to(Graph_lib::Window& win) {
    Face::attach_to(win);
    win.attach(rEye);
    win.attach(lEye);
}

// Smiley face: --------------------------------------------------
Smiley::Smiley(Point c, int r) : EmptyFace{c, r}, mouth{{c.x, c.y + (r/5)}, r, r,180, 360} {
    mouth.set_fill_color(Color::black);
    mouth.set_color(Color::black);
}
void Smiley::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

// Sad face: ------------------------------------------------------
SadFace::SadFace(Point c, int r) : EmptyFace{c, r}, mouth{{c.x, c.y+(r/2)}, r, r, 0, 180} {
    mouth.set_fill_color(Color::black);
    mouth.set_color(Color::black);
}
void SadFace::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

// Surprised face: ------------------------------------------------------
Surprised::Surprised(Point c, int r) : EmptyFace{c, r}, mouth{{c.x, c.y+(r/2)}, r/2, r/4} {
    mouth.set_fill_color(Color::black);
    mouth.set_color(Color::black);
}
void Surprised::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

// Winkey Eye (support-class): ------------------------------------------
WinkyEye::WinkyEye(Point c, int r) : Face{c, r}, 
rEye{{c.x+(r/3), c.y-(r/5)}, r/8, r/7, 0, 180}, 
lEye{{c.x-(r/3), c.y-(r/5)}, r/10, r/7},
rLash{{c.x+(r/3), c.y-(r/3)}, r/3, r/6, 0, 160}, 
lLash{{c.x-(r/3), c.y-(r/3)}, r/2, r/3, 90, 170} 
{
    rEye.set_fill_color(Color::black);
    rEye.set_color(Color::black);
    lEye.set_fill_color(Color::black);
    lEye.set_color(Color::black);
    rLash.set_fill_color(Color::black);
    rLash.set_color(Color::black);
    lLash.set_fill_color(Color::black);
    lLash.set_color(Color::black);
}
void WinkyEye::attach_to(Graph_lib::Window& win) {
    Face::attach_to(win);
    win.attach(rEye);
    win.attach(lEye);
    win.attach(rLash);
    win.attach(lLash);
}

// Winkey Face: ----------------------------------------------------------
WinkyFace::WinkyFace(Point c, int r) : WinkyEye{c, r}, 
mouth{{c.x+(r/6),c.y+(r/3)}, static_cast<int>(r*1.1), static_cast<int>(r/1.6),   220, 380}/*,
dimpl{mouth.point(mouth.number_of_points()-1), r/4,   r/2, 340, 380}*/
{
    mouth.set_fill_color(Color::black);
    mouth.set_color(Color::black);
    //dimpl.set_fill_color(Color::black);
    //dimpl.set_color(Color::black);
}
void WinkyFace::attach_to(Graph_lib::Window& win) {
    WinkyEye::attach_to(win);
    win.attach(mouth);
    //win.attach(dimpl);
}