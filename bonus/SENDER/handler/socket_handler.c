/*
** socket_handler.c for socket_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:16:56 2016 Bonaldi Jordan
** Last update Sun Dec 18 13:11:01 2016 Bonaldi Jordan
*/

# include "project.h"

void	create_socket_desc(t_client *sv)
{
  if ((sv->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    my_exit("ERROR: Failed to obtain Socket Descriptor :");
  else
    my_printf("[Server] Socket descriptor obtained successfully.\n");
}

/* void	wait_connection(t_server *sv) */
/* { */
/*   int	size; */

/*   size = sizeof(struct sockaddr_in); */
/*   if ((sv->nfd = accept(sv->fd, (struct sockaddr *)&sv->server, (socklen_t *)&size)) < 0) */
/*     my_exit("ERROR: Impossible to obtain new Socket Descriptor :"); */
/*   else */
/*     my_printf("[Server] Server has got connected from %s.\n", */
/* 	      inet_ntoa(sv->server.sin_addr)); */
/* } */
