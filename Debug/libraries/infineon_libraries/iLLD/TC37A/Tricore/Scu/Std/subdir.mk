################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.o 

COMPILED_SRCS += \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.src 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/%.src: ../libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/%.c libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc37x "-fD:/MyPrograms/MyAURIXPrograms/E08_04_gps_tau1201_ips200_display_demo/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/%.o: ./libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/%.src libraries/infineon_libraries/iLLD/TC37A/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


