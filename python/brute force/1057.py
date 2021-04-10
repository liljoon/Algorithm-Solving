inp_list = list(map(int, input().split()))
n = inp_list[0]
num1 = inp_list[1]
num2 = inp_list[2]
arr = list()


round = 0
while True:
    if num1 == num2:
        break
    else:
        num1 = (num1+1)//2
        num2 = (num2+1)//2

    round = round+1
print(round)
