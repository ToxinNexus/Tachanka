#include "vex.h"
#include "assembly.h"

using namespace vex;

int intakecon;

bool middle;
bool active;

Assembly::Assembly(
    mik::motor top,
    mik::motor bottom,
    mik::piston wing,
    mik::piston scraper,
    mik::piston park,
    mik::piston trapdoor,
    mik::piston transmission,
    vex::optical leftscraper,
    vex::distance rightscraper

    ) : // Assign the ports to the devices
        top(top),
        bottom(bottom),
        wing(wing),
        scraper(scraper),
        park(park),
        trapdoor(trapdoor),
        transmission(transmission),
        leftscraper(leftscraper),
        rightscraper(rightscraper) {};

// You want to call this function once in the user control function in main.
void Assembly::init()
{
}

// You want to put this function inside the user control loop in main.
void Assembly::control()
{
    flow_control();
    intake_control();
    wing_control();
    scraper_control();
    park_control();
    transmission_control();
}

// Flow Control
void Assembly::flow_control()
{
    if (btnDown_new_press(Controller.ButtonDown.pressing()))
    {
        if (middle == false)
        {
            middle = true;
        }
        else
        {
            middle = false;
        }
    }
    if (btnRight_new_press(Controller.ButtonRight.pressing()))
    {
        if (active == false)
        {
            active = true;
        }
        else
        {
            active = false;
        }
    }
}

// Intake Control
void Assembly::intake_control()
{
    if (Controller.ButtonL1.pressing())
    {
        intakecon = 1;
    }
    else if (Controller.ButtonL2.pressing())
    {
        intakecon = 2;
    }
    else
    {
        intakecon = 3;
    }
}

// Wing Control
void Assembly::wing_control()
{
    if (btnY_new_press(Controller.ButtonY.pressing()))
    {
        wing.toggle();
    }
}

// Scraper Control
void Assembly::scraper_control()
{
    if (btnB_new_press(Controller.ButtonB.pressing()))
    {
        scraper.toggle();
    }
}

// Park Control
void Assembly::park_control()
{
    if (btnR2_new_press(Controller.ButtonR2.pressing()))
    {
        park.toggle();
    }
}

// Transmission Control
void Assembly::transmission_control()
{
    if (btnR1_new_press(Controller.ButtonR1.pressing()))
    {
        transmission.toggle();
    }
}