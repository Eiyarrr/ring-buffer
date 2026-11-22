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

void RingBufferInit(RingBuffer *buffer);

bool RingBufferPush(RingBuffer *buffer, uint8_t value);
bool RingBufferPop(RingBuffer *buffer, uint8_t *value);

bool RingBufferIsEmpty(const RingBuffer *buffer);
bool RingBufferIsFull(const RingBuffer *buffer);

void RingBufferClear(RingBuffer *buffer);

#endif
