#include "bm.h"

int
BM::convert64_to_32(uint64_t num, uint32_t *dst) {
    if (dst == NULL) return -1;
    
    for (int i=0; i < 32; i++) {
       dst[0] |= ((num >> i) << i);
    }
    for (int i=32; i < 64; i++) {
       dst[1] |= ((num >> i) << (i-32));
    }
    return 1;
}
