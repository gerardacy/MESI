#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <assert.h>

using namespace std;

//�������� ���������
struct menu	{  // �������� ���������
	string name; // �������� �������� @_@
	string mass[100]; 
};
/*-----------------------------------------------------------------------------------------------
a2b1c1 d3e1 d2e2
a2 = ��������������
b1 = ��� ������ ��������
c1 = �� ���������

d3 = ��������  
e1 = ������� (�� �����)

d2 = ��������������
e2 = �� ����� 


d1 = ����������
e3 = ���������� �� ��������

����� ����� ������ ������ ������� --� ����������-- � � ������, ����� ���-�� ������ � ����������� �.�. ����� ���� ,���� ��� ����� ���������
����� ������� �������� ����� ���� ������ � ��� ����� �� ������ �������, �� � � ����� ������� ����� ������� �� �������� � ����� ��� �� ������� ��� ���� �������� � ������� ��� � ��������

-�������� 3 ��� ����� ��?
-���
-����� ������ ���?
-��, �� ���������.

*/
//�������� (�� ������ ������ ����)
struct list{
	list *next;
	string data;
	int id;
	list *prev;//����������
};

//������
class Bigcube{
	list *first;
	int number;
public:
	Bigcube():first(NULL){}
	void Add(string nova){
		list *current = first; 
		list *newlink = new list;
		if (first==NULL){  //���� ������ ��������� // 
			number=1;
			first=newlink;

			newlink->next=NULL; //���������
			newlink->prev=NULL; //���������

			newlink->data=nova; //���� = �����
			newlink->id=number; // ����� � �����

			number++;
		}else{
			while (current->next!=NULL) {//���� �� ����������
				current=current->next;
			}
			current->next=newlink; //��������� ������ ��������� �� �����
			first->prev=newlink; //������ ������������ �� ���������

			newlink->next=NULL; //�� ����� ������ �������� ����
			newlink->prev=current; //�� ���������� �������� ���������

			newlink->data=nova; // �� ������ �������� ������������
			newlink->id=number; // � �����
			number++; //�������� �� ���� �����
		}
	}

int main()
{	

	menu razd[100]; 
	int K=7; //���������� ��������� ������.
	int M=6; 
	int key1=1; //�� �����
	int key2=1;

	razd[0].name ="File"; //��������� 
	razd[1].name ="Show";
	razd[2].name ="Create";
	razd[3].name ="Show";
	razd[4].name ="Delete";
	razd[6].name = "1";
	razd[5].name ="Exit";

	for (int i=0;i<K-1;i++)
		if (key1==i+1) // 0_0 ���������� 
						cout << i+1 << " *" << razd[i].name << "*\n";
																	else 
						cout << i+1 << "  " << razd[i].name << "\n";

	

	if (key1==7) cout << 0 << " *" << razd[5].name << "*\n";
															else 
			 	cout << 0 << "  " << razd[5].name << "\n";
 
	razd[0].mass[0]="Back";                                                                                                               //����������� ��������� � ��������

	razd[1].mass[0]="Back";

	razd[2].mass[0]="First";
	razd[2].mass[1]="Middle";
	razd[2].mass[2]="Last";
	razd[2].mass[3]="By key";
	razd[2].mass[4]="Back";

	razd[6].mass[1]="2";
	

	razd[3].mass[0]="First";
	razd[3].mass[1]="Middle";
	razd[3].mass[2]="Last";
	razd[3].mass[3]="By key";
	razd[3].mass[4]="Back";

	razd[4].mass[0]="First";
	razd[4].mass[1]="Middle";
	razd[4].mass[2]="Last";
	razd[4].mass[3]="By Key";
	razd[4].mass[4]="Back";

	razd[5].mass[0]= "Yes";
	razd[5].mass[1]= "No";

	bool F=true; // ������ �
	int w,x,y,z; //��������

	while (1)	{
					x=getch();
					if (x==224) 
					x=getch();
					switch (x) {
								case 80:
										key1++;
										break;
								case 72:
										key1--;
										break;
								case 13:
										F=false;
										break;


				}

		if (key1>K)
					key1=1;
		if (key1<1)
					key1=K;

		if (F==false) {
						system("cls");
		

						if (key1==1) cout << "0 *" << razd[0].mass[0] << "*\n";

						if (key1==2) cout << "0 *" << razd[1].mass[0] << "*\n";

						if (key1==3|| key1==4|| key1==5) {
															for (int i=0; i<M-1; i++) 
																						if (key2==i+1)	cout << i+1 << " *" << razd[key1-1].mass[i] << "*\n";
																																							else 
																										cout << i+1 <<"  " << razd[key1-1].mass[i] << "\n";
				
																						if (key2==5)	cout << 0 << " *" << razd[key1-1].mass[4] << "*\n";
																																							else 
																										cout << 0 << "  " << razd[key1-1].mass[4] << "\n";
															}
						key2=1;

								do	{
						if (key1==3|| key1==4|| key1 ==5 || key1 ==6) {
															z=getch();
																	if (z==224)
																				z=getch();
																				switch (z) {
																							case 80:
																									key2++;
																									break;
																							case 72:
																									key2--;
																									break;
																							default:
																									break;
																							}

						if (key2>M)
									key2=1;
						if (key2<1)
									key2=M;

						system ("cls");
					

						for (int i=0; i<M-1; i++)	
												if (key2==i+1) 
																cout << i+1 <<  " *" << razd[key1-1].mass[i] << "*\n";
																													else 
																cout << i+1 <<  "  " << razd[key1-1].mass[i] << "\n";
												if (key2==6)
																cout << 0 << " *" << razd[key1-1].mass[4] << "*\n";
																													else 
																cout << 0  <<  "  " << razd[key1-1].mass[4] << "\n";
					
												if (key2==7) 
															switch (z) {
																		case 13:
																				F=true;
																				key2=1;
																				break;
																		}
					}

												if (key1==1|| key1==2) {
																		y=getch();
																				if (y==224)
																							y=getch();
																							switch (y) {
																										case 13:
																												F=true;
																												key2=1;
																												break;
																										case 27:
																												F=true;
																												key2=1;
																												break;
																										}
																		}

												if (key1==7) {
																cout << "\nDude, are u sure?\n"; 
																	for (int i=0; i<2; i++)	{
																							if (key2==i+1) 
																											cout << "  *" << razd[key1-1].mass[i] << "*";
																																						else 
																											cout << "   " << razd[key1-1].mass[i] << "";
																							}

						w=getch();
						if (w==224)
									w=getch();
						switch (w) {
									case 77:
											key2++;
											break;
									case 75:
											key2--;
											break;
									}


						if (key2>2)
									key2=1;
						if (key2<1)
									key2=2;

						system ("cls");

						if (key2==2) 
									switch (w) {
												case 13:
														F=true;
														key2=1;
														break;
												}
					
																else
						if (key2==1) 
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
									for (int i=0;i<K-1;i++)
															if (key1==i+1)
																			cout << i+1 << " *" << razd[i].name << "*\n";
																														else 
																			cout << i+1 << "  " << razd[i].name << "\n";

															if (key1==6)
																			cout << 0 << " *" << razd[5].name << "*\n";
																														else 
																			cout << 0 << "  " << razd[5].name << "\n";
					}

	}

getch();
return 0;
}



