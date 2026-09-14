#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// no anidar
#define vector(T)     \
	struct vector_##T { \
		size_t tamaño;    \
		size_t capacidad; \
		T* dato;          \
	}
#define vector_init \
	{                 \
		.tamaño = 0,    \
		.capacidad = 0, \
		.dato = nullptr}
#define vector_at(this, index) ((this)->dato[index])
#define vector_capacity(this)	 ((this)->capacidad)
#define vector_size(this)			 ((this)->tamaño)
#define vector_pop_back(this)	 ((this)->tamaño--)
#define vector_empty(this)		 (vector_size(this) == 0)
#define vector_max_size(this)	 SIZE_MAX
#define vector_data(this)			 ((this)->dato)
#define vector_front(this)		 (vector_data(this)[0])
#define vector_back(this)			 (vector_data(this)[vector_size(this) - 1])
#define vector_clear(this)		 ((this)->tamaño = 0)
#define vector_reserve(this, new_cap)                                                                               \
	{                                                                                                                 \
		if ((new_cap) > vector_max_size(this)) {                                                                        \
			abort();                                                                                                      \
		}                                                                                                               \
		if ((new_cap) > vector_capacity(this)) {                                                                        \
			auto new_data = (typeof(vector_data(this)))aligned_alloc(alignof(typeof_unqual(vector_data(this))), new_cap); \
			for (auto i = 0u; i < vector_size(this); i++) {                                                                \
				new_data[i] = vector_data(this)[i];                                                                         \
			}                                                                                                             \
			free(vector_data(this));                                                                                      \
			(this)->dato = new_data;                                                                                      \
			(this)->capacidad = new_cap;                                                                                  \
		}                                                                                                               \
	}
// #define vector_resize(this, sz)
// {
// 	vector_size(this) = sz;
// 	if(sz > vector_si)
// }
#define vector_push_back(this, value)                                                   \
	{                                                                                     \
		if (vector_capacity(this) == vector_size(this)) {                                   \
			vector_reserve(this, vector_capacity(this) == 0 ? 1 : vector_capacity(this) * 2); \
		}                                                                                   \
		vector_data(this)[vector_size(this)] = value;                                       \
		(this)->tamaño++;                                                                   \
	}
