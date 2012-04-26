#ifndef _CMD_H
#define _CMD_H

#include "types.h"

#define START_BIT 0
#define TRANS_BIT_SEND 1
#define TRANS_BIT_RESP 0
#define END_BIT 1

#define START_BIT47 1<<47
#define TRANS_BIT46 1<<46
#define END_BIT0 1<<0

#define CMD_TYPE_NA     1<<0
#define CMD_TYPE_BC     1<<1
#define CMD_TYPE_BCR    1<<2
#define CMD_TYPE_AC     1<<3
#define CMD_TYPE_ADTC   1<<4


#define CMD_RESP_NA     1<<0
#define CMD_RESP_R1     1<<1
#define CMD_RESP_R1B    1<<2
#define CMD_RESP_R2     1<<3
#define CMD_RESP_R3     1<<4

#define CMD_SEQ_NA_NA   ((CMD_TYPE_NA<<8)+CMD_RESP_NA)  //CMD0,
#define CMD_SEQ_BC_NA   ((CMD_TYPE_BC<<8)+CMD_RESP_NA)  //CMD0,CMD4
#define CMD_SEQ_BCR_R3  ((CMD_TYPE_BCR<<8)+CMD_RESP_R3)  //CMD1
#define CMD_SEQ_BCR_R2  ((CMD_TYPE_BCR<<8)+CMD_RESP_R2) //CMD2
#define CMD_SEQ_AC_R1   ((CMD_TYPE_AC<<8)+CMD_RESP_R1) //CMD3,CMD7
#define CMD_SEQ_AC_R1B  ((CMD_TYPE_AC<<8)+CMD_RESP_R1B) //CMD5,CMD6,CMD7
#define CMD_SEQ_ADTC_R1 ((CMD_TYPE_ADTC<<8)+CMD_RESP_R1) //CMD8
//TO BE CONTINUE!!!


typedef struct
{
    u8 cmd_index;
    u8 cmd_type;
    u8 resp_type;
    u8 cmd_flag;
    u32 cmd_arg;
}S_EMMC_CMD;


/*
typedef struct
{
    u8 cmd_index;
    u32 cmd_arg;
}S_EMMC_CMD_ARG;
*/
/*
typedef struct
{
    u8 S_EMMC_CMD_ARG;
    u32 cmd_arg;
    u8 cmd_crc7;
}S_R1_RESP_TOKEN;

typedef struct
{
    u8 cmd_index;
    u32 cmd_arg;
}S_R2_RESP_TOKEN;

typedef struct
{
    u8 cmd_index;
    u32 cmd_arg;
}S_R3_RESP_TOKEN;
*/


u32 cmd_token_generator(S_EMMC_CMD *s_cmd_arg,u8 *cmd_token );
void print_cmd_token(u8 *cmd_token);

#endif
