
#include <iostream>
#include <cmath>

using namespace std;

void SeparateNumber(int num);

int main(){//main function
    int number=0;
    cout<<"Please enter the number:";//ask user for input
    cin>>number;
    SeparateNumber(number);//call function and pass the value
    
    return 0;
}

void SeparateNumber(int num){
    int count=0;
    int i=num;
    int result=0;
    while (i>0)//calculate the count and we can know how many digits
    {
        i=i/10;
        count++;
    }
    
    int c=0;
    int powerOfTen=count;
    int divisor=1;
    while(c<count-1){//calculate the divisor, we need to use this value later
        divisor=divisor*10;
        c++;
    }
    int whileCount=0; //to know how many times the while loop(line 52) run
    if(num==0){//if the number is 0
        cout<<"0"<<endl;
    }

    else{
        while(num>0){
            result=num/divisor;//calculate the value each line
            cout<<result<<endl;//print it one value one line

            if(num/divisor==1 && num==pow(10,powerOfTen))
            //if it is a special value like 10 or100 or 1000 and so on.
            //The reason I wrote the power is, if the input has"1",it will print extra"0"
            {
                
                //print 0s if the input is 100 or 1000 and so on
                for (int i=0; i<c; i++)
                {
                    whileCount++;//to make sure line 74-83 can work
                    cout<<"0"<<endl;
                }
                
            }
            num=num-result*divisor;//minus the biggest digit
            divisor=divisor/10;//divisor divided by 10, so we can calculate next number
            whileCount++;//to make sure line 74-83 can work
            powerOfTen--;//to make sure line 56 has the correct power
        }// end while loop(line 52)
        if(whileCount<count){
            //For example, if user enter "89100", the program will only print"891"
            //this while loop can add more 0s if user enter the number that many 0s at the
            //end of the number
            while(whileCount<count)
            {
                cout<<"0"<<endl;
                whileCount++;//to make sure the amount of 0s is correct
            }//end while loop
        }//end if (line 74)
        
        
    }//end else(line 51)
}//end function
