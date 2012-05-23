
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <assert.h>

using namespace std;

//Введение структуры
struct menu	{  // Название структуры
	string name; // названия разделов @_@
	string mass[100]; 
};
/*-----------------------------------------------------------------------------------------------
a2b1c1 d3e1 d2e2
a2 = двунаправленны
b1 = без голого элемента
c1 = не кольцевой

d3 = удаление  
e1 = первого (по ключу)

d2 = редактирование
e2 = по ключу 


d1 = добавление
e3 = добавление по среднему

Нужно вбить вместо лишних пунктов --в разработке-- и я считаю, нужно что-то делать с оформлением т.к. после того ,если эту прогу загрузить
этими файлами списками будет дико лагать и это будет не совсем выгодно, да и я думаю сначала нужно сделать по среднему а потом уже по первому или даже улучшить и сделать оба с запросом

-осталось 3 дня успею ли?
-нет
-плохо значит мне?
-да, ты огребаешь.

*/
//Листовка (не пустой должен быть)
struct list{
	list *next;
	string data;
	int id;
	list *prev;//предыдущий
};


//Классы
class Bigcube{
	list *first;
	int number;
public:
	Bigcube():first(NULL){}

	//---------------------------------------ADD-IN by key-----------------------------------//
	
	void Add(string nova)
	{
		list *current = first; 
		list *newlink = new list;
		if (first==NULL){  //если первый добавляем // 
						number=1;
						first=newlink;

						newlink->next=NULL; //обнуление
						newlink->prev=NULL; //обнуление

						newlink->data=nova; //дата = днова
						newlink->id=number; // цифра к днове

						number++;
		}else{
			  while (current->next!=NULL){							//идем до последнего
											current=current->next;
									  	 }
			  current->next=newlink; //последний теперь указывает на новый
			  first->prev=newlink; //голова перемещается на следующий

			  newlink->next=NULL; //на новый линкер ставится нуль
			  newlink->prev=current; //на предыдущий ставится последний

			  newlink->data=nova; // на стринг ставится наименование
			  newlink->id=number; // и цифра

			  number++; //смещение на след цифру
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
	Bigcube *set=new Bigcube;
	int newi=0;
	string line;
	string linenew;


	menu razd[100]; 
	int K=6; //Количество элементов кароче.
	int M=5; 
	int key1=1; //не очень
	int key2=1;

	razd[0].name ="File"; //структура 
	razd[1].name ="Show";
	razd[2].name ="Create";
	razd[3].name ="Show";
	razd[4].name ="Delete";
	razd[5].name ="Exit";

				

	for (int i=0;i<K-1;i++)
		if (key1==i+1) // 0_0 стрелочник 
						cout << i+1 << " *" << razd[i].name << "*\n";
																	else 
						cout << i+1 << "  " << razd[i].name << "\n";

	

	if (key1==7) cout << 0 << " *" << razd[5].name << "*\n";
															else 
			 	cout << 0 << "  " << razd[5].name << "\n";
 
	razd[0].mass[0]="Back";                                                                                                               //принадлежит структуре с индексом

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

	bool F=true; // бульон Ф
	int w,x,y,z; //кейсовые

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
//круг
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
												if (key2==1)
															switch (z) {
																		case 13:
																				while(F==false){
																				cout << "------------------------------" << endl;
																				cout << " Add one new element" << endl;
																				cout << " New Element's Name:";
																				cin>>line;//название строки
																				set->Add(line);//добавление элемента в список
																				cout << " New Element added"<<endl;
																				cout << " Press 0 twice to return" << endl;
																				cout << "------------------------------" << endl;
																				system("pause");
																				newi++;
																				break;
																				}
																		case 48: break;

																		
												};
     
																
																
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
/*fixer
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
-first complete.
*/