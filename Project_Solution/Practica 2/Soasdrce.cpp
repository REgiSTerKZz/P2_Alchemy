


std::string delUnnecessary(std::string &str)
{
	int size = str.length();
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= j; i++)
		{
			if (str[i] == ' ' && str[j] != ' ') {
				str.erase(0, i);
			}
		}
	}
	return str;
}