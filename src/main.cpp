#include "vex.h"

using namespace vex;
using namespace mik;

task UI;

static int run_UI()
{
    UI_init();
    UI_controller_auton_selector();
    UI_render();
    return 0;
}

void pre_auton()
{
    init();
    default_constants();
    odom_constants();
    UI = task(run_UI);
}

void auton(void)
{
    UI.stop();
    auton_scr->start_auton();
}

void user_control(void)
{
    while (calibrating)
    {
        task::sleep(50);
    }

    // How you want your drivetrain to stop during driver
    chassis.set_brake_type(brakeType::coast);

    assembly.init();

    while (true)
    {
        if (!control_disabled())
        {
            // Add your user control code here
            chassis.control(drive_mode::SPLIT_ARCADE_CURVED);
            assembly.control();
        }
        task::sleep(5);
    }
}

int main()
{
    Competition.autonomous(auton);
    Competition.drivercontrol(user_control);

    pre_auton();
    middle = false;
    active = false;
    // On Startup

    while (true)
    {
        // Forever

        if (active == true)
        {
            if (middle == true)
            {
                assembly.trapdoor.open();
            }
            else if (middle == false)
            {
                assembly.trapdoor.close();
            }
        }
        else if (active == false)
        {
            assembly.trapdoor.close();
        }
        if (intakecon == 1)
        {
            if (middle == false && active == false)
            {
                assembly.top.spin(reverse, 3, volt);
                assembly.bottom.spin(fwd, 12, volt);
            }
            else if (middle == false && active == true)
            {
                assembly.top.spin(fwd, 12, volt);
                assembly.bottom.spin(fwd, 12, volt);
            }
            else if (middle == true && active == false)
            {
                assembly.top.spin(reverse, 3, volt);
                assembly.bottom.spin(fwd, 12, volt);
            }
            else if (middle == true && active == true)
            {
                assembly.top.spin(reverse, 3, volt);
                assembly.bottom.spin(fwd, 9, volt);
            }
        }
        else if (intakecon == 2)
        {
            assembly.top.spin(reverse, 12, volt);
            assembly.bottom.spin(reverse, 12, volt);
        }
        else if (intakecon == 3)
        {
            assembly.top.stop();
            assembly.bottom.stop();
        }

        task::sleep(100);
    }
}
