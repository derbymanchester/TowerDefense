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
	cpoint getCurr() {
		return _curr; 
	}
	void setCurr(cpoint tcurr) {
		if (tcurr.getX() >= 0 && tcurr.getX() < cpoint::MAP_SIZE &&
			tcurr.getY() >= 0 && tcurr.getY() < cpoint::MAP_SIZE)
			_curr = tcurr;
	}
	cpoint* getP() 
	{ 
		return _p; 
	}
	int getSpeed() { 
		return _speed; 
	}
	int getN() 
	{ 
		return _n; 
	}
	void setN(int tn) 
	{
		if (tn >= 0 && tn <= cpoint::MAP_SIZE * cpoint::MAP_SIZE)
			_n = tn;
	}
	void setSpeed(int tspeed) 
	{
		if (tspeed > 0) 
			_speed = tspeed;
	}
	int queryCFromRowCol(int, int);
	int calcPathBullet(cpoint);
};
