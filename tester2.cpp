#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//�������� ���������
struct Menu	{  // �������� ���������
	string c; // ������� ��������, � �������� ����� ����������� �������� ��������
	string A[5]; // ������, ������� �� ���� ����� �� ����� ���� ���������.
};


int _tmain(int argc, _TCHAR* argv[]) //  ��� ��� ������� �� ��� ���
{	
	setlocale(LC_ALL,".1251"); // ����������� ��������� ������, ������ �� ������� ������ �����.
	Menu item[6]; // ���������� ����������� ������ � ����������� ���������. 
	int N=6; ���������� ��������� ������.
	int M=5; 
	int position_m=1; //������ ������� �� ������ �������
	int position_pm=1;

	item[0].c ="�����";
	item[1].c ="��������";
	item[2].c ="�������� ��������";
	item[3].c ="�������������� ��������";
	item[4].c ="�������� ��������";
	item[5].c ="�����";

	for (int i=0;i<N-1;i++)
		if (position_m==i+1) // ���� ������� (����� 1) ����� i+1 �� ������� ��������� �� ��� i=0, ������������� i+1=0+1=1, ����� �� ������ ��������� � ���.
			cout << i+1 << " *" << item[i].c << "*\n";
		else 
			cout << i+1 << "  " << item[i].c << "\n";

	if (position_m==6)
			cout << 0 << " *" << item[5].c << "*\n";
		else 
			cout << 0 << "  " << item[5].c << "\n";
 
	item [0].A[0]="���������";

	item [1].A[0]="���������";

	item [2].A[0]="������";
	item [2].A[1]="�������";
	item [2].A[2]="���������";
	item [2].A[3]="�� �����";
	item [2].A[4]="���������";

	item [3].A[0]="������";
	item [3].A[1]="�������";
	item [3].A[2]="���������";
	item [3].A[3]="�� �����";
	item [3].A[4]="���������";

	item [4].A[0]="������";
	item [4].A[1]="�������";
	item [4].A[2]="���������";
	item [4].A[3]="�� �����";
	item [4].A[4]="���������";

	item [5].A[0]= "��";
	item [5].A[1]= "���";

	bool F=true;

	int w,x,y,z;
	while (1)	{
		x=getch();
		if (x==224) 
			x=getch();
		switch (x) {
			case 49:
				position_m=1;
				break;
			case 50: 
				position_m=2;
				break;
			case 51: 
				position_m=3;
				break;
			case 52: 
				position_m=4;
				break;
			case 53: 
				position_m=5;
				break;
			case 48: 
				position_m=6;
				break;
			case 80:
				position_m++;
				break;
			case 72:
				position_m--;
				break;
			case 13:
				F=false;
				break;
			case 27:
				position_m=6;
				F=false;
				break;
			default:
				break;
		}
		if (position_m>N)
			position_m=1;
		if (position_m<1)
			position_m=N;

		if (F==false) {
			system("cls");
			cout << " " << item[position_m-1].c << "\n";

			if (position_m==1)
				cout << "1.1 *" << item[0].A[0] << "*\n";

			if (position_m==2)
				cout << "2.1 *" << item[1].A[0] << "*\n";

			if (position_m==3||position_m==4||position_m==5) {
				for (int i=0; i<M-1; i++) 
					if (position_pm==i+1)
						cout << position_m << "." << i+1 << " *" << item[position_m-1].A[i] << "*\n";
					else 
						cout << position_m << "." << i+1 << "  " << item[position_m-1].A[i] << "\n";
				if (position_pm==5)
							cout << position_m << "." << 0 << " *" << item[position_m-1].A[4] << "*\n";
						else 
							cout << position_m << "." << 0 << "  " << item[position_m-1].A[4] << "\n";
			}
				position_pm=1;

				do	{
					if (position_m==3||position_m==4||position_m==5) {
						z=getch();
						if (z==224)
							z=getch();
						switch (z) {
							case 49:
								position_pm=1;
								break;
							case 50:
								position_pm=2;
								break;
							case 51:
								position_pm=3;
								break;
							case 52:
								position_pm=4;
								break;
							case 48:
								position_pm=5;
								break;
							case 80:
								position_pm++;
								break;
							case 72:
								position_pm--;
								break;
							case 27:
								F=true;
								position_pm=1;
								break;
							default:
								break;
						}

						if (position_pm>M)
							position_pm=5;
						if (position_pm<1)
							position_pm=1;

						system ("cls");
						cout << " " << item[position_m-1].c << "\n";

						for (int i=0; i<M-1; i++)	
							if (position_pm==i+1) 
								cout << position_m << "." << i+1 << " *" << item[position_m-1].A[i] << "*\n";
							else 
								cout << position_m << "." << i+1 << "  " << item[position_m-1].A[i] << "\n";
							if (position_pm==5)
								cout << position_m << "." << 0 << " *" << item[position_m-1].A[4] << "*\n";
							else 
								cout << position_m << "." << 0 << "  " << item[position_m-1].A[4] << "\n";
					
						if (position_pm==5) 
							switch (z) {
							case 13:
								F=true;
								position_pm=1;
								break;
							}
					}

					if (position_m==1||position_m==2) {
						y=getch();
						if (y==224)
							y=getch();
						switch (y) {
							case 13:
								F=true;
								position_pm=1;
								break;
							case 27:
								F=true;
								position_pm=1;
								break;
						}
					}

					if (position_m==6) {
						cout << "\n�� �������, ��� ������ �����?\n"; 
						for (int i=0; i<2; i++)	{
							if (position_pm==i+1) 
								cout << "  *" << item[position_m-1].A[i] << "*";
							else 
								cout << "   " << item[position_m-1].A[i] << "";
						}

						w=getch();
						if (w==224)
							w=getch();
						switch (w) {
							case 49:
								position_pm=1;
								break;
							case 50:
								position_pm=2;
								break;
							case 77:
								position_pm++;
								break;
							case 75:
								position_pm--;
								break;
							case 27:
								F=true;
								position_pm=1;
								break;
						}

						if (position_pm>2)
							position_pm=1;
						if (position_pm<1)
							position_pm=2;

						system ("cls");
						cout << " " << item[position_m-1].c << "\n";

						if (position_pm==2) 
							switch (w) {
							case 13:
								F=true;
								position_pm=1;
								break;
							}
					
						else if (position_pm==1) 
							switch (w) {
							case 13:
								exit(1);
								break;
							}
					}
				}
				while (F==false);
		}

		if (F==true) {
			system("cls");
			for (int i=0;i<N-1;i++)
				if (position_m==i+1)
					cout << i+1 << " *" << item[i].c << "*\n";
				else 
					cout << i+1 << "  " << item[i].c << "\n";

			if (position_m==6)
					cout << 0 << " *" << item[5].c << "*\n";
				else 
					cout << 0 << "  " << item[5].c << "\n";
		}

	}

getch();
return 0;
}


