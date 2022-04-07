#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>

using namespace std;

const int maxDigit=9; //max digi count for secret number and user input
const int MaxGuessCount=100; //max count of gusses user have

//takes char a pointer and checks all characters till sentinel character. returns 0 if there exits non digit character.
int is_number(char* str){
    int retval=1,i=0;
    while(str[i] !='\0') {
        if(!isdigit(str[i]))
            retval= 0;
        i++;
    }
    return retval;
}

//takes number as int array and checks if the digits unique. if there is duplication return 0, otherwise 1.
int is_valid(int num_digits[], int digit_count){
    int retval=1,i,j;
    //if number starts with zero it's invalid input
    if(num_digits[0]==0)
        retval=0;
//iterate through given digit array and compare its elements with each other
    for(i=0;i<digit_count;i++){
        //inner loop iterate from num_digits[i+1] to num_digits[digit_count-1]
        for(j=i+1;j<digit_count;j++){
            if(num_digits[i]==num_digits[j])
                retval=0;
        }
    }
    return retval;
}

//transform char array consist of digits to int array stores into num_digits[] array and returns array lenght
int split_into_digits(char num[], int num_digits[]){
    int retval=1,i=0,j;
    while(num[i] !='\0'){
        num_digits[i]= num[i]-48;
        i++;
    }
    return i;
}
//it takes digit count for secret number and int array to store the randomly produced digits of secret number
//returns uniqueness info as return value
int produce_secret_number(int secret_number_digits[],int digit_count){
    int rand_digit,i=0,unique=1;
    //if current index zero assign random number within range [1,9]
    if(i==0){
        rand_digit=rand()%9 +1;
        secret_number_digits[i]=rand_digit;
    }
    do{
        i++;
        srand(time(NULL));
        rand_digit=rand()%10;
        secret_number_digits[i]=rand_digit;
        //check if last assigned digit exits in th privous part of secret number
        unique=is_valid(secret_number_digits,i+1);

        //if number produced for digit of secret number is not unique continue to produce
        while(unique==0){
            srand(time(NULL));
            rand_digit=rand()%10;
            secret_number_digits[i]=rand_digit;
            //check if currently produced secret number is valid if not continue to producr randomly
            unique=is_valid(secret_number_digits,i+1);
        }
    //if digit limit haven't been reaches continue
    }while(i<digit_count);

    unique=is_valid(secret_number_digits,digit_count);
    return unique;
}

//it takes two int array and compare elements
int compare_input_and_secret(int arr_user_input[], int arr_secret_number[], int digit_count ){
    int i,j;
    int first_count=0,second_count=0,found=0;
//iterate through given input and secret number arrays and compare their elements
    for(i=0;i<digit_count;i++){
        for(j=0;j<digit_count;j++){
            if(arr_user_input[i]==arr_secret_number[j]){
                //increment first count if digit and index of digit are same in the both arrays
                if(i==j)
                    first_count++;
                //increment secound_count if digit same but index different
                else
                    second_count++;
                //if a match found between secret and input, break inner for loop since a number cannot occur again.
                break;
            }
        }
    }

    //after traversing the input if first_count and digit_count is same then user guess is correct
    if(first_count==digit_count)
        found=1;
    //print recorded hints for the input similarit with secret number
    if(!found)
        cout<<"Digit count that their position matches with secret number:"<< first_count<<" \nDigit count that are not in right position: "<<second_count<<endl;

    return found;
}

//take secret number sequence and digit count provided for the game
void play_mastermind(int secret_num_digits[], int digit_count){
    //declarations of required variables
    int guess_count=0;
    int input_digits[maxDigit];
    //is found:1 if user found secret number
    //valid:1 if user input matches criterias
    //is_int:1 if input contains only integers
    int is_found=0,valid=0,is_int,input_lenght;
    //user input as char array
    char user_input[digit_count];

    do{
        //wait for user input and store as char array
        cin>> user_input;
        //if user guess negative  exit
        if(user_input[0]=='-'){
            cout<<"Input must be positive number!! "<<endl;
            exit(1);
        }
        //check if input contains all digits
        is_int=is_number(user_input);

        //exit if all characters are not digits
        if(is_int==0){
            cout<<"Input must consist of only digits!!"<<endl;
            exit(1);
        }
        //check digit count
        input_lenght=split_into_digits(user_input,input_digits);

        if(input_lenght != digit_count){
            //exit if user input digit count not right
            cout<<"Digit Count doesn't match with chosen digit count!!"<<endl;
            exit(1);
        }
        //check validity of user input
        valid=is_valid(input_digits,input_lenght);

        //exit if user input digits are not unique or starts with zero.
        //input suppose to be match secret number criterias since user try o guess the secret number

        if(!valid){
            cout<<"E1\n Invalid Guess format for Secret Number!!\n"<<endl;
            exit(1);
        }
        //if input format correct increase guess_count and continue to compare digits
        guess_count++;
        //compare input and secret number
        is_found=compare_input_and_secret(input_digits,secret_num_digits,digit_count);
        //if input matches exit game
        if(is_found==1){
            cout<<"Congragulations!! You won :)) Guess Count: "<<" "<<guess_count<<endl;
            break;
        }

    }while(guess_count<=MaxGuessCount);
//if user couldn't find secret number for 100 guess, user failed. game over.
    if(guess_count==MaxGuessCount){
        cout<<"FAILED"<<endl;
        exit(1);
    }

}

//give parameters to main in order to take arguments from command line
//argc: number provided of arguments. argv: list of strings containing the comand line arguments
int main(int argc, char** argv){
    //declarations of related variables
    int secret_number, secret_num_digits[maxDigit];
    int digit_count,unique,i;
    //set initial digits as -1
    for(i=0;i<maxDigit; i++)
        secret_num_digits[i]=-1;

    //checking  if there is missing or extra command line arguments
    if(argc !=3){
        cout<<"Invalid Initial Inputs!! "<<endl;
        exit(1);
    }
    //checking if arguments correct
    //exit if flags from command line argument is not -r or -u.
    if(!(argv[1][0]=='-' && (argv[1][1]=='r' )){
        cout<<"Invalid flag!! Please enter the input in following format to replay: <executiable_file> <-r> <digit_count>  "<<endl;
        exit(1);
    }
    //if -r then number of digits in secret number should be provided. digit count should be n<=9.
    if(argv[1][1]=='r'){
        // check secret number contains only digits
        //exit if value contains non-digit characters.
        if(is_number(argv[2])!=1){
            cout<<"Digit count must be an integer!!"<<endl;
            exit(1);
        }

        digit_count= stoi(argv[2]);
        //if digit count within range
        if(digit_count<=maxDigit && digit_count>0){
            //produce a valid secret number
            unique=produce_secret_number(secret_num_digits,digit_count);
            //play mastermind when valid secret number produced
            if(unique){
                play_mastermind(secret_num_digits,digit_count);
            }
        }
        //exit if digit_count does not match the conditions.
        else{
        cout<<"Invalid digit count!!! Digit count must be between [1-9]"<<endl;
        exit(1);
        }
    }
}
