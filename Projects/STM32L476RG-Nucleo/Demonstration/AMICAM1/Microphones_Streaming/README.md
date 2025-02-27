## __Microphone Streaming Application__

This document provides a description of the microphone streaming application based 
on Nucleo boards and X-NUCLEO-AMICAM1 expansion board. It allows acquisition of 
up to 4 analog MEMS microphones and streaming towards a host PC via a dedicated USB
Audio Input driver.
It is designed to be compatible with different MCU families, thus NUCLEO-L476 or 
NUCLEO-L4R5ZI boards can be adopted. 
It is possible to acquire up to four microphones at a maximum sampling frequency of
96 KHz or two microphones at 192KHz.

NOTE: if you want to use a sampling frequency of 16KHz, you must close the soldier bridge
SB11 to pass to the on-board ADC a required extra signal, the I2S master clock. 

A analog MEMS microphone can be acquired by using different peripherals, 
such as  I2S, SPI or DFSDM, using on-board external ADC or STM32 embedded ADC.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals. 
Then the SystemClock_Config() function is used to configure the system clock (SYSCLK). 
The resulting system clock speed depends on the MCU used and it's equal to 80MHz for 
STM32L4

At this point the following steps are required:

- USB Audio In configuration:
At first the USB descriptor is set up according to the number of channels 
to be streamed and the desired frequency. This allows the device to be 
recognized as a standard USB microphone with the requested configuration. 
Then the firmware initializes USB core and start USB functionalities 
with the standard USB Device functions.

- Audio peripheral configuration and start of the acquisition: 
Using BSP layer and Middlewares functionalities, all the required peripherals and 
libraries are configured, basing on the number of channels to be streamed and the 
desired sampling frequency to be achieved. These steps start inside the 
usbd_audio_if.c file, whose functions are called in response to the USB enumeration 
that starts when the device is connected to the PC. 
An alternative approach would be to manage the configuration and starting of the 
audio peripherals by calling directly the BSP functionalities from the application
space.
In the firmware, audio-related parts, concerning action to be performed in response 
to DMA callbacks, are collected in the audio_application.c 

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

### __Directory contents__

  - MicrophoneStreaming/Src/stm32xx_it.c            	Interrupt handlers file 
  - MicrophoneStreaming/Src/system_stm32f4xx.c      	STM32F4xx system clock configuration file
  - MicrophoneStreaming/Src/system_stm32l4xx.c      	STM32L4xx system clock configuration file
  - MicrophoneStreaming/Src/system_stm32f7xx.c      	STM32F7xx system clock configuration file
  - MicrophoneStreaming/Src/usbd_audio_if.c	        	USBD Audio-input interface  
  - MicrophoneStreaming/Src/usbd_conf_l4.c    			USB device driver Configuration file for STM32L4
  - MicrophoneStreaming/Src/usbd_desc.c    				USB device AUDIO-input descriptor   
  - MicrophoneStreaming/Src/cube_hal_l4.c           	Clock configuration file for STM32L4
  - MicrophoneStreaming/Src/main.c                  	Main program	
  - MicrophoneStreaming/Src/audio_application.c     	Audio application file  
  - MicrophoneStreaming/Inc/stm32l4xx_hal_conf.h    	HAL configuration file for STM32L4
  - MicrophoneStreaming/Inc/amicam1_conf.h 	X-NUCLEO-AMICAM1 configuration file
  - MicrophoneStreaming/Inc/amicam1_errno.h	Error file
  - MicrophoneStreaming/Inc/stm32xx_it.h          		Interrupt handlers header file 
  - MicrophoneStreaming/Inc/main.h                  	Main program header file
  - MicrophoneStreaming/Inc/cube_hal.h			    	X-CUBE includes file
  - MicrophoneStreaming/Inc/audio_application.h  		Application header file
  - MicrophoneStreaming/Inc/usbd_audio_if.h		    	USBD Audio-input interface header file  
  - MicrophoneStreaming/Inc/usbd_conf.h    				USB device driver Configuration file
  - MicrophoneStreaming/Inc/usbd_desc.h    				USB device AUDIO-input descriptor header file	

### __Hardware and Software environment__

  - This example runs on STM32L476RG devices.
    
  - This example has been tested with STMicroelectronics NUCLEO-L476RG RevC
    boards and can be easily tailored to any other supported device 
    and development board.
    

### __How to use it ?__

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 - In order to stream audio via USB, connect X-NUCLEO-AMICAM1 USB connector to a host PC