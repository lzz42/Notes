#include "4.miniCRT.h"

//整形转字符串
char *itoa(int n, char *str, int radix)
{
    char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p = str;
    char *head = str;
    if (!p || radix < 2 || radix > 36)
        return p;
    if (n == 0)
    {
        *p++ = '\0';
        *p = 0;
        return p;
    }
    if (radix == 10 && n < 0)
    {
        *p++ = '-';
        n = -n;
    }
    while (n)
    {
        *p++ = digit[n % radix];
        n /= radix;
    }
    *p = 0;
    for (--p; head < p; head++, --p)
    {
        char temp = *head;
        *head = *p;
        *p = temp;
    }
    return str;
}

int strcmp(const char *src, const char *dst)
{
    int ret = 0;
    unsigned char *p1 = (unsigned char *)src;
    unsigned char *p2 = (unsigned char *)dst;
    while (!(ret = *p1 - *p2) && *p2)
    {
        ++p1;
        ++p2;
    }
    if (ret < 0)
        return -1;
    else if (ret > 0)
        ret = 1;

    return ret;
    return ret;
}

char *strcpy(char *dst, const char *src)
{
    char *ret = dst;
    while (*src)
    {
        *dst++ = *src++;
    }
    *dst++ = '\0';
    return ret;
}

unsigned strlen(const char *src)
{
    if (!src)
        return 0;
    int ret = 0;
    for (; *src != '\0'; ++src)
    {
        ++ret;
    }
    return ret;
}

//格式输出

int fputc(int c, FILE *stream)
{
    if (fwrite(&c, 1, 1, stream) != 1)
        return EOF;
    else
        return c;
}

int fputs(const char *str, FILE *stream)
{
    int len = strlen(str);
    if (fwrite(str, 1, len, stream) != len)
        return EOF;
    else
        return len;
}

#ifdef WIN32
#include <Windows.h>
#else
#define va_list char *
#define va_start(ap, arg) (ap = (va_list)&arg + sizeof(arg))
#define va_arg(ap, t) (*(t *)((ap += sizeof(t)) - sizeof(t)))
#define va_end(ap) (ap = (va_list)0)
#endif

int vprintf(FILE *stream, const char *format, va_list arglist)
{
    int translaating = 0;
    int ret = 0;
    const char *p = 0;
    for (p = format; *p != '\0'; ++p)
    {
        switch (*p)
        {
        case '%':
            if (!translaating)
                translaating = 1;
            else
            {
                if (fputc('%', stream) < 0)
                    return EOF;
                ++ret;
                translaating = 0;
            }
            break;
        case 'd':
            if (translaating)
            {
                char buff[16];
                translaating = 0;
                itoa(va_arg(arglist, int), buff, 10);
                if (fputs(buff, stream) < 0)
                    return EOF;
                ret += strlen(buff);
            }
            else if (fputc('d', strlen) < 0)
                return EOF;
            else
                ++ret;
            break;
        case 's':
            if (translaating)
            {
                translaating = 0;
                const char *str = va_arg(arglist, const char *);
                if (fputs(str, stream) < 0)
                    return EOF;
                ret += strlen(str);
            }
            else if (fputc('s', strlen) < 0)
                return EOF;
            else
                ++ret;
            break;
        default:
            if (translaating)
                translaating = 0;
            if (fputc(*p, stream) < 0)
                return EOF;
            else
                ++ret;
            break;
        }
    }
    return ret;
}

int printf(const char *format, ...)
{
    va_list(arglist);
    va_start(arglist, format);
    return vprintf(stdout, format, arglist);
}

int fprintf(FILE *stream, const char *format, ...)
{
    va_list(arglist);
    va_start(arglist, format);
    return vprintf(stream, format, arglist);
}