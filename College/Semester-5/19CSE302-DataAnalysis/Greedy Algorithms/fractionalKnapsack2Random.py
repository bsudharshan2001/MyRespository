import time
import random

# sorting on the basis of value = (benefit/weight)

# class definition of Item, where each item has a weight and a value
class Item:
    def __init__(self, weight, benefit):
        self.weight = weight
        self.benefit = benefit

    def __lt__(self, x):
        return bool((self.benefit/self.weight) < (x.benefit/x.weight))
    
# returns the maximum possible value of the benefit
def fractionalKnapsack(arr, maxWeight):
    # sorting the array elements based on their values
    arr.sort(reverse = True)

    # this contains the current weight of the knapsack
    curWeight = 0

    totalBenefit = 0

    # this array stores the quantity of item i, selected
    x = []

    while curWeight < maxWeight:

        # curItem stores the item with the greatest value
        curItem = arr.pop(0)

        # a is the minimum of the weight of the item selected and the remaining weight
        a = min(curItem.weight, maxWeight - curWeight)

        # what is the share of benefit of the currItem that gets added to the totalBenefit
        totalBenefit += round(curItem.benefit * (a/curItem.weight),2)

        x.append(a)
        curWeight += a

    return totalBenefit

# main function to accept input from user
# the input from the user is stored in an array of Item objects
def main():
    n = int(input('Enter the number of items : '))
    arr = []
    for i in range(n):
        newItem = Item(random.randrange(1,100), random.randrange(1,100))
        arr.append(newItem)
    
    maxWeight = int(input('Enter maximum weight that can be accomodated in the knapsack : '))

    start = time.time()

    print(fractionalKnapsack(arr, maxWeight))

    end = time.time()

    print('Runtime : ',end-start)

main()