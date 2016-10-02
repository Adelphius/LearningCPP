#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


string generate(string base, int len)
{	

	const char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',	
                     'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                     's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };		//array of letters
	
	const char symbols[] = { '!','@','#','$','%','^','&','*'};	//array of symbols
	
	string password="";	//password starts as empty

	if(base.length()>len)	// make sure the base word is not longer than the password to be created
	{
		//cout << "Length of password MUST be longer than the base word" << endl;
		return "Length of password MUST be longer than the base word";	//return the error for the user
	}
	
	int extra = len-base.length(); 	//get the amount of character to be added to the password
	int split = (rand()%extra)+1;	// randomly decide how many characters to put in front of the base wrd
	
	
	for(int i=0;i<split;i++)	// create characters before the base word
	{
		
		int type= rand()%4; 	//randomly decide type of character
		
		switch(type)
		{
			case 0:		//Type: number
				password += to_string(rand()%10);	//choose random number 0-9
				break;
			case 1:		//Type: lowercase letter
				password += letters[rand()%26];	//choose random letter from letters[]
				break;
			case 2:		//Type: Uppercase letter
				password += toupper(letters[rand()%26]);	//choose random letter from letters[] and make it uppercase
				break;
			case 3:		//Type: symbol
				password += symbols[rand()%8];	//choose random symbol from symbols[]
				break;
		}
	}
	
	
	password += base; // add the base word to the passowrd
	
	for(int i=0; i<extra-split;i++)	//fill in the rest of the password after the base word
	{
		int type= rand()%4;	//same as above
               
                switch(type)
                {
                        case 0:
                                password += to_string(rand()%10);
                                break;
                        case 1:
                                password += letters[rand()%26];
                                break;
                        case 2:
                                password += toupper(letters[rand()%26]);
                                break;
                        case 3:
                                password += symbols[rand()%8];
                                break;
                }
	}

	
	return password;	//return the password to be printed
}
	

int main(int argc, char* argv[])
{
	srand(time(NULL));	//set the random seed to time (prevent the same password each time)

        if(argc<3)	//check if the required arguments exist
        {
                cout <<"Enter Arguments -> passGen [BaseWord] [PasswordLength]"<< endl;	//if not then print this error
                return 1;	//close the program to prevent errors
        }
        else{
                string base = argv[1];			//set the bas word
                int len = stoi(argv[2]);		//set the length to be outputted
             	cout << generate(base, len)<<endl;	// pass base and length to generate and print the result
        }
 
 
        return 0;	//end
}
