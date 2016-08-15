#include "bm.h"

int
BM::convert64_to_32(uint64_t num, uint32_t dst[]) {
    if (dst == NULL) return -1;

    dst[0] |= num;
    dst[1] |= (num >> 32);
    return 1;
}
