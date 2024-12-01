#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Leer el archivo de entrada y cargar los números en dos vectores
void readInput(const string& filename, vector<int>& leftList, vector<int>& rightList)
{
	ifstream file(filename);

	if (!file)
	{
		cerr << "Error al abrir el archivo " << filename << '\n';
		exit(1);
	}
	int left, right;
	while (file >> left >> right)
	{
		leftList.push_back(left);
		rightList.push_back(right);
	}
	file.close();
}

// Calcular la distancia total entre las listas
int calculateTotalDistance(vector<int>& leftList, vector<int>& rightList)
{
	sort(leftList.begin(), leftList.end());
	sort(rightList.begin(), rightList.end());
	int totalDistance{ 0 };
	for (size_t i{ 0 }; i < leftList.size(); ++i)
	{
		totalDistance += abs(leftList[i] - rightList[i]);
	}
	return totalDistance;
}

int main()
{
	vector<int> leftList, rightList;
	string filename{ "input.txt" };

	// Leer el archivo
	readInput(filename, leftList, rightList);

	// Calcular la distancia total
	int totalDistance{ calculateTotalDistance(leftList, rightList) };

	// Mostrar resultado
	cout << "La distancia total entre las dos listas es: " << totalDistance << '\n';

	return 0;
}
