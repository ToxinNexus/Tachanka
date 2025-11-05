#include "vex.h"

using namespace vex;
using namespace mik;

void default_constants(void) {
    chassis.set_control_constants(5, 10, 1.019, 5, 10, 1.019);

    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_drive_constants(7.5, 1.8, 0.2, 11.5, 0.5);
	chassis.set_heading_constants(12, 0.17, 0.02, 1.35, 2.5);
	chassis.set_turn_constants(12, 0.16, 0.01, 0.95, 15);
	chassis.set_swing_constants(12, 0.16, 0.01, 0.95, 15);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_turn_exit_conditions(1.5, 250, 2000);
    chassis.set_drive_exit_conditions(1, 250, 3000);
    chassis.set_swing_exit_conditions(1.25, 250, 3000);
}

void odom_constants(void) {
    default_constants();
    chassis.heading_max_voltage = 10;
    chassis.drive_max_voltage = 8;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.boomerang_setback = 2;    
}

std::string template_auto(bool calibrate, auto_variation var, bool get_name) {
    /* The first variation will be this auto */
    if (var == one) {}

    /* We declare and allow a second variation of this auto; 
    You may want this if you want a different movements in the same starting configuration */
    if (var == two) { return template_auto_other_variation(calibrate, get_name); }

    if (get_name) { /* Give a desciption of your auto */ return "template auto 1 (3 objs)"; }
    if (calibrate) {
        /* Initialize robots starting position "https://path.jerryio.com/" and/or add extra movements to line up robots 
        starting position **IF MOVING DURING CALIBRATION DO BEFORE FIELD CONTROLLER PLUG IN** */
        chassis.set_coordinates(55, 23.5, 90);
    
        /* Example of turning before auto is ran */
        chassis.turn_max_voltage = 6; 
        chassis.turn_to_angle(45);

        return "";
    }
    
    /* We now run the auto */ 
    assembly.intake.spin(fwd);
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(15, 40);
    chassis.turn_to_angle(135);
    chassis.drive_to_point(31.5, 18);
    chassis.turn_to_angle(180);
    chassis.drive_to_point(31.5, 4, {.max_voltage = 6}); 
    chassis.drive_to_point(32.75, 31.5, {.max_voltage = 8});

    return "";
}
std::string template_auto_other_variation(bool calibrate, bool get_name) {
    if (get_name) { return "template auto 2 (4 objs)"; }
    
    // Mirror template_auto() from the x-axis
    chassis.mirror_all_auton_y_pos();
    
    if (calibrate) {
        // Coordinates will be set to (55, -23.5) as y_pos is mirrored
        template_auto(calibrate, one, get_name);
        return "";
    }
    
    // Run auto, make sure to pass in one as var.
    template_auto(calibrate, one, get_name);

    return "";
}


std::string blue_left_middle(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "blue left middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    assembly.intake.spin(fwd);
    chassis.drive_to_point(0, 30);
    chassis.drive_to_point(15, 40);
    chassis.turn_to_angle(135);
    chassis.drive_to_point(31.5, 18);
    chassis.turn_to_angle(180);
    chassis.drive_to_point(31.5, 4, {.max_voltage = 6}); 
    chassis.drive_to_point(32.75, 31.5, {.max_voltage = 8});

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
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

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
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}

std::string red_left_middle(bool calibrate, auto_variation var, bool get_name) { 
    if (get_name) { return "red left middle"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }
    
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
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}

std::string skills(bool calibrate, auto_variation var, bool get_name) {
    if (get_name) { return "skills"; }
    if (calibrate) {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}