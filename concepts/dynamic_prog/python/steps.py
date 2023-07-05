class DP():
    def __init__(self):
        print("DP Class initialized...")

    def two_step(self, n):
        """
        What are the different ways you can climb up n steps by only being 
        able to climb up one or two steps at a time? Think about this in terms
        of dynamic programming. 

        To reach step 3, you need to consider how many steps it would take from one step down
        and also two steps down. 

        To elaborate, think of it like this: 

        To reach step 3, you could either be at step 2 or step 1. The reason why this is so is because
        you can only go up by one step or two steps at a time. Thus, the possible ways you can get to step 3
        utilizing either of those ways is from one step down or two steps down.

        Similarly, to reach step 4, you would first need to calculate the number of ways to reach (4 - 1) steps 
        and (4 - 2) steps. When you add both together, you get the total possible ways to reach the 4th step. 

        Here's a breakdown: 

        1st step:
        - 1 step

        2nd step:
        - 1 step, 1 step
        - 2 step 

        3rd step: 
        - 1 step, 1 step, 1 step 
        - 2 step, 1 step
        - 1 step, 2 step

        4th step:
        - 1 step, 1 step, 1 step, 1 step
        - 2 step, 2 step
        - 2 step, 1 step, 1 step 
        - 1 step, 2 step, 1 step 
        - 1 step, 1 step, 2 step 

        5th step:
        - 1 step, 1 step, 1 step, 1 step, 1 step
        - 1 step, 2 step, 2 step
        - 2 step, 2 step, 1 step
        - 2 step, 1 step, 2 step 
        - 1 step, 1 step, 1 step, 2 step
        - 1 step, 2 step, 1 step, 1 step 
        - 1 step, 1 step, 2 step, 1 step
        - 2 step, 1 step, 1 step, 1 step 
        """

        dp = [0] * (n)
        dp[0] = 1
        dp[1] = 2 
        print(f"To get to 1 step: {dp[0]}\n\nTo get to 2 step: {dp[1]}\n")

        for x in range(2, n):
            dp[x] = dp[x - 1] + dp[x - 2]
            print(f"To get to {x + 1} step: {dp[x-1]}+{dp[x-2]} = {dp[x]}\n")
        print(dp)

    def three_step(self, n):
        """
        Similar to the two-step problem, but you get to climb up in either:
        1 step, 2 step, or 3 step increments 

        You can find the number of possible ways to get to the kth step by either:
        Going down one step, going down two steps, or going down three steps 

        It is the same algorithm as the two-step problem, but you have the choice 
        of a third-step.     
        """

        dp = [0] * (n)
        dp[0] = 1
        dp[1] = 2
        dp[2] = 4

        print(f"To get to one step: {dp[0]}\nTo get to two step: {dp[1]}\nTo get to three step: {dp[2]}\n")

        for x in range(3, n):
            dp[x] = dp[x - 1] + dp[x - 2] + dp[x - 3]
            print(f"To get to {x + 1} step: {dp[x-1]}+{dp[x-2]}+{dp[x-3]} = {dp[x]}\n")
        print(dp)

    def coin_amount(self, coins, amount):
        """
        With the coins in your wallet, how many different ways can you reach the 
        specified amount? 

        Example: Given a list of coins in your wallet [1, 5, 10], how many different
        combinations of these coins can be used to reach the specified amount? 

        Note that the coins in the list are of an infinite amount, meaning, given [1, 5, 10], that 
        means you have unlimited pennies, nickels, and dimes. 

        This is a dynamic programming problem in which the subproblems are the number of ways
        you can get the amount - x, which leads you to solve the number of ways you can get 
        amount. 

        Example: What are the possible ways you can get 10? 

        Well, you can get: 
        - 10 pennies
        - 1 nickel and 5 pennies
        - 1 dime
        - 2 nickels

        So, there are 4 ways you can get 10 from either pennies, nickels, or dimes. 

        Another way of looking at this is: To get all the possible ways from 1 to 4, you
        simply need one singular way, since you can only use pennies. 

        For example, you can't use a nickel to get 4, because the nickel is greater than 4. 

        Thus, to get 5, you know you can use either the pennies or the nickel, so everything from 5 to 9 
        would yield 2 possible ways. 

        By finding the number of ways to get the values below amount, you get to find the number of ways 
        to get the amount itself. Like to find the number of ways to get 5, you need to first find the
        ways you can get 5 subtracted by each coin less than or equal to 5. Thus, in this case, a nickel or penny (2 ways). 
        """
        amounts = [0] * (amount + 1)
        print(amounts)
        amounts[0] = 1
        for x in range(1, amount + 1):
            print(x)
        for coin in coins:
            print(f"Coin that is being evaluated: {coin}\n")
            for x in range(coin, amount + 1):
                amounts[x] += amounts[x - coin]
                print(f"Amount: {x}\nWays added: {amounts[x - coin]} from {x - coin}\nPossible ways: {amounts[x]}\n\n")
            print("\n\n\n")


if __name__ == "__main__":
    dp = DP() 
    dp.two_step(7)
    #dp.coin_amount([1, 5, 10], 10)
    #dp.three_step(8)
