// 1. 输入/输出 (Input/Output)
#include <iostream>   // 用于标准输入/输出流 (cin, cout, cerr)
#include <fstream>    // 用于文件输入/输出流
#include <sstream>    // 用于字符串流
#include <iomanip>    // 用于格式化输出 (setprecision, setw等)

// 2. 容器 (Containers)
#include <vector>     // 动态数组
#include <string>     // 字符串
#include <list>       // 双向链表
#include <deque>      // 双端队列
#include <map>        // 有序键值对容器
#include <set>        // 有序唯一元素容器
#include <unordered_map> // 无序哈希表键值对容器
#include <unordered_set> // 无序哈希表唯一元素容器
#include <queue>      // 队列
#include <stack>      // 栈

// 3. 算法 (Algorithms)
#include <algorithm>  // 各种通用算法 (sort, find, for_each等)
#include <numeric>    // 数值操作 (accumulate, partial_sum等)

// 4. 功能 (Functions)
#include <functional> // 函数对象、绑定器 (std::function, std::bind等)

// 5. 数学 (Mathematics)
#include <cmath>      // 常用数学函数 (sqrt, pow, sin, cos等)

// 6. 内存管理 (Memory Management)
#include <memory>     // 智能指针 (shared_ptr, unique_ptr, weak_ptr)

// 7. 异常处理 (Exception Handling)
#include <exception>  // 异常基类
#include <stdexcept>  // 标准异常类 (runtime_error, logic_error等)

// 8. 工具 (Utilities)
#include <utility>    // 实用工具 (std::pair, std::move, std::forward等)
#include <tuple>      // 固定大小的异构元素集合

using namespace std;

//===============================================================
int func1(char x, const vector<int>& scores)
{
    if (!('A'<=x && x<='F')) return -1;
    else {
        int frontier=100;
        int diff=x-'A';
        int count=0;
        frontier=frontier-10*diff;
        for (auto &it: scores) {
            if (x=='A') {
                if (it<=100 && it>=90) count++;
            }
            if (x=='F') {
                if (frontier>=0 && frontier<=59) count++;
            }
            else {
                if (it<frontier && it>=frontier-10) count++;
            }
        }
        return count;
    }
}

//===============================================================

//判断是否为质数
bool is_prime(int n) {
    if (n<=1) return false;
    if (n==2) return true;
    else {
        for (int i=2;i<n;++i) {
            if (n%i==0) return false;
        }
        return true;
    }
}
//判断是否为奇数
bool is_odd(int n) {
    if (n%2==0) return false;
    return true;
}

int func2(int n) 
{
    int count=0;
    if (n<=0) return -1;
    int start=1;
    while (count!=n) {
        if (is_odd(start) && !is_prime(start)) {
            count++;
        }
        start+=2;
    }
    return start;
}

//===============================================================
//编写函数看是赢还是输，赢则输出1，输则输出0
int judge(char c1,char c2) {
    if (c1=='R' && c2=='S') return 1;
    else if (c1=='S' && c2=='R') return 0;
    else if (c1=='R' && c2=='P') return 0;
    else if (c1=='P' && c2=='R') return 1;
    else if (c1=='P' && c2=='S') return 0;
    else if (c1=='S' && c2=='P') return 1;
}
vector<string> func3(char a, char b, char c) 
{
    vector<string> result;
    if (a==b && b==c) {
        result.push_back("Draw");
        result.push_back("Draw");
        result.push_back("Draw");
    }
    else if (a!=b && b!=c && a!=c) {
        result.push_back("Draw");
        result.push_back("Draw");
        result.push_back("Draw");
    }
    else {
        if (a!=b && a!=c) {
            if (judge(a,b)) {
                result.push_back("Win");
                result.push_back("Lose");
                result.push_back("Lose");
            }
            else {
                result.push_back("Lose");
                result.push_back("Win");
                result.push_back("Win");
            }
        }
        else if (b!=a && b!=c) {
            if (judge(b,a)) {
                result.push_back("Lose");
                result.push_back("Win");
                result.push_back("Lose");
            }
            else {
                result.push_back("Win");
                result.push_back("Lose");
                result.push_back("Win");
            }
        }
        else {
            if (c!=a && c!=b) {
                if (judge(c,a)) {
                    result.push_back("Lose");
                    result.push_back("Lose");
                    result.push_back("Win");
                }
                else {
                    result.push_back("Win");
                    result.push_back("Win");
                    result.push_back("Lose");
                }
            }
        }
    }
    return result;
}

