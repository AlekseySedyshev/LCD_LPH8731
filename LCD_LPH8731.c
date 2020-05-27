//Library has been modified for STM32F0xx by Aleksey Sedyshev
//https://github.com/AlekseySedyshev

#include "stm32f0xx.h"  
#include "LCD_LPH8731.h"  
#include "main.h" 


unsigned char const font_5x8[][5]  = {
0x00, 0x00, 0x00, 0x00, 0x00,// (space)  32
0x00, 0x00, 0x5F, 0x00, 0x00,// !        33
0x00, 0x07, 0x00, 0x07, 0x00,// "        34
0x14, 0x7F, 0x14, 0x7F, 0x14,// #        35
0x24, 0x2A, 0x7F, 0x2A, 0x12,// $        36
0x23, 0x13, 0x08, 0x64, 0x62,// %        37
0x36, 0x49, 0x55, 0x22, 0x50,// &        38
0x00, 0x05, 0x03, 0x00, 0x00,// '        39
0x00, 0x1C, 0x22, 0x41, 0x00,// (        40
0x00, 0x41, 0x22, 0x1C, 0x00,// )        41
0x08, 0x2A, 0x1C, 0x2A, 0x08,// *        42
0x08, 0x08, 0x3E, 0x08, 0x08,// +        43
0x00, 0x50, 0x30, 0x00, 0x00,// ,        44
0x08, 0x08, 0x08, 0x08, 0x08,// -        45
0x00, 0x30, 0x30, 0x00, 0x00,// .        46
0x20, 0x10, 0x08, 0x04, 0x02,// /        47
0x3E, 0x51, 0x49, 0x45, 0x3E,// 0        48
0x00, 0x42, 0x7F, 0x40, 0x00,// 1        49
0x42, 0x61, 0x51, 0x49, 0x46,// 2        50
0x21, 0x41, 0x45, 0x4B, 0x31,// 3        51
0x18, 0x14, 0x12, 0x7F, 0x10,// 4        52
0x27, 0x45, 0x45, 0x45, 0x39,// 5        53
0x3C, 0x4A, 0x49, 0x49, 0x30,// 6        54
0x01, 0x71, 0x09, 0x05, 0x03,// 7        55
0x36, 0x49, 0x49, 0x49, 0x36,// 8        56
0x06, 0x49, 0x49, 0x29, 0x1E,// 9        57
0x00, 0x36, 0x36, 0x00, 0x00,// :        58
0x00, 0x56, 0x36, 0x00, 0x00,// ;        59
0x00, 0x08, 0x14, 0x22, 0x41,// <        60
0x14, 0x14, 0x14, 0x14, 0x14,// =        61
0x41, 0x22, 0x14, 0x08, 0x00,// >        62
0x02, 0x01, 0x51, 0x09, 0x06,// ?        63
0x32, 0x49, 0x79, 0x41, 0x3E,// @        64
0x7E, 0x11, 0x11, 0x11, 0x7E,// A        65
0x7F, 0x49, 0x49, 0x49, 0x36,// B        66
0x3E, 0x41, 0x41, 0x41, 0x22,// C        67
0x7F, 0x41, 0x41, 0x22, 0x1C,// D        68
0x7F, 0x49, 0x49, 0x49, 0x41,// E        69
0x7F, 0x09, 0x09, 0x01, 0x01,// F        70
0x3E, 0x41, 0x41, 0x51, 0x32,// G        71
0x7F, 0x08, 0x08, 0x08, 0x7F,// H        72
0x00, 0x41, 0x7F, 0x41, 0x00,// I        73
0x20, 0x40, 0x41, 0x3F, 0x01,// J        74
0x7F, 0x08, 0x14, 0x22, 0x41,// K        75
0x7F, 0x40, 0x40, 0x40, 0x40,// L        76
0x7F, 0x02, 0x04, 0x02, 0x7F,// M        77
0x7F, 0x04, 0x08, 0x10, 0x7F,// N        78
0x3E, 0x41, 0x41, 0x41, 0x3E,// O        79
0x7F, 0x09, 0x09, 0x09, 0x06,// P        80
0x3E, 0x41, 0x51, 0x21, 0x5E,// Q        81
0x7F, 0x09, 0x19, 0x29, 0x46,// R        82
0x46, 0x49, 0x49, 0x49, 0x31,// S        83
0x01, 0x01, 0x7F, 0x01, 0x01,// T        84
0x3F, 0x40, 0x40, 0x40, 0x3F,// U        85
0x1F, 0x20, 0x40, 0x20, 0x1F,// V        86
0x7F, 0x20, 0x18, 0x20, 0x7F,// W        87
0x63, 0x14, 0x08, 0x14, 0x63,// X        88
0x03, 0x04, 0x78, 0x04, 0x03,// Y        89
0x61, 0x51, 0x49, 0x45, 0x43,// Z        90
0x00, 0x00, 0x7F, 0x41, 0x41,// [        91
0x02, 0x04, 0x08, 0x10, 0x20,// "\"      92
0x41, 0x41, 0x7F, 0x00, 0x00,// ]        93
0x04, 0x02, 0x01, 0x02, 0x04,// ^        94
0x40, 0x40, 0x40, 0x40, 0x40,// _        95
0x00, 0x01, 0x02, 0x04, 0x00,// `        96
0x20, 0x54, 0x54, 0x54, 0x78,// a        97
0x7F, 0x48, 0x44, 0x44, 0x38,// b        98
0x38, 0x44, 0x44, 0x44, 0x20,// c        99
0x38, 0x44, 0x44, 0x48, 0x7F,// d        100
0x38, 0x54, 0x54, 0x54, 0x18,// e        101
0x08, 0x7E, 0x09, 0x01, 0x02,// f        102
0x08, 0x14, 0x54, 0x54, 0x3C,// g        103
0x7F, 0x08, 0x04, 0x04, 0x78,// h        104
0x00, 0x44, 0x7D, 0x40, 0x00,// i        105
0x20, 0x40, 0x44, 0x3D, 0x00,// j        106
0x00, 0x7F, 0x10, 0x28, 0x44,// k        107
0x00, 0x41, 0x7F, 0x40, 0x00,// l        108
0x7C, 0x04, 0x18, 0x04, 0x78,// m        109
0x7C, 0x08, 0x04, 0x04, 0x78,// n        110
0x38, 0x44, 0x44, 0x44, 0x38,// o        111
0x7C, 0x14, 0x14, 0x14, 0x08,// p        112
0x08, 0x14, 0x14, 0x18, 0x7C,// q        113
0x7C, 0x08, 0x04, 0x04, 0x08,// r        114
0x48, 0x54, 0x54, 0x54, 0x20,// s        115
0x04, 0x3F, 0x44, 0x40, 0x20,// t        116
0x3C, 0x40, 0x40, 0x20, 0x7C,// u        117
0x1C, 0x20, 0x40, 0x20, 0x1C,// v        118
0x3C, 0x40, 0x30, 0x40, 0x3C,// w        119
0x44, 0x28, 0x10, 0x28, 0x44,// x        120
0x0C, 0x50, 0x50, 0x50, 0x3C,// y        121
0x44, 0x64, 0x54, 0x4C, 0x44,// z        122
0x00, 0x08, 0x36, 0x41, 0x00,// {        123
0x00, 0x00, 0x7F, 0x00, 0x00,// |        124
0x00, 0x41, 0x36, 0x08, 0x00,// }        125
0x00, 0x00, 0x00, 0x00, 0x00,// (space)  126
0x00, 0x00, 0x00, 0x00, 0x00,// (space)  127
0x7E, 0x11, 0x11, 0x11, 0x7E,// A        192
0x7F, 0x45, 0x45, 0x45, 0x39,// Б        193
0x7F, 0x49, 0x49, 0x49, 0x36,// B        194
0x7F, 0x01, 0x01, 0x01, 0x03,// Г        195
0xC0, 0x7E, 0x41, 0x7F, 0xC0,// Д        196
0x7F, 0x49, 0x49, 0x49, 0x41,// E        197
119,8,127,8,119,             // Ж        198
34,73,73,73,54,              // З        199
127,32,16,8,127,             // И        200
127,32,19,8,127,             // Й        201
0x7F, 0x08, 0x14, 0x22, 0x41,// K        202
64,62,1,1,127,               // Л        203
0x7F, 0x02, 0x04, 0x02, 0x7F,// M        204
0x7F, 0x08, 0x08, 0x08, 0x7F,// H        205
0x3E, 0x41, 0x41, 0x41, 0x3E,// O        206
127,1,1,1,127,               // П        207
0x7F, 0x09, 0x09, 0x09, 0x06,// P        208
0x3E, 0x41, 0x41, 0x41, 0x22,// C        209
0x01, 0x01, 0x7F, 0x01, 0x01,// T        210
39,72,72,72,63,              // У        211
30,33,127,33,30,             // Ф        212
0x63, 0x14, 0x08, 0x14, 0x63,// X        213
127,64,64,127,192,           // Ц        214
15,16,16,16,127,             // Ч        215
127,64,124,64,127,           // Ш        216
127,64,124,64,255,           // Щ        217
1,127,72,72,48,              // Ъ        218
127,72,48,0,127,             // Ы        219
127,72,72,72,48,             // Ь        220
34,73,73,73,62,              // Э        221
127,8,62,65,62,              // Ю        222
118,9,9,9,127,               // Я        223
0x20, 0x54, 0x54, 0x54, 0x78,// a        224
124, 84, 84, 84, 36,         // б        225
124, 84, 84, 84, 40,         // в        226
124, 4, 4, 4, 12,            // г        227
192, 120, 68, 124, 192,      // д        228
0x38, 0x54, 0x54, 0x54, 0x18,// e        229
108, 16, 124, 16, 108,       // ж        230
40, 68, 84, 84, 40,          // з        231
124, 32, 16, 8, 124,         // и        232
124, 33, 18, 8, 124,         // й        233
124, 16, 16, 40, 68,         // к        234
64, 56, 4, 4, 124,           // л        235
124, 8, 16, 8, 124,          // м        236
124, 16, 16, 16, 124,        // н        237
0x38, 0x44, 0x44, 0x44, 0x38,// o        238
124, 4, 4, 4, 124,           // п        239
0x7C, 0x14, 0x14, 0x14, 0x08,// p        240
0x38, 0x44, 0x44, 0x44, 0x20,// c        241
4, 4, 124, 4, 4,             // т        242
0x0C, 0x50, 0x50, 0x50, 0x3C,// y        243
24, 36, 124, 36, 24,         // ф        244
0x44, 0x28, 0x10, 0x28, 0x44,// x        245
124, 64, 64, 124, 192,       // ц        246
12, 16, 16, 16, 124,         // ч        247
124, 64, 120, 64, 124,       // ш        248
124, 64, 120, 64, 252,       // щ        249
124, 84, 80, 80, 32,         // ъ        250
124,80,32,0,124,             // ы        251
124, 80, 80, 80, 32,         // ь        252
40, 68, 84, 84, 56,          // э        253
124, 16, 56, 68, 56,         // ю        254
72, 52, 20, 20, 124          // я        255
};

