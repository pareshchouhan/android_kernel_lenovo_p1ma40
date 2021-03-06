#ifndef __EPL2182_H__
#define __EPL2182_H__

#define REG_0			0X00
#define REG_1			0X01
#define REG_2			0X02
#define REG_3			0X03
#define REG_4			0X04
#define REG_5			0X05
#define REG_6			0X06
#define REG_7			0X07
#define REG_8			0X08
#define REG_9			0X09
#define REG_10			0X0A
#define REG_11			0X0B
#define REG_12			0X0C
#define REG_13			0X0D
#define REG_14			0X0E
#define REG_15			0X0F
#define REG_16			0X10
#define REG_17			0X11
#define REG_18			0X12
#define REG_19			0X13
#define REG_20			0X14
#define REG_21			0X15

#define W_SINGLE_BYTE	0X00
#define W_TWO_BYTE		0X01
#define W_THREE_BYTE	0X02
#define W_FOUR_BYTE		0X03
#define W_FIVE_BYTE		0X04
#define W_SIX_BYTE		0X05
#define W_SEVEN_BYTE	0X06
#define W_EIGHT_BYTE	0X07

#define R_SINGLE_BYTE	0X00
#define R_TWO_BYTE		0X01
#define R_THREE_BYTE	0X02
#define R_FOUR_BYTE		0X03
#define R_FIVE_BYTE		0X04
#define R_SIX_BYTE		0X05
#define R_SEVEN_BYTE	0X06
#define R_EIGHT_BYTE	0X07

#define EPL_SENSING_1_TIME	(0 << 5) 
#define EPL_SENSING_2_TIME	(1 << 5)
#define EPL_SENSING_4_TIME	(2 << 5)
#define EPL_SENSING_8_TIME	(3 << 5)
#define EPL_SENSING_16_TIME	(4 << 5)
#define EPL_SENSING_32_TIME	(5 << 5)
#define EPL_SENSING_64_TIME	(6 << 5)
#define EPL_SENSING_128_TIME (7 << 5)
#define EPL_C_SENSING_MODE	(0 << 4)
#define EPL_S_SENSING_MODE	(1 << 4)
#define EPL_ALS_MODE		(0 << 2)
#define EPL_PS_MODE			(1 << 2)
#define EPL_H_GAIN			(0)
#define EPL_M_GAIN			(1)
#define EPL_L_GAIN			(3)
#define EPL_AUTO_GAIN		(2)


#define EPL_8BIT_ADC		0
#define EPL_10BIT_ADC		1
#define EPL_12BIT_ADC		2
#define EPL_14BIT_ADC		3


#define EPL_C_RESET			0x00
#define EPL_C_START_RUN		0x04
#define EPL_C_P_UP			0x04
#define EPL_C_P_DOWN		0x06
#define EPL_DATA_LOCK_ONLY	0x01
#define EPL_DATA_LOCK		0x05
#define EPL_DATA_UNLOCK		0x04

#define EPL_GO_MID			0x1E
#define EPL_GO_LOW			0x1E

#define EPL_DRIVE_60MA		(0<<4)
#define EPL_DRIVE_120MA		(1<<4)

#define EPL_INT_BINARY			0
#define EPL_INT_DISABLE			2
#define EPL_INT_ACTIVE_LOW		3
#define EPL_INT_FRAME_ENABLE	4

#define EPL_PST_1_TIME		(0 << 2)
#define EPL_PST_4_TIME		(1 << 2)
#define EPL_PST_8_TIME		(2 << 2)
#define EPL_PST_16_TIME		(3 << 2)

//wt add for ps calibration start
#define CUST_EPL_PS_THRES_FAR         300
#define CUST_EPL_PS_THRES_CLOSE     1200
//wt add for ps calibration end

/*----------------------------------------------------------------------------*/
typedef enum{
    EPL2182_NOTIFY_PROXIMITY_CHANGE = 1,
    EPL2182_NOTIFY_ALS_RAW_DATA,
    EPL2182_NOTIFY_PS_RAW_DATA,
    EPL2182_NOTIFY_PROXIMITY_NOT_CHANGE
}EPL2182_NOTIFY_TYPE;
/*----------------------------------------------------------------------------*/
typedef enum{
    EPL2182_CUST_ACTION_SET_CUST = 1,
    EPL2182_CUST_ACTION_CLR_CALI,
    EPL2182_CUST_ACTION_SET_CALI,
    EPL2182_CUST_ACTION_SET_PS_THRESHODL,
    EPL2182_CUST_ACTION_SET_EINT_INFO,
    EPL2182_CUST_ACTION_GET_ALS_RAW_DATA,
    EPL2182_CUST_ACTION_GET_PS_RAW_DATA,
}EPL2182_CUST_ACTION;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
}EPL2182_CUST;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    uint16_t    part;
    int32_t    data[0];
}EPL2182_SET_CUST;
/*----------------------------------------------------------------------------*/
typedef EPL2182_CUST EPL2182_CLR_CALI;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    int32_t     cali;
}EPL2182_SET_CALI;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    int32_t     threshold[2];
}EPL2182_SET_PS_THRESHOLD;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    uint32_t    gpio_pin;
    uint32_t    gpio_mode;
    uint32_t    eint_num;
	uint32_t    eint_is_deb_en;
	uint32_t    eint_type;
}EPL2182_SET_EINT_INFO;
/*----------------------------------------------------------------------------*/
typedef EPL2182_CUST EPL2182_GET_ALS_RAW_DATA;
/*----------------------------------------------------------------------------*/
typedef EPL2182_CUST EPL2182_GET_PS_RAW_DATA;
/*----------------------------------------------------------------------------*/
typedef union
{
    uint32_t                    data[10];
    EPL2182_CUST                cust;
    EPL2182_SET_CUST            setCust;
    EPL2182_CLR_CALI            clearCali;
    EPL2182_SET_CALI            setCali;
    EPL2182_SET_PS_THRESHOLD    setPSThreshold;
    EPL2182_SET_EINT_INFO       setEintInfo;
    EPL2182_GET_ALS_RAW_DATA    getALSRawData;
    EPL2182_GET_PS_RAW_DATA     getPSRawData;
}EPL2182_CUST_DATA;
/*----------------------------------------------------------------------------*/

#endif
