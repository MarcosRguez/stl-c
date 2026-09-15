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
} contexto;
typedef vector(contexto) vector_contexto;
stack(contexto, vector) contextos;
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
void throw(const exception e) {
	if (!stack_empty(&contextos)) {
		stack_top(&contextos).e = e;
		stack_top(&contextos).caught = true;
		longjmp(*stack_top(&contextos).b, 0);
	} else {
		fprintf(stderr, "exception: %s\n", e.what);
		terminate();
	}
}
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
bool try
	(int a) {
		bool cond = a == 0 && stack_top(&contextos).estado == NONE;
		if (cond) {
			stack_top(&contextos).estado = TRY;
		}
		return cond;
	}
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
bool catch (int a) {
	bool cond = a == 1 && stack_top(&contextos).estado == TRY && stack_top(&contextos).caught;
	if (cond) {
		stack_top(&contextos).estado = CATCH;
	}
	return cond;
}
#if __has_c_attribute(nodiscard)
[[nodiscard]]
#endif
bool finally(int _) {
	bool cond = stack_top(&contextos).estado != FINALLY;
	if (cond) {
		stack_top(&contextos).estado = FINALLY;
	}
	return cond;
}
#define try                                                    \
	jmp_buf _bufo;                                               \
	{                                                            \
		contexto cosa = {.b = &_bufo};                             \
		stack_push(&contextos, cosa);                              \
	}                                                            \
	for (auto i = setjmp(*stack_top(&contextos).b); i <= 2; i++) \
		if (try (i))
#define catch(var) \
	else if (catch (i))
#define finally \
	else if (finally(i))