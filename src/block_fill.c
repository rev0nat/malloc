#include "../include/malloc.h"

void	try_fill_existing_block(size_t size, t_block *ret_block, t_heap *ret_heap)
{
	t_block 		*block;
	t_heap			*heap;
	t_heap_group	group;

	heap = g_heap_pin;
	group = find_block_group_from_size(size);
	while (heap)
	{
		block = (t_block*)HEAP_SHIFT(heap);
		while (block && heap->group == group)
		{
			if (block->free && (block->data_size >= size + sizeof(t_block)))
			{
				ret_block = block;
				ret_heap = heap;
				return ;
			}
			block = block->next;
		}
		heap = heap->next;
	}
}