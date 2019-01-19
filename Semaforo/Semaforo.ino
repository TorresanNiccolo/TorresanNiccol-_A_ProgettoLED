
int rosso1 = 12;
int giallo1 = 11;
int verde1 = 10;

int rosso2 = 5;
int giallo2 = 4;
int verde2 = 3;

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

  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  delay(5000);

  digitalWrite(verde2, LOW);
  digitalWrite(giallo2, LOW);
  digitalWrite(rosso2, HIGH);
  digitalWrite(verde1, HIGH);
  digitalWrite(giallo1, LOW);
  digitalWrite(rosso1, LOW);
  delay(5000);

  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  delay(5000);

  digitalWrite(verde1, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(rosso1, HIGH);
  digitalWrite(verde2, HIGH);
  digitalWrite(giallo2, LOW);
  digitalWrite(rosso2, LOW);
}
