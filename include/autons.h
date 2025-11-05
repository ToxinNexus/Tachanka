#pragma once

#include "vex.h"

void default_constants(void);
void odom_constants(void);

std::string template_auto(bool calibrate , mik::auto_variation var, bool get_name );
std::string template_auto_other_variation(bool calibrate, bool get_name);

std::string blue_left_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string blue_left_sawp(bool calibrate, mik::auto_variation var, bool get_name );
std::string blue_left_no_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string blue_right_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string blue_right_sawp(bool calibrate, mik::auto_variation var, bool get_name );
std::string blue_right_no_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string red_left_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string red_left_sawp(bool calibrate, mik::auto_variation var, bool get_name );
std::string red_left_no_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string red_right_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string red_right_sawp(bool calibrate, mik::auto_variation var, bool get_name );
std::string red_right_no_middle(bool calibrate, mik::auto_variation var, bool get_name );
std::string skills(bool calibrate, mik::auto_variation var, bool get_name );