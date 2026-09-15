#include "../src/h/optional.h"
#include <stdio.h>
#include <stdlib.h>
int f(int a) {
	return a + 1;
}
int main(const int argc, const char* const* const argv) {
	optional(int) a = optional_ctor;
	// auto b = nullopt;
	auto c = make_optional(float, 1.5);
	int value = optional_value(&a);
	optional_transform(&a, f);
	printf("valor: %i\n", value);
	return EXIT_SUCCESS;
}