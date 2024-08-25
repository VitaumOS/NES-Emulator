#include "MOS6502.h"

MOS6502::MOS6502() {

	using mos = MOS6502;
	/*
	* Só pra ficar mais fácil ler enquanto tô escrevendo a tabelona
	* 
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
	*/


	opcode_matrix = {

		{"BRK", &mos::BRK, &mos::IMP, 7}, {"ORA", &mos::ORA, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ORA", &mos::ORA, &mos::ZP0, 3}, {"ASL", &mos::ASL, &mos::ZP0, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"PHP", &mos::PHP, &mos::IMP, 3}, {"ORA", &mos::ORA, &mos::IMM, 2}, {"ASL", &mos::ASL, &mos::ACC, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ORA", &mos::ORA, &mos::ABS, 4}, {"ASL", &mos::ASL, &mos::ABS, 6}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BPL", &mos::BPL, &mos::REL, 2}, {"ORA", &mos::ORA, &mos::INDY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ORA", &mos::ORA, &mos::ZPX, 4}, {"ASL", &mos::ASL, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CLC", &mos::CLC, &mos::IMP, 2}, {"ORA", &mos::ORA, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ORA", &mos::ORA, &mos::ABSX, 4}, {"ASL", &mos::ASL, &mos::ABSX, 7}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"JSR", &mos::JSR, &mos::ABS, 6}, {"AND", &mos::AND, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"BIT", &mos::BIT, &mos::ZP0, 3}, {"AND", &mos::AND, &mos::ZP0, 3}, {"ROL", &mos::ROL, &mos::ZP0, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"PLP", &mos::PLP, &mos::IMP, 4}, {"AND", &mos::AND, &mos::IMM, 2}, {"ROL", &mos::ROL, &mos::ACC, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"BIT", &mos::BIT, &mos::ABS,4}, {"AND", &mos::AND, &mos::ABS, 4}, {"ROL", &mos::ROL, &mos::ABS, 6}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BMI", &mos::BMI, &mos::REL, 2}, {"AND", &mos::AND, &mos::INDY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"AND", &mos::AND, &mos::ZPX, 4}, {"ROL", &mos::ROL, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"SEC", &mos::SEC, &mos::IMP, 2}, {"AND", &mos::AND, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"AND", &mos::AND, &mos::ABSX, 4}, {"ROL", &mos::ROL, &mos::ABSX, 7}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"RTI", &mos::RTI, &mos::IMP, 6}, {"EOR", &mos::EOR, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"EOR", &mos::EOR, &mos::ZP0, 3}, {"LSR", &mos::LSR, &mos::ZP0, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"PHA", &mos::PHA, &mos::IMP, 3}, {"EOR", &mos::EOR, &mos::IMM, 2}, {"LSR", &mos::LSR, &mos::ACC, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"JMP", &mos::JMP, &mos::ABS, 3}, {"EOR", &mos::EOR, &mos::ABS, 4}, {"LSR", &mos::LSR, &mos::ABS, 6}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BVC", &mos::BVC, &mos::REL, 2}, {"EOR", &mos::EOR, &mos::INDY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"EOR", &mos::EOR, &mos::ZPX, 4}, {"LSR", &mos::LSR, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CLI", &mos::CLI, &mos::IMP, 2}, {"EOR", &mos::EOR, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"EOR", &mos::EOR, &mos::ABSX, 4}, {"LSR", &mos::LSR, &mos::ABSX, 7}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"RTS", &mos::RTS, &mos::IMP, 6}, {"ADC", &mos::ADC, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ADC", &mos::ADC, &mos::ZP0, 3}, {"ROR", &mos::ROR, &mos::ZP0, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"PLA", &mos::PLA, &mos::IMP, 4}, {"ADC", &mos::ADC, &mos::IMM, 2}, {"ROR", &mos::ROR, &mos::ACC, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"JMP", &mos::JMP, &mos::ABI, 5}, {"ADC", &mos::ADC, &mos::ABS, 4}, {"ROR", &mos::ROR, &mos::ABS, 6}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BVS", &mos::BVS, &mos::REL, 2}, {"ADC", &mos::ADC, &mos::INSY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ADC", &mos::ADC, &mos::ZPX, 4}, {"ROR", &mos::ROR, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"SEI", &mos::SEI, &mos::IMP, 2}, {"ADC", &mos::ADC, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"ADC", &mos::ADC, &mos::ABSX, 4}, {"ROR", &mos::ROR, &mos::ABSX, 7}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"XXX", &mos::XXX, &mos::IMP, 2}, {"STA", &mos::STA, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"STY", &mos::STY, &mos::ZP0, 3}, {"STA", &mos::STA, &mos::ZP0, 3}, {"STX", &mos::STX, &mos::ZP0, 3}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"DEY", &mos::DEY, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"TXA", &mos::TXA, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"STY", &mos::STY, &mos::ABS, 4}, {"STA", &mos::STA, &mos::ABS, 4}, {"STX", &mos::STX, &mos::ABS, 4}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BCC", &mos::BCC, &mos::REL, 2}, {"STA", &mos::STA, &mos::INDY, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"STY", &mos::STY, &mos::ZPX, 4}, {"STA", &mos::STA, &mos::ZPX, 4}, {"STX", &mos::STX, &mos::ZPY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"TYA", &mos::TYA, &mos::IMP, 2}, {"STA", &mos::STA, &mos::ABSY, 5}, {"TXS", &mos::TXS, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"STA", &mos::STA, &mos::ABSX, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"LDY", &mos::LDY, &mos::IMM, 2}, {"LDA", &mos::LDA, &mos::INDX, 6}, {"LDX", &mos::LDX, &mos::IMM, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"LDY", &mos::LDY, &mos::ZP0, 3}, {"LDA", &mos::LDA, &mos::ZP0, 3}, {"LDX", &mos::LDX, &mos::ZP0, 3}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"TAY", &mos::TAY, &mos::IMP, 2}, {"LDA", &mos::LDA, &mos::IMM, 2}, {"TAX", &mos::TAX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"LDY", &mos::LDY, &mos::ABS, 4}, {"LDA", &mos::LDA, &mos::ABS, 4}, {"LDX", &mos::LDX, &mos::ABS, 4}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BCS", &mos::BCS, &mos::REL, 2}, {"LDA", &mos::LDA, &mos::INSY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"LDY", &mos::LDY, &mos::ZPX, 4}, {"LDA", &mos::LDA, &mos::ZPX, 4}, {"LDX", &mos::LDX, &mos::ZPY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CLV", &mos::CLV, &mos::IMP, 2}, {"LDA", &mos::LDA, &mos::ABSY, 4}, {"TSX", &mos::TSX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"LDY", &mos::LDY, &mos::ABSX, 4}, {"LDA", &mos::LDA, &mos::ABSX, 4}, {"LDX", &mos::LDX, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"CPY", &mos::CPY, &mos::IMM, 2}, {"CMP", &mos::CMP, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CPY", &mos::CPY, &mos::ZP0, 3}, {"CMP", &mos::CMP, &mos::ZP0, 3}, {"DEC", &mos::DEC, &mos::ZP0, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"INY", &mos::INY, &mos::IMP, 2}, {"CMP", &mos::CMP, &mos::IMM, 2}, {"DEX", &mos::DEX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CPY", &mos::CPY, &mos::ABS, 4}, {"CMP", &mos::CMP, &mos::ABS, 4}, {"DEC", &mos::DEC, &mos::ABS, 6}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BNE", &mos::BNE, &mos::REL, 2}, {"CMP", &mos::CMP, &mos::INDY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CMP", &mos::CMP, &mos::ZPX, 4}, {"DEC", &mos::DEC, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CLD", &mos::CLD, &mos::IMP, 2}, {"CMP", &mos::CMP, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CMP", &mos::CMP, &mos::ABSX, 4}, {"DEC", &mos::DEC, &mos::ABSX, 7}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"CPX", &mos::CPX, &mos::IMM, 2}, {"SBC", &mos::SBC, &mos::INDX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CPX", &mos::CPX, &mos::ZP0, 3}, {"SBC", &mos::SBC, &mos::ZP0, 3}, {"INC", &mos::INC, &mos::ZP0, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"INX", &mos::INX, &mos::IMP, 2}, {"SBC", &mos::SBC, &mos::IMM, 2}, {"NOP", &mos::NOP, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"CPX", &mos::CPX, &mos::ABS, 4}, {"SBC", &mos::SBC, &mos::ABS, 4}, {"INC", &mos::INC, &mos::ABS, 6}, {"XXX", &mos::XXX, &mos::IMP, 2},
		{"BEQ", &mos::BEQ, &mos::REL, 2}, {"SBC", &mos::SBC, &mos::INDY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"SBC", &mos::SBC, &mos::ZPX, 4}, {"INC", &mos::INC, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"SED", &mos::SED, &mos::IMP, 2}, {"SBC", &mos::SBC, &mos::ABSY, 4}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"SBC", &mos::SBC, &mos::ABSX, 4}, {"INC", &mos::INC, &mos::ABSX, 7}, {"XXX", &mos::XXX, &mos::IMP, 2}
	}
}

MOS6502 :: ~MOS6502(){}

uint8_t MOS6502::read(uint16_t address) {

	return bus->read(address, false);

}
void MOS6502::write(uint16_t address, uint8_t data) {

	bus->write(address, data);
}

//aqui será trabalhado a função de clock
void MOS6502::CLOCK() {

	if (cycles == 0) {

		//inicialmente, lemos o opcode que está no endereço marcado pelo nosso contador de programa
		opcode = read(pc);
		pc++;

		cycles = opcode_matrix[opcode].cycles; //pegamos a quantidade de ciclos que a instrução possui e adicionamos ela nos ciclos;

		(this->*opcode_matrix[opcode].addrmode)();
		(this->*opcode_matrix[opcode].operate)();

	}
}
