void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putstr("map is not surrounded by walls\n");
			free(line);
			exit (1);
		}
		i++;
	}
}
