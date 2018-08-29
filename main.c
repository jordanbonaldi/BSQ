/*
** main.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sun Dec 18 11:23:21 2016 Bonaldi Jordan
*/

#include "project.h"

int	main(int argc, char **argv)
{
  t_bsq	*b;
  int	j;

  j = -1;
  if (argc != 2)
    return (84);
  b = bsq_initialiser(argv[1]);
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
  return (0);
}
