#include <stdio.h>

// static int	is_digit(int c)
// {
// 	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
// 		return 1;
// 	else
// 		return 0;
// }

// int	main(int argc, char **argv)
// {
// 	int	i = 0;

// 	if (argc <= 2)
// 		return 0;
// 	if (argc > 2)
// 	{
// 		i++;
// 		while (i < argc)
// 		{
// 			printf("%s\n", argv[i]);
// 			i++;
// 		}
// 		i = 0;
// 		while (!is_digit(argv[i]))
// 		{}
// 	}
// 	return 0;
// }

#include <stdio.h>
#include <string.h>

int has_duplicates(int argc, char *argv[])
{
	int	i = 0;
	while (i < argc)
	{
		int j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char	**stock;
	if (argc == 2)
			stock = ft_split(argv(1));
	if (ft_limits() == 0)
		return (0);
	if (ft_has_duplicates(argc, argv))
		return (0);
	if (ft_is_char() == 0)
	if (argc == 2)
		ft_push_swap()
	else if (argc > 2)
		ft_push_swap()
	return 0;
}
