/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sun Dec 18 15:00:57 2016 Bonaldi Jordan
*/

#ifndef H_CHECK
# define H_CHECK

# include <sys/stat.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
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

typedef struct          s_client
{
  int                   fd;
  int                   nfd;
  int                   num;
  int                   fs;
  struct sockaddr_in    local;
  struct sockaddr_in    server;
  char                  *buf;
  char                  *file;
  char                  *filebuf;
}                       t_client;

void            client(int, char *, int, int);
void            message_handler(t_client *, char *);
void            set_addr(t_client *, int);
void            send_file(t_client *, char *, int);
void            recept_file(t_client *);
void            create_socket_desc(t_client *);
void            wait_connection(t_client *);
void            my_exit(char *);
t_client        *init(int);
int		spec_display(t_bsq *);
t_bsq		*bsq_initialiser();
Boolean		refresh_file(t_bsq *);
void		lines_handler(t_bsq *);
void		display_bsq(t_bsq *);
void		tab1_to_bit(t_bsq *);
void		tab2_to_bit(t_bsq *);
int		va_min(int, ...);
int		bsq(char *);

#endif
