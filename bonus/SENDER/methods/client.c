/*
** server.c for server in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:20:30 2016 Bonaldi Jordan
** Last update Sun Dec 18 13:17:16 2016 Bonaldi Jordan
*/

# include "project.h"

void		client(int port, char *msg, int length, int mode)
{
  t_client	*cl;

  cl = init(port);
  if (mode == 1)
    message_handler(cl, msg);
  else if (mode == 2)
    send_file(cl, msg, length);
  else
    while (true)
      recept_file(cl);
}