//------------------------------LCD ------------------------------
  
void SPI_Wr(cmd_data_sv data,unsigned char value)																																							{
if (data==CMD) 	{CMD_();}
	else 					{DAT_();}
CS_LO();
while (!(SPI1->SR & SPI_SR_TXE)){};	 
SPI1_DR_8bit = value;
while (SPI1->SR & SPI_SR_BSY){};
while (!(SPI1->SR & SPI_SR_RXNE)){}; 
SPI1_DR_8bit;	
CS_HI();
}



void LCD_Init(void) 																																																					{// INIT LCD
CS_LO();
CMD_();	
RES_ON();
delay_ms(100);
RES_OFF();
delay_ms(100);	
CS_HI();
delay_ms(1);
 SPI_Wr(CMD,0x01); //reset sw
 delay_ms(50);
 SPI_Wr(CMD,0xc6); //initial escape
 delay_ms(40);
 SPI_Wr(CMD,0xb9); //Refresh set
 SPI_Wr(DAT,0x00);
 SPI_Wr(CMD,0xb6); //Display control
 SPI_Wr(DAT,0x80); //
 SPI_Wr(DAT,0x04); //
 SPI_Wr(DAT,0x8a); //
 SPI_Wr(DAT,0x54); //
 SPI_Wr(DAT,0x45); //
 SPI_Wr(DAT,0x52); //
 SPI_Wr(DAT,0x43); //
 
 SPI_Wr(CMD,0xb3); //Gray scale position set 0
 SPI_Wr(DAT,0x02); //
 SPI_Wr(DAT,0x0a); //
 SPI_Wr(DAT,0x15); //
 SPI_Wr(DAT,0x1f); //
 SPI_Wr(DAT,0x28); //
 SPI_Wr(DAT,0x30); //
 SPI_Wr(DAT,0x37); //
 SPI_Wr(DAT,0x3f); //
 SPI_Wr(DAT,0x47); //
 SPI_Wr(DAT,0x4c); //
 SPI_Wr(DAT,0x54); //
 SPI_Wr(DAT,0x65); //
 SPI_Wr(DAT,0x75); //
 SPI_Wr(DAT,0x80); //
 SPI_Wr(DAT,0x85); //
 SPI_Wr(CMD,0xb5); //Gamma curve
 SPI_Wr(DAT,0x01); //
 SPI_Wr(CMD,0xb7); //Temperature gradient
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x00); //
 SPI_Wr(CMD,0xbd); //Common driver output select
 SPI_Wr(DAT,0x00); //
 /* 
 SPI_Wr(CMD,0x33); //Vertical scrolling definition - 
 SPI_Wr(DAT,0x00); //qnt. lines, used for top fixed area (max - 0x53)
 SPI_Wr(DAT,0x53); //scrolling area
 SPI_Wr(DAT,0x00); //qnt. lines, used for bottom fixed area
 SPI_Wr(CMD,0x37); //Vertical scrolling start adress
 SPI_Wr(DAT,0x00);            
*/
 SPI_Wr(CMD,0x36); //Memory access control - Метод доступа к дисплейной памяти (установка нулевого адреса страницы и столбца, направление записи в память дисплея) 
 SPI_Wr(DAT,0x48); //6-й бит, установленный в "1" делает адресацию столбца - слева-направо, а 3-й бит в "1" - порядок RGB (а в даташите - ошибка!!!) 
 SPI_Wr(CMD,0x2d); //Colour set
 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x03); //
 SPI_Wr(DAT,0x05); //
 SPI_Wr(DAT,0x07); //
 SPI_Wr(DAT,0x09); //
 SPI_Wr(DAT,0x0b); //
 SPI_Wr(DAT,0x0d); //
 SPI_Wr(DAT,0x0f); //

 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x03); //
 SPI_Wr(DAT,0x05); //
 SPI_Wr(DAT,0x07); //
 SPI_Wr(DAT,0x09); //
 SPI_Wr(DAT,0x0b); //
 SPI_Wr(DAT,0x0d); //
 SPI_Wr(DAT,0x0f); //

 SPI_Wr(DAT,0x00); //
 SPI_Wr(DAT,0x05); //
 SPI_Wr(DAT,0x0b); //
 SPI_Wr(DAT,0x0f); //

 SPI_Wr(CMD,0xba);SPI_Wr(DAT,0x2f);SPI_Wr(DAT,0x03); //Voltage control
 SPI_Wr(CMD,0x25);SPI_Wr(DAT,0x63); 								 //Contrast   0x63 for 3.3v Backlight Led, 0x61 for 5v Backlight

 SPI_Wr(CMD,0xbe);  SPI_Wr(DAT,0x58);//Power control

 SPI_Wr(CMD,0x3a); //Информация о выводе пикселя
 #ifdef _8_BIT_COLOR 
 SPI_Wr(DAT,0x02); //8-ми битный цвет
 #else
 SPI_Wr(DAT,0x03); //12-ти битный цвет 
 #endif
 SPI_Wr(CMD,0x03); //Booster voltage ON
 delay_ms(40);
 SPI_Wr(CMD,0x11); //Выход из спящего режима

 delay_ms(20); 		//Перед включением ждем 20 миллисекунд 
 SPI_Wr(CMD,0x29); //Включение дисплея           
	
}

