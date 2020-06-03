int Shared =1;

void swap41(int* a,int* b){
    *a^=*b^=*a^=*b;
}

void swap42(int* a,int* b){
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

void swap43(int* a,int* b){
    *a^=*b;
    *b^=*a;
    *a^=*b;
    *a *=10;
    *b *=10;
}