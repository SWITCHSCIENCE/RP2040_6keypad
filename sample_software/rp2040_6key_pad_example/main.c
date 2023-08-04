/**
 * Copyright (c) 2023 Switch Science, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

#define BUTTON_GPIO 0
#define BUTTON_GPIO1 1
#define BUTTON_GPIO2 2
#define BUTTON_GPIO3 3
#define BUTTON_GPIO4 4
#define BUTTON_GPIO5 5

#define LED0 25
#define LED1 28
#define LED2 27
#define LED3 26

int main() {
    stdio_init_all();

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);
    gpio_set_input_hysteresis_enabled(BUTTON_GPIO, 1);

    gpio_init(BUTTON_GPIO1);
    gpio_set_dir(BUTTON_GPIO1, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO1);
    gpio_set_input_hysteresis_enabled(BUTTON_GPIO1, 1);

    gpio_init(BUTTON_GPIO2);
    gpio_set_dir(BUTTON_GPIO2, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO2);
    gpio_set_input_hysteresis_enabled(BUTTON_GPIO2, 1);

    gpio_init(BUTTON_GPIO3);
    gpio_set_dir(BUTTON_GPIO3, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO3);
    gpio_set_input_hysteresis_enabled(BUTTON_GPIO3, 1);

    gpio_init(BUTTON_GPIO4);
    gpio_set_dir(BUTTON_GPIO4, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO4);
    gpio_set_input_hysteresis_enabled(BUTTON_GPIO4, 1);

    gpio_init(BUTTON_GPIO5);
    gpio_set_dir(BUTTON_GPIO5, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO5);
    gpio_set_input_hysteresis_enabled(BUTTON_GPIO5, 1);

    gpio_init(LED0);
    gpio_set_dir(LED0, GPIO_OUT);
    gpio_disable_pulls(LED0);
    gpio_put(LED0, 0);

    gpio_init(LED1);
    gpio_set_dir(LED1, GPIO_OUT);
    gpio_disable_pulls(LED1);
    gpio_put(LED1, 1);

    gpio_init(LED2);
    gpio_set_dir(LED2, GPIO_OUT);
    gpio_disable_pulls(LED2);
    gpio_put(LED2, 1);

    gpio_init(LED3);
    gpio_set_dir(LED3, GPIO_OUT);
    gpio_disable_pulls(LED3);
    gpio_put(LED3, 1);

    uint8_t btn0 = 0;
    uint8_t btn1 = 0;
    uint8_t btn2 = 0;
    uint8_t btn3 = 0;
    uint8_t btn4 = 0;
    uint8_t btn5 = 0;

    uint8_t btn0_prev = 0;
    uint8_t btn1_prev = 0;
    uint8_t btn2_prev = 0;
    uint8_t btn3_prev = 0;
    uint8_t btn4_prev = 0;
    uint8_t btn5_prev = 0;

    while (true) {
        btn0 = !gpio_get(BUTTON_GPIO);
        btn1 = !gpio_get(BUTTON_GPIO1);
        btn2 = !gpio_get(BUTTON_GPIO2);
        btn3 = !gpio_get(BUTTON_GPIO3);
        btn4 = !gpio_get(BUTTON_GPIO4);
        btn5 = !gpio_get(BUTTON_GPIO5);

        gpio_put(LED1, !(btn0 | btn3));
        gpio_put(LED2, !(btn1 | btn4));
        gpio_put(LED3, !(btn2 | btn5));

        if((btn0 == 1) && (btn0_prev == 0)){
            printf("Button0 Pressed\n");
        }
        if ((btn1 == 1) && (btn1_prev == 0)) {
            printf("Button1 Pressed\n");
        }
        if ((btn2 == 1) && (btn2_prev == 0)) {
            printf("Button2 Pressed\n");
        }
        if ((btn3 == 1) && (btn3_prev == 0)) {
            printf("Button3 Pressed\n");
        }
        if ((btn4 == 1) && (btn4_prev == 0)) {
            printf("Button4 Pressed\n");
        }
        if ((btn5 == 1) && (btn5_prev == 0)) {
            printf("Button5 Pressed\n");
        }

        btn0_prev = btn0;
        btn1_prev = btn1;
        btn2_prev = btn2;
        btn3_prev = btn3;
        btn4_prev = btn4;
        btn5_prev = btn5;

        sleep_ms(1);

    }
    return 0;
}
