#include <stddef.h>
#define array(T, N) \
	struct {          \
		T elementos[N]; \
	}
#define at(this, index) ((this)->elementos[index])
#define front(this)			((this)->elementos[0])
#define back(this)			((this)->elementos[sizeof(this)->elementos - 1])
#define data(this)			((this)->elementos)
#define empty(this)			(sizeof(this)->elementos == 0)
#define size(this)			(sizeof(this)->elementos)
#define max_size(this)	(sizeof(this)->elementos)