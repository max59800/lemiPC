/*
** main.c for lemipc in /home/peelou/SVN
** 
** Made by gery baudry
** Login   <baudry_g@epitech.net>
** 
** Started on  Tue Mar 26 11:22:42 2013 gery baudry
** Last update Tue Mar 26 11:24:05 2013 gery baudry
*/

#include	"proto.h"

int		main(int ac, char **av)
{
  char		map[10][10];

  map[5][6] = '#';
  if (ac != 3)
    {
      printf("Usage : ./lemipc ...\n");
      return (-1);
    }
  else
    {
      //run
      printf("%c\n", map[5][6]);
    }
  return (0);
}
