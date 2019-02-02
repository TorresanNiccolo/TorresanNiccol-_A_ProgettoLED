//assegno alle porte della scheda di arduino i vari collegati
int rosso1 = 8;  
int giallo1 = 10;
int verde1 = 12;

int rosso2 = 2;
int giallo2 = 4;
int verde2 = 6;

//dichiaro le varibili riguardanti tempo e i lampeggi dei led
int numLampeggi = 0;
int tempoLamp = 0;
int tempoVerde = 0;
int tempoGiallo = 0;
int tempoRosso = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);

  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  //Comandi che permettono all'utente di scegliere i tempi e
  //e i lampeggi dei vari tempi
  Serial.begin(9600);
  
  Serial.println ("Quanti lampeggi deve fare il verde?");
  while (Serial.available() == 0) {};
  numLampeggi = Serial.readString().toInt();

  Serial.println ("Quanto durano i lampeggi?");
  while (Serial.available() == 0) {};
  tempoLamp = Serial.readString().toInt();

  Serial.println ("Quanto sta acceso il verde?");
  while (Serial.available() == 0) {};
  tempoVerde = Serial.readString().toInt();

  Serial.println ("Quanto sta acceso il giallo?");
  while (Serial.available() == 0);
  tempoGiallo = Serial.readString().toInt();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  tempoRosso = tempoVerde + tempoGiallo;
  
  digitalWrite(rosso1, HIGH);
  digitalWrite(verde2, HIGH);
  delay(tempoVerde);

  lampeggia2();
  digitalWrite(verde2, LOW);

  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  delay(tempoGiallo);

  digitalWrite(rosso1, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(giallo2, LOW);
  digitalWrite(verde1, HIGH);
  digitalWrite(rosso2, HIGH);
  delay(tempoVerde);

  lampeggia1();
  digitalWrite(verde1, LOW);

  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  delay(tempoGiallo);
  
  digitalWrite(giallo2, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(rosso2, LOW);
  }

  //metodi che permettono di far lampeggiare i due led verdi
  void lampeggia1()
  {
   for(int i = 0; i <= numLampeggi; i++)
   {
    delay(tempoLamp);
    digitalWrite(verde1, LOW);
    delay(tempoLamp);
    digitalWrite(verde1, HIGH);
   }
  }

  void lampeggia2()
  {
   for(int i = 0; i <= numLampeggi; i++)
   {
    delay(tempoLamp);
    digitalWrite(verde2, LOW);
    delay(tempoLamp);
    digitalWrite(verde2, HIGH);
   }
  }
 
 
