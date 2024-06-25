#pragma once
// BitMap.h
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t array_elem_type;

typedef struct {
    array_elem_type* array;
    size_t    bits;
} BitMap;

BitMap* bitmap_create(size_t bits);
void bitmap_destroy(BitMap* bm);

void bitmap_set(BitMap* bm, size_t n);
void bitmap_unset(BitMap* bm, size_t n);
bool bitmap_isset(BitMap* bm, size_t n);
void bitmap_clear(BitMap* bm);
static void bitmap_grow(BitMap* bm, size_t bits);