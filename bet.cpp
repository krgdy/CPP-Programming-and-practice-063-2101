#include"bet.h"
#include <iostream>

using namespace std;
betting::betting() :point1(10000), point2(10000), sum(0)
{
}
betting::betting(int p1, int p2, int s) : point1(p1), point2(p2), sum(s)
{

}
int betting::deal()
{
	int num;
	int bm1 = 0, bm2 = 0;
	bool check1 = false;
	bool check2 = false;
	if (point1 >= 100 && point2 >= 100) {

		point1 -= 100; //기본베팅 
		point2 -= 100;
		sum += 200;
	}
	else if (point1 < point2) {
		sum += 2 * point1;
		point2 -= point1;
		point1 = 0;
	}
	else if (point2 <= point1) {
		sum += 2 * point2;
		point1 -= point2;
		point2 = 0;
	}

	while (1)
	{

		cout << "플레이어 1, 베팅하시겠습니까?\n1.베팅 2.체크 3. 다이" << endl;
		do {
			cin >> num;
			if (num == 1)
			{
				cout << "베팅할 금액을 작성해 주세요" << endl;
				cin >> bm1;
				while (bm1 < bm2) {
					cout << "상대 베팅금액: " << bm2 << "과 같거나 보다 많은 금액을 입력해주세요\n";
					cin >> bm1;
				}
				if (bm1 > point2 && bm1 > point1) {
					if (point1 > point2) {
						cout << "상대의 돈보다 많은 돈을 입력했기 때문에 상대의 돈만큼 베팅합니다.\n";
						bm1 = point2;
					}
					else {
						cout << "자신의 돈보다 많은 돈을 입력했기 때문에 올인합니다.\n";
						bm1 = point1;
					}
				}
				else if (bm1 > point2)
				{
					cout << "상대의 돈보다 많은 돈을 입력했기 때문에 상대의 돈만큼 베팅합니다.\n";
					bm1 = point2;
				}
				else if (bm1 > point1)
				{
					cout << "자신의 돈보다 많은 돈을 입력했기 때문에 올인합니다.\n";
					bm1 = point1;
				}

				cout << "플레이어1의 베팅한 금액 : " << bm1 << endl;
				check1 = true;
			}
			else if (num == 2)
			{
				check1 = true;
				bm1 = bm2;
				if (check2 == true) {
					point1 -= bm1;
					sum += bm1;
					//cout<<point1<<" "<<sum<<endl;
					point2 -= bm2;
					sum += bm2;
					//cout<<point2<<" "<<sum<<endl;
					return 1;  //체크로 끝날시 리턴값 1 
				}
			}
			else if (num == 3)
			{
				cout << "플레이어1 다이";
					point1 -= bm1;
				sum += bm1;
				//cout<<point1<<" "<<sum<<endl;
				point2 -= bm2;
				sum += bm2;
				//cout<<point2<<" "<<sum<<endl;
				betting::playerWin(2);
				return -1;	//다이로 끝날시 리턴값 -1 
			}
			else {
				cout << "다시 입력해주세요.\n";
			}
		} while (num != 0 && num != 1 && num != 2);

		cout << "플레이어 2, 베팅하시겠습니까?\n1.베팅 2.체크 3. 다이" << endl;
		do {
			cin >> num;
			if (num == 1)
			{
				cout << "베팅할 금액을 작성해 주세요" << endl;
				cin >> bm2;
				while (bm2 < bm1) {
					cout << "상대 베팅금액: " << bm1 << "과 같거나 보다 많은 금액을 입력해주세요\n";
					cin >> bm2;
				}
				if (bm2 > point2 && bm2 > point1) {
					if (point1 > point2) {
						cout << "자신의 돈보다 많은 돈을 입력했기 때문에 올인합니다.\n";
						bm2 = point2;
					}
					else {
						cout << "상대의 돈보다 많은 돈을 입력했기 때문에 상대의 돈만큼 베팅합니다.\n";
						bm2 = point1;
					}
				}
				if (bm2 > point2)
				{
					cout << "자신의 돈보다 많은 돈을 입력했기 때문에 올인합니다.\n";
					bm2 = point2;
				}
				else if (bm2 > point1)
				{
					cout << "상대의 돈보다 많은 돈을 입력했기 때문에 상대의 돈만큼 베팅합니다.\n";
					bm2 = point2;
				}
				cout << "플레이어2의 베팅한 금액 : " << bm2 << endl;

				check2 = true;
			}
			else if (num == 2)
			{
				bm2 = bm1;
				check2 = true;
				if (check1 == true) {
					point1 -= bm1;
					sum += bm1;
					//cout<<point1<<" "<<sum<<endl;
					point2 -= bm2;
					sum += bm2;
					//cout<<point2<<" "<<sum<<endl;
					return 1;
				}
			}
			else if (num == 3)
			{
				cout << "플레이어2 다이";
					point1 -= bm1;
				sum += bm1;
				//cout<<point1<<" "<<sum<<endl;
				point2 -= bm2;
				sum += bm2;
				//cout<<point2<<" "<<sum<<endl;
				betting::playerWin(1);
				return -1;
			}
			else {
				cout << "다시 입력해주세요.\n";
			}
		} while (num != 0 && num != 1 && num != 2);

	}
}
void betting::playerWin(int playerNumber) {
	switch (playerNumber) {
	case 1:
		point1 += sum;
		break;
	case 2:
		point2 += sum;
		break;
	default:
		break;
	}
	sum = 0;
}
void betting::printMoney() {
	cout << "플레이어1의 돈입니다." << point1 << endl;
	cout << "플레이어2의 돈입니다." << point2 << endl;
}

/* 변경부분 */
int betting::retpoint1(betting ref) {
	return ref.point1;
}

int betting::retpoint2(betting ref) {
	return ref.point2;
}

