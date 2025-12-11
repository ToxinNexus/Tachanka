#pragma once

#include "vex.h"

using namespace vex;

extern int intakecon;
extern int flow;
extern int tcolor;

extern bool UseSort;

class Assembly {
public:
    Assembly(
        mik::motor intake,
        mik::motor low_center,
        mik::motor high_center,
        mik::motor score,
        mik::piston wings,
        mik::piston scraper,
        mik::piston park, 
        mik::piston lift,
        vex::optical sorter
    );

    void init();
    void control();

    void flow_control();
    void intake_control();
    void wings_control();
    void scraper_control();
    void park_control();
    void lift_control();
    
    mik::motor intake;
    mik::motor low_center;
    mik::motor high_center;
    mik::motor score;
    mik::piston wings;
    mik::piston scraper;
    mik::piston park;
    mik::piston lift;
    vex::optical sorter;
};