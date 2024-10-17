// Copyright 2024 Accenture.

#ifndef GUARD_B448F597_7AF1_4ABE_B91B_63012BEC6E72
#define GUARD_B448F597_7AF1_4ABE_B91B_63012BEC6E72

#ifdef __cplusplus
extern "C"
{
#endif

#define CRYSTAL_SPEED     8000000U
#define CRYSTAL_SPEED_KHZ ((CRYSTAL_SPEED) / (1000))

#define CPU_SPEED 80000000U

#define CPU_SPEED_MHZ ((CPU_SPEED) / (1000000))
#define BUS_SPEED     ((CPU_SPEED) / (2))
#define BUS_SPEED_MHZ ((BUS_SPEED) / (1000000))

#define CPU_XTAL_CLK_HZ      CRYSTAL_SPEED
#define CPU_INT_FAST_CLK_HZ  48000000U
#define DEFAULT_SYSTEM_CLOCK 48000000U

#define CORE_CLK CPU_SPEED
#define SYS_CLK  CPU_SPEED
#define BUS_CLK  (CPU_SPEED / 2)

#define CLOCKSET_PCC(sel, frac, pcd) (((sel) << 24) | ((frac) << 3) | (pcd))

#if (SYS_CLK == 48000000U)
#define _SCG_RCCR_SCS     (3 << 24)
#define _SCG_RCCR_DIVCORE (0 << 16)
#define _SCG_RCCR_DIVBUS  (0 << 4)
#define _SCG_RCCR_DIVSLOW (1)

#define _SPLLDIV1 (1)
#define _SPLLDIV2 (1)
#define _FIRCDIV1 (1)
#define _FIRCDIV2 (1)
#define _SIRCDIV1 (1)
#define _SIRCDIV2 (1)
#define _SOSCDIV1 (1)
#define _SOSCDIV2 (1)

#define CLOCKoUT_SELECT (0)

#define CLOCK_SOURCE_FTM3   (1 << 24)
#define CLOCK_SOURCE_ADC1   (1 << 24)
#define CLOCK_SOURCE_LPSPI0 (1 << 24)
#define CLOCK_SOURCE_LPSPI1 (1 << 24)
#define CLOCK_SOURCE_LPSPI2 (1 << 24)
#define CLOCK_SOURCE_LPIT   (1 << 24)

#define CLOCK_SOURCE_FTM0 (1 << 24)
#define CLOCK_SOURCE_FTM1 (1 << 24)
#define CLOCK_SOURCE_FTM2 (1 << 24)
#define CLOCK_SOURCE_ADC0 (1 << 24)

#define CLOCK_SOURCE_LPTMR0 CLOCKSET_PCC(1, 0, 0)
#define CLOCK_SOURCE_FLEXIO CLOCKSET_PCC(1, 0, 0)
#define CLOCK_SOURCE_LPI2C0 CLOCKSET_PCC(1, 0, 0)

#define CLOCK_SOURCE_LPUART0 CLOCKSET_PCC(1, 0, 0)
#define CLOCK_SOURCE_LPUART1 CLOCKSET_PCC(1, 0, 0)
#define CLOCK_SOURCE_LPUART2 CLOCKSET_PCC(1, 0, 0)

#define CLOCK_SOURCE_FTM4 (1 << 24)
#define CLOCK_SOURCE_FTM5 (1 << 24)

#elif (SYS_CLK == 80000000U)

#define _SCG_RCCR_SCS     (6 << 24)
#define _SCG_RCCR_DIVCORE (1 << 16)
#define _SCG_RCCR_DIVBUS  (1 << 4)
#define _SCG_RCCR_DIVSLOW (2)

#define _SPLLDIV1 (1)
#define _SPLLDIV2 (1)
#define _FIRCDIV1 (1)
#define _FIRCDIV2 (1)
#define _SIRCDIV1 (1)
#define _SIRCDIV2 (1)
#define _SOSCDIV1 (1)
#define _SOSCDIV2 (1)

#define PLLDIV1 0
#define PLLDIV2 1
#define PLLDIV3 2
#define PLLDIV4 3
#define PLLDIV5 4
#define PLLDIV6 5
#define PLLDIV7 6
#define PLLDIV8 7

#define PLLMULT16 0UL
#define PLLMULT40 (40 - 16)
#define PLLMULT47 (47 - 16)

/*
 * VCOPLL = 320MHz
 * SPLL 160MHz
 *
 * */
// setup reset for PLL Lock lost.
//		VCO_CLK = 320 MHz, SPLL_CLK = 160 MHz
//		• SCG_RCCR[SCS] = 0110b
//		• SCG_RCCR[DIVCORE] = 0001b
//		• SCG_RCCR[DIVBUS] = 0001b
//		• SCG_RCCR[DIVSLOW] = 0010b
//

#define SYSTEMCLICK_SCS_OSC_CLK  1UL
#define SYSTEMCLICK_SCS_SIRC_CLK 2UL
#define SYSTEMCLICK_SCS_FIRC_CLK 3UL
#define SYSTEMCLICK_SCS_SPLL_CLK 6UL

#define PLL_CONFIG ((PLLDIV1 << 8) | (PLLMULT40 << 16))

#define CLOCKoUT_SELECT (0)

#define CLOCK_SOURCE_ADC1   (SYSTEMCLICK_SCS_FIRC_CLK << 24)
#define CLOCK_SOURCE_LPSPI0 (SYSTEMCLICK_SCS_FIRC_CLK << 24)
#define CLOCK_SOURCE_LPSPI1 (SYSTEMCLICK_SCS_FIRC_CLK << 24)
#define CLOCK_SOURCE_LPSPI2 (SYSTEMCLICK_SCS_FIRC_CLK << 24)
#define CLOCK_SOURCE_LPIT   CLOCKSET_PCC(SYSTEMCLICK_SCS_SIRC_CLK, 0, 0)

#define CLOCK_SOURCE_FTM0 (SYSTEMCLICK_SCS_OSC_CLK << 24)
#define CLOCK_SOURCE_FTM1 (SYSTEMCLICK_SCS_SPLL_CLK << 24)
#define CLOCK_SOURCE_FTM2 (SYSTEMCLICK_SCS_OSC_CLK << 24)
#define CLOCK_SOURCE_FTM3 (SYSTEMCLICK_SCS_SPLL_CLK << 24)
#define CLOCK_SOURCE_FTM4 (SYSTEMCLICK_SCS_SPLL_CLK << 24)
#define CLOCK_SOURCE_FTM5 (SYSTEMCLICK_SCS_OSC_CLK << 24)

#define CLOCK_SOURCE_ADC0 (SYSTEMCLICK_SCS_FIRC_CLK << 24)

#define CLOCK_SOURCE_LPTMR0 CLOCKSET_PCC(SYSTEMCLICK_SCS_OSC_CLK, 0, 0)
#define CLOCK_SOURCE_FLEXIO CLOCKSET_PCC(SYSTEMCLICK_SCS_OSC_CLK, 0, 0)
#define CLOCK_SOURCE_LPI2C0 CLOCKSET_PCC(SYSTEMCLICK_SCS_OSC_CLK, 0, 0)

#define CLOCK_SOURCE_LPUART0 CLOCKSET_PCC(SYSTEMCLICK_SCS_OSC_CLK, 0, 0)
#define CLOCK_SOURCE_LPUART1 CLOCKSET_PCC(SYSTEMCLICK_SCS_FIRC_CLK, 0, 0)
#define CLOCK_SOURCE_LPUART2 CLOCKSET_PCC(SYSTEMCLICK_SCS_FIRC_CLK, 0, 0)

#endif

#define _RCM_SRIE_ ((3UL) | (1UL << 7) | (1UL << 5))

#define _SCG_RCCR_ \
    ((_SCG_RCCR_SCS) | (_SCG_RCCR_DIVCORE) | (_SCG_RCCR_DIVBUS) | (_SCG_RCCR_DIVSLOW))

#ifdef __cplusplus
}
#endif

#endif /* GUARD_B448F597_7AF1_4ABE_B91B_63012BEC6E72 */