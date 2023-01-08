if (insn_len == 4) {
    switch (OPCODE(insn)) {
        DECLARECASE(OPCODE_LUI, INSTRUCT_LUI)
        DECLARECASE(OPCODE_AUIPC, INSTRUCT_AUIPC)
        DECLARECASE(OPCODE_JAL, INSTRUCT_JAL)
        DECLARECASE(OPCODE_JALR, INSTRUCT_JALR)
    case OPCODE_BRANCH: {
        uint64_t imm_b(IMM_B(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_BEQ, INSTRUCT_BEQ)
            DECLARECASE(FUNCT3_BNE, INSTRUCT_BNE)
            DECLARECASE(FUNCT3_BLT, INSTRUCT_BLT)
            DECLARECASE(FUNCT3_BGE, INSTRUCT_BGE)
            DECLARECASE(FUNCT3_BLTU, INSTRUCT_BLTU)
            DECLARECASE(FUNCT3_BGEU, INSTRUCT_BGEU)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_LOAD: {
        uint64_t imm_i(IMM_I(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_LB, INSTRUCT_LB)
            DECLARECASE(FUNCT3_LH, INSTRUCT_LH)
            DECLARECASE(FUNCT3_LW, INSTRUCT_LW)
            DECLARECASE(FUNCT3_LBU, INSTRUCT_LBU)
            DECLARECASE(FUNCT3_LHU, INSTRUCT_LHU)
            DECLARECASE(FUNCT3_LWU, INSTRUCT_LWU)  // RV64
            DECLARECASE(FUNCT3_LD, INSTRUCT_LD)    // RV64
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_STORE: {
        uint64_t imm_s(IMM_S(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_SB, INSTRUCT_SB)
            DECLARECASE(FUNCT3_SH, INSTRUCT_SH)
            DECLARECASE(FUNCT3_SW, INSTRUCT_SW)
            DECLARECASE(FUNCT3_SD, INSTRUCT_SD)  // RV64
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_OP_IMM: {
        uint64_t imm_i(IMM_I(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_ADDI, INSTRUCT_ADDI)
            DECLARECASE(FUNCT3_SLTI, INSTRUCT_SLTI)
            DECLARECASE(FUNCT3_SLTIU, INSTRUCT_SLTIU)
            DECLARECASE(FUNCT3_XORI, INSTRUCT_XORI)
            DECLARECASE(FUNCT3_ORI, INSTRUCT_ORI)
            DECLARECASE(FUNCT3_ANDI, INSTRUCT_ANDI)
            DECLARECASE(FUNCT3_SLLI, INSTRUCT_SLLI)
        case FUNCT3_SRI:
            switch (FUNC7(insn) & 0x3e) {
                DECLARECASE(FUNCT7_SRLI, INSTRUCT_SRLI)
                DECLARECASE(FUNCT7_SRAI, INSTRUCT_SRAI)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_OP:
        switch (FUNC7(insn)) {
        case FUNCT7_ADD:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_ADD, INSTRUCT_ADD)
                DECLARECASE(FUNCT3_SLL, INSTRUCT_SLL)
                DECLARECASE(FUNCT3_SLT, INSTRUCT_SLT)
                DECLARECASE(FUNCT3_SLTU, INSTRUCT_SLTU)
                DECLARECASE(FUNCT3_XOR, INSTRUCT_XOR)
                DECLARECASE(FUNCT3_SRR, INSTRUCT_SRL)
                DECLARECASE(FUNCT3_OR, INSTRUCT_OR)
                DECLARECASE(FUNCT3_AND, INSTRUCT_AND)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_SUB:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_ADD, INSTRUCT_SUB)
                DECLARECASE(FUNCT3_SRR, INSTRUCT_SRA)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_MULDIV:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_MUL, INSTRUCT_MUL)
                DECLARECASE(FUNCT3_MULH, INSTRUCT_MULH)
                DECLARECASE(FUNCT3_MULHSU, INSTRUCT_MULHSU)
                DECLARECASE(FUNCT3_MULHU, INSTRUCT_MULHU)
                DECLARECASE(FUNCT3_DIV, INSTRUCT_DIV)
                DECLARECASE(FUNCT3_DIVU, INSTRUCT_DIVU)
                DECLARECASE(FUNCT3_REM, INSTRUCT_REM)
                DECLARECASE(FUNCT3_REMU, INSTRUCT_REMU)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_MISC_MEM:
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_FENCE, INSTRUCT_FENCE)
            DECLARECASE(FUNCT3_FENCE_I, INSTRUCT_FENCE_I)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_SYSTEM:
        switch (FUNC3(insn)) {
        case FUNCT3_PRIV:
            switch (FUNC12(insn)) {
                DECLARECASE(FUNCT12_ECALL, INSTRUCT_ECALL)
                DECLARECASE(FUNCT12_EBREAK, INSTRUCT_EBREAK)
                DECLARECASE(FUNCT12_WFI, INSTRUCT_WFI)
                DECLARECASE(FUNCT12_MRET, INSTRUCT_MRET)
                DECLARECASE(FUNCT12_SRET, INSTRUCT_SRET)
            // Check FUNC7(insn) next
            default:
                switch (FUNC7(insn)) {
                    DECLARECASE(FUNCT7_SFENCE_VMA, INSTRUCT_SFENCE_VMA)
                    DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
                }
                break;
            }
            break;
            DECLARECASE(FUNCT3_CSRRW, INSTRUCT_CSRRW)
            DECLARECASE(FUNCT3_CSRRS, INSTRUCT_CSRRS)
            DECLARECASE(FUNCT3_CSRRC, INSTRUCT_CSRRC)
            DECLARECASE(FUNCT3_CSRRWI, INSTRUCT_CSRRWI)
            DECLARECASE(FUNCT3_CSRRSI, INSTRUCT_CSRRSI)
            DECLARECASE(FUNCT3_CSRRCI, INSTRUCT_CSRRCI)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    // RV64
    case OPCODE_OP_IMM_32: {
        uint32_t shamt(SHAMT(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_ADDI, INSTRUCT_ADDIW)
            DECLARECASE(FUNCT3_SLLI, INSTRUCT_SLLIW)
        case FUNCT3_SRI:
            switch (FUNC7(insn)) {
                DECLARECASE(FUNCT7_SRLI, INSTRUCT_SRLIW)
                DECLARECASE(FUNCT7_SRAI, INSTRUCT_SRAIW)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_OP_32:
        switch (FUNC3(insn)) {
        case FUNCT3_ADD:
            switch (FUNC7(insn)) {
                DECLARECASE(FUNCT7_ADD, INSTRUCT_ADDW)
                DECLARECASE(FUNCT7_SUB, INSTRUCT_SUBW)
                DECLARECASE(FUNCT7_MULDIV, INSTRUCT_MULW)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLARECASE(FUNCT3_SLL, INSTRUCT_SLLW)
            DECLARECASE(FUNCT3_DIV, INSTRUCT_DIVW)
        case FUNCT3_SRR:
            switch (FUNC7(insn)) {
                DECLARECASE(FUNCT7_SRL, INSTRUCT_SRLW)
                DECLARECASE(FUNCT7_SRA, INSTRUCT_SRAW)
                DECLARECASE(FUNCT7_MULDIV, INSTRUCT_DIVUW)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLARECASE(FUNCT3_REM, INSTRUCT_REMW)
            DECLARECASE(FUNCT3_REMU, INSTRUCT_REMUW)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_AMO: {
        bool aq(AQ(insn)), rl(RL(insn));
        switch (FUNC3(insn)) {
        case FUNCT3_AMO_W:
            switch (FUNC5(insn)) {
                DECLARECASE(FUNCT5_LR, INSTRUCT_LR_W)
                DECLARECASE(FUNCT5_SC, INSTRUCT_SC_W)
                DECLARECASE(FUNCT5_AMOSWAP, INSTRUCT_AMOSWAP_W)
                DECLARECASE(FUNCT5_AMOADD, INSTRUCT_AMOADD_W)
                DECLARECASE(FUNCT5_AMOXOR, INSTRUCT_AMOXOR_W)
                DECLARECASE(FUNCT5_AMOAND, INSTRUCT_AMOAND_W)
                DECLARECASE(FUNCT5_AMOOR, INSTRUCT_AMOOR_W)
                DECLARECASE(FUNCT5_AMOMIN, INSTRUCT_AMOMIN_W)
                DECLARECASE(FUNCT5_AMOMAX, INSTRUCT_AMOMAX_W)
                DECLARECASE(FUNCT5_AMOMINU, INSTRUCT_AMOMINU_W)
                DECLARECASE(FUNCT5_AMOMAXU, INSTRUCT_AMOMAXU_W)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT3_AMO_D:
            switch (FUNC5(insn)) {
                DECLARECASE(FUNCT5_LR, INSTRUCT_LR_D)
                DECLARECASE(FUNCT5_SC, INSTRUCT_SC_D)
                DECLARECASE(FUNCT5_AMOSWAP, INSTRUCT_AMOSWAP_D)
                DECLARECASE(FUNCT5_AMOADD, INSTRUCT_AMOADD_D)
                DECLARECASE(FUNCT5_AMOXOR, INSTRUCT_AMOXOR_D)
                DECLARECASE(FUNCT5_AMOAND, INSTRUCT_AMOAND_D)
                DECLARECASE(FUNCT5_AMOOR, INSTRUCT_AMOOR_D)
                DECLARECASE(FUNCT5_AMOMIN, INSTRUCT_AMOMIN_D)
                DECLARECASE(FUNCT5_AMOMAX, INSTRUCT_AMOMAX_D)
                DECLARECASE(FUNCT5_AMOMINU, INSTRUCT_AMOMINU_D)
                DECLARECASE(FUNCT5_AMOMAXU, INSTRUCT_AMOMAXU_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_LOAD_FP: {
        uint64_t imm_i(IMM_I(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_LW, INSTRUCT_FLW)
            DECLARECASE(FUNCT3_LD, INSTRUCT_FLD)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_STORE_FP: {
        uint64_t imm_s(IMM_S(insn));
        switch (FUNC3(insn)) {
            DECLARECASE(FUNCT3_SW, INSTRUCT_FSW)
            DECLARECASE(FUNCT3_SD, INSTRUCT_FSD)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
    } break;
    case OPCODE_FMADD:
        switch (FUNC7(insn) & 0x3) {
            DECLARECASE(FUNCT7_FMADD_S, INSTRUCT_FMADD_S)
            DECLARECASE(FUNCT7_FMADD_D, INSTRUCT_FMADD_D)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_FNMADD:
        switch (FUNC7(insn) & 0x3) {
            DECLARECASE(FUNCT7_FMADD_S, INSTRUCT_FNMADD_S)
            DECLARECASE(FUNCT7_FMADD_D, INSTRUCT_FNMADD_D)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_FMSUB:
        switch (FUNC7(insn) & 0x3) {
            DECLARECASE(FUNCT7_FMADD_S, INSTRUCT_FMSUB_S)
            DECLARECASE(FUNCT7_FMADD_D, INSTRUCT_FMSUB_D)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_FNMSUB:
        switch (FUNC7(insn) & 0x3) {
            DECLARECASE(FUNCT7_FMADD_S, INSTRUCT_FNMSUB_S)
            DECLARECASE(FUNCT7_FMADD_D, INSTRUCT_FNMSUB_D)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_OP_FP:
        switch (FUNC7(insn)) {
            DECLARECASE(FUNCT7_FADD_S, INSTRUCT_FADD_S)
            DECLARECASE(FUNCT7_FSUB_S, INSTRUCT_FSUB_S)
            DECLARECASE(FUNCT7_FMUL_S, INSTRUCT_FMUL_S)
            DECLARECASE(FUNCT7_FDIV_S, INSTRUCT_FDIV_S)
            DECLARECASE(FUNCT7_FSQRT_S, INSTRUCT_FSQRT_S)
            DECLARECASE(FUNCT7_FADD_D, INSTRUCT_FADD_D)
            DECLARECASE(FUNCT7_FSUB_D, INSTRUCT_FSUB_D)
            DECLARECASE(FUNCT7_FMUL_D, INSTRUCT_FMUL_D)
            DECLARECASE(FUNCT7_FDIV_D, INSTRUCT_FDIV_D)
            DECLARECASE(FUNCT7_FSQRT_D, INSTRUCT_FSQRT_D)
        case FUNCT7_FSGNJ_S:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FSGNJ, INSTRUCT_FSGNJ_S)
                DECLARECASE(FUNCT3_FSGNJN, INSTRUCT_FSGNJN_S)
                DECLARECASE(FUNCT3_FSGNJX, INSTRUCT_FSGNJX_S)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FSGNJ_D:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FSGNJ, INSTRUCT_FSGNJ_D)
                DECLARECASE(FUNCT3_FSGNJN, INSTRUCT_FSGNJN_D)
                DECLARECASE(FUNCT3_FSGNJX, INSTRUCT_FSGNJX_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FMIN_S:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FMIN, INSTRUCT_FMIN_S)
                DECLARECASE(FUNCT3_FMAX, INSTRUCT_FMAX_S)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FMIN_D:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FMIN, INSTRUCT_FMIN_D)
                DECLARECASE(FUNCT3_FMAX, INSTRUCT_FMAX_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FMV_X_W:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FMV_X_W, INSTRUCT_FMV_X_W)
                DECLARECASE(FUNCT3_FCLASS_S, INSTRUCT_FCLASS_S)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FMV_X_D:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FMV_X_W, INSTRUCT_FMV_X_D)
                DECLARECASE(FUNCT3_FCLASS_S, INSTRUCT_FCLASS_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCMP_S:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FEQ_S, INSTRUCT_FEQ_S)
                DECLARECASE(FUNCT3_FLT_S, INSTRUCT_FLT_S)
                DECLARECASE(FUNCT3_FLE_S, INSTRUCT_FLE_S)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCMP_D:
            switch (FUNC3(insn)) {
                DECLARECASE(FUNCT3_FEQ_S, INSTRUCT_FEQ_D)
                DECLARECASE(FUNCT3_FLT_S, INSTRUCT_FLT_D)
                DECLARECASE(FUNCT3_FLE_S, INSTRUCT_FLE_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCVT_S_D:
            switch (rs2) {
                DECLARECASE(FUNCT5_FCVT_S_D, INSTRUCT_FCVT_S_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCVT_D_S:
            switch (rs2) {
                DECLARECASE(FUNCT5_FCVT_D_S, INSTRUCT_FCVT_D_S)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCVT_S_W:
            switch (rs2) {
                DECLARECASE(FUNCT5_FCVT_S_W, INSTRUCT_FCVT_S_W)
                DECLARECASE(FUNCT5_FCVT_S_WU, INSTRUCT_FCVT_S_WU)
                DECLARECASE(FUNCT5_FCVT_S_L, INSTRUCT_FCVT_S_L)
                DECLARECASE(FUNCT5_FCVT_S_LU, INSTRUCT_FCVT_S_LU)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCVT_D_W:
            switch (rs2) {
                DECLARECASE(FUNCT5_FCVT_S_W, INSTRUCT_FCVT_D_W)
                DECLARECASE(FUNCT5_FCVT_S_WU, INSTRUCT_FCVT_D_WU)
                DECLARECASE(FUNCT5_FCVT_S_L, INSTRUCT_FCVT_D_L)
                DECLARECASE(FUNCT5_FCVT_S_LU, INSTRUCT_FCVT_D_LU)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCVT_W_S:
            switch (rs2) {
                DECLARECASE(FUNCT5_FCVT_S_W, INSTRUCT_FCVT_W_S)
                DECLARECASE(FUNCT5_FCVT_S_WU, INSTRUCT_FCVT_WU_S)
                DECLARECASE(FUNCT5_FCVT_S_L, INSTRUCT_FCVT_L_S)
                DECLARECASE(FUNCT5_FCVT_S_LU, INSTRUCT_FCVT_LU_S)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
        case FUNCT7_FCVT_W_D:
            switch (rs2) {
                DECLARECASE(FUNCT5_FCVT_S_W, INSTRUCT_FCVT_W_D)
                DECLARECASE(FUNCT5_FCVT_S_WU, INSTRUCT_FCVT_WU_D)
                DECLARECASE(FUNCT5_FCVT_S_L, INSTRUCT_FCVT_L_D)
                DECLARECASE(FUNCT5_FCVT_S_LU, INSTRUCT_FCVT_LU_D)
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLARECASE(FUNCT7_FMV_W_X, INSTRUCT_FMV_W_X)
            DECLARECASE(FUNCT7_FMV_D_X, INSTRUCT_FMV_D_X)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    }
} else {  // RVC
    switch (OPCODE16(insn)) {
    case OPCODE_C0:
        switch (c_funct3) {
            DECLARECASE(FUNCT3_C_ADDI4SPN, INSTRUCT_C_ADDI4SPN)
            DECLARECASE(FUNCT3_C_FLD, INSTRUCT_C_FLD)
            DECLARECASE(FUNCT3_C_LW, INSTRUCT_C_LW)
            DECLARECASE(FUNCT3_C_LD, INSTRUCT_C_LD)
            DECLARECASE(FUNCT3_C_FSD, INSTRUCT_C_FSD)
            DECLARECASE(FUNCT3_C_SW, INSTRUCT_C_SW)
            DECLARECASE(FUNCT3_C_SD, INSTRUCT_C_SD)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_C1:
        switch (c_funct3) {
            DECLARECASE(FUNCT3_C_ADDI, INSTRUCT_C_ADDI)
            DECLARECASE(FUNCT3_C_ADDIW, INSTRUCT_C_ADDIW)
            DECLARECASE(FUNCT3_C_LI, INSTRUCT_C_LI)
        case FUNCT3_C_LUI:
            switch (rd) {
                DECLARECASE(REG_SP, INSTRUCT_C_ADDI16SP)
                DECLAREDEFAULTCASE(INSTRUCT_C_LUI)
            }
            break;
        case FUNCT3_C_MISC_ALU:
            switch (c_funct6) {
            case FUNCT6_C_SUB:
                switch (c_funct2) {
                    DECLARECASE(FUNCT2_C_SUB, INSTRUCT_C_SUB)
                    DECLARECASE(FUNCT2_C_XOR, INSTRUCT_C_XOR)
                    DECLARECASE(FUNCT2_C_OR, INSTRUCT_C_OR)
                    DECLARECASE(FUNCT2_C_AND, INSTRUCT_C_AND)
                    DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
                }
                break;
            case FUNCT6_C_SUBW:
                switch (c_funct2) {
                    DECLARECASE(FUNCT2_C_SUBW, INSTRUCT_C_SUBW)
                    DECLARECASE(FUNCT2_C_ADDW, INSTRUCT_C_ADDW)
                    DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
                }
                break;
            default:
                switch (_c_funct2) {
                    DECLARECASE(FUNCT2_C_SRLI, INSTRUCT_C_SRLI)
                    DECLARECASE(FUNCT2_C_SRAI, INSTRUCT_C_SRAI)
                    DECLARECASE(FUNCT2_C_ANDI, INSTRUCT_C_ANDI)
                    DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
                }
                break;
            }
            break;
            DECLARECASE(FUNCT3_C_J, INSTRUCT_C_J)
            DECLARECASE(FUNCT3_C_BEQZ, INSTRUCT_C_BEQZ)
            DECLARECASE(FUNCT3_C_BNEZ, INSTRUCT_C_BNEZ)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
    case OPCODE_C2:
        switch (c_funct3) {
            DECLARECASE(FUNCT3_C_SLLI, INSTRUCT_C_SLLI)
            DECLARECASE(FUNCT3_C_FLD, INSTRUCT_C_FLDSP)
            DECLARECASE(FUNCT3_C_LWSP, INSTRUCT_C_LWSP)
            DECLARECASE(FUNCT3_C_LDSP, INSTRUCT_C_LDSP)
        case FUNCT3_C_JR:
            switch (c_funct4) {
            case FUNCT4_C_JR:
                switch (c_rs2) {
                    DECLARECASE(0, INSTRUCT_C_JR)
                    DECLAREDEFAULTCASE(INSTRUCT_C_MV)
                }
                break;
            case FUNCT4_C_JALR:
                switch (c_rs2) {
                case 0:
                    switch (rd) {
                        DECLARECASE(0, INSTRUCT_C_EBREAK)
                        DECLAREDEFAULTCASE(INSTRUCT_C_JALR)
                    }
                    break;
                    DECLAREDEFAULTCASE(INSTRUCT_C_ADD)
                }
                break;
                DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
            }
            break;
            DECLARECASE(FUNCT3_C_FSD, INSTRUCT_C_FSDSP)
            DECLARECASE(FUNCT3_C_SWSP, INSTRUCT_C_SWSP)
            DECLARECASE(FUNCT3_C_SDSP, INSTRUCT_C_SDSP)
            DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
        }
        break;
        DECLAREDEFAULTCASE(INSTRUCT_UNKNOWN)
    }
}
