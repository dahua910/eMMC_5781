
#include "c2atl.h"
#include "types.h"
#include "cmd.h"

u32 cmd_token_to_atl(S_EMMC_CMD *s_emmc_cmd)
{
    //u8 cmd_type=s_emmc_cmd->cmd_type;
    //int bit47_to_bit16=(*(cmd_token+0)<<24)+(*(cmd_token+1)<<16)+(*(cmd_token+2)<<8)+(*(cmd_token+3)<<0);
    //int bit15_to_bit0=(*(cmd_token+4)<<24)+(*(cmd_token+5)<<16);
    switch(((s_emmc_cmd->cmd_type)<<8)+(s_emmc_cmd->resp_type)){
        case CMD_SEQ_NA_NA://CMD0,
            printf("\n go atl CMD_SEQ_NA_NA\n");
            ATL_wxec(ATL_GOSUB)
            break;
        case CMD_SEQ_BC_NA://CMD0,CMD4
            printf("\n go atl CMD_SEQ_BC_NA\n");
            break;
        case CMD_SEQ_BCR_R3://CMD1
            printf("\n go atl CMD_SEQ_BCR_R3\n");

            break;
        case CMD_SEQ_BCR_R2://CMD2
            printf("\n go atl CMD_SEQ_BCR_R2\n");
            break;
        case CMD_SEQ_AC_R1://CMD3,CMD7
            printf("\n go atl CMD_SEQ_AC_R1\n");
            break;
        case CMD_SEQ_AC_R1B://CMD5,CMD6,CMD7
            printf("\n go atl CMD_SEQ_AC_R1B\n");
            break;
        case CMD_SEQ_ADTC_R1://CMD8
            printf("\n go atl CMD_SEQ_ADTC_R1\n");
            break;

    	default:
            printf("\n unknow type cmd\n");
            break;
    }

}


