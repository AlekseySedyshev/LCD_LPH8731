//Library has been modified for STM32F0xx by Aleksey Sedyshev
//https://github.com/AlekseySedyshev

#ifndef LCD_LPH8731_h
#define LCD_LPH8731_h

#include "stm32f0xx.h"  

#define SPI1_DR_8bit 			*((__IO uint8_t *)&SPI1->DR)		// Limit for spi bus 8 bit

#define   HI				1
#define   LO				0

#define   CMD_()					GPIOA->BRR 	|=1<<3			//A0->0
#define   DAT_()					GPIOA->BSRR |=1<<3		//A0->1

#define   RES_ON()			GPIOA->BRR |=1<<2		//RES->0
#define   RES_OFF()			GPIOA->BSRR |=1<<2		//RES->1

#define   CS_HI()				GPIOA->BSRR |=1<<4	
#define   CS_LO()				GPIOA->BRR |=1<<4


//===============================================================
//                    Color defines
//===============================================================
#ifdef _8_BIT_COLOR			//8-bit color (256)
#define GREEN       0x1C
#define DARK_GREEN  0x15
#define RED         0xE0
#define BLUE        0x1F    
#define DARK_BLUE   0x03
#define YELLOW      0xFC
#define ORANGE      0xEC
#define VIOLET      0xE3
#define WHITE       0xFF
#define BLACK       0x00
#define GREY        0x6D
#else										//12-bit color (4096)
#define WHITE       0xFFF
#define BLACK       0x000
#define RED         0xF00
#define GREEN       0x0F0
#define BLUE        0x00F
#define CYAN        0x0FF
#define MAGENTA     0xF0F
#define YELLOW      0xFF0
#define BROWN       0xB22
#define ORANGE      0xFA0
#define PINK        0xF9E
#endif

typedef enum {
CMD	=				0,
DAT	=				1
} cmd_data_sv;

void LCD_Init(void);
void SPI_Wr(cmd_data_sv data,unsigned char value);

void Put_Pixel (char x, char y, unsigned int color);
void Send_Symbol (unsigned char symbol, char x, char y, int t_color, int b_color, char zoom_width, char zoom_height, int rot);
void LCD_Putchar(char symbol, char x, char y, int t_color, int b_color, char zoom_width, char zoom_height, int rot);
void LCD_Puts(char *str, int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot);
void Send_Symbol_Shadow (unsigned char symbol, char x, char y, int t_color, char zoom_width, char zoom_height, int rot);
void LCD_Putchar_Shadow (char symbol, char x, char y, int t_color, char zoom_width, char zoom_height, int rot);
void LCD_Puts_Shadow(char *str, int x, int y,  int t_color, char zoom_width, char zoom_height, int rot);

void LCD_FillScreen (unsigned int color);
void LCD_DrawLine (char x1, char y1, char x2, char y2, int color);
void LCD_DrawRect (char x1, char y1, char width, char height, char size, int color);
void LCD_FillRect (char x1, char y1, char width, char height, int color);
void LCD_DrawCircle (char xcenter, char ycenter, char rad, int color);
void LCD_FillCircle (char xcenter, char ycenter, char rad, int color);
void LCD_DrawTriangle(char x1, char y1, char x2, char y2, char x3, char y3, int color);
void LCD_FillTriangle(char x1, char y1, char x2, char y2, char x3, char y3, int color);
void LCD_PrintDec(long val,int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot);
void LCD_PrintHex(long val,int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot);
void LCD_PrintBin(unsigned char value,int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot);


#endif
