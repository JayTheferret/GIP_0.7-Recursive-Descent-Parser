#include <iostream>
#include <string>
#include "Prototypen.h"

using namespace std;

void parse_gesamtausdruck(string& input, int& pos)
{
	cout << "Betrete parse_gesamtausdruck()" << endl;
	parse_ausdruck(input, pos); //greift auf ausdruck zu

	match('.', input, pos);

	cout << "Verlasse parse_gesamtausdruck()" << endl;
}

void parse_ausdruck(string& input, int& pos)
{
	cout << "Betrete parse_ausdruck()" << endl;

	parse_term(input, pos); //greift auf term zu

	//danach

	while (expect('U', input, pos) || expect('O', input, pos))
	{
		if (expect('U', input, pos))
		{
			cout << "Betrete parse_ausdruck(): U Fall" << endl;
			match('U', input, pos);
			parse_term(input, pos); 
			cout << "Verlasse parse_ausdruck(): U Fall" << endl;
		}
		else if (expect('O', input, pos))
		{
			cout << "Betrete parse_ausdruck(): O Fall" << endl;
			match('O', input, pos);
			parse_term(input, pos);
			cout << "Verlasse parse_ausdruck(): O Fall" << endl;
		}
	}

	cout << "Verlasse parse_ausdruck()" << endl;
}

void parse_term(string& input, int& pos)
{
	cout << "Betrete parse_term()" << endl;

	parse_operand(input, pos); //weiter mit operand

	while (expect('>', input, pos) || expect('<', input, pos))
	{
		if (expect('>', input, pos))
		{
			cout << "Betrete parse_term(): > Fall" << endl;
			match('>', input, pos);
			parse_operand(input, pos);
			cout << "Verlasse parse_term(): > Fall" << endl;
		}
		else if (expect('<', input, pos))
		{
			cout << "Betrete parse_term(): < Fall" << endl;
			match('<', input, pos);
			parse_operand(input, pos);
			cout << "Verlasse parse_term(): < Fall" << endl;
		}
	}

	cout << "Verlasse parse_term()" << endl;
}

void parse_operand(string& input, int& pos) //nur nach aufruf ausgeführt
{
	cout << "Betrete parse_operand()" << endl;

	if (expect('(', input, pos))
	{
		cout << "Betrete parse_operand(): () Fall" << endl;
		match('(', input, pos);
		parse_ausdruck(input, pos);

		match(')', input, pos);
		cout << "Verlasse parse_operand(): '()' Fall" << endl;
	}

	else
	{
		parse_number(input, pos);
	}

	cout << "Verlasse parse_operand()" << endl;
}

void parse_number(string& input, int& pos)
{
	cout << "Betrete parse_number()" << endl;

	//0-9

	if (expect('0', input, pos))
	{
		match('0', input, pos);
	}
	else if (expect('1', input, pos))
	{
		match('1', input, pos);
	}
	else if (expect('2', input, pos))
	{
		match('2', input, pos);
	}
	else if (expect('3', input, pos))
	{
		match('3', input, pos);
	}
	else if (expect('4', input, pos))
	{
		match('4', input, pos);
	}
	else if (expect('5', input, pos))
	{
		match('5', input, pos);
	}
	else if (expect('6', input, pos))
	{
		match('6', input, pos);
	}
	else if (expect('7', input, pos))
	{
		match('7', input, pos);
	}
	else if (expect('8', input, pos))
	{
		match('8', input, pos);
	}
	else if (expect('9', input, pos))
	{
		match('9', input, pos);
	}

	cout << "Verlasse parse_number()" << endl;
}
