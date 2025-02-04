#include "get_next_line.h"

int	main()
{
	int count = 10;
	int		fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Fallo al leer");
		return (1);
	}
	printf("Ya ha leído el archivo\n");
	char	*str = get_next_line(fd);
	while (str)
	{
		printf("> %s\n", str);
		free(str);
	    str = get_next_line(fd);
		--count;
	}
	free(str);
	close(fd);
	return (0);
}