#include "../include/malloc.h"

t_group	find_block_group_from_size(size_t size)
{
	if (size < TINY_BLOCK_SIZE)
		return TINY;
	if (size >= TINY_BLOCK_SIZE && size < SMALL_BLOCK_SIZE)
		return SMALL;
	return LARGE;
}