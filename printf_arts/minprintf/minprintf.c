#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...){
	va_list ap;
	int ival;
	double dval;
	char *p, *sval;

	va_start(ap, fmt);
	for(p = fmt; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for(sval = va_arg(ap, char *); *sval; sval++){
					putchar(*sval);
				}
				break;
			default:
				putchar(*p);
				break;

		}

	}

	va_end(ap);

}

int main(){
	minprintf("Number is: %d\nReal number is %f\nString is %s\n", 20, 3.14, "Henurad");
	return 0;
}
