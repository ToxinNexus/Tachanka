#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_left_middle(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Blue Left Middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    // Red Left Middle
    red_left_middle(calibrate, var, get_name);

    return "";
}