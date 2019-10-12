/*
 * dma.h
 *
 *  Created on: Oct 25, 2017
 *      Author: mcowley
 */

#ifndef SRC_DMA_H_
#define SRC_DMA_H_

#include "xaxidma.h"
#include "xparameters.h"
#include "xdebug.h"

/************************** Function Prototypes ******************************/
#if defined(XPAR_UARTNS550_0_BASEADDR)
static void Uart550_Setup(void);
#endif

void init_progam();

int init_dma2();
int RxSetup(XAxiDma * AxiDmaInstPtr);
int TxSetup(XAxiDma * AxiDmaInstPtr);
int SendPacket(u8 *TxPacket, int length);
int CheckData(void);
u8* getPacket();


#define BASE (int*)0x43C00000
#define INT1 *(BASE)
#define INT2 *(BASE + 1)
//assign done = (index*PACKET_WIDTH >= num_words);
#define INT3 *(BASE + 2) //prev. INDEX
#define INT4 *(BASE + 3) //prev. PACKET_WIDTH
#define DONE *(BASE + 4)
#define RESET *(BASE + 16)
#define PACKET_SIZE_REG *(BASE + 17)
#define TRAIN_VECTORS *(BASE + 18)

#endif /* SRC_DMA_H_ */
