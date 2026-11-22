#pragma once
#include <cstdint>
#include "mem_bus.h"
#include "register.h"

class CPU {
  Register* reg;
  MemBus* bus;
  uint8_t curr_inst;

 public:
  void fetch() {
    curr_inst = bus->read(reg->pc++);
  }
  void excute() {
    switch (curr_inst) {
      case 0:
        break;

      default:
        break;
    }
  }
};
