################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/sc_math/sc_math.c 

OBJS += \
./code/sc_math/sc_math.o 

COMPILED_SRCS += \
./code/sc_math/sc_math.src 

C_DEPS += \
./code/sc_math/sc_math.d 


# Each subdirectory must supply rules for building sources it contributes
code/sc_math/%.src: ../code/sc_math/%.c code/sc_math/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc37x "-fD:/MyPrograms/MyAURIXPrograms/E08_04_gps_tau1201_ips200_display_demo/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

code/sc_math/%.o: ./code/sc_math/%.src code/sc_math/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


