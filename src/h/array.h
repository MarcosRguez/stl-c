#include <stddef.h>
#define array(T, N) \
	struct {          \
		T elementos[N]; \
	}
#define array_at(this, index) ((this)->elementos[index])
#define array_front(this)			((this)->elementos[0])
// #define array_front(this)			(array_empty(this) ? (this)->elementos[0] : throw_r(typeof((this)->elementos[0])))
#define array_back(this) ((this)->elementos[sizeof(this)->elementos - 1])
#define array_data(this) ((this)->elementos)
// #define array_begin(this)			(&array_front(this))
// #define array_cbegin(this)		((typeof(array_front(this))* const)&array_front(this))
#define array_empty(this)		 (sizeof(this)->elementos == 0)
#define array_size(this)		 (sizeof(this)->elementos)
#define array_max_size(this) (sizeof(this)->elementos)
#define array_fill(this, value) \
	for (auto i = 0u; i < array_size(this); i++) array_at(this, index) = value;