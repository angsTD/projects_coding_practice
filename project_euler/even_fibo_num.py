a=0
b=1
next_fib = 0
sum_even = 0

while True:
    next_fib = a+b
    if(next_fib > 4000000):
        print sum_even
        break
    if(next_fib%2==0):
        sum_even = sum_even + next_fib
    a = b
    b = next_fib

