#include "vex.h"

using namespace vex;
using namespace mik;

void default_constants(void)
{
	chassis.set_control_constants(5, 10, 1.019, 5, 10, 1.019);

	// Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
	chassis.set_turn_constants(12, .437, .0215, 3.383, 15);
	chassis.set_drive_constants(10, 1.5, 0, 10, 0);
	chassis.set_heading_constants(3, .4, 0, 1, 0);
	chassis.set_swing_constants(12, .437, .0295, 3.483, 15);

	// Each exit condition set is in the form of (settle_error, settle_time, timeout).
	chassis.set_turn_exit_conditions(1.5, 200, 2000);
	chassis.set_drive_exit_conditions(0.5, 200, 3000);
	chassis.set_swing_exit_conditions(1.25, 200, 3000);
}

void odom_constants(void)
{
	default_constants();
	chassis.heading_max_voltage = 10;
	chassis.drive_max_voltage = 8;
	chassis.drive_settle_error = 2;
	chassis.boomerang_lead = .5;
	chassis.boomerang_setback = 2;
}