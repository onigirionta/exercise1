#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <stdlib.h> 
#include <ctype.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string c;
    int debug=0;
	set<string> dictionary;			

	ifstream dic("english-upper.10"); //инициализация файловой переменной словаря

    if(!dic) {
        cerr << "Dictionary not found." << endl; //проверка наличия файла словаря
        system("pause");
        return 1;
    }

	while (!dic.eof())
	{
		dic >> c; 
		dictionary.insert (c);	//чтение из файла словаря в множество dictionary
        debug++;
    } 
    cout << endl << "Number of words in dictionary: " << debug << endl;

    ifstream row("input.txt"); //инициализация файловой перемнной row для текстового файла

    if(!row) {
        cerr << "File not found." << endl; //проверка наличия файла ввода
        system("pause");
        return 1;
    }
    string instr;
	getline (row, instr, '\0'); //чтение из файла ввода в строку instr

    transform(instr.begin(), instr.end(), instr.begin(), ::tolower); //перевод всей строки в нижний регистр
    cout << endl << instr; //вывод строкию ОТЛАДКА
    string word,inword;//строки для подсчета и для ввода новых слов
    istringstream in(instr);
    int j=-1; //
    do{
         in >> word;
         j++;
    } while(in);
    cout << endl <<j;

    istringstream inw(instr); //

    for(int i=0; i < j; i++){
        inw >> inword;
        cout << endl << inword;
    }


    cout << endl;
    system("pause");

	return 0;
}