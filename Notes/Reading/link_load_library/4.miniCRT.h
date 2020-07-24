#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

#ifdef __cplusplus
extern "C"
{
#endif

//malloc
#ifndef NULL
#define NULL (0)
#endif

    int mini_crt_init_heap();
    void *malloc(unsigned size);
    void free(void *ptr);
    static void *brk(void *end_data_segment);

    //string
    char *itoa(int n, char *str, int radix);
    unsigned strlen(const char *src);
    int strcmp(const char *src, const char *dst);
    char *strcpy(char *dst, const char *src);

    //IO
    typedef int FILE;
#define EOF (-1)

#ifdef WIN32
#define stdin ((FILE *)GetStdHadnle(STD_INPUT_HANDLE))
#define stdout ((FILE *)GetStdHadnle(STD_OUTPUT_HANDLE))
#define stderr ((FILE *)GetStdHadnle(STD_ERROR_HANDLE))
#else
#define stdin ((FILE *)0)
#define stdout ((FILE *)1)
#define stderr ((FILE *)2)
#endif

    int mini_crt_init_io();

    FILE *fopen(const char *fname, const char *mode);
    int fread(char *buffer, int size, int count, FILE *stream);
    int fwrite(const void *buffer, int size, int count, FILE *stream);
    int fclose(FILE *p);
    int fseek(FILE *p, int offset, int set);

    //printf
    int fputc(int c, FILE *stream);
    int fputs(const char *str, FILE *stream);
    int printf(const char *format, ...);
    int fprintf(FILE *stream, const char *format, ...);

    //internal
    void do_global_ctors();
    void mini_crt_call_exit_routine();

    //atexit
    typedef void (*atexit_func_t)(void);
    int atexit(atexit_func_t func);

#ifdef __cplusplus
}
#endif

#endif //__MINI_CRT_H__
