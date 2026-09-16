#include "../src/h/hash.h"
#include <stdlib.h>

#define hash_int(value) (size_t)value

int main(const int argc, const char* const* const argv) {
	hash(int)(5);
	return EXIT_SUCCESS;
}