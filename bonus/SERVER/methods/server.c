/*
** server.c for server in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:20:30 2016 Bonaldi Jordan
** Last update Sun Dec 18 13:03:00 2016 Bonaldi Jordan
*/

# include "project.h"

void	server(int port, Boolean mode)
{
  t_server	*sv;

  sv = init(port);
  while (true)
    {
      wait_connection(sv);
      if (mode)
	send_file(sv);
      else
	message_handler(sv);
      close(sv->nfd2);
      sv->nfd2 = 0;
    }
}
