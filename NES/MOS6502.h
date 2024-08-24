#pragma once

#include "Bus.h"
#include <string>
#include <vector>

using namespace std;

//Desgraça pelada, porra de processador, porra de caralho de processador

class Bus;

class MOS6502
{
	
public:
	MOS6502();
	~MOS6502();

	void ConnectBus(Bus* n) { bus = n; }

	enum FLAGS { 

		C = (1 << 0), //	Carry Flag
		Z = (1 << 1), //	Zero Flag
		I = (1 << 2), //	Interrupt Disable
		D = (1 << 3), //	Decimal Mode (Não iremos usar isso na nossa implementação)
		B = (1 << 4), //	Break Command
		U = (1 << 5), //	Sem Utilidade
		V = (1 << 6), //	Overflow Flag
		N = (1 << 7), //	Negative Flag
	};

	//Interrupções

	void NMI();		//Non-Maskable Interrupt
	void IRQ();		//Maskable Interrupts
	void RESET();	//Reset
	void CLOCK();   //Clock
	

	uint16_t	pc = 0x0000;		//Program Counter (PC)
	uint8_t		sp = 0x00;			//Stack Pointer (SP)
	uint8_t		ac = 0x00;			//Accumulator (A)
	uint8_t		X  = 0x00;			//Index Register X
	uint8_t		Y  = 0x00;			//Index Register Y
	uint8_t		sts_flag = 0x00;	//Processor Status(P)

private:
	
	Bus*     bus = nullptr;
	uint8_t  read(uint16_t address);
	void	 write(uint16_t address, uint8_t data);

	void     setFlag(FLAGS f, bool b);
	uint8_t  getFlag(FLAGS f);

	uint8_t  fetch();
	uint8_t  fetched = 0x00;

	uint16_t addr_abs = 0x0000;
	uint16_t addr_rel = 0x0000;
	uint8_t  opcode = 0x00;
	uint8_t  cycles = 0x00;

	typedef struct { // Declaração da estrutura que define a instr

		string name;
		uint8_t(MOS6502::* operate)(void) = nullptr;
		uint8_t(MOS6502::* addrmode)(void) = nullptr;
		uint8_t cycles = 0;

	}INSTRUCTION;

	vector<INSTRUCTION>opcode_matrix; //esse demônio aqui


private: // Modos de Enderaçamento



	uint8_t	ZP0();		// Zero Page Addressing [ZP]
	uint8_t ZPX();		// Indexed Zero Page Addressing [ZP, X]
	uint8_t XPY();		// Indexed Zero Page Addressing [ZP, Y]
	uint8_t ABS();		// Absolute Addressing [Absolute]
	uint8_t ABSX();		// Indexed Absolute Addressing [ABS, X]
	uint8_t ABSY();		// Indexed Absolute Addressing [ABS, Y]
	uint8_t IMP();		// Implied Addressing [Implied]
	uint8_t ACC();		// Accumulator Addressing [Accum]
	uint8_t IMM();		// Immediate Address [IMM]
	uint8_t REL();		// Relative Addressing [Relative]
	uint8_t INDX();		// Indexed Indirect Addressing [(IND, X)]
	uint8_t INDY();		// Indirect Indexed Addressing [(IND, Y)]
	uint8_t ABI();		// Absolute Indirect [Indirect]


private: // Instruções

	uint8_t ADC(); uint8_t AND(); uint8_t ASL(); uint8_t BCC(); 
	uint8_t BCS(); uint8_t BEQ(); uint8_t BIT(); uint8_t BMI(); 
	uint8_t BNE(); uint8_t BPL(); uint8_t BRK(); uint8_t BVC();
	uint8_t BVS(); uint8_t CLC(); uint8_t CLD(); uint8_t CLI(); 
	uint8_t CLV(); uint8_t CMP(); uint8_t CPX(); uint8_t CPY(); 
	uint8_t DEC(); uint8_t DEX(); uint8_t DEY(); uint8_t EOR();
	uint8_t INC(); uint8_t INX(); uint8_t INY(); uint8_t JMP(); 
	uint8_t JSR(); uint8_t LDA(); uint8_t LDX(); uint8_t LDY(); 
	uint8_t LSR(); uint8_t NOP(); uint8_t ORA(); uint8_t PHA();
	uint8_t PHP(); uint8_t PLA(); uint8_t PLP(); uint8_t ROL(); 
	uint8_t ROR(); uint8_t RTI(); uint8_t RTS(); uint8_t SBC(); 
	uint8_t SEC(); uint8_t SED(); uint8_t SEI(); uint8_t STA(); 
	uint8_t STX(); uint8_t STY(); uint8_t TAX(); uint8_t TAY(); 
	uint8_t TSX(); uint8_t TXA(); uint8_t TXS(); uint8_t TYA();

	uint8_t XXX(); //essa instrução são para os opcodes ilegais

};

