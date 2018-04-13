#ifndef _boat_h_
#define _boat_h_

#include "util.h"

/*
    Main C file for the boats
*/

void drawBoatPart(float x, float y, float m, float r, float g, float b, float canAngle);
float boatx(bool boat);
float boaty(bool boat);
float boatm(bool boat);
float boatcl(bool boat);

#endif