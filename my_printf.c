#include"main.h"

int _printf(const char *format, ...)
{
	va_list list;
	int i,j;
	int len =0;
	char newline = '\n';
	int array_size;

	print arr[] ={
		{'c', print_char},
		{'s', print_str},
		{'%', print_modulus},
	};

	array_size = sizeof(arr)/sizeof(arr[0]);
	if (format == NULL)
		return(0);
	va_start(list, format);
	for(i=0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1,&format[i],1);
			len++;
		}
		else
		{
			i++;
			for(j=0;j<array_size;j++)
			{
				if(format[i] == arr[j].specifier_type)
				{
					arr[j].print(list);
					break;
				}
			}
		}
	}
	if(format[i]=='\n')
		write(1, &newline,1);
	return(len + 1);
}
