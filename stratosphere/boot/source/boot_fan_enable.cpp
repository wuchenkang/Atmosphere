/*
 * Copyright (c) 2018-2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "boot_fan_enable.hpp"
#include "boot_gpio_utils.hpp"
#include "boot_spl_utils.hpp"

namespace sts::boot {

    namespace {

        /* Convenience definitions. */
        constexpr u32 GpioPadName_FanEnable = 0x4B;

    }

    void SetFanEnabled() {
        if (GetHardwareType() == spl::HardwareType::Copper) {
            gpio::Configure(GpioPadName_FanEnable);
            gpio::SetDirection(GpioPadName_FanEnable, GpioDirection_Output);
            gpio::SetValue(GpioPadName_FanEnable, GpioValue_High);
        }
    }

}
