#pragma once
#include "Expression.h"
class NumberExpression :
	public Expression
{
public:
	NumberExpression();
	NumberExpression(double number);
	~NumberExpression();
	double eval();
private:
	double number;
};

