/*
** main.c for lemipc in /home/peelou/SVN
** 
** Made by gery baudry
** Login   <baudry_g@epitech.net>
** 
** Started on  Tue Mar 26 11:22:42 2013 gery baudry
** Last update Tue Mar 26 11:24:05 2013 gery baudry
*/

#include	"lemipc.h"

int		semid = -1;

int		check_args(int ac)
{
  if (ac != 3)
    {
      printf("Usage : ./lemipc ...\n");
      return (-1);
    }
  return (0);
}

int		shm_init()
{
  //  shmid = shm(key);
}

int		sem_init(struct play *player, char *filename, char proj, int nb)
{
  if (player->sem_id == -1)
    {
      key_t	key;
      
      key = ftok(filename, proj);
      player->sem_id = semget(key, nb, 0666);
      if (player->sem_id == -1)
	{
	  player->sem_id = semget(key, nb, IPC_CREAT | IPC_EXCL);
	  if (player->sem_id == -1)
	    {
	      printf("Unable to create semaphore\n");
	      exit(EXIT_FAILURE);
	    }
	  return (1);
	}
      else
	return (0);
    }
  else
    return (-1);
}

int		main(int ac, char **av)
{
  char		map[10][10];
  char		proj;
  struct sembuf	op;
  struct play	player;

  proj = 'p';
  map[5][6] = '#';
  player.sem_id = -1;
  if (check_args(ac) == -1)
    return (-1);
  sem_init(&player, av[0], proj, 1);
  return (0);
}