void SetArea(char x1, char x2, char y1, char y2)																																							{//Задаем область вывода изображения 
 SPI_Wr( CMD, 0x2A );  //задаем область по X
 SPI_Wr( DAT, x1 );    //начальная
 SPI_Wr( DAT, x2 );    //конечная

 SPI_Wr( CMD, 0x2B );  //задаем область по Y
 SPI_Wr( DAT, y1+1 );  //начальная (у этого контроллера Y отсчитывается от 1, а не от 0)
 SPI_Wr( DAT, y2+1 );  //конечная

 SPI_Wr( CMD, 0x2C );  //отправляем команду на начало записи в память и начинаем посылать данные
}
void Put_Pixel (char x, char y, unsigned int color) 																																					{// Рисуем точку 
 SetArea( x, x, y, y );     
 #ifdef _8_BIT_COLOR	//(8-ми битовая цветовая палитра (256 цветов))
 SPI_Wr( DAT, color ); //Данные - задаём цвет пикселя 
 #else			//(12-ми битовая цветовая палитра (4096 цветов))
 SPI_Wr( DAT, color>>4 );  SPI_Wr( DAT, color<<4 );
 #endif
}  

void Send_Symbol (unsigned char symbol, char x, char y, int t_color, int b_color, char zoom_width, char zoom_height, int rot) {//Функция прорисовки символа на дисплее
 unsigned char temp_symbol, a, b, zw, zh, mask; 
 char m, n;
 m=x; 
 n=y;
 if (symbol>127) symbol-=64;    //Убираем отсутствующую часть таблицы ASCII
 for ( a = 0; a < 5; a++) //Перебираю 5 байт, составляющих символ
 {  
  temp_symbol = font_5x8[symbol-32][a];
  zw = 0; 
  while(zw != zoom_width) //Вывод байта выполняется zw раз 
  {    
   switch(rot)
   {
    case 0: case 180: n=y; break;
    case 90: case 270: m=x; break;
   } 
   mask=0x01;     
   for ( b = 0; b < 8; b++ ) //Цикл перебирания 8 бит байта
   {         
    zh = 0; //в zoom_height раз увеличится высота символа
    while(zh != zoom_height) //Вывод пикселя выполняется z раз
    {
     switch(rot)
     {
      case 0: case 180:  
      if (temp_symbol&mask) 
      {
       Put_Pixel (m+zw, n+zh, t_color);
      }
      else
      {
       Put_Pixel (m+zw, n+zh, b_color);
      }
      break; 
      case 90: case 270: 
      if (temp_symbol&mask) 
      {
       Put_Pixel (m+zh, n+zw, t_color);
      }
      else
      {
       Put_Pixel (m+zh, n+zw, b_color);
      }
      break; //Получить адрес начального пикселя по оси y для вывода очередного байта            
     }            
     zh++;
    }
    mask<<=1; //Смещаю содержимое mask на 1 бит влево;
    switch(rot)
    {
     case 0: case 180: n=n+zoom_height; break;
     case 90: case 270: m=m+zoom_height; break;
    }          
   }
   zw++;   
  }
  switch(rot)
  {
   case 0: case 180: m=m+zoom_width; break;
   case 90: case 270: n=n+zoom_width; break;
  }           
 }
} 


