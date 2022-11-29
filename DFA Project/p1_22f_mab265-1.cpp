#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// creating a function called header which will store details data about course and will pass this function to main to print all the stored data.

void header()
{
    cout << "\nProject 1 for CS 341" << endl;
    cout << "Section number: 007" << endl;
    cout << "Semester: Fall 2022" << endl;
    cout << "Written by: Munavvarhusain Bunglawala, mab265" << endl;
    cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << endl;
}




void finalResult(  string userInput, string currState){

    if((currState == "q8")){
            cout << "\n***********Result***********" << endl;
            cout << "\nyour string  : " << userInput << endl;
            cout << "Accepted!" << endl;
            cout << "\n*****************************\n"<< endl;

    }
    else{
        cout << "\n***********Result***********" << endl;
         cout << "\nYour string : " << userInput << endl;
         cout << "Rejected" << endl;
         cout << "\n****************************\n"<< endl;

    }
    
    

    

}






char getNextChar(int i, string userInput, char myChar, string currState)
{



    // here, the implemetation and the purpose of try and catch is to see if the chacter from userInput string is out of index. 
    try                 
    {
        myChar = userInput.at(i);
    }
    catch (const ::out_of_range &e)
    {
        cout << "DFA Finish " << endl;
        exit(1);
    }

    return myChar;
}


void isValid(int i, string userInput, string currState, char myChar){
    if (i == userInput.size()-1)
    {
        finalResult(userInput, currState);
    }
    else
    {
        myChar = getNextChar(i, userInput, myChar, currState);
    }
}


// Creating a function for q9(trap state) which will pass important parameter and will validate if the current state is q9 then will pass the Rejection. 

void trapState(int i, string currState, char myChar, string userInput)
{
    currState = "q9";
    cout << myChar << " -> " << currState << endl;
    
    //myChar = getNextChar(i, userInput, myChar, currState);
    finalResult(userInput, currState);
    
  
    
}


/*
 Gamma = {a,b,c,d.....z}
 Phi = {@}
 Delta = {.}
 Lambda = {0,1,2...9}

*/

int myDfa(string userInput)
{

    string currState = "q1";   // setting my starting state of DFA to q1
    char myChar;                  
    




    cout << "\n  -> " << currState << endl;  // printing the starting state of DFA which is q1

    for (int i = 0; i < (userInput.size()); i++)   // running for loop which will itreate over entire user given string charcater by character. 
    {            

     
        myChar = userInput.at(i);  // setting first character from user given string to myChar


    

        if (currState == "q1")          
        {
            // Checking the condition if the first character of userInput string is in Gamma
            if ((myChar >= 'a' && myChar <= 'z'))     
            {
                currState = "q2";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
                
            }
            // here sending the myChar to q9(trap state) if the first character is not in Gamma
            else                                  
            {
                trapState(i, currState, myChar, userInput);
                break;
            }

        }

        else if (currState == "q2")
        {
              // here checking if myChar is @ if it is it will set the currState to q3 
            if ((myChar == '@'))                          
            {
                currState = "q3";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
                
               
            }
            // here checking if myChar is in Gamma(a-z) or in Lambda(0-9) it will keep on looping and will stay currState = q2
            else if ((myChar >= 'a' && myChar <= 'z') || (myChar >= '0' && myChar <= '9'))    
            {
                currState = "q2";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
             
            }
            // here, checking if myChar is in Delta(.) then it will send myChar back to state q1
            else if (myChar == '.')
            {
                currState = "q1";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
                
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput );
                 break;
            }
        }

        else if (currState == "q3")
        {
            //cout<<"mychar from q3 for outside trap state "<< myChar <<endl;
            
         
            if (myChar >= 'a' && myChar <= 'z')
            {
                
                currState = "q4";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
               
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput);
                break;
            }
        }

        else if (currState == "q4")
        {
             // here checking if myChar is in Gamma(a-z) or in Lambda(0-9) it will keep on looping and will stay currState = q4
            if ((myChar >= 'a' && myChar <= 'z') || (myChar >= '0' && myChar <= '9'))
            {
                currState = "q4";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
               
            }
              // here, checking if myChar is in Delta(.) then it will send myChar back to state q5
            else if (myChar == '.')
            {
                currState = "q5";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
               
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput);
                 break;
            }
        }

        else if (currState == "q5")
        {
            // here checking if the character is equal to c then setting the currState to q6
            if (myChar == 'c')
            {
                currState = "q6";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
              
            }
            // if the character is lowercased and is everything other than c it will set the currState to q4.
            else if ((myChar >= 'a' && myChar <= 'b') || (myChar >= 'd' && myChar <= 'z'))
            {
                currState = "q4";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
                
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput);
                 break;
            }
        }

        else if (currState == "q6")
        {
             // here checking if the character is equal to o then setting the currState to q7
            if (myChar == 'o')
            {
                currState = "q7";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
            }

             // here, checking if myChar is  (.) then it will send myChar back to state q5
            else if (myChar == '.')
            {
                currState = "q5";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
               
            }
            
             // if the character is lowercased and is everything other than o it will set the currState to q4.
            else if ( (myChar >= 'a' && myChar <= 'n') || (myChar >= 'p' && myChar <= 'z') || (myChar >= '0' && myChar <= '9') )
            {
                currState = "q4";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput);
                 break;
            }
        }

        else if (currState == "q7")
        {
             // here checking if the character is equal to m then setting the currState to q8
            if (myChar == 'm')
            {
                currState = "q8";
                
                cout << myChar << " -> " << currState << endl;
                isValid(i,userInput,currState,myChar);
            }
             // here, checking if myChar is equal to (.) then it will send myChar back to state q5
            else if (myChar == '.')
            {
                currState = "q5";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
                
            }
             // if the character is lowercased and is everything other than m it will set the currState to q4.
            else if ((myChar >= 'a' && myChar <= 'l') || (myChar >= 'n' && myChar <= 'z') || (myChar >= '0' && myChar <= '9'))
            {
                currState = "q4";
                cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput);
                 break;
            }
        }

        else if (currState == "q8")
        {
             // here, checking if myChar is equal to (.) then it will send myChar back to state q5
            if (myChar == '.')
            {
                currState = "q5";
                cout << myChar << " -> " << currState << endl;
                
               isValid(i,userInput,currState,myChar);
              
            }
            // if character is anywhere between lowercased a-z inclusive then it wil set currState to q4
            else if ((myChar >= 'a' && myChar <= 'z') || (myChar >= '0' && myChar <= '9'))
            {
                currState = "q4";
                 cout << myChar << " -> " << currState << endl;
                
                isValid(i,userInput,currState,myChar);
            }
            // here, if all the above condition fails and the the character in userInput string doesn't support the langauge of DFA it will go to q9 (Trap State)
            else
            {
                
                trapState(i, currState, myChar, userInput );
                 break;
            }
        }

    }

    return 0;
}



int main()
{

    header();    // calling header function to print course realted details. 


    string yesNo;   
    string userString;

    cout << "\nDo you want to enter a string (y/n)? : ";    
    getline(cin, yesNo);

    do{
        
        if(yesNo == "y")
        {
            cout<<"please Enter a string: ";
            getline(cin, userString);
            cout << "You Enterd : " << userString << endl; 
            myDfa(userString);

        }
        else{
            exit(1);
        }
        cout << "Please Enter a (y/n) : ";    
        getline(cin, yesNo);

    }while(yesNo == "y");

    
            
    return 0;
}
