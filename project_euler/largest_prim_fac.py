def find_next_prime(num):
    nm = num+1
    #print("finding next prime after %d" %num)
    while True:
        #print ("nm %d"%nm)
        for x in range (2,nm):
            #print ("x is %d"%x)
            if(nm%x==0):
                nm = nm+1
                break
            else:
                if(x == nm-1):
                    #print ("next prime num is %d "%nm)
                    return nm



usrnum = input("Enter the number")

current_prim = 2
highest_prim = 2

while(current_prim <= usrnum):
    if(usrnum % current_prim == 0):
        while (usrnum%current_prim == 0):
            usrnum = usrnum/current_prim
    highest_prim = current_prim
    current_prim = find_next_prime(current_prim)

print ("highest prime is %d" %highest_prim)
