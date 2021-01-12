#include <stdio.h>
#include <math.h>

int int_to_bin(int dec, int* bin[]);

int main() {
	float dec;
	int integer_half;
	int sign;
	int int_bin[32];
	int float_bin[32];
	int binary_number[64];

	printf("Input your number.");
	scanf_s("%f", &dec);
	if (dec < 0)
		sign = -1;
	else
		sign = 1;

	integer_half = dec;
	dec -= integer_half;
	printf("%f", dec);
	//finally

}

int int_to_bin(int dec, int* bin[]) {
	int i = 0;gyi

	if (dec >= 0) { // для положительных чисел
		while (dec > 0) { //конвертация в двоичный вид
			bin[i] = dec % 2;
			dec /= 2;
			i += 1;
		}
	}
	else { // Для отрицательных чисел
		dec += 1;
		while (abs(dec) > 0) { //конвертация в двоичный вид
			bin[i] = dec % 2;
			dec /= 2;
			i += 1;
		}

		int j = i;
		bin[i] = 0; //Добавляет 0 
		for (i; i >= 0; --i) { //инвертирует 0 и 1
			if (bin[i] == 0)
				bin[i] = 1;
			else {
				bin[i] = 0;
			}
		}
	}
	return 0;
}

int float_to_bin(float dec, int* float_bin[]) {
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
	for (i; i < 32; ++i) {
		float_bin[i] = 2;
	}
	return 0;
}