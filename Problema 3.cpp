// C++ code
//

#include <Keypad.h>

const byte filas = 4;
const byte columnas = 4;
byte pinesFilas[] = {13,12,11,10};
byte pinesColumnas[] = {9, 8, 7, 6};

char teclas[4][4] = {{'1','2','3','A'},
					 {'4','5','6','B'},
					 {'7','8','9','C'},
					 {'*','0','#','D'}};
int ledR = 5;
int ledAM = 4;
int ledV = 3;

int horaActual = 0;
bool horaIngresada = false;

Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas,
pinesColumnas, filas, columnas);
void setup() {
	Serial.begin(9600);
	Serial.println("Semaforo con teclado Keypad 4x4");
  
    pinMode(ledR, OUTPUT);
    pinMode(ledAM, OUTPUT);
    pinMode(ledV, OUTPUT);
  
  
    digitalWrite(ledR, LOW);
    digitalWrite(ledAM, LOW);
    digitalWrite(ledV, LOW);
}

int leerHora(){
	 int hora = 0;
  	 char tecla;
   	 while (true) {
   		 tecla = teclado1.getKey();
  		 if (tecla && isDigit(tecla)) {  
    		 hora = hora * 10 + (tecla - '0'); 
     		 Serial.print(tecla);  
   	 }
   	 if (hora >= 0 && hora <= 23 && tecla == '#') {  
      	Serial.println();
      	Serial.print("Hora ingresada: ");
     	Serial.println(hora);
     	return hora;  
    }
  }
  
}

void semNormal(){  
  digitalWrite(ledV, HIGH);  
  delay(5000);
  digitalWrite(ledV, LOW);

  digitalWrite(ledAM, HIGH); 
  delay(2000);
  digitalWrite(ledAM, LOW);

  digitalWrite(ledR, HIGH);  
  delay(10000);
  digitalWrite(ledR, LOW);
}
void semDoble(){

  digitalWrite(ledV, HIGH);  
  delay(10000);  
  digitalWrite(ledV, LOW);

  digitalWrite(ledAM, HIGH); 
  delay(4000);  
  digitalWrite(ledAM, LOW);

  digitalWrite(ledR, HIGH);  
  delay(20000);  
  digitalWrite(ledR, LOW);
}

void semLibre()  {
  digitalWrite(ledAM, HIGH);
  delay(500);
  digitalWrite(ledAM, LOW);
  delay(500);
}


void loop(){
  if (!horaIngresada) {
    Serial.println("Ingrese la hora actual en formato de 24h (0-23): ");
    horaActual = leerHora();  
    horaIngresada = true; 
  }
  
  if (horaActual >= 3 && horaActual < 16) {
    semNormal();
  } else if (horaActual >= 16 && horaActual < 24) {
    semDoble();
  } else {
    semLibre();
  }
}


