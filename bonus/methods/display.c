/*
** display.c for display in /home/Neferett/CPE_2016_BSQ
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Dec  8 01:37:06 2016 root
** Last update Sun Dec 18 17:14:02 2016 Bonaldi Jordan
*/

# include "project.h"

int		spec_display(t_bsq *b)
{
  Boolean	ok;
  char		*tmp;
  int		i;

  if (!(ok = false) && (i = -1) && refresh_file(b)) {}
  while (read(b->fd, b->tmp, 1) && *b->tmp != '\n');
  if (!(tmp = malloc(b->lines)))
    return (84);
  if (read(b->fd, tmp, b->lines) < 0)
    return (84);
  if (*tmp == '.' && b->nblines == 1 && b->lines == 1 &&
      my_printf("%sx%s\n", C_G, RESET))
    return (0);
  while (++i < my_strlen(tmp))
    {
      if (tmp[i] == '.' && !ok && (ok = true))
	my_printf("%sx%s", C_G, RESET);
      else if (!(tmp[i] == '.' || tmp[i] == 'o')
	       && my_printf("Invalid character >%c<\n", tmp[i]))
	return (84);
      else
	my_printf("%c", tmp[i]);
    }
  my_printf("\n");
  return (0);
}

void	displayer(t_bsq *b, int i, char *tmp, int j)
{
  while (i <= b->nblines)
    {
      if (read(b->fd, tmp, b->lines) < 0)
	exit(84);
      if ((!(++i) ? 1 : 1) &&
	  ((i - 1) <= b->y - b->size || (i - 1) > b->y))
	write(1, tmp, b->lines);
      else
	{
	  if ((j = 1) && write(1, tmp, b->x - b->size)) {}
	  while (j++ <= b->size)
	    if (b->nblines == 1 && b->lines == 1 &&
		my_printf("%sx%s\n", C_G, RESET)) {}
	    else if (my_printf("%sx%s", C_G, RESET)) {}
	  if ((!(j = b->x) ? 1 : 1) && write(1, &tmp[j], b->lines - b->x)) {}
	}
    }
}

void	display_bsq(t_bsq *b)
{
  char	*tmp;
  int	j;
  int	i;

  j = 0;
  if (refresh_file(b) && (i = 1)) {}
  while (read(b->fd, b->tmp, 1) && *b->tmp != '\n');
  if (!(tmp = malloc(++b->lines)) || (tmp[b->lines - 1] = 0))
    exit(84);
  if (b->nblines == 1 && b->lines == 1 &&
      read(b->fd, tmp, 1) && *tmp == 'o' && my_printf("o\n"))
    return;
  displayer(b, i, tmp, j);
}
