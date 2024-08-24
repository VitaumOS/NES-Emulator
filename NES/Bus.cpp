#include "Bus.h"

//Inicializa todos os valores da RAM com 0 e conecta o barramento à CPU

Bus::Bus() {
	
	RAM.fill(0x0000);
	CPU.ConnectBus(this);
}


Bus::~Bus() {}//Nosso destrutor não fará nada

void Bus::write(uint16_t address, uint8_t data) {

	if(address >= 0x0 && address <= 0xFFFF) //Esse "suposto" if inútil será explicado depois
		RAM[address] = data;

}

uint8_t Bus::read(uint16_t address, bool bReadOnly) {

	if (address >= 0x0000 && address <= 0xFFFF)
		return RAM[address];

}