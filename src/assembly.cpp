#include "vex.h"
#include "assembly.h"

using namespace vex;
    int intake = 1;
Assembly::Assembly(
    mik::motor intake,
    mik::motor low_center,
    mik::motor high_center,
    mik::motor score,
    mik::piston wings,
    mik::piston scraper,
    mik::piston park
) :
    // Assign the ports to the devices
    intake(intake),
    low_center(low_center),
    high_center(high_center),
    score(score),
    wings(wings),
    scraper(scraper),
    park(park)
{};

// You want to call this function once in the user control function in main.
void Assembly::init() {

} 

// You want to put this function inside the user control loop in main.
void Assembly::control() {
    intake_control();
    wings_control();
    scraper_control();
    park_control();
}

// Controls Intake
void Assembly::intake_control() {
    if (Controller.ButtonL1.pressing()) {
        if (middle == false) {
            intake.spin(fwd, 12, volt);
            low_center.spin(fwd, 12, volt);
            high_center.spin(fwd, 12, volt);
            score.spin(fwd, 12, volt);
        } else {
            intake.spin(fwd, 12, volt);
            low_center.spin(fwd, 12, volt);
            high_center.spin(fwd, 12, volt);
            score.spin(fwd, 6, volt);
        }
    } else if (Controller.ButtonL2.pressing()) {
        intake.spin(fwd, -12, volt);
        low_center.spin(fwd, -12, volt);
        high_center.spin(fwd, -12, volt);
        score.spin(fwd, -12, volt);
    } else {
        intake.stop();
        low_center.stop();
        high_center.stop();
        score.stop();
    }
}


// Controls Wings
void Assembly::wings_control() {
    if (btnY_new_press(Controller.ButtonY.pressing())) {
        wings.toggle();
    }
}
// Controls Scraper
void Assembly::scraper_control() {
    if (btnB_new_press(Controller.ButtonB.pressing())) {
        scraper.toggle();
    }
}

// Controls Park
void Assembly::park_control() {
    if (btnX_new_press(Controller.ButtonX.pressing())) {
        park.toggle();
    }
}