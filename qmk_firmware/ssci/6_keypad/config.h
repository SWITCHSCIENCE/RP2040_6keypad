// Copyright (c) 2023 Switch Science, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define LED_NUM_LOCK_PIN GP28
#define LED_CAPS_LOCK_PIN GP27
#define LED_SCROLL_LOCK_PIN GP26
#define LED_PIN_ON_STATE 0
