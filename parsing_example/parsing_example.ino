      //function prototype
  char commaTest();     
  
      //various counters and place holders
  int NemaLen = 0;
  int strStart = 0;
  int charCount = 0;
  int strCount = 0;
  
      //the two following statements recieve the raw string which would come from the gps and 
      //help in processing the string.
  char NemaRaw[78] = "";
  char test='a';

      //sorted strings from NEMA raw string
  char MsgID[7] = "";
  char TimeUTC[11] = "";
  char Status[2] = "";    
  char Lat[12] = "";
  char NS[2] = "";        
  char Lon[12] = "";
  char EW[2] = "";        
  char GndSpd[7] = "";
  char Course[7] = "";
  char Date[7] = "";
  char MagVar[7] = "";
  char MagVarDir[2] = " ";
  char ModeCkSum[7] = " ";

void setup() {
  Serial.begin(9600);
    //the following is an example string from the datasheet
  strcpy(NemaRaw,"$GPRMC,064951.000,A,2307.1256,N,12016.4438,E,0.03,165.48,260406,3.05,W,A*2C ");
  NemaLen = strlen(NemaRaw);
  pinMode(13,OUTPUT);
}

void loop() {
  
    //even with the 2 seconds of delay, with the LEDs switching, the sort is quick
delay(1000);
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);

    //sorting the full string into substrings. 
    //could have been done in a loop with an enum type probably, but I'm rusty...
while(test != '\0'){
  if (strCount==0){
    MsgID[strStart]=commaTest();
  }
  if (strCount==1){
    TimeUTC[strStart]=commaTest();
  }
  if (strCount==2){
    Status[strStart]=commaTest();
  }
  if (strCount==3){
    Lat[strStart]=commaTest();
  }
  if (strCount==4){
    NS[strStart]=commaTest();
  }
  if (strCount==5){
    Lon[strStart]=commaTest();
  }
  if (strCount==6){
    EW[strStart]=commaTest();  
  }
  if (strCount==7){
    GndSpd[strStart]=commaTest();
  }
  if (strCount==8){
    Course[strStart]=commaTest();
  }
  if (strCount==9){
    Date[strStart]=commaTest();
  }
  if (strCount==10){
    MagVar[strStart]=commaTest();
  }
  if (strCount==11){
    MagVarDir[strStart]=commaTest();
  }
  if (strCount==12){
    ModeCkSum[strStart]=commaTest();
  }
   
   };
      //print the sorted fields
   Serial.print(MsgID);
   Serial.print(" ");
   Serial.print(TimeUTC);
   Serial.print(" ");
   Serial.print(Status);
   Serial.print(" ");
   Serial.print(Lat);
   Serial.print(" ");
   Serial.print(NS);
   Serial.print(" ");
   Serial.print(Lon);
   Serial.println(" ");
   Serial.print(EW);
   Serial.print(" ");
   Serial.print(GndSpd);
   Serial.print(" ");   
   Serial.print(Course);
   Serial.print(" ");
   Serial.print(Date);
   Serial.print(" ");
   Serial.print(MagVar);
   Serial.print(" ");
   Serial.print(MagVarDir);
   Serial.print(" ");
   Serial.print(ModeCkSum);
   Serial.println();
   Serial.println();

}
      //in function, look for the comma.  If found, replace it with NULL and
      //set the string counter to move on to the next string, while returning the 
      //NULL to the current string.  otherwise return the letter to the 
      //sub-string being filled.
char commaTest(){
  test = NemaRaw[charCount];
    if(test==','){
      strStart=0;
      strCount++;
      charCount++;
      return '\0';
      }
    else{
      strStart++;
      charCount++;
      return(test);
    }
  
}






