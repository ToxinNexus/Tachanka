#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_right_middle(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Blue Right Middle";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    // Call Blue Right Middle
    red_right_middle(calibrate, var, get_name);

    return "";
}