# Section 3 Work

> **DISCLAIMER:** This work section is not a full guide or walkthrough on how to configure the settings in STM32CubeMX, ***and every board model may have a different setup process***. You may need to use external resources in order to complete these exercises.

## Exercise 1: Using a Button to Turn On an LED

 In this exercise, you will read a input from a button and output to a LED using GPIO pins in your main loop. 
 
 You will need to generate a new project using ```Access the Board Selector``` and search for the ```NUCLEO-F030R8``` in the ```Commercial Part Number``` bar, and initialize all peripherals as default. You will then need to find the GPIO pins connected to the blue user button and LED in your ```.ioc``` file using STM32CubeMX.

> Note: It is VERY important to keep your code within the ```/* USER CODE BEGIN */``` comments, otherwise your code will be deleted when you update your ```.ioc``` file.

 Using the ```HAL_GPIO_ReadPin()``` and ```HAL_GPIO_WritePin()``` functions, have the LED turn on when the button is pressed and off when the button is not pressed.

## Exercise 2: Using Button Interrupts to Turn On an LED

In this exercise, you will learn how to use interrupts to turn on the LED using the button as opposed to polling in Exercise 1.

To set up an interrupt pin, open up your ```.ioc``` file in STM32CubeMX. You will need to configure the GPIO mode on the pin corresponding to your button in ```External Interrupt Mode with Falling Edge Trigger Detection``` 

You will need to use the ```HAL_GPIO_EXTI_Callback()``` function, preferrably after the ```/* USER CODE BEGIN 4 */``` section.

## Exercise 3: Reading Analog Voltages with the ADC using DMA

In this exercise, you will use the ADC, timers, and DMA peripherals to read voltages from an external source such as a wavegen, DC power supply, or another microcontroller. 

The ADC will need to run at 10kHz. This can be done by attaching and configuring a timer peripheral to the ADC in STM32CubeMX.

You will also need to use DMA writing. Make sure that ```Continuous Conversion Mode``` and ```DMA Continuous Requests``` are enabled. The DMA mode should be ```Circular``` as you want to continuously collect data after the buffer is full. You will need to use the ```HAL_ADC_ConvCpltCallback()``` to process the raw ADC data and convert it to a voltage. Setting up a double-buffer is not required, but encouraged.

You will need to find a way to display the converted voltage values either through the **Live Expressions** tab under the debugging session, or the **Serial Wire Viewer**.