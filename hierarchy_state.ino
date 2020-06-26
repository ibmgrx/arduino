int pintu, arah;
enum {berhenti, bergerak};
enum {buka, diam, tutup};
int sebuahTombol,
    saklar,
    sensor,
    RA = 6,
    RB = 5;

void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);
  Serial.begin(9600);
  pintu = berhenti;
}

void loop()
{
  saklar = digitalRead(13);
  sebuahTombol = digitalRead(12);
  sensor = digitalRead(11);
  switch (pintu) {
    case berhenti:
      Serial.println("Pintu Berhenti (Sudah Tertutup/Sudah Terbuka)");
      digitalWrite(RA, LOW);
      digitalWrite(RB, LOW);
      if (sebuahTombol == 1) {
        pintu = bergerak;
        arah = buka;
      }
      break;
      
    case bergerak:
      switch (arah) {
        case buka:
          Serial.println("Pintu Bergerak Membuka");
          digitalWrite(RA, HIGH);
          digitalWrite(RB, LOW);
          if (sebuahTombol == 1) {
            arah = diam;
          }
          if (saklar == 1)pintu = berhenti;
          break;

        case diam:
          Serial.println("Pintu Tidak Bergerak");
          digitalWrite(RA, LOW);
          digitalWrite(RB, LOW);
          if (sebuahTombol == 1) {
            arah = tutup;
          }
          if (saklar == 1)pintu = berhenti;
          break;

        case tutup:
          Serial.println("Pintu Bergerak Menutup");
          digitalWrite(RA, LOW);
          digitalWrite(RB, HIGH);
          if (sebuahTombol == 1 || sensor == 1) {
            arah = buka;
          }
          if (saklar == 1)pintu = berhenti;
          break;
      }
      break;
  }
}
