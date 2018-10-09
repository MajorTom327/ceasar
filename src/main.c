#include <unistd.h>
#include <libft.h>
#include <get_next_line.h>

int	main(void)
{
	char	*key;
	char	*value;
	char	*text;
	int		test;
	int		i;
	int		index;
	int		i_key;
	int		*ret;

	ft_putendl("\033[32m__CRYPTO__\033[0m");
	test = 1;
	i = 0;
	while (test)
	{
		if (i)
			ft_putendl("\033[31mIncorrect Value !\033[0m");
		ft_putstr("alphabet number:");
		get_next_line(0, &value);
		i_key = ft_atoi(value);
		ft_strdel(&value);
		if (i_key > 26)
			test = !test;
		i = 1;
	}
	ft_putstr("keyword:");
	get_next_line(0, &key);
	ft_putstr("Message to encode:");
	get_next_line(0, &text);
	ret = (int *)ft_memalloc(sizeof(int) * ft_strlen(text));
	index = 0;
	i = 0;
	while (text[index])
	{
		if (!key[i])
			i = 0;
		ret[index] = (key[i] - 'A' + i_key) - (text[index] - 'A');
		if (text[index] != ' ')
			i++;
		index++;
	}
	index = 0;
	while (text[index])
	{
		ft_putnbr(ret[index]);
		ft_putchar(' ');
		index++;
	}
	return (0);
}
