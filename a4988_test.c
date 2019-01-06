void a4988_test(){
    struct A4988 stepper;

        stepper.steps_per_rev = 200;
        stepper.dir_port = GPIOC;
        stepper.dir_pin = GPIO_PIN_0;
        stepper.step_port = GPIOA;
        stepper.step_pin = GPIO_PIN_2;
    
        A4988_setDirection(&stepper, 0);
    
            for(int i = 0; i < stepper.steps_per_rev ; i++)
            {
              A4988_step(&stepper);
              HAL_Delay(1);
            }
    
            HAL_Delay(1000);
            A4988_toggleDirection(&stepper);
    
    
            for(int i = 0; i < stepper.steps_per_rev ; i++)
            {
              A4988_step(&stepper);
              HAL_Delay(1);
            }

}

