#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char isim [27][30];//genel deðiþkenlerin tanýmý
char soyisim[27][30];
int sifre[27];
int numara[27];
int  girilenSifre , girilenNo;


int gecikme (int);//sayfalarýn gecikmesini saðlayan fonksiyon
int harfNotu(float x);//girilen ortalamaya göre harf notu bastýran fonksiyon
int menu ();//ana menü fonksiyonu

int main (void)
{//main baþý
	
	int giris , i=0 , donus;//deðiþken tanýmý
	
	
	printf("\n\n\t\t%s OGRENCI SISTEMINE HOS GELDINIZ.\n\n","BEYKOZ UNIVERSITESI");
	gecikme(2);
	system("cls");

	do{//do while baþý
		printf( "\n\n\t\tOGRENCI ADI : " ) ;//bilgilerin alýnýp kayýt iþleminin gerçekleþtirilmesi
		scanf( "%s" , &isim[i] ) ;
		printf( "\n\t\tOGRENCI SOYADI : " );
		scanf( "%s" , &soyisim[i]) ;
		printf( "\n\t\tOGRENCI NUMARASI : " );
		scanf( "%d" , &numara[i] );
		printf("\n\t\tOGRENCI SISTEMI SIFRE : ");
		scanf("%d",&sifre[i] );
		printf( "\n\t\tOGRENCININ SIRA NUMARASI %d \n\t\tOGRENCILER SISTEME BU SIRA NUMARASI VE SIFRE ILE GIRIS YAPACAKTIR." , i);
		i++;
		printf("\n\t\tYeni kayit yapacak misiniz?(Devam:1/Giris Ekrani:-1)\n");
		scanf("\t\t\t%d" , &giris);
	}while(giris == 1);//do while sonu
		
		KAYIT://goto label
		system("cls");
		printf("\n\n\t\tGIRIS YAP\n\t\tSira no : ");//giriþ yapma bölümü
		scanf("%d" , &girilenNo);
		printf("\n\t\tSifre : ");
		scanf("%d" , &girilenSifre);
		
		if(girilenSifre == sifre[girilenNo])//þifrenin doðruluðunun kontrolü
		{
			system("cls");
			printf("\n\n\t\tBasariyla giris yaptiniz.");
			gecikme(2);
			system("cls");
			menu();//giriþ baþarýlý ise ana menü fonksiyonunun çaðýrýlmasý
			
		}
		
		else
		{
			system("cls");
			printf("Hatali giris yaptiniz");
			gecikme(2);
			goto KAYIT;
		}
}//main sonu

int gecikme (int sn)
{//gecikme fonksiyonu baþý
	//zamaný milisaniyelere çevirir 
    int miliSn = 1000 * sn; 
  
    //zamaný tutar
    clock_t baslat = clock(); 
  
    //istenilen zamana gelene kadar döngü döndürür 
    while (clock() < baslat + miliSn) 
        ; 
}//gecikme fonksiyonu sonu

