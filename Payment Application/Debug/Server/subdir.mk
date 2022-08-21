################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Server/server.c 

C_DEPS += \
./Server/server.d 

OBJS += \
./Server/server.o 


# Each subdirectory must supply rules for building sources it contributes
Server/%.o: ../Server/%.c Server/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Server

clean-Server:
	-$(RM) ./Server/server.d ./Server/server.o

.PHONY: clean-Server

