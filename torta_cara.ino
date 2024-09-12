int btn = 2; 
int btn2 = 4; 
int valor = 0;      
int valor2 = 0; 
int ult_valor = 0;
int contador = 0;         
int led = 3;
long aleatorio;
long num_ale;
int leds[] = {13, 12, 11, 10, 9, 8, 7};
int display[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 }
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  // Inicializa os LEDs com o número 0 no display de 7 segmentos
  visor(0);
  
  pinMode(btn, INPUT);
  pinMode(btn2, INPUT);
  pinMode(led, OUTPUT);
  
  randomSeed(analogRead(0));
  aleatorio = random(10, 30);
  
  Serial.begin(9600);  
  Serial.println(aleatorio);
}

void loop() {
  // Leitura dos botões
  valor = digitalRead(btn);
  valor2 = digitalRead(btn2); 
  
  // Gera um número aleatório ao apertar o segundo botão
  if (valor2 == 1) {
    num_ale = random(1, 10);
    visor(num_ale);
    Serial.println(num_ale);  
    delay(300);  // Delay para evitar múltiplas leituras
  }

  // Contador ao apertar o primeiro botão
  if (valor == 1 && ult_valor == 0 && num_ale > 0) {  // Verifica se num_ale > 0
    contador++;
    num_ale--;
    visor(num_ale);
    Serial.println(contador);  
    delay(300);  // Delay para evitar múltiplas leituras
  }
  
  ult_valor = valor;
  
  // Acende o LED se o contador atingir o número aleatório
  if (contador >= aleatorio) {
    digitalWrite(led, HIGH);
  }
}

int visor(int num) {
  // Atualiza o display com o número atual
  for (int coluna = 0; coluna < 7; coluna++) {
    digitalWrite(leds[coluna], display[num][coluna]);
  }
  return 0;
}
