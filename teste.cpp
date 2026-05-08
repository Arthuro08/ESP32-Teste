#include <string.h>

char senha[10] = "";

void setup()
{
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  
  Serial.begin(9600);
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();
}

void loop()
{
    for (int ti = 3; ti<7; ti++)
    {
    //Alterna o estado dos pinos das linhas
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(8) == HIGH)
    {
      imprime_linha_coluna(ti-2, 1);
      while(digitalRead(8) == HIGH){}
    }

    //Verifica se alguma tecla da coluna 2 foi pressionada    
    if (digitalRead(9) == HIGH)
    {
      imprime_linha_coluna(ti-2, 2);
      while(digitalRead(9) == HIGH){};
    }
    
    //Verifica se alguma tecla da coluna 3 foi pressionada
    if (digitalRead(10) == HIGH)
    {
      imprime_linha_coluna(ti-2, 3);
      while(digitalRead(10) == HIGH){}
    }
    
    //Verifica se alguma tecla da coluna 4 foi pressionada
    if (digitalRead(11) == HIGH)
    {
      imprime_linha_coluna(ti-2, 4);
      while(digitalRead(11) == HIGH){} 
    }
   }
   delay(10);
}

void imprime_linha_coluna(int x, int y)
{
  if(x==1 && y==1){
    Serial.println("1");
    senha_criada('1');
  }
  if(x==1 && y==2){
    Serial.println("2");
    senha_criada('2');
  }
  if(x==1 && y==3){
    Serial.println("3");
    senha_criada('3');
  }
  if(x==1 && y==4){
    Serial.println("A");
    senha_criada('A');
  }
  if(x==2 && y==1){
    Serial.println("4");
    senha_criada('4');
  }
  if(x==2 && y==2){
    Serial.println("5");
    senha_criada('5');
  }
  if(x==2 && y==3){
    Serial.println("6");
    senha_criada('6');
  }
  if(x==2 && y==4){
    Serial.println("B");
    senha_criada('B');
  }
  if(x==3 && y==1){
    Serial.println("7");
    senha_criada('7');
  }
  if(x==3 && y==2){
    Serial.println("8");
    senha_criada('8');
  }
  if(x==3 && y==3){
    Serial.println("9");
    senha_criada('9');
  }
  if(x==3 && y==4){
    Serial.println("C");
    senha_criada('C');
  }
  if(x==4 && y==1){
    Serial.println("*");
    apagar_senha();
  }
  if(x==4 && y==2){
    Serial.println("0");
    senha_criada('0');
  }
  if(x==4 && y==3){
    Serial.println("#");
    enviar_senha();
  }
  if(x==4 && y==4){
    Serial.println("D");
    senha_criada('D');
  }
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
  Serial.println("Senha apagada com sucesso!\n");
}

void enviar_senha()
{
  Serial.print("Senha: ");
  Serial.println(senha);
  senha[0] = '\0';
}
