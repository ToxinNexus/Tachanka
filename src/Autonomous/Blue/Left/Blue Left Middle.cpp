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
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    return "";
}