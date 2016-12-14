#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include <stdint.h>

// Hilsmakros für Int <-> Bytes:
//  Byte      1 2 3 4
//  Number 0x12345678
#define U16_BYTE1(u) ((uint8_t) ((((uint16_t) (u)) >> 8) & 0xff))
#define U16_BYTE2(u) ((uint8_t) (((uint16_t) (u)) & 0xff))

#define U32_BYTE1(u) ((uint8_t) ((((uint32_t) (u)) >> 24) & 0xff))
#define U32_BYTE2(u) ((uint8_t) ((((uint32_t) (u)) >> 16) & 0xff))
#define U32_BYTE3(u) ((uint8_t) ((((uint32_t) (u)) >> 8) & 0xff))
#define U32_BYTE4(u) ((uint8_t) (((uint32_t) (u)) & 0xff))

// Hi LISP-C :D
#define BYTES_TO_U16(b1, b2) \
    ((uint16_t) ((((uint16_t) ((uint8_t) (b1))) << 8) | \
                   (uint16_t) ((uint8_t) (b2))))
#define BYTES_TO_U32(b1, b2, b3, b4) \
    ((uint32_t) ((((uint32_t) ((uint8_t) (b1))) << 24) | \
                 (((uint32_t) ((uint8_t) (b2))) << 16) | \
                 (((uint32_t) ((uint8_t) (b3))) << 8) | \
                   (uint32_t) ((uint8_t) (b4))))

// Hilfsmakro für Bitlogik
#define BIT(n) (1 << (n))
// Für ungenutzte Parameter
#define UNUSED(a) ((void)(a))

#endif

