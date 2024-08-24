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
		{"BMI", &mos::BMI, &mos::REL, 2}, {"AND", &mos::AND, &mos::INDY, 5}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"AND", &mos::AND, &mos::ZPX, 4}, {"ROL", &mos::ROL, &mos::ZPX, 6}, {"XXX", &mos::XXX, &mos::IMP, 2}, {"SEC", &mos::SEC, &mos::IMP, 2}, {"AND", &mos::AND, &mos::ABSY, 4}, 
	}
}

MOS6502 :: ~MOS6502(){}

uint8_t MOS6502::read(uint16_t address) {

	return bus->read(address, false);

}
void MOS6502::write(uint16_t address, uint8_t data) {

	bus->write(address, data);
}
