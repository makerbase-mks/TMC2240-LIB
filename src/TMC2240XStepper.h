#pragma once

//#define TMCDEBUG

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
	#include <SPI.h>
	#include <Stream.h>
#elif defined(bcm2835)
	#include <bcm2835.h>
	#include "source/bcm2835_spi.h"
	#include "source/bcm2835_stream.h"
#elif __cplusplus >= 201703L
	#if __has_include(<Arduino.h>)
		#include <Arduino.h>
	#endif
	#if __has_include(<SPI.h>)
		#include <SPI.h>
	#endif
	#if __has_include(<Stream.h>)
		#include <Stream.h>
	#endif
#endif

#if (__cplusplus == 201703L) && defined(__has_include)
	#define SW_CAPABLE_PLATFORM __has_include(<SoftwareSerial.h>)
#elif defined(__AVR__) || defined(TARGET_LPC1768) || defined(ARDUINO_ARCH_STM32)
	#define SW_CAPABLE_PLATFORM true
#else
	#define SW_CAPABLE_PLATFORM false
#endif

#if SW_CAPABLE_PLATFORM
	#include <SoftwareSerial.h>
#endif

#if SW_CAPABLE_PLATFORM
	#include <SoftwareSerial.h>
#endif

#include "SF_SPI.h"
#include "TMC2240_bitfields.h"
// #include "TMC2240U_bitfields.h"

#define INIT2240_REGISTER(REG) TMC2240_n::REG##_t REG##_register = TMC2240_n::REG##_t
#define INIT2240U_REGISTER(REG) TMC2240U_n::REG##_t REG##_register = TMC2240U_n::REG##_t


class TMC2240Stepper {
	public:
		TMC2240Stepper(uint16_t pinCS, float RS = default_RS);
		TMC2240Stepper(uint16_t pinCS, uint16_t pinMOSI, uint16_t pinMISO, uint16_t pinSCK);
		TMC2240Stepper(uint16_t pinCS, float RS, uint16_t pinMOSI, uint16_t pinMISO, uint16_t pinSCK);
		void write(uint8_t addressByte, uint32_t config);
		void send(uint32_t data);
		uint32_t read();
		void switchCSpin(bool state);
		void begin();
		bool isEnabled();
		uint8_t test_connection();
		uint16_t cs2rms(uint8_t CS);
		uint16_t rms_current();
		void rms_current(uint16_t mA);
		//uint16_t getMilliamps() {return val_mA;}
		void push();
		uint8_t savedToff() { return _savedToff; }

		// Helper functions
		void microsteps(uint16_t ms);
		uint16_t microsteps();
		void blank_time(uint8_t value);
		uint8_t blank_time();
		void hysteresis_end(int8_t value);
		int8_t hysteresis_end();
		void hysteresis_start(uint8_t value);
		uint8_t hysteresis_start();

		// W: CHOPCONF
		/*w*/
		void CHOPCONF(uint32_t);
		void hstrt(uint8_t) ;
		void hend(uint8_t) ;
		void fd3(bool) ;
		void disfdcc(bool) ;
		void chm(bool) ;
		void tbl(uint8_t) ;
		void vhighfs(bool) ;
		void vhighchm(bool);
		void tpfd(uint8_t) ;
		void mres(uint8_t) ;
		void intpol(bool) ;
		void dedge(bool);
		void diss2g(bool) ;
		void diss2vs(bool);
		void toff(uint8_t);
		/*r*/
		uint32_t CHOPCONF();
		uint8_t hstrt();
		uint8_t hend();
		bool fd3();
		bool disfdcc();
		bool chm();
		uint8_t tbl();
		bool vhighfs();
		bool vhighchm();
		uint8_t tpfd();
		uint8_t mres();
		bool intpol();
		bool dedge();
		bool diss2g();
		bool diss2vs();


		uint32_t DEVCONF();
		void DEVCONF(uint32_t);
		uint8_t cur_range();
		uint8_t slo_control();
		void cur_range(uint8_t) ;
		void slo_control(uint8_t) ;

		uint32_t IHOLD_IRUN();
		void IHOLD_IRUN(uint32_t);
		uint8_t ihold();
		uint8_t run();
		void ihold(uint8_t) ;
		void run(uint8_t) ;
		uint8_t iholddelay();
		uint8_t irundelay();
		void iholddelay(uint8_t) ;
		void irundelay(uint8_t) ;

		uint32_t SG4_THRS();
		void SG4_THRS(uint32_t);
		uint8_t sg4_thrsb();
		void sg4_thrsb(uint8_t) ;
		bool sg4_filt_en();
		void sg4_filt_en(bool) ;
		bool sg_angle_offset();
		void sg_angle_offset(bool) ;

		uint32_t TPOWERDOWM();
		void TPOWERDOWM(uint32_t);

		uint32_t TCOOLTHRS();
		void TCOOLTHRS(uint32_t);
		uint8_t tcoolthrs();
		void tcoolthrs(uint8_t) ;

