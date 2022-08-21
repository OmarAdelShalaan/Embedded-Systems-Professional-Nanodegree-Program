################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Card/card.c 

C_DEPS += \
./Card/card.d 

OBJS += \
./Card/card.o 


# Each subdirectory must supply rules for building sources it contributes
Card/%.o: ../Card/%.c Card/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Card

clean-Card:
	-$(RM) ./Card/card.d ./Card/card.o

.PHONY: clean-Card

