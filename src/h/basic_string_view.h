#define basic_string_view(C) \
	typedef struct {           \
		C* _data;                \
		size_t _size;            \
	}
#define basic_string_view_ctor1(C) ((basic_string_view(C)){._data = nullptr, ._size = 0u})
#define basic_string_view_ctor2(C, other)
#define basic_string_view_ctor3(C, s, count) ((basic_string_view(C)){._data = s, ._size = count})
#define basic_string_view_ctor4(C, s)
#define basic_string_view_ctor5(C, first, last)
#define basic_string_view_ctor6(C, r)
// #define basic_string_view_ctor7
#define basic_string_view_at(this, pos)
#define basic_string_view_front(this)
#define basic_string_view_back(this)
#define basic_string_view_data(this)	 ((this)->_data)
#define basic_string_view_size(this)	 ((this)->_size)
#define basic_string_view_length(this) basic_string_view_size(this)
#define basic_string_view_max_size(this)
#define basic_string_view_empty(this) (basic_string_view_size(this) == 0u)
#define basic_string_view_remove_prefix(this, n)
#define basic_string_view_remove_suffix(this, n)
#define basic_string_view_swap(this, rhs)
#define basic_string_view_copy(this, dest, count, pos)
#define basic_string_view_substr(this, pos, count)
#define basic_string_view_subview(this, pos, count)
#define basic_string_view_compare						// sobrecargas
#define basic_string_view_starts_with				// sobrecargas
#define basic_string_view_ends_with					// sobrecargas
#define basic_string_view_contains					// sobrecargas
#define basic_string_view_find							// sobrecargas
#define basic_string_view_rfind							// sobrecargas
#define basic_string_view_find_first_of			// sobrecargas
#define basic_string_view_find_last_of			// sobrecargas
#define basic_string_view_find_first_not_of // sobrecargas
#define basic_string_view_find_last_not_of	// sobrecargas