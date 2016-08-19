# T3BattleTest
T3project 战斗平衡性测试工具
***
## 战斗阶段：
A attack B
    1. 计算B是否闪避
    2. 计算A是否暴击
    3. 计算A所产生的伤害值
    4. 计算B护甲减免，格挡减免
    5. B 获得伤害
    6. 第一轮计算结束，计算A是否产生combo
***
### B闪避几率计算：
* k1=1
* k2=1
* k3=1
* a=5

```
EvadePro(%)=（(B敏捷*k1+B装备闪避加成)-(A敏捷*k2+A装备准确度加成)）*k3+a
(5<=E<=95)
```

### A暴击几率计算：
* k1=1
* a=5

```
CriPro(%)=A敏捷*k1+A装备暴击几率加成+a
```

### A武器攻击力产生计算
```
WeaponAtk=武器伤害*（力量/武器力量需求）*(敏捷/武器敏捷需求)
```

### A伤害基本值：（双持武器仅计算单手）
```
AtkCount=左手武器攻击力+右手武器攻击力
```

### A暴击伤害：
* k1=0.01

```
CriCount=A伤害基本值*（k1*A力量+1）+A装备暴击伤害加成
```

### B格挡几率：
* k1=1
* a=5

```
BlockPro(%)=B敏捷*k1+B装备格挡几率加成+a
```

### B格挡抵消伤害：
* k1=0.5
* a=5

```
BlockCount=B力量*k1+B装备格挡抵消伤害+a
```

### B所受伤害：
```
Damage=A产生最终伤害值-B格挡-B护甲
最少会受到1点伤害
```

### combo几率：
* k1=0.1
* k2=5
* a=5

```
ComboPro(%)=（敏捷*k1+装备加成+常量a）-k2*(当前回合已产生combo次数)
```
