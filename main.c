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
  char		proj;
  key_t		cle;
  int		nbShm;
  int		nbSem;
  int		semId;
  struct sembuf	op;

  proj = 'p';
  map[5][6] = '#';
  nbSem = 1;
  nbShm = 1;
  
  // creation de cle
  cle = ftok(av[0], proj);
  // initialisation de la memoire partagee
  
  // construction du segment de moire partagee
  shmId = shmget(cle, nbShm, IPC_CREAT | IPC_EXCL);

  




// creation du semaphore
  semId = semget(cle, nbSem, IPC_CREAT | IPC_EXCL | 0666);
  semctl(semId, 0, SETVAL, 1);
  
  op.sem_num = 0;
  op.sem_op = -1;
  op.sem_flg = 0;
  
  semop(semId, &op, 1);
  // section critique
  op.sem_op = 1;
  semop(semId, &op, 1);

  semctl(semId, 0, IPC_RMID, 0); // destruction du semaphore

  return (0);
}


/*
  if (ac != 3)
  {
  printf("Usage : ./lemipc ...\n");
  return (-1);
  }
  else
  {
  //run
  //printf("%c\n", map[5][6]);
  }
*/
