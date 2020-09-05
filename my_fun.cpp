void toTXT(char *from, char *to)			// to turn the name into file with .txt
{
	int i = 0;
	while (from[i] != '\0')
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '.';	i++;
	to[i] = 't';	i++;
	to[i] = 'x';	i++;
	to[i] = 't';	i++;
	to[i] = '\0';
}
