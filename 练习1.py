#编程练习文档Main.py


#序列相加
x1 = [1,2,3,] + [4,5,6,7]
print("列表")
print(x1)
#注:只能在相同类型的序列间做连接操作

print("-----------")


#步长为1
x2 = [1,2,3,4,5,6,7]
print("列表")
print(x2 [1:5])
print(x2 [1:5:1])

print("------------")


#步长为2
print("元组")
x3 = (1,2,3,4,5,6,7)
print(x3 [1::2])
print(x3 [1::3])
print("-----------")

#步长不能为0，但可以为负数
x4 = "1234567890"
print("字符串")
print(x4 [5::-1])
print(x4 [5::-2])
print("------------")

#序列重复
x5 = [1,2,3] * 10
print("序列重复")
print(x5)
x6 = "123" * 10
print("字符串序列重复")
print(x6)

print("--------------")
#成员资格
#1.列表
print("列表")
print(5 in [1,2,3,4,5,6])
print("abc" in [1,2,3,4,5,6])
#2.元组+字符串
print(5 in (1,2,3,4,5,6))
print("abc" in (1,2,3,4,5,6))
print("2" in "123456")
print("abc" in "1,2,3,4,5,6")
#错误示范，print(5 in "123456"),无法运行，因为数字5和字符串"5"不同，所以应为("5" in "123456")

print("-----------------")
#长度，最小值，最大值，求和
a1 = a2 = a3 = a4 = [1,2,3,4,5,6,7]
print("列表")
print("列表长度",len(a1))
print("列表最小值",min(a2))
print("列表最大值",max(a3))
print("列表求和",sum(a4))
#注意:字符串没有求和，即sum函数
#如下
a5 = "123456789"
print("字符串:最小，最大，长度",len(a5),min(a5),max(a5))#此时填入sum(a5)报错
print("--------------")

#列表索引元素，以及对列表内元素进行替换，如下
a6 = [1,2,3,4,5,6,7,8]
print("列表第三位",a6 [3])
#替换元素在前
a6 [3] = "学习(／_＼)大怨种"
print("替换列表内的元素",a6)
#替换元素不能超过列表上限，如a6 [10] ="૮ ºﻌºა站岗"
print("-------------------")
#在列表后添加新元素，使用append函数
a7 = [1,2,3]
a7.append("(ꐦÒ‸Ó)你个老六")
print(a7)
#若新增多个元素，则使用extend函数
a8 = [1,2,3,4,5,6,7,8,9]
print("append")
a8.append([10,11])
print(a8)
a9 = [1,2,3,4,5,6,7,8,9]
print("extend")
a9.extend([10,11])
print(a9)
#从执行结果我们能很容易看出append和extend两种方法的不同效果，
#append无论后面是单个元素还是一个列表，都会把它当成一个新元素追加在原来的列表的后面，
#而extend则会展开，把新列表拆开追加在原来的列表后面。
print("--------------------")
#append和extend两种方法都是在列表的最后追加元素，那有没有什么办法可以在列表中间插入元素呢？
#Python里当然也提供了相应的方法，就是方法insert，例如：
b1 = [1,2,3,4,5,6,7,8]
print(b1)
print("----------")

