#include "ring_buffer.h"
#include <stdio.h>

int main(void) {
    RingBuffer *buffer = malloc(sizeof(RingBuffer));
    RingBufferInit(buffer);

    if (!RingBufferIsEmpty(buffer)) {
        printf("expected empty buffer");
    }

    uint8_t x = 10;
    RingBufferPush(buffer, x);
    uint8_t *y = malloc(sizeof(uint8_t));
    RingBufferPop(buffer, y);
    if (x != *y) {
        printf("expected same pop as push");
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        RingBufferPush(buffer, 0);
    }
    if (!RingBufferIsFull(buffer)) {
        printf("expected full buffer");
    }

    if (RingBufferPush(buffer, 0)) {
        printf("expected fail push on full buffer");
    }

    RingBufferClear(buffer);
    if (!RingBufferIsEmpty(buffer)) {
        printf("expected empty buffer after clear");
    }

    if (RingBufferPush(NULL, 0)) {
        printf("expected fail on null buffer in Push");
    }
    if (RingBufferPop(NULL, 0)) {
        printf("expected fail on null buffer in Pop");
    }
    if (!RingBufferIsFull(NULL)) {
        printf("expected pass on null buffer in IsFull");
    }
    if (!RingBufferIsEmpty(NULL)) {
        printf("expected pass on null buffer in IsEmpty");
    }
}
