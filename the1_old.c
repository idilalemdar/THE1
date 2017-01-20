#include <stdio.h>

 void field_printer(int n, char field[10][10])
 {
 	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++) 
		{
			printf(" ");
		}
		for (j = 0; j < (n-i); j++)
		{
			printf("%c ", field[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 }

int isIdeal(int n, char field[10][10])
{
	int count = 0, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < (n-i); j++)
		{
			if (field[i][j] == 's')
			{
				count++;
			}
		}
	}
	if (count == 1)
	{
		return 1;
	}
	return 0;
}

int backtrack(int n, char field[10][10])
{
	int i, j;
	if (isIdeal(n, field))
	{
		field_printer(n,field);
		return 1;
	}
	else
	{
		for (i = 2; i < n; i++) /* Right up to left down movement */
		{
			for (j = 0; j < (n-i); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i-1][j+1] == 's' && field[i-2][j+2] == 's')
					{
						field[i][j] = 's';
						field[i-1][j+1] = 'e';
						field[i-2][j+2] = 'e';
						if (backtrack(n, field))
						{
							field[i][j] = 'e';
							field[i-1][j+1] = 's';
							field[i-2][j+2] = 's';
							field_printer(n, field);
							return 1;
						}
						else
						{
							field[i][j] = 'e';
							field[i-1][j+1] = 's';
							field[i-2][j+2] = 's';
						}
					}
				}
			}
		}
		for (i = 2; i < n; i++) /* Left up to right down movement */
		{
			for (j = 0; j < (n-i); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i-1][j] == 's' && field[i-2][j] == 's')
					{
						field[i][j] = 's';
						field[i-1][j] = 'e';
						field[i-2][j] = 'e';
						if (backtrack(n, field))
						{
							field[i][j] = 'e';
							field[i-1][j] = 's';
							field[i-2][j] = 's';
							field_printer(n, field);
							return 1;
						}
						else
						{
							field[i][j] = 'e';
							field[i-1][j] = 's';
							field[i-2][j] = 's';
						}
					}
				}
			}
		}
		for (i = 0; i < (n-2); i++) /* Left-to-Right Movement */
		{
			for (j = 2; j < (n-i); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i][j-1] == 's' && field[i][j-2] == 's')
					{
						field[i][j] = 's';
						field[i][j-1] = 'e';
						field[i][j-2] = 'e';
						if (backtrack(n, field))
						{
							field[i][j] = 'e';
							field[i][j-1] = 's';
							field[i][j-2] = 's';
							field_printer(n, field);
							return 1;
						}
						else
						{
							field[i][j] = 'e';
							field[i][j-1] = 's';
							field[i][j-2] = 's';
						}
					}
				}
			}
		}
		for (i = 0; i < (n-2); i++) /* Left down to right up movement */
		{
			for (j = 2; j < (n-i); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i+1][j-1] == 's' && field[i+2][j-2] == 's')
					{
						field[i][j] = 's';
						field[i+1][j-1] = 'e';
						field[i+2][j-2] = 'e';
						if (backtrack(n, field))
						{
							field[i][j] = 'e';
							field[i+1][j-1] = 's';
							field[i+2][j-2] = 's';
							field_printer(n, field);
							return 1;
						}
						else
						{
							field[i][j] = 'e';
							field[i+1][j-1] = 's';
							field[i+2][j-2] = 's';
						}
					}
				}
			}
		}
		for (i = 0; i < (n-2); i++) /* Right down to left up movement */
		{
			for (j = 0; j < (n-i-2); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i+1][j] == 's' && field[i+2][j] == 's')
					{
						field[i][j] = 's';
						field[i+1][j] = 'e';
						field[i+2][j] = 'e';
						if (backtrack(n, field))
						{
							field[i][j] = 'e';
							field[i+1][j] = 's';
							field[i+2][j] = 's';
							field_printer(n, field);
							return 1;
						}
						else
						{
							field[i][j] = 'e';
							field[i+1][j] = 's';
							field[i+2][j] = 's';
						}
					}
				}
			}
		}
		for (i = 0; i < (n-2); i++) /* Right-to-Left Movement */
		{
			for (j = 0; j < (n-i-2); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i][j+1] == 's' && field[i][j+2] == 's')
					{
						field[i][j] = 's';
						field[i][j+1] = 'e';
						field[i][j+2] = 'e';
						if (backtrack(n, field))
						{
							field[i][j] = 'e';
							field[i][j+1] = 's';
							field[i][j+2] = 's';
							field_printer(n, field);
							return 1;
						}
						else
						{
							field[i][j] = 'e';
							field[i][j+1] = 's';
							field[i][j+2] = 's';
						}
					}
				}
			}
		}
		return 0;
	}
}

int main()
{
	int i,j,n, a;
	char field[10][10];
	scanf("%d", &n);
	for (i = 0; i < n ; i++)
	{
		for (j = 0; j < (n-i); j++)
		{
			scanf(" %c", &field[i][j]);
		}
	}
	a = backtrack(n, field);
	if (!a)
	{
		printf("No ideal field!\n");
	}
	return 0;
}