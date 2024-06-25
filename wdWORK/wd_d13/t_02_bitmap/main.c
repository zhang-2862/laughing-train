#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BitMap.h"

#define BITS_PER_WORD 32
#define BITMAP_SHIFT 5
#define BITMAP_MASK 31

//向上取整，求位图中arr元素个数
#define BITMAP_SIZE(bits) ((bits + BITS_PER_WORD - 1) >> BITMAP_SHIFT)
//请用动态数组实现位图。

//		#include <stdint.h>
//		#include <stdbool.h>
//
//		typedef struct {
//			uint32_t* array;
//			size_t    bits;
//		} BitMap;
//

BitMap* bitmap_create(size_t bits) {
	BitMap* bm = malloc(sizeof(BitMap));
	bm->bits = bits;
	bm->array = calloc(BITMAP_SIZE(bits), sizeof(array_elem_type));
	return bm;
}

void bitmap_destroy(BitMap* bm) {
	if (bm) {
		if (bm->array) {
			free(bm->array);
		}
		free(bm);
	}
}

void bitmap_set(BitMap* bm, size_t n) {
	//若设置位置超出当前位图容量则进行扩容
	if (BITMAP_SIZE(n + 1) > BITMAP_SIZE(bm->bits)){
		bitmap_grow(bm, n + 1);
	}
	int arr_idx = n >> BITMAP_SHIFT;
	int offset = n & BITMAP_MASK;
	bm->array[arr_idx] |= 0x1 << offset;
}

void bitmap_unset(BitMap* bm, size_t n) {
	int arr_idx = n >> BITMAP_SHIFT;
	int offset = n & BITMAP_MASK;
	bm->array[arr_idx] &= ~(0x1 << offset);
}

bool bitmap_isset(BitMap* bm, size_t n) {
	if (n > bm->bits) {
		return false;
	}
	int arr_idx = n >> BITMAP_SHIFT;
	int offset = n & BITMAP_MASK;
	return (bm->array[arr_idx] >> offset) & 0x1;
}

void bitmap_clear(BitMap* bm) {
	memset(bm->array, 0, BITMAP_SIZE(bm->bits)*sizeof(array_elem_type));
}


static void bitmap_grow(BitMap* bm, size_t bits) {
	//重新设置array大小
	bm->array = realloc(bm->array, BITMAP_SIZE(bits) * sizeof(array_elem_type));
	//计算出需要初始化的字节数
	int bytes = (BITMAP_SIZE(bits) - BITMAP_SIZE(bm->bits))* sizeof(array_elem_type);
	//初始化，memset（初始化起点即《首地址》，值，字节数）
	memset(bm->array+BITMAP_SIZE(bm->bits), 0, bytes);
	//更新比特位总数
	bm->bits = bits;
}
int main(void) {
	BitMap* bm = bitmap_create(32);
	bitmap_set(bm, 34);
	bitmap_set(bm, 9);
	bitmap_set(bm, 39);
	bitmap_set(bm,5);
	printf("%s", bitmap_isset(bm,34) ? "ture\n" : "false\n");
	bitmap_unset(bm, 34);
	printf("%s", bitmap_isset(bm, 34) ? "ture\n" : "false\n");

	bitmap_clear(bm);
	printf("%s", bitmap_isset(bm, 34) ? "ture\n" : "false\n");

	bitmap_destroy(bm);

	return 0;
}