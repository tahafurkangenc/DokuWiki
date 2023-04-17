#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
#include <string.h>
#include <dirent.h>

//DOKUWIKIFINALIMIZ
//kendi üniversite dosyamızda masaustunde çalıştırabiliyoruz. scanf kullandığımızdan kod boşluklu etiketi arayamıyor. Türkçe karakter okuyabilmesi için bir takım şeyler yaptık ama emin değiliz.

void yenidenisimlendir(char *dosyauzantisi)
{
    char ilkisim[100];
    printf("yeniden isimlendirme\n");

    printf("ilkisim:");
    //gets(ilkisim);
    scanf("%s",&ilkisim);

    char ilkisimuzantisi[255];
    strcpy(ilkisimuzantisi,dosyauzantisi);
    strcat(ilkisimuzantisi,ilkisim);
   puts(ilkisimuzantisi);
   fflush(stdin);

    char sonisim[100];
    printf("sonisim:");
    //gets(sonisim);
    scanf("%s",&sonisim);
    char sonisimuzantisi[255];
    strcpy(sonisimuzantisi,dosyauzantisi);
    strcat(sonisimuzantisi,sonisim);
    puts(sonisimuzantisi);


    int result = rename(ilkisimuzantisi,sonisimuzantisi);
    if (result == 0) {
        printf("The file is renamed successfully.");
    } else {
        printf("The file could not be renamed.");
    }
}

int karaktersayisioku(const char *s)
{
    int i;
    for (i = 0 ; s[i] != '\0' ; i++)
    {
        /* islem yapmadan say */
    }
    return i;
}

int dosyaolustur(char universiteuzantisi[100],char dosyaadi[100][100][100],char etiketinadi[100],int dersnumarasi,int derslerklasorununindisnumarasi)
{
    FILE *dosyalar;
    char dosyayolu[255];
    sprintf(dosyayolu,"%s%s\\\\%s.txt",universiteuzantisi,dosyaadi[derslerklasorununindisnumarasi],etiketinadi);
    printf("\ndosyayolu=%s\n",dosyayolu);
    dosyalar=fopen(dosyayolu,"w");
    if(dosyalar==NULL)
    {
        printf("Dosya olusturulamadi");
        exit(1);
    }
    printf("\ndosya olusturuldu");
    fclose(dosyalar);
    dosyalar=fopen(dosyayolu,"a");
    if(dosyalar==NULL)
    {
        printf("\nDosyaya yazilamadi");
        exit(1);
    }

        fprintf(dosyalar,"Dersin Kodu:BLM%d\n\nDersin ismi:%s\n\nDersin icerigi:",dersnumarasi,etiketinadi);
        dersnumarasi++;


    fclose(dosyalar);
    return dersnumarasi;

}

int arama1(char* dosyauzantisi)
{
    int i = 0;
    int kontrol=0;
    char buf[100];
    FILE *dosya;
    char karakter;
    for (int deneneme=0;deneneme<200;deneneme++)
    {
            if (dosyauzantisi[deneneme]=='.')
        {   kontrol=1;
            if(dosyauzantisi[deneneme+1]=='t'&&
           dosyauzantisi[deneneme+2]=='x'&&dosyauzantisi[deneneme+3]=='t')
             {
            printf("\naramayagonderilenuzantitxtdir");
            break;
             }
             else
             {
                 printf("\naramayagonderilenuzanti.lidir");
                 break;
             }

        }
    }
    if(kontrol==0)
        printf("\naramayagonderilenuzantidosyadir\n");


            dosya = fopen(dosyauzantisi, "r");
            //dosya = fopen("C:\\Users\\asus\\Desktop\\denene\\fileEVREKA.txt", "r");
            if (dosya==NULL)
            {
                printf("dosya bulunamadi");
                return 0;

            }
            else
            {
                printf("\n\n");
               while(fgets(buf, 100, dosya) != NULL )
                 {
                    //karakter=fgetc(dosya);
                    printf("%s",buf);
               }
               return 1;

            }

}

int etiketstringineat(char buf[1000],int a,int b,int etiketmatrissirasi)
{
    printf("\netiketstringineatagirdi");
    char gecicietiket[100]="";
    for(int i=a+2;i<b;i++)
    {
        printf("buf[%d]-%c   ",i,buf[i]);
        gecicietiket[i-a-2]=buf[i];
    }
     printf("\nGECICI ETIKET:%s",gecicietiket);

}