//===============================================================
//求各位数字之和的函数
int sum_of_each_digit(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum+=digit;
        n /= 10;
    }
    return sum;
}

//求最高位与最低位数字之和
int sum_of_top_and_foot(int n) {
    int sum=n%10;
    while (n > 0) {
        if (n<10) {
            sum+=n;
            break;
        }
        n/=10;
    }
    return sum;
}

//计算一个整数的位数
int cal_digit(int n) {
    int counter=0;
    while (n > 0) {
        n/=10;
        counter++;
    }
    return counter;
}

vector<int> func4(int n, int m) {
    vector<int> result;

    for (int i=n;i<=m;++i) {
        if (i%sum_of_each_digit(i)==0 && sum_of_top_and_foot(i)%2!=0) result.push_back(i);
    }

    sort(result.begin(),result.end(),[](int& a,int& b) {
        if (cal_digit(a)!=cal_digit(b)) return cal_digit(a)<cal_digit(b);
        return a>b;
    });

    return result;
}

//===============================================================
//判断哪个向量更长
vector<int> longerVector(const vector<int>& vec1, const vector<int>& vec2) {
    int l1 = vec1.size();
    int l2 = vec2.size();
    if (l1>=l2) return vec1;
    return vec2;
}

vector<int> func5(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> result;
    //判断是否为空
    if (v1.empty()||v2.empty()) {
        for (auto& it:longerVector(v1,v2)) {
            result.push_back(it);
        }
    }
    else if (v1.empty()&&v2.empty()) return {};
    else{
        for (int i=0;i<min(v1.size(),v2.size());++i) {
            result.push_back(v1[i]);
            result.push_back(v2[i]);
        }
        if (v1.size()!=v2.size()) {
            for (int i=min(v1.size(),v2.size());i<longerVector(v1,v2).size();++i) {
                result.push_back(longerVector(v1,v2)[i]);
            }
        }
    }

    vector<int> final_result;
    for (int i=0;i<result.size();++i) {
        int start = i;
        final_result.push_back(result[start]);
        while (start!=result.size()-1&&result[i+1]==result[start]) {
            i++;
            if (i==result.size()) break;
        }
    }

    return final_result;
}

//===============================================================
class Student {
private:
    // TODO 1: 声明合适的数据成员来存储学生的基本信息和成绩
    // 提示: 需要存储学生的姓名和多门课程的成绩。
    

public:
    // 构造函数
    // TODO 2: 实现构造函数，用于初始化学生姓名。
    Student(const string& name);

    // 成员函数: 添加一门课程的成绩
    // TODO 3: 实现 add_score 函数，将一个成绩添加到成绩列表中。
    void add_score(double score);

    // 成员函数: 计算平均分
    // TODO 4: 实现 get_average_score 函数，计算并返回所有课程的平均分。
    // 如果没有任何成绩，返回 0.0。
    double get_average_score() const;

    // 成员函数: 获取姓名
    // TODO 5: 实现 get_name 函数，获取学生姓名
    string get_name() const;
};

Student::Student(const string& name)
{
}

void Student::add_score(double score)
{
}

double Student::get_average_score() const
{
    return 0;
}

string Student::get_name() const
{
    return "";
}

void func6(const string name, const vector<double>& scores)
{
    Student s { name };
    for (double d : scores) {
        s.add_score(d);
    }
    cout << s.get_name() << ' ' << s.get_average_score() << endl;
}

//===============================================================
//======CSet类定义====
class CSet {
    // TODO1: 实现加法运算符重载函数
    friend CSet operator+(const CSet& set1, const CSet& set2);

    // TODO2: 实现输出运算符重载函数
    friend ostream& operator<<(ostream& out, const CSet& obj);

private: 
    vector<int> m_set;   // 存放元素的向量
    bool m_sortflag;     // 元素排序规则；true--升序排序，false--降序排序

public:
    CSet(const vector<int>& vec = {}, bool sortFlag = true); // 带默认参数的构造函数
    bool hasValue(int value) const; // 查找值value是否在集合中
    void print() const; // 打印集合中所有元素
};

