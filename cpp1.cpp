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
	list*first;
	list*tail;
	int number;
public:
	Bigcube():first(NULL){}

	//---------------------------------------ADD-IN by last-----------------------------------//
	
	void Add(string nova)
	{
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
			  while (current->next!=NULL){							//���� �� ����������
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

	//---------------------------------------ADD-IN by middle--------------------------------//

	void Add2 (string nova){
	list *current = first;
	list *newlink = new list;
	list *temporary= new list;
		if(first == NULL)
		{
			number=0;
			newlink->data=nova;
			newlink->id=number;
			newlink->next=NULL;
			newlink->prev=NULL;
			first=newlink;
			number++;
		}
		else{
			int amount=0;
			while (current)//���� �� ����� 
			{
				amount++;
				current=current->next;
			}
			current=first;

			int inview;
			if (amount%2 ==1)
			{
				inview=amount/2;
			}
			else 
			{
				inview=(amount-1)/2;
			}

			int score=0;
			while(score<inview+1)
			{
				if (score == inview)
				{
					newlink->data=nova;
					newlink->id=number;
					number++;
					newlink->next=current->next;
					newlink->prev=current;
					current->next=newlink;
				}
				score++;
				current=current->next;
			}
		}
}

	//--------------------------------------ADD-IN by first---------------------------------//
	
void Add3(string nova)
{ // ������� ������ �������� � ����� ������

		list* temp = tail;


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

		first->prev=tail;
		newlink->next=first;
		first=newlink;
		newlink->data=nova;
		newlink->id=number;
		number++;
}

}

	//--------------------------------------SHOW--------------------------------------------------//
		void Show(){
		list *current = first;
			if(current==NULL){
								cout<<endl<<endl<<"       Nothing to say"<< endl<< endl;
							 }
			else
				{
				do {
					cout<<"Number - " << current->id<<"   "<<current->data<<endl;
					current=current->next;
				   } while (current!=NULL);}
				}
	

	//---------------------------------------EDIT-by-key-------------------------------------------//

		void gedit(int idnew,string datanew){
		list *current = first;
		do {
			if(idnew==(current->id)){
				current->data=datanew;}
		} while (current==first);
	}
		//----------------------------------------EDIT-by-first-------------------------------------//

	

	void gedit2(string datanew)
		{
// if (current==NULL){ cout << "Action is not available" << endl;	break;}
		list *current = first;
		
		current->data=datanew;
		current=current->next;
		

		}
		
	
	
	/*	void gedit3(string datanew)
		{
// if (current==NULL){ cout << "Action is not available" << endl;	break;}
		list *current = first;
		do {
		current->data=datanew;
		current=current->next;
		}while (current!=NULL);

		}*/
	  
	//---------------------------------------FILE-----------------------------------------------//
	void CreateFile(){
						ofstream out;
						out.open("New List.txt");
						list *current = first;
										do{
											out<<current->data<<"\n";
											current=current->next;
										  }
											while (current!=NULL);
	
												out.close();
	}
	void UseFile(Bigcube *name)
									{
												ifstream fin;
												string str;
												string paststring;

											fin.open("New List.txt",ios::in);
											assert (!fin.fail( ));

									while (!fin.eof( ))
									{
														fin >> str;
														if(str != paststring)
																			{
																			name->Add(str);
																			paststring=str;
																			}
								    }
							fin.close( );
									}};



	//--------------------------------------MENU-----------------------------------------------//
