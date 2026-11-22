#pragma once
#include <cstdint>
enum class FLAGS : uint8_t { FLAG_Z = 0x80,
                             FLAG_N = 0x40,
                             FLAG_H = 0x20,
                             FLAG_C = 0x10 };
struct Register {

  uint8_t a;
  uint8_t c;
  uint8_t b;
  uint8_t d;
  uint8_t e;
  uint8_t f;
  uint8_t h;
  uint8_t l;
  uint16_t sp;
  uint16_t pc;

 public:
  uint16_t get_AF() const { return uint16_t(a << 8 | f); }
  uint16_t get_BC() const { return uint16_t(b << 8 | c); }
  uint16_t get_DE() const { return uint16_t(d << 8 | e); }
  uint16_t get_HL() const { return uint16_t(h << 8 | l); }

  void set_AF(uint16_t val) {
    a = (val >> 8) & 0xFF;
    f = val & 0xF0;
  }
  void set_BC(uint16_t val) {
    b = (val >> 8) & 0xFF;
    c = val & 0xFF;
  }
  void set_DE(uint16_t val) {
    d = (val >> 8) & 0xFF;
    c = val & 0xFF;
  }
  void set_HL(uint16_t val) {
    h = (val >> 8) & 0xFF;
    c = val & 0xFF;
  }
  bool getFlag(FLAGS fl) const { return f & static_cast<uint8_t>(fl); }

  void setFlag(FLAGS fl, bool set) { f = set ? f | static_cast<uint8_t>(fl)
                                             : f & ~static_cast<uint8_t>(fl); }
  void setAllFlags(bool z, bool n, bool h, bool c) { f =
                                                         (z << 7 | n << 6 | h << 5 | c << 4); }
};
