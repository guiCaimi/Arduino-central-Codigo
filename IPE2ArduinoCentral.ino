#define sensor1 13
#define sensor2 12
#define sensor3 11
#define sensor4 10
#define sensor5 9
#define sensor6 8
#define sensor7 7
#define sensor8 6
#define sensor9 5
#define sensor10 4
#define sensor11 3
#define sensor12 2
#define sensor13 14  // Porta A0 como porta digital
#define sensor14 15  // Porta A1 como porta digital
#define sensor15 16  // Porta A2 como porta digital

void setup() {
  // Configurar todos os sensores como saídas no início
  for (int i = 2; i <= 16; i++) {
    pinMode(i, OUTPUT);
  }

  // Inicialize a comunicação serial
  Serial.begin(9600);
}

void loop() {
    int tempo = 1000; // Tempo em milissegundos (ajuste conforme necessário)
  for (int sensor = 2; sensor <= 16; sensor++) {
    while (Serial.available() == 0) {}  // Aguarde a chegada de dados na serial

    char command = Serial.read();
    if (command == 'M') {
    
      FazerMedida(tempo, sensor);
      Serial.print("F");  // Sinalize o fim da medição
    }
  }
}

void FazerMedida(int tempo, int sensor) {
  DesativarSensores();
  digitalWrite(sensor, HIGH);
  delay(tempo);
  DesativarSensores();
}

void DesativarSensores() {
  for (int i = 2; i <= 16; i++) {
    digitalWrite(i, LOW);
  }
}
