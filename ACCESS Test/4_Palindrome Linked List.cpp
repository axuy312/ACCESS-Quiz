#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;



list<string> DataSplit(const string str) {
	list<string>data;
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '-':
			break;
		case '>':
			data.push_back(tmp);
			tmp = "";
			break;
		case ' ':
			break;
		default:
			tmp += str[i];
			break;
		}
	}
	data.push_back(tmp);
	return data;
}

int main(int argc, char* argv[]) {
	string inputStr = "";
	list<string>inputList;
	
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
		getline(inFile, inputStr);
		inFile.close();
	}
	else
	{
		string line;
		cout << "Input: ";
		getline(cin, inputStr);
	}

	inputList = DataSplit(inputStr);
	int size = inputList.size(), cnt = 1;
	bool palindrome = true;
	for (list<string>::iterator it = inputList.begin(); it != inputList.end() && cnt <= size / 2; it++)
	{
		int cnt2 = size - 2 * cnt + 1;
		list<string>::iterator it2 = it;
		while (cnt2--)
		{
			it2++;
		}
		if (*it != *it2)
		{
			palindrome = false;
			break;
		}
		cnt++;
	}
	if (palindrome)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
	system("pause");
	return 0;
}