#include <Servo.h>
Servo servo;
int value;
int pos;
int arr[180];
int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
      if (arr[i] > max){
      max = arr[i];
    }
    return max;
}
int position(int arr[], int n){
    int i,j;
  j=0;
    int max = arr[0];
    for (i = 1; i < n; i++)
      if (arr[i] > max){
      max = arr[i];
      j=i;
    }
    return j;
}
void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  servo.attach(9);
  
}
void loop(){

 
  for(int i=0;i<=180;i++){
    servo.write(i);
    delay(5);
    value=analogRead(A0);
    arr[i]=value;
    
  }
  int max_value=largest(arr,180);
  int pos_servo=position(arr,180);
  servo.write(pos_servo);
  delay(10);
  
  int current_value=analogRead(A0);
  while(current_value==max_value){
  delay(1);
  }
  servo.write(0);
}
