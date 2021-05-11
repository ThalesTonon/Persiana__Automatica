<<<<<<< HEAD
#include  <Stepper.h> // inclue a biblioteca Stepper.h
#include <SoftwareSerial.h> //Comandos Seriais
//Pinos do módulo Bluetooth
SoftwareSerial HC05(8, 9); // TX-RX
// --------- LDR E PASSOS -----------
//Passos por volta indicado no configuração do Motor
const int PassosPorVolta = 200;
//Variável para controle
bool controle = true;
int controleA = 0;
int controleM = 0;
char modos = 'A';
int leitura;
//Inicializa a biblioteca utilizando as portas de 10, 11, 12 e 13
Stepper MPassos(PassosPorVolta, 10, 12, 11, 13);
//Declara a portaLDR
const int portaLDR = A5;
// ------ FIM LDR E PASSOS -----------

void setup() {
  Serial.begin(9600);
  HC05.begin(9600);// Taxa de transmissão do Módulo
  MPassos.setSpeed(60);// Ajusta velocidade para 60 RPM
}
void loop() {
  //Armazena os valores de leitura de HC05 na variável readBluetooth
  modos = HC05.read();
  if (modos == 'I' ){
    MPassos.step(6144);//Iniciando a persiana posição 0
  }
  else if (modos == 'A'){
    Serial.println("Modo Automático");
    controle = true;
    controleA = 0;
    Automatico();
  } //Modo Manual
  else if((modos == '4')||(modos == '6')||(modos == 'O')||(modos == 'C')){
    Serial.println("Modo Manual LOOP");
    controle = true;
    controleM = 0;
    Manual();
    
  }
}
void Automatico(){
  Serial.println("Void Automático");
  do{
  leitura = analogRead(portaLDR);
  Serial.print("Leitura do Sensor de LDR:");
  Serial.println(leitura);

  // Ambiente muito claro - Fechar persiana
  if(leitura > 450){//Verificar o valor sensor
    if( controleA != 1){
      Serial.println("Controle 1");
      if(controleA == 2){
        Serial.println("Controle 1 - 2");
        MPassos.step(3500);//Fechando a persiana a partir do controle 2
        delay(1000);
      } else if(controleA == 3 || controleA == 0){
        Serial.println("Controle 1 - 3");
        MPassos.step(6144);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controleA = 1;//Variável Controle Automático
    }
  } 
  // Ambiente agradável - Abrir Persiana 90º
  else if((leitura >= 250) && (leitura <= 450)){//Verificar o valor sensor
     if( controleA != 2){
      Serial.println("Controle 2");
      if(controleA == 1 || controleA == 0){
        if( controleA == 0){
          MPassos.step(6144);//Fechando a persiana a partir do controle 3
        }
        Serial.println("Controle 2 - 1");
        MPassos.step(-3072);//Abrindo a persiana a partir do controle 1
        delay(1000);
      } else if(controleA == 3){
        Serial.println("Controle 2 - 3");
        MPassos.step(3072);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controleA = 2;
    }
  }
  // Ambiente escuro - Abrir persiana
  if(leitura < 250){//Verificar o valor sensor
    if( controleA != 3){
      Serial.println("Controle 3");
      if(controleA == 1 || controleA == 0){
        if( controleA == 0){
          MPassos.step(6144);//Fechando a persiana a partir do controle 3
        }
        Serial.println("Controle 3 - 1");
        MPassos.step(-6144);//Abrindo a persiana a partir do controle 1
        delay(1000);
      } else if(controleA == 2){
        Serial.println("Controle 3 - 2");
        MPassos.step(-3072);//Fechando a persiana a partir do controle 2
        delay(1000);
      }
      controleA = 3;
    }
  }
  delay(2500);
  modos = HC05.read();//Lendo valor do módulo
  if (modos == 'A'){
    Serial.println("Modo Automático");
    Automatico();
    controle = true;
  } //Modo Manual
  else if(modos == 'S'){
    controle = false;//Saindo do void Automático
    controleA = 0;
    controleM = 0;
  }
  } while(controle);
}
void Manual(){
  do{
        Serial.println("Void Manual");
      if (modos == '4'){
        Serial.println("Modo 45º");
        if( controleM != 1){
          if(controleM == 2){
            Serial.println("Controle 1 - 2");
            MPassos.step(1024);//Fechando a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 3){
            Serial.println("Controle 1 - 3");
            MPassos.step(3072);//Fechando a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 4 || controleM == 0){
            Serial.println("Controle 1 - 4");
            MPassos.step(-3072);//Abrindo a persiana a partir do controle 2
            delay(1000);
          }
          controleM = 1;
        }
      } else if (modos == '6'){
        Serial.println("Modo 60º");
        if( controleM != 2){
          if(controleM == 1){
            Serial.println("Controle 2 - 1");
            MPassos.step(-1024);//Abrindo a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 3){
            Serial.println("Controle 2 - 3");
            MPassos.step(2048);//Fechando a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 4 || controleM == 0){
            Serial.println("Controle 2 - 4");
            MPassos.step(-4096);//Abrindo a persiana a partir do controle 2
            delay(1000);
          }
          controleM = 2;
        }
      } else if (modos == 'O'){
        Serial.println("Modo Open");
        if( controleM != 3){
          if(controleM == 1){
            Serial.println("Controle 3 - 1");
            MPassos.step(-3072);//Abrindo a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 2){
            Serial.println("Controle 3 - 2");
            MPassos.step(-2048);//Abrindo a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 4 || controleM == 0){
            Serial.println("Controle 3 - 4");
            MPassos.step(-6144);//Abrindo a persiana a partir do controle 2
            delay(1000);
          }
          controleM = 3;
        }
      } else if (modos == 'C'){
        Serial.println("Modo Close");
         if( controleM != 4){
          if(controleM == 1){
            Serial.println("Controle 4 - 1");
            MPassos.step(3072);//Fechando a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 2){
            Serial.println("Controle 4 - 2");
            MPassos.step(4096);//Fechando a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 3){
            Serial.println("Controle 4 - 3");
            MPassos.step(6144);//Fechando a persiana a partir do controle 3
            delay(1000);
          }
          controleM = 4;
        }
      }
  delay(2500);
  modos = HC05.read();//Lendo valor do módulo
  if ((modos == '4')||(modos == '6')||(modos == 'O')||(modos == 'C')){
    Serial.println("Modo Manual");
    controle = true;
  } //Modo Manual
  else if(modos == 'A'){
    controle = false;//Saindo do void Automático
    controleA = 0;
    controleM = 0;
  }
  } while(controle);
}
=======
#include  <Stepper.h> // inclue a biblioteca Stepper.h
#include <SoftwareSerial.h> //Comandos Seriais
//Pinos do módulo Bluetooth
SoftwareSerial HC05(8, 9); // TX-RX
// --------- LDR E PASSOS -----------
//Passos por volta indicado no configuração do Motor
const int PassosPorVolta = 200;
//Variável para controle
bool controle = true;
int controleA = 0;
int controleM = 0;
char modos = 'A';
int leitura;
//Inicializa a biblioteca utilizando as portas de 10, 11, 12 e 13
Stepper MPassos(PassosPorVolta, 10, 12, 11, 13);
//Declara a portaLDR
const int portaLDR = A5;
// ------ FIM LDR E PASSOS -----------

void setup() {
  Serial.begin(9600);
  HC05.begin(9600);// Taxa de transmissão do Módulo
  MPassos.setSpeed(60);// Ajusta velocidade para 60 RPM
}
void loop() {
  //Armazena os valores de leitura de HC05 na variável readBluetooth
  modos = HC05.read();
  if (modos == 'I' ){
    MPassos.step(6144);//Iniciando a persiana posição 0
  }
  else if (modos == 'A'){
    Serial.println("Modo Automático");
    controle = true;
    controleA = 0;
    Automatico();
  } //Modo Manual
  else if((modos == '4')||(modos == '6')||(modos == 'O')||(modos == 'C')){
    Serial.println("Modo Manual LOOP");
    controle = true;
    controleM = 0;
    Manual();
    
  }
}
void Automatico(){
  Serial.println("Void Automático");
  do{
  leitura = analogRead(portaLDR);
  Serial.print("Leitura do Sensor de LDR:");
  Serial.println(leitura);

  // Ambiente muito claro - Fechar persiana
  if(leitura > 450){//Verificar o valor sensor
    if( controleA != 1){
      Serial.println("Controle 1");
      if(controleA == 2){
        Serial.println("Controle 1 - 2");
        MPassos.step(3500);//Fechando a persiana a partir do controle 2
        delay(1000);
      } else if(controleA == 3 || controleA == 0){
        Serial.println("Controle 1 - 3");
        MPassos.step(6144);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controleA = 1;//Variável Controle Automático
    }
  } 
  // Ambiente agradável - Abrir Persiana 90º
  else if((leitura >= 250) && (leitura <= 450)){//Verificar o valor sensor
     if( controleA != 2){
      Serial.println("Controle 2");
      if(controleA == 1 || controleA == 0){
        if( controleA == 0){
          MPassos.step(6144);//Fechando a persiana a partir do controle 3
        }
        Serial.println("Controle 2 - 1");
        MPassos.step(-3072);//Abrindo a persiana a partir do controle 1
        delay(1000);
      } else if(controleA == 3){
        Serial.println("Controle 2 - 3");
        MPassos.step(3072);//Fechando a persiana a partir do controle 3
        delay(1000);
      }
      controleA = 2;
    }
  }
  // Ambiente escuro - Abrir persiana
  if(leitura < 250){//Verificar o valor sensor
    if( controleA != 3){
      Serial.println("Controle 3");
      if(controleA == 1 || controleA == 0){
        if( controleA == 0){
          MPassos.step(6144);//Fechando a persiana a partir do controle 3
        }
        Serial.println("Controle 3 - 1");
        MPassos.step(-6144);//Abrindo a persiana a partir do controle 1
        delay(1000);
      } else if(controleA == 2){
        Serial.println("Controle 3 - 2");
        MPassos.step(-3072);//Fechando a persiana a partir do controle 2
        delay(1000);
      }
      controleA = 3;
    }
  }
  delay(2500);
  modos = HC05.read();//Lendo valor do módulo
  if (modos == 'A'){
    Serial.println("Modo Automático");
    Automatico();
    controle = true;
  } //Modo Manual
  else if(modos == 'S'){
    controle = false;//Saindo do void Automático
    controleA = 0;
    controleM = 0;
  }
  } while(controle);
}
void Manual(){
  do{
        Serial.println("Void Manual");
      if (modos == '4'){
        Serial.println("Modo 45º");
        if( controleM != 1){
          if(controleM == 2){
            Serial.println("Controle 1 - 2");
            MPassos.step(1024);//Fechando a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 3){
            Serial.println("Controle 1 - 3");
            MPassos.step(3072);//Fechando a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 4 || controleM == 0){
            Serial.println("Controle 1 - 4");
            MPassos.step(-3072);//Abrindo a persiana a partir do controle 2
            delay(1000);
          }
          controleM = 1;
        }
      } else if (modos == '6'){
        Serial.println("Modo 60º");
        if( controleM != 2){
          if(controleM == 1){
            Serial.println("Controle 2 - 1");
            MPassos.step(-1024);//Abrindo a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 3){
            Serial.println("Controle 2 - 3");
            MPassos.step(2048);//Fechando a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 4 || controleM == 0){
            Serial.println("Controle 2 - 4");
            MPassos.step(-4096);//Abrindo a persiana a partir do controle 2
            delay(1000);
          }
          controleM = 2;
        }
      } else if (modos == 'O'){
        Serial.println("Modo Open");
        if( controleM != 3){
          if(controleM == 1){
            Serial.println("Controle 3 - 1");
            MPassos.step(-3072);//Abrindo a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 2){
            Serial.println("Controle 3 - 2");
            MPassos.step(-2048);//Abrindo a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 4 || controleM == 0){
            Serial.println("Controle 3 - 4");
            MPassos.step(-6144);//Abrindo a persiana a partir do controle 2
            delay(1000);
          }
          controleM = 3;
        }
      } else if (modos == 'C'){
        Serial.println("Modo Close");
         if( controleM != 4){
          if(controleM == 1){
            Serial.println("Controle 4 - 1");
            MPassos.step(3072);//Fechando a persiana a partir do controle 1
            delay(1000);
          } else if(controleM == 2){
            Serial.println("Controle 4 - 2");
            MPassos.step(4096);//Fechando a persiana a partir do controle 2
            delay(1000);
          } else if(controleM == 3){
            Serial.println("Controle 4 - 3");
            MPassos.step(6144);//Fechando a persiana a partir do controle 3
            delay(1000);
          }
          controleM = 4;
        }
      }
  delay(2500);
  modos = HC05.read();//Lendo valor do módulo
  if ((modos == '4')||(modos == '6')||(modos == 'O')||(modos == 'C')){
    Serial.println("Modo Manual");
    controle = true;
  } //Modo Manual
  else if(modos == 'A'){
    controle = false;//Saindo do void Automático
    controleA = 0;
    controleM = 0;
  }
  } while(controle);
}
>>>>>>> c1136d1c101b0140e698ccb58b9caf0c8975850b
