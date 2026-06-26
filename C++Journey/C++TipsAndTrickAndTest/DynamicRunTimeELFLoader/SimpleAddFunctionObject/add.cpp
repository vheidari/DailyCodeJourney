// Add function is a standalone function that we will go to load it speratly as ELF file in 
// In the memory then call it from a main functions.

int add(int a, int b) {
	if(a == 0) return b;
	if(b == 0) return a;
	return a + b;
}