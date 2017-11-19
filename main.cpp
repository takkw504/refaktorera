
/*Detta program är en räknare som kan användas för ellära med enbart växelspänningar och växelströmmar. Räknaren
tar upp räkning med spänningar i volt(U), resistanser upp till 20 000/ohm(R).
Ström upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
Även tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas där cosinus fi/cosinus() används
som effektfaktorn som är mindre än 1 och inte mindre än 0.
Frekvenser i (Hz):  och totala motståndet i parallellkopplade kretsar med max 3 motstånd.

50 Hertz(Hz) Finns det i våra uttag i sverige Vid 50 Hz byter ­spänningen polaritet och strömmen riktning 100 gånger per
sekund. Spänningen i svenska eluttag pendlar upp och ner från -325 V till +325 V. Att vi talar om 230 V beror på att det
är spänningens(växelström ~) effektivvärde eller roten ur. Spänningen V(U)=Toppvärdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Spänning i volt(U)=Resistans i ohm(R)*Ström i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL för likström: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()

*/

//#include <iostream>
#include "interface.h"
#include <iostream>


int main(void) {
  system("cls");

  int selected;
  while(1) {
    disp_menu();
    std::cin >> selected;
    disp_choice(selected);
    if(selected == 0) break;
    if(selected == 1 && ohm() == false) continue;
    if(selected == 2 && rtot() == false) continue;
    if(selected == 3 && power() == false) continue;
    if(selected == 4 && apparent_power_sp() == false) continue;
    if(selected == 5 && active_power_sp() == false) continue;
    if(selected == 6 && apparent_power_tp() == false) continue;
    if(selected == 7 && active_power_tp() == false) continue;
  }

  return 0;
}
