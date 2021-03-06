#include <16F877.h>

#FUSES NOWDT              //Watch Dog Timer Kullanma
#FUSES XT                 //Kristal  Osilat�r ile CLKOUT
#FUSES NOPUT              //Power Up Timer Kullanma
#FUSES NOPROTECT          //Rom'a Yaz�lan Veriler Okunabilir
#FUSES NOBROWNOUT         //Brownout Reset Kullanma
#FUSES NOLVP              //D���k Gerilimler ile Programlamay� Kapt
#FUSES NOCPD              //Data EEPROM Korumas�z
#FUSES NOWRT              //Program Belle�i Yazmaya A��k
#FUSES NODEBUG            //ICD i�in Hata Ay�klama Modu Kapal�

#use delay(clock=4000000)

#use fast_io(b)

#define data pin_b0
#define clock pin_b1

int i,j;

int dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};
void main()
{
   setup_psp(PSP_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   set_tris_b(0x00);
   
   output_b(0x00);
   
   while(1)
   {
      for(i=0;i<10;i++) // 10 elemanl� dizinin b�t�n elamanlar�n gezicektir.
       {
         for(j=0;j<8;j++)// 0 dan 8. bitine kadar kontrol edilmektedir.
         {
            output_bit(data,bit_test(dizi[i],j));//bit_test(dizi[i],j) ile dizinin i. eleman�n j. biti ��renilmi�tir.
                                       // oda pin B0 g�nderilmi�tir.
         output_high(clock);// clock 1
            output_low(clock);// clock 0 yap�lm�� ve 1 pulse verilmi�tir.
            
            /* i=0 da j=0,1,2,3,4,5,6,7 ye sayarken  data=pin b0'a 
            bit_test(diz[i],j) komutu ile her pulse'de j dizinin her elaman�n�n her bitini gezecek ve 
            8. turun her sonunda 741164'e dizinin i�indebir eleman�n� tamamlam�� olacakt�r i=10 oldu�unda b�t�n elamanlar yaz�lm�� olur*/
         }
         
         delay_ms(500);
       }
   }
}


