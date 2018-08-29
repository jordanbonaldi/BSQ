/*
** recept_file.c for recept_file in /home/Neferett/Client
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Dec 18 11:57:07 2016 Bonaldi Jordan
** Last update Sun Dec 18 14:41:42 2016 Bonaldi Jordan
*/

# include "project.h"

void		recept_file(t_client *sv)
{
  int		write;
  FILE		*fs;

  if (!(sv->filebuf = malloc(4097)))
    my_exit("ERROR: ");
  sv->file = "map";
  /* system("rm -f map"); */
  my_printf("[Client] Receiving file %s ...\n", sv->file);
  if (!(fs = fopen(sv->file, "a")))
    my_exit("ERROR: Problem with file:");
  bzero(sv->filebuf, 4096);
  while ((sv->fs = recv(sv->fd, sv->filebuf, 4096, 0)) > 0)
    {
      if ((write = fwrite(sv->filebuf, sizeof(char), sv->fs, fs)) < sv->fs)
	my_exit("ERROR:");
      bzero(sv->filebuf, 4096);
      if (!sv->fs || sv->fs != 512)
     break;
    }
  if (sv->fs < 0)
    {
      if (errno == EAGAIN && my_printf("[Client] TIME OUT !\n"));
      else
     my_exit("ERROR:");
    }
  my_printf("File received\n");
  fclose(fs);
  exit(0);
}
