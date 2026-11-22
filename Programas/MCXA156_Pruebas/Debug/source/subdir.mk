################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MCXA156_Pruebas.c \
../source/as5600_app.c \
../source/lcd_i2c.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/MCXA156_Pruebas.d \
./source/as5600_app.d \
./source/lcd_i2c.d \
./source/semihost_hardfault.d 

OBJS += \
./source/MCXA156_Pruebas.o \
./source/as5600_app.o \
./source/lcd_i2c.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MCXA156VLL -DCPU_MCXA156VLL_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\drivers" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\CMSIS" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\CMSIS\m-profile" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\utilities" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\utilities\debug_console" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\device" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\device\periph1" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\component\serial_manager" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\component\lists" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\utilities\str" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\component\uart" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\utilities\debug_console\config" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\board" -I"C:\Users\joelc\Desktop\MCXA156_Pruebas\source" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/MCXA156_Pruebas.d ./source/MCXA156_Pruebas.o ./source/as5600_app.d ./source/as5600_app.o ./source/lcd_i2c.d ./source/lcd_i2c.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

