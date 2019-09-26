/** 
\mainpage Дипломный проект
* Тема: "Разработка подистемы журналирования данных многофункциональной системы"
*  @author Комаров А.А.
*  @date 17.02.19
*  @version Версия: 1.0
*********************************************************************
*  Язык C++
* *******************************************************************
*  Задание:
*  В данном дипломном проекте стоит задача разработки
*  системы журналирования.
* *******************************************************************
*  Переменные, используемые в программе:
*  p - перменная класса Modul;
* *******************************************************************
*  Используемые функции:
*  open - функция открытия файла и записей стилей;
*  title - функция написания заголовка;
*  rtfa - функция экранирования;
*  rtf - функция прямого вывода;
*  text - функция полного экранирования;
*  table - функция создания таблицы;
*  field -функция вывода значения;
*  newline, br - перевод на новую строку;
*  img - вывод картинки;
*  close - функция закрытия файла.
* *******************************************************************
*/
#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Report.h"
#include <cstring>
#include <string>
#include <windows.h>
#include "resource.h"


using namespace std;
Report p;

int main()
{
	setlocale(0, "RUS");
	const char * sd = "Приложение 1";
	const char * ll = "Left";
	const char * rr = "Right";
	string alf[] = { "" };
	const char * cc = "Center";
	const char * tabble[] = { "Это","const char","Таблица" };
	string put = "Отчёт.rtf";
	string rat[] = { "Самолёт","Рейс","Спутник","Дата","Пассажиры","Экипаж"};
	string mas2[] = { "Самолёт","Рейс","Спутник" };
	string rett[] = { "a1","b1","c1","a2","b2","c2" };
	string rettttt[] = { "a1","b1","c1" };
	string rettt[] = { "Привет","b1","c1","d1","e1","f1","a2","b2","c2","d2","e2","f2","a3","b3","c3","d3","e3","f3","a4","b4","c4","d4","e4","f4" };
	string ret[] = { "Hello","b1","c1","d1","e1","f1","a2","b2","c2","d2","e2","f2","a3","b3","c3","d3","e3","f3","a4","b4","c4","d4" };
	string l = "Left";
	string r = "Right";
	string c = "Center";
	string sr = "Приложение 1";
	string sr1 = "Таблица 1";
	vector<string> vec = { "{\\rtf1\\ansi\\ansicpg1251\\deff0\\deflang1049{\\fonttbl{\\f0\\fnil\\fcharset204 times new roman;}{\\f1\\fnil\\fcharset204 lucida console;}{\\f2\\fnil\\fcharset204 courier new;}}\n{\\colortbl ;\\red0\\green176\\blue80;\\red255\\green0\\blue0;}\\viewkind4\\uc1\n","\\f1\\b\\cf1\\fs56 ","{\\pard\\cf0\\f40\\fs56 "," \\chbrdr\\brdrs\\brdrw10 \\hich\\af40\\loch\\f40 ","{\\pard\\f0\\b\\cf0\\fs20","\\fs40","\\fs30","\\brdrs\\brdrw120","\\brdrs\\brdrw120","\\brdrs\\brdrw120","\\brdrs\\brdrw120" ,"\\brdrs\\brdrw120","\\brdrs\\brdrw10" ,"\\brdrs\\brdrw10","\\brdrs\\brdrw10" ,"\\brdrs\\brdrw10","\\brdrs\\brdrw10" };
	string sr2 = "\\Вывод текста с обратной косой чертой\\";
	string sr3 = "{Левая ско{бка \\и правая скобка и слеш \\}";
	string sr4 = "Вывод текста без экранирования";
	string sr5 = "C:\\Users\\barar\\Desktop\\Диплом\\Диплом\\2.tif";
	string tttt = "Переменная х";
	string rrrr = "67";
	const char * ttt = "Переменная y";
	const char * rrr = "76";
	string h1 = "Original";
	string h2 = "Double";
	string h3 = "Fat";
	//////////////////////////////////////////////////
	p.open(put,vec);
	p.title(sr, p.ALIGN_RIGHT);
	p.table(3, sr1, mas2, p.ALIGN_CENTER);
	row_macro(rettttt);
	row_macro(rettttt);
	row_macro(rettttt);
	p.endtable();
	p.img(sr5);
	p.close();
	system("pause");
	return 0;
}