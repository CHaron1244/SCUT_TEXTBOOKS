###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = 80C51
COMPILER = "ASEM-51 (Proteus)"
TARGET = Debug
SHELL = C:\Windows\system32\cmd.exe

## Tools general options

## Processing Tools
ASM=asem.exe
DDX=ASEMDDX.EXE
#  E:/博士后/教学/计组实验 教学改革/实验 数字系列待补充/组成原理实验系列/组成原理实验3.4    存储器/80C51/Debug/Debug.HEX: TOOL=ASM
#  Post: $(DDX) $(DDXFLAGS) Debug.lst
#     E:/博士后/教学/计组实验 教学改革/实验 数字系列待补充/组成原理实验系列/组成原理实验3.4    存储器/80C51/Program.asm

# Build tree:
all:	Debug

Debug:	Debug.HEX

Debug.HEX:	../Program.asm 
	$(ASM) "..\Program.asm" "Debug.HEX" Debug.lst $(ASMFLAGS)  /INCLUDES:"C:\Program Files\Labcenter Electronics\Proteus 8 Professional\Tools\ASEM51"
	$(DDX) $(DDXFLAGS) Debug.lst

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Debug.lst

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.HEX
	rm -rf Debug.SDI

