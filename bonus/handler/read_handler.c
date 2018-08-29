/*
** read_handler.c for read_handler in /home/Neferett/CPE_2016_BSQ
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Dec  7 16:50:14 2016 Bonaldi Jordan
** Last update Thu Dec 15 13:36:48 2016 root
*/

# include "project.h"

void	lines_handler(t_bsq *b)
{
  int	i;
  char	tmp;
  char	buf[13];

  i = -1;
  refresh_file(b);
  if (read(b->fd, buf, 12) < 0)
    exit(84);
  buf[12] = 0;
  b->nblines = my_getnbr(buf);
  refresh_file(b);
  while (read(b->fd, &tmp, 1) && tmp != '\n');
  while (read(b->fd, &tmp, 1) && tmp != '\n'
	 && (!(++i) ? 1 : 1));
  b->lines = ++i;
}

void	tab1_to_bit(t_bsq *b)
{
  int	j;
  int	i;

  i = -1;
  *b->tmp = 0;
  refresh_file(b);
  while (read(b->fd, &b->tmp[++i], 1) && b->tmp[i] != '\n');
  *b->tmp = 0;
  i = -1;
  j = b->size;
  while (read(b->fd, &b->tmp[++i], 1) && b->tmp[i] != '\n')
    if (b->tmp[i] == '.' && (b->tab1[i] = true) && j <= 0
	&& !(j = false) && (b->size = true) && (b->x = i + 1)
	&& (b->y = true)) {}
    else if (b->tmp[i] != 'o' &&
	     my_printf("Forbidden character =>%c<=\n", b->tmp[i]))
      exit(84);
}

void      tab2_to_bit(t_bsq *b)
{
  int	j;
  int	i;

  if (!(i = 0) && !(*b->tab2 = false) && (b->ok ? (b->rl = 2)
					  && (b->ok = false) : b->rl++)) {}
  if (*b->tmp == '.' && (*b->tab2 = true)) {}
  else if (*b->tmp != 'o' && *b->tmp != '\n'
	   && my_printf("Forbidden character =>%c<=\n", *b->tmp))
    exit(84);
  if (b->size <= 0 && *b->tab2 &&
      ((!(b->size = *b->tab2) ? 1 : 1) && (b->x = true)
       && (!(b->y = b->rl) ? 1 : 1))) {}
  j = b->size;
  while (b->tmp[++i] != '\n' && !(b->tab2[i] = 0))
    if (b->tmp[i] == '.' &&
	(!(b->tab2[i] = va_min(3, b->tab2[i - 1],
			       b->tab1[i - 1], b->tab1[i])) ? 1 : 1))
      {
	if (b->tab2[i] > (signed)j && (!(j = b->tab2[i]) ? 1 : 1)
	    && (!(b->size = j) ? 1 : 1) &&
	    (!(b->x = i + 1) ? 1 : 1) && (!(b->y = b->rl) ? 1 : 1)) {}
      }
    else if (b->tmp[i] != 'o' &&
	     my_printf("Forbidden character =>%c<=\n", b->tmp[i]))
      exit(84);
}