int etiketarama(char* dosyauzantisi,char etiketler[100][100],int etiketmatrissirasi)
{
   // int i = 0;
    int kontrol=0;
    char buf[1000];
    FILE *dosya;
    char karakter;
    int karaktersayisi;

    char gecicietiket[100];
    for (int deneneme=0;deneneme<200;deneneme++)
    {
            if (dosyauzantisi[deneneme]=='.')
             {
                kontrol=1;
                  if(dosyauzantisi[deneneme+1]=='t'&&
                        dosyauzantisi[deneneme+2]=='x'&&dosyauzantisi[deneneme+3]=='t')
                    {
                        //printf("\naramayagonderilenuzantitxtdir");

                        dosya = fopen(dosyauzantisi, "r");

                              if (dosya==NULL)
                             {
                                   printf("dosya bulunamadi");
                                    //return 0;

                            }
                            else
                            {
                                int satirsayisi=0;
                                //printf("\n\n");
                                while(fgets(buf, 1000, dosya) != NULL )
                                    {
                                        satirsayisi++;

                                               karaktersayisi=0;
                                               while(buf[karaktersayisi]!='\0')
                                                karaktersayisi++;
                                        for(int a=0;a<karaktersayisi;a++)
                                        {

                                            if (buf[a]=='['&& buf[a+1]=='[')
                                            {
                                                //printf("\n [[ %d de var",a+1);

                                                int b=a+2;
                                                    while(b<karaktersayisi)
                                                    {
                                                      if(buf[b]==']'&& buf[b+1]==']')
                                                       {
                                                        //printf("\n]] %d de var",b);

                                                        // 18 ekim 4:13 de burada kaldim.
                                                        //printf("\netiketstringineatagirdi");
                                                            char gecicietiket[100]="";
                                                                for(int i=a+2;i<b;i++)
                                                                {
                                                               // printf("buf[%d]-%c   ",i,buf[i]);
                                                                gecicietiket[i-a-2]=buf[i];
                                                                }
                                                                //printf("\nGECICI ETIKET:%s",gecicietiket);
                                                                strcpy(etiketler[etiketmatrissirasi],gecicietiket);
                                                                //printf("\netiketler[%d]=%s",etiketmatrissirasi,etiketler[etiketmatrissirasi]);
                                                                etiketmatrissirasi++;

                                                         //etiketstringineat(buf,a,b,etiketmatrissirasi);
                                                         break;


                                                        }
                                                      else
                                                       b++;
                                                    }



                                            }

                                        }

                                    }
                                    //return 1;

                            }



            break;
             }
             else
             {
                 //printf("\naramayagonderilenuzanti.lidir");
                 break;
             }

        }
    }
    if(kontrol==0)
        printf("");






   return etiketmatrissirasi;
}

int direntdosyalari(char* uzanti)
{
    char dosyaadi[100][100];
    int i=0;


    DIR* dir= opendir(uzanti);
    if (dir==NULL)
    {
        return 1;
    }
    struct dirent* entity;
    entity=readdir(dir);
    while(entity != NULL)
    {

        //printf("%s\n",entity->d_name);
        strcpy(dosyaadi[i],entity->d_name);
        entity=readdir(dir);
        i++;
    }
    /*printf("dosyalar\n");
    for (int j=2;i>j;j++)
        printf("%d-) %s\n",j-1,dosyaadi[j]);*/

    closedir(dir);
    return i;
}

void direntdosyalari1(char* uzanti,char dosyaadi[100][100][100])
{

    int i=0;


    DIR* dir= opendir(uzanti);
    if (dir==NULL)
    {
       printf("dir==NULL");
    }
    struct dirent* entity;
    entity=readdir(dir);
    while(entity != NULL)
    {

        //printf("%s\n",entity->d_name);
        strcpy(dosyaadi[i],entity->d_name);
        entity=readdir(dir);
        i++;
    }

    /*printf("dosyalar\n");
    for (int j=2;i>j;j++)
    {
    	printf("%d-) %s\n",j-1,dosyaadi[j]);
	}
	printf("\n\nsayi (i) :%d\n\n",i);*/


    closedir(dir);


}

