// GraphHamband.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <ifstream>

using namespace std;
using std::ifstream;


void check_band(bool[1000][1000], int[1000], int, int, int&);


int main()
{
	//file declarations
	ifstream file("Dataset2.txt", ios::in);
	if (!file){
		system("pause");
		return 1;
	}
	cout << 0;
	//arrays to show the Graph
	bool mojaverat[1000][1000] = { false };

	int flags[1000] = { 0 };
	int number_of_v ;
	file>>number_of_v;
	int number_of_edges;
	file>>number_of_edges;
	int number_of_bands = 0;
	cout << "v:" << number_of_v<<"\nedges"<<number_of_edges;
	//setting mojaverat
	//loading Graph
	for (int i = number_of_edges,x,y; i; i--){
        file>>x;
		file>>y;
		cout << x <<','<< y << endl;
		mojaverat[x-1][y-1] = true;
		mojaverat[y-1][x-1] = true;
	}
	file.close();
	//counting bands
	int flag = 0;
	for (int i = 0; i<number_of_v; i++){
		if (flags[i] != 0)
			continue;
		flag++;
		check_band(mojaverat, flags, number_of_v, i, flag);
	}
	//printing result
	cout << "number of parts is equal to " << flag;
	system("pause");
	return 0;
}

void check_band(bool matrix[1000][1000], int flags[1000], int v, int current, int &flag){
	for (int i = 0; i < v; i++){
		if (matrix[i][current] && flags[i] == 0){
			flags[i] = flag;
			check_band(matrix, flags, v, i, flag);
		}
	}
}
