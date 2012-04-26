#ifndef _RESP_H
#define _RESP_H

#include "types.h"

#define START_BIT 0
#define TRANS_BIT_RESP 0
#define END_BIT 1

typedef struct
{
    u8 cmd_index;
    u32 cmd_arg;
}R1_RESP_TOKEN;

typedef struct
{
    u8 cmd_index;
    u32 cmd_arg;
}R2_RESP_TOKEN;

typedef struct
{
    u8 cmd_index;
    u32 cmd_arg;
}R3_RESP_TOKEN;


#endif
