#include "vex.h"

using namespace vex;
using namespace mik;

void default_constants(void) {
    chassis.set_control_constants(5, 10, 1.019, 5, 10, 1.019);

    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_drive_constants(12, 1.050, 0.001, 3.450, 1.000);
	chassis.set_heading_constants(12, 0.100, 0.001, 0.400, 2.500);
	chassis.set_turn_constants(12, 0.280, 0.010, 2.000, 15.000);
	chassis.set_swing_constants(12, 0.300, 0.010, 1.850, 15.000);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_turn_exit_conditions(1, 150, 1000);
    chassis.set_drive_exit_conditions(0.1, 150, 2000);
    chassis.set_swing_exit_conditions(1, 150, 2000);
}

void odom_constants(void) {
    default_constants();
    chassis.heading_max_voltage = 12;
    chassis.drive_max_voltage = 12;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.boomerang_setback = 2;    
}

/*
Checklist - 6/13
Blue Left Middle - Working
Blue Left SAWP - Not Started
Blue Left No Middle - Complete
Blue Right Middle - Complete
Blue Right SAWP - Not Started
Blue Right No Middle - Complete
Red Left Middle - Working
Red Left SAWP - Not Started
Red Left No Middle - Complete
Red Right Middle - Complete
Red Right SAWP - Not Started
Red Right No Middle - Complete
Skills - Not Started
*/


