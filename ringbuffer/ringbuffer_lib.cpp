//"ringbuffer_lib.cpp"

#include "ringbuffer_lib.h"

    RingBuffer::RingBuffer(size_t capacity) : capacity_(capacity) {
        if (capacity == 0)
            printf("capacity must be greater than 0!\n");
	else {
            buffer_ = new int[capacity];
            available_ = 0;
            write_pos_ = 0;
	}
    }
    RingBuffer::~RingBuffer() {
        if (buffer_ != nullptr)
            delete[] buffer_;
    }
    bool RingBuffer::Publish(int value) {
        if (available_ < capacity_) {
            if (write_pos_ >= capacity_) {
                write_pos_ = 0;
            }
            buffer_[write_pos_] = value;
            write_pos_++;
            available_++;
            return true;
        }

        return false;
    }
    bool RingBuffer::Consume(int *r) {
        if (available_ == 0) {
            return false;
        }
        int next_slot = write_pos_ - available_;
        if (next_slot < 0) {
            next_slot += capacity_;
        }
        *r = buffer_[next_slot];
        available_--;
        return true;
    }
