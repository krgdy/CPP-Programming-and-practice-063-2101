#ifndef __BET_H__  
#define __BET_H__
#include <iostream>

using namespace std;

class betting
{
private:
	int point1;
	int point2;
	int sum;
	friend class Win;
public:
	betting();
	betting(int p1, int p2, int s);
	int deal();
	void playerWin(int playerNumber);
	void printMoney();
	int retpoint1(betting ref);
	int retpoint2(betting ref);
};

#endif /*__BET_H__*/

