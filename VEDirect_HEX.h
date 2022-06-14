/*
 * VEDirect_HEX.h
 *
 * Created: 14/06/2022 20:44:35
 *  Author: dania
 */ 

#include <stdio.h>

#ifndef VEDIRECT_HEX_H_
#define VEDIRECT_HEX_H_

#define VED_CHECKSUM_BASE 0x55

enum ved_cmd_tx {
	VEDCMD_TX_PING			= 1,
	VEDCMD_TX_APPVER		= 3,
	VEDCMD_TX_PRODUCT_ID	= 4,
	VEDCMD_TX_RESTART		= 6,
	VEDCMD_TX_GET			= 7,
	VEDCMD_TX_SET			= 8,
	VEDCMD_TX_ASYNC			= 0xA
};

enum ved_cmd_rx {
	VEDCMD_RX_DONE		= 1,
	VEDCMD_RX_UNKNOWN	= 3,
	VEDCMD_RX_PING		= 5,
	VEDCMD_RX_GET		= 7,
	VEDCMD_RX_SET		= 8
};

enum ved_flags {
	VEDFLAG_UNKNOWN_ID	= 0b1,
	VEDFLAG_READONLY	= 0b10,
	VEDFLAG_BAD_PARAM	= 0b100
};

enum ved_reg_id {
	VEDID_PRODUCT_ID			= 0x0100,	/* u32 */
	VEDID_PRODUCT_REV			= 0x0101,	/* u24 | BMV712 only */
	VEDID_SERIAL_NUMBER			= 0x010A,	/* string(32 max) */
	VEDID_MODEL_NAME			= 0x010B,	/* string(32 max) */
	VEDID_DESCRIPTION			= 0x010C,	/* string(20 max) | BMV712 only */
	VEDID_DEVICE_UPTIME			= 0x0120,	/* u32 | seconds */
	VEDID_BT_CAPABILITIES		= 0x0150,	/* u32 | BMV712 only */
	
	VEDID_MAIN_VOLTAGE			= 0xED8D,	/* s16 | 0.01 V */
	VEDID_AUX_VOLTAGE			= 0xED7D,	/* s16 | 0.01 V */
	VEDID_CURRENT_1				= 0xED8F,	/* s16 | 0.1 A */
	VEDID_CURRENT_2_3			= 0xED8C,	/* s32 | 0.001 A */
	VEDID_POWER					= 0xED8E,	/* s16 | W */
	VEDID_CONSUMED_AH			= 0xEEFF,	/* s32 | 0.1 Ah */
	VEDID_SOC					= 0x0FFF,	/* u16 | 0.01 % */
	VEDID_TTG					= 0x0FFE,	/* u16 | minutes */
	VEDID_TEMPERATURE			= 0xEDEC,	/* u16 | 0.01 K */
	VEDID_MIDPOINT_VOLT			= 0x0382,	/* u16 | 0.01 V */
	VEDID_MIDPOINT_VOLT_DEV		= 0x0383,	/* s16 | 0.1 % */
	VEDID_SYNC_STATE			= 0xEEB6,	/* u8 */
	
};

class ved_rx_frame
{
public:
	ved_rx_frame();
private:
	~ved_rx_frame(){};
};


class ved_tx_frame
{
public:
	ved_tx_frame(ved_cmd_tx cmd);
	ved_tx_frame(ved_cmd_tx cmd, ved_reg_id regId);
	//ved_tx_frame(ved_cmd_tx cmd, ved_reg_id regId, uint8_t u8Data);
	//ved_tx_frame(ved_cmd_tx cmd, ved_reg_id regId, uint16_t u16Data);
	//ved_tx_frame(ved_cmd_tx cmd, ved_reg_id regId, uint32_t u32Data);
	//ved_tx_frame(ved_cmd_tx cmd, ved_reg_id regId, char* strn);
	char* Get_Frame() { return Frame; };
private:
	char Frame[50];
	~ved_tx_frame(){};
};

#endif /* VEDIRECT_HEX_H_ */