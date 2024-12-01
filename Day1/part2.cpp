#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> left_list;
    vector<int> right_list;
    unordered_map<int, int> right_count;
    int similarity_score = 0;

    ifstream file("input.txt");
    string line;

    // Lee el archivo y guarda los datos en las listas
    while (getline(file, line)) {
        stringstream ss(line);
        int left, right;
        ss >> left >> right;
        left_list.push_back(left);
        right_list.push_back(right);
    }

    // Cuenta la frecuencia de los elementos en right_list
    for (int num : right_list) {
        right_count[num]++;
    }

    // Calcula la similitud
    for (int num : left_list) {
        if (right_count.find(num) != right_count.end()) {
            similarity_score += num * right_count[num];
        }
    }

    cout << similarity_score << endl;

    return 0;
}
