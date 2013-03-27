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

int		main(int ac, char **av)
{
  key_t		key;
  int           sem_id;
  struct sembuf	sops;

  if (check_args(ac) == -1)
    return (-1);
  key = ftok(av[1], 0);
  printf("key = [%d]\n", key);

  sem_id = semget(key, 1, SHM_R | SHM_W);
  if (sem_id == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      printf("sem_id = [%d]\n", sem_id);
      semctl(sem_id, 0, SETVAL, 4);
    }
  else
    {
      printf("Already exist\n");
      sops.sem_num = 0;
      sops.sem_op = -1;
      sops.sem_flg = 0;
      semop(sem_id, &sops, 1);
      printf("value = %d\n", semctl(sem_id, 0, GETVAL));
    }
  if (semctl(sem_id, 0, GETVAL) == 0)
    {
       printf("All the players are here");
       return (-1);
    }
  return (0);
}
