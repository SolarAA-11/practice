### 14.1
如果左操作数是类对象时, 重载操作符被声明为成员或者普通函数效果都一样.
如果左操作数是可以被转换为类对象的类型时, 声明为成员的重载操作符无法使用, 而普通函数能够正常使用.

### 14.2

```c++
class Sales_data{
public:
    Sales_data operator+=(const Sales_data&);
    friend istream& operator>>(istream& is, const Sales_data&);
    friend ostream& operator<<(ostream& os, const Sales_data&);
    friend Sales_data& operator=(Sales_data&, const Sales_data&);
};

```

### 14.3
1. char*
2. string
3. vector<string>
4. string

### 14.4
1. Member 
2. Member
3. Member
4. Member
5. Member
6. Member
7. Ordinary
8. Ordinary
9. Member

### 14.5

### 14.6

