volatile int *LED = (int *)0x00000000;

int main() {
	for (int i = 0; i < 8; i++) {
		*LED = i;
	}
	while (1);
	return 0;
}
