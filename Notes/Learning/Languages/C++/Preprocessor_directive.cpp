#define PI 3.1415926f
#define Plank_H 6.62607e-34

#define CURSOR(top, bottom) (((top) << 8)) | (bottom)
#define RANDOM(min, max) \
    ((rand() % (int)(((max) + 1) - (min))) + (min))

#define ADD(a, b) (a + b)
#define MOD(a, b) (a % b)

#if !defined(__cplusplus)
#error c++ compiler required.
#endif

#if defined(LOG_LEVEL)
    #if LOG_LEVEL==1
        #pragma warning(disable:1)
    #elif LOG_LEVEL==2
        #pragma warning(disable:2)
    
    #elif LOG_LEVEL==3
        #pragma warning(disable:3)
    
    #elif LOG_LEVEL>3
        #pragma warning(disable:1024)
    #else
        #pragma warning(disable:2048)
    #endif
#else
    #pragma warning(disable : 4500; once : 4385; error : 164)
#endif

#if PI == 3
#define DPI
#if PI = 3.14f
#elif PI == 3.1415f

#else
#define PI = 3.14f
#endif

#include <stdio.h>

int main(int argc, char *argv)
{

    return 0;
}
