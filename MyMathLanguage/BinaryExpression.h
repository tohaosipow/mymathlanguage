#pragma once
#include "Expression.h"
#include "Lexem.h"
class BinaryExpression :
	public Expression
{
public:
	BinaryExpression(Expression* ex1, Expression*, OperationType op);
	~BinaryExpression();
	double eval();
private:
	Expression* ex1;
	Expression* ex2;
	OperationType op;
};

