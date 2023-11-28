def sol(s,keword):
    compare_string = ''
    for i in s:
        if i.isalpha():
            compare_string += i
    if keword in compare_string:
        return 1
    else:
        return 0

s = input()
keyword=input()
print(sol(s,keyword))

# 출처: https://sunchol21.tistory.com/m/1118