//=======CSet类实现=====
CSet::CSet(const vector<int>& vec, bool sortFlag) // 带参数的构造函数
{
    m_sortflag = sortFlag;
    m_set.clear();
    for (auto x : vec) {
        if (!hasValue(x)) {
            m_set.push_back(x);
        }
    }
    if (sortFlag)
        sort(m_set.begin(),m_set.end()); 
    else
        sort(m_set.begin(), m_set.end(), greater<int>());
}

// 查找值value是否在集合中
bool CSet::hasValue(int value) const
{
    for (unsigned i = 0; i < m_set.size(); ++i) {
        if (m_set[i] == value)
           return true;
    }
    return false;
}

// 打印集合中所有元素
void CSet::print() const
{
    for (int e : m_set) cout << e << ' ';
    cout << endl;
}

//===========友元函数==============
//==加法运算符重载函数=====
CSet operator+(const CSet& set1, const CSet& set2)
{
    CSet cs({0}, 1);
    return cs;  
}

//===输出运算符重载函数====
ostream& operator<<(ostream& out, const CSet& obj)
{
    return out;
}



void func7a(const vector<int>& v1, const vector<int>& v2)
{
    CSet set1(v1), set2(v2, false);
    (set1 + set2).print();
}

void func7b(const vector<int>& v)
{
    CSet set1(v);
    cout << set1 << endl;
}

//==================================================================
class Circle {
    friend ostream& operator<<(ostream& out, const Circle& circle);
private:
    double m_x, m_y;  // 表示圆心坐标
    double m_r;       // 表示圆半径
public:
    Circle(double x = 0, double y = 0, double r = 1);  // 构造函数  
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getR() const { return m_r; }
};

Circle::Circle(double x, double y, double r) : m_x {x}, m_y {y}, m_r {r}
{
}

ostream& operator<<(ostream& out, const Circle& c)
{
    out << '{' << c.m_x << ", " << c.m_y << ", " << c.m_r << '}';
    return out;
}

vector<Circle> func8(const vector<Circle>& circles)
{
    vector<Circle> v;
    return v;
}

//===============================================================
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	for (const auto& x: vec)
	{
		 out<<x<<" ";
  }	
  return out;
}


int main()
{
	  //=====Test func1==================
	  cout<<"======Test func1===========\n";
	  cout<<func1('A',{50,70,90})<<endl;
	  cout<<func1('C',{50,-70,90})<<endl;
	  cout<<func1('a',{50,70,90})<<endl;
	  
	  //=====Test func2==================
	  cout<<"======Test func2===========\n";
	  cout<<func2(-1)<<endl;
	  cout<<func2(1)<<endl;
	  cout<<func2(2)<<endl;
	  cout<<func2(5)<<endl;
	  
	  //=====Test func3==================
	  cout<<"======Test func3===========\n";
	  cout<<func3('R', 'R', 'S')<<endl;
	  cout<<func3('P', 'S', 'R')<<endl;
	  cout<<func3('S', 'S', 'S')<<endl;

    //=====Test func4=================
    cout<<"======Test func4===========\n";
    cout<<func4(80, 110)<<endl;
	  cout<<func4(980, 1010)<<endl;
	  cout<<func4(9950, 10010)<<endl;
	  
	  //=====Test func5=================
    cout<<"======Test func5===========\n";
    cout<<func5({1, 2, 3, 4, 5}, {3, 2, 3})<<endl;
	  cout<<func5({1, 1}, {1})<<endl;
	  
	  //=====Test func6=================
    cout<<"======Test func6===========\n";
    func6("Alice", {60, 70, 80});
	  func6("Alice", { });
	  
	  //=====Test func7a=================
    cout<<"======Test func7a===========\n";
    func7a({3,2,1,4}, {4,4,4,4,9,5,6});
    
    //=====Test func7b=================
    cout<<"======Test func7b===========\n";
    func7b({1,2,3,4});
	  
	  //=====Test func8=================
    cout<<"======Test func8===========\n";
    vector<Circle> vec1={Circle(0,0,1), Circle(0,2,2), Circle(0,3,2), 
    	                   Circle(1,2,1), Circle(2,2,1), Circle(3,3,1), Circle(6,7,2)};
    cout<<func8(vec1)<<endl;
    vector<Circle> vec2={Circle(0,0,1), Circle(3,4,1), Circle(-2,-3,2), 
    	                   Circle(1,2,1), Circle(2,2,1), Circle(9,3,2), Circle(9,7,2)};
    cout<<func8(vec2)<<endl;

    return 0;
}