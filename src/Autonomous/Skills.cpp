#include "vex.h"

using namespace vex;
using namespace mik;

std::string skills(bool calibrate, mik::auto_variation var, bool get_name)
{
    if (get_name)
    {
        return "Skills";
    }
    if (calibrate)
    {
        chassis.set_coordinates(0, 0, 0);

        return "";
    }

    // Add Code

    return "";
}