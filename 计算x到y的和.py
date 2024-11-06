print("计算从x到y的和（仅限正数）")
x=int(input("输入一个数字x:"))
y=int(input("输入一个数字y："))
z=x
a=0
c=y
if x>y:
    print("你可能输错啦，将按照y到x计算")
    while y <= x:
        a = a + y
        y += 1
    print('%d到%d的和为：%d' % (c, z, a))

else:
    while x<=y:
        a = a + x
        x += 1
    print('%d到%d的和为：%d' % (z, y, a))