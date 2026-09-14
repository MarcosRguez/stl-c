#include "vector.h"
#define stack(T, C)  \
	struct stack_##T { \
		C##_##T c;       \
	}
#define stack_top(this)					vector_back(&((this)->c))
#define stack_empty(this)				vector_empty(&((this)->c))
#define stack_size(this)				vector_size(&((this)->c))
#define stack_push(this, value) vector_push_back(&((this)->c), value)
#define stack_pop(this)					vector_pop_back(&((this)->c))