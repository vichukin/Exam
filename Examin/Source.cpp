#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#define Endl endl
using namespace std;
class Admin//admin
{
	char* login = new char[255];
	char* password = new char[255];
	bool signin = false;
public:
	Admin()
	{
		//ddd
		/*strcpy_s(login,255, "admin");
		strcpy_s(password,255, "admin");
		Save();*/
	}
	bool getsignin()
	{
		return signin;
	}
	void Shifr()
	{
		for (size_t i = 0; i < strlen(login); i++)
		{
			login[i] = login[i] + 3;
		}
		for (size_t i = 0; i < strlen(password); i++)
		{
			password[i] = password[i] + 5;
		}
	}
	void Deshifr()
	{
		for (size_t i = 0; i < strlen(login); i++)
		{
			login[i] = login[i] - 3;
		}
		for (size_t i = 0; i < strlen(password); i++)
		{
			password[i] = password[i] - 5;
		}
	}
	void Save()
	{
		Shifr();
		ofstream out("admin.txt");
		out << "login:" << login << endl;
		out << "password:" << password << endl;
		out.close();
	}
	void Load()
	{
		char* line = new char[255];
		char filename1[] = "admin.txt";
		FILE* fp1;
		const char name1[7] = "login:";
		const char name2[10] = "password:";
		if ((fp1 = fopen(filename1, "r")) == NULL)
		{
			perror("Error file");
		}
		while (fgets(line, 255, fp1))
		{
			char buf[6];
			for (size_t i = 0; i < 6; i++)
			{
				buf[i] = line[i];
			}
			if (strstr(buf, name1) != NULL)
			{
				char* bufl = new char[strlen(line) - 6];
				for (size_t i = 6, j = 0; i < strlen(line) - 1; i++, j++)
				{
					bufl[j] = line[i];
					if (i == strlen(line) - 2)
					{
						bufl[j + 1] = '\0';
					}
				}
				strcpy_s(login, strlen(bufl) + 1, bufl);
				continue;
			}
			char buf1[9];
			for (size_t i = 0; i < 9; i++)
			{
				buf1[i] = line[i];
			}
			if (strstr(buf1, name2) != NULL)
			{
				char* bufp = new char[strlen(line) - 7];
				for (size_t i = 9, j = 0; i < strlen(line) - 1; i++, j++)
				{
					bufp[j] = line[i];
					if (i == strlen(line) - 2)
					{
						bufp[j + 1] = '\0';
					}
				}
				strcpy_s(password, strlen(bufp) + 1, bufp);
			}

		}

		fclose(fp1);
	}
	void Login()
	{
		Load();
		Deshifr();
		char* bufl = new char[255];
		char* bufp = new char[255];
		cout << "������� �����: ";
		cin.ignore();
		gets_s(bufl, 255);
		cout << "������� ������: ";
		gets_s(bufp, 255);
		if (strstr(bufl, login) != NULL && strstr(bufp, password) != NULL)
		{
			cout << "���� �������!" << endl << endl;
			signin = true;
		}
		else
		{
			cout << "�������� ����� ��� ������!" << endl << endl;
		}
	}
	void show()
	{
		cout << login << endl;
		cout << password << endl;
	}
	void Relogin()
	{
		cout << "������� ����� �����: ";
		cin.ignore();
		gets_s(login, 255);
		cout << "������� ����� ������: ";
		gets_s(password, 255);
		Save();
	}

};
class Guest
{
	
	string login;
	string password;
	bool signin = false;
	string FIO;
	string adres;
	string number;
	bool Fizikatest=false;
	bool Matemtest=false;
	int Fizikaocen = 0;
	int Matemocen = 0;
public:
	Guest() = default;
	void Show()
	{
		cout << "FIO: " << FIO << endl;
		cout << "adres: " << adres << endl;
		cout << "number: " << number << endl;
		cout << "�����: " << endl;
		cout << "������ - ";
		if (Fizikatest)
		{
			cout << "��������"<<endl<<"������: "<<Fizikaocen<<endl<<endl;
		}
		else
		{
			cout << "�� ��������" << endl << endl;
		}
		cout << "���������� - ";
		if (Matemtest)
		{
			cout << "��������" << endl << "������: " << Matemocen << endl << endl;
		}
		else
		{
			cout << "�� ��������" << endl << endl;
		}
	}
	bool getfizikatest()
	{
		return Fizikatest;
	}
	bool getmatemtest()
	{
		return Matemtest;
	}
	void Init()
	{
		
		cout << "������� ���: ";
		getline(cin, FIO);
		cout << "������� �����: ";
		getline(cin, adres);
		cout << "������� �����: ";
		getline(cin, number);
	}
	
