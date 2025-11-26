
// *** NAVODILA ***
// Naloži kodo na arduino in odpri "Serial monitor"
// Najprej pusti menjalnik v N in nato pritisni tipko pri strani, da se izpiše vrednost "v" in "h"
// Prestavi v položaj R in nato pritisni tipko pri strani, da se izpiše vrednost "v" in "h" pri prestavi R
// Tako naprej nadaljuj za prestave od 1 do 6 PO VRSTI in vsakič pritisni tipko, da se izpišejo vrednosti "v" in "h" za prestave.
// Ko končaš, si te vrednosti zapiši. Odpri datoteko "menjalnik.ino" in popravi v njej pogoje po navodilih v tisti datoteki.



int state=0, i=0;
String tab[8] = {"N","R","1","2","3","4","5","6"};

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(13,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(13)==LOW && state==0 && i<8){
    Serial.print(tab[i]+": ");
    Serial.println(String(analogRead(A0))+" v");
    Serial.println("   "+String(analogRead(A1))+" h");
    Serial.println();
    state=1;
    i++;
  }
  else{
    if(digitalRead(13)==HIGH){
      state=0;
    }
  }
  delay(50);

}
