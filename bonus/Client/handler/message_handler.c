/*
** message_handler.c for message_handler in /home/Neferett/Client
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Fri Dec 16 11:21:22 2016 Bonaldi Jordan
** Last update Sun Dec 18 16:45:59 2016 Bonaldi Jordan
*/

# include <sys/select.h>
# include "project.h"

void	message_handler(t_client *cl, char *msg)
{
  fd_set                read;
  char                  *rec;
  int                   ret;
  struct timeval        tv;

  FD_ZERO(&read);
  FD_SET(cl->fd, &read);
  if (!(rec = malloc(200)))
    exit(84);
  if (send(cl->fd, msg, my_strlen(msg), 0) < 0)
    my_printf("ERROR: send failed !\n");
  my_printf("Sent : [%s]\n", msg);
  tv.tv_sec = 0;
  tv.tv_usec = 500000;
  if ((ret = select(cl->fd + 1, &read, NULL, NULL, &tv)) <= 0)
    perror("Select");
  else
    {
      if (FD_ISSET(cl->fd, &read))
	ret = recv(cl->fd, rec, 200, 0);
      rec[ret] = '\0';
      my_printf("Received : [%s]\n", rec);
    }
}
