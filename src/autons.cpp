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
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string blue_left_sawp(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "blue left sawp"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string blue_left_no_middle(bool calibrate, auto_variation var, bool get_name) {   
    if (get_name) { return "blue left no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

	chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string blue_right_middle(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "blue right middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string blue_right_sawp(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "blue right sawp"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string blue_right_no_middle(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "blue right no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}

std::string red_left_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);
    
    return "";
}
std::string red_left_sawp(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left sawp"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string red_left_no_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }
    
	chassis.set_coordinates(0, 0, 0);
    
    return "";
}
std::string red_right_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red right middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string red_right_sawp(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "red right sawp"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string red_right_no_middle(bool calibrate, auto_variation var, bool get_name) {   
    if (get_name) { return "red right no middle"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}
std::string skills(bool calibrate, auto_variation var, bool get_name) {   
    if (get_name) { return "skills"; }
    if (calibrate) {
        odom_constants();
        return "";
    }

    chassis.set_coordinates(0, 0, 0);

    return "";
}