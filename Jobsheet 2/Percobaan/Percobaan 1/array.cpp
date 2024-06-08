#include <stdio.h>

int main() {
	int rr;
	int nil[3];
	
	nil[0] = 80;
	nil[2] = 90;
	
	rr = (nil[0] + nil[1] + nil[2]) / 3;
	printf("The avarage of the 3 grades is: %d, %d");
	
	return 0;
}
