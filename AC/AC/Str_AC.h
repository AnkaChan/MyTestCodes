#ifndef _AC_STR_H_
#define _AC_STR_H_

namespace AC {
	struct STR
	{
		static void split(std::vector<std::string> & result, const char *str, char c = ' ')
		{
			do
			{
				const char *begin = str;

				while (*str != c && *str)
					str++;

				result.push_back(std::string(begin, str));
			} while (0 != *str++);

			return;
		}

		static void padTo(std::string &str, const size_t num, const char paddingChar = ' ')
		{
			if (num > str.size())
				str.insert(0, num - str.size(), paddingChar);
		}
	};
}
#endif