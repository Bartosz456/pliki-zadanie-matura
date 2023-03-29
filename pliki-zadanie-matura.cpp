#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream plik("przyklad.txt");
	string dane;
	string wynik;
	
	int poz = 0;

	while (getline(plik,dane))
	{
		char ins = dane[0];
		char param = dane[dane.length() - 1];
		char litera;
		string funkcja = dane;
		int kod;
		string litera_gotowa;

			

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

		//obliczanie najdluzszego ciagu instrukcji




		//cout << ins << " ";
	}

	cout << "\n\nDlugosc lancucha: " << wynik.length() << endl;
	
	plik.close();

}