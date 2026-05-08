#include <string.h>

char senha[10] = "";

void setup()
{
  // Pinos das Linhas
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Pinos das Colunas
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
    for (int ti = 3; ti < 7; ti++)
    {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(ti, HIGH);

      if (digitalRead(8) == HIGH) { imprime_linha_coluna(ti-2, 1); while(digitalRead(8) == HIGH){} }
      if (digitalRead(9) == HIGH) { imprime_linha_coluna(ti-2, 2); while(digitalRead(9) == HIGH){} }
      if (digitalRead(10) == HIGH) { imprime_linha_coluna(ti-2, 3); while(digitalRead(10) == HIGH){} }
      if (digitalRead(11) == HIGH) { imprime_linha_coluna(ti-2, 4); while(digitalRead(11) == HIGH){} }
    }
    delay(10);
}

void imprime_linha_coluna(int x, int y)
{
  // Teclas Numéricas e Letras
  if(x==1 && y==1) senha_criada('1');
  if(x==1 && y==2) senha_criada('2');
  if(x==1 && y==3) senha_criada('3');
  if(x==1 && y==4) senha_criada('A');
  if(x==2 && y==1) senha_criada('4');
  if(x==2 && y==2) senha_criada('5');
  if(x==2 && y==3) senha_criada('6');
  if(x==2 && y==4) senha_criada('B');
  if(x==3 && y==1) senha_criada('7');
  if(x==3 && y==2) senha_criada('8');
  if(x==3 && y==3) senha_criada('9');
  if(x==3 && y==4) senha_criada('C');
  if(x==4 && y==2) senha_criada('0');
  if(x==4 && y==4) senha_criada('D');

  // Tecla '*' para Apagar
  if(x==4 && y==1) apagar_senha();

  // Tecla '#' para Enviar
  if(x==4 && y==3) enviar_senha();
}

void senha_criada(char x)
{
  int len = strlen(senha);
  if(len < 9){
    senha[len] = x;
    senha[len+1] = '\0';
  }
}

void apagar_senha()
{
  senha[0] = '\0';
}

void enviar_senha()
{
  if(strlen(senha) > 0) {
    Serial.println(senha); 
    senha[0] = '\0';
  }
}
