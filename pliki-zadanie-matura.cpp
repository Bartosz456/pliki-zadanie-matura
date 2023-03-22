#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream plik("przyklad.txt");
	string dane;
	string wynik;
	string alf;
	
	int poz = 0;

	int znak = 65;  // ASC II
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (i != 'Q' && i != 'V' && i != 'X')
		{

		znak = i;
		alf += (char)znak;
		//cout << i << "    " << (char)znak << endl;
		}
	}

	while (getline(plik,dane))
	{
		char ins = dane[0];
		char param = dane[dane.length() - 1];

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
			wynik = wynik.substr(0, wynik[wynik.length() - 1]);
		}
		else if (ins == 'P')
		{
			poz = wynik.find('Z');

	
		}
		cout << wynik << '\n';
	}
	cout << alf<<endl;
	cout << alf.length()<<endl;
	cout << poz<<endl;
	
	plik.close();
}