unsigned int		ft_sqrti(unsigned int n)
{
	unsigned int	square;
	unsigned int	root;
	unsigned int	gap;

	if (n < 2)
		return (n);
	gap = 5;
	root = 2;
	square = 4;
	while (n >= square)	//n = 4
	{
		root++;			// 2 :
		square += gap;	// 4 :
		gap += 2;		// 5 :
	}
	return (--root);
}
