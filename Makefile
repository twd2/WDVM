myasm: main.o CPU.o CPU_Registers.o CPU_Instructions.o Memory.o Machine.o InterruptInfo.o BinaryHelper.o ParameterInfo.o InstructionInfo.o
	g++ -O2 -o myasm BinaryHelper.o main.o InterruptInfo.o CPU.o CPU_Registers.o CPU_Instructions.o Memory.o Machine.o  ParameterInfo.o InstructionInfo.o
myasm_static: myasm
	g++ -O2 -static -o myasm_static main.o CPU.o Memory.o Machine.o BinaryHelper.o ParameterInfo.o InstructionInfo.o
main.o: main.cpp main.hpp Machine.hpp
	g++ -O2 -c main.hpp main.cpp
CPU.o: CPU.cpp CPU.hpp Memory.hpp InterruptInfo.hpp type.hpp CPU_Registers.cpp CPU_Instructions.cpp
	g++ -O2 -c CPU.hpp CPU.cpp CPU_Registers.cpp CPU_Instructions.cpp
CPU_Registers.o: CPU.cpp CPU.hpp Memory.hpp InterruptInfo.hpp type.hpp CPU_Registers.cpp CPU_Instructions.cpp
	g++ -O2 -c CPU.hpp CPU_Registers.cpp
CPU_Instructions.o: CPU.cpp CPU.hpp Memory.hpp InterruptInfo.hpp type.hpp CPU_Registers.cpp CPU_Instructions.cpp
	g++ -O2 -c CPU.hpp InterruptInfo.hpp CPU_Instructions.cpp
InterruptInfo.o: InterruptInfo.cpp InterruptInfo.hpp CPU.hpp
	g++ -O2 -c InterruptInfo.hpp InterruptInfo.cpp CPU.hpp
Memory.o: Memory.cpp Memory.hpp BinaryHelper.hpp InstructionInfo.hpp type.hpp
	g++ -O2 -c Memory.hpp Memory.cpp
Machine.o: Machine.cpp Machine.hpp InterruptInfo.hpp CPU.hpp Memory.hpp type.hpp
	g++ -O2 -c Machine.hpp Machine.cpp
BinaryHelper.o: BinaryHelper.cpp BinaryHelper.hpp
	g++ -O2 -c BinaryHelper.hpp BinaryHelper.cpp
ParameterInfo.o: ParameterInfo.cpp ParameterInfo.hpp BinaryHelper.hpp type.hpp
	g++ -O2 -c ParameterInfo.hpp ParameterInfo.cpp
InstructionInfo.o: InstructionInfo.cpp InstructionInfo.hpp ParameterInfo.hpp type.hpp BinaryHelper.hpp
	g++ -O2 -c InstructionInfo.hpp InstructionInfo.cpp
clean: 
	-rm myasm myasm_static main.o CPU.o CPU_Registers.o CPU_Instructions.o InterruptInfo.o Memory.o Machine.o BinaryHelper.o ParameterInfo.o InstructionInfo.o *.gch
release: main
	make
	-mkdir release
	cp myasm release/
	#make clean
