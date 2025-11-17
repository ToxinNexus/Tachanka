#include "vex.h"

using namespace vex;
using namespace mik;

void default_constants(void) {
    chassis.set_control_constants(5, 10, 1.019, 5, 10, 1.019);

    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_drive_constants(12, 1, 0.3, 10, 1);
	chassis.set_heading_constants(12, 0.17, 0.02, 1.35, 2.5);
	chassis.set_turn_constants(12, 0.16, 0.01, 0.95, 15);
	chassis.set_swing_constants(12, 0.16, 0.01, 0.95, 15);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_turn_exit_conditions(1.5, 150, 1000);
    chassis.set_drive_exit_conditions(1, 150, 2000);
    chassis.set_swing_exit_conditions(1.25, 150, 2000);
}

void odom_constants(void) {
    default_constants();
    chassis.heading_max_voltage = 12;
    chassis.drive_max_voltage = 12;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.boomerang_setback = 2;    
}

std::string blue_left_middle(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "blue left middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(-10, 40, {.max_voltage = 3});
    chassis.drive_to_point(-5, 35);
    chassis.turn_to_point(5, 52, {.angle_offset = 180});
    chassis.drive_to_point(5, 52);
    intakecon = 2;
    task::sleep(750);
    intakecon = 1;
    chassis.turn_to_point(-33, 18);
    chassis.drive_to_point(-33, 18);
    assembly.scraper.open();
    chassis.turn_to_angle(180);
    chassis.drive_to_point(-33, 1, {.max_voltage = 4, .timeout = 1500});
    chassis.drive_to_point(-34, 18);
    chassis.turn_to_point(-34, 35, {.angle_offset = 180});
    chassis.drive_to_point(-34, 35, {.max_voltage = 6, .timeout = 1000});
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);

    return "";
}
std::string blue_left_sawp(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "blue left sawp"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}
std::string blue_left_no_middle(bool calibrate, auto_variation var, bool get_name) {   
    if (get_name) { return "blue left no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

	chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(-10, 40, {.max_voltage = 3});
    chassis.turn_to_point(-30.75, 18);
    chassis.drive_to_point(-30.75, 18);
    assembly.scraper.open();
    chassis.turn_to_angle(180);
    chassis.drive_to_point(-30.75, 1, {.max_voltage = 4, .timeout = 4000});
    task::sleep(1000);
    chassis.drive_to_point(-31.75, 18);
    chassis.turn_to_point(-31.75, 35, {.angle_offset = 180});
    chassis.drive_to_point(-31.75, 35, {.max_voltage = 6});
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);

    return "";
}
std::string blue_right_middle(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "blue right middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}
std::string blue_right_sawp(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "blue right sawp"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}
std::string blue_right_no_middle(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "blue right no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(10, 40, {.max_voltage = 3});
    chassis.turn_to_point(31.25, 18);
    chassis.drive_to_point(31.25, 18);
    assembly.scraper.open();
    chassis.turn_to_angle(180);
    chassis.drive_to_point(31.25, 1, {.max_voltage = 3, .timeout = 2000});
    chassis.drive_to_point(31.75, 18);
    chassis.turn_to_point(31.75, 35, {.angle_offset = 180});
    chassis.drive_to_point(31.75, 35, {.max_voltage = 6});
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);

    return "";
}

