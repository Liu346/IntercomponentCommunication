################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../CC3220SF_LAUNCHXL_FREERTOS.cmd 

SYSCFG_SRCS += \
../codestructure.syscfg 

C_SRCS += \
./syscfg/ti_drivers_config.c \
../debug.c \
../main_freertos.c \
../sensor_task.c \
../sensor_thread_queue.c \
../sensor_thread_state.c \
../timer500.c \
../timer70.c \
../timerled.c \
../uart_thread.c \
../uart_thread_queue.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./syscfg/ti_drivers_config.d \
./debug.d \
./main_freertos.d \
./sensor_task.d \
./sensor_thread_queue.d \
./sensor_thread_state.d \
./timer500.d \
./timer70.d \
./timerled.d \
./uart_thread.d \
./uart_thread_queue.d 

OBJS += \
./syscfg/ti_drivers_config.obj \
./debug.obj \
./main_freertos.obj \
./sensor_task.obj \
./sensor_thread_queue.obj \
./sensor_thread_state.obj \
./timer500.obj \
./timer70.obj \
./timerled.obj \
./uart_thread.obj \
./uart_thread_queue.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/ti_utils_build_linker.cmd.exp \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"syscfg\ti_drivers_config.obj" \
"debug.obj" \
"main_freertos.obj" \
"sensor_task.obj" \
"sensor_thread_queue.obj" \
"sensor_thread_state.obj" \
"timer500.obj" \
"timer70.obj" \
"timerled.obj" \
"uart_thread.obj" \
"uart_thread_queue.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\ti_utils_build_linker.cmd.exp" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"syscfg\ti_drivers_config.d" \
"debug.d" \
"main_freertos.d" \
"sensor_task.d" \
"sensor_thread_queue.d" \
"sensor_thread_state.d" \
"timer500.d" \
"timer70.d" \
"timerled.d" \
"uart_thread.d" \
"uart_thread_queue.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

SYSCFG_SRCS__QUOTED += \
"../codestructure.syscfg" 

C_SRCS__QUOTED += \
"./syscfg/ti_drivers_config.c" \
"../debug.c" \
"../main_freertos.c" \
"../sensor_task.c" \
"../sensor_thread_queue.c" \
"../sensor_thread_state.c" \
"../timer500.c" \
"../timer70.c" \
"../timerled.c" \
"../uart_thread.c" \
"../uart_thread_queue.c" 