void LCD_Putchar(char symbol, char x, char y, int t_color, int b_color, char zoom_width, char zoom_height, int rot)						{//Функция вывода одного символа ASCII-кода 
    unsigned char m;
    if(zoom_width == 0)   zoom_width = 1;
    if(zoom_height == 0)  zoom_height = 1;
    switch (rot)
    {
        case 0:  //Начальный адрес осей Х и У - левый верхний угол дисплея   
        Send_Symbol( symbol, x, y, t_color, b_color, zoom_width, zoom_height, rot);
        break;
        //================================
        case 90:
        m=y+3; y=x; x=m;
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x08); //Начальный адрес осей Х и У - правый верхний угол дисплея 
        Send_Symbol( symbol, x, y, t_color, b_color, zoom_width, zoom_height, rot);
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x48);
        break;
        //================================
        case 180:
        x+=3; y+=2;       
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x88); //Начальный адрес осей Х и У - правый нижний угол дисплея 
        Send_Symbol( symbol, x, y, t_color, b_color, zoom_width, zoom_height, rot);
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x48);
        break;
        //================================
        case 270:
        m=y; y=x+2; x=m;
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0xC8); //Начальный адрес осей Х и У - левый нижний угол дисплея  
        Send_Symbol( symbol, x, y, t_color, b_color, zoom_width, zoom_height, rot);
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x48);
        break;
        //================================
        default:
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x48); //Начальный адрес осей Х и У - левый верхний угол дисплея  
        Send_Symbol( symbol, x, y, t_color, b_color, zoom_width, zoom_height, rot);
        SPI_Wr(CMD, 0x36); 
        SPI_Wr(DAT, 0x48);
        //=================================    
    };  
}

