#pragma once
#include <cstdint>
namespace mem {
constexpr uint16_t ROM_START = 0x0;
constexpr uint16_t ROM_END = 0x7FFF;
constexpr uint16_t VRAM_START = 0x8000;
constexpr uint16_t VRAM_END = 0x9FFF;
constexpr uint16_t ERAM_START = 0xA000;  // external ram from cart
constexpr uint16_t ERAM_END = 0xBFFF;
constexpr uint16_t WRAM_START = 0xC000;  // RAM on the Gameboy
constexpr uint16_t WRAM_END = 0xDFFF;
constexpr uint16_t ECHO_START = 0xE000;
constexpr uint16_t ECHO_END = 0xFDFF;
constexpr uint16_t OAM_START = 0xFE00;
constexpr uint16_t OAM_END = 0xFE9F;
constexpr uint16_t UNUSABLE_START = 0xFEA0;  // not usable returns 0xFF
constexpr uint16_t UNUSABLE_END = 0xFEFF;
constexpr uint16_t IOREG_START = 0xFF00;
constexpr uint16_t IOREG_END = 0xFF7F;
constexpr uint16_t HRAM_START = 0xFF80;
constexpr uint16_t HRAM_END = 0xFFFE;
constexpr uint16_t IE = 0xFFFF;
}  // namespace mem