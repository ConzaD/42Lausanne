
int	ft_isalnum(int a)
{
		if((a >= 65 || a <= 90) && (a >= 97 || a <= 122) && (a >= 48 || a <= 57))
			return (1);
		return (0);
}