int led = 3; //Pino do led
int analogPin = A0;  //Pino analogico, recebe a largura de pulso (duty cycle)
int valor_analog; // Variavel para armazenar o valor o duty cycle do led
int brilho_led = 255; //Controlar o brilho do led
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);    
}

void loop()
{
  analogWrite(led, brilho_led); // mudar o brilho

  valor_analog = analogRead(analogPin); // Ler o valor do pino alanog A0

  int valor_remapeado = map(valor_analog, 0, 1023, 0, 255); // Remapear o valor para o 8 bits

  Serial.println(valor_remapeado);// Mostrar o valor do duty cycle
}
