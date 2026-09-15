#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "../h/stack.h"
typedef struct {
	const char* what;
} exception;
typedef enum {
	NONE,
	TRY,
	CATCH,
	FINALLY
} estado_ctx;
typedef struct {
	jmp_buf* b;
	exception e;
	bool caught;
	estado_ctx estado;
	bool has_finally;
} contexto;
typedef vector(contexto) vector_contexto;
thread_local stack(contexto, vector) contextos;
typedef void (*terminate_handler)();
terminate_handler _terminate_handle = abort;
#if __has_c_attribute(noreturn)
[[noreturn]]
#endif
void terminate() {
	_terminate_handle();
}
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
terminate_handler get_terminate() {
	return _terminate_handle;
}
terminate_handler set_terminate(terminate_handler f) {
	auto anterior = get_terminate();
	_terminate_handle = f;
	return anterior;
}
#if __has_c_attribute(noreturn)
[[noreturn]]
#endif
void throw_exception(const exception e) {
	if (!stack_empty(&contextos)) {
		stack_top(&contextos).e = e;
		stack_top(&contextos).caught = true;
		longjmp(*stack_top(&contextos).b, 0);
	} else {
		fprintf(stderr, "exception: %s\n", e.what);
		terminate();
	}
}
void throw_int(int _) {
	exception e = {.what = "int"};
	throw_exception(e);
}
#define throw(X) _Generic((X), \
	int: throw_int,              \
	exception: throw_exception)(X)
int throw_r_int(const int x) {
	exception e = {.what = "int"};
	throw_exception(e);
	return x;
}
#define throw_r(X) _Generic((X), \
	int: throw_r_int)(X)
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
bool try1(const int a, const bool pop) {
	bool cond = a == 0 && stack_top(&contextos).estado == NONE;
	if (cond) {
		stack_top(&contextos).estado = TRY;
	}
	if (a == 2 && !pop && !stack_top(&contextos).has_finally) {
		stack_pop(&contextos);
	}
	return cond;
}
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
bool catch1(const int a) {
	bool cond = a == 1 && stack_top(&contextos).estado == TRY && stack_top(&contextos).caught;
	if (cond) {
		stack_top(&contextos).estado = CATCH;
	}
	return cond;
}
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
bool finally1(const int a, bool* pop) {
	bool cond = a == 2 && stack_top(&contextos).estado != FINALLY;
	stack_top(&contextos).has_finally = true;
	if (cond) {
		stack_top(&contextos).estado = FINALLY;
		stack_pop(&contextos);
		*pop = true;
	}
	return cond;
}
#define try                                                    \
	jmp_buf _bufo;                                               \
	{                                                            \
		contexto cosa = {                                          \
			.b = &_bufo,                                             \
			.caught = false,                                         \
			.estado = NONE,                                          \
			.has_finally = false};                                   \
		stack_push(&contextos, cosa);                              \
	}                                                            \
	auto _pop = false;                                           \
	for (auto i = setjmp(*stack_top(&contextos).b); i <= 2; i++) \
		if (try1(i, _pop))
#define catch(var) \
	else if (catch1(i))
#define finally \
	else if (finally1(i, &_pop))