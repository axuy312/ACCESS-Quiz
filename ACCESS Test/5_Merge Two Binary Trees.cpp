#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Tree
{
public:
	Tree(vector<string> m, int posX);
	~Tree();
	void DisplayTree() {
		for (int i = 0; i < map.size(); i++)
		{
			cout << map[i] << endl;
		}
	}
	void merge(Tree tree1) {
		if (tree.size() < tree1.tree.size())
		{
			tree.resize(tree1.tree.size());
			treeExist.resize(tree1.tree.size(), false);
		}
		for (int i = 0; i < tree.size(); i++)
		{
			tree[i] += tree1.tree[i];
			treeExist[i] = treeExist[i] | tree1.treeExist[i];
		}
		if (map.size() < tree1.map.size())
		{
			map.resize(tree1.map.size());
		}
		for (int i = 0; i < map.size(); i++)
		{
			if (map[i].size() < tree1.map[i].size())
			{
				map[i].resize(tree1.map[i].size(), ' ');
			}
			for (int j = 0; j < map[i].size(); j++)
			{
				if (tree1.map[i][j] != ' ')
				{
					if (map[i][j] == ' ')
					{
						map[i][j] = tree1.map[i][j];

					}
					else if(map[i][j] != '/' && map[i][j] != '\\')
					{
						string tmp = to_string((tree1.map[i][j] - '0') + (map[i][j] - '0'));
						for (int k = 0; k < tmp.size(); k++)
						{
							if (j + k > map[i].size())
							{
								map[i].push_back(tmp[k]);
							}
							else
							{
								map[i][j + k] = tmp[k];
							}
						}
					}
				}
				
			}
		}
	}
private:
	vector<string> map;
	vector<int>tree;
	vector<bool>treeExist;

	
	/*void BuildTree(int posX, int posY, int indexX, int indexY) {
		int offset = pow(2, indexY) - 1;
		treeExist[offset + indexX] = true;
		tree[offset + indexX] += (map[posY][posX] - '0');
		if (posY + 1 < map.size())
		{
			if (posX > 0 && map[posY + 1][posX - 1] == '/')
			{
				BuildTree(posX - 2, posY + 2, indexX * 2, indexY + 1);
			}
			if (posX < map[posY + 1].size() && map[posY + 1][posX + 1] == '\\')
			{
				BuildTree(posX + 2, posY + 2, indexX * 2 + 1, indexY + 1);
			}
		}
	}*/
};

Tree::Tree(vector<string> m, int posX)
{
	map = m;
	int maxSize = pow(2, (map.size() + 1) / 2) - 1;
	tree.resize(maxSize, 0);
	treeExist.resize(maxSize, false);
	int last = map.size() - 1;
	for (int i = 0; i < map[last].size(); i++)
	{
		if (map[last][i] != ' ')
		{
			break;
		}
	}

	int lineLength = 2 * map.size() - 1;
	int initPosX = posX - map.size() + 1;

	for (int i = 0; i < map.size(); i++)
	{
		map[i] = map[i].substr(initPosX, lineLength);
		map[i].resize(lineLength, ' ');
	}
	posX = map.size();
	//BuildTree(posX, 0, 0, 0);
}

Tree::~Tree()
{
}


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
	tree1.DisplayTree();
	return 0;
}