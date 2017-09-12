#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	string c;
	map <string, int> dictionary;
	ifstream infile("english_words");

	int a=0;
	while (!infile.eof())
	{
		infile >> c;
		dictionary.insert (pair <string,int> (c,1));
    }

	return 0;
}