
int rosso1 = 12;
int giallo1 = 10;
int verde1 = 8;

int rosso2 = 6;
int giallo2 = 4;
int verde2 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);

  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rosso1, HIGH);
  digitalWrite(verde2, HIGH);
  delay(5000);
  
  lampeggia(verde2, 500, 4);
  digitalWrite(verde2, LOW);

  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  digitalWrite(rosso1, LOW);
  delay(3000);

  digitalWrite(rosso1, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(giallo2, LOW);
  digitalWrite(verde1, HIGH);
  digitalWrite(rosso2, HIGH);
  delay(5000);

  lampeggia(verde1, 500, 4);
  digitalWrite(verde1, LOW);

  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  digitalWrite(rosso2, LOW);
  delay(3000);

  digitalWrite(giallo2, LOW);
  digitalWrite(giallo1, LOW);
  delay(5000);
}

 void lampeggia(int led, int ritardo, int n)
 {
  for(int i = 0; i <= n; i++)
  {
    delay(ritardo);
    digitalWrite(led, LOW);
    delay(ritardo);
    digitalWrite(led, HIGH);
  }
 }
