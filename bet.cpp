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

		point1 -= 100; //�⺻���� 
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

		cout << "�÷��̾� 1, �����Ͻðڽ��ϱ�?\n1.���� 2.üũ 3. ����" << endl;
		do {
			cin >> num;
			if (num == 1)
			{
				cout << "������ �ݾ��� �ۼ��� �ּ���" << endl;
				cin >> bm1;
				while (bm1 < bm2) {
					cout << "��� ���ñݾ�: " << bm2 << "�� ���ų� ���� ���� �ݾ��� �Է����ּ���\n";
					cin >> bm1;
				}
				if (bm1 > point2 && bm1 > point1) {
					if (point1 > point2) {
						cout << "����� ������ ���� ���� �Է��߱� ������ ����� ����ŭ �����մϴ�.\n";
						bm1 = point2;
					}
					else {
						cout << "�ڽ��� ������ ���� ���� �Է��߱� ������ �����մϴ�.\n";
						bm1 = point1;
					}
				}
				else if (bm1 > point2)
				{
					cout << "����� ������ ���� ���� �Է��߱� ������ ����� ����ŭ �����մϴ�.\n";
					bm1 = point2;
				}
				else if (bm1 > point1)
				{
					cout << "�ڽ��� ������ ���� ���� �Է��߱� ������ �����մϴ�.\n";
					bm1 = point1;
				}

				cout << "�÷��̾�1�� ������ �ݾ� : " << bm1 << endl;
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
					return 1;  //üũ�� ������ ���ϰ� 1 
				}
			}
			else if (num == 3)
			{
				cout << "�÷��̾�1 ����";
					point1 -= bm1;
				sum += bm1;
				//cout<<point1<<" "<<sum<<endl;
				point2 -= bm2;
				sum += bm2;
				//cout<<point2<<" "<<sum<<endl;
				betting::playerWin(2);
				return -1;	//���̷� ������ ���ϰ� -1 
			}
			else {
				cout << "�ٽ� �Է����ּ���.\n";
			}
		} while (num != 0 && num != 1 && num != 2);

		cout << "�÷��̾� 2, �����Ͻðڽ��ϱ�?\n1.���� 2.üũ 3. ����" << endl;
		do {
			cin >> num;
			if (num == 1)
			{
				cout << "������ �ݾ��� �ۼ��� �ּ���" << endl;
				cin >> bm2;
				while (bm2 < bm1) {
					cout << "��� ���ñݾ�: " << bm1 << "�� ���ų� ���� ���� �ݾ��� �Է����ּ���\n";
					cin >> bm2;
				}
				if (bm2 > point2 && bm2 > point1) {
					if (point1 > point2) {
						cout << "�ڽ��� ������ ���� ���� �Է��߱� ������ �����մϴ�.\n";
						bm2 = point2;
					}
					else {
						cout << "����� ������ ���� ���� �Է��߱� ������ ����� ����ŭ �����մϴ�.\n";
						bm2 = point1;
					}
				}
				if (bm2 > point2)
				{
					cout << "�ڽ��� ������ ���� ���� �Է��߱� ������ �����մϴ�.\n";
					bm2 = point2;
				}
				else if (bm2 > point1)
				{
					cout << "����� ������ ���� ���� �Է��߱� ������ ����� ����ŭ �����մϴ�.\n";
					bm2 = point2;
				}
				cout << "�÷��̾�2�� ������ �ݾ� : " << bm2 << endl;

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
				cout << "�÷��̾�2 ����";
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
				cout << "�ٽ� �Է����ּ���.\n";
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
	cout << "�÷��̾�1�� ���Դϴ�." << point1 << endl;
	cout << "�÷��̾�2�� ���Դϴ�." << point2 << endl;
}

/* ����κ� */
int betting::retpoint1(betting ref) {
	return ref.point1;
}

int betting::retpoint2(betting ref) {
	return ref.point2;
}

