#include "cmd.h"
#include "crc7.h"

#define DKDEBUG 1

u32 cmd_token_generator(S_EMMC_CMD *s_cmd_arg,u8 *cmd_token )
{
    if((s_cmd_arg->cmd_index)>63){
        printf("\n cmd index error!\n");
        return -1;}
    *(cmd_token+0)= (START_BIT<<7)+(TRANS_BIT_SEND<<6)+(s_cmd_arg->cmd_index);
    *(cmd_token+1)=  (s_cmd_arg->cmd_arg)>>24;
    *(cmd_token+2)=  (s_cmd_arg->cmd_arg)>>16;
    *(cmd_token+3)=  (s_cmd_arg->cmd_arg)>>8;
    *(cmd_token+4)=  (s_cmd_arg->cmd_arg)>>0;
    *(cmd_token+5)=  (crc7(cmd_token,5)<<1)+END_BIT;
#if DKDEBUG
    printf("\n *(cmd_token+0)=0x%x \n",*(cmd_token+0));
    printf("\n *(cmd_token+1)=0x%x \n",*(cmd_token+1));
    printf("\n *(cmd_token+2)=0x%x \n",*(cmd_token+2));
    printf("\n *(cmd_token+3)=0x%x \n",*(cmd_token+3));
    printf("\n *(cmd_token+4)=0x%x \n",*(cmd_token+4));
    printf("\n *(cmd_token+5)=0x%x \n",*(cmd_token+5));
#endif
    return 0;
}

void print_cmd_token(u8 *cmd_token)
{
    printf("\n debug for cmd_token_generator");
    printf("\n cmd_%d: arg=0x%x%x%x%x crc7=0x%x \n",(*cmd_token)&0x3F,*(cmd_token+1),*(cmd_token+2),*(cmd_token+3),*(cmd_token+4),(*(cmd_token+5)));
}






