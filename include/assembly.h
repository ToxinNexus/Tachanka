#pragma once

#include "vex.h"

using namespace vex;

extern int intakecon;

extern bool middle;
extern bool active;

class Assembly
{
public:
    Assembly(
        mik::motor top,
        mik::motor bottom,
        mik::piston wing,
        mik::piston scraper,
        mik::piston park,
        mik::piston trapdoor,
        mik::piston transmission,
        vex::optical leftscraper,
        vex::distance rightscraper);

    void init();
    void control();

    void flow_control();
    void intake_control();
    void wing_control();
    void scraper_control();
    void park_control();
    void transmission_control();

    mik::motor top;
    mik::motor bottom;
    mik::piston wing;
    mik::piston scraper;
    mik::piston park;
    mik::piston trapdoor;
    mik::piston transmission;
    vex::optical leftscraper;
    vex::distance rightscraper;
};