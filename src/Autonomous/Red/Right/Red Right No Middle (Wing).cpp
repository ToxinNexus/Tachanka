#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_right_no_middle_wing(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Red Right No Middle (Wing)";
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