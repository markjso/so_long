void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != '\0')
	if (map->w[0][i] != '1' || [map->h - 1][i] != '1')
	{
		{
			ft_putstr("map is not surrounded by walls\n");
			free(line);
			exit (1);
		}
		i++;
	}
}
