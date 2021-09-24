################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1122224959: ../codestructure.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1040/ccs/utils/sysconfig_1.9.0/sysconfig_cli.bat" -s "C:/simplelink_cc32xx_sdk_4_20_00_07/.metadata/product.json" --script "C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure/codestructure.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-1122224959 ../codestructure.syscfg
syscfg/ti_drivers_config.h: build-1122224959
syscfg/ti_utils_build_linker.cmd.exp: build-1122224959
syscfg/syscfg_c.rov.xs: build-1122224959
syscfg/: build-1122224959

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure" --include_path="C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure/Debug" --include_path="C:/simplelink_cc32xx_sdk_4_20_00_07/source" --include_path="C:/simplelink_cc32xx_sdk_4_20_00_07/source/ti/posix/ccs" --include_path="C:/FreeRTOSv202107.00/FreeRTOS/Source/include" --include_path="C:/FreeRTOSv202107.00/FreeRTOS/Source/portable/CCS/ARM_CM3" --include_path="C:/Users/Jacob Carroll/workspace_alpha/freertos_builds_CC3220SF_LAUNCHXL_release_ccs" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=__SF_DEBUG__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure" --include_path="C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure/Debug" --include_path="C:/simplelink_cc32xx_sdk_4_20_00_07/source" --include_path="C:/simplelink_cc32xx_sdk_4_20_00_07/source/ti/posix/ccs" --include_path="C:/FreeRTOSv202107.00/FreeRTOS/Source/include" --include_path="C:/FreeRTOSv202107.00/FreeRTOS/Source/portable/CCS/ARM_CM3" --include_path="C:/Users/Jacob Carroll/workspace_alpha/freertos_builds_CC3220SF_LAUNCHXL_release_ccs" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=__SF_DEBUG__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/Jacob Carroll/Downloads/SimpleCodeStructure-main/SimpleCodeStructure/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


