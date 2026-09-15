#include <stdlib.h>
typedef struct {
	const char* const _type;
	void* _data;
} any;
#define any_ctor(T) \
	(any){                 \
		._type = #T,    \
		._data = malloc(sizeof(T))}
bool any_has_value(const any* this) {
	return this->_data != nullptr;
}
void any_reset(const any* this) {
	free(this->_data);
}
void any_dtor(const any* this) {
	any_reset(this);
}
const char* const any_type(const any* this) {
	return this->_type;
}
#define any_cast(T, any) \
	(*((T*)((any)._data)))
#define any_emplace(this, value) \
	any_cast(typeof(value), *(this)) = value;
#define make_any(T, value, var) \
	any var = any_ctor(T);        \
	any_emplace(&var, value)