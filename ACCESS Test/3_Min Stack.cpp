#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "Stack.h"

using namespace std;

vector<string> DataSplit(const string str) {
	vector<string>data;
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '[':
			break;
		case ']':
			break;
		case '"':
			break;
		case ',':
			if (tmp == "")
			{
				tmp = "null";
			}
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
	if (tmp == "")
	{
		tmp = "null";
	}
	data.push_back(tmp);
	return data;
}

int main(int argc, char* argv[]) {
	string actionStr = "", valueStr = "";
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
		getline(inFile, actionStr);
		getline(inFile, valueStr);
		inFile.close();
	}
	else
	{
		string line;
		cout << "Input(Action array): ";
		getline(cin, actionStr);
		cout << "Input(Value array): ";
		getline(cin, valueStr);
	}

	vector<string> actions = DataSplit(actionStr);
	vector<string> values = DataSplit(valueStr);
	Stack minStack;

	cout << "[";
	int i = 0;
	while (true)
	{
		if (actions[i] == "MinStack")
		{
			cout << "null";
		}
		else if (actions[i] == "push")
		{
			minStack.push(stoi(values[i]));
			cout << "null";
		}
		else if (actions[i] == "pop")
		{
			minStack.pop();
			cout << "null";
		}
		else if (actions[i] == "top")
		{
			cout << minStack.top();
		}
		else if (actions[i] == "getMin")
		{
			cout << minStack.getMin();
		}
		if (++i < actions.size())
		{
			cout << ",";
		}
		else
		{
			break;
		}
	}
	cout << "]\n";
	system("pause");
	return 0;
}