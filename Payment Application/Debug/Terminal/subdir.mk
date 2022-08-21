################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Terminal/terminal.c 

C_DEPS += \
./Terminal/terminal.d 

OBJS += \
./Terminal/terminal.o 


# Each subdirectory must supply rules for building sources it contributes
Terminal/%.o: ../Terminal/%.c Terminal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Terminal

clean-Terminal:
	-$(RM) ./Terminal/terminal.d ./Terminal/terminal.o

.PHONY: clean-Terminal

