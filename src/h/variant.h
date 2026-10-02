#include "exception.h"
#include "type_info.h"
#define variant(...) \
	struct {           \
		type_info tag;   \
		union {          \
			__VA_ARGS__    \
		} variante;      \
	}
#define variant_npos				-1
#define variant_index(this) ((this)->tag) // ¿hash?
#define variant_emplace(this, a)   \
	(this)->tag = typeid(typeof(a)); \
	(this)->variante.¿? = a
#define get(T, v) (type_equal(&typeid(T), &v.tag) ? v.variante._##T : throw_r(v.variante._##T))
#define get_if(T, v)
#define holds_alternative(T, v) type_equal(&typeid(T), &v.tag)
#define variant_valueless_by_exception(this) ((this)->tag.size == 0)