std::string blue_left_middle(bool calibrate, auto_variation var, bool get_name) { // Working
    if (get_name) { return "blue left middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 2;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_left_sawp(bool calibrate, auto_variation var, bool get_name) { // Not Started
    if (get_name) { return "blue left sawp"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 2;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_left_no_middle(bool calibrate, auto_variation var, bool get_name) { // Complete
    if (get_name) { return "blue left no middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 2;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

	intakecon = 1;
    chassis.drive_to_point(0, 13);
    chassis.right_swing_to_point(-23.8, 40);
    chassis.drive_to_point(-23.8, 40, {.max_voltage = 5, .timeout = 3000});
    task::sleep(250);
    chassis.drive_to_point(-12, 24);
    chassis.turn_to_point(-30, 6);
    chassis.drive_to_point(-30, 6);
    assembly.scraper.open();
    chassis.turn_to_point(-30, -24);
    chassis.drive_to_point(-30, -24, {.timeout = 1750, .max_voltage = 6});
    intakecon = 4;
    chassis.drive_to_point(-31.25, 12);
    chassis.turn_to_point(-31.25, 21, {.angle_offset = 180});
    chassis.drive_to_point(-31.25, 21, {.max_voltage = 8});
    assembly.wings.close();
    intakecon = 3;
    task::sleep(250);
    intakecon = 1;
    task::sleep(5000);

    return "";
}
std::string blue_right_middle(bool calibrate, auto_variation var, bool get_name) { // Complete
    if (get_name) { return "blue right middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 2;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 13);
    chassis.left_swing_to_point(10, 30);
    chassis.drive_to_point(10, 30, {.max_voltage = 5});
    task::sleep(250);
    chassis.drive_to_point(10, 20);
    chassis.turn_to_point(-4, 40);
    chassis.drive_to_point(-4, 40, {.timeout = 750});
    assembly.lift.open();
    intakecon = 3;  
    task::sleep(2000);
    intakecon = 1;
    chassis.drive_to_point(10, 20);
    assembly.lift.close();
    chassis.turn_to_point(30.5, 6);
    chassis.drive_to_point(30.5, 6);
    assembly.scraper.open();
    chassis.turn_to_point(30.5, -24);
    chassis.drive_to_point(30.5, -24, {.timeout = 1750, .max_voltage = 6});
    intakecon = 4;
    chassis.drive_to_point(32.5, 12);
    chassis.turn_to_point(32.5, 30, {.angle_offset = 180});
    chassis.drive_to_point(32.5, 30, {.max_voltage = 8, .timeout = 500});
    assembly.wings.close();
    intakecon = 3;
    task::sleep(250);
    intakecon = 1;
    task::sleep(5000);

    return "";
}
std::string blue_right_sawp(bool calibrate, auto_variation var, bool get_name) { // Not Started 
    if (get_name) { return "blue right sawp"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 2;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_right_no_middle(bool calibrate, auto_variation var, bool get_name) { // Complete
    if (get_name) { return "blue right no middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 2;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 13);
    chassis.left_swing_to_point(23.8, 40);
    chassis.drive_to_point(23.8, 40, {.max_voltage = 5, .timeout = 3000});
    task::sleep(250);
    chassis.drive_to_point(12, 24);
    chassis.turn_to_point(30, 6);
    chassis.drive_to_point(30, 6);
    assembly.scraper.open();
    chassis.turn_to_point(30, -24);
    chassis.drive_to_point(30, -24, {.timeout = 1750, .max_voltage = 6});
    intakecon = 4;
    chassis.drive_to_point(31.25, 12);
    chassis.turn_to_point(31.25, 21, {.angle_offset = 180});
    chassis.drive_to_point(31.25, 21, {.max_voltage = 8});
    assembly.wings.close();
    intakecon = 3;
    task::sleep(250);
    intakecon = 1;
    task::sleep(5000);

    return "";
}

std::string red_left_middle(bool calibrate, auto_variation var, bool get_name) { // Working
    if (get_name) { return "red left middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 1;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code
    
    return "";
}
std::string red_left_sawp(bool calibrate, auto_variation var, bool get_name) { // Not Started 
    if (get_name) { return "red left sawp"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 1;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string red_left_no_middle(bool calibrate, auto_variation var, bool get_name) { // Complete  
    if (get_name) { return "red left no middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 1;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 13);
    chassis.right_swing_to_point(-23.8, 40);
    chassis.drive_to_point(-23.8, 40, {.max_voltage = 5, .timeout = 3000});
    task::sleep(250);
    chassis.drive_to_point(-12, 24);
    chassis.turn_to_point(-30, 6);
    chassis.drive_to_point(-30, 6);
    assembly.scraper.open();
    chassis.turn_to_point(-30, -24);
    chassis.drive_to_point(-30, -24, {.timeout = 1750, .max_voltage = 6});
    intakecon = 4;
    chassis.drive_to_point(-31.25, 12);
    chassis.turn_to_point(-31.25, 21, {.angle_offset = 180});
    chassis.drive_to_point(-31.25, 21, {.max_voltage = 8});
    assembly.wings.close();
    intakecon = 3;
    task::sleep(250);
    intakecon = 1;
    task::sleep(5000);
    
    return "";
}
std::string red_right_middle(bool calibrate, auto_variation var, bool get_name) { // Complete  
    if (get_name) { return "red right middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 1;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 13);
    chassis.left_swing_to_point(10, 30);
    chassis.drive_to_point(10, 30, {.max_voltage = 5});
    task::sleep(250);
    chassis.drive_to_point(10, 20);
    chassis.turn_to_point(-4, 40);
    chassis.drive_to_point(-4, 40, {.timeout = 750});
    assembly.lift.open();
    intakecon = 3;  
    task::sleep(2000);
    intakecon = 1;
    chassis.drive_to_point(10, 20);
    assembly.lift.close();
    chassis.turn_to_point(30.5, 6);
    chassis.drive_to_point(30.5, 6);
    assembly.scraper.open();
    chassis.turn_to_point(30.5, -24);
    chassis.drive_to_point(30.5, -24, {.timeout = 1750, .max_voltage = 6});
    intakecon = 4;
    chassis.drive_to_point(32.5, 12);
    chassis.turn_to_point(32.5, 30, {.angle_offset = 180});
    chassis.drive_to_point(32.5, 30, {.max_voltage = 8, .timeout = 500});
    assembly.wings.close();
    intakecon = 3;
    task::sleep(250);
    intakecon = 1;
    task::sleep(5000);

    return "";
}
std::string red_right_sawp(bool calibrate, auto_variation var, bool get_name) { // Not Started
    if (get_name) { return "red right sawp"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 1;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 28);
    assembly.scraper.open();
    chassis.turn_to_point(24, 29);
    chassis.drive_to_point(24, 29, {.timeout = 1250, .max_voltage = 8});
    chassis.drive_to_point(-12, 31);
    chassis.turn_to_point(-30, 31, {.angle_offset = 180});
    chassis.drive_to_point(-30, 31, {.max_voltage = 8, .timeout = 1000});
    assembly.wings.close();
    task::sleep(1000);
    chassis.drive_to_point(-12, 32);

    return "";
}
std::string red_right_no_middle(bool calibrate, auto_variation var, bool get_name) { // Complete   
    if (get_name) { return "red right no middle"; }
    if (calibrate) {
        UseSort = true;
        tcolor = 1;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 13);
    chassis.left_swing_to_point(23.8, 40);
    chassis.drive_to_point(23.8, 40, {.max_voltage = 5, .timeout = 3000});
    task::sleep(250);
    chassis.drive_to_point(12, 24);
    chassis.turn_to_point(30, 6);
    chassis.drive_to_point(30, 6);
    assembly.scraper.open();
    chassis.turn_to_point(30, -24);
    chassis.drive_to_point(30, -24, {.timeout = 1750, .max_voltage = 6});
    intakecon = 4;
    chassis.drive_to_point(31.25, 12);
    chassis.turn_to_point(31.25, 21, {.angle_offset = 180});
    chassis.drive_to_point(31.25, 21, {.max_voltage = 8});
    assembly.wings.close();
    intakecon = 3;
    task::sleep(250);
    intakecon = 1;
    task::sleep(5000);

    return "";
}
std::string skills(bool calibrate, auto_variation var, bool get_name) { // Not Started   
    if (get_name) { return "skills"; }
    if (calibrate) {
        UseSort = false;
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}