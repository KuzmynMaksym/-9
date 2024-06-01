#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функція для зчитування матриці з файлу
vector<vector<int>> readMatrixFromFile(const string& filename, int& M, int& N) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Unable to open input file " << filename << endl;
        exit(1);
    }
    inputFile >> M >> N;
    vector<vector<int>> matrix(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();
    return matrix;
}

// Функція для знаходження кількості стовпців, елементи яких впорядковані за спаданням
int countColumnsSortedDescending(const vector<vector<int>>& matrix) {
    int count = 0;
    int M = matrix.size();
    int N = matrix[0].size();
    for (int j = 0; j < N; ++j) {
        bool isDescending = true;
        for (int i = 1; i < M; ++i) {
            if (matrix[i][j] > matrix[i - 1][j]) {
                isDescending = false;
                break;
            }
        }
        if (isDescending) {
            count++;
        }
    }
    return count;
}

int main() {
    string inputFilename;
    int M, N;

    // Зчитуємо ім'я файлу з консолі
    cout << "Enter the input filename: ";
    cin >> inputFilename;

    // Зчитуємо матрицю з файлу
    vector<vector<int>> matrix = readMatrixFromFile(inputFilename, M, N);

    // Оброблюємо матрицю та знаходимо кількість стовпців, елементи яких впорядковані за спаданням
    int sortedDescendingColumns = countColumnsSortedDescending(matrix);

    // Виводимо результат у консоль
    cout << "Number of columns sorted in descending order: " << sortedDescendingColumns << endl;

    // Дописуємо результат у той самий файл
    ofstream outputFile(inputFilename, ios::app);
    if (!outputFile) {
        cerr << "Unable to open output file " << inputFilename << endl;
        exit(1);
    }
    outputFile << "Number of columns sorted in descending order: " << sortedDescendingColumns << endl;
    outputFile.close();

    return 0;
}
