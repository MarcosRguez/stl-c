#include "../src/h/vector.h"
int main(const int argc, const char* const* const argv) {
	vector(int) a;
	a.capacidad = 0;
	a.tamaño = 0;
	a.dato = nullptr;
	// vector_empty(&a);
	vector_push_back(&a, 1);
	vector_push_back(&a, 2);
	vector_push_back(&a, 3);
	for (int i = 0; i < vector_size(&a); i++) {
		printf("%i", vector_at(&a, i));
	}
	// vector_at(&a, 0);
	vector(double) b = vector_init;
	typedef vector(double) vector_double;
	vector(vector_double) d = vector_init;
	vector_push_back(&d, b);
	return 0;
}