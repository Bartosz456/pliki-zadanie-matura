﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream plik("przyklad.txt");
	string dane;
	string wynik;

	int poz = 0;

	int ile = 0;
	int max = 0;

	while (getline(plik, dane))
	{
		char ins = dane[0];
		char param = dane[dane.length() - 1];
		char litera;
		string funkcja = dane;
		int kod;
		string litera_gotowa;
		char polecenie = ' ';
		char polecenie_max;

		cout << dane << '\n';

		if (ins == 'D')
		{
			wynik += param;
		}
		else if (ins == 'Z')
		{
			wynik[wynik.length() - 1] = param;
		}
		else if (ins == 'U')
		{
			wynik = wynik.erase(wynik.size() - 1, 1);
		}
		else if (ins == 'P')
		{
			litera = funkcja[8];
			kod = (int)litera;

			if (kod == 90)
			{
				kod = 65;
			}
			else
			{
				kod++;
			}

			litera_gotowa = (char)kod;

			poz = wynik.find(litera);

			wynik.replace(poz, 1, litera_gotowa);

		}
		cout << wynik << '\n';

		//ZAD 4.2 obliczanie najdluzszego ciagu instrukcji

		if (polecenie != dane[0])
		{
			if (ile > max)
			{
				max = ile;
				polecenie_max = polecenie;
				polecenie = dane[0];
				ile = 0;
			}
			else
			{
				polecenie = dane[0];
				ile++;
			}
		}


	}

	cout << "\n\nDlugosc lancucha: " << wynik.length() << endl;
	cout << "\nNajdluzszy ciag takich samych instrukcji: " << ile << endl;
	plik.close();

}