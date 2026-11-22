#pragma once
#include <cstdint>
class IOREG {
 public:
  uint8_t read(uint16_t) const;
};