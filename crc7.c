
//#include "type.h"
#include "cmd.h"
#include "types.h"

u8 crc7(u8 *chr, u32 cnt)
{
	u32 i,a;
	u8 crc,Data;
	crc=0;
	for (a=0;a<cnt;a++){
		Data=chr[a];
		for (i=0;i<8;i++){
			crc <<= 1;
			if ((Data & 0x80)^(crc & 0x80))
	    	crc ^=0x09;
	    	Data <<= 1;
		}
	}
	crc=(crc<<1)|1;
	return(crc);
}























