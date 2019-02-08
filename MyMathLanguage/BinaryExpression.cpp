#include "pch.h"
#include "BinaryExpression.h"


BinaryExpression::BinaryExpression(Expression * ex1, Expression * ex2, OperationType op)
{
	this->ex1 = ex1;
	this->ex2 = ex2;
	this->op = op;
}

BinaryExpression::~BinaryExpression()
{
}

double BinaryExpression::eval()
{
	switch (op)
	{
	case OT_PLUS:
		return ex1->eval() + ex2->eval();
		break;
	case OT_MINUS:
		return ex1->eval() - ex2->eval();
		break;
	case OT_MULT:
		return ex1->eval() * ex2->eval();
		break;
	case OT_DIV:
		return ex1->eval() / ex2->eval();
		break;
	default:
		return ex1->eval() + ex2->eval();
		break;
	}
	return 0.0;
}
