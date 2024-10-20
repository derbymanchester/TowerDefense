#pragma once
#include "cpoint.h"

class cbullet {
	//_n is not the number of bullets, but the current size of the bullet path array
	int _n, _speed;
	cpoint _p[cpoint::MAP_SIZE * cpoint::MAP_SIZE];
	// map information is used to calculate the path array _p
	cpoint _m[cpoint::MAP_SIZE][cpoint::MAP_SIZE];
	cpoint _curr; // current position of the bullet
public:
	cbullet();
	void updateMap(int, int, cpoint);
	cpoint getCurr();
	void setCurr(cpoint);
	cpoint* getP();
	int getSpeed();
	int getN();
	void setN(int);
	void setSpeed(int);
	int queryCFromRowCol(int, int);
	int calcPathBullet(cpoint);
};
