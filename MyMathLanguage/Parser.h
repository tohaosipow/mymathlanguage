#pragma once
#include "Expression.h"
#include "Lexem.h"

#include <list>
using namespace std;

class Parser
{

public:
	Parser(list<Lexem*> lexems);
	~Parser();
	list<Expression*>parse();
private:
	int pos = 0;
	Expression* primary();
	Expression* unary();
	Expression* multy();
	Expression* addy();
	Expression* expression();
	list <Lexem*> lexems;
	list<Lexem*>::iterator currentLex;
	bool checkLexemType(LexemType type);
	Lexem* get();
	



};

