################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Atom.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Cmu.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dpll.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dtm.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Psm.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Spe.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tbu.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tim.c \
../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tom.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Atom.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Cmu.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dpll.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dtm.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Psm.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Spe.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tbu.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tim.o \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tom.o 

COMPILED_SRCS += \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Atom.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Cmu.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dpll.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dtm.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Psm.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Spe.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tbu.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tim.src \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tom.src 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Atom.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Cmu.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dpll.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dtm.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Psm.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Spe.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tbu.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tim.d \
./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tom.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/%.src: ../libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/%.c libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc37x "-fD:/MyPrograms/MyAURIXPrograms/E08_04_gps_tau1201_ips200_display_demo/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/%.o: ./libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/%.src libraries/infineon_libraries/iLLD/TC37A/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


