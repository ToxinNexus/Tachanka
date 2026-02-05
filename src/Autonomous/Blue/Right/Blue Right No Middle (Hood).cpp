#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_right_no_middle_hood(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Blue Right No Middle (Hood)";
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