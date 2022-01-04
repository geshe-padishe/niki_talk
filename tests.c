# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

int main()
{
	printf("%d\n", 000000001);
	printf("%d\n", 97 | 000000001 << 3);
	printf("%d\n", 97 & 000000001 << 2);
}
