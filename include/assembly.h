#pragma once

#include "vex.h"

using namespace vex;

extern int intake = 1;

class Assembly {
public:
    Assembly(
        mik::motor intake,
        mik::motor low_center,
        mik::motor high_center,
        mik::motor score,
        mik::piston wings,
        mik::piston scraper,
        mik::piston park
    );

    void init();
    void control();

    void intake_control();
    void wings_control();
    void scraper_control();
    void park_control();

    bool middle = false;
    
    mik::motor intake;
    mik::motor low_center;
    mik::motor high_center;
    mik::motor score;
    mik::piston wings;
    mik::piston scraper;
    mik::piston park;
};