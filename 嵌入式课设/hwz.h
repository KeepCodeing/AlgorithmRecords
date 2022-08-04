#ifndef __HWZ_KARMA
#define __HWZ_KARMA

typedef struct {
	unsigned int CON;
	unsigned int DAT;
} gpm1, gpm2, gpm3, gpm4;

typedef struct {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
} gpx1;

// GPM1 0x1100 0280
// GPM2 0x1100 02A0
// GPM3 0x1100 02C0
// GPM4 0x1100 02E0
// GPX1 0x1100 0C20

#define GPM1 (*(volatile gpm1 *)0x11000280)
#define GPM2 (*(volatile gpm2 *)0x110002A0)
#define GPM3 (*(volatile gpm3 *)0x110002C0)
#define GPM4 (*(volatile gpm4 *)0x110002E0)
#define GPX1 (*(volatile gpx1 *)0x11000C20)

void hwz_led1_on();
void hwz_led1_off();

void hwz_led2_on();
void hwz_led2_off();

void hwz_led3_on();
void hwz_led3_off();

void hwz_led4_on();
void hwz_led4_off();

void hwz_led5_on();
void hwz_led5_off();

void hwz_led_init();
void hwz_key_init();
void hwz_led_flow();
void delay_ms(int ms);

#endif
