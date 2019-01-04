#ifndef _A4988_H_
#define _A4988_H_


#include "gpio.h"

struct A4988
{
        uint32_t steps_per_rev;
        GPIO_TypeDef *dir_port, *step_port;
        uint32_t dir_pin, step_pin;
        float omega;
};

void A4988_setDirection(struct A4988 *stepper, uint32_t dir);
void A4988_toggleDirection(struct A4988 *stepper);

void A4988_step(struct A4988 *stepper);

#endif // !_A4988_H_
