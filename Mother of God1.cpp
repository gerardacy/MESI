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

struct lalala{

	string la0;
	string la1;
	string la2;
	string la3;
	string la4;
	string la5;
	string la6;
	string la7;
	string la8;
	string la9;
	string la11;
	string la12;
};
struct Double{
   string d0;
   string d1;
   string d2;
   string d3;
   string d4;
   string d5;
   string d6;
   string d7;
   string d8;
   string d9;
   string d10;
   string d11;
   string d12;
};
struct Node{
	Node *next;
	string data;
	int id;
	Node *prev;//предыдущий
};
class Gloss{
	Node *first;
	int num;
public:
	Gloss():first(NULL){}
	void Add(string n){
		Node *current = first;
		Node *newlink = new Node;
		if (first==NULL){//если первый добавляем
			num=0;
			first=newlink;
			newlink->next=NULL;
			newlink->prev=NULL;
			newlink->data=n;
			newlink->id=num;
			num++;
		}else{
			while (current->next!=NULL) {//идем до последнего
				current=current->next;
			}
			current->next=newlink;//последний теперь указывает на новый
			first->prev=newlink;
			newlink->next=NULL;
			newlink->prev=current;
			newlink->data=n;
			newlink->id=num;
			num++;
		}
	}
	void addcenter (string n){
	Node *current = first;
	Node *newlink = new Node;
	Node *temporary= new Node;
		if(first == NULL)
		{
			num=0;
			newlink->data=n;
			newlink->id=num;
			newlink->next=NULL;
			newlink->prev=NULL;
			first=newlink;
			num++;
		}
		else{
			int number_of_elements=0;
			while (current)//идем до конца 
			{
				number_of_elements++;
				current=current->next;
			}
			current=first;
			int needed_el;
			if (number_of_elements%2 ==1)
			{
				needed_el=number_of_elements/2;
			}
			else 
			{
				needed_el=(number_of_elements-1)/2;
			}
			int shet=0;
			while(shet<needed_el+1)
			{
				if (shet == needed_el)
				{
					newlink->data=n;
					newlink->id=num;
					num++;
					newlink->next=current->next;
					newlink->prev=current;
					current->next=newlink;
				}
				shet++;
				current=current->next;
			}
		}
}
	void edit(int id2,string data2){
		Node *current = first;
		do {
			if(id2==(current->id)){
				current->data=data2;}
				current=current->next;
		} while (current!=NULL);
	}
	void Showfromfirst(){
		Node *current = first;
		if(current==NULL){cout<<endl<<endl<<"       Нет элементов!"<< endl<< endl;}else{
		do {
			cout<<"Id - " << current->id<<"   "<<current->data<<endl;
			current=current->next;
		} while (current!=NULL);}
	}
	void PrintToFile(){
		ofstream out;

		out.open("New List.txt");
		Node *current = first;
	do{
		//out<<current->id<<" "«current->data<<"\n";
		out<<current->data<<"\n";
		current=current->next;
	} while (current!=NULL);
	out.close();
	}

        void ExtractFromFile(Gloss *name){
			ifstream fin;
			string str;
			string paststring;//="meow";

			fin.open("New List.txt",ios::in);
			assert (!fin.fail( ));

		while (!fin.eof( )){
				fin >> str;
				if(str != paststring){
			name->Add(str);
			paststring=str;
			}
		}
		fin.close( );
		//assert(!fin.fail( ));
	}
		void Delete(){
			while(first!=NULL){
			Node *current=first;
			first=first->next;
			delete current;
			}
			first=NULL;
		}
};


