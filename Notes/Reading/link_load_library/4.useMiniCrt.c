#include "4.miniCRT.h"

int main(int argc,char* argv[])
{
    int i;
    FILE* p =NULL;
    char** v = malloc(argc*sizeof(char*));
    for (i = 0; i < argc; i++)
    {
        v[i]= malloc(strlen(argv[i])+1);
        strcpy(v[i],argv[i]);
    }
    p = fopen("4.useMinicrt.txt","w+");
    for (i = 0; i < argc; i++)
    {
        int len = strlen(v[i]);
        fwrite(&len,1,sizeof(int),p);
        fwrite(&v[i],1,len,p);
    }
    fclose(p);
    p = fopen("4.useMinicrt.txt","r");
    for (i = 0; i < argc; i++)
    {
        int len;
        char* buff;
        fread(&len,1,sizeof(int),p);
        buff[len]='\0';
        printf("%d %s\n",len,buff);
        free(buff);
        free(v[i]);
    }
    fclose(p);
}
/*
gcc

mscv


*/