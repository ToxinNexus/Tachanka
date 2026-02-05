#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_left_no_middle_hood(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Blue Left No Middle (Hood)";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    intakecon = 1;
    chassis.drive_to_pose(-7, 27, 350);
    chassis.turn_to_point(-31.5, 4);
    chassis.drive_to_point(-31.5, 4);
    assembly.scraper.toggle();
    chassis.turn_to_point(-31.5, -7);
    chassis.drive_distance(20, {.timeout = 1250, .max_voltage = 6});
    chassis.drive_to_point(-32.5, 10);
    chassis.turn_to_point(-32.5, -20);
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(3000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(-32, 12);
    chassis.drive_distance(-12, {.timeout = 500, .min_voltage = 12, .max_voltage = 12});

    return "";
}