int main()
{
	setlocale ( LC_ALL,"Russian" );
	srand(time(0));

	Gloss *tes=new Gloss;
	int i=0;
	string stroka;
	string strokanew;
	int id;

	int schetchik=0;


	lalala m;
	m.la0="  1. Работа с файлами ";
	m.la1="  2. Просмотр ";
	m.la2="  3. Добавление элемента ";
	m.la3="  4. Удаление элемента ";
	m.la4="  5. Редактирование элемента ";
	m.la5="  0. Exit ";
	m.la6="    0. Return ";
	m.la7="    1. Первый ";
	m.la8="    2. По ключу ";
	m.la9="    3. Средний ";
	m.la12="    2. Извлечь ";
	m.la11="    1. Сохранить ";

	Double a;
	a.d0="* 1. Работа с файлами";
	a.d1="* 2. Просмотр";
	a.d2="* 3. Добавление элемента";
	a.d3="* 4. Удаление элемента";
	a.d4="* 5. Редактирование элемента";
	a.d5="* 0. Exit";
	a.d6="  * 0. Return";
	a.d7="  * 1. Первый";
	a.d8="  * 2. По ключу";
	a.d9="  * 3. Средний";
	a.d10="   Not available";
	a.d12="  * 2. Извлечь ";
	a.d11="  * 1. Сохранить ";
	string kkk;
	int key;
	int s_i=0;
	int key2;
	int key3;
	int s_i2=0;
	int s_i3=0;
	int y;

	
	
	bool HG=true;
	bool MK=true;
	bool NF=true;
	while(HG==true){
		system("cls");
		MK=true;
		if(s_i==0){
			cout <<a.d0<<endl;}else{cout<<m.la0<<endl;}
		if(s_i==1){
			cout <<a.d1<<endl;}else{cout<<m.la1<<endl;}
		if(s_i==2){
			cout <<a.d2<<endl;}else{cout<<m.la2<<endl;}
		if(s_i==3){
			cout <<a.d3<<endl;}else{cout<<m.la3<<endl;}
		if(s_i==4){
			cout <<a.d4<<endl;}else{cout<<m.la4<<endl;}
		if(s_i==5){
			cout <<a.d5<<endl;}else{cout<<m.la5<<endl;}
			key=getch();
			switch (key){

			case 13:
				while(MK==true){
					system("cls");
					NF=true;
				if(s_i==0){
			cout<<m.la0<<endl;

			if(s_i2==1){cout<<a.d11<<endl;}else{cout<<m.la11<<endl;}
			if(s_i2==2){cout<<a.d12<<endl;}else{cout<<m.la12<<endl;}
			if(s_i2==3){cout<<a.d6<<endl;}else{cout<<m.la6<<endl;}
			}
				if(s_i==1){
					s_i2=3;
			cout<<m.la1<<endl;
			tes->Showfromfirst();
			if(s_i2==3){cout<<a.d6<<endl;}else{cout<<m.la6<<endl;}
			}

				if(s_i==2){	
			cout<<m.la2<<endl;
			if(s_i2==0){cout<<a.d7<<endl;}else{cout<<m.la7<<endl;}
			if(s_i2==1){cout<<a.d8<<endl;}else{cout<<m.la8<<endl;}
			if(s_i2==2){cout<<a.d9<<endl;}else{cout<<m.la9<<endl;}
			if(s_i2==3){cout<<a.d6<<endl;}else{cout<<m.la6<<endl;}
			}

				if(s_i==3){	
			cout<<m.la3<<endl;
			if(s_i2==0){cout<<a.d7<<endl;}else{cout<<m.la7<<endl;}
			if(s_i2==1){cout<<a.d8<<endl;}else{cout<<m.la8<<endl;}
			if(s_i2==2){cout<<a.d9<<endl;}else{cout<<m.la9<<endl;}
			if(s_i2==3){cout<<a.d6<<endl;}else{cout<<m.la6<<endl;}
			}

				if(s_i==4){				
			cout<<m.la4<<endl;
			if(s_i2==0){cout<<a.d7<<endl;}else{cout<<m.la7<<endl;}
			if(s_i2==1){cout<<a.d8<<endl;}else{cout<<m.la8<<endl;}
			if(s_i2==2){cout<<a.d9<<endl;}else{cout<<m.la9<<endl;}
			if(s_i2==3){cout<<a.d6<<endl;}else{cout<<m.la6<<endl;}
			}

				if(s_i==5){
					NF=true;
					while(NF==true){
						system("cls");
			cout << "     Вы уверены, что хотите выйти?" << endl;
			cout << "         ";
			if(s_i3==1){cout << "*yes*";}else{cout << " yes ";}
			cout << "    ";
			if(s_i3==0){cout << "*no*";}else{cout << " no ";}
			key3=getch();
			switch(key3){
			case 75:
				s_i3=1;
				break;
			case 77:
				s_i3=0;
				break;
			case 13:
				if(s_i3==1){
					system("cls");
					cout <<endl<<endl<<endl<< "      *  Спасибо за работу!  *";
					NF=false;
					HG=false;}else{NF=false;}
				break;
			case 27:
				s_i3=0;
				NF=false;
				break;
			}
			if(key3==48){s_i3=0;};
			if(key3==49){s_i3=1;};
				};
				}
			key2=getch();
				switch(key2){
			case 13: 
				if(s_i2==3){
					MK=false;
				};
				if(s_i2==0 && (s_i==0 || s_i==1)){
					MK=false;
				};
					if(s_i==0){
						if(s_i2==1){
						tes->PrintToFile();
						cout<<endl<<"Сохранено!"<<endl<<endl;
						system("pause");
						};
						if(s_i2==2){
							tes->Delete();
							tes->ExtractFromFile(tes);
						cout<<endl<<"Извлечено!"<<endl<<endl;
						system("pause");}
					};
					if(s_i2==0){
						if(s_i==2){system("cls"); cout <<a.d10<< endl<<endl; system("pause");}
						if(s_i==3){system("cls"); cout <<a.d10<< endl<<endl; system("pause");};
						if(s_i==4){system("cls"); cout <<a.d10<< endl<<endl; system("pause");};
					};
					if(s_i2==1){
						if(s_i==2){system("cls"); cout <<a.d10<< endl<<endl; system("pause");};
						if(s_i==3){system("cls"); cout <<a.d10<<endl<<endl; system("pause");};
						if(s_i==4){cout<<"Введите ключ - "; cin>>id; cout<<"Введите новое название - "; cin>>strokanew;
						tes->edit(id,strokanew);
						}
					};
					if(s_i2==2){
						if(s_i==2){
							cout << " Введите название элемента - ";
							cin>>stroka;//название строки
							tes->addcenter (stroka);//добавление элемента в список
							i++;

						};
						if(s_i==3){system("cls"); cout <<a.d10<< endl<<endl; system("pause");};
						if(s_i==4){system("cls"); cout <<a.d10<< endl<<endl; system("pause");};
					};
					
				break;
			case 72:
				s_i2--;
				break;
			case 80:
				s_i2++;
				break;
			case 27:
				MK=false;
				break;
				}
				if(s_i==0 && s_i2<=1){s_i2=1;};
				if(s_i2<0){s_i2=0;}
				if(s_i2>3){s_i2=3;}
				if(key2>48 && key2<53){
				s_i2=key2-49;
				if(s_i==0 && (s_i2==0 || s_i2==1)){s_i2=s_i2+1;};
				}
				if(key2==48){s_i2=3;}
				};
				break;
			case 72:
				s_i--;
				break;
			case 80:
				s_i++;
				break;
			case 27:
				s_i=5;
				if(s_i==5){
					NF=true;
					while(NF==true){
						system("cls");
			cout << "     Вы уверены, что хотите выйти?" << endl;
			cout << "         ";
			if(s_i3==1){cout << "*yes*";}else{cout << " yes ";}
			cout << "    ";
			if(s_i3==0){cout << "*no*";}else{cout << " no ";}
			key3=getch();
			switch(key3){
			case 75:
				s_i3=1;
				break;
			case 77:
				s_i3=0;
				break;
			case 13:
				if(s_i3==1){
					system("cls");
					cout <<endl<<endl<<endl<< "      *  Спасибо за работу!  *";
					NF=false;
					HG=false;}else{NF=false;}
				break;
			case 27:
				s_i3=0;
				NF=false;
				break;
			}
			if(key3==48){s_i3=0;};
			if(key3==49){s_i3=1;};
				}
					;}
				break;
			
			} 
			if(key>48 && key<54){
				s_i=key-49;
				}
			if(key==48){s_i=5;}
			if(s_i<0){s_i=0;}
			if(s_i>5){s_i=5;}

		}

//system("pause");
	return 0;
}

