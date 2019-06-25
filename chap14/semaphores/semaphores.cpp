#include <QtCore>
#include <iostream>

const int DataSize = 100000;
const int BufferSize = 4096;
char buffer[BufferSize];

QSemaphore freeSpace(BufferSize); // 空格子
QSemaphore usedSpace(0); // 满格子

class Producer : public QThread
{
public:
    void run();
};

void Producer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        freeSpace.acquire();
        buffer[i % BufferSize] = "ACGT"[uint(std::rand()) % 4];
        usedSpace.release();
    }
}

class Consumer : public QThread
{
public:
    void run();
};

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        usedSpace.acquire(); // p操作
        std::cerr << buffer[i % BufferSize];
        freeSpace.release(); // v操作
    }
    std::cerr << std::endl;
}

int main()
{
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return 0;
}
