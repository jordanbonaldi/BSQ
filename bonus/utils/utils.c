/*
** utils.c for utils in /home/Neferett/CPE_2016_BSQ
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Dec 18 11:04:24 2016 Bonaldi Jordan
** Last update Sun Dec 18 15:03:09 2016 Bonaldi Jordan
*/

# include "project.h"

Boolean         refresh_file(t_bsq *b)
{
  if ((b->fd = open(b->file, O_RDONLY)) < 0)
    exit(84);
  return (true);
}

int             va_min(int max, ...)
{
  va_list       argp;
  int           tmp;
  int           i;
  int           j;

  i = -1;
  va_start(argp, max);
  tmp = va_arg(argp, int);
  while (++i < max - 1)
    if ((!(j = va_arg(argp, int)) ? 1 : 1) && j <= tmp && (tmp = j)) {}
  va_end(argp);
  return (tmp + 1);
}
