/*
** message_handler.c for messages_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Dec 15 21:55:01 2016 Bonaldi Jordan
** Last update Fri Dec 16 13:30:53 2016 Bonaldi Jordan
*/

# include "project.h"

void	message_handler(t_server *sv)
{
  int	size;
  char	*message;

  if (!(message = malloc(4096)))
    exit(84);
  sv->size = recv(sv->nfd, message, 4096, 0);
  message[sv->size] = 0;
  printf("Sent from %d : %s\n", sv->nfd, message);
  write(sv->nfd2, message, my_strlen(message));
  bzero(message, 4096);
  size = recv(sv->nfd2, message, 4096, 0);
  message[size] = 0;
  printf("Sent from %d : %s\n", sv->nfd2, message);
  write(sv->nfd,  message, my_strlen(message));
  if (!sv->size && my_printf("Client disconnected\n"))
    fflush(stdout);
  else if (sv->size < 0)
    perror("ERROR: ");
  free(message);
}
