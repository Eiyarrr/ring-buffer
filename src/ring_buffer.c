#include "ring_buffer.h"

void RingBufferInit(RingBuffer *buffer) {
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
}

bool RingBufferPush(RingBuffer *buffer, uint8_t value) {}

bool RingBufferPop(RingBuffer *buffer, uint8_t *value) {}

bool RingBufferIsEmpty(const RingBuffer *buffer) {}

bool RingBufferIsFull(const RingBuffer *buffer) {}

void RingBufferClear(RingBuffer *buffer) {}
