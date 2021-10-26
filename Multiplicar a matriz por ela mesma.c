#include <stdio.h>

int
main ()
{
  int i, j, x, y = 0, k, z = 0, f = 0, l = 0;
  printf("Declare o tamanho da matriz quadrada: ");
  scanf ("%i", &x);
  double matriz[x][x], v[x], c[x], multi[x], soma = 0;
  z = x * x;
  printf("Declare a matriz: ");
  for (i = 0; i < x; i++)
    {
      for (j = 0; j < x; j++)
	{
	  scanf ("%lf", &matriz[i][j]);
	}
    }

  do
    {
      for (k = 0; k < x; k++)
	{
	  for (j = 0, i = l; j < x; j++)
	    {
	      c[j] = matriz[i][j];

	    }

	  for (i = 0, j = y; i < x; i++)
	    {
	      v[i] = matriz[i][j];

	    }

	  y++;
	  if (y == x)
	    {
	      y = 0;
	    }
	  for (i = 0; i < x; i++)
	    {
	      multi[i] = c[i] * v[i];
	    }
	  for (i = 0; i < x; i++)
	    {
	      soma = multi[i] + soma;
	    }
	  printf ("%.1lf ", soma);
	  f++;
	  soma = 0;
	}
      l++;
      printf ("\n");
    }
  while (f < z);
}
