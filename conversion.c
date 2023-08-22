#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++;  // Move to the character after '%'
            switch (*format) {
                case 'c':
                    {
                        char c = va_arg(args, int); // Get the character argument
                        putchar(c);  // Print the character
                        count++;
                    }
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *); // Get the string argument
                        while (*str) {
                            putchar(*str);  // Print each character of the string
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');  // Print a '%' character
                    count++;
                    break;
                default:
                    putchar('%');    // Print the '%' character
                    putchar(*format); // Print the character after '%'
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);  // Print non-format characters
            count++;
        }
        format++;  // Move to the next character in the format string
    }

    va_end(args);
    return count;
}

int main() {
    int num = 42;
    char ch = 'A';
    char *str = "Hello, World!";
    
    int count = _printf("This is a test: %c %s %%%d\n", ch, str, num);

    printf("\nNumber of characters printed: %d\n", count);

    return 0;
}

