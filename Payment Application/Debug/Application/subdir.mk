################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/app.c 

C_DEPS += \
./Application/app.d 

OBJS += \
./Application/app.o 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o: ../Application/%.c Application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Application

clean-Application:
	-$(RM) ./Application/app.d ./Application/app.o

.PHONY: clean-Application

