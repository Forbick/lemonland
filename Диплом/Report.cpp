#include "pch.h"
#include "Report.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include "resource.h"
#include <cctype>
#include <algorithm>
using namespace std;
ofstream fout;

/**
* @brief Функция открытия файла и записи стилей
********************************************************************
 Формальные параметры:
* \param [in] filename - адрес файла;
********************************************************************
 <p>Глобальные переменные:
*<p>CSS - Стиль документа;
*<p>Title - Стиль заголовка;
*<p>Field - Стиль подписи значения;
*<p>Value - Стиль значения;
*<p>Header_Table - Стиль шапки;
*<p>Cell_Header_Table - Стиль шапки таблицы;
*<p>Cell_Table - Стиль ячейки;
*<p>Hed_U_Tab - Стиль верхней границы шапки;
*<p>Hed_L_Tab - Стиль левой границы шапки;
*<p>Hed_D_Tab - Стиль нижней границы шапки;
*<p>Hed_R_Tab - Стиль правой границы шапки;
*<p>Cel_U_Tab - Стиль верхней границы ячейки;
*<p>Cel_L_Tab - Стиль левой границы ячейки;
*<p>Cel_D_Tab - Стиль нижней границы ячейки;
*<p>Cel_R_Tab - Стиль правой границы ячейки;
*<p>Cel_Bet - Стиль границы ячейки;
*<p>End_Tab - Стиль нижней границы таблицы.
********************************************************************
*/
void Report::open(string filename)
{
	fout.open(filename);
	TCHAR szTitle[255];
	LoadString(NULL, IDS_CSS, szTitle, 255);
	CSS = szTitle;
	LoadString(NULL, IDS_TITLE, szTitle, 255);
	Title = szTitle;
	LoadString(NULL, IDS_FIELD, szTitle, 255);
	Field = szTitle;
	LoadString(NULL, IDS_VALUE, szTitle, 255);
	Value = szTitle;
	LoadString(NULL, IDS_TABLE_NAME, szTitle, 255);
	Header_Table = szTitle;
	LoadString(NULL, IDS_TEXT_HED_CELL_TAB, szTitle, 255);
	Cell_Header_Table = szTitle;
	LoadString(NULL, IDS_TEXT_CELL_TAB, szTitle, 255);
	Cell_Table = szTitle;
	LoadString(NULL, IDS_HED_CELL_UP, szTitle, 255);
	Hed_U_Tab = szTitle;
	LoadString(NULL, IDS_HED_CELL_LEFT, szTitle, 255);
	Hed_L_Tab = szTitle;
	LoadString(NULL, IDS_HED_CELL_DOWN, szTitle, 255);
	Hed_D_Tab = szTitle;
	LoadString(NULL, IDS_HED_CELL_RIGHT, szTitle, 255);
	Hed_R_Tab = szTitle;
	LoadString(NULL, IDS_CELL_UP, szTitle, 255);
	Cel_U_Tab = szTitle;
	LoadString(NULL, IDS_CELL_LEFT, szTitle, 255);
	Cel_L_Tab = szTitle;
	LoadString(NULL, IDS_CELL_DOWN, szTitle, 255);
	Cel_D_Tab = szTitle;
	LoadString(NULL, IDS_CELL_RIGHT, szTitle, 255);
	Cel_R_Tab = szTitle;
	LoadString(NULL, IDS_CELL, szTitle, 255);
	Cel_Bet = szTitle;
	LoadString(NULL, IDS_END_TABLE, szTitle, 255);
	End_Tab = szTitle;
	rtf(CSS);
}

