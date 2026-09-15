#include "exception.h"
#include <assert.h>
#define optional(T)         \
	struct {     \
		bool _existe;           \
		typeof_unqual(T) _data; \
	}
// #define optional(T)         \
// 	struct optional_##T {     \
// 		bool _existe;           \
// 		typeof_unqual(T) _data; \
// 	}
#define optional_has_value(this) \
	((this)->_existe)
#define optional_value(this) \
	(optional_has_value(this) ? (this)->_data : throw_r((this)->_data))
#define optional_value_or(this, value) \
	(optional_has_value(this) ? (this)->_data : value)
#define optional_ctor \
	{._existe = false}
#define optional_reset(this) \
	((this)->_existe = false)
#define optional_emplace(this, value) \
	(this)->_existe = true;             \
	(this)->_data = value
#define nullopt \
	(optional(int)) { ._existe = false }
#define optional_transform(this, f)                                          \
	(optional_has_value(this)                                                  \
			? (typeof(*(this))){._existe = true, ._data = f(optional_value(this))} \
			: (typeof(*(this))){._existe = false})
#define make_optional(T, value) \
	((optional(T)){._existe = true, ._data = value})