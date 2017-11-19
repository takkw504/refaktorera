#include "interface.h"
#include "formulas.h"
#include <iostream>

void disp_menu(void) {
  std::cout
  << "\nV\x84lj vilka storheter du vill ber\x84kna: \n"
  << "V\x84lj 1 f\x94r: OHMS LAG\n"
  << "V\x84lj 2 f\x94r: Rtot\n"
  << "V\x84lj 3 f\x94r: EFFEKTLAGEN ENKEL\n"
  << "V\x84lj 4 f\x94r: SKENBAR EFFEKT ENFAS\n"
  << "V\x84lj 5 f\x94r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n"
  << "V\x84lj 6 f\x94r: SKENBAR EFFEKT 3-FAS\n"
  << "V\x84lj 7 f\x94r: AKTIV EFFEKT 3-FAS\n"
  << "V\x84lj 0 f\x94r: F\x99R ATT AVSLUTA"
  << std::endl;
}

void disp_choice(int choice) {
  if(choice == 1) {

    std::cout << "Ohms lag sp\x84nningen(volt/V) bet\x84"
    << "ckning U lika med Resistansen(Ohm) bet\x84"
    << "ckning R" << std::endl;
    std::cout << "g\x86nger Str\x94mmen(Ampere) med bet\x84"
    << "ckningen I. Kort U=R*I. \n" << std::endl;

  } else if(choice == 2) {

    std::cout << "Resistans sammankopplade i parallella kretsar \x84r lika med 1"
    << " delat Resistans R total \x84r lika med" << std::endl;
    std::cout << "Resistans 1/R1 + 1/R2 + 1/R3 d\x86 vi h\x94gst anv\x84nder"
    << " tre resistanser.\n" << std::endl;

  } else if(choice == 3) {

    std::cout << "Effektlagen enkel f\x94r likstr\x94m \x84r effekten P i Watt (W)"
    <<" lika med sp\x84nningen U i volt(V)" << std::endl;
    std::cout << "g\x86nger str\x94mmen I i Ampere(A): \n" << std::endl;

  } else if(choice == 4) {

    std::cout << "Skenbar effekt enfas r\x84knas med storheten VA(VoltAmpere)"
    <<" som \x84r lika med sp\x84nningen U i volt(V)" << std::endl;
    std::cout << "g\x86nger str\x94mmen I i ampere(A)\n" << std::endl;

  } else if(choice == 5) {

    std::cout << "Aktiv medelefdekt enfas \x84r lika med effekt P i watt(W)"
    << " lika med sp\x84nningen U i volt(V) g\x86nger str\x94mmen I " << std::endl;
    std::cout << "i Ampere g\x86nger cosinus fi/efkektfaktor < 1:\n" << std::endl;

  } else if(choice == 6) {

    std::cout << "3-fas skenbar effekt \x84r v\x84xelsp\x84nning \x84r skenbar "
    << "effekt S i voltampere(VA) lika med sp\x84nningen U i volt(V) " << std::endl;
    std::cout << "g\x86nger str\x94mmen I i ampere(A) g\x86nger roten "
    << "ur 3 SQRT(3).\n" << std::endl;

  } else if(choice == 7) {

    std::cout << "3-fas aktiv effekt \x84r effekten P i Watt(W) lika "
    << "med sp\x84nningen U i volt(V) g\x86nger str\x94mmen " <<
    "I i ampere(A)" << std::endl;
    std::cout << "g\x86nger cos < 1 && cos > 0 g\x86nger "
    << "roten ur 3 SQRT(3).\n" << std::endl;

  }
}


bool ohm(void) {

  double R1, I;

  std::cout << "Skriv resistans R <= 20 000ohm: " << std::endl;
  std::cin >> R1;
  if(R1 > 20000) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }

  std::cout << "Skriv str\x94m I <= 440 Ampere: " << std::endl;
  std::cin >> I;
  if(I > 440) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }

  std::cout << ohms_lag(R1, I) << " V" << std::endl;
  return true;
}


bool rtot(void) {

  double R1, R2, R3;

  std::cout << "Skriv resistans R <= 20 000ohm: " << std::endl;
  std::cin >> R1;
  if(R1 > 20000) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }
  std::cout << "Skriv resistans R2 <= 20 000ohm: " << std::endl;
  std::cin >> R2;
  if(R2 > 20000) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }
  std::cout << "Skriv resistans R3 <= 20 000ohm: " << std::endl;
  std::cin >> R3;
  if(R3 > 20000) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }

  std::cout << res_tot(R1, R2, R3) << " Ohm" << std::endl;
  return true;
}


bool power(void) {
  double U , I;

  std::cout << "Skriv sp\x84nnngen U i volt(V): " << std::endl; //ingen check
  std::cin >> U;
  std::cout << "Skriv str\x94m I <= 440 Ampere: " << std::endl;
  std::cin >> I;
  if(I > 440) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }

  std::cout << eff_enk(U, I) << " W" << std::endl;
  return true;
}


bool apparent_power_sp(void) {
  double U , I;

  std::cout << "Skriv sp\x84nnngen U i volt(V): " << std::endl; //ingen check
  std::cin >> U;
  std::cout << "Skriv str\x94m I <= 440 Ampere: " << std::endl;
  std::cin >> I;
  if(I > 440) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }

  std::cout <<  sken_eff(U, I) << " VA" << std::endl;
  return true;
}


bool active_power_sp(void) {
  double U, I, cosine;

  std::cout << "Skriv sp\x84nnngen U i volt(V): " << std::endl; //ingen check
  std::cin >> U;
  std::cout << "Skriv str\x94m I <= 440 Ampere: " << std::endl;
  std::cin >> I;
  if(I > 440) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }
  std::cout << "Skriv in effektfaktorn cos > 0 && cos < 1: " << std::endl;
  std::cin >> cosine;
  if(cosine < 0 || cosine > 1) {
    printf("Fel v\x84rde, f\x94rs\x94k igen\n");
    return false;
  }

  std::cout << aktiv_eff(U, I, cosine) << " W" << std::endl;
  return true;
}


bool apparent_power_tp(void) {
  double U, I;

  std::cout << "Skriv sp\x84nning U i volt(V) <= 400V: " << std::endl;
  std::cin >> U;
  if(U > 400) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }
  std::cout << "Skriv str\x94m I <= 440 Ampere: " << std::endl;
  std::cin >> I;
  if(I > 440) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }

  std::cout << sken_3fas(U, I) << " VA" << std::endl;
  return true;
}


bool active_power_tp(void ) {
  double U, I, cosine;

  std::cout << "Skriv sp\x84nning U i volt(V) <= 400V: " << std::endl;
  std::cin >> U;
  if(U > 400) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }
  std::cout << "Skriv str\x94m I <= 440 Ampere: " << std::endl;
  std::cin >> I;
  if(I > 440) {
    printf("F\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
    return false;
  }
  std::cout << "Skriv in effektfaktorn cos > 0 && cos < 1: " << std::endl;
  std::cin >> cosine;
  if(cosine < 0 || cosine > 1) {
    printf("Fel v\x84rde, f\x94rs\x94k igen\n");
    return false;
  }

  std::cout << aktiv_3fas(U ,I, cosine) << " W" << std::endl;
  return true;
}
