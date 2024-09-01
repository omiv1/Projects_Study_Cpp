#ifndef BUFFERFILE_H
#define BUFFERFILE_H

#include "Buffer.h"

class BufferFile : public Buffer {
private:
    const char* filePath;
    FILE* file;

public:
    BufferFile(const char* filePath);
    ~BufferFile();
    void add(int a) override;
    void write() override;
};

#endif // BUFFERFILE_H
