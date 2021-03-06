/*>execute.c
 *
 * Chuckie Egg
 * BBC version by Doug Anderson. Copyright A & F Software.
 * RISC OS Conversion by Michel Foot.
 * Version 1.03 (09 Feb 2003).
 *
 * PC port of RISC OS Conversion by Mark Lomas (31 Mar 2007)
 */
#include <stdio.h>
#include "bbcb/bbcb.h"

extern void m1902(void);
extern void m1987(void);
extern void m19DB(void);
extern void m1A0C(void);
extern void m1A26(void);
extern void m1A3B(void);
extern void m1A90(void);
extern void m1AA4(void);
extern void m1AB5(void);
extern void m1B01(void);
extern void m1B10(void);
extern void m1B33(void);
extern void m1CC3(void);
extern void m1E63(void);
extern void m2276(void);
extern void m22FE(void);
extern void m2311(void);
extern void m2324(void);
extern void m2336(void);
extern void m234B(void);
extern void m2374(void);
extern void m23C8(void);
extern void m23E0(void);
extern void m2407(void);
extern void m25A9(void);
extern void m26DC(void);
extern void m2702(void);
extern void m2715(void);
extern void m2728(void);
extern void m277C(void);
extern void m27CB(void);
extern void m2806(void);
extern void m2838_displayHighScores(void);
extern void m28BE(void);
extern void m2ACD_systemInit(void);
extern void m2B83(void);
extern void m2BF6(void);
extern void m2C54(void);
extern void m2C65(void);
extern void m2DB4(void);
extern void m2DC0(void);
extern void m2DFE(void);
extern void m2E2D(void);
extern void m2E6B(void);
extern void m2E92(void);
extern void m2F49(void);
extern void m2F7C(void);
extern void m3003_redefineKeys(void);
extern void m305C(void);
extern void m32F0(void);
extern void m3338(void);

extern FILE * hfile;


