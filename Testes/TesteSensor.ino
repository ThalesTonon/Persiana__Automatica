// Definindo porta do LDR
const int portaLDR = A0;
 
void setup() {
  // Inicializando o serial
  Serial.begin(9600);
  // Definindo a porta do sensor como entrada
  pinMode(portaLDR, INPUT);
}
 
void loop() {
  // Realizando a leitura do sensor
  int leitura = analogRead(portaLDR);
  // Realizando o print da leitura no serial
  Serial.println("Leitura do Sensor de LDR:");
  Serial.println(leitura);
  // Um delay e inicializar leitura daqui a 2 segundos
  delay(2000);
}
