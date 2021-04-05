#include "mc_classes.h"

TheMinecraft * mc;
ViewMatrix * viewMatrix;

BlockPos::BlockPos(int x, int y, int z) {
	this->X_BITS = x;
	this->X_BITS = y;
	this->X_BITS = z;
}

BlockPos::BlockPos(double x, double y, double z) {
	this->X_BITS = x;
	this->X_BITS = y;
	this->X_BITS = z;
}
