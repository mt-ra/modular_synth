// This file contains both the definition and implementation of the
// BoundedBuffer template class
// Producer consumer problem

#pragma once

#include <iostream>
#include <engine/BoundedBuffer.hpp>
#include <semaphore>

#include <boost/circular_buffer.hpp>

#define DEFAULT_BUFF_SIZE 4096

namespace engine {

template<typename T>
class BoundedBuffer {
private:
    std::counting_semaphore<2> full_semaphore_;
    std::counting_semaphore<2> empty_semaphore_;
    boost::circular_buffer<T> buffer_;

public: // RAII member functions
    // TODO: FIX THIS
    // TODO: FIGURE OUT WHY DEFAULT CONSTRUCTOR IS BEING CALLED
    BoundedBuffer() : BoundedBuffer(DEFAULT_BUFF_SIZE) {}
    BoundedBuffer(size_t size) : buffer_(size), full_semaphore_(size), empty_semaphore_(0) {
        std::cerr << "made bounded buffer with size = " << size << std::endl;
    }
    ~BoundedBuffer() = default;
    BoundedBuffer(BoundedBuffer const &other) = delete;
    BoundedBuffer &operator=(BoundedBuffer const &other) = delete;

public: // interface
    void produce(T v) {
        full_semaphore_.acquire();
        buffer_.push_back(v);
        empty_semaphore_.release();
    }

    T consume() {
        empty_semaphore_.acquire();
        T v = buffer_.front();
        buffer_.pop_front();
        full_semaphore_.release();
        return v;
    }
};
}
