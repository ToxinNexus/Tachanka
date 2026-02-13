#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_right_goal_rush(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Blue Right Goal Rush";
    }
    if (calibrate)
    {
        odom_constants();
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    // Call Blue Right Goal Rush
    red_right_goal_rush(calibrate, var, get_name);

    return "";
}
