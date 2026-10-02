#include "../src/h/variant.h"
#include <stdio.h>
#include <stdlib.h>
int main(const int argc, const char* const* const argv) {
	variant(int _int; float _float;) a;
	variant_emplace(&a, 3);
	const auto b = get(int, a);
	printf("%i", b);
	return EXIT_SUCCESS;
}