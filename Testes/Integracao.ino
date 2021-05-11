<<<<<<< HEAD
#include  <Stepper.h> // inclue a biblioteca Stepper.h
//Passos por volta indicado no configuração do Motor
const int PassosPorVolta = 200;
//Variável para controle
int controle = 0;
//Inicializa a biblioteca utilizando as portas de 8, 10, 9, 11
Stepper MPassos(PassosPorVolta, 8, 10, 9, 11);
//Declara a portaLDR
const int portaLDR = A0;
void setup() {
  // Inicializando o serial
  Serial.begin(9600);
  // Definindo a porta do sensor como entrada
  pinMode(portaLDR, INPUT);
  // Ajusta velocidade para 60 RPM
  MPassos.setSpeed(60);
}

void loop() {
  // Realizando a leitura do sensor
  int leitura = analogRead(portaLDR);
  // Realizando o print da leitura no serial
  Serial.println("Leitura do Sensor de LDR:");
  Serial.println(leitura);

  // Ambiente muito claro - Fechar persiana
  if(leitura > 450){
    if( controle != 1){
      Serial.println("Controle 1");
      if(controle == 2){
        Serial.println("Controle 1 - 2");
        MPassos.step(-2560);//Fechando a persiana a partir do controle 2
        delay(1000);
      } else if(controle == 3){
        Serial.println("Controle 1 - 3");
        MPassos.step(-6144);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controle = 1;
    }
  } 
  // Ambiente agradável - Abrir Persiana 90º
  else if((leitura >= 250) && (leitura <= 450)){
     if( controle != 2){
      Serial.println("Controle 2");
      if(controle == 1){
        Serial.println("Controle 2 - 1");
        MPassos.step(2560);//Fechando a persiana a partir do controle 1
        delay(1000);
      } else if(controle == 3){
        Serial.println("Controle 2 - 3");
        MPassos.step(-2048);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controle = 2;
    }
  }
  // Ambiente escuro - Abrir persiana
  if(leitura < 250){
    if( controle != 3){
      Serial.println("Controle 3");
      if(controle == 1){
        Serial.println("Controle 3 - 1");
        MPassos.step(6144);//Fechando a persiana a partir do controle 1
        delay(1000);
      } else if(controle == 2){
        Serial.println("Controle 3 - 2");
        MPassos.step(3584);//Fechando a persiana a partir do controle 2
        delay(1000);
      }
      controle = 3;
    }
  }
  delay(5000);// Tempo de 5 segundos
}
=======
#include  <Stepper.h> // inclue a biblioteca Stepper.h
//Passos por volta indicado no configuração do Motor
const int PassosPorVolta = 200;
//Variável para controle
int controle = 0;
//Inicializa a biblioteca utilizando as portas de 8, 10, 9, 11
Stepper MPassos(PassosPorVolta, 8, 10, 9, 11);
//Declara a portaLDR
const int portaLDR = A0;
void setup() {
  // Inicializando o serial
  Serial.begin(9600);
  // Definindo a porta do sensor como entrada
  pinMode(portaLDR, INPUT);
  // Ajusta velocidade para 60 RPM
  MPassos.setSpeed(60);
}

void loop() {
  // Realizando a leitura do sensor
  int leitura = analogRead(portaLDR);
  // Realizando o print da leitura no serial
  Serial.println("Leitura do Sensor de LDR:");
  Serial.println(leitura);

  // Ambiente muito claro - Fechar persiana
  if(leitura > 450){
    if( controle != 1){
      Serial.println("Controle 1");
      if(controle == 2){
        Serial.println("Controle 1 - 2");
        MPassos.step(-2560);//Fechando a persiana a partir do controle 2
        delay(1000);
      } else if(controle == 3){
        Serial.println("Controle 1 - 3");
        MPassos.step(-6144);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controle = 1;
    }
  } 
  // Ambiente agradável - Abrir Persiana 90º
  else if((leitura >= 250) && (leitura <= 450)){
     if( controle != 2){
      Serial.println("Controle 2");
      if(controle == 1){
        Serial.println("Controle 2 - 1");
        MPassos.step(2560);//Fechando a persiana a partir do controle 1
        delay(1000);
      } else if(controle == 3){
        Serial.println("Controle 2 - 3");
        MPassos.step(-2048);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controle = 2;
    }
  }
  // Ambiente escuro - Abrir persiana
  if(leitura < 250){
    if( controle != 3){
      Serial.println("Controle 3");
      if(controle == 1){
        Serial.println("Controle 3 - 1");
        MPassos.step(6144);//Fechando a persiana a partir do controle 1
        delay(1000);
      } else if(controle == 2){
        Serial.println("Controle 3 - 2");
        MPassos.step(3584);//Fechando a persiana a partir do controle 2
        delay(1000);
      }
      controle = 3;
    }
  }
  delay(5000);// Tempo de 5 segundos
}
>>>>>>> e0c51943334ecdef7ee7313e6809b8ecb1808428
