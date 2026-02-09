#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_right_middle(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Red Right Middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    intakecon = 1;
    chassis.drive_to_point(0, 28.5);
    assembly.scraper.toggle();
    chassis.turn_to_point(12, 28.5);
    chassis.drive_distance(20, {.timeout = 1000, .max_voltage = 6});
    chassis.drive_to_point(-12, 29.5);
    chassis.turn_to_point(-20, 29.5, {.angle_offset = 180});
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(1500);
    active = false;
    assembly.scraper.toggle();
    chassis.left_swing_to_point(-26, 9);
    chassis.drive_to_point(-26, 9);
    chassis.turn_to_point(-40, -6.5);
    chassis.drive_to_point(-40, -6.5);
    intakecon = 2;
    task::sleep(1000);
    intakecon = 1;
    chassis.drive_to_point(-15, 18.75);
    chassis.turn_to_point(-30, 18.75, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-20, {.timeout = 700});

    return "";
}