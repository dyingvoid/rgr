
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int int_to_bin(int dec, int* bin[]);
int float_to_bin(float dec, int* float_bin[]);
int integral_exponent_size(const int* int_bin, int sign);
int decimal_exp_size(const int* float_bin, int sign);
void flush();

int main() {
	while (1) {
		float dec = 0;
		int integer_half = 0;
		int sign = 0;
		int int_bin[32] = { 0 };
		int float_bin[17] = { 0 };
		int mantissa[23] = { 0 };
		int exp = 0;
		int bin_exp[8] = { 0 };

		if (scanf_s("%f", &dec)) {
			printf("Success, calculating...\n");

			if (dec < 0)
				sign = 1;
			else
				sign = 0;

			integer_half = dec;
			dec -= integer_half;

			int_to_bin(integer_half, int_bin);
			float_to_bin(dec, float_bin);

			if (integer_half != 0)
				exp = integral_exp_size(int_bin, sign);
			else
				exp = decimal_exp_size(float_bin, sign);
			int_to_bin(exp, bin_exp);

			printf("%d ", sign);
			for (int i = 7; i >= 0; --i)
				printf("%d", bin_exp[i]);
			printf(" ");

			int state = 0;
			for (int i = 31; i > 0; --i) {
				if (int_bin[i] == 1)
					state += 1;
				if (state != 0) {
					printf("%d", int_bin[i - 1]);
				}
			}

			for (int i = 0; i < 17; ++i) {
				printf("%d", float_bin[i]);
			}
			printf("\n");
		}
		else {
			printf("Input must contain only a number.\n");
			flush();
		}
	}
	return 0;
}
/*Подсчет экспоненты при целой части равной 0*/
int decimal_exp_size(const int* float_bin, int sign) {
	int exp = 127;
	int state = 0;
	int sub_num = 1;
	for (int i = 0; i < 17; ++i) {
		if (float_bin[i] == 1)
			state += 1;
		if (state == 0)
			sub_num += 1;
	}
	if (sign == 0) // знак вводимого числа
		exp += sub_num;
	else
		exp -= sub_num;
	return exp;
}
/*Подсчет экспоненты при наличии целой части*/
int integral_exp_size(const int* int_bin, int sign) {
	int exp = 127;
	int state = 0;
	int sub_num = 0;
	for (int i = 31; i > 0; --i) {
		if (int_bin[i] == 1)
			state = 1;
		if (state != 0) {
			sub_num += 1;
		}
	}
	if (sign == 0) // знак вводимого числа
		exp += sub_num;
	else
		exp -= sub_num;
	return exp;
}
/*Очистка потока ввода при неправильных данных*/
void flush() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}
/*Конвертирует в двоичный вид целую часть числа*/
int int_to_bin(int dec, int* bin) {
	int i = 0;
	dec = abs(dec);
	while (dec > 0) {
		bin[i] = dec % 2;
		dec /= 2;
		i += 1;
	}
	return 0;
}
/*Конвертирует в двочиный вид часть числа после запятой*/
int float_to_bin(float dec, int* float_bin) {
	int change;
	dec = fabs(dec);
	int i = 0;
	while (dec != 0) {
		dec *= 2;
		change = dec;
		float_bin[i] = change;
		dec -= change;
		++i;
	}
	return 0;
}
