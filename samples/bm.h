#include <iostream>
#include <stdint.h>

class BM {
public:
    BM() {;}
    int convert64_to_32(uint64_t num, uint32_t dst[]);
};
