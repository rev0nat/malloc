#include <sys/mman.h>


void	*malloc(size_t size)
{
	//gestion multithread first
	if (!size || size <= 0)
		return (NULL);
	//si freelist alors
		//si fill_freelist(size) réussi alors
			//return ptr;
	if (try_fill_existing_block(size))
		return (newptr);
	//sinon creation nouvelle heap via mmap;
}