
#ifndef __RISCV_H__
#define __RISCV_H__

#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "memory.h"
#include "hart.h"
#include "instruction.h"
#include "log_service.h"


class Riscv
{
public:
    Riscv() = default;

    // instructions executors
    #include "rv32i.inc"

//private:
    reg_t getReg(uint8_t num);
    void setReg(uint8_t num, reg_t val);
    void memRead(address_t addr, void* dst, size_t nbyte);
    void memWrite(address_t addr, void* src, size_t nbyte);
    tag_t getTag(address_t address);
    void setTag(address_t address, tag_t tag);

    void logRegRead(uint8_t num, reg_t val);
    void logRegWrite(uint8_t num, reg_t val);
    void logMemRead(address_t addr, void* dst, size_t nbyte);
    void logMemWrite(address_t addr, void* src, size_t nbyte);
    void logGetTag(address_t addr, tag_t tag);
    void logSetTag(address_t addr, tag_t tag);

    void logRegImm(string name, uint8_t rd, uint8_t rs1, int32_t imm);
    void logIntRegReg(string name, uint8_t rd, uint8_t rs1, uint8_t rs2);
    void logJump(string name, uint8_t rd, uint32_t addr);
    void logCondBr(string name, uint8_t rs1, uint8_t rs2, uint32_t addr);

    Hart hart;
    Memory memory;
    ofstream log = ofstream("log_file");
};

#endif
