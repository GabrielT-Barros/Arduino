int led = 9;      // Pino do LED
int b1Pin = 2;     // Pino do botão 1
int b2Pin = 4;     // Pino do botão 2
int b3Pin = 7;     // Pino do botão 3
int analogPin = A0; // Pino analógico, recebe a largura de pulso (duty cycle)
int valor_analog;   // Variável para armazenar o valor do duty cycle do LED

void setup() {
  pinMode(led, OUTPUT);
  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
  pinMode(b3Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(b1Pin) == HIGH) {
    padraoFast();
  }

  if (digitalRead(b2Pin) == HIGH) {
    padraoIncremento();
  }

  if (digitalRead(b3Pin) == HIGH) {
    padraoRandom();
  }
}
void padraoFast() {
  Serial.println("Padrao Fast executado!");
  for (int i = 0; i < 100; i++) {
    int brilho = map(i, 0, 99, 0, 255);
    analogWrite(led, brilho);
    lerValorAnalogico();
    delay(25);  // Ajuste este valor para controlar a velocidade
  }
  for (int i = 100; i >= 0; i--) {
    int brilho = map(i, 0, 99, 0, 255);
    analogWrite(led, brilho);
    lerValorAnalogico();
    delay(25);  // Ajuste este valor para controlar a velocidade
  }
  analogWrite(led, 0);
}

void padraoIncremento() {
  Serial.println("Padrao Incremento executado!");
  for (int i = 0; i < 100; i++) {
    int brilho = map(i, 0, 99, 0, 255);
    analogWrite(led, brilho);
    lerValorAnalogico();
    delay(50);
  }
  analogWrite(led, 0);
}

void padraoRandom() {
  Serial.println("Padrao Random executado!");
  for (int i = 0; i < 100; i++) {
    int randomBrilho = random(0, 255);
    analogWrite(led, randomBrilho);
    lerValorAnalogico();
    delay(50);
  }
  analogWrite(led, 0);
}

void lerValorAnalogico() {
  valor_analog = analogRead(analogPin); // Ler o valor do pino analógico A0
  int valor_remapeado = map(valor_analog, 0, 1023, 0, 255); // Remapear o valor para 8 bits
  Serial.println(valor_remapeado); // Mostrar o valor do duty cycle
}