#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

typedef struct {
    uint8_t data[BUFFER_SIZE];
    size_t head;
    size_t tail;
    size_t count;
} RingBuffer;

#endif
