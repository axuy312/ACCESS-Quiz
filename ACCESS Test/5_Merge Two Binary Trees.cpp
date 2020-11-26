#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include "Tree.h"

using namespace std;


int main(int argc, char* argv[]) {
	string line;
	vector<string> map;
	if (argc == 2)
	{
		string line;
		ifstream inFile;
		inFile.open(argv[1]);
		if (!inFile)
		{
			cout << "File is not exist!";
			return 1;
		}
		getline(inFile, line);
		while (getline(inFile, line))
		{
			map.push_back(line);
		}
		inFile.close();
	}
	else
	{
		string line;
		cout << "Input(Double enter to end): \n";
		getline(cin, line);
		while (getline(cin, line))
		{
			if (line == "")
			{
				break;
			}
			map.push_back(line);
		}
	}

	int posX1, posX2;
	bool s = false;
	for (int i = 0; i < map[0].size(); i++)
	{
		if (map[0][i] != ' ')
		{
			if (s)
			{
				posX2 = i;
				break;
			}
			else
			{
				posX1 = i;
				s = true;
			}
		}
	}
	Tree tree1(map, posX1), tree2(map, posX2);
	tree1.merge(tree2);
	cout << "Merged tree:\n";
	tree1.DisplayTree();
	system("pause");
	return 0;
}