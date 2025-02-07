
#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "riscv.h"
#include "decoder.h"
#include "instruction.h"

class Simulator
{
public:
    Simulator() = default;

    void load(const char* name);

    uint32_t fetch(address_t address);
    Instruction decode(uint32_t encoding);
    void execute(const Instruction& instr);

    void run();
    void dump() {}
//private:
    Riscv riscv;
    Decoder decoder;
};

#endif