print("insert")
b1.insert(3,"(*´I`*)")
print(b1)
#insert和append一样，只能一次添加一个元素
print("-----------------------")
#删除元素
b2 = [1,2,3,4,5,6,7,8]
print(b2)
print("pop()")
b3 = b2.pop()
print("result",b3)
print("list",b2)
print("------------------")
b4 = [1,2,3,4,5,6,7,8]
print("pop(3)")
b5 = b4.pop(3)
print("result",b5)
print("list",b4)
#pop()仅可以删除数字，删去元素需要remove
b6 = ["₍˄·͈༝·͈˄*₎◞ ̑̑","(*´I`*)","(˵¯͒〰¯͒˵)","(˃ ⌑ ˂ഃ )"]
print(b6)
b7 = b6.remove("₍˄·͈༝·͈˄*₎◞ ̑̑")
print(b7)#执行结果为None
print("list",b6)
#remove会删除查找到的第一个元素，且没有返回值
#使用函数del来删除列表元素
b8 = ["y1","y2","y3","y4"]
print("b8")
print("del")
del b8 [2]
print(b8)
#关键字“del”后是指定的列表元素和索引，
#从例子中可以看出，“del”删除了其中一个元素，
#元素数量从四个变成了三个。“del”不仅可以删除列表的元素，
#还能删除其他元素
print("----------------")
#查找元素
c1 = [1,2,3,4,5,6,7,8]
print(c1)
print("5 index is",c1.index(5))
print("3 index is",c1.index(3))
#注意，当查找元素不在给出的集时，python解释器会报错
#例如：c2 = [1,2,3,4]
#print("8 index is",c2.index(8))时，会出现报错，提示这个元素不在这个列表
print("------------------")
#队列的其他操作，使用reverse函数可以反转队列，和“[::-1]”类似，但使用reverse方法为修改原来的队列，并没有返回值。如：
c2 = [1,2,3,4,5,6,7,8]
print(c2)
print("reverse")
c2.reverse()
print(c2)
#count函数用于统计某个元素在列表里出现的次数，如：
c3 = [1,2,3,4,4,5,6,7,7,8]
print(c3)
print(c3.count(4))
print(c3.count(7))
print(c3.count(10))
print("-------------------")
#sort方法用于对列表进行排序，也可进行自定义排序。sort会修改原列表，无返回值
c4 = [1,5,3,4,2,9,8,1,6,7,5,4,3,8,6,4,2,9]
print(c4)
print("sort")
c4.sort()
print(c4)


