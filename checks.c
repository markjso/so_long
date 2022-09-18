void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != '\0')
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[0][j] != '1' || [map->w - 1][j] != '1')
				ft_putstr("map is not surrounded by walls\n");
			if (map->map[j][0] != '-1' || map->map[i][map->h - 1] != '1')
				ft_putstr("map is not surrounded by walls\n");
			j++
			}
		i++;
	}
}
