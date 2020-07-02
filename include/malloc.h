#include <unistd.h>

//Heap and block size def
#define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)

typedef enum 		e_heap_group{
					TINY,
					SMALL,
					LARGE
}					t_heap_group;

//Structures definition
typedef struct 		s_heap{
	struct s_heap 	*prev;
	struct s_heap 	*next;
	t_heap_group	group;
	size_t			total_size;
	size_t			free_size;
	size_t			block_count;	
} 					t_heap;		

typedef struct 		s_block{
	struct s_block 	*prev;
	struct s_block 	*next;
	size_t			data_size;
	bool			freed;
}					t_block;

//Global variables definitions
t_heap 				*g_heap_pin;

//Library method
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

//Intern methods
void	try_fill_existing_block(size_t size, t_block *ret_block, t_heap *ret_heap);