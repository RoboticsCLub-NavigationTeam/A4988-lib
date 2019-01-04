#include "a4988.h"

void A4988_setDirection(struct A4988 *stepper, uint32_t dir)
{
        if (dir) {
                HAL_GPIO_WritePin(stepper->dir_port, stepper->dir_pin, GPIO_PIN_SET);
        }
        else {
                HAL_GPIO_WritePin(stepper->dir_port, stepper->dir_pin, GPIO_PIN_RESET);
        }
}


void A4988_toggleDirection(struct A4988 *stepper)
{
        HAL_GPIO_TogglePin(stepper->dir_port, stepper->dir_pin);
}


void A4988_step(struct A4988 *stepper)
{
        HAL_GPIO_WritePin(stepper->step_port, stepper->step_pin, GPIO_PIN_RESET);
        asm volatile("nop");
        asm volatile("nop");
        HAL_GPIO_WritePin(stepper->step_port, stepper->step_pin, GPIO_PIN_SET);
        for (uint32_t i = 0; i < 10; ++i) {
                asm volatile("nop");
        }
        HAL_GPIO_WritePin(stepper->step_port, stepper->step_pin, GPIO_PIN_RESET);
        asm volatile("nop");
        asm volatile("nop");
}
