#include "../src/h/array.h"
#include <stddef.h>
#include <stdlib.h>
int main(const int argc, const char* const* const argv) {
	array(int, 5) v = {.elementos = {1, 2, 3, 4, 5}};
	at(&v, 2) = 10;
	front(&v) = 20;
	back(&v) = 20;
	auto elems = data(&v);
	empty(&v) ? 1 : 0;
	size(&v);
	max_size(&v);
	return EXIT_SUCCESS;
}