void LCD_Puts(char *str, int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot)									{//Функция вывода строки
 unsigned char i=0;
              
 if(zoom_width == 0)   zoom_width = 1;
 if(zoom_height == 0)  zoom_height = 1;
   
 while (str[i]) //x и y - адрес пикселя начальной позиции; с увеличением переменной i адрес вывода очередного символа смещается на i*6 (чем организуются столбцы дисплея)  
 {      
  LCD_Putchar(str[i], x+(i*6*zoom_width), y, t_color, b_color, zoom_width, zoom_height, rot);
  i++;
 }  
}
void Send_Symbol_Shadow (unsigned char symbol, char x, char y, int t_color, char zoom_width, char zoom_height, int rot) 			{//
 unsigned char temp_symbol, a, b, zw, zh, mask; 
 char m, n;
 m=x; 
 n=y;
 if (symbol>127) symbol-=64;    //Убираем отсутствующую часть таблицы ASCII
 for ( a = 0; a < 5; a++) //Перебираю 5 байт, составляющих символ
 {  
  temp_symbol = font_5x8[symbol-32][a];
  zw = 0; 
  while(zw != zoom_width) //Вывод байта выполняется zw раз 
  {    
   switch(rot)
   {
    case 0: case 180: n=y; break;
    case 90: case 270: m=x; break;
   } 
   mask=0x01;     
   for ( b = 0; b < 8; b++ ) //Цикл перебирания 8 бит байта
   {         
    zh = 0; //в zoom_height раз увеличится высота символа
    while(zh != zoom_height) //Вывод пикселя выполняется z раз
    {
     switch(rot)
     {
      case 0: case 180:  
      if (temp_symbol&mask) 
      {
       Put_Pixel (m+zw, n+zh, t_color);
      }
      break; 
      case 90: case 270: 
      if (temp_symbol&mask) 
      {
       Put_Pixel (m+zh, n+zw, t_color);
      }
      break; //Получить адрес начального пикселя по оси y для вывода очередного байта            
     }            
     zh++;
    }
    mask<<=1; //Смещаю содержимое mask на 1 бит влево;
    switch(rot)
    {
     case 0: case 180: n=n+zoom_height; break;
     case 90: case 270: m=m+zoom_height; break;
    }          
   }
   zw++;   
  }
  switch(rot)
  {
   case 0: case 180: m=m+zoom_width; break;
   case 90: case 270: n=n+zoom_width; break;
  }           
 }
} 