std::string red_left_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(-10, 40, {.max_voltage = 3});
    chassis.drive_to_point(-5, 35);
    chassis.turn_to_point(5, 52, {.angle_offset = 180});
    chassis.drive_to_point(5, 52);
    intakecon = 2;
    task::sleep(750);
    intakecon = 1;
    chassis.turn_to_point(-33, 18);
    chassis.drive_to_point(-33, 18);
    assembly.scraper.open();
    chassis.turn_to_angle(180);
    chassis.drive_to_point(-33, 1, {.max_voltage = 4, .timeout = 1500});
    chassis.drive_to_point(-34, 18);
    chassis.turn_to_point(-34, 35, {.angle_offset = 180});
    chassis.drive_to_point(-34, 35, {.max_voltage = 6, .timeout = 1000});
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);
    
    return "";
}
std::string red_left_sawp(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left sawp"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}
std::string red_left_no_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left no middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);
        
        return "";
    }
    
	chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(-10, 40, {.max_voltage = 3});
    chassis.turn_to_point(-30.75, 18);
    chassis.drive_to_point(-30.75, 18);
    assembly.scraper.open();
    chassis.turn_to_angle(180);
    chassis.drive_to_point(-30.75, 1, {.max_voltage = 4, .timeout = 4000});
    task::sleep(1000);
    chassis.drive_to_point(-31.75, 18);
    chassis.turn_to_point(-31.75, 35, {.angle_offset = 180});
    chassis.drive_to_point(-31.75, 35, {.max_voltage = 6});
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);
    
    return "";
}
std::string red_right_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red right middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);
        
        return "";
    }

    return "";
}
std::string red_right_sawp(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "red right sawp"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);
        
        return "";
    }

    return "";
}
std::string red_right_no_middle(bool calibrate, auto_variation var, bool get_name) {   
    if (get_name) { return "red right no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(10, 40, {.max_voltage = 3});
    chassis.turn_to_point(31.25, 18);
    chassis.drive_to_point(31.25, 18);
    assembly.scraper.open();
    chassis.turn_to_angle(180);
    chassis.drive_to_point(31.25, 1, {.max_voltage = 3, .timeout = 2000});
    chassis.drive_to_point(31.75, 18);
    chassis.turn_to_point(31.75, 35, {.angle_offset = 180});
    chassis.drive_to_point(31.75, 35, {.max_voltage = 6});
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);

    return "";
}

std::string skills(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "skills"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    intakecon = 1;
    chassis.drive_to_point(0, 20);
    chassis.turn_to_point(30.85, 20);
    chassis.drive_to_point(30.85, 20);
    assembly.scraper.open();
    chassis.turn_to_point(30.85, 0);
    chassis.drive_to_point(30.85, 0, {.max_voltage = 4, .timeout = 4000});
    task::sleep(1000);
    chassis.drive_to_point(31.25, 20);
    chassis.turn_to_point(31.25, 35, {.angle_offset = 180});
    chassis.drive_to_point(31.25, 35);
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);
    intakecon = 3;
    task::sleep(1000);
    intakecon = 1;
    chassis.drive_to_point(31.75, 20);
    assembly.wings.open();
    assembly.scraper.close();
    chassis.turn_to_point(0, 40);
    chassis.drive_to_point(0, 40, {.max_voltage = 6, .timeout = 5000});
    task::sleep(1000);
    chassis.right_swing_to_point(30, 20, {.turn_direction = ccw, .timeout = 5000, .max_voltage = 6});
    chassis.drive_to_point(31.75, 20);
    chassis.turn_to_point(31.75, 35, {.angle_offset = 180});
    chassis.drive_to_point(31.75, 35);
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    assembly.scraper.close();
    intakecon = 1;
    task::sleep(5000);
    chassis.drive_to_point(30, 20);
    assembly.wings.open();
    chassis.turn_to_point(-62.5, 20);
    chassis.drive_to_point(-62.5, 20, {.timeout = 5000});
    assembly.scraper.open();
    chassis.turn_to_point(-62.5, 0);
    chassis.drive_to_point(-62.5, 0, {.max_voltage = 4, .timeout = 4000});
    task::sleep(1000);
    chassis.drive_to_point(-63.5, 20);
    chassis.turn_to_point(-63.5, 35, {.angle_offset = 180});
    chassis.drive_to_point(-63.5, 35);
    intakecon = 4;
    task::sleep(500);
    assembly.wings.close();
    intakecon = 1;
    task::sleep(5000);
    intakecon = 3;
    task::sleep(1000);
    intakecon = 1;
    chassis.drive_to_point(-62, 20);
    assembly.wings.open();
    assembly.scraper.close();
    chassis.turn_to_point(-16, 20);
    chassis.drive_to_point(-16, 20);
    chassis.turn_to_angle(0);
    chassis.drive_to_point(-15, 0, {.max_voltage = 9});

    return "";
}