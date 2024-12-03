#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

// Función para verificar si un informe es seguro
bool isSecure(const vector<int>& levels) {
    bool ascending{ true }, descending{ true };

    for (size_t i = 1; i < levels.size(); ++i) {
        int difference{ abs(levels[i] - levels[i - 1]) };

        // Verificar si la diferencia está en el rango válido (1 a 3)
        if (difference < 1 || difference > 3) {
            return false;
        }

        // Verificar si el informe es ascendente o descendente
        if (levels[i] < levels[i - 1]) {
            ascending = false;
        }
        if (levels[i] > levels[i - 1]) {
            descending = false;
        }
    }

    return ascending || descending;
}

int main() {
    ifstream file("input.txt");
    string line;
    int safeCount{ 0 };

    // Lee cada línea del archivo
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> levels;
        int nivel;

        // Lee los números de la línea y se almacenan en un vector
        while (ss >> nivel) {
            levels.push_back(nivel);
        }

        // Verificar si el informe es seguro
        if (isSecure(levels)) {
            safeCount++;
        }
    }

    file.close();

    cout << "Cantidad de informes seguros: " << safeCount << endl;

    return 0;
}
