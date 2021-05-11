<<<<<<< HEAD
#include <Stepper.h> //Inclue a biblioteca
//Passos por volta indicado na configuração do Motor
const int PassosPorVolta = 200;
//Inicializa a biblioteca utilizandi as portas do arduino 10,11,12 e 13
Stepper MPassos(PassosPorVolta, 10, 12, 11, 13);
void setup() {
  // Ajusta a velocidade para 60 RPM
  MPassos.setSpeed(60);
}

void loop() {
  // Motor gira 360º no semtido horário
  MPassos.step(2048);
  // Motor gira 360º no semtido anti-horário
  MPassos.step(2048);
  delay(2000);
}
=======
#include <Stepper.h> //Inclue a biblioteca
//Passos por volta indicado na configuração do Motor
const int PassosPorVolta = 200;
//Inicializa a biblioteca utilizandi as portas do arduino 10,11,12 e 13
Stepper MPassos(PassosPorVolta, 10, 12, 11, 13);
void setup() {
  // Ajusta a velocidade para 60 RPM
  MPassos.setSpeed(60);
}

void loop() {
  // Motor gira 360º no semtido horário
  MPassos.step(2048);
  // Motor gira 360º no semtido anti-horário
  MPassos.step(2048);
  delay(2000);
}
>>>>>>> e0c51943334ecdef7ee7313e6809b8ecb1808428
