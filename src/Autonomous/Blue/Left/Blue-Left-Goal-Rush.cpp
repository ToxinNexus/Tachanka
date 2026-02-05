#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_left_goal_rush(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Blue Left Goal Rush";
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
    chassis.turn_to_point(-32.5, -20);
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(3000);
    active = false;
    chassis.drive_to_point(-32, 12);
    chassis.turn_to_point(-41.3, 12);
    chassis.drive_to_point(-41.3, 12);
    chassis.turn_to_point(-41.3, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}