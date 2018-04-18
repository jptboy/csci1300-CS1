'''
Author: Ayush Khanal CS1300 Fall 2017
Recitation: 204- Chelsea Chandler
Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
Recitation 13 - Problem # 3
'''
'''
Algorithim: Says fizzbuzz or fizz or buzz or n
	1.Use a for loop to increment up to the number and if the current value of i in the for loop is divisible by 3 print fizz or if its divisible by 5 print buzz or if its divisible by both print fizzbuzz otherwise print the number

Input paramters: a positive int
Output:the easiest CS interview question(why do companies ask this?)
'''
def fizz_buzz(arg):
    for i in range(0,arg+1):
        if i==0:#basic if else if and else if statements... no need to comment
            print(i)
        elif (i%5==0 and i%3==0):
            print('FizzBuzz')
        elif i%3==0:
            print('Fizz')
        elif i%5==0:
            print('Buzz')
        else:
            print(i)

def main():
    fizz_buzz(2)#Test Case 1
    fizz_buzz(123)#Test case 2

if __name__ == "__main__":
    main()#calling the main