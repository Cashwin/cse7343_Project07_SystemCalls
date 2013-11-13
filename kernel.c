/* kernel.c
   A simple Kernel that displays a message.
   Ashwin Chandrasekhar and Preethi Rajagopalan
*/

void printString(char* String);             // Prints a string in the screen
//void readString(char* String);              // Reads a string from the input in the keyboard
//void readSector(char* buffer, int sector);  // Reads a sector of the image in the disk.
//void handleInterrupt21(int ax, int bx, int cx, int dx); // For the execution of interrupt21
//int mod(int a, int b);       // For Calculating mod function
//char line[80];
//char buffer[512];

//<------------------------------------  Main Function-------------------------------------->

int main() {
	
	printString("Hello World\r\n\0");   // related to step 1    
	//printString("Enter a line: \0");
	//printString("\r\n\0");    
	//readString(line);                   // related to step 2
	//printString("\r\n\0");
	//printString(line);                  // related to step 2
	//printString("\r\n\0");
	//readSector(buffer, 30);             // related to step 3
	//printString("\r\n\0");
	//printString(buffer);                // related to step 3
	//printString("\r\n\0");
	//makeInterrupt21();                  // related to step 4
	//interrupt(0x21, 1, line, 0, 0);     // related to step 5
	//printString("\r\n\0");
	//interrupt(0x21, 0, line, 0, 0);     // related to step 5
 	while(1) {
 		//todo
 	}
	return 0;
} //<----------------------------------- Main ends------------------------------------------->


//-------------------------------------printString Function---------------------------------->
void printString(char* String) {
	int i = 0;
	char c = String[i];
	while (c != 0) {
		interrupt(0x10, 0xE * 256 + c, 0, 0, 0);          //interrupt for printing on the screen.
		c = String[++i];
	}
}//-------------------------------------printString Ends------------------------------------->


//-------------------------------------readString Function---------------------------------->
/*void readString(char* String) {
	int index = 0;
	char c = 0;

	while(1) {
		c = interrupt(0x16, 0, 0, 0, 0);          // Interrupt for Accepting from keyboard,
		interrupt(0x10, 0xE * 256 + c, 0, 0, 0);  // Interrupt for printing on screen.
		if(c == 0xD) {                            // if ENTER
			String[index] = '\n';
		    String[index + 1] = 0;
			break;
		}
			
		if(c == 0x8) {                            // if BACKSPACE
			if(index > 0) {
				index = index -1; 	
			}		
    	}

		String[index] = c;
		++index;		
	}
}//-------------------------------------readString ends------------------------------------->


//-------------------------------------readSector Function---------------------------------->
void readSector(char* buffer, int sector) {
	int CL = mod(sector, 18);   
	int DH = mod(sector/18, 2);
	int CH = sector/36;

	interrupt(0x13, 2 * 256 + 1, buffer, CH * 256 + CL + 1, DH * 256 + 0);         // interrupt for reading a sector.

}//-------------------------------------readSector Ends------------------------------------->


//-------------------------------------Modulo Function-------------------------------------->
int mod(int a, int b) {
	while(a >= b)
		a = a - b;
	return a;
}//-------------------------------------Modulo ends----------------------------------------->



//-------------------------------------handleInterrupt21 Function---------------------------->
void handleInterrupt21(int ax, int bx, int cx, int dx) {
	printString("Hello World\r\n\0");
	if(ax == 0){
		printString(bx);
	}else if(ax == 1) {
		printString("Enter a line: ");
		readString(bx);
	} else if(ax == 2) {
		readSector(bx, cx);
	} else {
		printString("ERROR! Enter again...");
	}
}//-------------------------------------handleInterrupt21 ends------------------------------->
*/