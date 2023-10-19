const int botaoPin = 2;  // Pino digital conectado ao botão
const int ledPin = 13;   // Pino digital conectado à LED embutida (no Arduino Uno, é o pino 13)

int estadoBotao = 0;     // Variável para armazenar o estado atual do botão
int estadoAnterior = 0;  // Variável para armazenar o estado anterior do botão
int ledEstado = LOW;     // Variável para armazenar o estado da LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Configura o pino da LED como saída
  pinMode(botaoPin, INPUT); // Configura o pino do botão como entrada
}

void loop() {
  // Lê o estado atual do botão
  estadoBotao = digitalRead(botaoPin);

  // Verifica se o botão foi pressionado
  if (estadoBotao != estadoAnterior) {
    if (estadoBotao == HIGH) {
      // Inverte o estado da LED quando o botão é pressionado
      ledEstado = (ledEstado == LOW) ? HIGH : LOW;
      digitalWrite(ledPin, ledEstado);
    }
    delay(50); // Pequena pausa para evitar leituras falsas
  }

  // Atualiza o estado anterior do botão
  estadoAnterior = estadoBotao;
}
