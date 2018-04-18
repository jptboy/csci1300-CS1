'''
Author: Ayush Khanal CS1300 Fall 2017
Recitation: 204- Chelsea Chandler
Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
Recitation 13 - Problem # 2
'''
'''
Algorithim:
If the argument divided by 2 doesnt have a remainder its even otherwise its odd. 
'''
def odd_or_even(arg):
    if (arg%2==0):#If the argument divided by 2 doesnt have a remainder its even otherwise its odd. 
        print('even')
    else:
        print('odd')

def main():	
    odd_or_even(3)#Test Case 1
    odd_or_even(10)#Test case 2

if __name__ == "__main__":
    main()#calling the main