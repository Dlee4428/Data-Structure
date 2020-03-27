#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

#include "HashTable.h"


int main(void)
{
	ifstream ranking;
	string entry;
	string points;
	string size;

	ranking.open("fifa.txt");
	
	if(!ranking)
	{
		cerr << "Error: Could not open file" << endl;
		return -1;
	}

	ranking >> size;

	HashTable<int> leaderboard(atoi(size.c_str()));

	while(!ranking.eof())
	{
		ranking >> entry;
		ranking >> points;

		leaderboard.insert(entry, atoi(points.c_str()));
	}

	ranking.close();

	leaderboard.printTable();

	leaderboard.resize();

	leaderboard.printTable();

	HashTable<int>::Entry team = leaderboard.find("Canada");
	if (team.isValid())
		cout << "Canada's ranking is " << team.getValue() << endl;

	return 0;
}
