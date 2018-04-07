/* there may be better ways to manipulate the I/O, but if there is, I have yet to 
 *  learn them.  I've done my best to keep the spirit of Mr. McWhorters exercise
 *  and execute it in a more user friendly input form (in my opinion) and add error
 *  checking to prevent it from running out of bounds, and ignore erroneous entries.
 */

#include <stdlib.h>       //needed for the atof() function

double grades[25];        //will initialize in a for loop
int possGrades = 25;      //Upper limit of entries allowed.
int numGrades = 0;        //all variables are initialized to prevent oddball values from memory being used accidentally
double avg = 0;           //had to change all the floats to double to support atof() function from the stdlib.h  If I were concerned
String input = "";        //about memory, I would have used one double, and typecast it back to floats, knowing that doubles were not needed otherwise.
char convert[11]={'\0'};  //these last two are to cover for the fact that Strings come from the C++ libraries, and can not be manipulated
double checking = 0;      //here in Arduino with the supporting C++ libraries. Must convert to C type char string.


void outputGrades(int);   //function prototype for final output
void initVars();          //function prototype to get things started, and re-started

void setup() {
  Serial.begin(9600);  
  
  initVars();             
}

void loop() {
  while(!Serial.available()){   //used the not (!) operator to test on return. saves the ==0
    }
  input=Serial.readString();
  Serial.print(input);          //echos the user's input for their own verification..  edification???  definatly not vacation... :)
  Serial.print(", ");
  
  if (input[0] == 'E' || input[0] == 'e'){    //while the first character of the string can be grabbed, it cannot use standard C functions like 'toupper()'
    outputGrades(numGrades);                  //function to print output.  (and it's formatted)
    initVars();                               //function which basically starts and restarts the input portion
  }
  
  else if(input[0] == 'C' || input[0] == 'c' && numGrades > 0){   //allows user to back up and correct entries.
    numGrades--;
  }
  
  else if(isDigit(input[0])){
    for (int k=0;k<=10;k++){            //ok, this gets odd. The great folks at Arduino gave us C++ strings, but none of the libraries which enable conversion.
      convert[k]=input[k];              //As such, I converted the string type to a char string type one character at a time.  After which, it's possible to 
    }                                   //convert by using C conversions.
  checking=atof(convert);
  grades[numGrades]=checking;
  numGrades++;
  }

  if(numGrades==25){                    // this prevents more than the alloted 25 entries. It simply processes the current 25 and resets as though "e" was entered.
    outputGrades(numGrades);
    initVars();
  }

}

void outputGrades(int numOfGrades){
  int total=0;
Serial.println();       
Serial.println();
  for (int i=0;i < numGrades;i++){    //loop for printing grade array
    total=total+grades[i];
    Serial.print(grades[i]);
    Serial.print(", ");    
    if((i+1)%5==0 && i>2){            //provides linefeed after 5 columns of output
      Serial.println();
    }
  }  
    avg=total/numGrades;
    Serial.println();
    Serial.print("The average of the grades is ");
    Serial.println(avg);              //here's the answer....   whoda' thunk it....
    Serial.println();
    Serial.println();
    return; 
}  


void initVars(){
  for (int i;i>=25;i++){  //initialize the grades array with NULL. 
    grades[i]='\0';
  }  
  numGrades = 0;
  avg = 0;
  input = "";
  Serial.println("Enter the grade, or E to end, or C to change the grade(s) just entered");
  return;
}

