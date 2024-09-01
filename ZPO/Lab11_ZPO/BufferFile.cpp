#include "BufferFile.h"

using namespace std;

BufferFile::BufferFile(const char* filePath) : filePath(filePath) {
    file = fopen(filePath, "a");
    std::cout << "Konstruktor klasy BufferFile" << std::endl;
}

BufferFile::~BufferFile() {
    fclose(file);
    std::cout << "Destruktor klasy BufferFile" << std::endl;
}

void BufferFile::add(int a) {
    fprintf(file, "%d\n", a);
}

void BufferFile::write() {
    FILE* readfile = fopen(filePath, "r");
    if (readfile != nullptr) {
        cout << "Elementy tablicy BufferFile:" << endl;
        int num;
        while (fscanf(readfile, "%d", &num) != EOF) {
            cout << num << " ";
        }
        fclose(readfile);
    }
    cout << endl;
}
