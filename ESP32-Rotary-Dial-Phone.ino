// Stworzenie zmiennych
int number, count = 0;
unsigned long start, current, last, last2;

bool last_D1, last_D3 = false;
bool sluchawka;

void setup() {
  start = millis(); //Pobranie czasu startu
  Serial.begin(115200);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
}

void loop() {
  current = millis();

  if ((last2 <= current - 150) && (last_D3 == !digitalRead(D3))) {
    last2 = current;
    sluchawka = digitalRead(D3);
    if (sluchawka) {
      Serial.println("o");
    } else {
      Serial.println("p");
    }
    last_D3 = digitalRead(D3);
  }

  if (last_D1 == !digitalRead(D1)) {
    last = current;
    count++;
    last_D1 = digitalRead(D1);
  }
  if ((last <= current - 150)  && (count != 0)) {
    if (count/2 == 10) { // liczba jest dzielona przez 2 ponieważ to liczy też odskakiwanie przycisku
      number = 0;
    } else {
      number = count/2;
    }

    Serial.println(number);

    count = 0;
  }
  delay(1);
}
