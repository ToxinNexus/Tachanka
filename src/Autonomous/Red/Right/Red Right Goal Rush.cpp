#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_right_goal_rush(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Red Right Goal Rush";
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