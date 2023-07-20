#include "source/TMC_MACROS.h"
#include "TMC2240XStepper.h"

// #define GET_REG(SETTING) return TPWMTHRS_register.SETTING;
#define GET_REG(SETTING) TMC2240_n::TPWMTHRS_t r{0}; r.sr = TPWMTHRS(); return r.SETTING

#define SET_REG(SETTING) TPWMTHRS_register.SETTING = B; write(TPWMTHRS_register.address, TPWMTHRS_register.sr)

uint32_t TMC2240Stepper::TPWMTHRS() { return TPWMTHRS_register.sr; }
void TMC2240Stepper::TPWMTHRS(uint32_t data) {
  TPWMTHRS_register.sr = data;
  write(TPWMTHRS_register.address, TPWMTHRS_register.sr);
}


void TMC2240Stepper::tpwmthrsb(uint8_t B) 	{ SET_REG(tpwmthrsb); 	}
uint8_t TMC2240Stepper::tpwmthrsb() 	{ GET_REG(tpwmthrsb); 	}


