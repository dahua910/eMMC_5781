#include <stdio.h>
#include "cmd.h"


main()
{
    printf("\n dk debug for 5781_eMMC \n");
    //printf("\n %x \n",(START_BIT<<31));
    S_EMMC_CMD *test_cmd=(S_EMMC_CMD*)malloc(sizeof(S_EMMC_CMD));
    memset(test_cmd,0, (sizeof(S_EMMC_CMD)));

    test_cmd->cmd_index=25;
    test_cmd->cmd_arg=0;
    u8 *test_cmd_token = (u8*)malloc(6);

    cmd_token_generator(test_cmd,test_cmd_token);
    print_cmd_token(test_cmd_token);
}
