#include <stdio.h>
#include <stdlib.h>
unsigned short get(unsigned short value, int bit);
int isPalin(unsigned short value);
int main (int argc, char** argv) {
unsigned short value;
int counter;
value = atoi(argv[1]);
counter = isPalin (value);
if (counter == 8) {
	printf("Is-Palindrome\n");
}
else {
	printf("Not-Palindrome\n");
}
return 0;
}
unsigned short get(unsigned short value, int bit) {
        int y;
        y = (value >> bit)&1;
        return y;
}


int isPalin(unsigned short value) {
	int i = 0;
	int j = 15-i;
	int count = 0;
	for (i = 0; i < 8; i ++) {
		 j = 15-i;
			if ((get(value, i)) == (get(value,j))) {
	 			count ++;
			}
	}
return count;
}
