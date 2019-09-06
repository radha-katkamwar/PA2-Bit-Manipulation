#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getnumBits (unsigned short val);
int getPairCount (unsigned short val, int numBits);
int getNumOneBits(unsigned short val);
int main (int argc, char** argv) {
unsigned short value;
value = atoi(argv[1]);
int numBits;
numBits = getnumBits(value);
int numPairs = 0;
numPairs = getPairCount (value, numBits);
int setOne = getNumOneBits (value);
if (setOne%2==0) {
	printf("Even-Parity\t%d\n", numPairs);
}
else {
	printf("Odd-Parity\t%d\n", numPairs);
}

return 0;
}

int getnumBits (unsigned short num) {
int par =0;
int count = 0;
while (num) {
	count++;
	num >>=1;
}
if (count ==1) {
printf("Odd-Parity\t%d\n", par);
exit(0);
}
//printf("num bits is %d\n", count);
return count;

}
int getPairCount (unsigned short val, int numberofBits) {
int i = 0;
int first;
int second;
int pairs = 0;

while (i < numberofBits) {
	first = (val >> i)&1;
	second = (val >> (i + 1)) & 1;
	//printf ("%d: %d %d\n",i,first, second);
	//printf("The second value i %d at %d\n", second, i+1);
	if (first ==1 && second == first) {
		pairs = pairs +1;
		i +=2;
	} else {
		i++;
	}		
}
return pairs;
}

int getNumOneBits(unsigned short val) {

unsigned int count = 0;

while (val) {
	count += val & 1;
	val >>=1;
}
return count;

}
