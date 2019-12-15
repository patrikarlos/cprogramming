#include <sys/random.h>

int getrandom_int(void)
{
    int rand;

    getrandom(&rand, sizeof(int), GRND_RANDOM);

    if (rand < 0) {
	return (rand * -1);
    } else {
	return (rand);
    }
}
