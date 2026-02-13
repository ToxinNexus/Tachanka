#include "vex.h"

using namespace vex;
using namespace mik;

std::string skills(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Skills";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    intakecon = 1;
    chassis.set_coordinates(51.5, 16.93, 0);
    chassis.drive_to_point(51.5, 45.2);
    assembly.scraper.toggle();
    chassis.turn_to_point(61.5, 46.2);
    chassis.drive_to_point(61.5, 46.2, {.timeout = 2000});
    chassis.drive_to_point(27.39, 59, {.settle_error = 5, .settle_time = 100, .min_voltage = 5});
    assembly.scraper.toggle();
    chassis.drive_to_point(-23.93, 59, {.settle_error = 5, .settle_time = 100, .min_voltage = 5});
    chassis.drive_to_point(-41.82, 47.48, {.settle_error = 5, .settle_time = 100, .min_voltage = 5});
    chassis.turn_to_point(-28.01, 47.48, {.angle_offset = 180});
    chassis.drive_distance(-24, {.timeout = 750});
    active = true;
    task::sleep(2000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(-60.09, 45.04, {.timeout = 2500});
    chassis.drive_to_point(-41.66, 47.33);
    chassis.turn_to_point(-27.85, 47.39, {.angle_offset = 180});
    chassis.drive_distance(-24, {.timeout = 750});
    active = true;
    task::sleep(2000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(-41.86, 45.2);
    chassis.turn_to_point(-43.3, -47.39);
    chassis.drive_to_point(-43.3, -47.39);
    assembly.scraper.toggle();
    chassis.turn_to_point(-60.24, -47.52);
    chassis.turn_to_point(-60.24, -47.52);
    chassis.drive_to_point(-60.24, -47.52, {.timeout = 2000});
    chassis.drive_to_point(-27.39, -60, {.settle_error = 5, .settle_time = 100, .min_voltage = 4});
    assembly.scraper.toggle();
    chassis.drive_to_point(23.93, -60, {.settle_error = 5, .settle_time = 100, .min_voltage = 4});
    chassis.drive_to_point(41.98, -47.72, {.settle_error = 5, .settle_time = 100, .min_voltage = 4});
    chassis.turn_to_point(29.24, -47.48, {.angle_offset = 180});
    chassis.drive_distance(-24, {.timeout = 750});
    active = true;
    task::sleep(2000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(61.95, -47.49, {.timeout = 2500});
    chassis.drive_to_point(42.14, -47.88);
    chassis.turn_to_point(29.37, -47.49, {.angle_offset = 180});
    chassis.drive_distance(-24, {.timeout = 750});
    active = true;
    task::sleep(2000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(44.17, -47.86);
    chassis.turn_to_point(63.63, -16.1, {.angle_offset = 180});
    chassis.drive_to_pose(63.63, -16.1, 180);

    return "";
}