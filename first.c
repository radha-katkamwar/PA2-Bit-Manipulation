#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get(unsigned short manipulateNum, int changeBitTo);
unsigned short set(unsigned short manipulateNum, int bit, int change);
unsigned short complement(unsigned short manipulateNum, int bit);
int main (int argc, char** argv) {
        FILE *fp; //create file pointer
        fp = fopen(argv[1], "r");//open file and read
        if (fp == NULL) { //if the file is null return -1
                return -1;
	}
	unsigned short manipulateNum;
	int int1, int2;
	int updateX;
	char arr [20];
	//int num = set(5,1,1);
	//printf("set num is : %d", num);
	//int number = complement(5,0);
	fscanf(fp, "%ho", &manipulateNum);
	while (fscanf(fp, "%s %d %d ", arr, &int1, &int2)!=EOF) {
		if (strcmp(arr,	"get")==0) {
			updateX=get(manipulateNum, int1);
			printf("%d\n", updateX);
		}
		if (strcmp(arr, "comp")==0) {
			manipulateNum=complement(manipulateNum, int1);
			printf("%ho\n", manipulateNum);
		}
		if (strcmp(arr, "set")==0) {
			manipulateNum=set(manipulateNum, int1, int2);
			printf("%ho\n", manipulateNum);
			}	
	}
	return 0;
}
int get(unsigned short manipulateNum, int bit) {
	int y;
	y = (manipulateNum >> bit)&1;
	return y;
}
unsigned short set(unsigned short manipulateNum, int bit, int changeBitTo) {
int nthBit = get (manipulateNum, bit);
unsigned short temp;
temp = manipulateNum;
if (nthBit == changeBitTo) {
	return temp;
	
}
if (nthBit != changeBitTo && nthBit == 0) {
	temp |= (1 << bit); //change to 1
}
if (nthBit != changeBitTo && nthBit == 1) {
	temp &= ~ (1 << bit);//change to 0
	
}

return temp;
}

unsigned short complement(unsigned short manipulateNum, int bit){ 
int nthBit = get(manipulateNum, bit);
unsigned short temp = manipulateNum;

if (nthBit == 0) {
	temp |= (1 <<bit);
}

if (nthBit == 1) {
	temp &= ~ (1 << bit);
}
return temp;
}

