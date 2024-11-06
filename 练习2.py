#if用来判断按照不同条件执行不同代码
#if表达式：
#语句1
#语句二，注意if语句的后面有4个空格的符号，不能省略
x = 0
if x:
    print("It is True")
#注意，若x=false或为0，则无输出
#当为字典，列表，元组里无任何值时if语句输出也为错误
#当if=none时，也无输出
#else语句只能跟在if后，当if不能执行，则跟在后面的else语句可以被执行
else:
    print("It is False")
#------------------------------------
#当有多个条件时，可以使用elif语句，也不能单独出现，必须跟在if后面
#当一个if语句后面有多个elif时，只会执行第一个为正确的elif，当eilf和else同时出现，elif必须在else前面，不能使
#else在前
#循环
#while循环与if类似，语句的前面的4个空格不能省略
c = 1
while c <=10:
    print(c)
    c += 1
#若没有结束条件或结束条件出错，则会使while 循环一直持续下去，最后造成崩溃
#for循环
#for循环in序列
#序列里有项则继续执行，无项则结束
for i in (1,2,3,4,5):
    print(i)
#注意，语法格式可以是列表，元组和可迭代对象
for b in range(1,10):
    print(b)
#根据运行结果，range输出的是从1到9，即小于10的数
#使用range时也可以设定步长
for u in range(1,10,2):
    print(u)
#在循环中，若想立即停止输出，即可使用break来终止输出
print("--------------------------------------")
for e in range(10):
    if e > 5:
        break
    print(e)
#注意在输出时的缩进，以上print与if缩进一致，而并非在break后的输出结果‘
#continue与break相似，不过是跳过当前的输出数值
for a1 in range(10):
    if a1 == 5:
        continue
    print(a1)
#发现，使用continue后，数值5跳过了print的输出
#------------------------------------------
#在python中，缩进至关重要，有时在需要缩进的地方不需要任何值或要填入的内容还未想好，则使用pass来占位
print("---------------------------")
for a2 in range(10):
    if a2 == 3:
        pass
    else:
        print(a2)
print("----------------------------")
#在循环中，eise可以和if while for 一起组合使用，不是只能与if连用
#如：
count = 0
while count < 5:
    print(count,"is less than 5")
    count += 1
else:
    print(count,"is not less than 5")
print("---------------------------")
#加入break后，最后的代码块不会被执行
counts = 0
while counts < 5:
    print(counts,"is less than 5")
    if counts == 3:
        break
    counts += 1
else:
    print(counts,"is not less than 5")
#根据结果，else语句未被执行
