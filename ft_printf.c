#include <stdio.h>
#include <stdlib.h>

#define VECTOR(TYPE) struct { TYPE* items; size_t used; size_t capacity; }

typedef VECTOR(int) t_int_vector;
typedef VECTOR(void) t_vector;

// typedef struct vector {
// 	size_t	used;
// 	size_t	capacity;
// 	void	*items;
// }			t_vector;

// t_vector *ft_init_vector(size_t array_size, size_t capacity)
// {
// 	t_vector *new_vector;
//
// 	new_vector = malloc(sizeof(t_vector));
// 	if (!new_vector)
// 		return (NULL);
// 	new_vector->capacity = capacity;
// 	new_vector->used = 0;
// 	new_vector->items = malloc(array_size);
// 	if (!new_vector->items)
// 		return (NULL);
// 	return (new_vector);
// }

t_int_vector ft_init_vec(t_int_vector vec, size_t capacity)
{
	vec.items = malloc(sizeof(*vec.items) * capacity);
	vec.capacity = capacity;
	vec.used = 0;
	return (vec);
}

void *ft_init_vec2(void *vec, size_t capacity)
{
	vec->items = malloc(sizeof(*(vec->items)) * capacity);
	vec->capacity = capacity;
	vec->used = 0;
	return (vec);
}

void ft_zgeg(void **zgeg)
{
	((int *)(*zgeg))[0] = 42;
}

int main() {
	t_int_vector my_vec;
	int *zgeg;
	zgeg = malloc(sizeof(int) * 5);
	ft_zgeg(&zgeg);

	ft_init_vec2(&my_vec, 5);
    return 0;
}