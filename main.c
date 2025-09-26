#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float n1 = -1000;
float str = 0.001;

float calc(float input) {
	return input*n1;
}

void learn(float inp, float out) {

  n1 += str;
	int v2 = calc(inp);
  n1 -= str*2;
	int v3 = calc(inp);
  n1 += str;

  // is v2 closer to out or v3?
  float check2 = fabsf(v2-out);
  float check3 = fabsf(v3-out);

  // this means check2 is closer
	if ( check2 < check3 ) {
		n1 += str;
	} else {
		n1 -= str;
	}
}

int main(int argc, char** argv) {

  srand(time(NULL));

  int l = 5000000;
  int rand_numb = rand()%100 + 1;
  int factor = 2;

  n1 = rand()%200 + 1;
  n1 -= 100;

  if (argc == 2) {
    factor = atoi(argv[1]);
  } else if (argc == 3) {
    factor = atoi(argv[1]);
    l = atoi(argv[2]);
  } else {
    printf("HINT: The first argument can be used to supply a custom factor to multiply and learn, and the second argument is how many times to apply learning!\n\n");
  }

  printf("Before %d learns, result of calc(%d) is %f\n", l, rand_numb, calc(rand_numb));

	for (int i = 1; i < l; i++) {
		int inp = i;
		int out = i*factor;

		learn(inp, out);
	}

	printf("After %d learns, result of calc(%d) is %f\n", l, rand_numb, calc(rand_numb));
  printf("\nProper result: %d\nDifference: %f\n", rand_numb*factor, ((float)(rand_numb*factor))-(calc(rand_numb)));

	return 0;
}