int menu ()
{//ana menü fonksiyonu
	int menuGiris , dersGiris , donus , i;//deðiþken tanýmlama
	int trNotlari[6] , fizikNotlari[6] , calculusNotlari[6] , ingNotlari[6] , labNotlari[6] , ictNotlari[6] , introNotlari[6];
	float ortTr , ortFizik , ortCalculus , ortIng , ortLab , ortIct , ortIntro;
	
	srand(time(NULL));
	
	for(i=0;i<=5;i++)//random  notlarý tanýmlama
	{
		fizikNotlari[i]=rand()%101;
		calculusNotlari[i]=rand()%101;
		introNotlari[i]=rand()%101;
		ictNotlari[i]=rand()%101;
		labNotlari[i]=rand()%101;
		ingNotlari[i]=rand()%101;
		trNotlari[i]=rand()%101;
	}
	
	int fizikDevam=rand()%21;//random devamsýzlýk tanýmlama
	int calculusDevam=rand()%21;
	int introDevam=rand()%21;
	int ictDevam=rand()%21;
	int labDevam=rand()%21;
	int ingDevam=rand()%21;

	int bursMiktari=rand()%3;//random burs miktarý tanýmlama

	ANAMENU:
	system("cls");
	printf("BEYOZ UNIVERSITESI OGRENCI SISTEMINE HOS GELDINIZ\n\n***********************MENU***********************\n*********************1-NOTLAR*********************\n******************2-DEVAMSIZLIK*******************\n*****************3-UCRETLENDIRME******************\n\n\n");
	printf("Giris yapmak istediginiz bolumun numarasini tuslayin : ");
	scanf("%d",&menuGiris);
	
	if(menuGiris==1)//ana menüde notlar bölümü
	{//if baþý
		NOTLAR:
		system("cls");
		printf("BEYOZ UNIVERSITESI OGRENCI SISTEMINE HOS GELDINIZ\n\n\t\t1-FIZIK\n\n\t\t2-DIFERANSIYEL VE INTEGRAL HESABI\n\n\t\t3-PROGRAMLAMAYA GIRIS\n\n\t\t4-BILGI VE ILETISIM TEKNOLOJILERI\n\n\t\t5-FIZIK LABORATUVARI\n\n\t\t6-INGILIZCE\n\n\t\t7-TURK DILI\n\n");
		printf("Notlarinizi gormek istediginiz dersin numarasini tuslayin : ");
		scanf("%d",&dersGiris);
		
		if(dersGiris==1)//fizik dersi notlarý bölümü
		{
			system("cls");
			printf("|---------------FIZIK NOTLARINIZ---------------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , fizikNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , fizikNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , fizikNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , fizikNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , fizikNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , fizikNotlari[5]);
			
			ortFizik=(float)(fizikNotlari[0]*(0.1))+(fizikNotlari[1]*(0.1))+(fizikNotlari[2]*(0.05))+(fizikNotlari[3]*(0.05))+(fizikNotlari[4]*(0.2))+(fizikNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortFizik);
			harfNotu(ortFizik);
			
			if(fizikDevam>13)
			printf("\n\t\t|------DEVAMSIZLIKTAN KALDINIZ!------|");
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else if(dersGiris==2)//kalkülüs dersi notlarý bölümü
		{
			system("cls");
			printf("|----------DIFERANSIYEL VE INTEGRAL HESABI NOTLARINIZ----------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , calculusNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , calculusNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , calculusNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , calculusNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , calculusNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , calculusNotlari[5]);
			
			ortCalculus=(float)(calculusNotlari[0]*(0.1))+(calculusNotlari[1]*(0.1))+(calculusNotlari[2]*(0.05))+(calculusNotlari[3]*(0.05))+(calculusNotlari[4]*(0.2))+(calculusNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortCalculus);
			harfNotu(ortCalculus);
			
			if(calculusDevam>13)
			printf("\n\t\t|------DEVAMSIZLIKTAN KALDINIZ!------|");
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else if(dersGiris==3)//programlamaya giriþ dersi notlarý bölümü
		{
			system("cls");
			printf("|----------PROGRAMLAMAYA GIRIS NOTLARINIZ----------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , introNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , introNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , introNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , introNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , introNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , introNotlari[5]);
			
			ortIntro=(float)(introNotlari[0]*(0.1))+(introNotlari[1]*(0.1))+(introNotlari[2]*(0.05))+(introNotlari[3]*(0.05))+(introNotlari[4]*(0.2))+(introNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortIntro);
			harfNotu(ortIntro);
			
			if(introDevam>18)
			printf("\n\t\t|------DEVAMSIZLIKTAN KALDINIZ!------|");
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else if(dersGiris==4)//bilgi ve iletiþim teknolojileri dersi notlarý bölümü
		{
			system("cls");
			printf("|----------BILGI VE ILETISIM TEKNOLOJILERI NOTLARINIZ----------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , ictNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , ictNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , ictNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , ictNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , ictNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , ictNotlari[5]);
			
			ortIct=(float)(ictNotlari[0]*(0.1))+(ictNotlari[1]*(0.1))+(ictNotlari[2]*(0.05))+(ictNotlari[3]*(0.05))+(ictNotlari[4]*(0.2))+(ictNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortIct);
			harfNotu(ortIct);
			if(ictDevam>18)
			printf("\n\t\t|------DEVAMSIZLIKTAN KALDINIZ!------|");
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else if(dersGiris==5)//fizik laboratuvarý dersi notlarý bölümü
		{
			system("cls");
			printf("|---------------FIZIK LABORATUVARI NOTLARINIZ---------------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , labNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , labNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , labNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , labNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , labNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , labNotlari[5]);
			
			ortLab=(float)(labNotlari[0]*(0.1))+(labNotlari[1]*(0.1))+(labNotlari[2]*(0.05))+(labNotlari[3]*(0.05))+(labNotlari[4]*(0.2))+(labNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortLab);
			harfNotu(ortLab);
			if(labDevam>12)
			printf("\n\t\t|------DEVAMSIZLIKTAN KALDINIZ!------|");
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else if(dersGiris==6)//ingilizce dersi notlarý bölümü
		{
			system("cls");
			printf("|---------------INGILIZCE NOTLARINIZ---------------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , ingNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , ingNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , ingNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , ingNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , ingNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , ingNotlari[5]);
			
			ortIng=(float)(ingNotlari[0]*(0.1))+(ingNotlari[1]*(0.1))+(ingNotlari[2]*(0.05))+(ingNotlari[3]*(0.05))+(ingNotlari[4]*(0.2))+(ingNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortIng);
			harfNotu(ortIng);
			if(ingDevam>9)
			printf("\n\t\t|------DEVAMSIZLIKTAN KALDINIZ!------|");
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else if(dersGiris==7)//türk dili dersi notlarý bölümü
		{
			system("cls");
			printf("|---------------TURK DILI NOTLARINIZ---------------|\n\n");
			printf("\t\t(%s)1.PROJE : %d\n", "%10" , trNotlari[0]);
			printf("\t\t(%s)2.PROJE : %d\n", "%10" , trNotlari[1]);
			printf("\t\t(%s)1.KUCUK SINAV : %d\n","%5" , trNotlari[2]);
			printf("\t\t(%s)2.KUCUK SINAV : %d\n", "%5" , trNotlari[3]);
			printf("\t\t(%s)ARA SINAV : %d\n", "%20" , trNotlari[4]);
			printf("\t\t(%s)FINAL SINAV : %d\n", "%50" , trNotlari[5]);
			
			ortTr=(float)(trNotlari[0]*(0.1))+(trNotlari[1]*(0.1))+(trNotlari[2]*(0.05))+(trNotlari[3]*(0.05))+(trNotlari[4]*(0.2))+(trNotlari[5]*(0.5));
			printf("\t\tORTALAMANIZ : %.2f\n",ortTr);
			harfNotu(ortTr);
			
			printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)\n(Ana menuye donmek icin-2)");
			scanf("%d",&donus);
			if(donus==1)
			goto NOTLAR;
			if(donus==2)
			goto ANAMENU;
		}
		else
		{
			//system("cls");
			printf("Hatali giris yaptiniz.(Girmek istediginiz bolumun numarasini giriniz)");
			gecikme(1);
			int dersGiris=0;
			goto NOTLAR;
		}
	}//if sonu
	else if(menuGiris==2)//ana menüde devamsýzlýk bölümü
	{//else if baþý	
		system("cls");
		printf("\tBEYOZ UNIVERSITESI OGRENCI SISTEMINE HOS GELDINIZ");
		printf("\n\n\t\tDERS\t\t\t\t\tDEVAMSIZLIK DURUMU");
		printf("\n\n\t\t1-FIZIK\t\t\t\t\t%d" , fizikDevam);
		printf("\n\t\t2-DIFERANSIYEL VE INTEGRAL HESABI\t%d" , calculusDevam);
		printf("\n\t\t3-PROGRAMLAMAYA GIRIS\t\t\t%d" , introDevam);
		printf("\n\t\t4-BILGI VE ILETISIM TEKNOLOJILERI\t%d" , ictDevam);
		printf("\n\t\t5-FIZIK LABORATUVARI\t\t\t%d" , labDevam);
		printf("\n\t\t6-INGILIZCE\t\t\t\t%d" , ingDevam);
		printf("\n\t\t7-TURK DILI\t\t\t\t%s" , "ONLINE DERS");
		
		printf("\nBir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)");
		scanf("%d",&donus);
		if(donus==1)
			goto ANAMENU;
	}//else if sonu
	else if(menuGiris==3)//ana menü ücretlendirme bölümü
	{//else if baþý
		system("cls");
		printf("\n\n|----------%s %s ait ucretlendirme bilgileri----------|\n\n" , &isim[girilenNo] , &soyisim[girilenNo]);
		
		if(bursMiktari==0)
		printf("Burs miktariniz : %s\n\nTOPLAM TUTAR\tTAKSIT MIKTARI\tKALAN TAKSIT\n|--20000--|\t|----10----|\t|----5----|\n\n","%50");
		if(bursMiktari==1)
		printf("Burs miktariniz : %s\n\nTOPLAM TUTAR\tTAKSIT MIKTARI\tKALAN TAKSIT\n|--10000--|\t|----10----|\t|----5----|\n\n","%75");
		if(bursMiktari==2)
		printf("Burs miktariniz : %s\n\n","%100");
		
		printf("Bir ust menuye donmek istiyor musunuz?(Evet:1/Hayir:-1)");
		scanf("%d",&donus);
		if(donus==1)
			goto ANAMENU;
		
	}//else if sonu
	else
	{
		printf("Hatali Giris Yaptiniz.(Girmek istediginiz bolumun basindaki numarayi giriniz.)");
		gecikme(2);
		goto ANAMENU;
	
	}
}//ana menü fonksiyonu sonu


int harfNotu(float x)
{//harf notu fonksiyonu baþý
	if(x<=35)
	{
		printf("\t\tHARF NOTUNUZ : FF");
	
	}
	else if(x>35 && x<=49)
	{
		printf("\t\tHARF NOTUNUZ : FD");
	}
	else if(x>49 && x<=54)
	{
		printf("\t\tHARF NOTUNUZ : DD");
	}
	else if(x>54 && x<=59)
	{
		printf("\t\tHARF NOTUNUZ : DC");
	}
	else if(x>59 && x<=65)
	{
		printf("\t\tHARF NOTUNUZ : CC");
	}
	else if(x>65 && x<=72)
	{
		printf("\t\tHARF NOTUNUZ : CB");
	}
	else if(x>72 && x<=79)
	{
		printf("\t\tHARF NOTUNUZ : BB");
	}
	else if(x>79 && x<=89)
	{
		printf("\t\tHARF NOTUNUZ : BA");
	}
	else if(x>89 && x<=100)
	{
		printf("\t\tHARF NOTUNUZ : AA");
	}
}//harf notu fonksiyonu baþý
