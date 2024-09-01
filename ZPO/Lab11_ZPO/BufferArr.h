#ifndef BUFFERARR_H
#define BUFFERARR_H

#include "Buffer.h"

class BufferArr : public Buffer {
private:
    int* array;
    int size;
    int count;

public:
    BufferArr(int bufferSize);
    ~BufferArr() override;
    void add(int a) override;
    void write() override;
    int getSize() const;
    void setSize(int newSize);
    int getCount() const;
    void setCount(int newCount);
};

#endif // BUFFERARR_H
