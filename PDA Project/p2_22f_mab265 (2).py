


# In order to run this program you must have python 3.10 or above otherwise the match which is equvelent of switch statement will not work without latest version. 


class stack:             # using a stack to remember inputs
    def __init__(self) :
        self.items = []
    def emptyVal(self):     # empty func
        return self.item == []
    def pushVal(self, item):   # pushVal func which will add an element to the stack
        self.items.append(item)
    def popVal(self):    # popVal func which will remove an element from the stack
        return self.items.pop()
    def peekVal(self):    # peekVal func which will get the top most element of the stack
        return self.items[len(self.items)-1]
    def sizeVal(self):   
        return len(self.items)


def myPDA(string):

    myStack = stack()    # initialize the stack
    symbolVal = '*/+-'          # our set of valid symbols for PDA which we will itreate through while writing statements for specific state. 
    currState = 'q0'    # Initial state 
    finalState = 'q6'   # Accepting state also known as final state

    print('\nInitial state = ', currState)

    for char in string:         # Itreating over entire user enterd string and reading single char at a time.

        match currState:              # match is like a eqvielent of switch statement feature of other languages like java, c++ and you will need python 3.10 or above to use this feature in python.

            case "q0":          # Initial state or also can say that state 0 or q0

                if char == '%':            # checking if the first char of user enterd string is equal to '%' 
                    myStack.pushVal('%')    # if it is then push onto stack
                    currState = 'q1'          # and transiting to the next state 
                    print(char, ', ε -> % : After Transition Current State = ', currState)    # here, printing the transition and state after the transition that took place. 

                else:
                    print("\nprogram crashed at state", currState )    # if the first char is not a valid from user enterd string then it will show crahsed message and the state it happend at. 
                    print("The enterd string", string , "is denied!\n")
                    break

            case "q1":     # first state or also can say that state 1 or q1

                if char == '(':    # checking if the char of user enterd string is equal to '(' 
                    myStack.pushVal('(')   # if it is then push onto stack
                    currState = 'q1'     # and transiting to the next state
                    print(char, ', ε -> ( : After Transition Current State = ', currState)   
                
                elif char.isdigit():    # checking if the char of user enterd string is equal to digits which is like anything from 0-9. 
                    currState = 'q2'  # and then transiting to the next state
                    print(char, ', ε -> ε : After Transition Current State = ', currState)
                
                elif char == '.':  # checking if the  char of user enterd string is equal to '.'
                    currState = 'q3'   # and then transiting to the next state
                    print(char, ', ε -> ε : After Transition Current State = ', currState)
                
                else:                           # if the  char is not a valid from user enterd string then it will show crahsed message and the state it happend at. 
                    print("\nprogram crashed at state", currState )
                    print("The enterd string", string , "is denied!\n")
                    break
     
            case "q2":   # second state or also can say that state 2 or q2

                if char.isdigit():   # checking if the char of user enterd string is equal to digits which is like anything from 0-9. 
                    currState = 'q2'
                    print(char, ', ε -> ε : After Transition Current State = ', currState)
                
                elif char == '.':   # checking if the char of user enterd string is equal to '.'
                    currState = 'q4'
                    print(char, ', ε -> ε : After Transition Current State = ', currState)

                else:       # if the char is not a valid from user enterd string then it will show crahsed message and the state it happend at.
                    print("\nprogram crashed at state", currState )
                    print("The enterd string", string , "is denied!\n")
                    break
                
            case "q3":    # third state or also can say that state 3 or q3

                if char.isdigit():   # checking if the  char of user enterd string is equal to digits which is like anything from 0-9. 
                    currState = 'q4'
                    print(char, ', ε -> ε : After Transition Current State = ', currState)

                else:                 # if the char is not a valid from user enterd string then it will show crahsed message and the state it happend at.
                    print("\nprogram crashed at state", currState )
                    print("The enterd string", string , "is denied!\n")
                    break
            
            case "q4":    # fourth state or also can say that state 4 or q4

                if char.isdigit():  # checking if the  char of user enterd string is equal to digits which is like anything from 0-9.
                    currState = 'q4'
                    print(char, ', ε -> ε : After Transition Current State = ', currState)

                elif char in symbolVal:      # here , we are checking if the char from user enterd string falls under those defined char in symbolVal and are valid for our PDA which are '+-*/'
                    currState = 'q1'
                    print(char, ', ε -> ε : After Transition Current State = ', currState)

                elif char == '%':     # checking if the char of user enterd string is equal to '%' 
                    if myStack.peekVal() == '%':      # if it is then send it to peekVal function 
                        myStack.popVal()          # also call the popVal function 
                        currState = finalState         # and finally after this transition set the current state to final state or also known as accepting state or q6. 
                    else:
                        print("\nprogram crashed at state", currState )              # if the char is not a valid from user enterd string then it will show crahsed message and the state it happend at.
                        print("The enterd string", string , "is denied!\n")
                        break
                    print(char, ', % -> ε : After Transition Current State = ', currState)
 
                elif char == ')':          # checking if the char of user enterd string is equal to ')' 
                    if myStack.peekVal() == '(':       # call the peekVal func and check if the char is equal to '('
                        myStack.popVal()
                        currState = 'q5'          #  set current state equal to q5 or known as state 5
                    else:                                        # if the char is not a valid from user enterd string then it will show crahsed message and the state it happend at.
                        print("\nprogram crashed at state", currState )      
                        print("The enterd string", string , "is denied!\n")
                        break
                    print(char, ', ( -> ε : After Transition Current State = ', currState)

                else:
                    print("\nprogram crashed at state", currState )
                    print("The enterd string", string , "is denied!\n")
                    break

            case "q5":   # fifth state or also can say that state 5 or q5

                if char in symbolVal:      # here , we are checking if the char is either one of this '+-*/'
                    currState = "q1"     # if it is then setting the currState equal to q1 or known as state 1
                    print(char, ', ε -> ε : After Transition Current State = ', currState)

                elif char == ')':    # if the char is equal to ')'
                    if myStack.peekVal() == '(':   # use peekVal fun to see if the char is equal to '('
                        myStack.popVal()    # recall the popVal fun also
                        currState = "q5"    # then ser the currState to q5 or known as state 5
                    else: 
                        print("\nprogram crashed at state", currState )              # if the char is not a valid from user enterd string then it will show crahsed message and the state it happend at.
                        print("The enterd string", string , "is denied!\n")
                        break
                    print(char, ', ( -> ε : After Transition Current State = ', currState)

                elif char == '%':   # checking if the char of user enterd string is equal to '%' 
                    if myStack.peekVal() == '%':
                        myStack.popVal()
                        currState = finalState         # and finally after this transition set the current state to final state or also known as accepting state or q6.
                    else:
                        print("\nprogram crashed at state", currState )        
                        print("The enterd string", string , "is denied!\n")
                        break
                    print(char, ', % -> ε : After Transition Current State = ',  currState)

                else:
                    print("\nprogram crashed at state", currState )
                    print("The enterd string", string , "is denied!\n")
                    break
                
            case default:                 # this is default case where if something invalid is enterd it will just break the for loop. 
                break

    if currState == "q6":              # after itreating though all the states if the currState is equal to final state or known as state 6 or q6 then print the message that string enterd by user is accepted. 
        print("\nYour Enterd String", string, "is accepted! \n")
   
def main():          # main function 

    # printing out header details for the project.
    print("\nProject 1 for CS 341")                  
    print("Section number: 007")
    print("Semester: Fall 2022")
    print("Written by: Munavvarhusain Bunglawala, mab265")
    print("Instructor: Marvin Nakayama, marvin@njit.edu")

    while True:     
        yesNo = input("\nDo you want to enter a string ? (y/n) : ")    # getting user input in form of y or n and storing it in the varriable called yesNo.
        if yesNo == 'y':     # if user decided to enter y 
            userString = input("Please Enter a string: ")       # asking the user to enter a string of their choice 
            myPDA(userString)       # sending the user enterd string to myPDA function to further analyze
        else:           # if user decides to enter n then exit
            break        
if __name__ == "__main__":
    main()