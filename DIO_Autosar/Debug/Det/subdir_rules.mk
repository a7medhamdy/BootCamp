################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Det/Det.obj: ../Det/Det.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-039/workspace_v8/DIO_Autosar" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --strict_ansi --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --check_misra="all" --misra_advisory=warning --misra_required=warning --preproc_with_compile --preproc_dependency="Det/Det.d_raw" --obj_directory="Det" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


