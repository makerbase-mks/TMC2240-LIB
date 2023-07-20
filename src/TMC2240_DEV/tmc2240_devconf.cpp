#include "source/TMC_MACROS.h"
#include "TMC2240XStepper.h"

// #define GET_REG(SETTING) return DEVCONF_register.SETTING;
#define GET_REG(SETTING) TMC2240_n::DEVCONF_t r{0}; r.sr = DEVCONF(); return r.SETTING

#define SET_REG(SETTING) DEVCONF_register.SETTING = B; write(DEVCONF_register.address, DEVCONF_register.sr)

uint32_t TMC2240Stepper::DEVCONF() { return DEVCONF_register.sr; }
void TMC2240Stepper::DEVCONF(uint32_t data) {
  DEVCONF_register.sr = data;
  write(DEVCONF_register.address, DEVCONF_register.sr);
}


void TMC2240Stepper::cur_range(uint8_t B) 	{ SET_REG(cur_range); 	}
void TMC2240Stepper::slo_control(uint8_t B) 	{ SET_REG(slo_control);	}



uint8_t TMC2240Stepper::cur_range() 	{ GET_REG(cur_range); 	}
uint8_t TMC2240Stepper::slo_control() 	{ GET_REG(slo_control);	}



