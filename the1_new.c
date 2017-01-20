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

void back(int i, int j, int a, int b, int c, int d, char field[10][10])
{
	field[i][j] = 'e';
	field[i+a][j+b] = 's';
	field[i+c][j+d] = 's';
}

void move(int i, int j, int a, int b, int c, int d, char field[10][10])
{
	field[i][j] = 's';
	field[i+a][j+b] = 'e';
	field[i+c][j+d] = 'e';
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
		for (i = 0; i < (n-2); i++) /* Left down to right up movement */
		{
			for (j = 2; j < (n-i); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i+1][j-1] == 's' && field[i+2][j-2] == 's')
					{
						move(i, j, 1, -1, 2, -2, field);
						if (backtrack(n, field))
						{
							back(i, j, 1, -1, 2, -2, field);
							field_printer(n, field);
							return 1;
						}
						else
						{
							back(i, j, 1, -1, 2, -2, field);
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
						move(i, j, 0, -1, 0, -2, field);
						if (backtrack(n, field))
						{
							back(i, j, 0, -1, 0, -2, field);
							field_printer(n, field);
							return 1;
						}
						else
						{
							back(i, j, 0, -1, 0, -2, field);
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
						move(i, j, -1, 0, -2, 0, field);
						if (backtrack(n, field))
						{
							back(i, j, -1, 0, -2, 0, field);
							field_printer(n, field);
							return 1;
						}
						else
						{
							back(i, j, -1, 0, -2, 0, field);
						}
					}
				}
			}
		}
		for (i = 2; i < n; i++) /* Right up to left down movement */
		{
			for (j = 0; j < (n-i); j++)
			{
				if (field[i][j] == 'e')
				{
					if (field[i-1][j+1] == 's' && field[i-2][j+2] == 's')
					{
						move(i, j, -1, 1, -2, 2, field);
						if (backtrack(n, field))
						{
							back(i, j, -1, 1, -2, 2, field);
							field_printer(n, field);
							return 1;
						}
						else
						{
							back(i, j, -1, 1, -2, 2, field);
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
						move(i, j, 0, 1, 0, 2, field);
						if (backtrack(n, field))
						{
							back(i, j, 0, 1, 0, 2, field);
							field_printer(n, field);
							return 1;
						}
						else
						{
							back(i, j, 0, 1, 0, 2, field);
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
						move(i, j, 1, 0, 2, 0, field);
						if (backtrack(n, field))
						{
							back(i, j, 1, 0, 2, 0, field);
							field_printer(n, field);
							return 1;
						}
						else
						{
							back(i, j, 1, 0, 2, 0, field);
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