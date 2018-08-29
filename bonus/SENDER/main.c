/*
** main.c for main in /home/Neferett/bin/IMPORT
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sun Dec 18 12:27:50 2016 Bonaldi Jordan
*/

#include "project.h"

int	main(int argc, char **argv)
{
  if (argc > 5)
    return (84);
  if (*argv[1] == '-' && argv[1][1] == 'm')
    client(my_getnbr(argv[2]), argv[3], 0, 1);
  if (*argv[1] == '-' && argv[1][1] == 's')
    client(my_getnbr(argv[2]), argv[3], my_getnbr(argv[4]), 2);
  if (*argv[1] == '-' && argv[1][1] == 'r')
    client(my_getnbr(argv[2]), NULL, 0, 3);
  return (0);
}
