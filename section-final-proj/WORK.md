~~# Final project: Acceleration Pedal Position Simulator~~

## There is a final project that will be done as a team.

The final project is TBD. It will be done with a combination of firmware and electrical members. You should be able to work between disciplines (although electrical and embedded are extremely intertwined nowadays.)

Please ensure your fork is public and ready to be graded. 






# Project if you intend to skip the onboarding (on top of resume and interview)

Design an STM32 program to act as a DAQ system. It should have a FreeRTOS system. Set up a git repo to be checked by us. Program a branch following MISRA C conventions, i.e. as if it were a hard real-time system. The DAQ would not normally be a hard real-time system, but this is just for us to test you. You're not expected to already know this, but it's a good test to show that you're willing to put in basic effort to learn to program the 'proper' way for firmware.

>Note that MISRA C isn't strictly necessary for **all** firmware. But it's very useful for hard real-time systems.

Assume that the STM32 has input from 4 I2C devices (address 0x00 - 0x03), all on the same bus. Each I2C input gives 2 bytes (uint16_t) of data to the DAQ and does not output sequentially. Then, output these inputs over a CAN line. If you use classic CAN, your data field is limited to 8 bytes, which should be just enough for this project. You don't need to include any metadata in the CAN data field, just forward the data sequentially from i2c_0 to i2c_3. Assume the CAN identifier to the external microcontroller is ```0x3FF```.

Try to make your code efficient, thread-safe, non-blocking, and easy to read. Try utilizing DMA to optimize your program.

### More details

You should use STM32CubeMX for the initiialization of this program. Assume an STM32 G474RE microcontroller.

**DO NOT USE AI FOR THIS**. We expect mistakes and we will review them and tell you how to improve your code. What's most important is that you LEARN. Make use of git and have good, well-explained messages with your commits. **DO NOT DO THIS ALL IN ONE COMMIT**. If your code is readable, there shouldn't be a need for many comments. If your code is not, then you need to re-write it. Use doc comments for complex or not immediately understandable functions. You don't need an STM32 to test this, but you need to ensure your program compiles.

This isn't a massive program, but it tests many foundations. It may take you some time to do this and you may make some mistakes, but that's perfectly acceptable. As long as you learn along the way and are willing to ask questions, you can do this project!

On top of this, it would be a good idea to read the rest of the sections in this repo and make sure you have a basic grasp of everything covered. You don't need to do the projects associated if you don't want to, just this one.

The interview is not high-stress, we'll just ask you some questions about projects you've done in the past and what you'd like to work on.

If you have some experience with microcontrollers and are willing to read, you can do this project with some effort. I would encourage you to clone and look at the code in the EV27's Battery Management System (starting at bms/Core/src/main.c) if you need help seeing general coding practices. **You will probably not understand the BMS code. That is okay. Look at some of the threads and functions to see general firmware/MISRA C coding practices. Ask questions if you need to, but also be willing to look up what things do on your own.** 

If you don't wish to do this project (or feel it's **completely** out of your skill area at this time), you're more than welcome to do the normal onboarding process.

Good luck!!