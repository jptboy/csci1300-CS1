'''
Author: Ayush Khanal CS1300 Fall 2017
Recitation: 204- Chelsea Chandler
Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
Recitation 13 - Problem # 4
'''
'''
Algorithim: Returns the onesum
	1.Use the outside for loop to increment up to n
	2.Use the inside for loop to increment up to the current incremented value of n and add the power of 10 to m to itself
    3.Finish and return that value
Input paramters: a positive int
Output:the onesum
'''
def oneSum(n):
    totsum=0#initialize the variable
    for i in range(1,n+1):#loop to n using n+1 otherwise it doesnt get to n
        for m in range(0,i):#loop to the current value of i
            totsum+=pow(10,m)#increment to the current value of i and add that to totsum
    return totsum#return totsum

def main():#who writes python with a main?
    print(oneSum(5))#test case 1
    print(oneSum(15))#test case 2

if __name__ == "__main__":
    main()#calling the main