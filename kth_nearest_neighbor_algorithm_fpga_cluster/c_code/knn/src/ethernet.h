/*
 * ethernet.h
 *
 *  Created on: Mar 7, 2018
 *      Author: FettigG
 */

#ifndef SRC_ETHERNET_H_
#define SRC_ETHERNET_H_
#include <stdio.h>
#include "xil_cache.h"
#include "platform.h"
#include "platform_config.h"
#include <string.h>
#include <math.h>

#if LWIP_DHCP==1
#include "lwip/dhcp.h"
#endif
#include "ethernet.h"
#include "lwip/err.h"
#include "lwip/tcp.h"
#if defined (__arm__) || defined (__aarch64__)
#include "xil_printf.h"
#include "xparameters.h"
#endif

/*ECHO EXAMPLE FUNCTIONS*/
int ethernet_config(); //renamed. was echo example main() function
void tcp_fasttmr();
void tcp_slowtmr();
int xemacif_input(struct netif *echo_netif);
void print_app_header();
int start_application();

/*ECHO EXAMPLE VARABILES AS GLOBAL*/
struct netif *echo_netif;
struct netif server_netif;

/*CUSTOM FUNCTIONS*/
void ethernet_accept();
void ethernet_send(int kth_nearest[], int k);
void ethernet_receive();

/*CUSTOM VARIABLES*/
int ACCEPTED_CONNECTION;
int ETH_PACKETS_RECEIVED;
int NUM_ETH_PACKETS;
int BUF_OFFSET;
struct tcp_pcb *TCP_PCB;
char * VECTORS;
unsigned port;
unsigned char * mac_ethernet_address;
u32_t IP;


#endif /* SRC_ETHERNET_H_ */
#include "lwip/tcp.h"