/**
* @brief Функция открытия файла и записи стилей
********************************************************************
 Формальные параметры:
* \param [in] filename - адрес файла;
* \param [in] filenam
********************************************************************
 <p>Глобальные переменные:
*<p>CSS - Стиль документа;
*<p>Title - Стиль заголовка;
*<p>Field - Стиль подписи значения;
*<p>Value - Стиль значения;
*<p>Header_Table - Стиль шапки;
*<p>Cell_Header_Table - Стиль шапки таблицы;
*<p>Cell_Table - Стиль ячейки;
*<p>Hed_U_Tab - Стиль верхней границы шапки;
*<p>Hed_L_Tab - Стиль левой границы шапки;
*<p>Hed_D_Tab - Стиль нижней границы шапки;
*<p>Hed_R_Tab - Стиль правой границы шапки;
*<p>Cel_U_Tab - Стиль верхней границы ячейки;
*<p>Cel_L_Tab - Стиль левой границы ячейки;
*<p>Cel_D_Tab - Стиль нижней границы ячейки;
*<p>Cel_R_Tab - Стиль правой границы ячейки;
*<p>Cel_Bet - Стиль границы ячейки;
*<p>End_Tab - Стиль нижней границы таблицы.
********************************************************************
*/
void Report::open(string filename, vector<string> css)
{
	cout << css.size();
	fout.open(filename);
	CSS = css[0];
	Title = css[1];
	Field = css[2];
	Value = css[3];
	Header_Table = css[4];
	Cell_Header_Table = css[5];
	Cell_Table = css[6];
	Hed_L_Tab = css[7];
	Hed_R_Tab = css[8];
	Hed_U_Tab = css[9];
	Hed_D_Tab = css[10];
	Cel_L_Tab = css[11];
	Cel_R_Tab = css[12];
	Cel_D_Tab = css[13];
	Cel_U_Tab = css[14];
	Cel_Bet = css[15];
	End_Tab = css[16];
	rtf(CSS);
}

/*!
\brief функция закрытия файла
*******************************************************************
 <p>Глобальная переменная:
 <p>fout - переменная класса ofstream.
*******************************************************************
*/
void Report::close()
{
	rtf( "}");
	fout.close();
}

void Report::title(string header, enum Align Al)
{
	string Alignment;
	Alignment = (Al == ALIGN_LEFT) ? "{\\ql" : (Al == ALIGN_CENTER) ? "{\\qc" : (Al == ALIGN_RIGHT) ? "{\\qr" : "{\\ql";
	rtf(Alignment + Title + header + "\\par}\n");
}

void Report::title(const char* header, enum Align Al)
{
	string Alignment;
	Alignment = (Al == ALIGN_LEFT) ? "{\\ql" : (Al == ALIGN_CENTER) ? "{\\qc" : (Al == ALIGN_RIGHT) ? "{\\qr" : "{\\ql";
	rtf(Alignment + Title + header + "\\par}\n");
}

/**
\brief функция написания заголовка
********************************************************************
* Формальные параметры:
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное числом.
*******************************************************************
* <p>Глобальная переменная:
* <p>fout - переменная класса ofstream.
********************************************************************
* <p>Локальная переменная:
* <p>Alignment - переменная указывающая выравнивание.
*******************************************************************
*/
void Report::title(string header,  int align)
{
	string Alignment;
	Alignment = (align == ALIGN_LEFT) ? "{\\ql" : (align == ALIGN_CENTER) ? "{\\qc" : (align == ALIGN_RIGHT) ? "{\\qr" : "{\\ql";
	rtf(Alignment + Title + header + "\\par}\n");
}

/**
\brief функция написания заголовка
********************************************************************
* Формальные параметры:
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное строкой.
*******************************************************************
*<p>Глобальная переменная:
*<p>fout - переменная класса ofstream.
********************************************************************
*<p>Локальная переменная:
*<p>Alignment - переменная указывающая выравнивание.
*******************************************************************
*/
void Report::title(string header, string align)
{
	int Alignment;
	transform(align.begin(), align.end(), align.begin(), tolower);
	Alignment = align == "left" ?  ALIGN_LEFT : align == "right" ? ALIGN_RIGHT : align == "center" ? ALIGN_CENTER : ALIGN_NO;		
	title(header, Alignment);
}

/**
\brief функция написания заголовка
********************************************************************
* Формальные параметры:
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное числом.
*******************************************************************
*<p>Глобальная переменная:
*<p>fout - переменная класса ofstream.
********************************************************************
*<p>Локальная переменная:
*<p>Alignment - переменная указывающая выравнивание.
*******************************************************************
*/
void Report::title(const char* header, int align)
{
	string Alignment;
	Alignment = (align == ALIGN_LEFT) ? "{\\ql" : (align == ALIGN_CENTER) ? "{\\qc" : (align == ALIGN_RIGHT) ? "{\\qr" : "{\\ql";
	rtf(Alignment + Title + header + "\\par}\n");
}

