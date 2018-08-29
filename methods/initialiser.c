/*
** initialiser.c for init in /home/Neferett/CPE_2016_BSQ
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Wed Dec  7 20:50:36 2016 root
** Last update Sun Dec 18 11:10:04 2016 Bonaldi Jordan
*/

# include "project.h"

t_bsq	*bsq_initialiser(char *file)
{
  int	j;
  t_bsq	*b;

  if (!(b = malloc(sizeof(*b))))
    exit(84);
  if (!(b->x = 0) && !(b->y = 0) &&
      !(b->size = 0) && (b->ok = true) && !(b->rl = 0)) {}
  b->file = file;
  lines_handler(b);
  if (!(b->origin = malloc((b->lines * b->nblines) + 1)) ||
      (j = read(b->fd, b->origin, b->lines * b->nblines)) < 0)
    exit(84);
  b->origin[j] = 0;
  if (!(b->tmp = malloc(b->lines + 2))
      || !(b->tab1 = malloc(sizeof(int *) * (b->lines + 1)))
      || !(b->tab2 = malloc(sizeof(int *) * (b->lines + 1))))
    exit(84);
  j = -1;
  while (++j < b->lines && !(b->tab1[j] = false));
  j = -1;
  while (++j < b->lines && (b->tab2[j] = false));
  return (b);
}
