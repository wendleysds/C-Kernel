#include <lib/utils.h>

void itoa(int value, char* result, int base){
	char* digits = "0123456789ABCDEF";
	char buffer[32];
	int i = 0, j = 0; 

	if (value < 0 && base == 10){
		result[j++] = '-';
		value = -value;
	}

	do {
		buffer[i++] = digits[value % base];
		value /= base;
	} while(value);

	while(i > 0){
		result[j++] = buffer[--i];
	}

	result[j] = '\0';
}

void strupper(char* str){
	for(int i = 0; str[i]; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= 32;
		}
	}
}
