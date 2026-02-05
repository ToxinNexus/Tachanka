#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_sawp(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Red SAWP";
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