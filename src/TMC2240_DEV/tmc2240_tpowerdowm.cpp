#include "source/TMC_MACROS.h"
#include "TMC2240XStepper.h"

// #define GET_REG(SETTING) return TPOWERDOWM_register.SETTING;
#define GET_REG(SETTING) TMC2240_n::TPOWERDOWM_t r{0}; r.sr = TPOWERDOWM(); return r.SETTING

#define SET_REG(SETTING) TPOWERDOWM_register.SETTING = B; write(TPOWERDOWM_register.address, TPOWERDOWM_register.sr)

uint32_t TMC2240Stepper::TPOWERDOWM() { return TPOWERDOWM_register.sr; }
void TMC2240Stepper::TPOWERDOWM(uint32_t data) {
  TPOWERDOWM_register.sr = data;
  write(TPOWERDOWM_register.address, TPOWERDOWM_register.sr);
}



