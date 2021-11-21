#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <ctype.h>
#define PM 100

void str_replace(char *target, const char *needle, const char *replacement)
{
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    const char *tmp = target;
    size_t needle_len = strlen(needle);
    size_t repl_len = strlen(replacement);
    while (1) {
        const char *p = strstr(tmp, needle);

        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        memcpy(insert_point, replacement, repl_len);
        insert_point += repl_len;

        tmp = p + needle_len;
    }

    strcpy(target, buffer);
}


int main(int argc, char *argv[]){
	char *line, *regex_line, buffer[100], *substitution;
	size_t n;
	regex_t r;
	int i, status, size;
	regmatch_t pm[PM];

	if (argc != 4){
		printf("USAGE: ./esub <string> <eregexp> <substitution>\n");
		return 0;
	}

	line = argv[1];
	substitution = argv[3];
	str_replace(substitution, "\\n", "\n");
	str_replace(substitution, "\\a", "\a");
	str_replace(substitution, "\\b", "\b");
	str_replace(substitution, "\\e", "\e");
	str_replace(substitution, "\\f", "\f");
	str_replace(substitution, "\\r", "\r");
	str_replace(substitution, "\\v", "\v");
	str_replace(substitution, "\\t", "\t");

	if ((status = regcomp(&r, argv[2], REG_EXTENDED)))
	{
		regerror(status, &r, buffer, 100);
     	fprintf(stderr, "regcomp() failed with '%s'\n%d\n", buffer, status);
     	return 0;
	}

	if (!(status = regexec(&r, line, PM, pm, 0)))
	{
		int max_submatch = 0, submatch_num = 0; 
		for (i = 1; i < PM; i++)
		{
			if (pm[i].rm_so != -1 && pm[i].rm_eo != 1)
			{
				max_submatch++;
			}
		}
		for (i = 0; i < strlen(substitution); i++)
		{
			if (substitution[i] == '\\' && substitution[i+1] == '(')
			{
				submatch_num = 0;
				i = i + 2;
				while (isdigit(substitution[i]))
				{
					submatch_num = submatch_num * 10 + (substitution[i] - '0');
					i++;
				}
				if (substitution[i] != ')' || submatch_num == 0)
				{
					fprintf(stderr, "Error parsing substitution string!\n");
					return 0;
				}
				if (submatch_num > max_submatch){
					fprintf(stderr, "There is no %d submatches!\n", submatch_num);
					return 0;
				}
			}
			else if (substitution[i] == '\\' && substitution[i+1] != '(')
			{
				fprintf(stderr, "Error parsing substitution string!\n");
				return 0;
			}
		}
		for (i = 1; i <= max_submatch; i++)
		{
			if (i < 10)
			{
				size = 5;
			}
			else if (i < 100)
			{
				size = 6;
			}
			else
			{
				size = 7;
			}
			status = 10;
			char buf[pm[i].rm_eo - pm[i].rm_so + 1], sub_num[size];
			buf[pm[i].rm_eo - pm[i].rm_so] = '\0';
			sub_num[size - 1] = '\0';
			for(int j = 0; j < (pm[i].rm_eo - pm[i].rm_so); j++)
			{
				buf[j] = line[pm[i].rm_so + j];
			}
			sub_num[0] = '\\';
			sub_num[1] = '(';
			sub_num[size - 2] = ')';
			for(int j = size - 3; j > 1; j--)
			{

				sub_num[j] = (i % status) + '0';
				status = status * 10;
			}
			str_replace(substitution, sub_num, buf);

		}
		char buf[pm[0].rm_eo - pm[0].rm_so + 1];
		buf[pm[0].rm_eo - pm[0].rm_so] = '\0';
		for (i = 0; i < (pm[0].rm_eo - pm[0].rm_so); i++)
		{
			buf[i] = line[i + pm[0].rm_so];
		}
		str_replace(line, buf, substitution);
		printf("%s\n", line);

	}
	else if (status == REG_NOMATCH)
	{
		printf("%s\n", line);
		return 0;
	}
	else
	{
		regerror(status, &r, buffer, 100);
     	fprintf(stderr, "regexec() failed with '%s'\n", buffer);
     	return 0;
	}



	return 0;
}








































































