#ifndef __SED1335_H__
#define __SED1335_H__

#include "stm32f10x_usart.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void AG320240_Init(void);
void AG320240_Test(void);

extern void 	Cmdwrite(unsigned char cmdcode) ;
extern void 	Datawrite(unsigned char wrdata) ;
extern void 	LCD_Initial(void);

extern void 	LcdClear(void);				//��LCDȫ���Ӻ���
extern void 	LcdClear_1(void);				//��LCD����1��ʾ���Ӻ���
extern void 	LcdClear_2(void);				//��LCD����2��ʾ���Ӻ���
extern void 	LcdClear_3(void);				//��LCD����3��ʾ���Ӻ���
extern void 	PutBMP(unsigned char *puts);	//��ʾͼƬ����
extern void 	dot (U16 x, U16 y,U8 c);			//���㺯��
extern void 	draw_circle(int a,int b,int R); 		//��Բ����

extern void 	Set_Add1(char x, char y);			//����1�����������ַ
extern void 	Set_Add2(char x, char y);			//����2�����������ַ
extern void 	Set_Add3(char x, char y);			//����3�����������ַ

extern void 	frame(void);						//����
extern void 	d_perpend(char x,char y,char wide);	 	//����
extern void 	Disp_16Char(char c);					//��ʾһ��8*16�ַ�
extern void 	Disp_32Char(char c);					//��ʾһ��16*32�ַ�
extern void 	Disp_String( char *c);					//��ʾ�ַ���
extern void 	DispStringAt(char x, char y,char *c);		//�ڶ���������ʾ�ַ���
extern void 	Disp_16Float(float value, char numb);  	//��ʾ8*16������
extern void 	Disp_32Float(float value, char numb);  	//��ʾ16*32������

extern void 	Write_16StringChar(char *str);			//�Լ�����ʾ�ַ���
extern void 	Write_16StringHZ( char *strhz);			//�Լ�����ʾ���ּ��ַ���


extern void 	Write_16Char(unsigned char str);     				 //���Լ���д8*16�ַ�
extern void 	Write_16HZ(unsigned char hz0,unsigned char hz1);  //���Լ���д16*16����

extern void 	GUI_DispString_GS(char *fmt,...);   //����ʽ��GUI_DispString��ʾ�ַ���

extern void dface(void);		//��������
extern void mainface(void);	//������




//������ʾ��ع�����ʾ
 /*
x: ��
y: ��
m: ÿ���ַ���ɨ�������� 8*16���ַ���16*16�ĺ���ȡ16
n: �ַ��߶�
*p:  �ַ���ַ

*/

 extern void CCTW(unsigned int x,unsigned char y,unsigned char m,unsigned char n,unsigned char *p);


extern void Printstr(void) ;

extern void sed1335_read(char commandcode, unsigned char *parameter,unsigned int n);

extern void sed1335_write(unsigned char commandcode, unsigned char *parameter,unsigned char n);

extern void mDelay1_2uS(void );  // ������ʱ1.2uS,���ݵ�Ƭ����Ƶ���� 



  

//void Beep_2(void);

#endif /*__SED1335_H__*/
