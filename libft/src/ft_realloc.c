#include <libft.h>
#include <stdlib.h>

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void *const	ptr = malloc(new_size);

	if (ptr)
	{
		ft_memcpy(ptr, old, old_size);
		free(old);
	}
	return (ptr);
}
