//assegno alle porte della scheda di arduino i vari collegati
int rosso1 = 12;  
int giallo1 = 10;
int verde1 = 8;

int rosso2 = 6;
int giallo2 = 4;
int verde2 = 2;

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

  Serial.begin(9600);
  //domande che vengono poste all'utente per scegliere la varie caratteristiche di un semaforo
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
  //metodi richiamati
  tempoRosso = tempoVerde + tempoGiallo;
  primaSequenza();
  lampeggia2();
  digitalWrite(verde2, LOW);
  secondaSequenza();
  terzaSequenza();
  lampeggia1();
  digitalWrite(verde1, LOW);
  quartaSequenza();
  quintaSequenza();
  }
  //metodi che permettono di far lampeggiare i due led verdi
  void lampeggia1()
  {//metodo che permette al primo led verde di lampeggiare
   for(int i = 0; i <= numLampeggi; i++)
   {
    delay(tempoLamp);
    digitalWrite(verde1, LOW);
    delay(tempoLamp);
    digitalWrite(verde1, HIGH);
   }
  }
  void lampeggia2()
  {//metodo che permette al secondo led verde di lampeggiare
   for(int i = 0; i <= numLampeggi; i++)
   {
    delay(tempoLamp);
    digitalWrite(verde2, LOW);
    delay(tempoLamp);
    digitalWrite(verde2, HIGH);
   }
  }
  void primaSequenza()
  {//sequenza che accende il primo rosso e il secondo verde
    digitalWrite(rosso1, HIGH);
    digitalWrite(verde2, HIGH);
    delay(tempoVerde);
  }
  void secondaSequenza()
  {//sequenza che accende i due gialli
    digitalWrite(giallo1, HIGH);
    digitalWrite(giallo2, HIGH);
    delay(tempoGiallo);
  }
  void terzaSequenza()
  {//sequenza che spegne il primo rosso e i due gialli e a sua volta accende il secondo rosso e il primo verde
    digitalWrite(rosso1, LOW);
    digitalWrite(giallo1, LOW);
    digitalWrite(giallo2, LOW);
    digitalWrite(verde1, HIGH);
    digitalWrite(rosso2, HIGH);
    delay(tempoVerde);
  }
  void quartaSequenza()
  {//sequenza che accende i due gialli
    digitalWrite(giallo1, HIGH);
    digitalWrite(giallo2, HIGH);
    delay(tempoGiallo);
  }
  void quintaSequenza()
  {//sequenza che spegne i due gialli e il primo rosso per poi far ricominciare tutto
    digitalWrite(giallo2, LOW);
    digitalWrite(giallo1, LOW);
    digitalWrite(rosso2, LOW);
  }
 
 