int main()
{	

//-------------------------------------NEW const------------------------//
	Bigcube *set=new Bigcube;
	int newi=0;
	string line;
	string linenew;
	int id;
//----------------------------------------------------------------------//

	menu razd[100]; 
	int K=6; //���������� ��������� ������.
	int M=5; 
	int key1=1; //�� �����
	int key2=1;

	razd[0].name ="File"; //��������� 
	razd[1].name ="Show";
	razd[2].name ="Create";
	razd[3].name ="Edit";
	razd[4].name ="Delete";
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

						if (key1==2){
									cout << "0 *" << razd[1].mass[0] << "*\n";
									set -> Show();
									}		


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
//����
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
												if (key2==5)
																cout << 0 << " *" << razd[key1-1].mass[4] << "*\n";
																													else 
																cout << 0  <<  "  " << razd[key1-1].mass[4] << "\n";
					
												if (key2==5) 
															switch (z) {
																		case 13:
																				F=true;
																				key2=1;
																				break;
																		}
									if (key1==3){
												if (key2==3)
															switch (z) {
																		case 13:
																				while(F==false){
																				cout << "------------------------------" << endl;
																				cout << " Add one new last element" << endl;
																				cout << " New Element's Name:";
																				cin>>line;//�������� ������
																				set->Add(line);//���������� �������� � ������
																				cout << " New Element added"<<endl;
																				cout << " Press 0 twice to return" << endl;
																				cout << "------------------------------" << endl;
																			//	system("pause");
																				newi++;
																				break;
																				}
																		case 48: break;
												};
												if (key2==2)
															switch (z) {
																		case 13: while(F==false)
																				 {
																				cout << "------------------------------" << endl;
																				cout << " Add one new middle element" << endl;																				cout << " Add one new element" << endl;
																				cout << " New Element's Name:";
																				cin>>line;//�������� ������
																				set->Add2(line);//���������� �������� � ������
																				cout << " New Element added"<<endl;
																				cout << " Press 0 twice to return" << endl;
																				cout << "------------------------------" << endl;
																				//system("pause");
																				newi++;
																				 break;
																				 }
																		case 48: break;
																		
												};
												if (key2==1)
															switch (z) {
																		case 13: while(F==false)
																				 {
																				cout << "------------------------------" << endl;
																				cout << " Add one new first element" << endl;																				cout << " Add one new element" << endl;
																				cout << " New Element's Name:";
																				cin>>line;//�������� ������
																				set->Add3(line);//���������� �������� � ������
																				cout << " New Element added"<<endl;
																				cout << " Press 0 twice to return" << endl;
																				cout << "------------------------------" << endl;
																				//system("pause");
																				newi++;
																				 break;
																				 }
																		case 48: break;
												};
     
												}
									if (key1==4)
												{
													if (key2==4){
																switch(z){
																			case 13: while(F==false)
																					 {
																						 cout << "------------------------------" << endl;
																						 cout << "Edit one element by key" << endl;
																						 cout << "Write id of element: "<< endl;
																						 cin >> id;
																						 cout << "Write a new name: " << endl;
																						 cin >> linenew;
																						 set->gedit(id,linenew);
																						 cout << "-------------------------------" << endl;
																						 break;
																					 }
																			case 48: break;
																}; }
													if (key2==1){
																switch(z){
																case 13: while(F==false)
																		 {
																			cout << "------------------------------" << endl;
																			cout << "Edit first element"<< endl;
																			cout << "Write a new name: " << endl;
																				cin >> linenew;
																			set->gedit2(linenew);
																			cout << "-----------------------------" << endl;
																			break;
																		 }
																case 48: break;
																}; }

									
																
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
/* Note of fixes
-Rabotaet show
-Dobavleno sozdanie faila i extractor pravda ya ne ponimau za4em eto, nujno zapihnut' v file punkt nujno narisovat'
4tonibud's
-Add String doljen zarabotat' nujno dobavit' vizivateli :)
-ustranena oshibka so skobkoi (class zakrivaetsya skobkoi i ";")
-------------------------
-add string rabotaet no nujno eshe podkorrektirovat' cikl
-show rabotaet otli4no
-nujno vpisat' ru language
-add func by first can return
-first complete
-----------------------------
-add by middle func added.
-need to write this func in case for key2=1, if i'm right.
-add first - changed into add last
-add middle worked 100%		
-----------------------------
-add by first into developin'
-edit by key can be work i think cuz it's easy !!!!!!!!!!!!!!!!!!11
-edit by key worked but not originally !!!!!!!!!!!!
-i think need to make id-shower for editin' and block some actions in editin' 
--------------------------
-edit by first worked 100% but need i think checker !!!!!!!!!!!!!!!!!!!!!!
-edit by first is not allowed when number>1
-edit by first worked 100% now but need something like return button;
*/