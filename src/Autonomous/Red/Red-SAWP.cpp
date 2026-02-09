#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_sawp(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Red SAWP";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(46.87, 8, 180);

        return "";
    }
    intakecon = 1;
    chassis.drive_to_point(46.87, -3.5);
    chassis.drive_to_point(46.87, 46);
    assembly.scraper.toggle();
    chassis.turn_to_point(58.16, 46);
    chassis.drive_to_point(58.16, 46);
    task::sleep(750);
    chassis.drive_to_point(28.94, 46.36);
    active = true;
    task::sleep(750);
    chassis.turn_to_point(22.89, 20.89);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(22.89, 20.89);
    chassis.drive_to_point(22.69, -23.09);
    chassis.turn_to_point(10.77, -11.36, {.angle_offset = 180});
    chassis.drive_to_point(10.77, -11.36);
    chassis.drive_to_point(44, -47.61);
    chassis.turn_to_point(28.94, -47.61, {.angle_offset = 180});
    chassis.drive_to_point(28.94, -47.61);

    return "";
}