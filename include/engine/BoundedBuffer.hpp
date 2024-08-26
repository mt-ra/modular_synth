// This file contains both the definition and implementation of the
// BoundedBuffer template class
// Producer consumer problem

#pragma once

#include <engine/BoundedBuffer.hpp>
#include <semaphore>

namespace engine {

template<typename T>
class BoundedBuffer {
private:
    std::counting_semaphore<2> full_semaphore_;
    std::counting_semaphore<2> empty_semaphore_;
    boost::circular_buffer<T> buffer_;

public: // RAII member functions
    BoundedBuffer(size_t size) : buffer_(size), full_semaphore_(0), empty_semaphore_(size) {}
    ~BoundedBuffer() = default;
    BoundedBuffer(BoundedBuffer const &other) = delete;
    BoundedBuffer &operator=(BoundedBuffer const &other) = delete;

public: // interface
    void produce(T v) {
        full_semaphore.acquire();
        buffer_.push_back(v);
        empty_semaphore.release();
    }

    T consume() {
        empty_semaphore.acquire();
        T v = buffer_.front();
        buffer_.pop_front();
        full_semaphore.release();
        return v;
    }
};
}