	void Save()
	{
		
		fstream in("Guest.dat", ios::app | ios::binary);
		in.write((char*)this, sizeof(*this));
		in.close();
	}
	bool checkforlogin(char* ind, Guest* G)
	{
		
		for (size_t i = 0; i < Guest::Guestcount(); i++)
		{
			if (G[i].login == ind)
			{
				return true;
			}
		}
		return false;
	}
	bool checkforlogin(char* ind, vector<Guest> G)
	{

		for (auto it:G)
		{
			if (it.login == ind)
			{
				return true;
			}
		}
		return false;
	}
	void shifr(char*& l, char*& p)
	{
		for (size_t i = 0; i < strlen(l); i++)
		{
			l[i] = l[i] + 5;
		}
		for (size_t i = 0; i < strlen(l); i++)
		{
			l[i] = l[i] + 7;
		}
	}
	void Login(Guest* G)
	{
		char* bufl = new char[255];
		char* bufp = new char[255];
		cin.ignore();
		cout << "������� �����: ";
		gets_s(bufl, 255);
		cout << "������� ������: ";
		gets_s(bufp, 255);
		shifr(bufl, bufp);
		for (size_t i = 0; i < Guest::Guestcount(); i++)
		{
			if (check(G[i],bufl,bufp))
			{
				*this = G[i];
				signin = true;
				return;
			}

		}
		cout << "������������ ����� ��� ������!" << endl << endl;
	}
	bool check(Guest G,string login,string password)
	{
		return (login == G.login && password == G.password) ? true : false;
	}
	bool check(Guest G)
	{
		return (login == G.login && password == G.password) ? true : false;
	}
	void Load(int size)
	{
		fstream in("Guest.dat", ios::in | ios::binary);
		in.seekg(size * sizeof(Guest));
		in.read((char*)this, sizeof(*this));
		in.close();
	}
	void registr(Guest* G)
	{
		char* bufl = new char[255];
		char* bufp = new char[255];
		cin.ignore();
		cout << "������� �����: ";
		gets_s(bufl, 255);
		cout << "������� ������: ";
		gets_s(bufp, 255);
		shifr(bufl, bufp);
		if (checkforlogin(bufl,G) == false)
		{
			login = bufl;
			password = bufp;
			Init();
			Save();
		}
		else
		{
			cout << "����� �� ����������!" << endl << endl;
		}
	}
	void registr(vector<Guest> G)
	{
		char* bufl = new char[255];
		char* bufp = new char[255];
		cin.ignore();
		cout << "������� �����: ";
		gets_s(bufl, 255);
		cout << "������� ������: ";
		gets_s(bufp, 255);
		shifr(bufl, bufp);
		if (checkforlogin(bufl, G) == false)
		{
			login = bufl;
			password = bufp;
			Init();
			Save();
		}
		else
		{
			cout << "����� �� ����������!" << endl << endl;
		}
	}
	bool getsignin()
	{
		return signin;
	}
	void setocenkafiz(int a)
	{
		Fizikaocen = a;
	}
	void setocenkamatem(int a)
	{
		Matemocen = a;
	}
	void SetFizika()
	{
		Fizikatest = true;
	}
	void Setmatem()
	{
		Matemtest = true;
	}
	int getFizikaocen()
	{
		return Fizikaocen;
	}
	int getMatemocen()
	{
		return Matemocen;
	}
	static int Guestcount();
};
class Vopros
{
	string msg;
	string a;
	string b;
	string c;
	string d;
	int otvet;
public:
	Vopros(string _msg, string _a, string _b, string _c, string _d,int _otvet) :msg(_msg), a(_a), b(_b), c(_c), d(_d),otvet(_otvet)
	{}
	Vopros() = default;
	void Show()
	{
		cout << msg << endl;
		cout << "1 - "<<a<<"   | " << "2 - " << b << "   | " << "3 - " << c << "   | " << "4 - " << d << "    "<<endl;
	}
	bool checkotv(int a)
	{
		return (a == otvet) ? true : false;
	}
	Vopros operator()(string _msg, string _a, string _b, string _c, string _d, int _otvet)
	{
		msg=_msg;
		a=_a;
		b=_b;
		c=_c;
		d=_d;
		otvet=_otvet;
		return *this;
	}
};
void Fizika(Guest& G)
{
	vector<Vopros> V;
	Vopros buf("������� ��� ��������(V)", "V=S/t", "V=S*t", "V=t/S", "��� ����������� ������", 1);
	V.push_back(buf);
	buf("������ ����� �������", "m=a/F", "F=m*a", "F=m/a", "4 - a=m/F", 2);
	V.push_back(buf);
	buf("����� ��������� � ����?", "100��/�^3", "1000��/�^3", "10000��/�^3", "10��/�^3", 2);
	V.push_back(buf);
	buf("������� ������� ������ �� ��������� 60��/��� �� 2.5 ����?", "57.5��", "24��", "150��", "62.5��", 3);
	V.push_back(buf);
	buf("����� ���","U=R/i","R=I/U","F=U*R","F=U/R",4);
	V.push_back(buf);
	int buff = 0;
	for (auto it:V)
	{
		it.Show();
		bool GG = false;
		while (!GG)
		{
			int h;
			cin >> h;
			switch (h)
			{
			case 1:
			{
				if(it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			case 2:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			case 3:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			case 4:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			default:
			{
				cout << "������ ������ ���! ��������� ��� ���!" << endl;
			}
			}
		}
	}
	int pr = 100 * buff / V.size();
	int ocen = 12 * buff / V.size();
	cout << "�� �������� ��������� �� " << buff << " ��������"<<endl<<"���� ������: "<<ocen<<Endl<<"������� ���������� �������: "<<pr<<"%"<<endl<<endl;
	G.SetFizika();
	G.setocenkafiz(ocen);
	
}
void Matem(Guest& G)
{
	vector<Vopros> V;
	Vopros buf("����������� �������� ����� p", "p=4", "p=3.14", "p=3.56", "p=2", 2);
	V.push_back(buf);
	buf("������� ��� ���������� ������� ��������������", "S=a*b", "S=2R", "S=d", "4 - S=a*a", 1);
	V.push_back(buf);
	buf("����� ������� �����, ���� ��� ������ ��������� 4", "2", "8", "16", "0", 2);
	V.push_back(buf);
	buf("x^2-2x-3=0", "x=3,x=1", "x=-3,x=1", "x=2", "x=3,x=-1", 4);
	V.push_back(buf);
	buf("6x=18", "x=3", "x=12", "x=24", "x=108", 1);
	V.push_back(buf);
	int buff = 0;
	for (auto it : V)
	{
		it.Show();
		bool GG = false;
		while (!GG)
		{
			int h;
			cin >> h;
			switch (h)
			{
			case 1:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			case 2:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			case 3:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			case 4:
			{
				if (it.checkotv(h))
					buff++;
				GG = true;
				break;
			}
			default:
			{
				cout << "������ ������ ���! ��������� ��� ���!" << endl;
			}
			}
		}
	}
	int pr = 100 * buff / V.size();
	int ocen = 12 * buff / V.size();
	cout << "�� �������� ��������� �� " << buff << " ��������" << endl << "���� ������: " << ocen << Endl << "������� ���������� �������: " << pr << "%" << endl << endl;
	G.Setmatem();
	G.setocenkamatem(ocen);
}
void adminmenu(Admin& A)
{
	for (;;)
	{
		bool FF = false;
		int h;
		cout << "�������� ��������: " << endl << "1 - C������ ������" << endl<<"2 - ���������� ����������"<<endl<<"3 - ���������� �� ������"<<endl << "����� ������ ����� �����" << endl;
		cin >> h;
		switch (h)
		{
		case 1:
		{
			A.Relogin();
			break;
		}
		case 2:
		{
			
			for (;;)
			{
				int size = Guest::Guestcount();
				Guest* Allguests = new Guest[size];
				for (size_t i = 0; i < size; i++)
				{
					Allguests[i].Load(i);
				}
				vector<Guest> ALLG;
				for (size_t i = 0; i < size; i++)
				{
					ALLG.push_back(Allguests[i]);
				}
				bool FF = false;
				int h;
				cout << "�������� ��������: " << endl << "1 - ������� ����"<<endl << "2 - �������������" << endl << "3 - ��������" << endl << "4 - �������" << endl << "����� ������ ����� �����" << endl;
				cin >> h;
				switch (h)
				{
				case 1:
				{
					int j = 0;
					for (auto it : ALLG)
					{
						cout << "������� " << j + 1 << ": "<<endl;
						it.Show();
						j++;
					}
					break;
				}
				case 2:
				{
					cout << "������� ����� ��������: ";
					int g;
					cin >> g;
					g--;
					if (g<0 || g>size)
					{
						cout << "�������� �����! " << endl << endl;
					}
					else
					{
						auto it = ALLG.begin();
						advance(it, g);
						cin.ignore();
						it->Init();
						ofstream in("Guest.dat", ios::trunc | ios::binary);
						in.close();
						for (auto it : ALLG)
						{
							it.Save();
						}
					}
					break;
				}
				case 3:
				{
					Guest G;
					
					G.registr(ALLG);
					break;
				}
				case 4:
				{
					cout << "������� ����� ��������: ";
					int g;
					cin >> g;
					g--;
					if (g<0 || g>size)
					{
						cout << "�������� �����! " << endl << endl;
					}
					else
					{
						auto it = ALLG.begin();
						advance(it, g);
						ALLG.erase(it);
						ofstream in("Guest.dat", ios::trunc | ios::binary);
						in.close();
						for (auto it : ALLG)
						{
							it.Save();
						}
					}
					break;
				}
				default:
				{
					FF = true;
					break;
				}
				}
				if (FF == true)
				{
					break;
				}
			}
			

			break;
		}
		case 3:
		{
			int size = Guest::Guestcount();
			Guest* Allguests = new Guest[size];
			for (size_t i = 0; i < size; i++)
			{
				Allguests[i].Load(i);
			}
			vector<Guest> ALLG;
			for (size_t i = 0; i < size; i++)
			{
				ALLG.push_back(Allguests[i]);
			}
			int sumf(0), sumM(0), sum(0), maxf(0), minf(100), maxm(0), minm(100);
			int counterf = 0;
			int counterm = 0;
			for (auto it : ALLG)
			{
				if (it.getfizikatest())
				{
					counterf++;
					sumf += it.getFizikaocen();
					if (maxf < it.getFizikaocen())
					{
						maxf = it.getFizikaocen();
					}
					if (minf > it.getFizikaocen())
					{
						minf = it.getFizikaocen();
					}
					sum += it.getFizikaocen();
				}
				if (it.getmatemtest())
				{
					counterm++;
					sumM += it.getMatemocen();
					if (maxm < it.getMatemocen())
					{
						maxm = it.getMatemocen();
					}
					if (minm > it.getMatemocen())
					{
						minm = it.getMatemocen();
					}
					sum += it.getMatemocen();


				}
			}
			cout << "����� ������ - " << size * 2 << " �� ��� " << size << " ������ � " << size << " ����������." << endl;
			cout << "����� ��������� ������ - " << counterf + counterm << " ������� ��� �� ��� ����� - " << (double)(sum / (counterf + counterm)) << endl;
			cout << "��������� ������ �� ������ - " << counterf << " � ��� " << (int)(100 * counterf / size) << "% �� ���� ������." << " ������� ��� - " << (double)(sumf / counterf) << ". ����� ������� ��� - " << maxf << ". ����� ������ - " << minf << endl;
			cout << "��������� ������ �� ���������� - " << counterm << " � ��� " << (int)(100 * counterm / size) << "% �� ���� ������" << " ������� ��� - " << (double)(sumM / counterm) << ". ����� ������� ��� - " << maxm << ". ����� ������ - " << minm << endl;
			ofstream out("stat.txt");
			out << "����� ������ - " << size * 2 << " �� ��� " << size << " ������ � " << size << " ����������." << endl;
			out << "����� ��������� ������ - " << counterf + counterm << " ������� ��� �� ��� ����� - " << (double)(sum / (counterf + counterm)) << endl;
			out << "��������� ������ �� ������ - " << counterf << " � ��� " << (int)(100 * counterf / size) << "% �� ���� ������." << " ������� ��� - " << (double)(sumf / counterf) << ". ����� ������� ��� - " << maxf << ". ����� ������ - " << minf << endl;
			out << "��������� ������ �� ���������� - " << counterm << " � ��� " << (int)(100 * counterm / size) << "% �� ���� ������" << " ������� ��� - " << (double)(sumM / counterm) << ". ����� ������� ��� - " << maxm << ". ����� ������ - " << minm << endl;
			out.close();
			break;
		}
		default:
		{
			FF = true;
			break;
		}
		}
		if (FF == true)
		{
			break;
		}
	}
}
void Resave(Guest& G, Guest*& Allguest)
{
	int n = Guest::Guestcount();
	ofstream in("Guest.dat", ios::trunc | ios::binary);
	in.close();
	for (size_t i = 0; i < n; i++)
	{
		if (Allguest[i].check(G))
		{
			Allguest[i] = G;
		}
		Allguest[i].Save();
	}
}
void choosetest(Guest& G)
{
	if (G.getfizikatest() && G.getmatemtest())
	{
		cout << "����� ��������! ������ ������ ���������� � �������!"<<endl<<endl;
	}
	else if (!G.getfizikatest() && !G.getmatemtest())
	{
		cout << "1 - ������" << endl << "2 - ����������" << endl;
		int g;
		cin >> g;
		switch (g)
		{
		case 1:
		{
			Fizika(G);
			break;
		}
		case 2:
		{
			Matem(G);
			break;
		}
		default:
			break;
		}
	}
	else if (!G.getfizikatest() && G.getmatemtest())
	{
		cout << "1 - ������" << endl;
		int g;
		cin >> g;
		switch (g)
		{
		case 1:
		{
			Fizika(G);
			break;
		}
		default:
			break;
		}
	}
	else if (G.getfizikatest() && !G.getmatemtest())
	{
		cout << "1 - ����������" << endl;
		int g;
		cin >> g;
		switch (g)
		{
		case 1:
		{
			Matem(G);
			break;
		}
		default:
			break;
		}
	}
}
void guestmenu(Guest& G, Guest* &Allguest)
{
	for (;;)
	{
		bool FF = false;
		int h;
		cout << "�������� ��������: " << endl << "1 - ����������� ���� ������" <<endl<<"2 - ������ ����"<<endl << "����� ������ ����� �����" << endl;
		cin >> h;
		switch (h)
		{
		case 1:
		{
			G.Show();
			break;
		}
		case 2:
		{
			choosetest(G);
			Resave(G, Allguest);
			break;
		}
		default:
		{
			FF = true;
			break;
		}
		}
		if (FF == true)
		{
			break;
		}
	}
	
}
int Guest::Guestcount()
{
	fstream in("Guest.dat", ios::in | ios::binary);
	in.seekg(0, ios::end);
	int k = (int)(in.tellg() / sizeof(Guest));
	in.close();
	return k;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	
	Admin A;
	
	Guest G;
	for (;;)
	{
		
		bool FF = false;
		int n;
		cout << "�������� ��������: " << endl << "1 - �����" << endl << "2 - �����" << endl << "����� ������ ����� �����" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "������� � �������(�� ��������� admin admin): " << endl;
			A.Login();
			if (A.getsignin())
			{
				adminmenu(A);
			}
			break;
		}
		case 2:
		{
			
			for (;;)
			{
				int size = Guest::Guestcount();
				Guest* Allguests = new Guest[size];
				/*vector <Guest> Allguests(size);
				int j = 0;
				for (auto it : Allguests)
				{
					it.Load(j);
					j++;
				}*/
				for (size_t i = 0; i < size; i++)
				{
					Allguests[i].Load(i);
				}
				
				bool FF = false;
				int h;
				cout << "�������� ��������: " << endl << "1 - �����" << endl << "2 - ������������������" << endl << "����� ������ ����� �����" << endl;
				cin >> h;
				switch (h)
				{
				case 1:
				{
					G.Login(Allguests);
					if (G.getsignin())
					{
						guestmenu(G,Allguests);
					}
					break;
				}
				case 2:
				{
					G.registr(Allguests);
					break;
				}
				default:
				{
					FF = true;
					break;
				}
				}
				if (FF == true)
				{
					break;
				}
			}
			break;
		}
		default:
		{
			FF = true;
			break;
		}
		}
		if (FF == true)
		{
			break;
		}
	}
}