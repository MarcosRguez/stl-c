#include <stddef.h>
#define array(T, N) \
	struct {          \
		T elementos[N]; \
	}
#define array_empty(this)		 (sizeof(this)->elementos == 0)
#define array_size(this)		 (sizeof(this)->elementos)
#define array_max_size(this) (sizeof(this)->elementos)
#define array_at(this, pos)	 (pos >= array_size(this) ? throw() : (this)->elementos[pos])
#if __cpp_lib_hardened_array >= 202502L
	#define array_front(this) (array_empty(this) ? throw() : (this)->elementos[0])
#else
	#define array_front(this) ((this)->elementos[0])
#endif
#if __cpp_lib_hardened_array >= 202502L
	#define array_back(this) (array_empty(this) ? throw() : (this)->elementos[array_size(this) - 1])
#else
	#define array_back(this) ((this)->elementos[array_size(this) - 1])
#endif
#define array_data(this) ((this)->elementos)
#define array_operator_subscript
#define array_swap(this, rhs) \
	for (auto i = 0u; i < array_size(this); i++) swap(array_at(this, i), array_at(rhs, i));
// #define array_begin(this)			(&array_front(this))
// #define array_cbegin(this)		((typeof(array_front(this))* const)&array_front(this))
#define array_fill(this, value) \
	for (auto i = 0u; i < array_size(this); i++) array_at(this, i) = value;