// MyMathLanguage.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Lexem.h"
#include "Parser.h"
#include <list>
using namespace std;

int main()
{
	char str[] = "2+2*2+2*5+10";
	list<Lexem*> ls = list<Lexem*>();
	char* ptr = str;
	while(true) {
		ls.push_back(new Lexem());
		ptr = (*ls.back()).read(ptr);
		if ((*ls.back()).type == LT_NONE) break;
	}
	Parser* p = new Parser(ls);
	list<Expression*> l = p->parse();
	cout << l.back()->eval();
	std::cout << std::endl;

	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