/**
\brief функция написания заголовка
********************************************************************
* Формальные параметры:
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное строкой.
*******************************************************************
*<p>Глобальная переменная:
*<p>fout - переменная класса ofstream.
********************************************************************
*<p>Локальная переменная:
*<p>Alignment - переменная указывающая выравнивание.
*******************************************************************
*/
void Report::title(const char* header, const char* align)
{
	int Alignment;
	string Al = align;
	transform(Al.begin(), Al.end(), Al.begin(), tolower);
	Alignment = Al=="left" ? ALIGN_LEFT : Al=="right" ? ALIGN_RIGHT : Al== "center" ? ALIGN_CENTER : ALIGN_NO;
	title(header, Alignment);
}

/**
\brief Функция создания таблицы
*******************************************************************
* Формальные параметры:
*\param[in] numcols - Количество столбцов;
*\param[in] title - Заголовок таблицы;
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное числом.
*******************************************************************
*<p>Глобальные переменные:
*<p>fout - переменная класса ofstream;
*<p>NumCols - Переменная для запоминания количества столбцов;
*<p>s1,s2,s3,s4 - Переменные отвечающие за стиль таблицы.
*******************************************************************
*<p>Локальные переменные:
*<p>Alignment - переменная указывающая выравнивание;
*<p>Current_Cell_Size Текущий размер ячейки;
*<p>Cell_Size Размер каждой ячейки;
*<p>Up - Верхняя линия;
*<p>Right - Правая линия;
*<p>Left - Левая линия;
*<p>LeftTol - Толщина левой линии;
*<p>RightTol - Толщина правой линии;
*<p>i - счетчик строк.
*******************************************************************
*/
void Report::table(int numcols, string title, string header[], int align)
{
	if (numcols != 0)
	{
		string Alignment;
		Alignment = (align == ALIGN_LEFT) ? "\\ql " : (align == ALIGN_CENTER) ? "\\qc " : (align == ALIGN_RIGHT) ? "\\qr " : " ";
		int Current_Cell_Pos = 0;
		int Cell_Size = MAX_SIZE / numcols; //Делим на кол-во столбцов, чтобы они были равны друг другу
		string Left, Right;
		rtf(Header_Table + Alignment + title + "\\b0\\par\n" + "{\\trowd\\trftsWidth2\\trwWidth5000\\ts15\\trgaph108\\trleft-108\n");
		for (int i = 0; i < numcols; i++)
		{
			Current_Cell_Pos = Current_Cell_Pos + Cell_Size - 5; //вычисляем следующую ячейку.
			Left = (i == 0) ? Hed_L_Tab : Cel_Bet;
			Right = (i == numcols - 1) ? Hed_R_Tab : Cel_Bet;
			rtf("\\clbrdrt" + Hed_U_Tab + "\\clbrdrl" + Left + "\\clbrdrb" + Hed_D_Tab + "\\clbrdrr" + Right + "\\cellx" + to_string(Current_Cell_Pos) + "\n");
		}
		for (int i = 0; i < numcols; i++)
		{
			rtf(Cell_Header_Table + header[i] + "\\cell ");
		}
		rtf("\\row}\n");
		NumCols = numcols;
		First_Line = 1;
	}
}

/**
\brief Функция создания таблицы
*******************************************************************
* Формальные параметры:
*\param[in] numcols - Количество столбцов;
*\param[in] title - Заголовок таблицы;
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное числом.
*******************************************************************
*<p>Локальная переменная:
*<p>Alignment - переменная указывающая выравнивание.
*******************************************************************
*/
void Report::table(int numcols, string title, string header[], string align)
{
		int Alignment;
		transform(align.begin(), align.end(), align.begin(), tolower);
		Alignment = align == "left" ? ALIGN_LEFT : align == "right" ? ALIGN_RIGHT : align == "center" ? ALIGN_CENTER : ALIGN_NO;
		table(numcols,title, header, Alignment);
}


