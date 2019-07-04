void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}
int income = 0;
void loop()
{ 
  if(Serial.available()>0){
      income = Serial.read() - '0';
      Serial.print("Number get:");
      Serial.println(income);
    int a[4]={0, 0, 0, 0};
      int i = 0;
      while(income > 0){
        
        if(income % 2 == 0){
            a[i] = 0;
        }
        else{
            a[i] = 1;
        }
        income = income / 2;
        i ++ ;
    }
      for(int j=0;j<4;j++){ 
          if(a[j]==0){
              digitalWrite(j+2, LOW);
      }
          else{
              digitalWrite(j+2, HIGH);
      }  
    }
      Serial.println();Serial.print("The code is:");
      for(int p=0;p<4;p++){
          Serial.print(a[p]);
      }
    }
  }
