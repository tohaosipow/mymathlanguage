#include "pch.h"
#include "Parser.h"
#include "NumberExpression.h"
#include "BinaryExpression.h"
#include "Lexem.h"

Parser::Parser(list<Lexem*> lexems)
{
	this->lexems = lexems;
	currentLex = this->lexems.begin();
}


Parser::~Parser()
{
}

Expression* Parser::primary()
{
	Lexem* c_lexem = get();
	if (checkLexemType(LexemType::LT_NUMBER)) {
		return new NumberExpression((double)c_lexem->number);
	}
	return nullptr;
}

Expression* Parser::unary()
{
	Lexem* c_lexem = get();
	return primary();
}

Expression* Parser::multy()
{
	Lexem* c_lexem = get();
	Expression* expr = unary();
	while (true) {
		c_lexem = get();
		if (c_lexem->operation == OperationType::OT_MULT && checkLexemType(LexemType::LT_OPERATION)) {
			expr = new BinaryExpression(expr, unary(), c_lexem->operation);
			continue;
		}
		if (c_lexem->operation == OperationType::OT_DIV && checkLexemType(LexemType::LT_OPERATION) ) {
			expr = new BinaryExpression(expr, unary(), c_lexem->operation);
			continue;
		}
		break;
	}
	return expr;
}

Expression* Parser::addy()
{
	Lexem* c_lexem = get();
	Expression* expr = multy();
	while (true) {
		c_lexem = get();
		if (c_lexem->operation == OperationType::OT_PLUS && checkLexemType(LexemType::LT_OPERATION)) {
			expr = new BinaryExpression(expr, multy(), c_lexem->operation);
			continue;
		}
		if (c_lexem->operation == OperationType::OT_MINUS && checkLexemType(LexemType::LT_OPERATION)) {
			expr = new BinaryExpression(expr, multy(), c_lexem->operation);
			continue;
		}
		break;
	}
	return expr;
}

Expression * Parser::expression()
{
	Lexem* c_lexem = get();
	return addy();
}

bool Parser::checkLexemType(LexemType type)
{
	Lexem* c_lexem = get();
	if (c_lexem->type != type) return false;
	pos++;
	return true;
}

Lexem * Parser::get()
{
	int d = pos - distance(lexems.begin(), currentLex);
	advance(currentLex, d);
	return (*currentLex);
}

list<Expression*> Parser::parse()
{
	list<Expression*> exs = list<Expression*>();
	Lexem* c_lexem = get();
	while (c_lexem->type != LexemType::LT_NONE)
	{
		exs.push_back(expression());
		c_lexem = get();
		
	}
	return exs;
}

