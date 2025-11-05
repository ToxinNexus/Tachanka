#include "vex.h"
#include "assembly.h"

using namespace vex;

int intakecon = 1;
int flow = 1;

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
    flow_control();
    intake_control();
    wings_control();
    scraper_control();
    park_control();
}

// Flow Control
void Assembly::flow_control() {
    if (Controller.ButtonRight.pressing()) {
        flow = 1;
    } else if (Controller.ButtonDown.pressing()) {
        flow = 2;
    }
    if (intakecon == 1) {
        // Top
        assembly.intake.spin(fwd, 12, volt);
        assembly.low_center.spin(fwd, 12, volt);
        assembly.high_center.spin(fwd, 12, volt);
        assembly.score.spin(fwd, 12, volt);
    } else if (intakecon == 2) {
        // Middle
        assembly.intake.spin(fwd, 12, volt);
        assembly.low_center.spin(fwd, 12, volt);
        assembly.high_center.spin(fwd, 12, volt);
        assembly.score.spin(reverse, 3, volt);
    } else if (intakecon == 3) {
        // Bottom
        assembly.intake.spin(reverse, 12, volt);
        assembly.low_center.spin(reverse, 12, volt);
        assembly.high_center.spin(reverse, 12, volt);
        assembly.score.spin(reverse, 12, volt);
    } else if (intakecon == 4) {
        // Stopped
        assembly.intake.stop();
        assembly.low_center.stop();
        assembly.high_center.stop();
        assembly.score.stop();
    }
}

// Controls Intake
void Assembly::intake_control() {
    if (Controller.ButtonL1.pressing()) {
        if (flow == 1) {
            intakecon = 1;
        } else {
            intakecon = 2;
        }
    } else if (Controller.ButtonL2.pressing()) {
        intakecon = 3;
    } else {
        intakecon = 4;
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