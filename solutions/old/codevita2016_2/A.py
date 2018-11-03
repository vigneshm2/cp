from fractions import gcd
try:

    def lcm(a, b):
        return a * b // gcd(a, b)

    def calc_ans(lis):
        lcm_ans = 1
        for a in lis:
            lcm_ans = lcm(lcm_ans, a)
        return lcm_ans


    Total_flag = 0

    n = int(input())

    points = dict()
    points["Darrell"] = 0
    points["Sally"] = 0
    cur_playa = "temp"

    for i in range(n):
        line_val = input().split()

        #  invalid input
        if i%2==0 and len(line_val)!=2:
            print("Invalid Input")
            Total_flag = 1
            break

        if i%2==0 and (line_val[0]!="Sally" and line_val[0]!="Darrell"):
            print("Invalid Input")
            Total_flag = 1
            break

        if i%2==1 and (line_val[0]==cur_playa):
            print("Invalid Input")
            Total_flag = 1
            break


        if i%2==1 and len(line_val)!=3:
            print("Invalid Input")
            Total_flag = 1
            break

        if i%2==1 and line_val[0]!='A':
            print("Invalid Input")
            Total_flag = 1
            break

        
        if(i==0):
            if line_val[0] == "Darrell":
                first_player = 0
            else:
                first_player = 1
            

        if i%2==0:
            cur_playa = line_val[0]

            print(line_val[0] + "'s question is: " + line_val[1])
            numbers_check = list(map(int, line_val[1].split(",")))
            if len(numbers_check) < 2 or len(numbers_check) > 7:
                print("Invalid Input")
                Total_flag = 1
                break
            for num in numbers_check:
                if num<1 or num>100:
                    print("Invalid Input")
                    Total_flag = 1
                    raise ValueError()

        elif i%2==1:

            if(line_val[2]=="PASS"):
                print("Question is PASSed")
                output_ans = calc_ans(numbers_check)
                print("Answer is: " + str(output_ans))
                print( line_val[1] + ": 0points")

            else:
                answer_told = int(line_val[2])

                flag = 0
                for num in numbers_check:
                    if answer_told%num!=0:
                        flag = 1
                        break

                if flag==0:
                    print("Correct Answer")
                    print( line_val[1] + ": 10points")
                    points[line_val[1]] = points[line_val[1]] + 10

                else:
                    print("Wrong Answer")
                    print( line_val[1] + ": 0points")

    if Total_flag ==0:
        players_names = ["Darrell", "Sally"]
        print("Total Points:")
        print(players_names[first_player] + ": " + str(points[players_names[first_player]]) + "points")
        print(players_names[(first_player+1)%2] + ": " + str(points[players_names[(first_player+1)%2]]) + "points")

        if(points[players_names[0]] > points[players_names[1]]):
            print("Game Result: Darrell is winner")

        elif(points[players_names[0]] < points[players_names[1]]):
            print("Game Result: Sally is winner")
        else:
            print("Game Result: Draw")

except (RuntimeError, TypeError, NameError, ValueError):
    print("Invalid Input")