void LCD_Putchar_Shadow (char symbol, char x, char y, int t_color, char zoom_width, char zoom_height, int rot)								{//Функция вывода одного символа ASCII-кода без цвета фона
 unsigned char m;
 if(zoom_width == 0)   zoom_width = 1;
 if(zoom_height == 0)  zoom_height = 1;
 switch (rot)
 {
  case 0:  //Начальный адрес осей Х и У - левый верхний угол дисплея   
  Send_Symbol_Shadow( symbol, x, y, t_color, zoom_width, zoom_height, rot);
  break;
  //================================
  case 90:  
  m=y+3; y=x; x=m;
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x08); //Начальный адрес осей Х и У - правый верхний угол дисплея 
  Send_Symbol_Shadow( symbol, x, y, t_color, zoom_width, zoom_height, rot);
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x48);
  break;
  //================================
  case 180:
  x+=3; y+=2;          
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x88); //Начальный адрес осей Х и У - правый нижний угол дисплея 
  Send_Symbol_Shadow( symbol, x, y, t_color, zoom_width, zoom_height, rot);
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x48);
  break;
  //================================
  case 270:
  m=y; y=x+2; x=m;
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0xC8); //Начальный адрес осей Х и У - левый нижний угол дисплея  
  Send_Symbol_Shadow( symbol, x, y, t_color, zoom_width, zoom_height, rot);
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x48);
  break;
  //================================
  default:
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x48); //Начальный адрес осей Х и У - левый верхний угол дисплея  
  Send_Symbol_Shadow( symbol, x, y, t_color, zoom_width, zoom_height, rot);
  SPI_Wr(CMD, 0x36); 
  SPI_Wr(DAT, 0x48);
  //=================================    
 };  
}

void LCD_Puts_Shadow(char *str, int x, int y,  int t_color, char zoom_width, char zoom_height, int rot)												{//Функция вывода строки, без цвета фона 

 unsigned char i=0;
                    
 if(zoom_width == 0)   zoom_width = 1;
 if(zoom_height == 0)  zoom_height = 1;
   
 while (str[i]) //x и y - адрес пикселя начальной позиции; с увеличением переменной i адрес вывода очередного символа смещается на i*6 (чем организуются столбцы дисплея)  
 {      
  LCD_Putchar_Shadow(str[i], x+(i*6*zoom_width), y, t_color, zoom_width, zoom_height, rot);
  i++;
 }  
}


void LCD_PrintDec(long val,int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot) 							{// Print Dec

 if(zoom_width == 0)   zoom_width = 1;
 if(zoom_height == 0)  zoom_height = 1;
	
	char i=1,d=0;
	unsigned char text[10];
//-------Added for support valur <0----------------
	uint8_t minus_flag=0;
	uint32_t value;
	if (val>=0) {value=val;}
		else {value=val*(-1);minus_flag=1;}

//-------------------------------------------------	
do 
  { 
    if (value >=10)  {
				d = value % 10; 																				
				text[i] = d + '0'; 																			
				value /= 10; 																						
			}
		else 
			{	text[i] = value + '0';
				value=0;
			}
 		i++;
  }
	while(value); 

//-------Added for support valur <0----------------
	if(minus_flag) {text[i]='-';}
		else {i--;}		
	d=i;
for (d=i;d>0;d--){	
	
		LCD_Putchar(text[d], x+((i-d)*6*zoom_width), y, t_color, b_color, zoom_width, zoom_height, rot);
		
	}

}
			
void LCD_PrintHex(long val,int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot) 							{// Print Hex
	
	char i=1,d=0;
	unsigned char text[10];
//-------------Added for support valur <0
	uint8_t minus_flag=0;
	uint32_t value;
	if (val>=0) {value=val;}
		else {value=val*(-1);minus_flag=1;}
//---------------------------------------		
	do 
  { 
    if (value >=0x10)  {
				d = value % 0x10; 																				
				if(d<0x0A) text[i] = d + '0'; 																			
				else 			 text[i] = d + 0x37;
				value /= 0x10; 																						
			}
		else 
			{	
				if(value < 0x0A)	text[i] = value + '0';			//0..9
				else 							text[i] = value + 0x37;			//A...F
				value=0;
			}
 		i++;
  }
	while(value); 
//-------Added for support valur <0----------------
	if(minus_flag) {text[i]='-';}
	else {i--;}		
//---------------------------------------		
d=i;
	do
	{	LCD_Putchar(text[i], x+((d-i)*6*zoom_width), y, t_color, b_color, zoom_width, zoom_height, rot);
		i--;
	}
	while(i);
}

