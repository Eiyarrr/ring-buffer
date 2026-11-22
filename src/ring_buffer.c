#include "ring_buffer.h"

void RingBufferInit(RingBuffer *buffer) {
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
}

bool RingBufferPush(RingBuffer *buffer, uint8_t value) {
    if (buffer == NULL || RingBufferIsFull(buffer)) {
        return false;
    }

    buffer->data[buffer->head] = value;
    buffer->head = (buffer->head + 1) % BUFFER_SIZE;
    buffer->count++;

    return true;
}

bool RingBufferPop(RingBuffer *buffer, uint8_t *value) {
    if (buffer == NULL || value == NULL || RingBufferIsEmpty(buffer)) {
        return false;
    }

    *value = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
    buffer->count--;

    return true;
}

bool RingBufferIsEmpty(const RingBuffer *buffer) {
    return (buffer == NULL || buffer->count == 0);
}

bool RingBufferIsFull(const RingBuffer *buffer) {}

void RingBufferClear(RingBuffer *buffer) {}
