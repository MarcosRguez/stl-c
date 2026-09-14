#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "../h/stack.h"
typedef struct {
	jmp_buf* b;
} jmp;
typedef vector(jmp) vector_jmp;
stack(jmp, vector) a;
typedef struct {
	const char* what;
} exception;
exception exce;
void throw(const exception e) {
	if (!stack_empty(&a)) {
		exce = e;
		longjmp(*stack_top(&a).b, 0);
	} else {
		fprintf(stderr, "exception: %s\n", e.what);
		abort();
	}
}
#define try                  \
	{                          \
		jmp_buf bufo;            \
		jmp cosa = {.b = &bufo}; \
		stack_push(&a, cosa);    \
	}                          \
	auto _cach = false;        \
	if (setjmp(*stack_top(&a).b) == 0)
#define catch(var)       \
	else { _cach = true; } \
	var = &exce;           \
	stack_pop(&a);         \
	if (_cach)
#define finally