void LCD_PrintBin(unsigned char value,int x, int y,  int t_color, int b_color, char zoom_width, char zoom_height, int rot) 		{// Print Bin
	
	unsigned char i=1,d=0;
	unsigned char text[9];
	do 
  { 
    if (value >=2)  {
				d = value % 2; 																				
				text[i] = d + '0'; 																			
				value /= 0x2; 																						
			}
		else 
			{	
				text[i] = value + '0';			//0..9
				value=0;
			}
 		i++;
  }
	while(i<9); 
	i--;
d=i;	
	do
	{	LCD_Putchar(text[i], x+((d-i)*6*zoom_width), y, t_color, b_color, zoom_width, zoom_height, rot);
		i--;
	}
	while(i);
}	

//------------------------------
void LCD_FillScreen (unsigned int color)																																											{//заливаем цветом 
 unsigned int x;
 SetArea( 0, 100, 0, 80 );   //Область всего экрана
 for (x = 0; x < 8080; x++)  
 {   
  #ifdef _8_BIT_COLOR        //(8-ми битовая цветовая палитра (256 цветов))
  SPI_Wr( DAT, color ); //Данные - задаём цвет пикселя       
  #else                      //(12-ми битовая цветовая палитра (4096 цветов))
  SPI_Wr( DAT, color>>4 );  SPI_Wr( DAT, (color<<4)|(color>>8) ); SPI_Wr( DAT, color ); x++; //Задаём цвет двух пикселей
  #endif
 }                 
} 
void LCD_DrawLine (char x1, char y1, char x2, char y2, int color)																															{//НАРИСОВАТЬ ЛИНИЮ 
 short  x, y, d, dx, dy, i, i1, i2, kx, ky;
 signed char flag;

 dx = x2 - x1;
 dy = y2 - y1;
 if (dx == 0 && dy == 0) Put_Pixel(x1, y1, color);  //Точка
 else      //Линия
 {
  kx = 1;
  ky = 1;
  if( dx < 0 )
  { 
   dx = -dx; 
   kx = -1; 
  }
  else
  if(dx == 0) kx = 0;
  if(dy < 0)
  { 
   dy = -dy; 
   ky = -1; 
  }
  if(dx < dy)
  { 
   flag = 0; 
   d = dx; 
   dx = dy; 
   dy = d; 
  }
  else flag = 1;
  i1 = dy + dy; 
  d = i1 - dx; 
  i2 = d - dx;
  x = x1; 
  y = y1;

  for(i=0; i < dx; i++)
  {
   Put_Pixel(x, y, color);
   if(flag) x += kx;
   else y += ky;
   if( d < 0 ) d += i1;
   else
   {
    d += i2;
    if(flag) y += ky;
    else x += kx;
   }
  }
  Put_Pixel(x, y, color);
 }
} 



