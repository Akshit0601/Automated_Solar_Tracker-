#include <Servo.h>
Servo servo;
int value;
int pos;
int arr[181];
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
    delay(10);
    value=analogRead(A0);
    arr[i]=value;
    
  }
  int max_value=largest(arr,180);
  int pos_servo=position(arr,180);
  Serial.println(max_value);
  Serial.println(pos_servo);
  servo.write(pos_servo);
  delay(10);
  
  int current_value=analogRead(A0);
  while(current_value==max_value){
  current_value=analogRead(A0);
    
  delay(1);
  }
  
}