		uint32_t TPWMTHRS();
		void TPWMTHRS(uint32_t);
		uint8_t tpwmthrsb();
		void tpwmthrsb(uint8_t) ;

		uint32_t GCONF();
		void GCONF(uint32_t);
		uint32_t COOLCONF();
		void COOLCONF(uint32_t);
		void sgt(uint8_t);
		uint8_t sgt();
		void diag1_stall(uint8_t);
		uint8_t diag1_stall();
		
		// R: DRVSTATUS
		uint32_t DRV_STATUS() { return DRVSTATUS(); }
		uint32_t DRVSTATUS();
		uint16_t mstep();
		uint8_t se();
		bool stst();
		bool olb();
		bool ola();
		bool s2gb();
		bool s2ga();
		bool otpw();
		bool ot();
		bool sg();
		uint16_t sg_result();

		// W: SGCSCONF
		uint32_t SGCSCONF();
		void cs(uint8_t);
		void SGCSCONF(uint32_t);
		uint8_t cs();

		// W: SMARTEN
		void SMARTEN(uint32_t);
		// void semin(uint8_t B);
		uint32_t SMARTEN();
	
		uint8_t status_response;

		uint32_t GSTAT();
		void GSTAT(uint32_t);
		void reset(bool );
		void drv_err(bool );
		void uv_cp(bool );
		void register_reset(bool );
		void vm_uvlo(bool );
		bool reset() 	;
		bool drv_err() 	;
		bool uv_cp() 	;
		bool register_reset() 	;
		bool vm_uvlo() 	;


		uint32_t PWMCONF() ;
		void PWMCONF(uint32_t ) ;
		void pwm_ofs(uint8_t );
		void pwm_grad(uint8_t );
		void pwm_freq(uint8_t );
		void pwm_autoscale(bool );
		void pwm_autograd(bool );
		void freewheel(uint8_t );
		void pwm_meas_sd_enable(bool );
		void pwm_dis_reg_stst(bool );
		void pwm_reg(uint8_t );
		void pwm_lim(uint8_t );

		uint8_t pwm_ofs() ;
		uint8_t pwm_grad() ;
		uint8_t pwm_freq() ;
		bool pwm_autoscale();
		bool pwm_autograd() ;
		uint8_t freewheel() ;
		bool pwm_meas_sd_enable();
		bool pwm_dis_reg_stst() ;
		uint8_t pwm_reg() ;
		uint8_t pwm_lim() ;
		void semin(uint8_t ) ;
		void seup(uint8_t ) ;
		void semax(uint8_t );
		void sedn(uint8_t ) ;
		void seimin(bool ) ;
		void sfilt(bool ) ;
		uint8_t semin();
		uint8_t seup();
		uint8_t semax();
		uint8_t sedn();
		bool seimin();
		bool sfilt();

		bool fast_standstill();
		bool en_pwm_mode();
		bool multistep_filt();
		bool shaft();
		bool diag0_error ();
		bool diag0_otpw();
		bool diag0_stall();
		bool diag1_index();
		bool diag1_onstate();
		bool diag0_pushpull();
		bool diag1_pushpull ();
		bool small_hysteresis();
		bool stop_enable();
		bool direct_mode();

		void fast_standstill(bool);
		void en_pwm_mode(bool);
		void multistep_filt(bool);
		void shaft(bool);
		void diag0_error(bool);
		void diag0_otpw(bool);
		void diag0_stall(bool);
		void diag1_index(bool);
		void diag1_onstate(bool);
		void diag0_pushpull(bool);
		void diag1_pushpull(bool);
		void small_hysteresis(bool);
		void stop_enable(bool);
		void direct_mode(bool);
		
	private:
		INIT2240_REGISTER(DEVCONF){{.sr=0}};
		INIT2240_REGISTER(IHOLD_IRUN){{.sr=0}};
		INIT2240_REGISTER(CHOPCONF){{.sr=0}};
		INIT2240_REGISTER(TPOWERDOWM){{.sr=0}};
		INIT2240_REGISTER(TPWMTHRS){{.sr=0}};
		INIT2240_REGISTER(SG4_THRS){{.sr=0}};
		INIT2240_REGISTER(GCONF){{.sr=0}};
		INIT2240_REGISTER(COOLCONF){{.sr=0}};
		INIT2240_REGISTER(TCOOLTHRS){{.sr=0}};
		INIT2240_REGISTER(GSTAT){{.sr=0}};
		INIT2240_REGISTER(PWMCONF){{.sr=0}};

		const uint16_t _pinCS;
		const float Rsense;
		static constexpr float default_RS = 0.1;
		float holdMultiplier = 0.5;
		uint32_t spi_speed = 16000000/8; // Default 2MHz
		uint8_t _savedToff = 0;
		SF_SPIClass * TMC_SW_SPI = nullptr;
};
