/*
 * VEDirect_HEX.cpp
 *
 * Created: 14/06/2022 21:22:21
 *  Author: dania
 */ 

#include "VEDirect_HEX.h"

void Request_Register(ved_reg_id regId) {
	
}

ved_tx_frame::ved_tx_frame(ved_cmd_tx cmd)
{
	uint8_t chk = VED_CHECKSUM_BASE - cmd;
	snprintf(Frame, sizeof(Frame), ":%1X%2X\n", cmd, chk);
}

ved_tx_frame::ved_tx_frame(ved_cmd_tx cmd, ved_reg_id regId)
{
	uint16_t swapedId = __bswap16(regId);
	uint8_t chk = VED_CHECKSUM_BASE - cmd - ((swapedId >> 8) & 0xFF) - (swapedId & 0xFF);
	snprintf(Frame, sizeof(Frame), ":%1X%04X%2X\n", cmd, swapedId, chk);
}
