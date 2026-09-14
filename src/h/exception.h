#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "../h/stack.h"
typedef struct {
	const char* what;
} exception;
typedef struct {
	jmp_buf* b;
	exception e;
} contexto;
typedef vector(contexto) vector_contexto;
stack(contexto, vector) contextos;
#if __has_c_attribute(noreturn)
[[noreturn]]
#endif
void throw(const exception e) {
	if (!stack_empty(&contextos)) {
		stack_top(&contextos).e = e;
		longjmp(*stack_top(&contextos).b, 2);
	} else {
		fprintf(stderr, "exception: %s\n", e.what);
		abort();
	}
}
#define try                                           \
	jmp_buf _bufo;                                      \
	{                                                   \
		contexto cosa = {.b = &_bufo};                    \
		stack_push(&contextos, cosa);                     \
	}                                                   \
	auto _cach = false;                                 \
	const auto _jmp = setjmp(*stack_top(&contextos).b); \
	if (_jmp == 0)
#define catch(var)                      \
	else if (_jmp == 1) { _cach = true; } \
	var = &stack_top(&contextos).e;       \
	stack_pop(&contextos);                \
	if (_cach)
#define finally \
	else