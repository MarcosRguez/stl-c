#include "../src/h/type_info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main(const int argc, const char* const* const argv) {
	const auto a = typeid(int);
	// const auto b = typeid(3);
	// assert(typeid(int) == typeid(int));
	// assert(typeid(int) != typeid(float));
	return EXIT_SUCCESS;
}