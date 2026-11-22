#include "ring_buffer.h"
#include <stdio.h>

int main(void) {
    RingBuffer *buffer = malloc(sizeof(RingBuffer));
    RingBufferInit(buffer);

    if (!RingBufferIsEmpty(buffer)) {
        printf("expected empty buffer");
    }

    uint8_t x = 10;
    if (!RingBufferPush(buffer, x)) {
        printf("failed to push");
    }
    uint8_t *y = malloc(sizeof(uint8_t));
    if (!RingBufferPop(buffer, y)) {
        printf("failed to pop");
    }
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

    RingBufferPush(buffer, 10);
    RingBufferPush(buffer, 20);
    RingBufferPush(buffer, 30);
    RingBufferPop(buffer, y);
    RingBufferPop(buffer, y);

    RingBufferPush(buffer, 40);
    RingBufferPush(buffer, 50);
    RingBufferPop(buffer, y);
    if (*y != 30) {
        printf("expected pop of value 30");
    }
    RingBufferPop(buffer, y);
    if (*y != 40) {
        printf("expected pop of value 40");
    }
    RingBufferPop(buffer, y);
    if (*y != 50) {
        printf("expected pop of value 50");
    }
    
    printf("tests finished");
}
