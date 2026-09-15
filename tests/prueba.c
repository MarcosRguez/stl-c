#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
jmp_buf j;
bool hay = false;
typedef enum { nada,
	trying,
	catching,
	finalling } estado;
estado jmp_estado = nada;
bool try
	(int set) {
		hay = true;
		if (jmp_estado == nada && set == 0) {
			jmp_estado = trying;
			return true;
		} else {
			jmp_estado = trying;
			return false;
		}
	}
bool catch (int set) {
	hay = false;
	if (set != 0 && jmp_estado != catching) {
		jmp_estado = catching;
		return true;
	} else {
		jmp_estado = catching;
		return false;
	}
}
void throw() {
	if (hay) {
		longjmp(j, 0);
	} else {
		abort();
	}
}
void f() {
	throw();
}
int main() {
	const auto set = setjmp(j);
	if (try (set)) {
		fprintf(stdout, "try\n");
		f();
	} else if (catch (set)) {
		fprintf(stdout, "catch\n");
		// f();
	} else {
		fprintf(stdout, "finally\n");
	}
}