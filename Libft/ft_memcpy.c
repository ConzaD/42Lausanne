
void ft_memcpy(void *dest, const void *src, int size)
{
	char	*p;
	char	*m;
	int		i;

	p = (char *)src;
	m = (char *)dest;
	i = 0;
	while( i < size)
	{
		m[i] = p[i];
		i++;
	}
	return (dest);
}