void LCD_DrawRect (char x1, char y1, char width, char height, char size, int color)																						{//НАРИСОВАТЬ РАМКУ     
 unsigned int i;
 char x2=x1+(width-1), y2=y1+(height-1); //Конечные размеры рамки по осям х и у
 for( i=1; i<=size; i++)   // size - толщина рамки
 {
  LCD_DrawLine(x1, y1, x1, y2, color);
  LCD_DrawLine(x2, y1, x2, y2, color);
  LCD_DrawLine(x1, y1, x2, y1, color);
  LCD_DrawLine(x1, y2, x2, y2, color);
  x1++; // Увеличиваю толщину рамки, если это задано
  y1++;
  x2--;
  y2--;
 }
}
void LCD_FillRect (char x1, char y1, char width, char height, int color)																											{//ЗАПОЛНИТЬ ПРЯМОУГОЛЬНИК ЦВЕТОМ COLOR  
 unsigned int x, y;																																			//Для 12-ти битного режима результат произведения width * height должен быть кратен 2!
       
 SetArea( x1, x1+(width-1), y1, y1+(height-1) );
 y = width * height;	        //Количество пикселей в прямоугольнике
 for (x = 0; x < y; x++) 
 {   
  #ifdef _8_BIT_COLOR        //(8-ми битовая цветовая палитра (256 цветов))
  SPI_Wr( DAT, color ); SPI_Wr( DAT, color ); //Данные - задаём цвет пикселя 
  #else                      
  SPI_Wr( DAT, color>>4 ); SPI_Wr( DAT, (color<<4)|(color>>8) ); SPI_Wr( DAT, color ); x++; //Задаём цвет двух пикселей
  #endif
 }   
}  
void LCD_DrawCircle (char xcenter, char ycenter, char rad, int color)																													{//НАРИСОВАТЬ ОКРУЖНОСТЬ
 signed int tswitch, x1=0, y1; 
 char d;

 d = ycenter - xcenter;
 y1 = rad;
 tswitch = 3 - 2 * rad;
 while (x1 <= y1) 
 {
  Put_Pixel(xcenter + x1, ycenter + y1, color); 
  Put_Pixel(xcenter + x1, ycenter - y1, color);
  Put_Pixel(xcenter - x1, ycenter + y1, color);   
  Put_Pixel(xcenter - x1, ycenter - y1, color);
  Put_Pixel(ycenter + y1 - d, ycenter + x1, color); 
  Put_Pixel(ycenter + y1 - d, ycenter - x1, color);
  Put_Pixel(ycenter - y1 - d, ycenter + x1, color);
  Put_Pixel(ycenter - y1 - d, ycenter - x1, color);

  if (tswitch < 0) tswitch += (4 * x1 + 6);
  else 
  {
   tswitch += (4 * (x1 - y1) + 10);
   y1--;
  }
  x1++;
 }
}    
void LCD_FillCircle (char xcenter, char ycenter, char rad, int color)																													{// ЗАПОЛНИТЬ КРУГ ЦВЕТОМ COLOR
 signed int x1=0, y1, tswitch; 
 y1 = rad;
 tswitch = 1 - rad;

 do
 {
  LCD_DrawLine(xcenter-x1, ycenter+y1, xcenter+x1, ycenter+y1, color);
  LCD_DrawLine(xcenter-x1, ycenter-y1, xcenter+x1, ycenter-y1, color);
  LCD_DrawLine(xcenter-y1, ycenter+x1, xcenter+y1, ycenter+x1, color);
  LCD_DrawLine(xcenter-y1, ycenter-x1, xcenter+y1, ycenter-x1, color);

  if(tswitch < 0)
  tswitch+= 3 + 2*x1++;
  else
  tswitch+= 5 + 2*(x1++ - y1--);
 } while(x1 <= y1);
}

void LCD_DrawTriangle(char x1, char y1, char x2, char y2, char x3, char y3, int color)																				{//НАРИСОВАТЬ ТРЕУГОЛЬНИК
 LCD_DrawLine(x1, y1, x2, y2, color);
 LCD_DrawLine(x3, y3, x1, y1, color);
 LCD_DrawLine(x3, y3, x2, y2, color);  
}


void LCD_FillTriangleA(char x1, char y1, char x2, char y2, char x3, char y3, int color)																				{
 signed long x, y, addx, dx, dy;
 signed long P;
 int i;
 long a1,a2,b1,b2;
 if(y1>y2)  {b1=y2; b2=y1; a1=x2; a2=x1;}
 else       {b1=y1; b2=y2; a1=x1; a2=x2;}
 dx = a2 -a1;
 dy = b2 - b1;
 if(dx<0)dx=-dx;
 if(dy<0)dy=-dy;
 x = a1;
 y = b1;
   
 if(a1 > a2)    addx = -1;
 else           addx = 1;
   
 if(dx >= dy)
 {
  P = 2*dy - dx;
  for(i=0; i<=dx; ++i)
  {
   LCD_DrawLine((int)x, (int)y, x3, y3, color);
   if(P < 0)
   {
    P += 2*dy;
    x += addx;
   }
   else
   {
    P += 2*dy - 2*dx;
    x += addx;
    y ++;
   }
  }
 }
 else
 {
  P = 2*dx - dy;
  for(i=0; i<=dy; ++i)
  {
   LCD_DrawLine((int)x, (int)y, x3, y3, color);
   if(P < 0)
   {
    P += 2*dx;
    y ++;
   }
   else
   {
    P += 2*dx - 2*dy;
    x += addx;
    y ++;
   }
  }
 }
}
void LCD_FillTriangle(char x1, char y1, char x2, char y2, char x3, char y3, int color)																				{//ЗАПОЛНИТЬ ТРЕУГОЛЬНИК ЦВЕТОМ COLOR
 LCD_FillTriangleA(x1, y1, x2, y2, x3, y3, color);
 LCD_FillTriangleA(x3, y3, x1, y1, x2, y2, color);
 LCD_FillTriangleA(x3, y3, x2, y2, x1, y1, color);
}    


