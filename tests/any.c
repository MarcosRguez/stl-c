#include "../src/h/any.h"
#include <stdio.h>
#include <stdlib.h>
int main(const int argc, const char* const* const argv) {
	auto b = any_ctor(int);
	// any_emplace(&a, 3);
	make_any(int, 3, a);
	printf("tipo: %s\n", any_type(&a));
	printf("valor: %i\n", any_cast(int, a));
	any_dtor(&a);
	return EXIT_SUCCESS;
}