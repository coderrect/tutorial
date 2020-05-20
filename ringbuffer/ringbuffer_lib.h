//"ringbuffer_lib.h"
#ifndef RINGBUFFER_LIB_H
#define RINGBUFFER_LIB_H

#include <stdexcept>
    class RingBuffer {
    private:
        int *buffer_;
        size_t write_pos_;
        size_t available_;
        size_t capacity_;

    public:
        RingBuffer(size_t capacity);
        ~RingBuffer();

        bool Publish(int value);
        bool Consume(int *r);
    };

#endif //RINGBUFFER_LIB_H
