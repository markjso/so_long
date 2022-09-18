int key_hook(t_map *map, int keypress)
{
  int x;
  int y;
  
  x = playerx;
  y = playery;
  if (keypress == 0 || 123)
    x--;
  if (keypress == 1 || 122)
    x++;
  etc
    
  }
}

static void move(t_map *map, int keypress, int col, int row)
{
  int valid;
  int tcol;
  int trow;
  
  tcol = map->playery;
  trow = map->playerx;
  valid = valed_move(map, col, row, keypress);
  if (valed != -1)
  {
    map->map[trow][tcol] = '0';
    map>playery = col;
    map->playerx = row;
    map->map[row][col] = 'P';
    ft_putstr("Steps: ");
    ft_putnubr(map->steps++);
    ft_putstr("\n");
  }
