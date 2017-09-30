#include <fstream>
#include <iostream>
#include <vector>
#include "Book.h"
#include <Windows.h>

using namespace std;

int check(string s)
{
	if (s.compare("Автор") == 0)
		return 0;
	else if (s.compare("Название") == 0)
		return 1;
	else if (s.compare("Раздел") == 0)
		return 2;
	else if (s.compare("Наличие") == 0)
		return 3;
	else if (s.compare("Оценка") == 0)
		return 4;
	else
		return -1;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	fstream f;
	f.open("books.txt", fstream::in);
	vector<Book> data;
	vector<Book*> result;
	int n = 0;
	while (true)
	{
		string author, title, section, inStock, value;
		f >> author >> title >> section >> inStock >> value;
		Book b(n, author, title, section, inStock, value);
		data.push_back(b);
		n++;
		if (f.eof())
			break;
	}
	f.close();
	while (true)
	{
		cout << "Введите команду или введите Помощь, чтобы просмотреть список команд.\n";
		string cmd;
		cin >> cmd;
		if (cmd.compare("Добавить") == 0)
		{
			cout << "Введите данные о книге. Для пробелов внутри полей используйте нижнее подчеркивание\n";
			string author, title, section, inStock, value;
			cin >> author >> title >> section >> inStock >> value;
			Book b(n, author, title, section, inStock, value);
			data.push_back(b);
			n++;
		}
		else if (cmd.compare("Изменить") == 0)
		{
			cout << "Введите id книги\n";
			int id;
			cin >> id;
			Book *cur = NULL;
			for (int i = 0; i < data.size(); i++)
				if (data[i].id() == id)
				{
					cur = &data[i];
					break;
				}
			if (cur == NULL)
			{ 
				cout << "Нет книги с таким id\n";
				continue;
			}
			cout << *cur;
			cout << "Введите новые данные о книге. Для пробелов внутри полей используйте нижнее подчеркивание\n";
			string author, title, section, inStock, value;
			cin >> author >> title >> section >> inStock >> value;
			cur->author(author);
			cur->title(title);
			cur->section(section);
			cur->inStock(inStock);
			cur->value(value);
		}
		else if (cmd.compare("Удалить") == 0)
		{
			cout << "Введите id книги\n";
			int id;
			cin >> id;
			bool ok = false;
			for (int i = 0; i < data.size(); i++)
				if (data[i].id() == id)
				{
					data.erase(data.begin() + i);
					ok = true;
					break;
				}
			for (int i = 0; i < result.size(); i++)
				if (result[i]->id() == id)
				{
					result.erase(result.begin() + i);
					break;
				}
			if (ok==false)
				cout << "Нет книги с таким id\n";
		}
		else if (cmd.compare("Запрос") == 0)
		{
			cout << "Введите параметр, по которому проводить запрос\n";
			string s;
			cin >> s;
			int res = check(s);
			if (res == -1)
			{
				cout << "Неверный параметр запроса\n";
				continue;
			}
			cout << "Введите запрос\n";
			cin >> s;
			result.clear();
			switch (res)
			{
			case 0:
				for (int i = 0; i < data.size(); i++)
					if (data[i].author().compare(s) == 0)
						result.push_back(&data[i]);
				break;
			case 1:
				for (int i = 0; i < data.size(); i++)
					if (data[i].title().compare(s) == 0)
						result.push_back(&data[i]);
				break;
			case 2:
				for (int i = 0; i < data.size(); i++)
					if (data[i].section().compare(s) == 0)
						result.push_back(&data[i]);
				break;
			case 3:
				for (int i = 0; i < data.size(); i++)
					if (data[i].inStock().compare(s) == 0)
						result.push_back(&data[i]);
				break;
			case 4:
				for (int i = 0; i < data.size(); i++)
					if (data[i].value().compare(s) == 0)
						result.push_back(&data[i]);
				break;
			default:
				break;
			}
			for (int i = 0; i < result.size(); i++)
			{
				cout << "такая книга есть" << endl;
				cout << result[i]->id() << ' ' << *(result[i]);

			}
		}
		else if (cmd.compare("Поиск") == 0)
		{
			cout << "Введите параметр, по которому проводить поиск\n";
			string s;
			cin >> s;
			int res = check(s);
			if (res == -1)
			{
				cout << "Неверный параметр поиска\n";
				continue;
			}
			cout << "Введите запрос\n";
			cin >> s;
			switch (res)
			{
			case 0:
				for (int i = 0; i < result.size(); i++)
					if (result[i]->author().compare(s) == 0)
						cout << result[i]->id() << ' ' << *(result[i]);
				break;
			case 1:
				for (int i = 0; i < result.size(); i++)
					if (result[i]->title().compare(s) == 0)
						cout << result[i]->id() << ' ' << *(result[i]);
				break;
			case 2:
				for (int i = 0; i < result.size(); i++)
					if (result[i]->section().compare(s) == 0)
						cout << result[i]->id() << ' ' << *(result[i]);
				break;
			case 3:
				for (int i = 0; i < result.size(); i++)
					if (result[i]->inStock().compare(s) == 0)
						cout << result[i]->id() << ' ' << *(result[i]);
				break;
			case 4:
				for (int i = 0; i < result.size(); i++)
					if (result[i]->value().compare(s) == 0)
						cout << result[i]->id() << ' ' << *(result[i]);
				break;
			default:
				break;
			}
		}
		else if (cmd.compare("Печать") == 0)
		{
			cout << "Введите id книги\n";
			int id;
			cin >> id;
			bool ok = false;
			for (int i = 0; i < data.size(); i++)
				if (data[i].id() == id)
				{
					cout << data[i].id() << ' ' << data[i];
					ok = true;
					break;
				}
			if (!ok)
				cout << "Нет книги с таким id\n";
		}
		else if (cmd.compare("Помощь") == 0)
		{
			fstream f;
			f.open("help.txt", fstream::in);
			string s;
			while (getline(f, s).good())
			{
				cout << s << endl;
			}
			f.close();
		}
		else if (cmd.compare("Выход") == 0)
			break;
		else
			cout << "Неверная команда! Введите Помощь, чтобы посмотреть список команд\n";
	}
	f.open("books.txt", fstream::out);
	for (int i = 0; i < data.size(); i++)
		f << data[i];
	f.close();
	return 0;
}