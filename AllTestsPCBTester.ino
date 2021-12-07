#define U3B0 A11
#define U4B0 A16
#define U7A0 14
#define U3C0 A29
#define U7B0 8
#define U7C0 10
#define U7C1 10
#define U7B1 8
#define U3C1 A29
#define U7A1 14
#define U4B1 A16
#define U3B1 A11
#define U4C0 A33
#define U4A0 A31
#define U3A0 A34
#define U6A0 0
#define U6B0 1
#define U6C0 2
#define U6B1 1
#define U6A1 0
#define U3A1 A34
#define U4A1 A31
#define U4C1 A33
#define U1A3 A12
#define U1B3 A13
#define U5A1 45
#define U5B1 41
#define U5C1 17
#define U1B2 A13
#define U1A2 A12
#define U2A0 A35
#define U2B0 A32
#define U5A0 45
#define U5B0 41
#define U5C0 17
#define U1B1 A13
#define U2A1 A35
#define SControl 4
#define SW1 9
#define SW2 26
#define SW3 15
#define PR1 19
#define PR2 18

// Secondary Names
#define Lin A11
#define P1S A16
#define P1W 14
#define P1F A29
#define VPlus 8
#define bLOut 10
#define bROut 10
#define VMinus 8
#define P2F A29
#define P2W 14
#define P2S A16
#define Rin A11
#define P3F A33
#define P3W A31
#define P3S A34
#define tLin 0
#define tLOut 1
#define Gnd 2
#define tROut 1
#define tRin 0
#define P4S A34
#define P4W A31
#define P4F A33
#define O1 A12
#define O2 A13
#define O3 45
#define O4 41
#define O5 17
#define O6 A13
#define O7 A12
#define O8 A35
#define O9 A32
#define O10 45
#define O11 41
#define O12 17
#define O13 A13
#define O14 A35

bool debugMode = true;

void setAllPinsInputPullup() {
  pinMode(tLOut,INPUT_PULLUP);
  pinMode(P3F,INPUT_PULLUP);
  pinMode(P3S,INPUT_PULLUP);
  pinMode(P3W,INPUT_PULLUP);
  pinMode(tLin,INPUT_PULLUP);
  pinMode(VPlus,INPUT_PULLUP);
  pinMode(Gnd,INPUT_PULLUP);
  pinMode(tROut,INPUT_PULLUP);
  pinMode(P4S,INPUT_PULLUP);
  pinMode(P4F,INPUT_PULLUP);
  pinMode(P4W,INPUT_PULLUP);
  pinMode(Lin,INPUT_PULLUP);
  pinMode(P1S,INPUT_PULLUP);
  pinMode(P1W,INPUT_PULLUP);
  pinMode(P1F,INPUT_PULLUP);
  pinMode(VPlus,INPUT_PULLUP);
  pinMode(bLOut,INPUT_PULLUP);
  pinMode(bROut,INPUT_PULLUP);
  pinMode(VMinus,INPUT_PULLUP);
  pinMode(P2F,INPUT_PULLUP);
  pinMode(P2W,INPUT_PULLUP);
  pinMode(P2S,INPUT_PULLUP);
  pinMode(Rin,INPUT_PULLUP);
  pinMode(O1,INPUT_PULLUP);
  pinMode(O2,INPUT_PULLUP);
  pinMode(O3,INPUT_PULLUP);
  pinMode(O4,INPUT_PULLUP);
  pinMode(O5,INPUT_PULLUP);
  pinMode(O6,INPUT_PULLUP);
  pinMode(O7,INPUT_PULLUP);
  pinMode(O8,INPUT_PULLUP);
  pinMode(O9,INPUT_PULLUP);
  pinMode(O10,INPUT_PULLUP);
  pinMode(O11,INPUT_PULLUP);
  pinMode(O12,INPUT_PULLUP);
  pinMode(O13,INPUT_PULLUP);
  pinMode(O14,INPUT_PULLUP);

}



int test(int testPin, int selPin, int testValue, String pinName) {
    String value = "";
    if (digitalRead(selPin) == 1) {
      value = "HIGH";
    }
    else {
      value = "LOW";
    }
    
    if (testPin != selPin) {
        if (testValue == 1) {
            Serial.println("Check " + String(pinName) + ": " + value + "; Expected a HIGH value; Evaluates to " + (1 == digitalRead(selPin) ? "TRUE" : "FALSE") + "; Value == " + String(digitalRead(selPin)));
            return 1 == digitalRead(selPin);
        }
        else {
            Serial.println("Check " + String(pinName) + ": " + value + "; Expected a LOW value; Evaluates to " + (0 == digitalRead(selPin) ? "TRUE" : "FALSE") + "; Value == " + String(digitalRead(selPin)));
            return 0 == digitalRead(selPin);
        }
    }
    else {
        Serial.println("Check " + String(pinName) + ": " + value + "; Expected no value" + "; Value == " + String(digitalRead(selPin)));
        return -1;
    }
}

