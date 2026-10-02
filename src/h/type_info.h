#include <stddef.h>
#include <string.h>
typedef struct {
	const char* name;
	size_t size;
	size_t align;
} type_info;
#define typeid(T)      \
	((type_info){        \
		.name = #T,        \
		.size = sizeof(T), \
		.align = alignof(T)})
bool type_equal(const type_info* const lhs, const type_info* const rhs) {
	return strcmp(lhs->name, rhs->name) == 0 &&
				 lhs->size == rhs->size &&
				 lhs->align == rhs->align;
}