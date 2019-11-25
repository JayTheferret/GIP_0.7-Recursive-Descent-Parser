#include <iostream>
#include <string>
#include "Prototypen.h"

using namespace std;

void match(char c,string& input, int& pos)
{
	cout << "Betrete match() fuer das Zeichen " << c << endl;

	if (unsigned(pos) >= input.length()) //wenn position größer als Input
	{
		cout << "Input-Zeichenkette zu kurz. "
			<< "Erwarte noch das Zeichen " << c << endl;
		cout << "Verlasse match(): " << endl;
	}

	if (input.at(pos) != c)
	{
		cout << "Fehler: an Position "
			<< pos << " erwarte "
			<< c << " und sehe " << input.at(pos) << endl;
		cout << "Verlasse match(): " << endl;

	}
	pos++; //eine position weitergehen

	cout << "Zeichen " << c << " konsumiert." << endl;
	cout << "Verlasse match() fuer das Zeichen "
		<< c << endl;
}

bool expect(char c, string& input, int pos)
{
	cout << "Teste auf das Zeichen " << c << endl;
	if (unsigned(pos) >= input.length()) //nach ende
	{
		cout << "Aber schon am Ende der Eingabe-Zeichenkette angelangt." << endl ; //damit kein U/O etc am ende-> nur ziffern
		return false; 
	}
	if (input.at(pos) == c) //zeichen gefunden
	{
		cout << "Zeichen " << c << " gefunden." << endl;
		return true; //weiter
	}
	else
	{
		cout << "Test auf " << c << " nicht erfolgreich. "
			<< "Stattdessen " << input.at(pos)
			<< " gesehen.\n";
		return false;
	}
}