String testBoard3(int testPin, int testValue[], int pinsToTest[]) {
  setAllPinsInputPullup();
  pinMode(testPin, OUTPUT);
  digitalWrite(testPin, LOW);
  // MAIN TESTS
  
  int check1 = pinsToTest[0] == 1 ? test(testPin, tLOut, testValue[0], "tLOut") : -1;
  int check2 = pinsToTest[1] == 1 ? test(testPin, P3F, testValue[1], "P3F") : -1;
  int check3 = pinsToTest[2] == 1 ? test(testPin, P3S, testValue[2], "P3S") : -1;
  int check4 = pinsToTest[3] == 1 ? test(testPin, P3W, testValue[3], "P3W") : -1;
  int check5 = pinsToTest[4] == 1 ? test(testPin, tLin, testValue[4], "tLin") : -1;
  int check6 = pinsToTest[5] == 1 ? test(testPin, VPlus, testValue[5], "VPlus") : -1;
  int check7 = pinsToTest[6] == 1 ? test(testPin, Gnd, testValue[6], "Gnd") : -1;
  int check8 = pinsToTest[7] == 1 ? test(testPin, tROut, testValue[7], "tROut") : -1;
  int check9 = pinsToTest[8] == 1 ? test(testPin, tRin, testValue[8], "tRin") : -1;
  int check10 = pinsToTest[9] == 1 ? test(testPin, P4S, testValue[9], "P4S") : -1;
  int check11 = pinsToTest[10] == 1 ? test(testPin, P4W, testValue[10], "P4W") : -1;
  int check12 = pinsToTest[11] == 1 ? test(testPin, P4F, testValue[11], "P4F") : -1;
  int check13 = pinsToTest[12] == 1 ? test(testPin, Lin, testValue[12], "Lin") : -1;
  int check14 = pinsToTest[13] == 1 ? test(testPin, P1S, testValue[13], "P1S") : -1;
  int check15 = pinsToTest[14] == 1 ? test(testPin, P1W, testValue[14], "P1W") : -1;
  int check16 = pinsToTest[15] == 1 ? test(testPin, P1F, testValue[15], "P1F") : -1;
  int check17 = pinsToTest[16] == 1 ? test(testPin, VPlus, testValue[16], "VPlus") : -1;
  int check18 = pinsToTest[17] == 1 ? test(testPin, bLOut, testValue[17], "bLOut") : -1;
  int check19 = pinsToTest[18] == 1 ? test(testPin, bROut, testValue[18], "bROut") : -1;
  int check20 = pinsToTest[19] == 1 ? test(testPin, VMinus, testValue[19], "VMinus") : -1;
  int check21 = pinsToTest[20] == 1 ? test(testPin, P2F, testValue[20], "P2F") : -1;
  int check22 = pinsToTest[21] == 1 ? test(testPin, P2W, testValue[21], "P2W") : -1;
  int check23 = pinsToTest[22] == 1 ? test(testPin, P2S, testValue[22], "P2S") : -1;
  int check24 = pinsToTest[23] == 1 ? test(testPin, Rin, testValue[23], "Rin") : -1;
  int check25 = pinsToTest[24] == 1 ? test(testPin, O1, testValue[24], "O1") : -1;
  int check26 = pinsToTest[25] == 1 ? test(testPin, O2, testValue[25], "O2") : -1;
  int check27 = pinsToTest[26] == 1 ? test(testPin, O3, testValue[26], "O3") : -1;
  int check28 = pinsToTest[27] == 1 ? test(testPin, O4, testValue[27], "O4") : -1;
  int check29 = pinsToTest[28] == 1 ? test(testPin, O5, testValue[28], "O5") : -1;
  int check30 = pinsToTest[29] == 1 ? test(testPin, O6, testValue[29], "O6") : -1;
  int check31 = pinsToTest[30] == 1 ? test(testPin, O7, testValue[30], "O7") : -1;
  int check32 = pinsToTest[31] == 1 ? test(testPin, O8, testValue[31], "O8") : -1;
  int check33 = pinsToTest[32] == 1 ? test(testPin, O9, testValue[32], "O9") : -1;
  int check34 = pinsToTest[33] == 1 ? test(testPin, O10, testValue[33], "O10") : -1;
  int check35 = pinsToTest[34] == 1 ? test(testPin, O11, testValue[34], "O11") : -1;
  int check36 = pinsToTest[35] == 1 ? test(testPin, O12, testValue[35], "O12") : -1;
  int check37 = pinsToTest[36] == 1 ? test(testPin, O13, testValue[36], "O13") : -1;
  int check38 = pinsToTest[37] == 1 ? test(testPin, O14, testValue[37], "O14") : -1;

  

  if (check1 == 0 && !(check1 == -1)) {
    return "B3:E tLOut->V-";
  }
  else if (check2 == 0 && !(check2 == -1)) {
    return "B3:E P3F->V-";
  }
  else if (check3 == 0 && !(check3 == -1)) {
    return "B3:E P3S->V-";
  }
  else if (check4 == 0 && !(check4 == -1)) {
    return "B3:E P3W->V-";
  }
  else if (check5 == 0 && !(check5 == -1)) {
    return "B3:E tLin->V-";
  }
  else if (check6 == 0 && !(check6 == -1)) {
    return "B3:E VPlus->V-";
  }
  else if (check7 == 0 && !(check7 == -1)) {
    return "B3:E Gnd->V-";
  }
  else if (check8 == 0 && !(check8 == -1)) {
    return "B3:E tROut->V-";
  }
  else if (check9 == 0 && !(check9 == -1)) {
    return "B3:E tRin->V-";
  }
  else if (check10 == 0 && !(check10 == -1)) {
    return "B3:E P4S->V-";
  }
  else if (check11 == 0 && !(check11 == -1)) {
    return "B3:E P4W->V-";
  }
  else if (check12 == 0 && !(check12 == -1)) {
    return "B3:E P4F->V-";
  }
  else if (check13 == 0 && !(check13 == -1)) {
    return "B3:E Lin->V-";
  }
  else if (check14 == 0 && !(check14 == -1)) {
    return "B3:E P1S->V-";
  }
  else if (check15 == 0 && !(check15 == -1)) {
    return "B3:E P1W->V-";
  }
  else if (check16 == 0 && !(check16 == -1)) {
    return "B3:E P1F->V-";
  }
  else if (check17 == 0 && !(check17 == -1)) {
    return "B3:E V+->V-";
  }
  else if (check18 == 0 && !(check18 == -1)) {
    return "B3:E bLOut->V-";
  }
  else if (check19 == 0 && !(check19 == -1)) {
    return "B3:E bROut->V-";
  }
 else if (check20 == 0 && !(check20 == -1)) {
   return "B3:E V->V-";
 }
  else if (check21 == 0 && !(check21 == -1)) {
    return "B3:E P2F->V-";
  }
  else if (check22 == 0 && !(check22 == -1)) {
    return "B3:E P2W->V-";
  }
  else if (check23 == 0 && !(check23 == -1)) {
    return "B3:E P2S->V-";
  }
  else if (check24 == 0 && !(check24 == -1)) {
    return "B3:E Rin->V-";
  }
  else if (check25 == 0 && !(check25 == -1)) {
    return "B3:E O1->V-";
  }
  else if (check26 == 0 && !(check26 == -1)) {
    return "B3:E O2->V-";
  }
  else if (check27 == 0 && !(check27 == -1)) {
    return "B3:E O3->V-";
  }
  else if (check28 == 0 && !(check28 == -1)) {
    return "B3:E O4->V-";
  }
  else if (check29 == 0 && !(check29 == -1)) {
    return "B3:E O5->V-";
  }
  else if (check30 == 0 && !(check30 == -1)) {
    return "B3:E O6->V-";
  }
  else if (check31 == 0 && !(check31 == -1)) {
    return "B3:E O7->V-";
  }
  else if (check32 == 0 && !(check32 == -1)) {
    return "B3:E O8->V-";
  }
  else if (check33 == 0 && !(check33 == -1)) {
    return "B3:E O9->V-";
  }
  else if (check34 == 0 && !(check34 == -1)) {
    return "B3:E O10->V-";
  }
  else if (check35 == 0 && !(check35 == -1)) {
    return "B3:E O11->V-";
  }
  else if (check36 == 0 && !(check36 == -1)) {
    return "B3:E O12->V-";
  }
  else if (check37 == 0 && !(check37 == -1)) {
    return "B3:E O13->V-";
  }
  else if (check38 == 0 && !(check38 == -1)) {
    return "B3:E O14->V-";
  }
  else {
    return "B3 V- Passed!";
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SControl, OUTPUT);
  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  pinMode(SW3,INPUT);
  pinMode(PR1,OUTPUT);
  pinMode(PR2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pinsToTest[] = {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int expectedValues[] =    {1,0,1,1,1,-1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  String temp = testBoard3(VMinus, expectedValues, pinsToTest);
  Serial.println(temp);
  delay(5000);
}
