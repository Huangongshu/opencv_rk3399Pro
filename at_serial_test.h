#ifndef __AT_SERIAL_TEST_H
#define __AT_SERIAL_TEST_H
#include <stdio.h>
#ifdef __cplusplus
extern "C" {

}
#endif

#define MAX_CAMERA_NUM  20

typedef struct at_qiopen{
	unsigned short  connectID;
	unsigned char	service_type[30];
	unsigned char	server_ip[40];
	unsigned short  server_port;
	unsigned short  local_port;
	unsigned short  access_mode;
	short			connect_status;
}at_qiopen_t;

typedef struct at_qicsgp{
	unsigned int  context_id;
	unsigned int  context_type;
	unsigned char APN[20];
}at_qicsgp_t;



typedef struct camera_info{
	char device_name[20];//设备名称 如video0 video1
	char camera_name[20];//自己取的别名 如摄像头一 摄像头二
}camera_info_t;

struct clnt_info{
	unsigned short fd_ec20;  //file descriptor
	char cops_info[30]; //operator
	camera_info_t camera_list[MAX_CAMERA_NUM];// camera device name list
	 
	static at_qicsgp_t csgp_info;

};
/* Operator info */
#define OPERATOR_CM "CHINA MOBILE" //中国移动
#define OPERATOR_CT "CHN_CT" //中国电信
#define OPERATOR_UNICOM "CHN_UNICOM" //中国联通

/* AT COMMAND ERROR */
#define AT_SEND_ERROR     -10
#define AT_LENGTH_ERROR   -13
#define AT_RECV_ERROR     -11
#define AT_SET_COMMAND_FAILED  -12
#define AT_SET_COMMAND_SUCCESS 12

#define AT_NO_RESPOND				-99
#define AT_NO_SIM					-98
#define AT_SERIAL_INIT_ERROR		-97 
#define AT_COMMAND_ERROR_NO_MODULE  -96
#define AT_NO_NETWORK				-95
#define AT_SET_CONTEXT_ERROR		-94
#define AT_ACTIVE_CONTEXT_ERROR		-93
#define AT_QIOPEN_ERROR				-92
#define AT_QICLOSE_ERROR			-91

#define AT_COMMAND_RESPOND_SIM "\r\n+CPIN: READY\r\n\r\nOK\r\n"
#define AT_COMMAND_RESPOND_OK "\r\nOK\r\n"
#define AT_COMMAND_RESPOND_ATE0 "ATE0\r\n\r\nOK\r\n"
#define AT_COMMAND_RESPOND_ERROR "\r\nERROR\r\n"
#define AT_COMMAND_RESPOND_CREG "\r\n+CREG: 0,1\r\n\r\nOK\r\n"
#define AT_COMMAND_RESPOND_CGREG "\r\n+CGREG: 0,1\r\n\r\nOK\r\n"
#define AT_COMMAND_URC_RECV  "\r\n+QIURC: \"recv\",0\r\n"

/* AT Connect configure */
#define SERVICE_TYPE_TCP			"TCP"
#define SERVICE_TYPE_UDP			"UDP"
#define SERVICE_TYPE_TCP_LISTENER	"TCP LISTENER"
#define SERVICE_TYPE_UDP_SERVICE	"UDP SERVICE"

#define SERVER_IP   "124.79.129.208"
#define SERVER_PORT 8001

#define BUFFER_ACCESS_MODE		0
#define DIRECT_PUSH_MODE		1
#define TRANSPARENT_ACCESS_MODE 2


/* serial error code */
#define SERIAL_ERROR_OPEN        -1
#define SERIAL_ERROR_READ        -2
#define SERIAL_ERROR_WRITE       -3
#define SERIAL_ERROR_BAUDRATE    -4
#define SERIAL_ERROR_SETTING     -5
#define SERIAL_INVALID_RESOURCE  -6
#define SERIAL_INVALID_FILE      -7

/* data bits */
#define DATA_BITS_8		8
#define DATA_BITS_7     7
#define DATA_BITS_6		6
#define DATA_BITS_5		5


/* flow control */
#define FLOW_CONTROL_NONE         0
#define FLOW_CONTROL_HARDWARE     1
#define FLOW_CONTROL_SOFTWARE     2

/* stop bit */
#define STOP_BIT_1	1
#define STOP_BIT_2  2

/* parity */
#define PARITY_NONE  'N'
#define PARITY_EVEN  'E'
#define PARITY_ODD   'O'
#define PARITY_SPACE 'S'
#define PARITY_MARK  'M'

/* baud rate*/
#define BAUD_RATE_0			0
#define BAUD_RATE_5			5	
#define BAUD_RATE_75		75
#define BAUD_RATE_110		110
#define BAUD_RATE_150		150
#define BAUD_RATE_200		200
#define BAUD_RATE_300		300
#define BAUD_RATE_600		600
#define BAUD_RATE_1200		1200
#define BAUD_RATE_1800		1800
#define BAUD_RATE_2400		2400
#define BAUD_RATE_4800		4800
#define BAUD_RATE_9600		9600
#define BAUD_RATE_19200		19200
#define BAUD_RATE_38400		38400
#define BAUD_RATE_57600		57600
#define BAUD_RATE_115200	115200
#define BAUD_RATE_230400	230400
#define BAUD_RATE_460800	460800
#define BAUD_RATE_500000	500000
#define BAUD_RATE_576000	576000
#define BAUD_RATE_921600	9216000
#define BAUD_RATE_1000000	1000000
#define BAUD_RATE_11520000	11520000
#define BAUD_RATE_15000000	15000000
#define BAUD_RATE_20000000	20000000
#define BAUD_RATE_25000000	25000000
#define BAUD_RATE_30000000	30000000
#define BAUD_RATE_35000000	35000000
#define BAUD_RATE_40000000	40000000


int serial_init(const char* device_name,int baut_rate,short data_bits,char parity,short stop_bits,short flow_control);
int AT_set_command(int fd,char* cmd,size_t cmd_len,char* res,size_t res_len,int timeout_ms,const char* res_expect);






#endif
