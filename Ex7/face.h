#ifndef FACE_H
#define FACE_H

#include "Emoji.h"

class Face : public Emoji {
protected:
    Circle outline;
public:
    Face(Point c, int r);
    virtual void attach_to(Graph_lib::Window&) = 0;
    virtual ~Face() {};
};


class EmptyFace : public Face {
protected:
    Ellipse rEye;
    Ellipse lEye;
public:
    EmptyFace(Point c, int r);
    void attach_to(Graph_lib::Window&);
    ~EmptyFace() {};
};

class Smiley : public EmptyFace {
protected:
    Arc mouth;
public:
    Smiley(Point c, int r);
    void attach_to(Graph_lib::Window&);
    ~Smiley() {};
};

class SadFace : public EmptyFace {
protected:
    Arc mouth;
public:
    SadFace(Point c, int r);
    void attach_to(Graph_lib::Window&);
    ~SadFace() {};
};

class Surprised : public EmptyFace {
protected:
    Ellipse mouth;
public:
    Surprised(Point c, int r);
    void attach_to(Graph_lib::Window&);
    ~Surprised() {};
};

class WinkyEye : public Face {
protected:
    Arc rEye;
    Ellipse lEye;
    Arc rLash;
    Arc lLash;
public:
    WinkyEye(Point c, int r);
    void attach_to(Graph_lib::Window&);
    ~WinkyEye() {};
};

class WinkyFace : public WinkyEye {
protected:
    Arc mouth;
    //Arc dimpl;
public:
    WinkyFace(Point c, int r);
    void attach_to(Graph_lib::Window&);
    ~WinkyFace() {};
};

#endif /* FACE_H */