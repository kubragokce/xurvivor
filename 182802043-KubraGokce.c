#include <stdio.h>
#include <stdlib.h>

void AralarindaAsalMi(int sayi1,int *sayi2,int engelSayisi,FILE *fp);

int main(){

int parkurUzunlugu;
int HP=100;
int engelSayisi;
FILE *fp;
     if ((fp = fopen("log.txt", "a")) == NULL) {
      printf("Dosya acma hatasi!\n");
      exit(1);
     }

fprintf(fp,"XURVIVOR YARISMASINA HOSGELDINIZ!\n");

srand(time(NULL));
parkurUzunlugu =50+rand()%50;
fprintf(fp,"Parkur Uzunlugu: %d\n",parkurUzunlugu);

srand(time(NULL));
engelSayisi =2+rand()%3;
fprintf(fp,"Engel Sayisi: %d\n",engelSayisi);

int *engelUzunlugu[engelSayisi];

srand(time(NULL));
for(int i=0;i<engelSayisi;i++){
    *(engelUzunlugu+i) =5+rand()%(parkurUzunlugu-5);
    fprintf(fp,"%d. Engel Uzunlugu: %d\n",i+1,*(engelUzunlugu+i));
}

AralarindaAsalMi(HP,engelUzunlugu,engelSayisi,fp);

if(HP>0){
    fprintf(fp,"Tebrikler yarismayi kazandiniz buyuk odul sizin!\n HP : %d",HP);
}
else{
    fprintf(fp,"Yarismayi kaybettiniz.\nHP : %d\n", HP);
}

fclose(fp);
getch();
return 0;
}

void AralarindaAsalMi(int sayi1,int *sayi2,int engelSayisi,FILE *fp){

    int buyuk, kucuk, kontrol=0;

for(int i=0;i<engelSayisi;i++){

    if ( sayi1 == 1 || *(sayi2+i) == 1){
        fprintf(fp,"%d ile %d aralarinda asal degildir.", sayi1, *(sayi2+i));
        getch();
        return 0;
    }

    else if (sayi1 > *(sayi2+i)){        //Küçük ve büyük sayýlarý buluyoruz
        buyuk = sayi1;
        kucuk = *(sayi2+i);
    }
    else{
        buyuk = *(sayi2+i);
        kucuk = sayi1;
    }

    for(int j=2; j<=kucuk; j++){
        if( (buyuk % j == 0) && (kucuk % j == 0) ){
            kontrol = 1;    // Herhangi bir sayýyýa bölündü ile kontrol 1 olur
            break;            // Diðer sayýlara bölmeye gerek kalmadýðý için döngüden çýkýlýr
        }
    }

    if(kontrol == 1){
        fprintf (fp,"%d ile %d aralarinda asal degildir\n", sayi1, *(sayi2+i));
}
    else{
        sayi1 -= *(sayi2+i);
        printf ("HP: %d\n", sayi1);
         if(sayi1<=0){
            fprintf(fp,"Yasam puaniniz bitti elendiniz.\n");
            exit(1);
         }
}
}
}