#元组
#元组与列表很相似，但是元组与列表存在差异，列表可以修改，读取，删除
#但是元组在创建后就不可以修改，不可以删除单个元素，但是可以删除整个元组
#----------------------------------------------------------------
#定义元组
#列表使用[]框住元素，用“，”相隔。元组使用（），并使用“，”相隔
c5 = (1,2,3)
print(c5)
print(type(c5))
#注，若元组只有一个元素，则这个元素后面必须有“.”否则元素就还是其原来的类型。如：
c6 = (1)
print(c6,type(c6))
c7 = (1,)
print(c7,type(c7))
c8 = ("Hello")
print(c8,type(c8))
c9 = ("Hello",)
print(c9,type(c9))
#从执行结果可以看到，若只有一个元素，单单使用“（）”是不够的，还要再最后加上“，”，才能能定义一个元组
#-----------------------------------------------------------------
#删除元组
#由于元组不能修改，所以元组不能删除部分元素，要删除就只能删除全部元素，例如：
c10 = ("Hello",)
del c10
#print(c10),此时若运行，则提示错误，找不到变量c10
print("-------------------")
#元组的其他操作，如查找元素出现的次数。使用count函数来统计某个元素在元组里出现的次数
d1 = (1,29,37,44,42,95,88,26,35,48,71)
print(d1)
print(d1.count(44))
print(d1.count(48))
#index函数用于查找元素在元组里出现的次数
d2 = (1,3,6,5,2,8,7,1,5,8,5,1,9,3,4,6)
print(d2)
print("5 index is",d2.count(5))
print("----------------------------")
#------------------------------------------------------------------
#字典
#定义一个字典，可以向字典一样去查找。
#定义：
english = {
    "we":"我们",
    "world":"世界",
    "company":"公司"
}
print(english,type(english))
#字典可以是空字典
#从例子中我们可以很容易地看出，字典的元素是成对出现的，每个元素都是由“：”和键值对（“：”左边的称为键或者Key，“：”右边的称为值或者Value）构成，
# 元素和元素之间用“”分隔，整个字典用花括号“{}”包围。字典的键必须是唯一、不重复的，如果是空字典（一个元素都没有），则可以直接使用“{}”表示。例如：
empty = {}
print(empty,type(empty))
#使用字典，如
print("world",english["world"])
#注：用这种索引列标的方式查找值时，只能查找已有的值，当访问未被定义的值是会报错
#字典以列表类似，可以被删除，修改等，且以列表的操作方式类似
#注意，以下全部使用English字典，当修改，删除后修改为以上字典
print(english)
english["world"] = "shijie"
print(english)
#新增元素，修改元素语法相同
egn = {}
print(egn,type(egn))
egn["city"] = "城市"
#此时在egn中添加了一个元素
print(egn)
#修改字典元素
print(english)
del english["we"]
print(english)
#字典的其他操作，clear删除字典所有元素
print(english)
english.clear()
print(english)
#使用copy方法可以返回一个具有相同值的新字典，字典与列表一样，若只是赋值则是引用先前的内容，修改则改变先前的字典内容。
#copy方法类似于列表的[:]语法，相当于完整的复制了一份新的副本，例如：
english1 = {"we":"我们","city":"城市","company":"公司"}
english2 = english1
english3 = english1.copy()
print("english",english1)
print("english2",english2)
print("english3",english3)
print("-------------------------")
print("change english2")
english2["city"] = "城市2"
print("english1",english1)
print("english2",english2)
print("english3",english3)
print("--------------------------")
print("change english3")
english3["school"] =  "学校"
print("english1",english1)
print("english2",english2)
print("english3",english3)
print("------------------------")
#使用copy方法获取到的字典修改时只会修改复制出来的字典，不会修改原字典
#注意，当一个字典的元素还是一个字典，则使用copy命令只会浅复制最表层的字典，
#深层字典还是如english2一样引用，可以用深拷贝来解决
#------------------------------------
#fromkeys方法用于创建一个新的字典，用序列中的元素作为字典的键，第二个参数为字典所有参数对应的初始值。例如:
seq = ("name","age","class")
student1 = dict.fromkeys(seq)
print("不指定默认值",student1)
student2 = dict.fromkeys(seq,15)
print("指定默认值",student2)
#使用get方法返回对应键的值，若字典不存在对应值，则返回默认值
#使用keys来返回列表，从而返回字典里的所有键
print(egn.keys())
#--------------------------------------
#keys常常用于判断一个字典中是否有需要的值，与in组合使用
qwe = {"123":"456","789":"1234","45678":"13246"}
print("123是否在字典qwe中？","123" in qwe.keys())
print("0098是否在字典qwe中？","0098" in qwe.keys())
#使用values方法来返回一个列表，包含字典所有值
print("qwe字典的值",qwe.values())
#使用items来返回字典里的所有键列表和所有值列表
print(qwe.items())
#字典无法直接参与 for 循环，使用items方法来遍历字典
for k,v in qwe.items():
    print(k,"=>","v")

print("------------------------------")
#关于集合，空集合使用set（），注意不能使用{}，混合集合mix 数字集合number ，注意集合内不会包含重复的值
empty = set()
print(empty)
number = {1,2,3}
print(number)
mix = set([1,"cvd",9,"what"])
print(mix)
#若是空集合则必须用set()来定义
#在集合中添加元素使用add方法
number.add(5)
number.add(1)
print(number)
#若添加的元素在原集合里已有，则不会继续添加
#在集合中删除元素，使用remove
number.remove(2)
#remove不能删除不存在的信息
#python也可以进行集合间的数集运算p76
#列表推导式
d3 = [x for x in range(10)]
print(d3)
odd = [x for x in range(10) if x % 2 !=0]
print(odd)
#字典推导式
acc = {n: n**2 for n in range(10)}
print(acc)
acv = {v: k for k , v in acc.items()}
print(acv)
#集合推导式，与列表相似，但使用{}
dc = {i**2 for i in [-1,-5,1,2,-2]}
print(dc)
#此时运行，集合对于重复的运算结果只会输出一次