/**
\brief Функция создания таблицы
*******************************************************************
* Формальные параметры:
*\param[in] numcols - Количество столбцов;
*\param[in] title - Заголовок таблицы;
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное числом.
*******************************************************************
*<p>Глобальные переменные:
*<p>fout - переменная класса ofstream;
*<p>NumCols - Переменная для запоминания количества столбцов;
*<p>s1,s2,s3,s4 - Переменные отвечающие за стиль таблицы.
*******************************************************************
*<p>Локальные переменные:
*<p>Alignment - переменная указывающая выравнивание;
*<p>Current_Cell_Size Текущий размер ячейки;
*<p>Cell_Size Размер каждой ячейки;
*<p>Up - Верхняя линия;
*<p>Right - Правая линия;
*<p>Left - Левая линия;
*<p>LeftTol - Толщина левой линии;
*<p>RightTol - Толщина правой линии;
*<p>i - счетчик строк.
*******************************************************************
*/
void Report::table(int numcols, const char * title, const char* header[], int align)
{
	if (NumCols != 0)
	{
		string Alignment;
		Alignment = (align == ALIGN_LEFT) ? "\\ql " : (align == ALIGN_CENTER) ? "\\qc " : (align == ALIGN_RIGHT) ? "\\qr " : " ";
		int Current_Cell_Pos = 0;
		int Cell_Size = MAX_SIZE / numcols; //Делим на кол-во столбцов, чтобы они были равны друг другу
		string Left, Right;
		rtf(Header_Table + Alignment + title + "\\b0\\par\n" + "{\\trowd\\ts15\\trgaph108\\trleft-108\n");
		for (int i = 0; i < numcols; i++)
		{
			Current_Cell_Pos = Current_Cell_Pos + Cell_Size - 5; //вычисляем следующую ячейку.
			Left = (i == 0) ? Hed_L_Tab : Cel_Bet;
			Right = (i == numcols - 1) ? Hed_R_Tab : Cel_Bet;
			rtf("\\clbrdrt" + Hed_U_Tab + "\\clbrdrl" + Left + "\\clbrdrb" + Hed_D_Tab + "\\clbrdrr" + Right + "\\cellx" + to_string(Current_Cell_Pos) + "\n");
		}
		for (int i = 0; i < numcols; i++)
		{
			rtf(Cell_Header_Table);
			rtf(header[i]);
			rtf("\\cell ");
		}
		rtf("\\row}\n");
		NumCols = numcols;
		First_Line = 1;
	}
}

/** 
\brief Функция создания таблицы
*******************************************************************
* Формальные параметры:
*\param[in] numcols - Количество столбцов;
*\param[in] title - Заголовок таблицы;
*\param[in] header - Заголовок отчёта;
*\param[in] align - Выравнивание текста заданное числом.
*******************************************************************
*<p>Локальная переменная:
*<p>Alignment - переменная указывающая выравнивание.
*******************************************************************
*/
void Report::table(int numcols, const char * title, const char * header[], const char * align)
{
	int Alignment;
	string Al = align;
	transform(Al.begin(), Al.end(), Al.begin(), tolower);
	Alignment = Al == "left" ? ALIGN_LEFT : Al == "right" ? ALIGN_RIGHT : Al == "center" ? ALIGN_CENTER : ALIGN_NO;
	table(numcols, title, header, Alignment);
}

/**
\brief Функция прямого вывода
*******************************************************************
* Формальный параметр:
*\param[in] s - Строка на вывод.
*******************************************************************
*<p>Глобальная переменная:
*<p>fout - переменная класса ofstream.
*******************************************************************
*/
void Report::rtf(string s)
{
	fout << s;
}

/**
\brief Функция прямого вывода
*******************************************************************
* Формальный параметр:
*\param[in] s - Число на вывод.
*******************************************************************
*<p>Глобальная переменная:
*<p>fout - Переменная класса ofstream.
*******************************************************************
*/
void Report::rtf(int s)
{
	fout << s;
}

/**
\brief Функция прямого вывода
*******************************************************************
* Формальный параметр:
*\param[in] s - Строка на вывод.
*******************************************************************
*<p>Глобальная переменная:
*<p>fout - Переменная класса ofstream.
*******************************************************************
*/
void Report::rtf(const char*s)
{
	fout << s;
}

/**
\brief Функция экранирования
*******************************************************************
* Формальный параметр:
*\param[in] s - Строка на экранирование.
*******************************************************************
*/
void Report::rtfa(string s)
{
	s = replaceAll(s, '\\',"\\\\");
	rtf(s);
}

