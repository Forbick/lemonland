
#pragma once
#include <string>
#include <vector>
using namespace std;


/**
 @brief Родительский класс, содержащий все основные функции
*/
class Report
{
private:
	string s1, s2, s3, s4;
	int NumCols;//Переменная для запоминания количества столбцов последней созданной таблицы с помощью функции table
	int First_Line;
	string Title;
	string Field;
	string Value;
	string Cell_Header_Table;
	string Cell_Table;
	string CSS;
	string Header_Table;
	string Row_Line;
	string Cell;
	string Left, LeftTol, RightTol, UpTol, DownTol, Right, Down, Up;
	string Hed_L_Tab, Hed_R_Tab, Hed_U_Tab, Hed_D_Tab, Cel_L_Tab, Cel_R_Tab, Cel_D_Tab, Cel_U_Tab, End_Tab, Cel_Bet;
	int Row_Flag;

public:
	/*! ENUM Для выравниваиня текста */
	enum Align {
		ALIGN_LEFT, ///<Значение для выравнивания по левому краю.
		ALIGN_CENTER, ///Значение для выравнивания по центу.
		ALIGN_RIGHT, ///<Значение для выравнивания по правому краю.
		ALIGN_NO = 0, ///<Значение для текста без выравниваия.
		ALIGN_NONE = 0 ///<Значение для текста без выравниваия.
	};

    #define row_macro(a) (p.row(sizeof(a) / sizeof(a[0]), a))
	#define rows_macro(a) (p.rows(sizeof(a) / sizeof(a[0]), a))
	#define table_macro(a,b,c) (p.table(sizeof(b) / sizeof(b[0]), a, b, c))
	#define table_macros(a,b) (p.table(sizeof(b) / sizeof(b[0]), a, b))

	const int MAX_SIZE = 9350;//!<Константа макс размера ячейки
	const int ALIGN_L = 0;//!<Константа для выравнивания по левому краю
	const int ALIGN_C = 1;//!<Константа для выравнивания по центру
	const int ALIGN_R = 2;//!<Константа для выравнивания по правому краю

	void open(string filename);
	void open(string filename, vector<string> css);
	void close();

	void title(string header, enum Align Al);
	void title(string header, int align=ALIGN_NO);
	void title(string header, string align);
	void title(const char* header, enum Align Al);
	void title(const char* header, int align=ALIGN_NO);
	void title(const char* header, const char* align);

	void table(int numcols, string title, string header[], int align=ALIGN_NO);
	void table(int numcols, string title, string header[], string align);
	//void table(int numcols, string title, string header[], enum Align Al);
	void table(int numcols, const char * title, const char * header[], int align=ALIGN_NO);
	void table(int numcols, const char * title, const char * header[], const char * align);
	//void table(int numcols, const char * title, const char * header[], enum Align Al);
	void endtable();

	void rtf(string s);
	void rtf(int s);
	void rtf(const char*s);
	void rtfa(string s);
	void text(string s);
	string replaceAll(string s, char a, const char *b);
	void br();
	void newline();

	void field(string title, string value);
	void field(string title, string value, bool newLine);
	void field(string title, string value, float indent);
	void field(string title, string value, bool newLine, string indent);
	void field(const char * title, const char * value);
	void field(const char * title, const char * value, bool newLine);
	void field(const char * title, const char * value, float indent);
	void field(const char * title, const char * value, bool newLine, string indent);

	void img(string filename);

	void rows(int size_mas, string cols[]);
	void row(int size_mas, string cols[]);
};