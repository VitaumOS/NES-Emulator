#pragma once
#include <cstdint>
#include <array>
#include "MOS6502.h"
using namespace std;
/*Nessa parte, irei implementar o barramento 
* que, internamente, apenas escreve e l� as
* os dados e endere�os entre os componentes
* da placa

*/


class Bus
{

public:
	Bus();
	~Bus();

	//� importante criarmos a CPU e a RAM dentro do nosso barramento
	MOS6502 CPU;
	array<uint8_t, 64 * 1024> RAM;

public:// Como sabemos, o endere�o possui 16 bits e o dado possui 8 bits

	uint8_t read(uint16_t address, bool bReadOnly = false);
	void write(uint16_t address, uint8_t data); 

};

