#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLN	1024
#define SPACE	"\t\n\f\r " 

char * check(char *bptr)
{
	while (*bptr != '\n') {
		if (!isspace(*bptr))
			return bptr;
		++bptr;	
	}
	return bptr;
}
char *fillbuff(char *buff)
{
	fgets(buff, MAXLN, stdin);
	return buff;
}

int simplescanf(const char *fmt, ...)
{
	char buff[MAXLN], *str, *bptr, *ch;		
	int len = 0, count = 0, space = 0,*var;
	char tmp[MAXLN];
	va_list ap;
	va_start(ap, fmt);
	bptr = fillbuff(buff);
	while (*fmt) {
		len = 0;
		while (*fmt && isspace(*fmt)) {
			++fmt;
			++space;
		}
		if (!*fmt)
			break;
		if (*fmt == 's') {
			bptr = check(bptr);
			if (*bptr == '\n') {
				bptr = fillbuff(buff);
				continue;
			}
			str = va_arg(ap, char *);
			len = strcspn(bptr, SPACE);
			strncpy(str, bptr, len);
			bptr += len;
			++count;
			space = 0;
		} else if (*fmt == 'd') { 
			bptr = check(bptr);
			if (*bptr == '\n') {
				bptr = fillbuff(buff);
				continue;
			}
			var = va_arg(ap, int *);
			len = strcspn(bptr, SPACE);
			strncpy(tmp, bptr, len);
			*var = atoi(tmp);
			bptr += len;
			++count;
			space = 0;
		} else if (*fmt == 'c') {
			len = 1;
			if (space > 0) {
				bptr = check(bptr);
				if (*bptr == '\n') {
					bptr = fillbuff(buff);
					continue;
				}
			}
			str = va_arg(ap, char *);
			strncpy(str, bptr, len);
			if (*bptr == '\n') {
				bptr = fillbuff(buff);
				len = 0;
			}		
			bptr += len;
			++count;
			space = 0;
		} else
			;
		++fmt;
	}
	va_end(ap);
	return count;
}

