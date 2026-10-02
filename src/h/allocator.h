#define allocator(T)                          \
	struct allocator_##T {                      \
		T* (*allocate)(size_t n);                 \
		void (*deallocate)(T * p, std::size_t n); \
	}
#define allocator_ctor(T) \
	{                       \
		.allocate = malloc,   \
		.deallocate = free,   \
	}