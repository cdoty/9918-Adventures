#ifndef __argcrack_h
#define __argcrack_h

// (C) 2009 Charlie Robson

#include <string>
using namespace std;

class argcrack
{
public:
	argcrack(int argc, char **argv) :
		m_argc(argc),
		m_argv(argv)
	{
	}

	bool eval(int index, int& result)
	{
		const char* val = m_argv[index];

		int len = strlen(val);
		if (!len)
			return false;

		int base = 0;
		if (*val == '%')
		{
			base = 2;
			++val;
		}
		else if (*val == '$')
		{
			base = 16;
			++val;
		}
		else if (len > 2 && val[0] == '0' && val[1] == 'x')
		{
			base = 16;
			val += 2;
		}

		char* final;
		result = strtol(val, &final, base);

		return *final == 0;
	}

	bool getint(const char* pname, int& target)
	{
		int n = indexof(pname);
		if (n == -1 || n + 1 >= m_argc)
			return false;

		return eval(n + 1, target);
	}

	bool getstring(const char* pname, string& target)
	{
		int n = indexof(pname);
		if (n == -1 || n + 1 >= m_argc)
			return false;

		target = m_argv[n+1];
		return true;
	}

	int indexof(const char* pname)
	{
		for (int i = 1; i < m_argc; ++i)
		{
			if (strcmp(pname, m_argv[i]) == 0)
			{
				return i;
			}
		}

		return -1;
	}

	bool ispresent(const char* pname)
	{
		return indexof(pname) != -1;
	}

	bool isHelpRequested()
	{
		for (int i = 1; i < m_argc; ++i)
		{
			if (strchr(m_argv[i],'?') != NULL)
			{
				return true;
			}
		}

		return false;
	}

private:
	int m_argc;
	char** m_argv;
};

#endif
