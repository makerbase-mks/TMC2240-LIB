#pragma once
#pragma pack(push, 1)


namespace TMC2240_n {
  struct CHOPCONF_t {
    constexpr static uint8_t address = 0x6C;
      union {
        uint32_t sr;
        struct {
          uint8_t toff : 4;
          uint8_t hstrt : 3;
          uint8_t hend : 4;
          bool fd3 : 1;
          bool disfdcc : 1;
          bool : 1;
          bool chm : 1;
          uint8_t tbl : 2;
          bool : 1;
          bool vhighfs : 1;
          bool vhighchm : 1;
          uint8_t tpfd : 4;
          uint8_t mres : 4;
          bool intpol : 1;
          bool dedge : 1;
          bool diss2g : 1;
          bool diss2vs : 1;
        };
    };
  };
  struct DEVCONF_t {
    constexpr static uint8_t address = 0x0a;
    union {
      uint32_t sr;
      struct {
        uint8_t cur_range : 2;
        uint8_t : 2;
        uint8_t slo_control : 2;
      };
    };
  };

  struct IHOLD_IRUN_t {
    constexpr static uint8_t address = 0X10;
    union {
      uint32_t sr;
      struct {
        uint8_t ihold : 5;
        uint8_t : 3;
        uint8_t run : 5;
        uint8_t : 3;
        uint8_t iholddelay : 4;
        uint8_t : 4;
        uint8_t irundelay : 4;
      };
    };
  };
  struct TPOWERDOWM_t {
    constexpr static uint8_t address = 0x11;
    union {
      uint32_t sr;
      struct {
        uint8_t semin : 8;
      };
    };
  };

  struct TPWMTHRS_t {
    constexpr static uint8_t address = 0x13;
    union {
      uint32_t sr;
      struct {
        // uint8_t tpwmthrsb : 20;
        uint8_t tpwmthrsb;
      };
    };
  };
  struct TCOOLTHRS_t {
    constexpr static uint8_t address = 0x14;
    union {
      uint32_t sr;
      struct {
        // uint8_t tcoolthrs : 20;
        uint8_t tcoolthrs;
      };
    };
  };
  struct SG4_THRS_t {
    constexpr static uint8_t address = 0x74;
    union {
      uint32_t sr;
      struct {
        uint8_t sg4_thrsb: 8;
        bool sg4_filt_en: 1;
        bool sg_angle_offset: 1;
      };
    };
  };

  struct COOLCONF_t {
    constexpr static uint8_t address = 0x6D;
    union {
      uint32_t sr;
      struct {
        uint8_t semin: 4;
        bool : 1;
        uint8_t seup: 2;
        bool : 1;
        uint8_t semax: 4;
        bool : 1;
        uint8_t sedn: 2;
        bool seimin: 1;
        uint8_t sgt: 7;
        bool : 1;
        bool sfilt: 1;
        uint8_t : 7;
      };
    };
  };

  struct GCONF_t {
    constexpr static uint8_t address = 0x00;
    union {
      uint32_t sr;
      struct {
        bool : 1;
        bool fast_standstill: 1;
        bool en_pwm_mode : 1;
        bool multistep_filt: 1;
        bool shaft: 1;
        bool diag0_error : 1;
        bool diag0_otpw: 1;
        bool diag0_stall: 1;
        bool diag1_stall : 1;
        bool diag1_index: 1;
        bool diag1_onstate: 1;
        bool : 1;
        bool diag0_pushpull: 1;
        bool diag1_pushpull : 1;
        bool small_hysteresis: 1;
        bool stop_enable: 1;
        bool direct_mode: 1;
      };
    };
  };

  struct GSTAT_t {
    constexpr static uint8_t address = 0x01;
    union {
      uint32_t sr;
      struct {
        bool reset: 1;
        bool drv_err : 1;
        bool uv_cp: 1;
        bool register_reset : 1;
        bool vm_uvlo : 1;
      };
    };
  };

  struct PWMCONF_t {
    constexpr static uint8_t address = 0x70;
    union {
      uint32_t sr;
      struct {
        uint8_t pwm_ofs: 8;
        uint8_t pwm_grad: 8;
        uint8_t pwm_freq: 2;
        bool pwm_autoscale : 1;
        bool pwm_autograd : 1;
        uint8_t freewheel: 2;
        bool pwm_meas_sd_enable : 1;
        bool pwm_dis_reg_stst : 1;
        uint8_t pwm_reg: 4;
        uint8_t pwm_lim: 4;
      };
    };
  };
}

#pragma pack(pop)
