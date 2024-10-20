#include "cbullet.h"

cbullet::cbullet() 
{
	_n = 0;
	_speed = 4;
	
	_curr = { 0,0,0 };
	for (int i = 0; i < cpoint::MAP_SIZE * cpoint::MAP_SIZE;i++) _p[i] = { 0,0,0 };
	for (int i = 0; i < cpoint::MAP_SIZE;i++) {
		for (int j = 0; j < cpoint::MAP_SIZE;j++) {
			_m[i][j] = { 0, 0, 0 };
		}
	}
}

void cbullet::updateMap(int i, int j, cpoint v)
{
	if (i >= 0 && i < cpoint::MAP_SIZE && j >= 0 && j < cpoint::MAP_SIZE)
		_m[i][j] = v;
}

cpoint cbullet::getCurr()
{
	return _curr;
}

void cbullet::setCurr(cpoint tcurr)
{
	if (tcurr.getX() >= 0 && tcurr.getX() < cpoint::MAP_SIZE &&
		tcurr.getY() >= 0 && tcurr.getY() < cpoint::MAP_SIZE)
		_curr = tcurr;
}

cpoint* cbullet::getP()
{
	return _p;
}

int cbullet::getSpeed()
{
	return _speed;
}

int cbullet::getN()
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

int cbullet::queryCFromRowCol(int row, int col) 
{
	if (row < 0 || row >= cpoint::MAP_SIZE || col < 0 || col >= cpoint::MAP_SIZE)
		return -2;
	else 
	{
		for (int i = 0; i < cpoint::MAP_SIZE; i++) {
			for (int j = 0; j < cpoint::MAP_SIZE; j++) {
				cpoint tmp = cpoint::fromXYToRowCol(_m[i][j]);
				if (tmp.getX() == row && tmp.getY() == col) {
					return _m[i][j].getC();
				}
			}
		}
	}
	return -1; // Return -1 if no match is found
}
int cbullet::calcPathBullet(cpoint tower) 
{
	cpoint tmp = cpoint::fromXYToRowCol(tower);
	int row = tmp.getX(), col = tmp.getY(), i = 0;
	do {
		col++; row--;
		if (queryCFromRowCol(row, col) == 0) {
			_p[i] = cpoint::fromRowColToXY({ row,col,0 });
			i += 2;
		}
		else break;
	} while (i < cpoint::MAP_SIZE);
	_n = i;
	for (i = 1; i < _n;i += 2) 
	{
		_p[i] = { _p[i - 1].getX() + 2,_p[i - 1].getY() - 1,0 };
	}
	_curr = { _p[0].getX(),_p[0].getY(),_p[0].getC() };
	return _n;
}
