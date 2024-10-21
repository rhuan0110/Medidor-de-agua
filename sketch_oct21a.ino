#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(12, 13);  // Inicializa o sensor que usa os pinos digitais 13 e 12.

const float alturaGarrafao = 15.0; // altura da garrafa em cm
const float volumeTotal = 1000.0;  // volume total da garrafa em ml (1 litro)

void setup() {
    Serial.begin(9600);  // Inicializa a conexão serial para imprimir valores.
}

void loop() {
    // Medir a distância até a superfície da água
    float distancia = distanceSensor.measureDistanceCm();
    
    // Calcular o volume de água restante na garrafa
    float alturaAgua = alturaGarrafao - distancia; // altura da água em cm
    // Certificar-se de que a altura da água não é negativa
    alturaAgua = max(0.0, alturaAgua);
    float volumeRestante = (alturaAgua / alturaGarrafao) * volumeTotal; // volume restante em ml
    
    // Imprimir a distância e o volume restante
   // Serial.print("Distância até a água: ");
    //Serial.print(distancia);
   // Serial.println(" cm");
    
    Serial.print("Volume de água restante: ");
    Serial.print(volumeRestante);
    Serial.println(" ml");

    delay(500); // Espera 500 milissegundos antes da próxima medição
}
