# This is a makefile for our source files 
SRC_DIR     = src
CMSIS_DIR   = CMSIS
INCLUDE_DIR = include

# List all your source files here
SRCS = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/TIM_Driver.c \
$(SRC_DIR)/led.c \
$(SRC_DIR)/GPIO_stm32f4.c \
$(SRC_DIR)/Timer.c \
$(SRC_DIR)/pwm.c \
$(CMSIS_DIR)/stm32.startup.c

# List all your include directories here
INCLUDES = \
-I$(INCLUDE_DIR) \
-I$(CMSIS_DIR)