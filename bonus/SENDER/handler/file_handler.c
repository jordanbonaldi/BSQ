/*
** file_handler.c for file_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:28:16 2016 Bonaldi Jordan
** Last update Sun Dec 18 14:34:07 2016 Bonaldi Jordan
*/

# include "project.h"

void	send_file(t_client *sv, char *file, int length)
{
  FILE  *fs;

  if (!(sv->filebuf = malloc(length)))
    my_exit("ERROR: ");
  sv->file = file;
  my_printf("[Client] Sending %s ...\n", sv->file);
  if (!(fs = fopen(sv->file, "r")))
    my_exit("ERROR: Problem with file:");
  bzero(sv->filebuf, length);
  while ((sv->fs = fread(sv->filebuf, 1, 512, fs)) > 0)
    if (send(sv->fd, sv->filebuf, sv->fs, 0) < 0)
      my_exit("ERROR: Failed to send the file :");
    else
      bzero(sv->filebuf, length);
  my_printf("[Client] File sent successfully.\n");
}

/* void	send_file(t_client *sv, char *file, int length) */
/* { */
/*   int	write; */
/*   FILE  *fs; */

/*   if (!(sv->filebuf = malloc(length))) */
/*     my_exit("ERROR: "); */
/*   sv->file = file; */
/*   my_printf("[Client] Receiving file %s ...\n", sv->file); */
/*   if (!(fs = fopen(sv->file, "a"))) */
/*     my_exit("ERROR: Problem with file:"); */
/*   bzero(sv->filebuf, length); */
/*   while ((sv->fs = recv(sv->fd, sv->filebuf, length, 0)) > 0) */
/*     { */
/*       if ((write = fwrite(sv->filebuf, sizeof(char), sv->fs, fs)) < sv->fs) */
/* 	my_exit("ERROR:"); */
/*       bzero(sv->filebuf, length); */
/*       if (!sv->fs || sv->fs != 512) */
/* 	break; */
/*     } */
/*   if (sv->fs < 0) */
/*     { */
/*       if (errno == EAGAIN && my_printf("[Client] TIME OUT !\n")); */
/*       else */
/* 	my_exit("ERROR:"); */
/*     } */
/*   my_printf("File received\n"); */
/*   fclose(fs); */
/*   close(sv->fd); */
/*   my_printf("[Client] connection closed\n"); */
/* } */
