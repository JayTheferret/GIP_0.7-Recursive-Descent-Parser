#include <iostream>
#include <string>
#include "Prototypen.h"

using namespace std;

int main()//grund ausführung --> wenn aufruf von funktion dann ausführung dessen
{
	int pos = 0;
	string input = "";

	cout << "Bitte geben Sie die Zeichenkette ein: ";
	getline(cin, input);

	parse_gesamtausdruck(input, pos); //greift auf parse_gesamtausdruck zurück

	if (pos != input.length()) //wenn ende nicht erreicht
	{
		cout << "ERROR! Noch Input-Zeichen uebrig." << endl;
	}

	system("PAUSE");
	return 0;
}