/**
\brief Функция полного экранирования
*******************************************************************
* Формальный параметр:
*\param[in] s - Строка на экранирование.
*******************************************************************
*/
void Report::text(string s)
{
	s = replaceAll(s, '\\',"\\\\");
	s = replaceAll(s, '{',"\\{");
	s = replaceAll(s, '}',"\\}");
	rtf(s);
}

/**
\brief Функция экранирования
*******************************************************************
* Формальные параметры:
*\param[in] s - Строка на экранирование;
*\param[in] a - То что мы хотим заменить;
*\param[in] b - То на что мы хотим заменить;
*******************************************************************
*<p>Локальные переменные:
*<p>size - количество символов в сроке;
*<p>i - счётчик цикла.
*******************************************************************
*/
string Report::replaceAll(string s, char a, const char *b)
{
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		s[i] == a ? s.replace(i, 1, b), i++, size++ : 0;
	}
	return s;
}

/**
\brief Функция вывода изображения
*******************************************************************
* Формальный параметр:
*\param[in] filename - Адрес файла.
*******************************************************************
* <p>Локальнаые переменные:
* <p>byte - Переменная для чтения байтов из файла;
* <p>buffer - Беззнакоое представление переменной byte;
* <p>Hex_byte - Hex представление переменной buffer.
*******************************************************************
*/
void Report::img(string filename)
	{
	rtf("\\par{\\pict\\picw2709\\pich2709\\jpegblip\n");
	ifstream fin(filename, ios::binary);
	char byte;
	char Hex_byte[3];
	unsigned char buffer;
	while (fin.eof() == 0)
	{
		fin.read(&byte, sizeof(char));
		buffer = (unsigned char)byte;
		_itoa_s(buffer / 16, Hex_byte, 2, 16);
		_itoa_s(buffer % 16, (Hex_byte + 1), 2, 16);
		rtf(Hex_byte);
	}
	fin.close();
	rtf("}\\par\n");
	}

/**
\brief Функция перевода на новую строчку
*******************************************************************
*/
void Report::br()
{
	newline();
}

