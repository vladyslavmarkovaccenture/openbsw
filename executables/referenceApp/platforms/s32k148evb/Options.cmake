set(OPENBSW_PLATFORM s32k1xx)

set(PLATFORM_SUPPORT_IO
    ON
    CACHE BOOL "Turn IO support on or off" FORCE)
set(PLATFORM_SUPPORT_CAN
    ON
    CACHE BOOL "Turn CAN support on or off" FORCE)
set(PLATFORM_SUPPORT_UDS
    ON
    CACHE BOOL "Turn UDS support on or off" FORCE)
set(PLATFORM_SUPPORT_WATCHDOG
    ON
    CACHE BOOL "Turn ON Watchdog support" FORCE)
set(PLATFORM_SUPPORT_MPU
    ON
    CACHE BOOL "Turn ON MPU support" FORCE)
