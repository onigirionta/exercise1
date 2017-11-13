#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <stdlib.h> 
#include <ctype.h>
#include <algorithm>
#include <boost/tokenizer.hpp>
using namespace std;

int main(int argc, char const *argv[])
{
	string c;
	set<string> dictionary;			

	ifstream dic("english-upper.10");

    if(!dic) {
        cerr << "Dictionary not found." << endl;
        system("pause");
        return 1;
    }

	while (!dic.eof())
	{
		dic >> c;
		dictionary.insert (c);	
    }

    ifstream input("input.txt");

    if(!input) {
        cerr << "File not found." << endl;
        system("pause");
        return 1;
    }
    string instr;
	getline (input, instr, '\0');

    transform(instr.begin(), instr.end(), instr.begin(), ::tolower);
    cout << endl << instr;

    typedef boost::tokenizer<boost::char_separator<char> > Tok;
     boost::char_separator<char> sep; // default constructed
     Tok tok(instr, sep);
   for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
     std::cout << "<" << *tok_iter << "> ";
   std::cout << "\n";

    system("pause");

	return 0;
}