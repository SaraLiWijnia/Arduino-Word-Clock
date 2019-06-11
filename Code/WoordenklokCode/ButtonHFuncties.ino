// alle functies met de buttons

boolean negatiefOfPositief = true;


void buttonFunctiesTijdSkippen_Loop() {

  // 30 seconden
  if (button_Clicked(2) == true) {
    setClockTime30(negatiefOfPositief);
  }


  // 5 min
  if (button_Clicked(1) == true) {
    if (negatiefOfPositief == true ) {
      setTime5MinutesForward();
    }
    else {
      setTime5MinutesBackwards();
    }
  }
}

void buttonFuncties_Vooruit_Achteruit() { 
  if (button_Clicked(0) == true )  {
    if (negatiefOfPositief == false) {
      negatiefOfPositief = true;
      // doorgeven = 1;
    } else {
      negatiefOfPositief = false;
      //  doorgeven = -1;
    }
  }
}
