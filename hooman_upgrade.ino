//INITIALIZATION
const int numReads=5;
int reads[numReads];
int readI=0;
int total=0;
int average=0;
int inpin =A5;
int curav=0;
int oldav=0;
int change=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(7,OUTPUT);
//SET ARRAY TO HOLD VALUES=0
for (int thisRead=0;thisRead<numReads;thisRead++)
  reads[thisRead]=0;
}

void loop() {
  //INPUT TO ARRAY
  total=total-reads[readI];
  reads[readI]=analogRead(inpin);
  total=total+reads[readI];
  readI=readI+1;

  //RETURN AFTER numReads
  if(readI>=numReads)
  {
    readI=0;
  }

  //CALC AVG
  average=total/numReads;
  Serial.println(average);
  delay(100);

  //LED LOGIC
  curav=average;
  change=curav-oldav;
  if((change<=0)&&(curav<1000))
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
  }
  oldav=curav;
}