void execute(void)
{
	int duration;
	//int timeleft;
/*goto m29AB;

m29AB:*/
  /*JSR_ABSOL(0x29AB,m2ACD)*/
  m2ACD_systemInit();
  #ifndef __ORIGINAL__
    //hfile = fopen("Scores","rb");
    //if (hfile != NULL)
    //{
    //  fread(memory+0x0430,1,0xA0,hfile);
    //  fclose(hfile);
    //}
  #endif

m29AE:

  /*JSR_ABSOL(0x29AE,m2C65)*/
  m2C65();

  /*quit the game*/
  if (quit)
    return;

  /*JSR_ABSOL(0x2B83,m2B83)*/
  /*m2B83();*/
/*m2B83:*/
  /*display "how many players"*/
  LDX_IMMED(0x3A)
  LDY_IMMED(0x2C)
  /*JSR_ABSOL(0x1A26,m1A26)*/
  m1A26(); /* Print string */
  LDA_IMMED(0x00)
  STA_ZEROP(0x8B)
  LDA_IMMED(0x64)
  STA_ZEROP(0x8C)
m2B92:
  PollMessages();
  /*get number of players*/
  LDX_IMMED(0xCF)
  LDY_IMMED(0xFF)
  LDA_IMMED(0x81)
  OSBYTE81
  CPY_IMMED(0x00)
  BEQ(m2BA4)
  LDA_IMMED(0x01)
  JMP_ABSOL(m2BE7)
m2BA4:
  LDX_IMMED(0xCE)
  LDY_IMMED(0xFF)
  LDA_IMMED(0x81)
  OSBYTE81
  CPY_IMMED(0x00)
  BEQ(m2BB6)
  LDA_IMMED(0x02)
  JMP_ABSOL(m2BE7)
m2BB6:
  LDX_IMMED(0xEE)
  LDY_IMMED(0xFF)
  LDA_IMMED(0x81)
  OSBYTE81
  CPY_IMMED(0x00)
  BEQ(m2BC8)
  LDA_IMMED(0x03)
  JMP_ABSOL(m2BE7)
m2BC8:
  LDX_IMMED(0xED)
  LDY_IMMED(0xFF)
  LDA_IMMED(0x81)
  OSBYTE81
  CPY_IMMED(0x00)
  BEQ(m2BDA)
  LDA_IMMED(0x04)
  JMP_ABSOL(m2BE7)
m2BDA:
  /* Test keys upto 64*256 times then exit back to main screen */
  DEC_ZEROP(0x8B)
  BNE(m2B92)

  /* Make this delay bigger */
  delay(32);

  /* Test keys upto 64*256 times then exit back to main screen */
  DEC_ZEROP(0x8C)
  BNE(m2B92)
  PLA
  PLA
  JMP_ABSOL(m29AE)
m2BE7:
  /*start game*/
  STA_ZEROP(0x5E)
  STA_ZEROP(0x5F)
  CLC
  ADC_IMMED(0x30)
  OSWRCH
  LDA_IMMED(0x05)
  /*JSR_ABSOL(0x2C54,m2C54)*/
  m2C54();
  /*set up lives*/
  m2BF6();
m29B4:
  /*display "get ready"*/
  LDX_IMMED(0xA8)
  LDY_IMMED(0x2A)
  /*JSR_ABSOL(0x1A26,m1A26)*/
  m1A26(); /* Print string */
  /*display "player"*/
  LDX_IMMED(0xBF)
  LDY_IMMED(0x2A)
  /*JSR_ABSOL(0x1A26,m1A26)*/
  m1A26(); /* Print string */
  LDA_ZEROP(0x5D)
  CLC
  ADC_IMMED(0x31)
  OSWRCH
  LDA_IMMED(0x14)
  /*JSR_ABSOL(0x2C54,m2C54)*/
  m2C54();
m29CF:
  /*JSR_ABSOL(0x2DC0,m2DC0)*/
  m2DC0();
  /*JSR_ABSOL(0x1B33,m1B33)*/
  m1B33(); /* Draw game screen */
  /*JSR_ABSOL(0x2E92,m2E92)*/
  m2E92();
m29D8:
  /*play game loop*/

  /*JSR_ABSOL(0x1A3B,m1A3B)*/
  m1A3B();
  /*JSR_ABSOL(0x1E63,m1E63)*/
  m1E63();
  /*JSR_ABSOL(0x3338,m3338)*/
  m3338();
  /*JSR_ABSOL(0x2374,m2374)*/
  m2374();
  /*JSR_ABSOL(0x2407,m2407)*/
  m2407();
  /*JSR_ABSOL(0x2F49,m2F49)*/
  m2F49();
  /*JSR_ABSOL(0x2728,m2728)*/
  m2728();
  /*JSR_ABSOL(0x1B10,m1B10)*/
  m1B10(); /* Main game delay loop to set speed. */
  LDA_ZEROP(0x4F)

  BNE(m2A39)

  LDA_ZEROP(0x41)
  CMP_IMMED(0x11)
  BCC(m2A39)
  LDA_ZEROP(0x39)
  BEQ(m2A05)
  LDA_ZEROP(0x60)
  BMI(m29AE)

  /*
  WAIT_FOR_VERTICAL_SYNC
  */

  JMP_ABSOL(m29D8) /* next iteration of game loop */
m2A05:
  LDA_ZEROP(0x3D)
  BNE(m2A2B)

	  //timeleft = 0; /* Reset total duration counter for applause */
m2A09:
  LDA_IMMED(0x01)
  LDX_IMMED(0x06)
  /*JSR_ABSOL(0x1AB5,m1AB5)*/
  m1AB5();
  /*JSR_ABSOL(0x26DC,m26DC)*/
  m26DC();
  /*JSR_ABSOL(0x2F49,m2F49)*/
  m2F49();
  LDA_ZEROP(0x3C)
  BEQ(m2A1E)
  CMP_IMMED(0x05)
  BNE(m2A27)
m2A1E:
  LDX_IMMED(0xB0)
  LDY_IMMED(0x0C)
  LDA_IMMED(0x07)
  OSWORD

  /* Slow down the bonus score count down.*/
  duration = ((memory[0x0CB7] << 8) | memory[0x0CB6]);
  /* duration is in 20ths of a second */
  delay((duration*1000)/20); /* delay expects milliseconds */
  PollMessages();

m2A27:
  LDA_ZEROP(0x3D)
  BEQ(m2A09)

m2A2B:
  INC_ZEROP(0x50)
  /*JSR_ABSOL(0x2E6B,m2E6B)*/
  m2E6B();
  /*JSR_ABSOL(0x2DFE,m2DFE)*/
  m2DFE();
  /*JSR_ABSOL(0x2E2D,m2E2D)*/
  m2E2D();
  JMP_ABSOL(m29CF)
m2A39:
  /*JSR_ABSOL(0x2E6B,m2E6B)*/
  m2E6B();
  LDX_IMMED(0xA6)
  LDY_IMMED(0x2F)
  /*&2A40 : play death tune*/
  /*JSR_ABSOL(0x2F7C,m2F7C)*/
  m2F7C();
  /*&2A43*/
  LDX_ZEROP(0x5D)
  /*&2A45 : decrement lives*/
  DEC_ZEROX(0x20)
  /*check for 0 lives*/
  BNE(m2A70)
  LDX_IMMED(0x8A)
  LDY_IMMED(0x2A)
  /*JSR_ABSOL(0x1A26,m1A26)*/
  m1A26(); /* Print string */
  LDX_IMMED(0xBF)
  LDY_IMMED(0x2A)
  /*JSR_ABSOL(0x1A26,m1A26)*/
  m1A26(); /* Print string */
  LDA_ZEROP(0x5D)
  CLC
  ADC_IMMED(0x31)
  OSWRCH
  LDA_IMMED(0x0A)
  /*JSR_ABSOL(0x2C54,m2C54)*/
  m2C54(); /*delay loop*/
  /*JSR_ABSOL(0x28BE,m28BE)*/
  m28BE();
  LDA_IMMED(0x05)
  /*JSR_ABSOL(0x2C54,m2C54)*/
  m2C54();
  DEC_ZEROP(0x5F)
  BEQ(m2A87)
m2A70:
  LDX_ZEROP(0x5D)
  INX
  TXA
  AND_IMMED(0x03)
  STA_ZEROP(0x5D)
  CMP_ZEROP(0x5E)
  BCS(m2A70)
  TAX
  LDA_ZEROX(0x20)
  BEQ(m2A70)
  /*JSR_ABSOL(0x2E2D,m2E2D)*/
  m2E2D();
  JMP_ABSOL(m29B4)
m2A87:
  JMP_ABSOL(m29AE)
}

