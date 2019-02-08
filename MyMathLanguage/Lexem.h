#pragma once
#include<iostream>
enum LexemType {
	LT_NONE,
	LT_NUMBER,
	LT_VARIABLE,
	LT_OPERATION
};

enum OperationType
{
	OT_PLUS,
	OT_MINUS,
	OT_MULT,
	OT_DIV,
	OT_LBRACK,
	OT_RBRACK
};
class Lexem
{
public:
	Lexem();
	~Lexem();
	LexemType type;
	union {
		int number;
		OperationType operation;
	};
	char* read(char* str);	friend std::ostream& operator <<(std::ostream& in,
		const Lexem& lexem);	static bool isSpace(char* ch);	static char* missSpaces(char* str);

};