void direntdosyalari2 (char* uzanti,char dosyaadi[100][100])
{

    int i=0;


    DIR* dir= opendir(uzanti);
    if (dir==NULL)
    {
       printf("dir==NULL");
    }
    struct dirent* entity;
    entity=readdir(dir);
    while(entity != NULL)
    {

        //printf("%s\n",entity->d_name);
        strcpy(dosyaadi[i],entity->d_name);
        entity=readdir(dir);
        i++;
    }




    closedir(dir);


}


int main()
{
    int dersnumarasi=200;
    int derslerklasorununindisnumarasi;
     printf("dersler klasorunun indisini giriniz:");
    scanf("%d",&derslerklasorununindisnumarasi);




    while(1)
    {
    //setlocale(LC_ALL, "Turkish");
    char uniklasoruzantisi[10][255];
    char gecicidosyaadi[100][100];
    char dosyaadi[100][100][100]; // [bölüm\dersler][dosya isimleri]
    int yapilacakislem;
    char universiteklasorununuzantisi[]="C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\";
    char arama[255];
    char aramauzantisi[255];
    int acilacakdosyanumarasi;


	direntdosyalari1("C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite",dosyaadi);
	int universitedosyasayisi=direntdosyalari("C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite");

    for(int uniklasorici=2;uniklasorici<universitedosyasayisi;uniklasorici++)
    {
        printf("\n**dosyaadi[%d]:%s**\n",uniklasorici,dosyaadi[uniklasorici]);
    	sprintf(uniklasoruzantisi[uniklasorici-2],"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\%s",dosyaadi[uniklasorici]);

    	direntdosyalari2(uniklasoruzantisi[uniklasorici-2],gecicidosyaadi);
    	int klasordosyasayisi=direntdosyalari(uniklasoruzantisi[uniklasorici-2]);

    	for(int i=2;i<klasordosyasayisi;i++)
        {

            strcpy(dosyaadi[uniklasorici][i],gecicidosyaadi[i]);
        }

        for(int i=2;i<klasordosyasayisi;i++)
        {
            printf("dosya:[%d][%d]-)%s\n",uniklasorici,i,dosyaadi[uniklasorici][i]);
        }


        strcpy(gecicidosyaadi[uniklasorici],"");


	}


    char etiketler[100][100];
    int etiketmatrissirasi=0;

    for(int klasornumarasi=2;klasornumarasi<universitedosyasayisi;klasornumarasi++)
    {
        char etiketaramauzantisi[255];
        char etiketsayisiaramauzantisi[255];
        sprintf(etiketsayisiaramauzantisi,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\%s",dosyaadi[klasornumarasi]);
        int kacdosyavar=direntdosyalari(etiketsayisiaramauzantisi);
        for(int dosyanumarasi=2;dosyanumarasi<kacdosyavar;dosyanumarasi++)
        {
            sprintf(etiketaramauzantisi,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\%s\\\\%s",dosyaadi[klasornumarasi],dosyaadi[klasornumarasi][dosyanumarasi]);

            etiketmatrissirasi=etiketarama(etiketaramauzantisi,etiketler,etiketmatrissirasi);



        }

    }


    char duzenlietiketler[100][100];
    int duzenlietiketmatrissirasi=1;
    int kontrol1;

    for(int kiyasla=0;kiyasla<etiketmatrissirasi;kiyasla++)
    {
        kontrol1=0;
        for(int kiyasla2=0;kiyasla2<duzenlietiketmatrissirasi;kiyasla2++)
        {

            if(strcmp(etiketler[kiyasla],duzenlietiketler[kiyasla2])==0)
            {
               kontrol1++;
               break;
            }


        }
        if(kontrol1==0)
        {
            strcpy(duzenlietiketler[duzenlietiketmatrissirasi-1],etiketler[kiyasla]);
            duzenlietiketmatrissirasi++;
        }


    }
    for(int asd=0;asd<duzenlietiketmatrissirasi-1;asd++)
    printf("\n----etiketler[%d]=%s",asd,duzenlietiketler[asd]);


    //duzenli etiket sayisi duzenlietiketmatrisi-1 tanedir

    //19 ekim 17:55 da burada kaldim

    char yetimetiketler[100][100];
    int yetimetiketmatrissirasi=0;
    char derslerklasoruuzantisi[255];
    char kiyaslancaketiket[100];
    int kontrol2=0;

    sprintf(derslerklasoruuzantisi,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\%s",dosyaadi[derslerklasorununindisnumarasi]);

    int derslerklasorundekidosyasayisi=direntdosyalari(derslerklasoruuzantisi);


    for(int s1=0;s1<duzenlietiketmatrissirasi-1;s1++)
    {
        kontrol2=0;
        sprintf(kiyaslancaketiket,"%s.txt",duzenlietiketler[s1]);
       for(int s2=2;s2<derslerklasorundekidosyasayisi;s2++)
       {

           if(strcmp(kiyaslancaketiket,dosyaadi[derslerklasorununindisnumarasi][s2])==0)
            break;
           if(s2==derslerklasorundekidosyasayisi-1)
            kontrol2=1;
       }
       if(kontrol2==1)
       {
           strcpy(yetimetiketler[yetimetiketmatrissirasi],duzenlietiketler[s1]);
           yetimetiketmatrissirasi++;
       }
    }
    printf("\n");
    for(int denemeler=0;denemeler<yetimetiketmatrissirasi;denemeler++)
    {
        printf("\nyetimetiket[%d]= %s",denemeler,yetimetiketler[denemeler]);
    }

    int kontrol3=0;
    char istenenetiketkontrol[100];
    char istenenetiketler[100][100];
    int istenenetiketmatrissayisi=0;
    int karaktersayisi=0;
    char uzantisizdersdosyalari[100][100];
    int uzantisizdersdosyalarimatrisboyutu=0;

    for(int s1=2;s1<derslerklasorundekidosyasayisi;s1++)
    {


        for(int s2=0;s2<100;s2++)
        {

            if(dosyaadi[derslerklasorununindisnumarasi][s1][s2]=='.'&&dosyaadi[derslerklasorununindisnumarasi][s1][s2+1]=='t'&&dosyaadi[derslerklasorununindisnumarasi][s1][s2+2]=='x'&&dosyaadi[derslerklasorununindisnumarasi][s1][s2+3]=='t')
            {

                memcpy(uzantisizdersdosyalari[uzantisizdersdosyalarimatrisboyutu],dosyaadi[derslerklasorununindisnumarasi][s1],sizeof(char)*s2);

                uzantisizdersdosyalarimatrisboyutu++;

                break;
            }

        }

    }

    for (int s1=0;s1<uzantisizdersdosyalarimatrisboyutu;s1++)
    {

        kontrol3=0;
        for(int s2=0;s2<duzenlietiketmatrissirasi-1;s2++)
        {
            if(strcmp(uzantisizdersdosyalari[s1],duzenlietiketler[s2])==0)
            {
                kontrol3=1;
                break;
            }


        }
        if(kontrol3==0)
        {
            strcpy(istenenetiketler[istenenetiketmatrissayisi],uzantisizdersdosyalari[s1]);
            istenenetiketmatrissayisi++;

        }
    }


    printf("\n");
    for (int denemeler2=0;denemeler2<istenenetiketmatrissayisi;denemeler2++)
        printf("\nistenenetiketler[%d]=%s",denemeler2,istenenetiketler[denemeler2]);


    printf("\n\n*****   DOKUWIKI    *****\n\n");
    printf("Yapmak istediğiniz işlemi giriniz \n");
    printf("\nDosya Adı güncelleme:1\nDosya açma(yazı ile):2\nDosya açma(indis ile):3\nyetim etikete dosya ekleme:4\nOutput yazdırma:5\nKelime veya Etiket arama:6\nGüncelleme(çalışmıyor):7\n\n");
    scanf("%d",&yapilacakislem);


    if (yapilacakislem==1)
    {
        char guncellemeuzantisi[255];
        int klasornumarasi;
        printf("guncellencek dosyanýn klasorunu seçin:");
        scanf("%d",&klasornumarasi);
        printf("%s",dosyaadi[klasornumarasi+1]);
        sprintf(guncellemeuzantisi,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\%s\\\\",dosyaadi[klasornumarasi]);
        printf("guncellemeuzantisi:%s",guncellemeuzantisi);
        yenidenisimlendir(guncellemeuzantisi);
    }



    if(yapilacakislem==2)
        {
            int girilecekdosyaninumarasi;



            printf("girilecek dosyayı seciniz\n%s:1\n%s:2\n\n",dosyaadi[2],dosyaadi[3]);
            scanf("%d",&girilecekdosyaninumarasi);
            printf("aramanız:");
            scanf("%s",&arama);
            printf("\ndosyaadi[girilecekdosyaninumarasi]:%s\n",dosyaadi[girilecekdosyaninumarasi]);
            strcpy(aramauzantisi,universiteklasorununuzantisi);
            printf("\naramauzantisi:%s",aramauzantisi);
            strcat(aramauzantisi,dosyaadi[girilecekdosyaninumarasi]);
              printf("\naramauzantisi:%s",aramauzantisi);
            strcat(aramauzantisi,"\\\\");
              printf("\naramauzantisi:%s",aramauzantisi);
            strcat(aramauzantisi,arama);
              printf("\naramauzantisi:%s",aramauzantisi);
            strcat(aramauzantisi,".txt");
              printf("\naramauzantisi:%s",aramauzantisi);
            arama1(aramauzantisi);

        }


       if (yapilacakislem==3)
       {

           int secilecekdosya,secilecekdosyasirasi;
           int dosyami=0;
           printf("\naçilacak dosya sırasını seçiniz:");
           scanf("%d",&secilecekdosya);
           printf("\naçilacak text dosyasının sırasını seciniz:");
           scanf("%d",&secilecekdosyasirasi);

           char direktuzanti[255];
           sprintf(direktuzanti,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\%s\\\\%s",dosyaadi[secilecekdosya],dosyaadi[secilecekdosya][secilecekdosyasirasi]);
           printf("\ndirektuzanti:%s",direktuzanti);
           arama1(direktuzanti);

       }

       if(yapilacakislem==4)
       {
           printf("\ndosyasýný eklemek istediðiniz yetim etiketi seçiniz;");
           for(int yetimsira=0;yetimsira<yetimetiketmatrissirasi;yetimsira++)
           {
               printf("\n yetimetiketler [%d]=%s",yetimsira,yetimetiketler[yetimsira]);
           }
           int secilecekyetimetiket;
           scanf("%d",&secilecekyetimetiket);
           dersnumarasi=dosyaolustur(universiteklasorununuzantisi,dosyaadi,yetimetiketler[secilecekyetimetiket],dersnumarasi,derslerklasorununindisnumarasi);


       }

       if(yapilacakislem==5)
       {
           FILE *dosya;
           char outputdosyauzantisi[255];
           int etikettekrarsayisi;
           int outputindisi;
           printf("\n output indisi girin=");
           scanf("%d",&outputindisi);
           sprintf(outputdosyauzantisi,"%s%s",universiteklasorununuzantisi,dosyaadi[outputindisi]);
           printf("outputdosyauzantisi:%s\n",outputdosyauzantisi);

            dosya=fopen(outputdosyauzantisi,"w");
            if (dosya==NULL)
            {
                printf("Output.txt FAILED");
                exit(1);
            }

            fputs(" {etiket listesi} : {tekrar sayisi}\n\n",dosya);
            fclose(dosya);

           for (int s1=0;s1<duzenlietiketmatrissirasi-1;s1++)
           {
               etikettekrarsayisi=0;
               for (int s2=0;s2<etiketmatrissirasi;s2++)
               {
                   if(strcmp(duzenlietiketler[s1],etiketler[s2])==0)
                    etikettekrarsayisi++;
               }
               dosya=fopen(outputdosyauzantisi,"a");
               if(dosya==NULL)
                {
                printf("\nDosyaya yazilamadi a FAILED\n");
                exit(1);
                }
                fprintf(dosya,"%s : %d\n\n",duzenlietiketler[s1],etikettekrarsayisi);
                fclose(dosya);
           }
           dosya=fopen(outputdosyauzantisi,"a");
           if(dosya==NULL)
                {
                printf("\nDosyaya yazilamadi a FAILED\n");
                exit(1);
                }
           fprintf(dosya,"\n\nYetimetiketler");
           for(int s1=0;s1<yetimetiketmatrissirasi;s1++)
           {
               fprintf(dosya,"\n%s",yetimetiketler[s1]);
           }
           fclose(dosya);
       }


       if(yapilacakislem==6)
       {
           //Etiket ve kelime arama
           FILE *etiketdosya;
           char satir[1000];

           for(int asd=0;asd<duzenlietiketmatrissirasi-1;asd++)
            printf("\n----etiketler[%d]=%s",asd,duzenlietiketler[asd]);
           for(int denemeler=0;denemeler<yetimetiketmatrissirasi;denemeler++)
            {
        printf("\nyetimetiket[%d]= %s",denemeler,yetimetiketler[denemeler]);
            }
            printf("\n");
            for (int denemeler2=0;denemeler2<istenenetiketmatrissayisi;denemeler2++)
            printf("\nistenenetiketler[%d]=%s",denemeler2,istenenetiketler[denemeler2]);

           char aranacakstring[100];
           printf("\n\nAramanizi girin:");
           scanf("%s",aranacakstring);


           int aranacakstringetiketmi=0;

           for(int s1=0;s1<duzenlietiketmatrissirasi-1;s1++)
           {
               if(strcmp(aranacakstring,duzenlietiketler[s1])==0)
               {
                   printf("\nAranan kelime bir etikettir\n Eğer etiket aramak isterseniz ::1 \n kelime aramak isterseniz:0\n===");
                   scanf("%d",&aranacakstringetiketmi);
                   break;
               }

           }
           if(aranacakstringetiketmi==1)
           {
               char geciciaranacakstring[100];
               sprintf(geciciaranacakstring,"[[%s]]",aranacakstring);
               strcpy(aranacakstring,geciciaranacakstring);


           }

           if(aranacakstringetiketmi==0)
           {
               char geciciaranacakstring[100];
               sprintf(geciciaranacakstring,"%s ",aranacakstring);
               strcpy(aranacakstring,geciciaranacakstring);


           }


           for(int s1=2;s1<universitedosyasayisi;s1++)
            {
                char kacdosyavar2uzantisi[255];
                sprintf(kacdosyavar2uzantisi,"%s%s",universiteklasorununuzantisi,dosyaadi[s1]);
            int kacdosyavar2=direntdosyalari(kacdosyavar2uzantisi);

            char etiketveyakelimearamauzantisi[255];
            for(int s2=2;s2<kacdosyavar2;s2++)
                {
                    sprintf(etiketveyakelimearamauzantisi,"%s%s\\\\%s",universiteklasorununuzantisi,dosyaadi[s1],dosyaadi[s1][s2]);

                    etiketdosya=fopen(etiketveyakelimearamauzantisi,"r");

                         if (etiketdosya==NULL)
                             {
                                   printf("\n dosya bulunamadı : \nuzantı%s\ndosyaadi[%d][%d]=%s\n",etiketveyakelimearamauzantisi,s1,s2,dosyaadi[s1][s2]);

                            }
                            int satirsayisi=0;

                            while(fgets(satir, 1000, etiketdosya) != NULL )
                                {
                                    satirsayisi++;
                                  int satirkaraktersayisi=karaktersayisioku(satir);

                                  int aranacakstringkaraktersayisi=karaktersayisioku(aranacakstring);


                                    for (int s3= 0 ; s3 <= satirkaraktersayisi-aranacakstringkaraktersayisi ; s3++)
                                        {

                                            int s4;
                                            for (s4 = 0 ; s4 < aranacakstringkaraktersayisi ; s4++)
                                            {

                                                if (satir[s3+s4] != aranacakstring[s4])
                                                {

                                                    break;
                                                }

                                            }// eger j == aranan_N olduysa:j dongusu bitmis ve aranan_N tanesi aynidir
                                             if (s4 == aranacakstringkaraktersayisi)
                                              printf("\nKlasorü:%s    Dosyasi:%s    Satir:%d  Arama:%s",dosyaadi[s1], dosyaadi[s1][s2],satirsayisi,aranacakstring);
                                        }

                                }
                }
            }
       }

       if(yapilacakislem==7)
       {
           int guncellenceketiketinindisi;
           char yerinekoyulacaketiket[100];
           char satir2[1000];
           char gunceldosyaici[100][1000];
           printf("\nGUNCELLEME\n");
           for (int s1=0;s1<duzenlietiketmatrissirasi;s1++)
           {
               printf("\netiketler[%d]=%s",s1,duzenlietiketler[s1]);
           }

           printf("\nGuncellencek etiketin indisini giriniz:\n");
           scanf("%d",&guncellenceketiketinindisi);
           printf("\nyerine yazilacak yaziyi giriniz:\n");
           scanf("%s",yerinekoyulacaketiket);
           char ilkisimuzantisi[255];
           sprintf(ilkisimuzantisi,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\Dersler\\\%s",duzenlietiketler[guncellenceketiketinindisi]);
           char sonisimuzantisi[255];
           sprintf(sonisimuzantisi,"C:\\\\Users\\\\asus\\\\Desktop\\\\Üniversite\\\\Dersler\\\%s",yerinekoyulacaketiket);

            int result = rename(ilkisimuzantisi,sonisimuzantisi);
            if (result == 0)
            {
                printf("The file is renamed successfully.");
            }
            else
            {
                printf("The file could not be renamed.");
            }

            char guncellenceketiket[100];
           strcpy(guncellenceketiket,duzenlietiketler[guncellenceketiketinindisi]);

            strcpy(duzenlietiketler[guncellenceketiketinindisi],yerinekoyulacaketiket);



           printf("\nguncellenecek etiket=%s",guncellenceketiket); //isaretci

           FILE *etiketguncellemedosya;

           for(int s1=2;s1<universitedosyasayisi;s1++)
           {

               char kacdosyavar3uzantisi[255];
               sprintf(kacdosyavar3uzantisi,"%s%s",universiteklasorununuzantisi,dosyaadi[s1]);

                int kacdosyavar3=direntdosyalari(kacdosyavar3uzantisi);

                char etiketguncellemeuzantisi[255];
                for(int s2=2;s2<kacdosyavar3;s2++)
                {

                    sprintf(etiketguncellemeuzantisi,"%s%s\\\\%s",universiteklasorununuzantisi,dosyaadi[s1],dosyaadi[s1][s2]);

                    etiketguncellemedosya=fopen(etiketguncellemeuzantisi,"r");
                    if (etiketguncellemedosya==NULL)
                             {
                                   printf("\n dosya bulunamadi : \nuzanti%s\ndosyaadi[%d][%d]=%s\n",etiketguncellemeuzantisi,s1,s2,dosyaadi[s1][s2]);

                            }
                            int satirsayisi2=0;
                            while(fgets(satir2,1000,etiketguncellemedosya)!=NULL)
                            {

                                int satir2karaktersayisi=karaktersayisioku(satir2);

                                int guncellenceketiketkaraktersayisi=karaktersayisioku(guncellenceketiket);

                                int dosyaicikaraktersayaci=0;
                                for (int s3=0;s3<satir2karaktersayisi;s3++)
                                {

                                    int s4;
                                    if(s3<satir2karaktersayisi-guncellenceketiketkaraktersayisi)
                                    {
                                        for(s4=0;s4<guncellenceketiketkaraktersayisi;s4++)
                                        {
                                            if(satir2[s3+s4]!=guncellenceketiket[s4])
                                            {
                                                gunceldosyaici[satirsayisi2][dosyaicikaraktersayaci]=satir2[s3];
                                                dosyaicikaraktersayaci++;
                                                break;
                                            }

                                        }
                                        if(s4==guncellenceketiketkaraktersayisi)
                                            {
                                                int yerinekoyulacaketiketinkaraktersayisi=karaktersayisioku(yerinekoyulacaketiket);
                                                for(int s5=0;s5<yerinekoyulacaketiketinkaraktersayisi;s5++)
                                                {
                                                    gunceldosyaici[satirsayisi2][dosyaicikaraktersayaci]=yerinekoyulacaketiket[s5];
                                                    dosyaicikaraktersayaci++;
                                                }
                                                s3=s3+guncellenceketiketkaraktersayisi;

                                            }
                                    }

                                }
                                satirsayisi2++;
                            }
                            fclose(etiketguncellemedosya);

                            printf("\nGUNCELDOSYAIÇI    :   %s\n\n",dosyaadi[s1][s2]);

                            for(int bastir1=0;bastir1<satirsayisi2+1;bastir1++)
                            {
                                printf("%s\n",gunceldosyaici[bastir1]);
                            }

                }

           }

       }
       int menuyegitmekicin;
       printf("\n\n\nMenüye gitmek için herhangi bir int değer girin");
       scanf("%d",&menuyegitmekicin);


    }

//23 ekim 17:32 yorum satýrlarý silinecek. türkçe karakter düzenlemesi yapýlacak
//23 ekim 6:26 de kaldim. istenen etiket problemi var. Yetim etiketin ismi gidiyor. guncelleme hatali. Menu yapilcak
    return 0;
}
