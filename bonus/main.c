/*
** main.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sun Dec 18 15:20:31 2016 Bonaldi Jordan
*/

#include "project.h"

int	bsq(char *str)
{
  t_bsq	*b;
  int	j;

  j = -1;
  b = bsq_initialiser(str);
  if (b->nblines == 1)
    return (spec_display(b));
  tab1_to_bit(b);
  j = -1;
  while (++j < b->nblines - 1)
    {
      read(b->fd, b->tmp, b->lines + 1);
      tab2_to_bit(b);
      my_swap(&b->tab1, &b->tab2);
    }
  display_bsq(b);
  return (1);
}

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  if (*argv[1] == '-' && argv[1][1] == 'n')
    client(my_getnbr(argv[2]), NULL, 0, 3);
  else
    while (++i < argc)
      if (my_printf("=> %s:\n", argv[i]))
	bsq(argv[i]);
  return (0);
}
