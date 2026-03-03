#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_right_no_middle(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        if (var == one)
        {
            return "Red Right No Middle (Wing)";
        }
        if (var == two)
        {
            return "Red Right No Middle (Hood)";
        }
        if (var == three)
        {
            return "Red Right Goal Rush";
        }
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(-47.3, -14.5, 90);
        return "";
    }

    // Get middle blocks.
    intakecon = 1;
    if (chassis.y_pos_mirrored())
    {
        chassis.drive_to_pose(-20, -24, 110, {.max_voltage = 8, .wait = false});
    }
    else
    {
        chassis.drive_to_pose(-20, -24, 70, {.max_voltage = 8, .wait = false});
    }
    task::sleep(750);
    assembly.scraper.toggle();
    while (chassis.is_in_motion())
    {
        task::sleep(25);
    }
    chassis.turn_to_point(-50, -47.5);
    assembly.scraper.toggle();
    chassis.drive_to_point(-50, -47.5);
    assembly.scraper.toggle();
    chassis.turn_to_point(-60, -47.5);

    // Matchload
    if (var == one || var == two)
    {
        chassis.drive_distance(20, {.timeout = 1000, .max_voltage = 8});
    }

    // Score
    intakecon = 3;
    chassis.drive_to_point(-38, -50.1);
    chassis.turn_to_point(-30, 50.25, {.angle_offset = 180});
    chassis.drive_distance(-12, {.timeout = 750});
    intakecon = 1;
    active = true;
    task::sleep(2250);
    active = false;
    assembly.scraper.toggle();

    if (var == one || var == three)
    { // Use Wing
        chassis.drive_to_point(-40, -50.1);
        chassis.turn_to_point(-40, -58.75);
        chassis.drive_to_point(-40, -58.75);
        chassis.turn_to_point(-50, -58.75);
        assembly.wing.toggle();
        task::sleep(250);
        assembly.wing.toggle();
        chassis.drive_distance(-12, {.timeout = 750});
    }
    else if (var == two)
    { // Use Hood
        chassis.drive_distance(6);
        chassis.drive_distance(-20, {.timeout = 750});
    }

    return "";
}