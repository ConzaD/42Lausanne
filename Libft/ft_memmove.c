
void ft_memmove(void *dest, const void *src, int size)
{
	int	i;

	if (src < dest)
	{
		i = size;
		while ( i > 0)
		{
			i--;
			((unsigned char *)dest)[i]=((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while ( i > 0)
		{
			((unsigned char *)dest)[i]=((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
