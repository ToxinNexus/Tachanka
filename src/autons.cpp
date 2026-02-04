#include "vex.h"

using namespace vex;
using namespace mik;

void default_constants(void)
{
    chassis.set_control_constants(5, 10, 1.019, 5, 10, 1.019);

    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_turn_constants(12, .437, .0215, 3.383, 15);
    chassis.set_drive_constants(10, 1.5, 0, 10, 0);
    chassis.set_heading_constants(3, .4, 0, 1, 0);
    chassis.set_swing_constants(12, .437, .0295, 3.483, 15);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_turn_exit_conditions(1.5, 200, 2000);
    chassis.set_drive_exit_conditions(0.5, 200, 3000);
    chassis.set_swing_exit_conditions(1.25, 200, 3000);
}

void odom_constants(void)
{
    default_constants();
    chassis.heading_max_voltage = 10;
    chassis.drive_max_voltage = 8;
    chassis.drive_settle_error = 2;
    chassis.boomerang_lead = .5;
    chassis.boomerang_setback = 2;
}

/*
Checklist - 3/13
Blue Left Middle - Not Started
Blue Left SAWP - Not Started
Blue Left No Middle - Not Started
Blue Right Middle - Not Started
Blue Right SAWP - Not Started
Blue Right No Middle - Not Started
Red Left Middle - Not Started
Red Left SAWP - Not Started
Red Left No Middle - Not Started
Red Right Middle - Not Started
Red Right SAWP - Not Started
Red Right No Middle - Not Started
Skills - Not Started
*/

std::string blue_left_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "blue left middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_left_sawp(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "blue left sawp";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_left_no_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "blue left no middle";
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
    chassis.turn_to_point(-41.3, 12);
    chassis.drive_to_point(-41.3, 12);
    chassis.turn_to_point(-41.3, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string blue_left_goal_rush(bool calibrate, auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "blue left no middle";
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
    chassis.turn_to_point(-41.3, 12);
    chassis.drive_to_point(-41.3, 12);
    chassis.turn_to_point(-41.3, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string blue_right_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "blue right middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_right_sawp(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "blue right sawp";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string blue_right_no_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "blue right no middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_pose(7, 27, 10);
    chassis.turn_to_point(31.5, 4);
    chassis.drive_to_point(31.5, 4);
    assembly.scraper.toggle();
    chassis.turn_to_point(31.5, -7);
    chassis.drive_distance(20, {.timeout = 1250, .max_voltage = 6});
    chassis.drive_to_point(32.5, 10);
    chassis.turn_to_point(32.5, -20);
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(3000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(32, 12);
    chassis.turn_to_point(22.7, 12);
    chassis.drive_to_point(22.7, 12);
    chassis.turn_to_point(22.7, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string blue_right_goal_rush(bool calibrate, auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "blue right goal rush";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_pose(7, 27, 10);
    chassis.turn_to_point(31.5, 4);
    chassis.drive_to_point(31.5, 4);
    assembly.scraper.toggle();
    chassis.turn_to_point(31.5, -7);
    chassis.drive_distance(20, {.timeout = 1250, .max_voltage = 6});
    chassis.drive_to_point(32.5, 10);
    chassis.turn_to_point(32.5, -20);
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(3000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(32, 12);
    chassis.turn_to_point(22.7, 12);
    chassis.drive_to_point(22.7, 12);
    chassis.turn_to_point(22.7, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string red_left_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "red left middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string red_left_sawp(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "red left sawp";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string red_left_no_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (var == one)
    {
    }
    if (var == two)
    {
        return red_left_goal_rush(calibrate, var, get_name);
    }
    if (get_name)
    {
        return "red left no middle";
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
    chassis.turn_to_point(-41.3, 12);
    chassis.drive_to_point(-41.3, 12);
    chassis.turn_to_point(-41.3, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string red_left_goal_rush(bool calibrate, auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "red left goal rush";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_pose(-8, 28, 350, {.wait = false});
    chassis.wait_until(30);
    assembly.scraper.toggle();
    chassis.wait();
    chassis.turn_to_point(-32.5, 6);
    chassis.drive_to_point(-32.5, 6);
    chassis.turn_to_point(-32.5, -20);
    chassis.drive_distance(-16, {.timeout = 1250});
    active = true;
    task::sleep(1500);
    active = false;
    chassis.drive_to_point(-32, 12);
    chassis.turn_to_point(-41.2, 12);
    chassis.drive_to_point(-41.2, 12);
    chassis.turn_to_point(-41.2, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string red_right_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "red right middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string red_right_sawp(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "red right sawp";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}
std::string red_right_no_middle(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (var == one)
    {
    }
    if (var == two)
    {
        return red_right_goal_rush(calibrate, var, get_name);
    }
    if (get_name)
    {
        return "red right no middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_pose(7, 27, 10);
    chassis.turn_to_point(31.5, 4);
    chassis.drive_to_point(31.5, 4);
    assembly.scraper.toggle();
    chassis.turn_to_point(31.5, -7);
    chassis.drive_distance(20, {.timeout = 1250, .max_voltage = 6});
    chassis.drive_to_point(32.5, 10);
    chassis.turn_to_point(32.5, -20);
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(3000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(32, 12);
    chassis.turn_to_point(22.7, 12);
    chassis.drive_to_point(22.7, 12);
    chassis.turn_to_point(22.7, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string red_right_goal_rush(bool calibrate, auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "red right no middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    intakecon = 1;
    chassis.drive_to_pose(7, 27, 10);
    chassis.turn_to_point(31.5, 4);
    chassis.drive_to_point(31.5, 4);
    assembly.scraper.toggle();
    chassis.turn_to_point(31.5, -7);
    chassis.drive_distance(20, {.timeout = 1250, .max_voltage = 6});
    chassis.drive_to_point(32.5, 10);
    chassis.turn_to_point(32.5, -20);
    chassis.drive_distance(-12, {.timeout = 1000});
    active = true;
    task::sleep(3000);
    active = false;
    assembly.scraper.toggle();
    chassis.drive_to_point(32, 12);
    chassis.turn_to_point(22.7, 12);
    chassis.drive_to_point(22.7, 12);
    chassis.turn_to_point(22.7, 30, {.angle_offset = 180});
    assembly.wing.toggle();
    task::sleep(250);
    assembly.wing.toggle();
    chassis.drive_distance(-12, {.timeout = 600});

    return "";
}
std::string skills(bool calibrate, auto_variation var, bool get_name)
{ // Not Started
    if (get_name)
    {
        return "skills";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);
        return "";
    }

    // Add Code

    return "";
}