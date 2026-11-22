#pragma once
#include <cstdint>
#include "cartridge.h"
#include "constants.h"
#include "ioreg.h"
class MemBus {
 private:
  uint8_t vram[mem::VRAM_END - mem::VRAM_START + 1]{};
  uint8_t wram[mem::WRAM_END - mem::WRAM_START + 1]{};
  uint8_t oam[mem::OAM_END - mem::OAM_START + 1]{};
  IOREG* ioreg;
  uint8_t hram[mem::HRAM_END - mem::HRAM_START + 1]{};
  uint8_t ie{};
  Cartridge* cart{};

 public:
  uint8_t read(uint16_t addr) const {
    if (addr <= mem::ROM_END)
      return cart->rom[addr - mem::ROM_START];
    if (addr <= mem::VRAM_END)
      return vram[addr - mem::VRAM_START];
    if (addr <= mem::ERAM_END)
      return cart->ram[addr - mem::ERAM_START];
    if (addr <= mem::WRAM_END)
      return wram[addr - mem::WRAM_START];
    if (addr <= mem::ECHO_END)
      return wram[addr - mem::ECHO_START];
    if (addr <= mem::OAM_END)
      return oam[addr - mem::OAM_START];
    if (addr <= mem::UNUSABLE_END)
      return 0xFF;
    if (addr <= mem::IOREG_END)
      return ioreg->read(addr - mem::IOREG_START);
    if (addr <= mem::HRAM_END)
      return hram[addr - mem::HRAM_START];
    return ie;
  }
  void write(uint16_t addr, uint8_t val) {
    if (addr <= mem::ROM_END) {
      cart->rom[addr - mem::ROM_START] = val;
      return;
    }
    if (addr <= mem::VRAM_END) {
      vram[addr - mem::VRAM_START] = val;
      return;
    }
    if (addr <= mem::ERAM_END) {
      cart->ram[addr - mem::ERAM_START] = val;
      return;
    }
    if (addr <= mem::WRAM_END) {
      wram[addr - mem::WRAM_START] = val;
      return;
    }
    if (addr <= mem::ECHO_END) {
      wram[addr - mem::ECHO_START] = val;
      return;
    }
    if (addr <= mem::OAM_END) {
      oam[addr - mem::OAM_START] = val;
      return;
    }
    if (addr <= mem::UNUSABLE_END)
      return;
    if (addr <= mem::IOREG_END)
      return;
    if (addr <= mem::HRAM_END)
      hram[addr - mem::HRAM_START] = val;
    return;
  }
};
