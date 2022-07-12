# Manual of DouLuo Game Demo

## 1. Basic elements:

```c++
class Soul;
class Ability;
class Ring;
class Bone;
class Beast;
class Buff;
```

#### 

## 2. Basic settings:

### (0) Background info:

```c++
enum class Attribute{attack, defense, control, support, heal};
enum class Age{ten, hundred, thousand, ten_thousand, god};
```



### (1) For Souls:

```c++
//Two copies,Basic ones and in-game ones
int level;		//Level of soul force
int exp;
int hp;				//Health point
int damage;		
int defense;
int speed;
std::vector<Ring> rings;
std::vector<Bone> bones;
std::vector<Ability> self_ability;
std::string name;

void display_info();
void revive();
Ability use_ability(int ability_num);
void add_ability(Ability new_ability);
void grow_hp(int growth);
void grow_damage(int growth);
void grow_defense(int growth);
void grow_speed(int growth);
void exp_level_up(int exp_growth);
void level_up(int growth);
```

### (2) For Rings:

```c++
//Levels that can grow after absorbing the ring
int force_growth;	
//Ability that the beast can use when it is alive,souls can use when the ring is absorbed
Ability ring_ability;
Age age;
```

### (3) For bones:

```c++
Ability bone_ability;
std::vector<Buff> buffs;
```

### (4) Ability

```c++
int basic_value;
int real_value;
Attribute attribute;
void effect(int object_value);
```

### (5) Beast

```c++
Ring ring;
Bone bone;
Age age;
std::string name;
```

### (6) Buff

```c++
Attribute attribute;
int value;
void buff(Soul object);
```



## 3. Game process

### (1) Get new ability:

```c++
void absorb(Soul absorber, Ring ring);
void absorb(Soul absorber, Bone bone);
```

### (2) Practice:

```c++
void practice(Soul practicer, int amount);
```

### (3) Game

```c++
int choose_ability(Soul user);
void use_ability(Soul user, Ability used_ability,Soul object);
void display_welcome();
void display_souls();
```

