/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sun Dec 18 11:22:57 2016 Bonaldi Jordan
*/

#ifndef H_CHECK
# define H_CHECK

# include <sys/stat.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include "lib.h"

typedef struct		s_bsq
{
  char			*file;
  char			*tmp;
  char			*origin;
  int			nblines;
  int			fd;
  int      		*tab1;
  int      		*tab2;
  Boolean		ok;
  int      		rl;
  int			lines;
  int			size;
  int			y;
  int			x;
}			t_bsq;

int		spec_display(t_bsq *);
t_bsq		*bsq_initialiser();
Boolean		refresh_file(t_bsq *);
void		lines_handler(t_bsq *);
void		display_bsq(t_bsq *);
void		tab1_to_bit(t_bsq *);
void		tab2_to_bit(t_bsq *);
int		va_min(int, ...);

#endif
