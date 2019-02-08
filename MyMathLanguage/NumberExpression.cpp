#include "pch.h"
#include "NumberExpression.h"


NumberExpression::NumberExpression()
{
}

NumberExpression::NumberExpression(double number)
{
	this->number = number;
}


NumberExpression::~NumberExpression()
{
}

double NumberExpression::eval()
{
	return number;
}
