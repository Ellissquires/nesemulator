#pragma once

#include <cstdint>
#include <array>

#include "cpu.h"
#include "ppu2C02.h"
#include "Cartridge.h"

class Bus
{
public:
	Bus();
	~Bus();
public:
	// Define the devices on the bus 
	cpu cpu;
	ppu2C02 ppu;
	std::array<uint8_t, 2048> cpuRam;
	std::shared_ptr<Cartridge> cart;

public: // Bus Read and Write
	void cpuWrite(uint16_t addr, uint8_t data);
	uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

public: // System Interface
	void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void reset();
	void clock();
private:
	uint32_t nSystemClockCounter = 0;
};

