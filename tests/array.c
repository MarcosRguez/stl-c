#include "../src/h/array.h"
#include <stddef.h>
#include <stdlib.h>
int main(const int argc, const char* const* const argv) {
	array(int, 5) v = {.elementos = {1, 2, 3, 4, 5}};
	array_at(&v, 2) = 10;
	array_front(&v) = 20;
	array_back(&v) = 20;
	auto elems = array_data(&v);
	array_empty(&v) ? 1 : 0;
	array_size(&v);
	array_max_size(&v);
	return EXIT_SUCCESS;
}