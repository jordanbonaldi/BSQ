/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sun Dec 18 12:24:21 2016 Bonaldi Jordan
*/

#ifndef H_CHECK
# define H_CHECK

# include "lib.h"

# include <errno.h>
# include <string.h>
# include <strings.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <sys/wait.h>
# include <sys/socket.h>
# include <signal.h>
# include <ctype.h>
# include <arpa/inet.h>
# include <netdb.h>

typedef struct		s_client
{
  int			fd;
  int			nfd;
  int			num;
  int			fs;
  struct sockaddr_in    local;
  struct sockaddr_in	server;
  char			*buf;
  char			*file;
  char			*filebuf;
}			t_client;

void		client(int, char *, int, int);
void		message_handler(t_client *, char *);
void		set_addr(t_client *, int);
void		send_file(t_client *, char *, int);
void		recept_file(t_client *);
void		create_socket_desc(t_client *);
void		wait_connection(t_client *);
void		my_exit(char *);
t_client	*init(int);

#endif
