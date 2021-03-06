#include <16F877.h>

#FUSES NOWDT              //Watch Dog Timer Kullanma
#FUSES RC                 //Resistor/Capacitor Osilat�r ile CLKOUT
#FUSES NOPUT              //Power Up Timer Kullanma
#FUSES PROTECT            //Rom'a Yaz�lan Verilerin Okunamas�n� Engelle
#FUSES NOBROWNOUT         //Brownout Reset Kullanma
#FUSES NOLVP              //D���k Gerilimler ile Programlamay� Kapt
#FUSES NOCPD              //Data EEPROM Korumas�z
#FUSES NOWRT              //Program Belle�i Yazmaya A��k
#FUSES NODEBUG            //ICD i�in Hata Ay�klama Modu Kapal�

/*Programda zamanlama kullan�lacaksa*/
#use delay(clock=4000000) 

/*Port y�nlendirme yap�l�yor */
#use fast_io(b)


void main()
{
/*Genel Pic de b�lmlerinin ayarlamalar� yap�l�yor*/
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);

/* A pinleri a0 giri� lojik-1 hari� lojik-0 ��k��  yap�l�yor*/
set_tris_b(0x00);
/* B portu giri� lojik-1 yap�l�yor*/
output_b(0x11);
// b portun t�m pinleri enerjilendi
}