/**
\brief Функция перевода на новую строчку
*******************************************************************
*/
void Report::newline()
{
	rtf("\\par\n");
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке.
*******************************************************************
*/
void Report::field(string title, string value)
{
	field(title, value, 0, to_string(0));
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке;
*\param[in] newLine - Переход на новую строчку.
*******************************************************************
*/
void Report::field(string title, string value, bool newLine)
{
	field(title, value, newLine, 0);
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке;
*\param[in] indent - Отступ от левой границы.
*******************************************************************
*/
void Report::field(string title, string value, float indent)
{
	field(title, value, 0, to_string(indent));
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке;
*\param[in] newLine - Переход на новую строчку;
*\param[in] indent - Отступ от левой границы.
*******************************************************************
* <p>Глобальные переменные:
* <p> Field - Стиль подписи значения;
* <p> Value - Стиль значения.
*******************************************************************
* <p>Локальная переменная:
* <p>i - счетчик цикла.
*******************************************************************
*/
void Report::field(string title, string value, bool newLine, string indent)
{
	if (newLine ==1) newline();
	for (int i = 0; i < stoi(indent); i++) rtf(" ");
	rtf(Field + title + Value + value + "\\par}");
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке.
*******************************************************************
*/
void Report::field(const char * title, const char * value)
{
	field(title, value, 0, to_string(0));
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке;
*\param[in] newLine - Переход на новую строчку.
*******************************************************************
*/
void Report::field(const char * title, const char * value, bool newLine)
{
	field(title, value, newLine, 0);
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке;
*\param[in] indent - Отступ от левой границы.
*******************************************************************
*/
void Report::field(const char * title, const char * value, float indent)
{
	field(title, value, 0, to_string(indent));
}

/**
\brief Функция обрамления значения рамкой
*******************************************************************
* Формальные параметры:
*\param[in] title - Подпись к значению;
*\param[in] value - Значение в рамочке;
*\param[in] newLine - Переход на новую строчку;
*\param[in] indent - Отступ от левой границы.
*******************************************************************
* <p>Глобальные переменные:
* <p> Field - Стиль подписи значения;
* <p> Value - Стиль значения.
*******************************************************************
* <p>Локальная переменная:
* <p>i - счетчик цикла.
*******************************************************************
*/
void Report::field(const char * title, const char * value, bool newLine, string indent)
{
	if (newLine == 1) newline();
	for (int i = 0; i < stoi(indent); i++) fout << " ";
	rtf(Field);
	rtf(title);
	rtf(Value + value);
	rtf("\\par}");
}

/**
\brief Функция заполнения таблицы
*******************************************************************
* Формальные параметры:
*\param[in] size_mas - Количество элементов массива;
*\param[in] cols - Массив значений таблицы.
*******************************************************************
* <p>Глобальные переменные:
* <p>NumCols - Переменная для запоминания количества столбцов;
* <p>Cell_Table - Переменная содержащая стиль ячейки;
* <p>First_Line - Переменная, указывающая является ли выводимоя строка первой;
* <p>Cel_L_Tab - Стиль левой границы ячейки;
* <p>Cel_R_Tab - Стиль правой границы ячейки;
* <p>Cel_U_Tab - Стиль верхней границы ячейки;
* <p>Row_Flag - Флаг необходимый для закрытия таблицы;
* <p>Cel_Bet - Стиль границы ячейки между ячейками.
*******************************************************************
* <p>Локальные переменные:
* <p>Alignment - переменная указывающая выравнивание;
* <p>Current_Cell_Size Текущий размер ячейки;
* <p>Number_of_Lines - Количество строк;
* <p>Cell_Size Размер каждой ячейки;
* <p>Up - Верхняя линия;
* <p>Down - Нижняя линия;
* <p>Right - Правая линия;
* <p>Left - Левая линия;
* <p>j - Счетчик строк;
* <p>b - Порядковый номер элемента.
*******************************************************************
*/
void Report::rows(int size_mas, string cols[])
{
	if (NumCols != 0) 
	{
		int Current_Cell_Pos;
		int Cell_Size;
		double Number_of_Lines = ceil((size_mas + .0) / (NumCols + .0));//количество строк
		int b = 0;
		for (int i = 0; i < Number_of_Lines; i++)
		{
			Current_Cell_Pos = 0;
			Cell_Size = MAX_SIZE / NumCols;//Делим на кол-во столбцов, чтобы они были равны друг другу
			rtf("{\\trowd\\ts15\\trgaph108\\trleft-108\n");
			for (int j = 0; j < NumCols; j++)
			{
				Current_Cell_Pos = Current_Cell_Pos + Cell_Size - 5; //вычисляем следующую ячейку.
				Left = (j == 0) ? Cel_L_Tab : Cel_Bet;
				Right = (j == NumCols - 1) ? Cel_R_Tab : Cel_Bet;
				Down = (i == Number_of_Lines - 1) ? End_Tab : Cel_Bet;
				Up = (i == 0) ? Cel_U_Tab : Cel_Bet;
				rtf("\\clbrdrt" + Up + "\\clbrdrl" + Left + "\\clbrdrb" + Down + "\\clbrdrr" + Right + "\\cellx" + to_string(Current_Cell_Pos) + "\n");
			}
			for (int j = 0; j < NumCols; j++)
			{
				rtf(Cell_Table + cols[b] + "\\cell ");
				b++;
				if ((b == size_mas) or (b > size_mas))
				{
					for (int ij = b; ij < (Number_of_Lines*NumCols); ij++)
					{
						rtf("\\cell");
					}
					break;
				}
			}
			rtf("\\row}\n");
		}
		Row_Flag = 0;
	}
	
}

/**
\brief Функция заполнения строки таблицы
*******************************************************************
* Формальные параметры:
*\param[in] size_mas - Количество элементов массива;
*\param[in] cols - Массив значений таблицы.
*******************************************************************
* <p>Глобальные переменные:
* <p>fout - переменная класса ofstream;
* <p>NumCols - Переменная для запоминания количества столбцов;
* <p>Row_Line - Переменная для запоменания выводимой строки;
* <p>Cell - Переменная для запоменания выводимого стиля строки;
* <p>Cell_Table - Переменная содержащая стиль ячейки;
* <p>First_Line - Переменная, указывающая является ли выводимоя строка первой;
* <p>Cel_L_Tab - Стиль левой границы ячейки;
* <p>Cel_R_Tab - Стиль правой границы ячейки;
* <p>Cel_U_Tab - Стиль верхней границы ячейки;
* <p>Row_Flag - Флаг необходимый для закрытия таблицы;
* <p>Cel_Bet - Стиль границы ячейки между ячейками.
*******************************************************************
* <p>Локальные переменные:
* <p>Alignment - переменная указывающая выравнивание;
* <p>Current_Cell_Pos Текущий размер ячейки;
* <p>Cell_Size Размер каждой ячейки;
* <p>Up - Верхняя линия;
* <p>Down - Нижняя линия;
* <p>Right - Правая линия;
* <p>Left - Левая линия;
* <p>j - Счетчик строк;
* <p>b - Порядковый номер элемента.
*******************************************************************
*/
void Report::row(int size_mas, string cols[])
{
	if (NumCols != 0)
	{
		int Current_Cell_Pos = 0;
		int Cell_Size = MAX_SIZE / NumCols;//Делим на кол-во столбцов, чтобы они были равны друг другу
		int b = 0;
		if (First_Line == 0)
		{
			rtf(Cell);
			rtf(Row_Line);
		}
		Cell = "{\\trowd\\ts15\\trgaph108\\trleft-108\n";
		Row_Line = "";
		for (int j = 0; j < NumCols; j++)
		{
			Current_Cell_Pos = Current_Cell_Pos + Cell_Size - 5; //вычисляем следующую ячейку.
			Left = (j == 0) ? Cel_L_Tab : Cel_Bet;
			Right = (j == NumCols - 1) ? Cel_R_Tab : Cel_Bet;
			Up = (First_Line == 1) ? Cel_U_Tab : Cel_Bet;
			Cell = Cell + "\\clbrdrt" + Up + "\\clbrdrl" + Left + "\\clbrdrb" + Cel_Bet + "\\clbrdrr" + Right + "\\cellx" + to_string(Current_Cell_Pos) + "\n";
		}
		First_Line = 0;
		for (int j = 0; j < NumCols; j++)
		{
			Row_Line = Row_Line + Cell_Table + cols[b] + "\\cell ";
			b++;
			if ((b == size_mas) or (b > size_mas))
			{
				for (int ij = b; ij < (NumCols); ij++)
				{
					Row_Line = Row_Line + "\\cell";
				}
				break;
			}
		}
		Row_Line = Row_Line + "\\row}\n";
		Row_Flag = 1;
	}
}

/**
\brief Функция закрытия таблицы
*******************************************************************
* <p>Глобальные переменные:
* <p>NumCols - Переменная для запоминания количества столбцов;
* <p>Row_Line - Переменная для запоменания выводимой строки;
* <p>Cell - Переменная для запоменания выводимого стиля строки;
* <p>Row_Flag - Флаг необходимый для закрытия таблицы;
* <p>End_Tab - Стиль нижней границы таблицы;
* <p>Cel_L_Tab - Стиль левой границы ячейки;
* <p>Cel_R_Tab - Стиль правой границы ячейки;
* <p>Cel_Bet - Стиль границы ячейки между ячейками.
*******************************************************************
* <p>Локальные переменные:
* <p>Current_Cell_Pos Текущий размер ячейки;
* <p>Cell_Size Размер каждой ячейки;
* <p>j - Счетчик строк.
*******************************************************************
*/
void Report::endtable()
{
	if (NumCols != 0)
	{
		if (Row_Flag == 1)
		{
			Cell = "{\\trowd\\ts15\\trgaph108\\trleft-108\n";
			int Current_Cell_Pos = 0;
			int Cell_Size = MAX_SIZE / NumCols;//Делим на кол-во столбцов, чтобы они были равны друг другу
			for (int j = 0; j < NumCols; j++)
			{
				Current_Cell_Pos = Current_Cell_Pos + Cell_Size - 5; //вычисляем следующую ячейку.
				Left = (j == 0) ? Cel_L_Tab : Cel_Bet;
				Right = (j == NumCols - 1) ? Cel_R_Tab : Cel_Bet;
				Cell = Cell + "\\clbrdrt" + Cel_Bet + "\\clbrdrl" + Left + "\\clbrdrb" + End_Tab + "\\clbrdrr" + Right + "\\cellx" + to_string(Current_Cell_Pos) + "\n";
			}
			rtf(Cell);
			rtf(Row_Line);
		}
		rtf("\\pard}\n");
		NumCols = 0;
	}
}

