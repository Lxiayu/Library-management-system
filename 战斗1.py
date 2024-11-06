attack_vals = {
    "藏獒": 70,
    "大黄": 50,
    "杜宾": 30,
}


def dog(name, d_type):
    data = {
        "name": name,
        "d_type": d_type,
        "attack_val": attack_vals,
        "life_val": 100,
    }
    if d_type in attack_vals:
        data["attack_val"] = attack_vals[d_type]
    else:
        data["attack_val"] = 15
    return data


def person(name, age):
    data = {
        "name": name,
        "age": age,
        "life_val": 100,
        "has_heal_item": True,  # 初始设定人没有回血道具
        "heal_amount": 0,  # 对回血道具、技能（可能有？）的可恢复量进行初始化，即为0
    }
    if age > 18:
        data["attack_val"] = 50
    else:
        data["attack_val"] = 30
    return data


def person_heal(person_obj, heal_amount):
    person_obj["life_val"] += heal_amount
    print("[%s]恢复了[%s]点生命值"%(person_obj["name"],person_obj["heal_amount"]))


p1 = person("XYZ", 20)
d1 = dog("大黄", "藏獒")
d2 = dog("小黄", "杜宾")
d3 = dog("小黑", "大黄")


def dog_bite(dog_obj, person_obj):
    person_obj["life_val"] -= dog_obj["attack_val"]
    print("狗[%s]咬了[%s]一口，造成[%s]点伤害，[%s]还剩[%s]血量"
          %(dog_obj["name"],person_obj["name"],
            dog_obj["attack_val"],person_obj["name"],person_obj["life_val"]))


def person_beat(person_obj, dog_obj):
    dog_obj["life_val"] -= person_obj["attack_val"]
    print("人[%s]打了[%s]一下，造成[%s]点伤害，[%s]剩余[%s]血量"
          %(person_obj["name"],dog_obj["name"],
            person_obj["attack_val"],dog_obj["name"],dog_obj["life_val"]))


def battle_round(person_obj, dog_obj):
    round_num = 1

    print("回合开始，当前[%s]有[%s]点生命值，[%s]有[%s]点生命值"
          %(person_obj["name"],person_obj["life_val"],
            dog_obj["name"],dog_obj["life_val"]))

    while True:
        print(f"第{round_num}回合开始：")

        person_choice = input(f"{person_obj['name']}，"
                              f"请选择行动（1. 攻击  2. 使用道具（X）  3. 防御（X））：")
        if person_choice == "1":
            person_beat(person_obj, dog_obj)
        elif person_choice == "2":
            print("没实现使用道具。")
        elif person_choice == "3":
            print("没实现防御功能。")

        if dog_obj["life_val"] <= 0:
            print(f"狗[{dog_obj['name']}]已死亡，人[{person_obj['name']}]获胜！")
            heal_amount = 20  # 设定狗被击败后的回血量
            person_heal(person_obj, heal_amount)
            break

        # 检查狗是否还活着，如果活着则狗行动
        if dog_obj['life_val'] > 0:
            dog_choice = input(f"{dog_obj['name']}，"
                               f"请选择行动（1. 攻击  2. （pass））：")
            if dog_choice == "1":
                dog_bite(dog_obj, person_obj)
            elif dog_choice == "2":
                print("暂未实现其他狗行动功能。")

        if person_obj["life_val"] <= 0:
            print(f"人[{person_obj['name']}]已死亡，狗[{dog_obj['name']}]获胜！")
            break

        round_num += 1

    print(
            f"回合结束，当前人[{person_obj['name']}]"
            f"生命值：{person_obj['life_val']}，"
            f"狗[{dog_obj['name']}]生命值：{dog_obj['life_val']}")


battle_round(p1, d1)


while True:
    command = input("请输入指令(‘heal’回血，‘quit’退出)")
    if command == "heal":
        if p1["has_heal_item"]:
            p1["life_val"] += p1["heal_amount"]
            print("[%s]使用了回血道具，回复了[%s]点血量，当前血量为[%s]"
                  %(p1["name"],p1["heal_amount"],p1["life_val"]))
        else:
            print("[%s]没有回血道具，无法回血")
    elif command == "quit":
        break