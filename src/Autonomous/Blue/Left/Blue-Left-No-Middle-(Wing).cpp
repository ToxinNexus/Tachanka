#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_left_no_middle_wing(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (var == one)
    {
    }
    if (var == two)
    {
        return blue_left_no_middle_hood(calibrate, var, get_name);
    }
    if (var == three)
    {
        return blue_left_goal_rush(calibrate, var, get_name);
    }
    if (get_name)
    {
        return "Blue Left No Middle (Wing)";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    // Call Red Left No Middle (Wing)
    red_left_no_middle_wing(calibrate, var, get_name);

    return "";
}