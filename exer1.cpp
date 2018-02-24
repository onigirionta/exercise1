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

void underlining(string word, string data){
	size_t found = data.find(word);
	//cout << endl << "Found = " << found;
	//cout << endl << "length of word = " << word.length();
	for (int i = 0; i < found; i++){
		cout << " ";
		}
  
    for (int l = 0; l < word.length(); l++){
        cout << "^";
    }
    cout << "\r";
}

int main(int argc, char const *argv[])
{
	string c; //строка для чтения из файла в множество словаря
    int debug = 0; //контролько количества слов в словаре
	set<string> dictionary;		//множество словаря	

	ifstream dic("english-words.95"); //инициализация файловой переменной словаря

    if(!dic) {
        cerr << "Dictionary not found." << endl; //проверка наличия файла словаря
        system("pause");
        return 1;
    }

	while (!dic.eof())
	{
		dic >> c; 
        transform(c.begin(), c.end(), c.begin(), ::tolower);
		dictionary.insert (c);	//чтение из файла словаря в множество dictionary
        debug++;
    } 
    //cout << endl << "Number of words in dictionary: " << debug << endl;

    ifstream row("input.txt"); //инициализация файловой перемнной row для текстового файла

    if(!row) {
        cerr << "File not found." << endl; //проверка наличия файла ввода
        system("pause");
        return 1;
    }
    string instr; //строка для работы getline
    string word; //строка для обработки по слову
	while (getline (row, instr)){
            int under=0;//включение перехода на новую строку
            transform(instr.begin(), instr.end(), instr.begin(), ::tolower); //перевод всей строки в нижний регистр
            istringstream in(instr);
            cout << endl << instr; //вывод строки. ОТЛАДКА
            while (in >> word){
                //cout << endl << "\"" << word << "\""; //ОТЛАДКА. вывод слова из потока
                if (dictionary.find(word) != dictionary.end()){ 
                //cout << endl << "Existence"; //ОТЛАДКА. проверка наличия слова в словаре
                 }
                else {
                under++;
                if(under == 1){
                    cout << endl;
                }
                //cout << endl << "Nothing"; //ОТЛАДКА. проверка наличия слова в словаре
                underlining(word, instr);

                 }
             } //чтение из файла ввода в строку instr
     }

    cout << endl;
    system("pause");

	return 0;
}