#include "vex.h"

using namespace vex;
using namespace mik;

task UI;

static int run_UI() {
    UI_init();
    UI_controller_auton_selector();
    UI_render();
    return 0;
}

void pre_auton() {
    init();
    default_constants();
    odom_constants();
    UI = task(run_UI);
}

void auton(void) {
    UI.stop();
    auton_scr->start_auton();
}

void user_control(void) {
    while (calibrating) { task::sleep(50); }

    // How you want your drivetrain to stop during driver
    chassis.set_brake_type(brakeType::coast);
    
    assembly.init();

    while (true) {
        if (!control_disabled()) {
            // Add your user control code here
            chassis.control(drive_mode::SPLIT_ARCADE_CURVED);
            assembly.control();
        }
        task::sleep(5);
    }
}

int main() {
    Competition.autonomous(auton);
    Competition.drivercontrol(user_control);

    pre_auton();
    assembly.wings.open();

    while (true) {
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
        task::sleep(100);
    }
}
