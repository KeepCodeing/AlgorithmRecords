#include <stdio.h>
#include "hwz.h"

// output 0b1 -> 1亮 0灭

// LED1 -> GPIO_D1_M1 -> A62 -> SIM900A_POWERKEY -> AE6 -> GPM4_2
// -> GPM4CON[2] -> 0x1100 02E0[11:8]

// LED2 -> GPIO_LOCK_M2 -> A57 -> GPIO_595_LOCK -> AG6 -> GPM1_6
// -> GPM1CON[6] -> 0x1100 0280[27:24]

// LED3 -> GPIO_LOCK_M3 -> A58 -> GPIO_595_CLK -> AG1 -> GPM3_5
// -> GPM3CON[5] -> 0x1100 02C0[23:20]

// LED4 -> GPIO_M4 -> A64 -> SIM900A_RI -> AG4 -> GPM1_3
// -> GPM1CON[3] -> 0x1100 0280[15:12]

// LED5 -> GPIO_M5 -> A65 -> SIM900A_RST -> AE5 -> GPM2_2
// -> GPM2CON[2] -> 0x1100 02A0[11:8]

// GPM1 0x1100 0280
// GPM2 0x1100 02A0
// GPM3 0x1100 02C0
// GPM4 0x1100 02E0

// KEY1 -> XEINT16/KP_COL0 -> D25 -> XEINT16/KP_COL0_LV -> A3 -> GPX1_0 -> GPX1CON[0] -> 0x1100 0C20[3:0]
// KEY2 -> XEINT17/KP_COL1 -> D26 -> XEINT17/KP_COL1_LV -> B5 -> GPX1_1 -> GPX1CON[1] -> 0x1100 0C20[7:4]
// KEY3 -> XEINT18/KP_COL2 -> D25 -> XEINT18/KP_COL2_LV -> H6 -> GPX1_2 -> GPX1CON[2] -> 0x1100 0C20[11:8]
// KEY4 -> XEINT19/KP_COL3 -> D25 -> XEINT19/KP_COL3_LV -> D7 -> GPX1_3 -> GPX1CON[3] -> 0x1100 0C20[15:12]

int main() {
	hwz_led_init();
	hwz_key_init();
	hwz_led_flow();
	char k2_stat, k3_stat;
	char k2_num = 0, k3_num = 0;
	while (1) {
		// stat = n - 1
		k2_stat = GPX1.DAT & (0x1 << 1);
		k3_stat = GPX1.DAT & (0x1 << 2);
		if (!k2_stat) {
			delay_ms(60);
			if (!k2_stat) {
				if (k2_num % 2 == 0) hwz_led4_on();
				else hwz_led4_off();

				k2_num++;

				while (!k2_stat);
			}
		}

		if (!k3_stat) {
			delay_ms(60);
			if (!k3_stat) {
				if (k3_num % 2 == 0) hwz_led3_on();
				else hwz_led3_off();

				k3_num++;

				while (!k3_stat);
			}
		}
	}
	return 0;
}

void hwz_led1_on() {
	GPM4.DAT &= ~(0x1 << 2);
}

void hwz_led1_off() {
	GPM4.DAT |= (0x1 << 2);
}

void hwz_led2_on() {
	GPM1.DAT &= ~(0x1 << 6);
}

void hwz_led2_off() {
	GPM1.DAT |= (0x1 << 6);
}

void hwz_led3_on() {
	GPM3.DAT &= ~(0x1 << 5);
}

void hwz_led3_off() {
	GPM3.DAT |= (0x1 << 5);
}

void hwz_led4_on() {
	GPM1.DAT &= ~(0x1 << 3);
}

void hwz_led4_off() {
	GPM1.DAT |= (0x1 << 3);
}

void hwz_led5_on() {
	GPM2.DAT &= ~(0x1 << 2);
}

void hwz_led5_off() {
	GPM2.DAT |= (0x1 << 2);
}

// 设置输出模式
void hwz_led_init() {
	// LED1
	GPM4.CON &= ~(0xF << 8)  | (0x1 << 8);
	// LED2, LED4
	GPM1.CON &= ~(0xF << 24) | (0x1 << 24);
	GPM1.CON &= ~(0xF << 12) | (0x1 << 12);
	// LED3
	GPM3.CON &= ~(0xF << 20) | (0x1 << 20);
	// LED5
	GPM2.CON &= ~(0xF << 8)  | (0x1 << 8);
}

// 3324
void hwz_key_init() {
	// K3 PUD (N - 1) * 2
	GPX1.CON &= ~(0xF << 8);
	GPX1.PUD &= ~(0x3 << 4);
	// K2
	GPX1.CON &= ~(0xF << 4);
	GPX1.PUD &= ~(0x3 << 2);
}

void hwz_led_flow() {
	hwz_led1_on();
	delay_ms(1000);
	hwz_led1_off();
	delay_ms(1000);

	hwz_led2_on();
	delay_ms(1000);
	hwz_led2_off();
	delay_ms(1000);

	hwz_led3_on();
	delay_ms(1000);
	hwz_led3_off();
	delay_ms(1000);

	hwz_led4_on();
	delay_ms(1000);
	hwz_led4_off();
	delay_ms(1000);

	hwz_led5_on();
	delay_ms(1000);
	hwz_led5_off();
	delay_ms(1000);
}

void delay_ms(int ms) {
	int i, j;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 1000; j++);
}
