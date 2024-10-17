// Copyright 2024 Accenture.

/**
 * Contains bus identifier class BusId.
 * \file
 * \ingroup common
 */
#ifndef GUARD_BFEDE919_D13E_4A5F_866C_E8021D90D2B5
#define GUARD_BFEDE919_D13E_4A5F_866C_E8021D90D2B5

#include <estd/bitset.h>
#include <platform/estdint.h>

#include <type_traits>

namespace common
{
namespace busid
{

class BusIdTraits
{
    BusIdTraits() = delete;

public:
    static char const* getName(uint8_t index);
};

} // namespace busid
} // namespace common

#endif /* GUARD_BFEDE919_D13E_4A5F_866C_E8021D90D2B5 */