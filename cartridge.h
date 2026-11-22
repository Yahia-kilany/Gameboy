#pragma once
#include <cstdint>
#include "constants.h"
struct Cartridge {

  uint8_t rom[mem::ROM_END - mem::ROM_START + 1]{};
  uint8_t ram[mem::ERAM_END - mem::ERAM_START + 1]{};
};