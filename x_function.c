/*
** x_function.c for lemipc in /home/peelou/SVN/lemiPC
** 
** Made by gery baudry
** Login   <baudry_g@epitech.net>
** 
** Started on  Wed Mar 27 10:10:12 2013 gery baudry
** Last update Wed Mar 27 14:07:03 2013 gery baudry
*/

key_t		xftok(const char *pathname, int proj_id)
{
  key_t		key;

  key = ftok(pathname, proj_id);
  if (key == -1)
    {
      printf("Fail Ftok\n");
      exit(EXIT_FAILURE);
    }
  return (key);
}

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      printf("Malloc Fail\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

void		xshmdt(const void *shmaddr)
{
  if (shmdt(shmaddr) == - 1)
    {
      printf("Shmaddr Fail\n");
      exit(EXIT_FAILURE);
    }
}
