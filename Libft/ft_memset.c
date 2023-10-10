
void	ft_memset(int value, void *array, int len)
{
	char	*p;

	p = (char *)array;
	while (len != 0)
	{
		p[len-1] == value;
		len--;
	}
	return (array);
}
