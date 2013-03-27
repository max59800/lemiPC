#ifndef		__LEMIPC_H__
#define		__LEMIPC_H__

#include	<pthread.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<sys/shm.h>

struct	play
{

  int	sem_id;
  int	shm_id;

};

#endif
