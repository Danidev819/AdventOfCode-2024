#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");

    // Leer todo el contenido del archivo en una cadena
    std::string text((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    file.close();

    std::regex mulRegex(R"(mul\((\d+),(\d+)\))");
    std::smatch match; // Para almacenar los resultados de las coincidencias
    long long totalSum = 0;

    // Iterar sobre todas las coincidencias en el texto
    auto searchStart = text.cbegin();
    while (std::regex_search(searchStart, text.cend(), match, mulRegex)) {
        int x = std::stoi(match[1].str());
        int y = std::stoi(match[2].str());
        totalSum += x * y;
        searchStart = match.suffix().first;
    }

    std::cout << "La suma total de las multiplicaciones válidas es: " << totalSum << std::endl;

    return 0;
}
