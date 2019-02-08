#include "pch.h"
#include "Lexem.h"


Lexem::Lexem()
{
}


Lexem::~Lexem()
{
}

char * Lexem::read(char * str)
{
	char ch;
	str = missSpaces(str);
	if (*str == 0) {
		type = LT_NONE;
		return str;
	}
	ch = *str++;
	switch (ch)
	{
	case '+':{
		type = LT_OPERATION;
		operation = OT_PLUS;
		return str;
		break;
	}
	case '-': {
		type = LT_OPERATION;
		operation = OT_MINUS;
		return str;
		break;
	}
	case '/': {
		type = LT_OPERATION;
		operation = OT_DIV;
		return str;
		break;
	}
	case '*': {
		type = LT_OPERATION;
		operation = OT_MULT;
		return str;
		break;
	}
	case '(': {
		type = LT_OPERATION;
		operation = OT_LBRACK;
		return str;
		break;
	}
	case ')': {
		type = LT_OPERATION;
		operation = OT_RBRACK;
		return str;
		break;
	}
	case 'x': {
		type = LT_VARIABLE;
		return str;
	}

	}
	if (ch >= '0' && ch <= '9') {
		number = (ch - '0');
		ch = *str;
		while (ch >= '0' && ch <= '9') {
			number = 10 * number + (ch - '0');
			ch = *++str;
		}
		type = LT_NUMBER;
		return str;

	}
	return nullptr;
}

bool Lexem::isSpace(char * ch)
{
	return (*ch == ' ') || (*ch == '\t');
}

char * Lexem::missSpaces(char * str)
{
	while ((*str) != 0 && isSpace(str)) str++;
	return str;
}

std::ostream & operator<<(std::ostream & in, const Lexem & lexem)
{
	in << lexem.type;
	return in;
}
